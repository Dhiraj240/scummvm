/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "director/director.h"
#include "director/lingo/lingo.h"

namespace Director {

Common::String preprocessReturn(Common::String in);
Common::String preprocessPlay(Common::String in);
Common::String preprocessSound(Common::String in);

bool isspec(char c) {
	return strchr("-+*/%%^:,()><&[]=", c) != NULL;
}

static Common::String nexttok(const char *s, const char **newP = nullptr) {
	Common::String res;

	// Scan first non-whitespace
	while (*s && (*s == ' ' || *s == '\t' || *s == '\xC2')) // If we see a whitespace
		s++;

	if (Common::isAlnum(*s)) {
		// Now copy everything till whitespace
		while (*s && (Common::isAlnum(*s) || *s == '.'))
			res += *s++;
	} else {
		while (*s && isspec(*s))
			res += *s++;
	}

	if (newP)
		*newP = s;

	return res;
}

static Common::String prevtok(const char *s, const char *lineStart, const char **newP = nullptr) {
	Common::String res;

	// Scan first non-whitespace
	while (s >= lineStart && (*s == ' ' || *s == '\t' || *s == '\xC2')) // If we see a whitespace
		if (s > lineStart) {
			s--;
		} else {
			break;
		}

	// Now copy everything till whitespace
	if (Common::isAlnum(*s)) {
		// Now copy everything till whitespace
		while (s >= lineStart && (Common::isAlnum(*s) || *s == '.'))
			res = *s-- + res;
	} else {
		while (s >= lineStart && isspec(*s))
			res = *s-- + res;
	}

	if (newP)
		*newP = s;

	return res;
}

Common::String Lingo::codePreprocessor(const char *s, bool simple) {
	Common::String res;

	// We start from processing the continuation synbols
	// \xC2\n  ->  \xC2
	// This will greatly simplify newline processing, still leaving
	// the line number tracking intact
	while (*s) {
		if (*s == '\xC2') {
			res += *s++;
			if (!*s)	// Who knows, maybe it is the last symbol in the script
				break;
			s++;
			continue;
		}
		res += *s++;
	}

	Common::String tmp(res);
	res.clear();
	s = tmp.c_str();

	// Strip comments
	while (*s) {
		if (*s == '-' && *(s + 1) == '-') { // At the end of the line we will have \0
			while (*s && *s != '\n')
				s++;
		}

		if (*s == '\r')
			res += '\n';
		else if (*s)
			res += *s;

		if (*s)
			s++;
	}

	tmp = res;
	res.clear();

	// Strip trailing whitespaces
	s = tmp.c_str();
	while (*s) {
		if (*s == ' ' || *s == '\t' || *s == '\xC2') { // If we see a whitespace
			const char *ps = s; // Remember where we saw it

			while (*ps == ' ' || *ps == '\t' || *ps == '\xC2') // Scan until end of whitespaces
				ps++;

			if (*ps) {	// Not end of the string
				if (*ps == '\n') {	// If it is newline, then we continue from it
					s = ps;
				} else {	// It is not a newline
					while (s != ps) {	// Add all whitespaces
						res += *s;
						s++;
					}
				}
			}
		}

		if (*s)
			res += *s;

		s++;
	}

	if (simple)
		return res;

	tmp = res;
	s = tmp.c_str();
	res.clear();

	// Preprocess if statements
	// Here we add ' end if' at end of each statement, which lets us
	// make the grammar very straightforward
	Common::String line, tok, res1;
	const char *lineStart, *prevEnd;
	int iflevel = 0;

	while (*s) {
		line.clear();
		res1.clear();

		// Get next line
		while (*s && *s != '\n') { // If we see a whitespace
			res1 += *s;
			line += tolower(*s++);
		}
		debugC(2, kDebugLingoParse, "line: %d                         '%s'", iflevel, line.c_str());

		res1 = preprocessReturn(res1);
		res1 = preprocessPlay(res1);
		res1 = preprocessSound(res1);

		res += res1;

		if (line.size() < 4) { // If line is too small, then skip it
			if (*s)	// copy newline symbol
				res += *s++;

			debugC(2, kDebugLingoParse, "too small");

			continue;
		}

		tok = nexttok(line.c_str(), &lineStart);
		if (tok.equals("if")) {
			tok = prevtok(&line.c_str()[line.size() - 1], lineStart, &prevEnd);
			debugC(2, kDebugLingoParse, "start-if <%s>", tok.c_str());

			if (tok.equals("if")) {
				debugC(2, kDebugLingoParse, "end-if");
				tok = prevtok(prevEnd, lineStart);

				if (tok.equals("end")) {
					// do nothing, we open and close same line
					debugC(2, kDebugLingoParse, "end-end");
				} else {
					iflevel++;
				}
			} else if (tok.equals("then")) {
				debugC(2, kDebugLingoParse, "last-then");
				iflevel++;
			} else if (tok.equals("else")) {
				debugC(2, kDebugLingoParse, "last-else");
				iflevel++;
			} else { // other token
				// Now check if we have tNLELSE
				if (!*s) {
					iflevel++;	// end, we have to add 'end if'
					break;
				}
				const char *s1 = s + 1;

				while (*s1 && *s1 == '\n')
					s1++;
				tok = nexttok(s1);

				if (tok.equalsIgnoreCase("else")) { // ignore case because it is look-ahead
					debugC(2, kDebugLingoParse, "tNLELSE");
					iflevel++;
				} else {
					debugC(2, kDebugLingoParse, "++++ end if (no nlelse after single liner)");
					res += " end if";
				}
			}
		} else if (tok.equals("else")) {
			debugC(2, kDebugLingoParse, "start-else");
			bool elseif = false;

			tok = nexttok(lineStart);
			if (tok.equals("if")) {
				debugC(2, kDebugLingoParse, "second-if");
				elseif = true;
			} else if (tok.empty()) {
				debugC(2, kDebugLingoParse, "lonely-else");
				continue;
			}

			tok = prevtok(&line.c_str()[line.size() - 1], lineStart, &prevEnd);
			debugC(2, kDebugLingoParse, "last: '%s'", tok.c_str());

			if (tok.equals("if")) {
				debugC(2, kDebugLingoParse, "end-if");
				tok = prevtok(prevEnd, lineStart);

				if (tok.equals("end")) {
					debugC(2, kDebugLingoParse, "end-end");
					iflevel--;
				}
			} else if (tok.equals("then")) {
				debugC(2, kDebugLingoParse, "last-then");

				if (elseif == false) {
					warning("Badly nested then");
				}
			} else if (tok.equals("else")) {
				debugC(2, kDebugLingoParse, "last-else");
				if (elseif == false) {
					warning("Badly nested else");
				}
			} else { // check if we have tNLELSE or \nEND
				if (!*s) {
					break;
				}
				const char *s1 = s + 1;

				while (*s1 && *s1 == '\n')
					s1++;
				tok = nexttok(s1, &s1);

				if (tok.equalsIgnoreCase("else") && elseif) {
					// Nothing to do here, same level
					debugC(2, kDebugLingoParse, "tNLELSE");
				} else if (tok.equalsIgnoreCase("end") && elseif) {
					tok = nexttok(s1);

					if (tok.equalsIgnoreCase("if")) {
						// Nothing to do here
						debugC(2, kDebugLingoParse, "see-end-if");
					} else {
						debugC(2, kDebugLingoParse, "++++ end if (no tNLELSE 2)");
						res += " end if";
						iflevel--;
					}
				} else {
					debugC(2, kDebugLingoParse, "++++ end if (no tNLELSE)");
					res += " end if";
					iflevel--;
				}
			}
		} else if (tok.equals("end")) {
			debugC(2, kDebugLingoParse, "start-end");

			tok = nexttok(lineStart);
			if (tok.equals("if")) {
				debugC(2, kDebugLingoParse, "second-if");
				iflevel--;
			}
		} else if (tok.equals("when")) {
			debugC(2, kDebugLingoParse, "start-when");

			if (strstr(lineStart, "if") && strstr(lineStart, "then")) {
				tok = prevtok(&line.c_str()[line.size() - 1], lineStart, &prevEnd);
				debugC(2, kDebugLingoParse, "when-start-if <%s>", tok.c_str());

				if (tok.equals("if")) {
					debugC(2, kDebugLingoParse, "when-end-if");
					tok = prevtok(prevEnd, lineStart);

					if (tok.equals("end")) {
						// do nothing, we open and close same line
						debugC(2, kDebugLingoParse, "when-end-end");
					} else {
						res += " end if";
					}
				} else {
					res += " end if";
				}
			}
		} else {
			debugC(2, kDebugLingoParse, "nothing");
		}
	}

	for (int i = 0; i < iflevel; i++) {
		debugC(2, kDebugLingoParse, "++++ end if (unclosed)");
		res += "\nend if";
	}

	// Make the parser happier when there is no newline at the end
	res += '\n';

	debugC(2, kDebugLingoParse, "#############\n%s\n#############", res.c_str());

	return res;
}

#ifndef strcasestr
const char *strcasestr(const char *s, const char *find) {
	char c, sc;
	size_t len;

	if ((c = *find++) != 0) {
		c = (char)tolower((unsigned char)c);
		len = strlen(find);
		do {
			do {
				if ((sc = *s++) == 0)
					return (NULL);
			} while ((char)tolower((unsigned char)sc) != c);
		} while (scumm_strnicmp(s, find, len) != 0);
		s--;
	}
	return s;
}
#endif

// "hello" & return && "world" -> "hello" & scummvm_return && "world"
//
// This is to let the grammar not confuse RETURN constant with
// return command
Common::String preprocessReturn(Common::String in) {
	Common::String res, prev, next;
	const char *ptr = in.c_str();
	const char *beg = ptr;

	while ((ptr = strcasestr(beg, "return")) != NULL) {
		res += Common::String(beg, ptr);

		if (ptr == beg)
			prev = "";
		else
			prev = prevtok(ptr - 1, beg);

		next = nexttok(ptr + 6); // end of 'return'

		debugC(2, kDebugLingoParse, "RETURN: prevtok: %s nexttok: %s", prev.c_str(), next.c_str());

		if (prev.hasSuffix("&") || prev.hasSuffix("&&") || prev.hasSuffix("=") ||
				next.hasPrefix("&") || next.hasPrefix("&&")) {
			res += "scummvm_"; // Turn it into scummvm_return
		}

		res += *ptr++; // We advance one character, so 'eturn' is left
		beg = ptr;
	}

	res += Common::String(beg);

	if (in.size() != res.size())
		debugC(2, kDebugLingoParse, "RETURN: in: %s\nout: %s", in.c_str(), res.c_str());

	return res;
}

// play done -> play #done
Common::String preprocessPlay(Common::String in) {
	Common::String res, next;
	const char *ptr = in.c_str();
	const char *beg = ptr;
	const char *nextPtr;

	while ((ptr = strcasestr(beg, "play")) != NULL) {
		if (ptr > in.c_str() && Common::isAlnum(*(ptr - 1))) { // If we're in the middle of a word
			res += *beg++;
			continue;
		}

		ptr += 4; // end of 'play'
		res += Common::String(beg, ptr);

		if (!*ptr)	// If it is end of the line
			break;

		if (Common::isAlnum(*ptr)) { // If it is in the middle of the word
			beg = ptr;
			continue;
		}

		next = nexttok(ptr, &nextPtr);

		debugC(2, kDebugLingoParse, "PLAY: nexttok: %s", next.c_str());

		if (next.equalsIgnoreCase("done")) {
			res += " #"; // Turn it into SYMBOL
		} else {
			res += ' ';
		}

		res += next;
		ptr = nextPtr;
		beg = ptr;
	}

	res += Common::String(beg);

	if (in.size() != res.size())
		debugC(2, kDebugLingoParse, "PLAY: in: %s\nout: %s", in.c_str(), res.c_str());

	return res;
}

// sound fadeIn 5, 10 -> sound #fadeIn, 5, 10
Common::String preprocessSound(Common::String in) {
	Common::String res, next;
	const char *ptr = in.c_str();
	const char *beg = ptr;
	const char *nextPtr;

	while ((ptr = strcasestr(beg, "sound")) != NULL) {
		if (ptr > in.c_str() && Common::isAlnum(*(ptr - 1))) { // If we're in the middle of a word
			res += *beg++;
			continue;
		}

		ptr += 5; // end of 'sound'
		res += Common::String(beg, ptr);

		if (!*ptr)	// If it is end of the line
			break;

		if (Common::isAlnum(*ptr)) { // If it is in the middle of the word
			beg = ptr;
			continue;
		}

		next = nexttok(ptr, &nextPtr);

		debugC(2, kDebugLingoParse, "SOUND: nexttok: %s", next.c_str());

		bool modified = false;

		if (next.equalsIgnoreCase("close") ||
				next.equalsIgnoreCase("fadeIn") ||
				next.equalsIgnoreCase("fadeOut") ||
				next.equalsIgnoreCase("playFile") ||
				next.equalsIgnoreCase("stop")) {
			res += '#'; // Turn it into SYMBOL
			modified = true;
		} else {
			res += ' ';
		}

		res += next;
		if (modified)
			res += ',';
		ptr = nextPtr;
		beg = ptr;
	}

	res += Common::String(beg);

	if (in.size() != res.size())
		debugC(2, kDebugLingoParse, "SOUND: in: %s\nout: %s", in.c_str(), res.c_str());

	return res;
}

} // End of namespace Director
