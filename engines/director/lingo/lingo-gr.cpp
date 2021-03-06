/* A Bison parser, made by GNU Bison 3.6.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.6.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 54 "engines/director/lingo/lingo-gr.y"

#define FORBIDDEN_SYMBOL_ALLOW_ALL

#include "common/endian.h"
#include "common/hash-str.h"
#include "common/rect.h"

#include "director/director.h"
#include "director/lingo/lingo.h"
#include "director/lingo/lingo-code.h"
#include "director/lingo/lingo-gr.h"

extern int yylex();
extern int yyparse();
extern void lex_unput(int c);
extern bool lex_check_parens();

using namespace Director;

void yyerror(const char *s) {
	g_lingo->_hadError = true;
	warning("######################  LINGO: %s at line %d col %d", s, g_lingo->_linenumber, g_lingo->_colnumber);
}

void checkEnd(Common::String *token, const char *expect, bool required) {
	if (required) {
		if (token->compareToIgnoreCase(expect)) {
			Common::String err = Common::String::format("end mismatch. Expected %s but got %s", expect, token->c_str());
			yyerror(err.c_str());
		}
	}
}


#line 106 "engines/director/lingo/lingo-gr.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_ENGINES_DIRECTOR_LINGO_LINGO_GR_H_INCLUDED
# define YY_YY_ENGINES_DIRECTOR_LINGO_LINGO_GR_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    UNARY = 258,                   /* UNARY  */
    CASTREF = 259,                 /* CASTREF  */
    VOID = 260,                    /* VOID  */
    VAR = 261,                     /* VAR  */
    POINT = 262,                   /* POINT  */
    RECT = 263,                    /* RECT  */
    ARRAY = 264,                   /* ARRAY  */
    OBJECT = 265,                  /* OBJECT  */
    REFERENCE = 266,               /* REFERENCE  */
    LEXERROR = 267,                /* LEXERROR  */
    PARRAY = 268,                  /* PARRAY  */
    INT = 269,                     /* INT  */
    ARGC = 270,                    /* ARGC  */
    ARGCNORET = 271,               /* ARGCNORET  */
    THEENTITY = 272,               /* THEENTITY  */
    THEENTITYWITHID = 273,         /* THEENTITYWITHID  */
    THEMENUITEMENTITY = 274,       /* THEMENUITEMENTITY  */
    THEMENUITEMSENTITY = 275,      /* THEMENUITEMSENTITY  */
    FLOAT = 276,                   /* FLOAT  */
    BLTIN = 277,                   /* BLTIN  */
    FBLTIN = 278,                  /* FBLTIN  */
    RBLTIN = 279,                  /* RBLTIN  */
    THEFBLTIN = 280,               /* THEFBLTIN  */
    ID = 281,                      /* ID  */
    STRING = 282,                  /* STRING  */
    HANDLER = 283,                 /* HANDLER  */
    SYMBOL = 284,                  /* SYMBOL  */
    ENDCLAUSE = 285,               /* ENDCLAUSE  */
    tPLAYACCEL = 286,              /* tPLAYACCEL  */
    tMETHOD = 287,                 /* tMETHOD  */
    THEOBJECTFIELD = 288,          /* THEOBJECTFIELD  */
    THEOBJECTREF = 289,            /* THEOBJECTREF  */
    tDOWN = 290,                   /* tDOWN  */
    tELSE = 291,                   /* tELSE  */
    tELSIF = 292,                  /* tELSIF  */
    tEXIT = 293,                   /* tEXIT  */
    tGLOBAL = 294,                 /* tGLOBAL  */
    tGO = 295,                     /* tGO  */
    tIF = 296,                     /* tIF  */
    tIN = 297,                     /* tIN  */
    tINTO = 298,                   /* tINTO  */
    tLOOP = 299,                   /* tLOOP  */
    tMACRO = 300,                  /* tMACRO  */
    tMOVIE = 301,                  /* tMOVIE  */
    tNEXT = 302,                   /* tNEXT  */
    tOF = 303,                     /* tOF  */
    tPREVIOUS = 304,               /* tPREVIOUS  */
    tPUT = 305,                    /* tPUT  */
    tREPEAT = 306,                 /* tREPEAT  */
    tSET = 307,                    /* tSET  */
    tTHEN = 308,                   /* tTHEN  */
    tTO = 309,                     /* tTO  */
    tWHEN = 310,                   /* tWHEN  */
    tWITH = 311,                   /* tWITH  */
    tWHILE = 312,                  /* tWHILE  */
    tNLELSE = 313,                 /* tNLELSE  */
    tFACTORY = 314,                /* tFACTORY  */
    tOPEN = 315,                   /* tOPEN  */
    tPLAY = 316,                   /* tPLAY  */
    tINSTANCE = 317,               /* tINSTANCE  */
    tGE = 318,                     /* tGE  */
    tLE = 319,                     /* tLE  */
    tEQ = 320,                     /* tEQ  */
    tNEQ = 321,                    /* tNEQ  */
    tAND = 322,                    /* tAND  */
    tOR = 323,                     /* tOR  */
    tNOT = 324,                    /* tNOT  */
    tMOD = 325,                    /* tMOD  */
    tAFTER = 326,                  /* tAFTER  */
    tBEFORE = 327,                 /* tBEFORE  */
    tCONCAT = 328,                 /* tCONCAT  */
    tCONTAINS = 329,               /* tCONTAINS  */
    tSTARTS = 330,                 /* tSTARTS  */
    tCHAR = 331,                   /* tCHAR  */
    tITEM = 332,                   /* tITEM  */
    tLINE = 333,                   /* tLINE  */
    tWORD = 334,                   /* tWORD  */
    tSPRITE = 335,                 /* tSPRITE  */
    tINTERSECTS = 336,             /* tINTERSECTS  */
    tWITHIN = 337,                 /* tWITHIN  */
    tTELL = 338,                   /* tTELL  */
    tPROPERTY = 339,               /* tPROPERTY  */
    tON = 340,                     /* tON  */
    tENDIF = 341,                  /* tENDIF  */
    tENDREPEAT = 342,              /* tENDREPEAT  */
    tENDTELL = 343                 /* tENDTELL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 89 "engines/director/lingo/lingo-gr.y"

	Common::String *s;
	int i;
	double f;
	int e[2];	// Entity + field
	int code;
	int narg;	/* number of arguments */
	Director::DatumArray *arr;

	struct {
		Common::String *os;
		int oe;
	} objectfield;

	struct {
		Common::String *obj;
		Common::String *field;
	} objectref;

#line 264 "engines/director/lingo/lingo-gr.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ENGINES_DIRECTOR_LINGO_LINGO_GR_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_UNARY = 3,                      /* UNARY  */
  YYSYMBOL_CASTREF = 4,                    /* CASTREF  */
  YYSYMBOL_VOID = 5,                       /* VOID  */
  YYSYMBOL_VAR = 6,                        /* VAR  */
  YYSYMBOL_POINT = 7,                      /* POINT  */
  YYSYMBOL_RECT = 8,                       /* RECT  */
  YYSYMBOL_ARRAY = 9,                      /* ARRAY  */
  YYSYMBOL_OBJECT = 10,                    /* OBJECT  */
  YYSYMBOL_REFERENCE = 11,                 /* REFERENCE  */
  YYSYMBOL_LEXERROR = 12,                  /* LEXERROR  */
  YYSYMBOL_PARRAY = 13,                    /* PARRAY  */
  YYSYMBOL_INT = 14,                       /* INT  */
  YYSYMBOL_ARGC = 15,                      /* ARGC  */
  YYSYMBOL_ARGCNORET = 16,                 /* ARGCNORET  */
  YYSYMBOL_THEENTITY = 17,                 /* THEENTITY  */
  YYSYMBOL_THEENTITYWITHID = 18,           /* THEENTITYWITHID  */
  YYSYMBOL_THEMENUITEMENTITY = 19,         /* THEMENUITEMENTITY  */
  YYSYMBOL_THEMENUITEMSENTITY = 20,        /* THEMENUITEMSENTITY  */
  YYSYMBOL_FLOAT = 21,                     /* FLOAT  */
  YYSYMBOL_BLTIN = 22,                     /* BLTIN  */
  YYSYMBOL_FBLTIN = 23,                    /* FBLTIN  */
  YYSYMBOL_RBLTIN = 24,                    /* RBLTIN  */
  YYSYMBOL_THEFBLTIN = 25,                 /* THEFBLTIN  */
  YYSYMBOL_ID = 26,                        /* ID  */
  YYSYMBOL_STRING = 27,                    /* STRING  */
  YYSYMBOL_HANDLER = 28,                   /* HANDLER  */
  YYSYMBOL_SYMBOL = 29,                    /* SYMBOL  */
  YYSYMBOL_ENDCLAUSE = 30,                 /* ENDCLAUSE  */
  YYSYMBOL_tPLAYACCEL = 31,                /* tPLAYACCEL  */
  YYSYMBOL_tMETHOD = 32,                   /* tMETHOD  */
  YYSYMBOL_THEOBJECTFIELD = 33,            /* THEOBJECTFIELD  */
  YYSYMBOL_THEOBJECTREF = 34,              /* THEOBJECTREF  */
  YYSYMBOL_tDOWN = 35,                     /* tDOWN  */
  YYSYMBOL_tELSE = 36,                     /* tELSE  */
  YYSYMBOL_tELSIF = 37,                    /* tELSIF  */
  YYSYMBOL_tEXIT = 38,                     /* tEXIT  */
  YYSYMBOL_tGLOBAL = 39,                   /* tGLOBAL  */
  YYSYMBOL_tGO = 40,                       /* tGO  */
  YYSYMBOL_tIF = 41,                       /* tIF  */
  YYSYMBOL_tIN = 42,                       /* tIN  */
  YYSYMBOL_tINTO = 43,                     /* tINTO  */
  YYSYMBOL_tLOOP = 44,                     /* tLOOP  */
  YYSYMBOL_tMACRO = 45,                    /* tMACRO  */
  YYSYMBOL_tMOVIE = 46,                    /* tMOVIE  */
  YYSYMBOL_tNEXT = 47,                     /* tNEXT  */
  YYSYMBOL_tOF = 48,                       /* tOF  */
  YYSYMBOL_tPREVIOUS = 49,                 /* tPREVIOUS  */
  YYSYMBOL_tPUT = 50,                      /* tPUT  */
  YYSYMBOL_tREPEAT = 51,                   /* tREPEAT  */
  YYSYMBOL_tSET = 52,                      /* tSET  */
  YYSYMBOL_tTHEN = 53,                     /* tTHEN  */
  YYSYMBOL_tTO = 54,                       /* tTO  */
  YYSYMBOL_tWHEN = 55,                     /* tWHEN  */
  YYSYMBOL_tWITH = 56,                     /* tWITH  */
  YYSYMBOL_tWHILE = 57,                    /* tWHILE  */
  YYSYMBOL_tNLELSE = 58,                   /* tNLELSE  */
  YYSYMBOL_tFACTORY = 59,                  /* tFACTORY  */
  YYSYMBOL_tOPEN = 60,                     /* tOPEN  */
  YYSYMBOL_tPLAY = 61,                     /* tPLAY  */
  YYSYMBOL_tINSTANCE = 62,                 /* tINSTANCE  */
  YYSYMBOL_tGE = 63,                       /* tGE  */
  YYSYMBOL_tLE = 64,                       /* tLE  */
  YYSYMBOL_tEQ = 65,                       /* tEQ  */
  YYSYMBOL_tNEQ = 66,                      /* tNEQ  */
  YYSYMBOL_tAND = 67,                      /* tAND  */
  YYSYMBOL_tOR = 68,                       /* tOR  */
  YYSYMBOL_tNOT = 69,                      /* tNOT  */
  YYSYMBOL_tMOD = 70,                      /* tMOD  */
  YYSYMBOL_tAFTER = 71,                    /* tAFTER  */
  YYSYMBOL_tBEFORE = 72,                   /* tBEFORE  */
  YYSYMBOL_tCONCAT = 73,                   /* tCONCAT  */
  YYSYMBOL_tCONTAINS = 74,                 /* tCONTAINS  */
  YYSYMBOL_tSTARTS = 75,                   /* tSTARTS  */
  YYSYMBOL_tCHAR = 76,                     /* tCHAR  */
  YYSYMBOL_tITEM = 77,                     /* tITEM  */
  YYSYMBOL_tLINE = 78,                     /* tLINE  */
  YYSYMBOL_tWORD = 79,                     /* tWORD  */
  YYSYMBOL_tSPRITE = 80,                   /* tSPRITE  */
  YYSYMBOL_tINTERSECTS = 81,               /* tINTERSECTS  */
  YYSYMBOL_tWITHIN = 82,                   /* tWITHIN  */
  YYSYMBOL_tTELL = 83,                     /* tTELL  */
  YYSYMBOL_tPROPERTY = 84,                 /* tPROPERTY  */
  YYSYMBOL_tON = 85,                       /* tON  */
  YYSYMBOL_tENDIF = 86,                    /* tENDIF  */
  YYSYMBOL_tENDREPEAT = 87,                /* tENDREPEAT  */
  YYSYMBOL_tENDTELL = 88,                  /* tENDTELL  */
  YYSYMBOL_89_ = 89,                       /* '<'  */
  YYSYMBOL_90_ = 90,                       /* '>'  */
  YYSYMBOL_91_ = 91,                       /* '&'  */
  YYSYMBOL_92_ = 92,                       /* '+'  */
  YYSYMBOL_93_ = 93,                       /* '-'  */
  YYSYMBOL_94_ = 94,                       /* '*'  */
  YYSYMBOL_95_ = 95,                       /* '/'  */
  YYSYMBOL_96_ = 96,                       /* '%'  */
  YYSYMBOL_97_n_ = 97,                     /* '\n'  */
  YYSYMBOL_98_ = 98,                       /* '('  */
  YYSYMBOL_99_ = 99,                       /* ')'  */
  YYSYMBOL_100_ = 100,                     /* ','  */
  YYSYMBOL_101_ = 101,                     /* '['  */
  YYSYMBOL_102_ = 102,                     /* ']'  */
  YYSYMBOL_103_ = 103,                     /* ':'  */
  YYSYMBOL_YYACCEPT = 104,                 /* $accept  */
  YYSYMBOL_program = 105,                  /* program  */
  YYSYMBOL_programline = 106,              /* programline  */
  YYSYMBOL_asgn = 107,                     /* asgn  */
  YYSYMBOL_stmtoneliner = 108,             /* stmtoneliner  */
  YYSYMBOL_stmtonelinerwithif = 109,       /* stmtonelinerwithif  */
  YYSYMBOL_stmt = 110,                     /* stmt  */
  YYSYMBOL_tellstart = 111,                /* tellstart  */
  YYSYMBOL_ifstmt = 112,                   /* ifstmt  */
  YYSYMBOL_elseifstmtlist = 113,           /* elseifstmtlist  */
  YYSYMBOL_elseifstmt = 114,               /* elseifstmt  */
  YYSYMBOL_ifoneliner = 115,               /* ifoneliner  */
  YYSYMBOL_repeatwhile = 116,              /* repeatwhile  */
  YYSYMBOL_repeatwith = 117,               /* repeatwith  */
  YYSYMBOL_if = 118,                       /* if  */
  YYSYMBOL_elseif = 119,                   /* elseif  */
  YYSYMBOL_begin = 120,                    /* begin  */
  YYSYMBOL_end = 121,                      /* end  */
  YYSYMBOL_stmtlist = 122,                 /* stmtlist  */
  YYSYMBOL_when = 123,                     /* when  */
  YYSYMBOL_simpleexpr = 124,               /* simpleexpr  */
  YYSYMBOL_expr = 125,                     /* expr  */
  YYSYMBOL_chunkexpr = 126,                /* chunkexpr  */
  YYSYMBOL_reference = 127,                /* reference  */
  YYSYMBOL_proc = 128,                     /* proc  */
  YYSYMBOL_129_1 = 129,                    /* $@1  */
  YYSYMBOL_130_2 = 130,                    /* $@2  */
  YYSYMBOL_globallist = 131,               /* globallist  */
  YYSYMBOL_propertylist = 132,             /* propertylist  */
  YYSYMBOL_instancelist = 133,             /* instancelist  */
  YYSYMBOL_gotofunc = 134,                 /* gotofunc  */
  YYSYMBOL_gotomovie = 135,                /* gotomovie  */
  YYSYMBOL_playfunc = 136,                 /* playfunc  */
  YYSYMBOL_137_3 = 137,                    /* $@3  */
  YYSYMBOL_defn = 138,                     /* defn  */
  YYSYMBOL_139_4 = 139,                    /* $@4  */
  YYSYMBOL_140_5 = 140,                    /* $@5  */
  YYSYMBOL_141_6 = 141,                    /* $@6  */
  YYSYMBOL_on = 142,                       /* on  */
  YYSYMBOL_143_7 = 143,                    /* $@7  */
  YYSYMBOL_argdef = 144,                   /* argdef  */
  YYSYMBOL_endargdef = 145,                /* endargdef  */
  YYSYMBOL_argstore = 146,                 /* argstore  */
  YYSYMBOL_macro = 147,                    /* macro  */
  YYSYMBOL_arglist = 148,                  /* arglist  */
  YYSYMBOL_nonemptyarglist = 149,          /* nonemptyarglist  */
  YYSYMBOL_list = 150,                     /* list  */
  YYSYMBOL_valuelist = 151,                /* valuelist  */
  YYSYMBOL_linearlist = 152,               /* linearlist  */
  YYSYMBOL_proplist = 153,                 /* proplist  */
  YYSYMBOL_proppair = 154                  /* proppair  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  129
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2363

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  104
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  172
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  377

#define YYMAXUTOK   343


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      97,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    96,    91,     2,
      98,    99,    94,    92,   100,    93,     2,    95,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   103,     2,
      89,     2,    90,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   101,     2,   102,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   144,   144,   145,   147,   148,   149,   151,   157,   161,
     172,   173,   174,   180,   187,   193,   200,   206,   213,   224,
     231,   232,   233,   235,   236,   237,   238,   240,   241,   246,
     257,   274,   286,   297,   299,   304,   308,   313,   317,   327,
     338,   339,   341,   348,   358,   369,   371,   377,   383,   390,
     392,   394,   395,   396,   398,   404,   407,   410,   414,   418,
     422,   430,   431,   432,   443,   444,   445,   448,   451,   454,
     457,   463,   468,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   498,   499,   500,   501,
     502,   503,   504,   505,   507,   510,   512,   513,   514,   515,
     516,   517,   517,   518,   518,   519,   520,   523,   526,   527,
     529,   533,   538,   542,   547,   551,   563,   564,   565,   566,
     570,   574,   579,   580,   582,   586,   590,   594,   594,   624,
     624,   624,   631,   632,   632,   639,   649,   657,   657,   659,
     660,   661,   663,   664,   665,   667,   669,   677,   678,   679,
     681,   682,   684,   686,   687,   688,   689,   691,   692,   694,
     695,   697,   701
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "UNARY", "CASTREF", "VOID",
  "VAR", "POINT", "RECT", "ARRAY", "OBJECT", "REFERENCE", "LEXERROR",
  "PARRAY", "INT", "ARGC", "ARGCNORET", "THEENTITY", "THEENTITYWITHID",
  "THEMENUITEMENTITY", "THEMENUITEMSENTITY", "FLOAT", "BLTIN", "FBLTIN",
  "RBLTIN", "THEFBLTIN", "ID", "STRING", "HANDLER", "SYMBOL", "ENDCLAUSE",
  "tPLAYACCEL", "tMETHOD", "THEOBJECTFIELD", "THEOBJECTREF", "tDOWN",
  "tELSE", "tELSIF", "tEXIT", "tGLOBAL", "tGO", "tIF", "tIN", "tINTO",
  "tLOOP", "tMACRO", "tMOVIE", "tNEXT", "tOF", "tPREVIOUS", "tPUT",
  "tREPEAT", "tSET", "tTHEN", "tTO", "tWHEN", "tWITH", "tWHILE", "tNLELSE",
  "tFACTORY", "tOPEN", "tPLAY", "tINSTANCE", "tGE", "tLE", "tEQ", "tNEQ",
  "tAND", "tOR", "tNOT", "tMOD", "tAFTER", "tBEFORE", "tCONCAT",
  "tCONTAINS", "tSTARTS", "tCHAR", "tITEM", "tLINE", "tWORD", "tSPRITE",
  "tINTERSECTS", "tWITHIN", "tTELL", "tPROPERTY", "tON", "tENDIF",
  "tENDREPEAT", "tENDTELL", "'<'", "'>'", "'&'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'\\n'", "'('", "')'", "','", "'['", "']'", "':'",
  "$accept", "program", "programline", "asgn", "stmtoneliner",
  "stmtonelinerwithif", "stmt", "tellstart", "ifstmt", "elseifstmtlist",
  "elseifstmt", "ifoneliner", "repeatwhile", "repeatwith", "if", "elseif",
  "begin", "end", "stmtlist", "when", "simpleexpr", "expr", "chunkexpr",
  "reference", "proc", "$@1", "$@2", "globallist", "propertylist",
  "instancelist", "gotofunc", "gotomovie", "playfunc", "$@3", "defn",
  "$@4", "$@5", "$@6", "on", "$@7", "argdef", "endargdef", "argstore",
  "macro", "arglist", "nonemptyarglist", "list", "valuelist", "linearlist",
  "proplist", "proppair", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,    60,
      62,    38,    43,    45,    42,    47,    37,    10,    40,    41,
      44,    91,    93,    58
};
#endif

#define YYPACT_NINF (-275)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-164)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     783,   -77,  -275,  -275,    31,  -275,   605,   321,    31,   -15,
     506,  -275,  -275,  -275,  -275,  -275,  -275,     4,  -275,  1630,
    -275,  -275,    10,  1786,    -7,    92,    39,    44,  1868,  1667,
      50,  1868,  1868,  1868,  1868,  1868,  1868,  1868,  -275,  -275,
    1868,  1868,  1868,   416,    81,     0,  -275,  -275,  -275,  -275,
    1868,   -26,  1868,  1466,  -275,  2255,  -275,  -275,  -275,  -275,
    -275,  -275,  -275,  -275,  -275,  -275,  -275,  -275,    19,  1786,
    1749,  2255,    26,  1749,    26,  -275,    31,  1749,  2255,    28,
     694,  -275,  -275,    77,  -275,  1868,  -275,    60,  -275,   408,
    -275,   104,  -275,   108,   153,   126,  -275,   -47,    31,    31,
     -14,    59,   103,  -275,  2152,   408,  -275,  -275,    58,  -275,
    1860,  1908,  1941,  1974,  2222,  2139,   133,   134,  -275,  -275,
    2185,    61,    62,  -275,  2255,    64,    63,    69,  -275,  -275,
     783,  2255,  -275,  -275,  2255,  -275,  -275,  1868,  2255,  -275,
    -275,  1868,  1868,  1868,  1868,  1868,  1868,  1868,  1868,  1868,
    1868,  1868,  1868,  1868,  1868,  1868,  1868,  1868,   136,  1749,
     153,  2185,    20,  1868,    22,  -275,    24,  1868,    26,   136,
    -275,    70,  2255,  1868,  -275,  -275,    31,    17,  1868,  1868,
    -275,  1868,  1868,     8,   129,  1868,  1868,  1868,  -275,  1868,
    -275,   148,  1868,  1868,  1868,  1868,  1868,  1868,  1868,  1868,
    1868,  1868,  -275,  -275,  -275,    78,  -275,  -275,    31,    31,
    -275,  1868,    87,  -275,  -275,  1868,  1868,   131,  -275,  2255,
       7,     7,     7,     7,  2268,  2268,  -275,    -4,     7,     7,
       7,     7,    -4,    13,    13,  -275,  -275,  -275,   -76,  -275,
    2255,  -275,  -275,  2255,   -28,   159,  2255,  -275,   154,  -275,
    -275,  2255,  2255,  2255,     7,  1868,  1868,   172,  2255,     7,
    2255,  2255,  -275,  2255,  2007,  2255,  2040,  2255,  2073,  2255,
    2106,  2255,  2255,  1548,  -275,   173,  -275,  -275,  2255,    61,
      62,  -275,  1210,  2255,  2255,  -275,   147,  -275,   175,  -275,
    -275,   136,  1868,  2255,     7,    31,  1868,  1868,  1868,  1868,
    -275,  1295,  -275,  -275,  -275,   115,  -275,   -16,  1124,  1548,
    -275,  -275,  -275,    15,  2255,   149,  2255,  2255,  2255,  2255,
    -275,   116,  -275,  1210,   152,  1868,  -275,  -275,   869,   954,
    -275,  1868,  -275,   120,  1868,  2255,   118,   -27,   182,  -275,
    2255,  -275,  2255,  -275,  -275,  -275,  -275,  1868,   125,  -275,
    -275,  -275,   112,  1039,  -275,  1210,  -275,  2255,  -275,  1548,
     187,  1210,   135,  1380,   176,  -275,  -275,   143,  -275,   145,
    -275,   146,  -275,  -275,  1124,  -275,  -275
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    55,    60,     0,    56,     0,     0,     0,     0,
       0,    58,    57,   137,   143,    71,    72,   110,   111,     0,
      47,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   113,   147,
       0,     0,     0,     0,     0,     2,    73,    27,     6,    28,
       0,     0,     0,     0,    64,    21,   105,    65,    22,   107,
     108,     5,    49,    20,    62,    63,    59,    70,    59,     0,
       0,   158,   117,     0,    67,   104,     0,     0,   160,   156,
       0,    49,   109,     0,   126,     0,   127,     0,   128,   129,
     131,     0,    33,     0,   106,     0,    45,     0,     0,     0,
       0,     0,     0,   142,   119,   134,   136,   124,   115,    87,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
       0,    58,    57,   164,   167,     0,   165,   166,   169,     1,
       0,    50,    49,    49,    50,    50,    26,     0,    24,    25,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   149,     0,
       0,   158,     0,     0,     0,    69,     0,     0,   138,   149,
     120,   112,   133,     0,   130,   140,     0,     0,     0,     0,
      46,     0,     0,     0,     0,     0,     0,     0,    54,     0,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,    37,   122,   114,   148,    61,     0,     0,
     162,     0,     0,     3,    51,     0,     0,     0,    34,    50,
      83,    84,    81,    82,    85,    86,    78,    89,    90,    91,
      80,    79,    88,    74,    75,    76,    77,   150,     0,   116,
     159,    66,    68,   161,     0,     0,   132,    49,     0,     7,
       8,    10,    11,    15,    13,     0,     0,     0,    14,    12,
      19,   118,   125,    96,     0,    98,     0,   100,     0,   102,
       0,    94,    95,     0,    51,     0,   172,   171,   168,     0,
       0,   170,     0,    50,    50,    51,     0,   155,     0,   155,
     121,   149,     0,    16,    17,     0,     0,     0,     0,     0,
      50,     0,   123,    52,    53,     0,    51,     0,     0,     0,
      51,   151,    51,     0,     9,     0,    97,    99,   101,   103,
      36,     0,    29,     0,     0,     0,    40,    50,     0,     0,
     155,     0,    35,     0,     0,    50,    50,     0,   152,    51,
      18,    32,    50,    51,    49,    48,    41,     0,     0,    49,
      44,   153,   145,     0,    51,     0,    51,    50,    38,     0,
       0,     0,     0,     0,     0,    50,   154,     0,    30,     0,
      51,     0,    31,    39,     0,    43,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -275,   107,  -275,  -275,  -267,  -275,     3,    30,  -275,  -275,
    -275,  -275,  -275,  -275,   185,  -275,   -79,   -48,   630,  -275,
       6,    -6,  -275,    74,   186,  -275,  -275,  -275,  -275,  -275,
    -275,   -21,  -275,  -275,  -275,  -275,  -275,  -275,  -275,  -275,
    -164,  -275,  -274,   188,     5,  -275,  -275,  -275,  -275,  -275,
      42
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    44,    45,    46,    47,   135,   304,   273,    49,   336,
     346,   136,    50,    51,    52,   347,   158,   214,   282,    53,
      54,    55,    56,    57,    58,    83,   116,   171,   205,   108,
      59,    90,    60,    80,    61,    91,   247,    81,    62,   117,
     238,   352,   310,    63,   166,    79,    64,   125,   126,   127,
     128
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      71,    71,   169,    48,    78,   244,   300,   181,   106,   349,
      67,    72,    74,    89,    75,   312,   132,    94,   182,   324,
      65,   287,   104,   105,   288,   109,   110,   111,   112,   113,
     114,   115,     1,    76,   118,   119,   120,   124,   325,   133,
     185,     8,   327,   249,   131,     2,   134,   138,     3,    95,
      96,   186,     5,   215,   216,    82,   339,    66,    11,   350,
      12,    92,   255,   160,   161,   102,   147,   161,   174,   289,
     103,   161,   288,   256,    71,   162,   107,   147,   164,   172,
     148,   129,   165,   147,   190,   168,   217,   218,   154,   155,
     156,   157,   365,    32,    33,    34,    35,   130,   153,   154,
     155,   156,   157,   170,   183,   184,   173,   156,   157,    97,
      98,    99,   330,   187,   279,   288,   280,   159,   100,   239,
     163,   241,   163,   242,   163,   101,   163,   313,   167,    42,
     175,   219,    43,    48,   176,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   180,    71,   344,   345,   188,   240,   191,   204,
     206,   243,   237,   211,   208,   209,   210,   246,   291,   212,
     245,   286,   251,   252,   262,   253,   254,   257,   275,   258,
     259,   260,   248,   261,   285,   290,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   177,   292,   295,   302,
     309,   311,   322,   331,   332,   278,   334,   341,   351,   283,
     284,   358,   360,   366,   276,   277,   141,   142,   143,   144,
     145,   146,   368,   147,   178,   179,   148,   149,   150,   370,
     372,   373,   375,   274,   305,   306,   307,   213,   137,   139,
       0,   140,   151,   152,   153,   154,   155,   156,   157,   293,
     294,   250,   320,   321,   281,     0,     0,     0,     0,     0,
     326,     0,     0,     0,     0,   356,     0,     0,     0,     0,
     359,     0,     0,     0,     0,   333,     0,     0,     0,   337,
       0,     0,     0,     0,     0,     0,   314,   343,   348,     0,
     316,   317,   318,   319,   354,     0,     0,     0,     0,     0,
       0,   315,     0,     0,     0,     0,     0,   362,     0,   364,
       0,     0,     0,   367,     0,   369,     0,   371,     0,   335,
       0,  -157,     1,     0,     0,   340,   376,     0,   342,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     3,     4,
       0,   357,     5,  -157,     7,     8,     9,    68,    11,     0,
      12,  -157,  -157,     0,    15,    16,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,     0,  -157,     0,     0,  -157,  -157,  -157,
       0,    69,  -157,    25,  -157,  -157,  -157,  -157,     0,     0,
       0,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
      31,  -157,  -157,  -157,  -157,  -157,  -157,    32,    33,    34,
      35,    36,  -157,  -157,  -157,  -157,     0,  -157,  -157,  -157,
    -157,  -157,  -157,    40,    41,  -157,  -157,     1,  -157,    73,
    -157,  -157,    43,  -157,     0,     0,     0,     0,     0,     0,
       2,     0,     0,     3,     4,     0,     0,     5,     0,     7,
       8,     9,    68,   121,     0,   122,     0,     0,     0,    15,
      16,     0,     0,     0,    85,     0,    87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,     0,    25,     0,
       0,   141,   142,   143,   144,   145,   146,     0,   147,     0,
       0,   148,   149,   150,     0,    31,     0,     0,     0,     0,
       0,     0,    32,    33,    34,    35,    36,   151,   152,   153,
     154,   155,   156,   157,     0,     0,   -59,     1,    40,    41,
       0,     0,     0,     0,    42,     0,     0,    43,  -163,   123,
       2,     0,     0,     3,     4,     0,     0,     5,   -59,     7,
       8,     9,    68,    11,     0,    12,   -59,   -59,     0,    15,
      16,     0,   -59,   -59,   -59,   -59,   -59,   -59,     0,     0,
       0,     0,     0,   -59,     0,     0,    69,   -59,    25,     0,
       0,   -59,     0,     0,     0,     0,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,    31,   -59,     0,     0,   -59,
     -59,   -59,    32,    33,    34,    35,    36,     0,     0,   -59,
     -59,     0,   -59,   -59,   -59,   -59,   -59,   -59,    40,    41,
     -59,   -59,     0,   -59,    77,  -157,     1,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       0,     0,     3,     4,     0,     0,     5,  -157,     7,     8,
       9,    68,    11,     0,    12,  -157,  -157,     0,    15,    16,
       0,  -157,  -157,  -157,  -157,  -157,  -157,     0,     0,     0,
       0,     0,  -157,     0,     0,    69,  -157,    25,     0,     0,
    -157,     0,     0,     0,     0,  -157,  -157,  -157,     0,     0,
       0,     0,     0,     0,    31,     0,     0,     0,     0,     0,
       0,    32,    33,    34,    35,    36,     0,     0,  -157,  -157,
       0,  -157,  -157,  -157,  -157,     1,     0,    40,    41,     0,
       0,     0,  -157,    70,     0,  -157,    43,     0,     2,     0,
       0,     3,     4,     0,     0,     5,  -157,     7,     8,     9,
      68,    11,     0,    12,  -157,  -157,     0,    15,    16,     0,
    -157,  -157,  -157,  -157,  -157,  -157,     0,     0,     0,     0,
       0,  -157,     0,     0,    69,  -157,    25,     0,     0,  -157,
       0,     0,     0,     0,  -157,  -157,  -157,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
      32,    33,    34,    35,    36,     0,     0,  -157,  -157,     0,
    -157,  -157,  -157,    -4,     1,     0,    40,    41,     0,     0,
       0,  -157,    42,     0,  -157,    43,     0,     2,     0,     0,
       3,     4,     0,     0,     5,     6,     7,     8,     9,    10,
      11,     0,    12,     0,    13,    14,    15,    16,     0,     0,
       0,    17,    18,    19,    20,     0,     0,     0,    21,     0,
      22,     0,     0,    23,    24,    25,     0,     0,    26,     0,
       0,     0,    27,    28,    29,    30,     0,     0,     0,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     0,    32,
      33,    34,    35,    36,     0,     0,    37,    38,    39,  -146,
       1,     0,     0,     0,     0,    40,    41,     0,     0,     0,
      -4,    42,     0,     2,    43,     0,     3,     4,     0,     0,
       5,     6,     7,     8,     9,    10,    11,     0,    12,   338,
      13,     0,    15,    16,   301,     0,     0,    17,    18,    19,
      20,     0,     0,     0,     0,   308,    22,     0,     0,    23,
      24,    25,     0,     0,    26,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     0,     0,   323,     0,    31,     0,
     328,     0,   329,     0,     0,    32,    33,    34,    35,    36,
       0,     0,    37,    38,  -144,     1,     0,     0,     0,     0,
       0,    40,    41,     0,     0,     0,   303,    42,     2,   353,
      43,     3,     4,   355,     0,     5,     6,     7,     8,     9,
      10,    11,     0,    12,   361,    13,   363,    15,    16,     0,
       0,     0,    17,    18,    19,    20,     0,     0,     0,     0,
     374,    22,     0,     0,    23,    24,    25,     0,     0,    26,
       0,     0,     0,     0,    28,    29,    30,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
      32,    33,    34,    35,    36,     0,     0,    37,    38,  -141,
       1,     0,     0,     0,     0,     0,    40,    41,     0,     0,
       0,   303,    42,     2,     0,    43,     3,     4,     0,     0,
       5,     6,     7,     8,     9,    10,    11,     0,    12,     0,
      13,     0,    15,    16,     0,     0,     0,    17,    18,    19,
      20,     0,     0,     0,     0,     0,    22,     0,     0,    23,
      24,    25,     0,     0,    26,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     0,     0,     0,     0,    31,     0,
       0,     0,     0,     0,     0,    32,    33,    34,    35,    36,
       0,     0,    37,    38,     0,     1,     0,     0,     0,     0,
       0,    40,    41,     0,     0,     0,   303,    42,     2,     0,
      43,     3,     4,     0,     0,     5,     6,     7,     8,     9,
      10,    11,     0,    12,     0,    13,     0,    15,    16,     0,
     -50,   -50,    17,    18,    19,    20,     0,     0,     0,     0,
       0,    22,     0,     0,    23,    24,    25,     0,     0,    26,
       0,     0,     0,     0,    28,    29,    30,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
      32,    33,    34,    35,    36,     0,     0,    37,    38,     0,
     -50,     1,     0,     0,     0,     0,    40,    41,     0,     0,
       0,   303,    42,     0,     2,    43,     0,     3,     4,     0,
       0,     5,     6,     7,     8,     9,    10,    11,     0,    12,
       0,    13,     0,    15,    16,     0,     0,     0,    17,    18,
      19,    20,     0,     0,     0,     0,     0,    22,     0,     0,
      23,    24,    25,     0,     0,    26,     0,     0,     0,     0,
      28,    29,    30,     0,     0,     0,     0,     0,     0,    31,
       0,     0,     0,     0,     0,     0,    32,    33,    34,    35,
      36,     0,     0,    37,    38,     0,     1,   -50,     0,     0,
       0,     0,    40,    41,     0,     0,     0,   303,    42,     2,
       0,    43,     3,     4,     0,     0,     5,     6,     7,     8,
       9,    10,    11,     0,    12,     0,    13,     0,    15,    16,
       0,     0,     0,    17,    18,    19,    20,     0,     0,     0,
       0,     0,    22,     0,     0,    23,    24,    25,     0,     0,
      26,     0,     0,     0,     0,    28,    29,    30,     0,     0,
       0,     0,     0,     0,    31,     0,     0,     0,     0,     0,
       0,    32,    33,    34,    35,    36,     0,     0,    37,    38,
       0,     1,     0,   -50,     0,     0,     0,    40,    41,     0,
       0,     0,   303,    42,     2,     0,    43,     3,     4,     0,
       0,     5,     6,     7,     8,     9,    10,    11,     0,    12,
       0,    13,     0,    15,    16,     0,     0,     0,    17,    18,
      19,    20,     0,     0,     0,     0,     0,    22,     0,     0,
      23,    24,    25,     0,     0,    26,     0,     0,     0,     0,
      28,    29,    30,     0,     0,     0,     0,     0,     0,    31,
       0,     0,     0,     0,     0,     0,    32,    33,    34,    35,
      36,     0,     0,    37,    38,     0,   -50,     1,     0,     0,
       0,     0,    40,    41,     0,     0,     0,   303,    42,     0,
       2,    43,     0,     3,     4,     0,     0,     5,     6,     7,
       8,     9,    10,    11,     0,    12,     0,    13,     0,    15,
      16,     0,     0,     0,    17,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,    23,     0,    25,     0,
       0,     0,     0,     0,     0,     0,    28,    29,    30,     0,
       0,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,    32,    33,    34,    35,    36,     0,     0,     1,
      38,     0,     0,     0,     0,     0,     0,     0,    40,    41,
       0,     0,     2,     0,    42,     3,     4,    43,     0,     5,
       6,     7,     8,     9,    10,    11,     0,    12,     0,    13,
       0,    15,    16,     0,     0,     0,    17,    18,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,     0,
      25,     0,     0,     0,     0,     0,     0,     0,    28,    29,
      30,     0,     0,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,     0,    32,    33,    34,    35,    36,     0,
       0,     1,    38,     0,     0,     0,     0,     0,     0,     0,
      40,    41,     0,     0,     2,     0,    42,     3,     4,    43,
       0,     5,     0,     7,     8,     9,    68,    11,     0,    12,
       0,     0,     0,    15,    16,     0,     0,     0,     1,     0,
       0,     0,     0,     0,    84,     0,    85,    86,    87,    88,
      69,     2,    25,     0,     3,     4,     0,     0,     5,     0,
       7,     8,     9,    68,    11,     0,    12,     0,     0,    31,
      15,    16,     0,     0,     0,     0,    32,    33,    34,    35,
      36,     0,     0,    85,     0,    87,     0,    69,     0,    25,
       0,     0,    40,    41,     0,     0,     0,     0,    42,     0,
       0,    43,     0,     0,     0,     0,    31,     0,     0,     0,
       0,     0,     0,    32,    33,    34,    35,    36,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,    40,
      41,     0,     0,     2,     0,    42,     3,     4,    43,     0,
       5,     0,     7,     8,     9,    68,    11,     0,    12,     0,
       0,     0,    15,    16,     0,     0,     0,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
       2,    25,     0,     3,     4,     0,    93,     5,     0,     7,
       8,     9,    68,    11,     0,    12,     0,     0,    31,    15,
      16,     0,     0,     0,     0,    32,    33,    34,    35,    36,
       0,     0,     0,     0,     0,     0,    69,     0,    25,     0,
       0,    40,    41,     0,     0,     0,     0,    42,  -157,  -157,
      43,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,    32,    33,    34,    35,    36,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     0,    40,    41,
       0,     0,     2,     0,    42,     3,     4,    43,     0,     5,
       0,     7,     8,     9,    68,    11,     0,    12,     0,     0,
       0,    15,    16,     0,     0,     0,     0,     0,   192,     0,
       0,     0,     0,     0,   193,     0,     0,     0,    69,     0,
      25,     0,     0,   141,   142,   143,   144,   145,   146,     0,
     147,     0,     0,   148,   149,   150,     0,    31,     0,     0,
       0,     0,     0,     0,    32,    33,    34,    35,    36,   151,
     152,   153,   154,   155,   156,   157,   194,     0,     0,     0,
      40,    41,   195,     0,     0,     0,    42,     0,     0,    43,
       0,   141,   142,   143,   144,   145,   146,     0,   147,     0,
       0,   148,   149,   150,     0,     0,     0,     0,     0,   196,
       0,     0,     0,     0,     0,   197,     0,   151,   152,   153,
     154,   155,   156,   157,   141,   142,   143,   144,   145,   146,
       0,   147,     0,     0,   148,   149,   150,     0,     0,     0,
       0,     0,   198,     0,     0,     0,     0,     0,   199,     0,
     151,   152,   153,   154,   155,   156,   157,   141,   142,   143,
     144,   145,   146,     0,   147,     0,     0,   148,   149,   150,
       0,     0,     0,     0,     0,   296,     0,     0,     0,     0,
       0,     0,     0,   151,   152,   153,   154,   155,   156,   157,
     141,   142,   143,   144,   145,   146,     0,   147,     0,     0,
     148,   149,   150,     0,     0,     0,     0,     0,   297,     0,
       0,     0,     0,     0,     0,     0,   151,   152,   153,   154,
     155,   156,   157,   141,   142,   143,   144,   145,   146,     0,
     147,     0,     0,   148,   149,   150,     0,     0,     0,     0,
       0,   298,     0,     0,     0,     0,     0,     0,     0,   151,
     152,   153,   154,   155,   156,   157,   141,   142,   143,   144,
     145,   146,     0,   147,     0,     0,   148,   149,   150,     0,
       0,     0,     0,     0,   299,     0,     0,     0,     0,     0,
       0,     0,   151,   152,   153,   154,   155,   156,   157,   141,
     142,   143,   144,   145,   146,     0,   147,     0,     0,   148,
     149,   150,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,     0,   151,   152,   153,   154,   155,
     156,   157,   141,   142,   143,   144,   145,   146,   189,   147,
       0,     0,   148,   149,   150,   141,   142,   143,   144,   145,
     146,     0,   147,     0,     0,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,     0,   203,     0,     0,     0,
       0,   151,   152,   153,   154,   155,   156,   157,   141,   142,
     143,   144,   145,   146,     0,   147,     0,     0,   148,   149,
     150,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   151,   152,   153,   154,   155,   156,
     157,     0,     0,     0,   207,   141,   142,   143,   144,   145,
     146,     0,   147,     0,     0,   148,   149,   150,     0,     0,
       0,     0,     0,   200,   201,     0,     0,     0,     0,     0,
       0,   151,   152,   153,   154,   155,   156,   157,   141,   142,
     143,   144,   145,   146,     0,   147,     0,     0,   148,   149,
     150,   141,   142,   143,   144,     0,     0,     0,   147,     0,
       0,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,   151,   152,   153,
     154,   155,   156,   157
};

static const yytype_int16 yycheck[] =
{
       6,     7,    81,     0,    10,   169,   273,    54,    29,    36,
       4,     6,     7,    19,     8,   289,    42,    23,    65,    35,
      97,    97,    28,    29,   100,    31,    32,    33,    34,    35,
      36,    37,     1,    48,    40,    41,    42,    43,    54,    65,
      54,    24,   309,    26,    50,    14,    52,    53,    17,    56,
      57,    65,    21,   132,   133,    51,   330,    26,    27,    86,
      29,    51,    54,    69,    70,    26,    70,    73,    89,    97,
      26,    77,   100,    65,    80,    70,    26,    70,    73,    85,
      73,     0,    76,    70,   105,    80,   134,   135,    92,    93,
      94,    95,   359,    76,    77,    78,    79,    97,    91,    92,
      93,    94,    95,    26,    98,    99,    46,    94,    95,    17,
      18,    19,    97,    54,    27,   100,    29,    98,    26,    99,
     100,    99,   100,    99,   100,    33,   100,   291,   100,    98,
      26,   137,   101,   130,    26,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,    26,   159,    36,    37,    53,   163,   100,    26,
      26,   167,    26,   100,   103,   103,   102,   173,   247,   100,
     100,   219,   178,   179,    26,   181,   182,    48,   100,   185,
     186,   187,   176,   189,    53,    26,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,    43,    43,    26,    26,
      53,    26,    87,    54,    88,   211,    54,    87,    26,   215,
     216,    86,   100,    26,   208,   209,    63,    64,    65,    66,
      67,    68,    87,    70,    71,    72,    73,    74,    75,    53,
      87,    86,    86,   203,   282,   283,   284,   130,    53,    53,
      -1,    53,    89,    90,    91,    92,    93,    94,    95,   255,
     256,   177,   300,   301,   212,    -1,    -1,    -1,    -1,    -1,
     308,    -1,    -1,    -1,    -1,   344,    -1,    -1,    -1,    -1,
     349,    -1,    -1,    -1,    -1,   323,    -1,    -1,    -1,   327,
      -1,    -1,    -1,    -1,    -1,    -1,   292,   335,   336,    -1,
     296,   297,   298,   299,   342,    -1,    -1,    -1,    -1,    -1,
      -1,   295,    -1,    -1,    -1,    -1,    -1,   355,    -1,   357,
      -1,    -1,    -1,   361,    -1,   363,    -1,   365,    -1,   325,
      -1,     0,     1,    -1,    -1,   331,   374,    -1,   334,    -1,
      -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,    17,    18,
      -1,   347,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    -1,    -1,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     1,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    -1,    -1,    17,    18,    -1,    -1,    21,    -1,    23,
      24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    -1,    -1,    46,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    52,    -1,
      -1,    63,    64,    65,    66,    67,    68,    -1,    70,    -1,
      -1,    73,    74,    75,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    78,    79,    80,    89,    90,    91,
      92,    93,    94,    95,    -1,    -1,     0,     1,    92,    93,
      -1,    -1,    -1,    -1,    98,    -1,    -1,   101,   102,   103,
      14,    -1,    -1,    17,    18,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    50,    51,    52,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    73,
      74,    75,    76,    77,    78,    79,    80,    -1,    -1,    83,
      84,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    -1,    97,    98,     0,     1,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,
      -1,    -1,    17,    18,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    31,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    50,    51,    52,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    77,    78,    79,    80,    -1,    -1,    83,    84,
      -1,    86,    87,    88,     0,     1,    -1,    92,    93,    -1,
      -1,    -1,    97,    98,    -1,   100,   101,    -1,    14,    -1,
      -1,    17,    18,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    30,    31,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    50,    51,    52,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    78,    79,    80,    -1,    -1,    83,    84,    -1,
      86,    87,    88,     0,     1,    -1,    92,    93,    -1,    -1,
      -1,    97,    98,    -1,   100,   101,    -1,    14,    -1,    -1,
      17,    18,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    -1,    31,    32,    33,    34,    -1,    -1,
      -1,    38,    39,    40,    41,    -1,    -1,    -1,    45,    -1,
      47,    -1,    -1,    50,    51,    52,    -1,    -1,    55,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      77,    78,    79,    80,    -1,    -1,    83,    84,    85,     0,
       1,    -1,    -1,    -1,    -1,    92,    93,    -1,    -1,    -1,
      97,    98,    -1,    14,   101,    -1,    17,    18,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    30,
      31,    -1,    33,    34,   274,    -1,    -1,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,   285,    47,    -1,    -1,    50,
      51,    52,    -1,    -1,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,    -1,    -1,   306,    -1,    69,    -1,
     310,    -1,   312,    -1,    -1,    76,    77,    78,    79,    80,
      -1,    -1,    83,    84,     0,     1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    -1,    -1,    -1,    97,    98,    14,   339,
     101,    17,    18,   343,    -1,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,   354,    31,   356,    33,    34,    -1,
      -1,    -1,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
     370,    47,    -1,    -1,    50,    51,    52,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    78,    79,    80,    -1,    -1,    83,    84,     0,
       1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    -1,
      -1,    97,    98,    14,    -1,   101,    17,    18,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    -1,
      31,    -1,    33,    34,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,
      51,    52,    -1,    -1,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,    80,
      -1,    -1,    83,    84,    -1,     1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    -1,    -1,    -1,    97,    98,    14,    -1,
     101,    17,    18,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    31,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    50,    51,    52,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    78,    79,    80,    -1,    -1,    83,    84,    -1,
      86,     1,    -1,    -1,    -1,    -1,    92,    93,    -1,    -1,
      -1,    97,    98,    -1,    14,   101,    -1,    17,    18,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      -1,    31,    -1,    33,    34,    -1,    -1,    -1,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      50,    51,    52,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,
      80,    -1,    -1,    83,    84,    -1,     1,    87,    -1,    -1,
      -1,    -1,    92,    93,    -1,    -1,    -1,    97,    98,    14,
      -1,   101,    17,    18,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    -1,    31,    -1,    33,    34,
      -1,    -1,    -1,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    50,    51,    52,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    77,    78,    79,    80,    -1,    -1,    83,    84,
      -1,     1,    -1,    88,    -1,    -1,    -1,    92,    93,    -1,
      -1,    -1,    97,    98,    14,    -1,   101,    17,    18,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      -1,    31,    -1,    33,    34,    -1,    -1,    -1,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      50,    51,    52,    -1,    -1,    55,    -1,    -1,    -1,    -1,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,
      80,    -1,    -1,    83,    84,    -1,    86,     1,    -1,    -1,
      -1,    -1,    92,    93,    -1,    -1,    -1,    97,    98,    -1,
      14,   101,    -1,    17,    18,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    -1,    31,    -1,    33,
      34,    -1,    -1,    -1,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    78,    79,    80,    -1,    -1,     1,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      -1,    -1,    14,    -1,    98,    17,    18,   101,    -1,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    31,
      -1,    33,    34,    -1,    -1,    -1,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    77,    78,    79,    80,    -1,
      -1,     1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    -1,    -1,    14,    -1,    98,    17,    18,   101,
      -1,    21,    -1,    23,    24,    25,    26,    27,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    -1,    -1,     1,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    46,    47,    48,    49,
      50,    14,    52,    -1,    17,    18,    -1,    -1,    21,    -1,
      23,    24,    25,    26,    27,    -1,    29,    -1,    -1,    69,
      33,    34,    -1,    -1,    -1,    -1,    76,    77,    78,    79,
      80,    -1,    -1,    46,    -1,    48,    -1,    50,    -1,    52,
      -1,    -1,    92,    93,    -1,    -1,    -1,    -1,    98,    -1,
      -1,   101,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    77,    78,    79,    80,    -1,    -1,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    -1,    -1,    14,    -1,    98,    17,    18,   101,    -1,
      21,    -1,    23,    24,    25,    26,    27,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    -1,    -1,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      14,    52,    -1,    17,    18,    -1,    20,    21,    -1,    23,
      24,    25,    26,    27,    -1,    29,    -1,    -1,    69,    33,
      34,    -1,    -1,    -1,    -1,    76,    77,    78,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    52,    -1,
      -1,    92,    93,    -1,    -1,    -1,    -1,    98,    99,   100,
     101,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    78,    79,    80,    -1,    -1,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      -1,    -1,    14,    -1,    98,    17,    18,   101,    -1,    21,
      -1,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    50,    -1,
      52,    -1,    -1,    63,    64,    65,    66,    67,    68,    -1,
      70,    -1,    -1,    73,    74,    75,    -1,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    77,    78,    79,    80,    89,
      90,    91,    92,    93,    94,    95,    48,    -1,    -1,    -1,
      92,    93,    54,    -1,    -1,    -1,    98,    -1,    -1,   101,
      -1,    63,    64,    65,    66,    67,    68,    -1,    70,    -1,
      -1,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    89,    90,    91,
      92,    93,    94,    95,    63,    64,    65,    66,    67,    68,
      -1,    70,    -1,    -1,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      89,    90,    91,    92,    93,    94,    95,    63,    64,    65,
      66,    67,    68,    -1,    70,    -1,    -1,    73,    74,    75,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    90,    91,    92,    93,    94,    95,
      63,    64,    65,    66,    67,    68,    -1,    70,    -1,    -1,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      93,    94,    95,    63,    64,    65,    66,    67,    68,    -1,
      70,    -1,    -1,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      90,    91,    92,    93,    94,    95,    63,    64,    65,    66,
      67,    68,    -1,    70,    -1,    -1,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    90,    91,    92,    93,    94,    95,    63,
      64,    65,    66,    67,    68,    -1,    70,    -1,    -1,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    89,    90,    91,    92,    93,
      94,    95,    63,    64,    65,    66,    67,    68,    56,    70,
      -1,    -1,    73,    74,    75,    63,    64,    65,    66,    67,
      68,    -1,    70,    -1,    -1,    73,    74,    75,    89,    90,
      91,    92,    93,    94,    95,    -1,    97,    -1,    -1,    -1,
      -1,    89,    90,    91,    92,    93,    94,    95,    63,    64,
      65,    66,    67,    68,    -1,    70,    -1,    -1,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    -1,    99,    63,    64,    65,    66,    67,
      68,    -1,    70,    -1,    -1,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    91,    92,    93,    94,    95,    63,    64,
      65,    66,    67,    68,    -1,    70,    -1,    -1,    73,    74,
      75,    63,    64,    65,    66,    -1,    -1,    -1,    70,    -1,
      -1,    73,    74,    75,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,
      92,    93,    94,    95
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    14,    17,    18,    21,    22,    23,    24,    25,
      26,    27,    29,    31,    32,    33,    34,    38,    39,    40,
      41,    45,    47,    50,    51,    52,    55,    59,    60,    61,
      62,    69,    76,    77,    78,    79,    80,    83,    84,    85,
      92,    93,    98,   101,   105,   106,   107,   108,   110,   112,
     116,   117,   118,   123,   124,   125,   126,   127,   128,   134,
     136,   138,   142,   147,   150,    97,    26,   124,    26,    50,
      98,   125,   148,    98,   148,   124,    48,    98,   125,   149,
     137,   141,    51,   129,    44,    46,    47,    48,    49,   125,
     135,   139,    51,    20,   125,    56,    57,    17,    18,    19,
      26,    33,    26,    26,   125,   125,   135,    26,   133,   125,
     125,   125,   125,   125,   125,   125,   130,   143,   125,   125,
     125,    27,    29,   103,   125,   151,   152,   153,   154,     0,
      97,   125,    42,    65,   125,   109,   115,   118,   125,   128,
     147,    63,    64,    65,    66,    67,    68,    70,    73,    74,
      75,    89,    90,    91,    92,    93,    94,    95,   120,    98,
     125,   125,   148,   100,   148,   124,   148,   100,   148,   120,
      26,   131,   125,    46,   135,    26,    26,    43,    71,    72,
      26,    54,    65,   124,   124,    54,    65,    54,    53,    56,
     135,   100,    48,    54,    48,    54,    48,    54,    48,    54,
      81,    82,    54,    97,    26,   132,    26,    99,   103,   103,
     102,   100,   100,   105,   121,   120,   120,   121,   121,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,    26,   144,    99,
     125,    99,    99,   125,   144,   100,   125,   140,   124,    26,
     127,   125,   125,   125,   125,    54,    65,    48,   125,   125,
     125,   125,    26,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   111,   111,   100,   124,   124,   125,    27,
      29,   154,   122,   125,   125,    53,   121,    97,   100,    97,
      26,   120,    43,   125,   125,    26,    48,    48,    48,    48,
     108,   122,    26,    97,   110,   121,   121,   121,   122,    53,
     146,    26,   146,   144,   125,   124,   125,   125,   125,   125,
     121,   121,    87,   122,    35,    54,   121,   108,   122,   122,
      97,    54,    88,   121,    54,   125,   113,   121,    30,   146,
     125,    87,   125,   121,    36,    37,   114,   119,   121,    36,
      86,    26,   145,   122,   121,   122,   120,   125,    86,   120,
     100,   122,   121,   122,   121,   108,    26,   121,    87,   121,
      53,   121,    87,    86,   122,    86,   121
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   104,   105,   105,   106,   106,   106,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     108,   108,   108,   109,   109,   109,   109,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   111,   112,   112,
     113,   113,   114,   115,   115,   116,   117,   118,   119,   120,
     121,   122,   122,   122,   123,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   126,   126,   126,   126,
     126,   126,   126,   126,   127,   127,   128,   128,   128,   128,
     128,   129,   128,   130,   128,   128,   128,   128,   128,   128,
     131,   131,   132,   132,   133,   133,   134,   134,   134,   134,
     134,   134,   135,   135,   136,   136,   136,   137,   136,   139,
     140,   138,   138,   141,   138,   138,   138,   143,   142,   144,
     144,   144,   145,   145,   145,   146,   147,   148,   148,   148,
     149,   149,   150,   151,   151,   151,   151,   152,   152,   153,
     153,   154,   154
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     0,     1,     1,     4,     4,     6,
       4,     4,     4,     4,     4,     4,     5,     5,     8,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     6,
      11,    12,     8,     2,     3,     7,     6,     0,     9,    12,
       0,     2,     6,    11,     7,     2,     3,     1,     1,     0,
       0,     0,     2,     2,     3,     1,     1,     1,     1,     1,
       1,     3,     1,     2,     1,     1,     4,     2,     4,     3,
       2,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     2,     2,     4,     4,     4,     6,     4,     6,
       4,     6,     4,     6,     2,     1,     2,     1,     1,     2,
       1,     0,     3,     0,     3,     2,     4,     2,     4,     2,
       1,     3,     1,     3,     1,     3,     2,     2,     2,     2,
       3,     2,     3,     2,     2,     3,     2,     0,     3,     0,
       0,     9,     2,     0,     7,     8,     6,     0,     3,     0,
       1,     3,     0,     1,     3,     0,     2,     0,     1,     3,
       1,     3,     3,     0,     1,     1,     1,     1,     3,     1,
       3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




/* The kind of the lookahead of this context.  */
static yysymbol_kind_t
yypcontext_token (const yypcontext_t *yyctx) YY_ATTRIBUTE_UNUSED;

static yysymbol_kind_t
yypcontext_token (const yypcontext_t *yyctx)
{
  return yyctx->yytoken;
}



/* User defined function to report a syntax error.  */
static int
yyreport_syntax_error (const yypcontext_t *yyctx);

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case 22: /* BLTIN  */
#line 139 "engines/director/lingo/lingo-gr.y"
            { delete ((*yyvaluep).s); }
#line 1861 "engines/director/lingo/lingo-gr.cpp"
        break;

    case 23: /* FBLTIN  */
#line 139 "engines/director/lingo/lingo-gr.y"
            { delete ((*yyvaluep).s); }
#line 1867 "engines/director/lingo/lingo-gr.cpp"
        break;

    case 24: /* RBLTIN  */
#line 139 "engines/director/lingo/lingo-gr.y"
            { delete ((*yyvaluep).s); }
#line 1873 "engines/director/lingo/lingo-gr.cpp"
        break;

    case 25: /* THEFBLTIN  */
#line 139 "engines/director/lingo/lingo-gr.y"
            { delete ((*yyvaluep).s); }
#line 1879 "engines/director/lingo/lingo-gr.cpp"
        break;

    case 26: /* ID  */
#line 139 "engines/director/lingo/lingo-gr.y"
            { delete ((*yyvaluep).s); }
#line 1885 "engines/director/lingo/lingo-gr.cpp"
        break;

    case 27: /* STRING  */
#line 139 "engines/director/lingo/lingo-gr.y"
            { delete ((*yyvaluep).s); }
#line 1891 "engines/director/lingo/lingo-gr.cpp"
        break;

    case 28: /* HANDLER  */
#line 139 "engines/director/lingo/lingo-gr.y"
            { delete ((*yyvaluep).s); }
#line 1897 "engines/director/lingo/lingo-gr.cpp"
        break;

    case 29: /* SYMBOL  */
#line 139 "engines/director/lingo/lingo-gr.y"
            { delete ((*yyvaluep).s); }
#line 1903 "engines/director/lingo/lingo-gr.cpp"
        break;

    case 30: /* ENDCLAUSE  */
#line 139 "engines/director/lingo/lingo-gr.y"
            { delete ((*yyvaluep).s); }
#line 1909 "engines/director/lingo/lingo-gr.cpp"
        break;

    case 31: /* tPLAYACCEL  */
#line 139 "engines/director/lingo/lingo-gr.y"
            { delete ((*yyvaluep).s); }
#line 1915 "engines/director/lingo/lingo-gr.cpp"
        break;

    case 32: /* tMETHOD  */
#line 139 "engines/director/lingo/lingo-gr.y"
            { delete ((*yyvaluep).s); }
#line 1921 "engines/director/lingo/lingo-gr.cpp"
        break;

    case 33: /* THEOBJECTFIELD  */
#line 140 "engines/director/lingo/lingo-gr.y"
            { delete ((*yyvaluep).objectfield).os; }
#line 1927 "engines/director/lingo/lingo-gr.cpp"
        break;

    case 142: /* on  */
#line 139 "engines/director/lingo/lingo-gr.y"
            { delete ((*yyvaluep).s); }
#line 1933 "engines/director/lingo/lingo-gr.cpp"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yystacksize = YYINITDEPTH;
  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;


  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 7:
#line 151 "engines/director/lingo/lingo-gr.y"
                                        {
		g_lingo->code1(LC::c_varpush);
		g_lingo->codeString((yyvsp[0].s)->c_str());
		g_lingo->code1(LC::c_assign);
		(yyval.code) = (yyvsp[-2].code);
		delete (yyvsp[0].s); }
#line 2219 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 8:
#line 157 "engines/director/lingo/lingo-gr.y"
                                                {
		g_lingo->code1(LC::c_assign);
		(yyval.code) = (yyvsp[-2].code); }
#line 2227 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 9:
#line 161 "engines/director/lingo/lingo-gr.y"
                                                                {
		if (!(yyvsp[-3].s)->equalsIgnoreCase("menu")) {
			warning("LEXER: keyword 'menu' expected");
			YYERROR;
		}

		g_lingo->code1(LC::c_themenuentitypush);
		g_lingo->codeInt((yyvsp[-4].e)[0]);
		g_lingo->codeInt((yyvsp[-4].e)[1]);
		g_lingo->code1(LC::c_assign);
		(yyval.code) = (yyvsp[0].code); }
#line 2243 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 10:
#line 172 "engines/director/lingo/lingo-gr.y"
                                                { (yyval.code) = g_lingo->code1(LC::c_after); }
#line 2249 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 11:
#line 173 "engines/director/lingo/lingo-gr.y"
                                                { (yyval.code) = g_lingo->code1(LC::c_before); }
#line 2255 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 12:
#line 174 "engines/director/lingo/lingo-gr.y"
                                                {
		g_lingo->code1(LC::c_varpush);
		g_lingo->codeString((yyvsp[-2].s)->c_str());
		g_lingo->code1(LC::c_assign);
		(yyval.code) = (yyvsp[0].code);
		delete (yyvsp[-2].s); }
#line 2266 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 13:
#line 180 "engines/director/lingo/lingo-gr.y"
                                        {
		g_lingo->code1(LC::c_intpush);
		g_lingo->codeInt(0); // Put dummy id
		g_lingo->code1(LC::c_theentityassign);
		g_lingo->codeInt((yyvsp[-2].e)[0]);
		g_lingo->codeInt((yyvsp[-2].e)[1]);
		(yyval.code) = (yyvsp[0].code); }
#line 2278 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 14:
#line 187 "engines/director/lingo/lingo-gr.y"
                                                {
		g_lingo->code1(LC::c_varpush);
		g_lingo->codeString((yyvsp[-2].s)->c_str());
		g_lingo->code1(LC::c_assign);
		(yyval.code) = (yyvsp[0].code);
		delete (yyvsp[-2].s); }
#line 2289 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 15:
#line 193 "engines/director/lingo/lingo-gr.y"
                                        {
		g_lingo->code1(LC::c_intpush);
		g_lingo->codeInt(0); // Put dummy id
		g_lingo->code1(LC::c_theentityassign);
		g_lingo->codeInt((yyvsp[-2].e)[0]);
		g_lingo->codeInt((yyvsp[-2].e)[1]);
		(yyval.code) = (yyvsp[0].code); }
#line 2301 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 16:
#line 200 "engines/director/lingo/lingo-gr.y"
                                                        {
		g_lingo->code1(LC::c_swap);
		g_lingo->code1(LC::c_theentityassign);
		g_lingo->codeInt((yyvsp[-3].e)[0]);
		g_lingo->codeInt((yyvsp[-3].e)[1]);
		(yyval.code) = (yyvsp[0].code); }
#line 2312 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 17:
#line 206 "engines/director/lingo/lingo-gr.y"
                                                        {
		g_lingo->code1(LC::c_swap);
		g_lingo->code1(LC::c_theentityassign);
		g_lingo->codeInt((yyvsp[-3].e)[0]);
		g_lingo->codeInt((yyvsp[-3].e)[1]);
		(yyval.code) = (yyvsp[0].code); }
#line 2323 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 18:
#line 213 "engines/director/lingo/lingo-gr.y"
                                                                        {
		if (!(yyvsp[-3].s)->equalsIgnoreCase("menu")) {
			warning("LEXER: keyword 'menu' expected");
			YYERROR;
		}

		warning("STUB: menuItem entity");
		g_lingo->code1(LC::c_themenuitementityassign);
		g_lingo->codeInt((yyvsp[-6].e)[0]);
		g_lingo->codeInt((yyvsp[-6].e)[1]);
		(yyval.code) = (yyvsp[0].code); }
#line 2339 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 19:
#line 224 "engines/director/lingo/lingo-gr.y"
                                        {
		g_lingo->code1(LC::c_objectfieldassign);
		g_lingo->codeString((yyvsp[-2].objectfield).os->c_str());
		g_lingo->codeInt((yyvsp[-2].objectfield).oe);
		delete (yyvsp[-2].objectfield).os;
		(yyval.code) = (yyvsp[0].code); }
#line 2350 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 29:
#line 246 "engines/director/lingo/lingo-gr.y"
                                                                        {
		inst body = 0, end = 0;
		WRITE_UINT32(&body, (yyvsp[-3].code) - (yyvsp[-5].code));
		WRITE_UINT32(&end, (yyvsp[-1].code) - (yyvsp[-5].code));
		(*g_lingo->_currentScript)[(yyvsp[-5].code) + 1] = body;	/* body of loop */
		(*g_lingo->_currentScript)[(yyvsp[-5].code) + 2] = end; }
#line 2361 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 30:
#line 257 "engines/director/lingo/lingo-gr.y"
                                                                                                 {
		inst init = 0, finish = 0, body = 0, end = 0, inc = 0;
		WRITE_UINT32(&init, (yyvsp[-8].code) - (yyvsp[-10].code));
		WRITE_UINT32(&finish, (yyvsp[-4].code) - (yyvsp[-10].code));
		WRITE_UINT32(&body, (yyvsp[-2].code) - (yyvsp[-10].code));
		WRITE_UINT32(&end, (yyvsp[-1].code) - (yyvsp[-10].code));
		WRITE_UINT32(&inc, 1);
		(*g_lingo->_currentScript)[(yyvsp[-10].code) + 1] = init;		/* initial count value */
		(*g_lingo->_currentScript)[(yyvsp[-10].code) + 2] = finish;	/* final count value */
		(*g_lingo->_currentScript)[(yyvsp[-10].code) + 3] = body;		/* body of loop */
		(*g_lingo->_currentScript)[(yyvsp[-10].code) + 4] = inc;		/* increment */
		(*g_lingo->_currentScript)[(yyvsp[-10].code) + 5] = end; }
#line 2378 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 31:
#line 274 "engines/director/lingo/lingo-gr.y"
                                                                                                       {
		inst init = 0, finish = 0, body = 0, end = 0, inc = 0;
		WRITE_UINT32(&init, (yyvsp[-9].code) - (yyvsp[-11].code));
		WRITE_UINT32(&finish, (yyvsp[-4].code) - (yyvsp[-11].code));
		WRITE_UINT32(&body, (yyvsp[-2].code) - (yyvsp[-11].code));
		WRITE_UINT32(&end, (yyvsp[-1].code) - (yyvsp[-11].code));
		WRITE_UINT32(&inc, (uint32)-1);
		(*g_lingo->_currentScript)[(yyvsp[-11].code) + 1] = init;		/* initial count value */
		(*g_lingo->_currentScript)[(yyvsp[-11].code) + 2] = finish;	/* final count value */
		(*g_lingo->_currentScript)[(yyvsp[-11].code) + 3] = body;		/* body of loop */
		(*g_lingo->_currentScript)[(yyvsp[-11].code) + 4] = inc;		/* increment */
		(*g_lingo->_currentScript)[(yyvsp[-11].code) + 5] = end; }
#line 2395 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 32:
#line 286 "engines/director/lingo/lingo-gr.y"
                                                                            {
		inst list = 0, body = 0, end = 0;
		WRITE_UINT32(&list, (yyvsp[-5].code) - (yyvsp[-7].code));
		WRITE_UINT32(&body, (yyvsp[-2].code) - (yyvsp[-7].code));
		WRITE_UINT32(&end, (yyvsp[-1].code) - (yyvsp[-7].code));
		(*g_lingo->_currentScript)[(yyvsp[-7].code) + 1] = list;		/* initial count value */
		(*g_lingo->_currentScript)[(yyvsp[-7].code) + 2] = 0;		/* final count value */
		(*g_lingo->_currentScript)[(yyvsp[-7].code) + 3] = body;		/* body of loop */
		(*g_lingo->_currentScript)[(yyvsp[-7].code) + 4] = 0;		/* increment */
		(*g_lingo->_currentScript)[(yyvsp[-7].code) + 5] = end; }
#line 2410 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 33:
#line 297 "engines/director/lingo/lingo-gr.y"
                        {
		g_lingo->code1(LC::c_nextRepeat); }
#line 2417 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 34:
#line 299 "engines/director/lingo/lingo-gr.y"
                                      {
		inst end = 0;
		WRITE_UINT32(&end, (yyvsp[0].code) - (yyvsp[-2].code));
		g_lingo->code1(STOP);
		(*g_lingo->_currentScript)[(yyvsp[-2].code) + 1] = end; }
#line 2427 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 35:
#line 304 "engines/director/lingo/lingo-gr.y"
                                                          {
		inst end;
		WRITE_UINT32(&end, (yyvsp[-1].code) - (yyvsp[-3].code));
		(*g_lingo->_currentScript)[(yyvsp[-3].code) + 1] = end; }
#line 2436 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 36:
#line 308 "engines/director/lingo/lingo-gr.y"
                                                    {
		inst end;
		WRITE_UINT32(&end, (yyvsp[0].code) - (yyvsp[-2].code));
		(*g_lingo->_currentScript)[(yyvsp[-2].code) + 1] = end; }
#line 2445 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 37:
#line 313 "engines/director/lingo/lingo-gr.y"
                                                        {
		(yyval.code) = g_lingo->code1(LC::c_tellcode);
		g_lingo->code1(STOP); }
#line 2453 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 38:
#line 317 "engines/director/lingo/lingo-gr.y"
                                                                                       {
		inst then = 0, else1 = 0, end = 0;
		WRITE_UINT32(&then, (yyvsp[-6].code) - (yyvsp[-8].code));
		WRITE_UINT32(&else1, (yyvsp[-3].code) - (yyvsp[-8].code));
		WRITE_UINT32(&end, (yyvsp[-1].code) - (yyvsp[-8].code));
		(*g_lingo->_currentScript)[(yyvsp[-8].code) + 1] = then;	/* thenpart */
		(*g_lingo->_currentScript)[(yyvsp[-8].code) + 2] = else1;/* elsepart */
		(*g_lingo->_currentScript)[(yyvsp[-8].code) + 3] = end;	/* end, if cond fails */

		g_lingo->processIf((yyvsp[-8].code), (yyvsp[-1].code) - (yyvsp[-8].code), 0); }
#line 2468 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 39:
#line 327 "engines/director/lingo/lingo-gr.y"
                                                                                                              {
		inst then = 0, else1 = 0, end = 0;
		WRITE_UINT32(&then, (yyvsp[-9].code) - (yyvsp[-11].code));
		WRITE_UINT32(&else1, (yyvsp[-6].code) - (yyvsp[-11].code));
		WRITE_UINT32(&end, (yyvsp[-1].code) - (yyvsp[-11].code));
		(*g_lingo->_currentScript)[(yyvsp[-11].code) + 1] = then;	/* thenpart */
		(*g_lingo->_currentScript)[(yyvsp[-11].code) + 2] = else1;/* elsepart */
		(*g_lingo->_currentScript)[(yyvsp[-11].code) + 3] = end;	/* end, if cond fails */

		g_lingo->processIf((yyvsp[-11].code), (yyvsp[-1].code) - (yyvsp[-11].code), (yyvsp[-3].code) - (yyvsp[-11].code)); }
#line 2483 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 42:
#line 341 "engines/director/lingo/lingo-gr.y"
                                                        {
		inst then = 0;
		WRITE_UINT32(&then, (yyvsp[-3].code) - (yyvsp[-5].code));
		(*g_lingo->_currentScript)[(yyvsp[-5].code) + 1] = then;	/* thenpart */

		g_lingo->codeLabel((yyvsp[-5].code)); }
#line 2494 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 43:
#line 348 "engines/director/lingo/lingo-gr.y"
                                                                                                         {
		inst then = 0, else1 = 0, end = 0;
		WRITE_UINT32(&then, (yyvsp[-8].code) - (yyvsp[-10].code));
		WRITE_UINT32(&else1, (yyvsp[-5].code) - (yyvsp[-10].code));
		WRITE_UINT32(&end, (yyvsp[-1].code) - (yyvsp[-10].code));
		(*g_lingo->_currentScript)[(yyvsp[-10].code) + 1] = then;	/* thenpart */
		(*g_lingo->_currentScript)[(yyvsp[-10].code) + 2] = else1;/* elsepart */
		(*g_lingo->_currentScript)[(yyvsp[-10].code) + 3] = end;	/* end, if cond fails */

		g_lingo->processIf((yyvsp[-10].code), (yyvsp[-1].code) - (yyvsp[-10].code), (yyvsp[-3].code) - (yyvsp[-10].code)); }
#line 2509 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 44:
#line 358 "engines/director/lingo/lingo-gr.y"
                                                                   {
		inst then = 0, else1 = 0, end = 0;
		WRITE_UINT32(&then, (yyvsp[-4].code) - (yyvsp[-6].code));
		WRITE_UINT32(&else1, 0);
		WRITE_UINT32(&end, (yyvsp[-1].code) - (yyvsp[-6].code));
		(*g_lingo->_currentScript)[(yyvsp[-6].code) + 1] = then;	/* thenpart */
		(*g_lingo->_currentScript)[(yyvsp[-6].code) + 2] = else1;/* elsepart */
		(*g_lingo->_currentScript)[(yyvsp[-6].code) + 3] = end;	/* end, if cond fails */

		g_lingo->processIf((yyvsp[-6].code), (yyvsp[-1].code) - (yyvsp[-6].code), (yyvsp[-1].code) - (yyvsp[-6].code)); }
#line 2524 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 45:
#line 369 "engines/director/lingo/lingo-gr.y"
                                        { (yyval.code) = g_lingo->code3(LC::c_repeatwhilecode, STOP, STOP); }
#line 2530 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 46:
#line 371 "engines/director/lingo/lingo-gr.y"
                                                {
		(yyval.code) = g_lingo->code3(LC::c_repeatwithcode, STOP, STOP);
		g_lingo->code3(STOP, STOP, STOP);
		g_lingo->codeString((yyvsp[0].s)->c_str());
		delete (yyvsp[0].s); }
#line 2540 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 47:
#line 377 "engines/director/lingo/lingo-gr.y"
                                                {
		(yyval.code) = g_lingo->code1(LC::c_ifcode);
		g_lingo->code3(STOP, STOP, STOP);
		g_lingo->code1(0);  // Do not skip end
		g_lingo->codeLabel(0); }
#line 2550 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 48:
#line 383 "engines/director/lingo/lingo-gr.y"
                                        {
		inst skipEnd;
		WRITE_UINT32(&skipEnd, 1); // We have to skip end to avoid multiple executions
		(yyval.code) = g_lingo->code1(LC::c_ifcode);
		g_lingo->code3(STOP, STOP, STOP);
		g_lingo->code1(skipEnd); }
#line 2561 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 49:
#line 390 "engines/director/lingo/lingo-gr.y"
                                { (yyval.code) = g_lingo->_currentScript->size(); }
#line 2567 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 50:
#line 392 "engines/director/lingo/lingo-gr.y"
                                { g_lingo->code1(STOP); (yyval.code) = g_lingo->_currentScript->size(); }
#line 2573 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 51:
#line 394 "engines/director/lingo/lingo-gr.y"
                                                { (yyval.code) = g_lingo->_currentScript->size(); }
#line 2579 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 54:
#line 398 "engines/director/lingo/lingo-gr.y"
                                {
		(yyval.code) = g_lingo->code1(LC::c_whencode);
		g_lingo->code1(STOP);
		g_lingo->codeString((yyvsp[-1].s)->c_str());
		delete (yyvsp[-1].s); }
#line 2589 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 55:
#line 404 "engines/director/lingo/lingo-gr.y"
                        {
		(yyval.code) = g_lingo->code1(LC::c_intpush);
		g_lingo->codeInt((yyvsp[0].i)); }
#line 2597 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 56:
#line 407 "engines/director/lingo/lingo-gr.y"
                        {
		(yyval.code) = g_lingo->code1(LC::c_floatpush);
		g_lingo->codeFloat((yyvsp[0].f)); }
#line 2605 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 57:
#line 410 "engines/director/lingo/lingo-gr.y"
                        {											// D3
		(yyval.code) = g_lingo->code1(LC::c_symbolpush);
		g_lingo->codeString((yyvsp[0].s)->c_str());
		delete (yyvsp[0].s); }
#line 2614 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 58:
#line 414 "engines/director/lingo/lingo-gr.y"
                                {
		(yyval.code) = g_lingo->code1(LC::c_stringpush);
		g_lingo->codeString((yyvsp[0].s)->c_str());
		delete (yyvsp[0].s); }
#line 2623 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 59:
#line 418 "engines/director/lingo/lingo-gr.y"
                        {
		(yyval.code) = g_lingo->code1(LC::c_eval);
		g_lingo->codeString((yyvsp[0].s)->c_str());
		delete (yyvsp[0].s); }
#line 2632 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 60:
#line 422 "engines/director/lingo/lingo-gr.y"
                        {
		(yyval.code) = g_lingo->code1(LC::c_intpush);
		g_lingo->codeInt(0); // Put dummy id
		g_lingo->code1(LC::c_theentitypush);
		inst e = 0, f = 0;
		WRITE_UINT32(&e, (yyvsp[0].e)[0]);
		WRITE_UINT32(&f, (yyvsp[0].e)[1]);
		g_lingo->code2(e, f); }
#line 2645 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 61:
#line 430 "engines/director/lingo/lingo-gr.y"
                                                { (yyval.code) = (yyvsp[-1].code); }
#line 2651 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 63:
#line 432 "engines/director/lingo/lingo-gr.y"
                                {
		// Director parser till D3 was forgiving for any hanging parentheses
		if (g_lingo->_ignoreError) {
			warning("# LINGO: Ignoring trailing paren");
			g_lingo->_ignoreError = false;
			lex_unput('\n');	// We ate '\n', so put it back, otherwise lines will be joined
		} else {
			yyerrok;
		}
	}
#line 2666 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 64:
#line 443 "engines/director/lingo/lingo-gr.y"
                 { (yyval.code) = (yyvsp[0].code); }
#line 2672 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 66:
#line 445 "engines/director/lingo/lingo-gr.y"
                                 {
		g_lingo->codeFunc((yyvsp[-3].s), (yyvsp[-1].narg));
		delete (yyvsp[-3].s); }
#line 2680 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 67:
#line 448 "engines/director/lingo/lingo-gr.y"
                                {
		g_lingo->codeFunc((yyvsp[-1].s), (yyvsp[0].narg));
		delete (yyvsp[-1].s); }
#line 2688 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 68:
#line 451 "engines/director/lingo/lingo-gr.y"
                                {
		(yyval.code) = g_lingo->codeFunc((yyvsp[-3].s), (yyvsp[-1].narg));
		delete (yyvsp[-3].s); }
#line 2696 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 69:
#line 454 "engines/director/lingo/lingo-gr.y"
                                        {
		(yyval.code) = g_lingo->codeFunc((yyvsp[-2].s), 1);
		delete (yyvsp[-2].s); }
#line 2704 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 70:
#line 457 "engines/director/lingo/lingo-gr.y"
                                     {
		(yyval.code) = g_lingo->code1(LC::c_theentitypush);
		inst e = 0, f = 0;
		WRITE_UINT32(&e, (yyvsp[-1].e)[0]);
		WRITE_UINT32(&f, (yyvsp[-1].e)[1]);
		g_lingo->code2(e, f); }
#line 2715 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 71:
#line 463 "engines/director/lingo/lingo-gr.y"
                         {
		g_lingo->code1(LC::c_objectfieldpush);
		g_lingo->codeString((yyvsp[0].objectfield).os->c_str());
		g_lingo->codeInt((yyvsp[0].objectfield).oe);
		delete (yyvsp[0].objectfield).os; }
#line 2725 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 72:
#line 468 "engines/director/lingo/lingo-gr.y"
                       {
		g_lingo->code1(LC::c_objectrefpush);
		g_lingo->codeString((yyvsp[0].objectref).obj->c_str());
		g_lingo->codeString((yyvsp[0].objectref).field->c_str());
		delete (yyvsp[0].objectref).obj;
		delete (yyvsp[0].objectref).field; }
#line 2736 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 74:
#line 475 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->code1(LC::c_add); }
#line 2742 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 75:
#line 476 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->code1(LC::c_sub); }
#line 2748 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 76:
#line 477 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->code1(LC::c_mul); }
#line 2754 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 77:
#line 478 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->code1(LC::c_div); }
#line 2760 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 78:
#line 479 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->code1(LC::c_mod); }
#line 2766 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 79:
#line 480 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->code1(LC::c_gt); }
#line 2772 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 80:
#line 481 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->code1(LC::c_lt); }
#line 2778 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 81:
#line 482 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->code1(LC::c_eq); }
#line 2784 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 82:
#line 483 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->code1(LC::c_neq); }
#line 2790 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 83:
#line 484 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->code1(LC::c_ge); }
#line 2796 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 84:
#line 485 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->code1(LC::c_le); }
#line 2802 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 85:
#line 486 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->code1(LC::c_and); }
#line 2808 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 86:
#line 487 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->code1(LC::c_or); }
#line 2814 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 87:
#line 488 "engines/director/lingo/lingo-gr.y"
                                        { g_lingo->code1(LC::c_not); }
#line 2820 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 88:
#line 489 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->code1(LC::c_ampersand); }
#line 2826 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 89:
#line 490 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->code1(LC::c_concat); }
#line 2832 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 90:
#line 491 "engines/director/lingo/lingo-gr.y"
                                        { g_lingo->code1(LC::c_contains); }
#line 2838 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 91:
#line 492 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->code1(LC::c_starts); }
#line 2844 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 92:
#line 493 "engines/director/lingo/lingo-gr.y"
                                    { (yyval.code) = (yyvsp[0].code); }
#line 2850 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 93:
#line 494 "engines/director/lingo/lingo-gr.y"
                                    { (yyval.code) = (yyvsp[0].code); g_lingo->code1(LC::c_negate); }
#line 2856 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 94:
#line 495 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->code1(LC::c_intersects); }
#line 2862 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 95:
#line 496 "engines/director/lingo/lingo-gr.y"
                                                        { g_lingo->code1(LC::c_within); }
#line 2868 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 96:
#line 498 "engines/director/lingo/lingo-gr.y"
                                                        { g_lingo->code1(LC::c_charOf); }
#line 2874 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 97:
#line 499 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->code1(LC::c_charToOf); }
#line 2880 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 98:
#line 500 "engines/director/lingo/lingo-gr.y"
                                                        { g_lingo->code1(LC::c_itemOf); }
#line 2886 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 99:
#line 501 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->code1(LC::c_itemToOf); }
#line 2892 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 100:
#line 502 "engines/director/lingo/lingo-gr.y"
                                                        { g_lingo->code1(LC::c_lineOf); }
#line 2898 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 101:
#line 503 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->code1(LC::c_lineToOf); }
#line 2904 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 102:
#line 504 "engines/director/lingo/lingo-gr.y"
                                                        { g_lingo->code1(LC::c_wordOf); }
#line 2910 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 103:
#line 505 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->code1(LC::c_wordToOf); }
#line 2916 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 104:
#line 507 "engines/director/lingo/lingo-gr.y"
                                        {
		g_lingo->codeFunc((yyvsp[-1].s), 1);
		delete (yyvsp[-1].s); }
#line 2924 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 106:
#line 512 "engines/director/lingo/lingo-gr.y"
                                        { g_lingo->code1(LC::c_printtop); }
#line 2930 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 109:
#line 515 "engines/director/lingo/lingo-gr.y"
                                        { g_lingo->code1(LC::c_exitRepeat); }
#line 2936 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 110:
#line 516 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->code1(LC::c_procret); }
#line 2942 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 111:
#line 517 "engines/director/lingo/lingo-gr.y"
                  { g_lingo->_indef = kStateInArgs; }
#line 2948 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 112:
#line 517 "engines/director/lingo/lingo-gr.y"
                                                                 { g_lingo->_indef = kStateNone; }
#line 2954 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 113:
#line 518 "engines/director/lingo/lingo-gr.y"
                    { g_lingo->_indef = kStateInArgs; }
#line 2960 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 114:
#line 518 "engines/director/lingo/lingo-gr.y"
                                                                     { g_lingo->_indef = kStateNone; }
#line 2966 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 116:
#line 520 "engines/director/lingo/lingo-gr.y"
                                                {
		g_lingo->codeFunc((yyvsp[-3].s), (yyvsp[-1].narg));
		delete (yyvsp[-3].s); }
#line 2974 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 117:
#line 523 "engines/director/lingo/lingo-gr.y"
                                        {
		g_lingo->codeFunc((yyvsp[-1].s), (yyvsp[0].narg));
		delete (yyvsp[-1].s); }
#line 2982 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 118:
#line 526 "engines/director/lingo/lingo-gr.y"
                                { g_lingo->code1(LC::c_open); }
#line 2988 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 119:
#line 527 "engines/director/lingo/lingo-gr.y"
                                        { g_lingo->code2(LC::c_voidpush, LC::c_open); }
#line 2994 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 120:
#line 529 "engines/director/lingo/lingo-gr.y"
                                                {
		g_lingo->code1(LC::c_global);
		g_lingo->codeString((yyvsp[0].s)->c_str());
		delete (yyvsp[0].s); }
#line 3003 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 121:
#line 533 "engines/director/lingo/lingo-gr.y"
                                                {
		g_lingo->code1(LC::c_global);
		g_lingo->codeString((yyvsp[0].s)->c_str());
		delete (yyvsp[0].s); }
#line 3012 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 122:
#line 538 "engines/director/lingo/lingo-gr.y"
                                                {
		g_lingo->code1(LC::c_property);
		g_lingo->codeString((yyvsp[0].s)->c_str());
		delete (yyvsp[0].s); }
#line 3021 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 123:
#line 542 "engines/director/lingo/lingo-gr.y"
                                        {
		g_lingo->code1(LC::c_property);
		g_lingo->codeString((yyvsp[0].s)->c_str());
		delete (yyvsp[0].s); }
#line 3030 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 124:
#line 547 "engines/director/lingo/lingo-gr.y"
                                                {
		g_lingo->code1(LC::c_instance);
		g_lingo->codeString((yyvsp[0].s)->c_str());
		delete (yyvsp[0].s); }
#line 3039 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 125:
#line 551 "engines/director/lingo/lingo-gr.y"
                                        {
		g_lingo->code1(LC::c_instance);
		g_lingo->codeString((yyvsp[0].s)->c_str());
		delete (yyvsp[0].s); }
#line 3048 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 126:
#line 563 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->code1(LC::c_gotoloop); }
#line 3054 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 127:
#line 564 "engines/director/lingo/lingo-gr.y"
                                                        { g_lingo->code1(LC::c_gotonext); }
#line 3060 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 128:
#line 565 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->code1(LC::c_gotoprevious); }
#line 3066 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 129:
#line 566 "engines/director/lingo/lingo-gr.y"
                                        {
		g_lingo->code1(LC::c_intpush);
		g_lingo->codeInt(1);
		g_lingo->code1(LC::c_goto); }
#line 3075 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 130:
#line 570 "engines/director/lingo/lingo-gr.y"
                                {
		g_lingo->code1(LC::c_intpush);
		g_lingo->codeInt(3);
		g_lingo->code1(LC::c_goto); }
#line 3084 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 131:
#line 574 "engines/director/lingo/lingo-gr.y"
                                                {
		g_lingo->code1(LC::c_intpush);
		g_lingo->codeInt(2);
		g_lingo->code1(LC::c_goto); }
#line 3093 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 134:
#line 582 "engines/director/lingo/lingo-gr.y"
                                        { // "play #done" is also caught by this
		g_lingo->code1(LC::c_intpush);
		g_lingo->codeInt(1);
		g_lingo->code1(LC::c_play); }
#line 3102 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 135:
#line 586 "engines/director/lingo/lingo-gr.y"
                                {
		g_lingo->code1(LC::c_intpush);
		g_lingo->codeInt(3);
		g_lingo->code1(LC::c_play); }
#line 3111 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 136:
#line 590 "engines/director/lingo/lingo-gr.y"
                                                        {
		g_lingo->code1(LC::c_intpush);
		g_lingo->codeInt(2);
		g_lingo->code1(LC::c_play); }
#line 3120 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 137:
#line 594 "engines/director/lingo/lingo-gr.y"
                     { g_lingo->codeSetImmediate(true); }
#line 3126 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 138:
#line 594 "engines/director/lingo/lingo-gr.y"
                                                                        {
		g_lingo->codeSetImmediate(false);
		g_lingo->codeFunc((yyvsp[-2].s), (yyvsp[0].narg));
		delete (yyvsp[-2].s); }
#line 3135 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 139:
#line 624 "engines/director/lingo/lingo-gr.y"
             { g_lingo->_indef = kStateInArgs; }
#line 3141 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 140:
#line 624 "engines/director/lingo/lingo-gr.y"
                                                    { g_lingo->_currentFactory.clear(); }
#line 3147 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 141:
#line 625 "engines/director/lingo/lingo-gr.y"
                                                                        {
		g_lingo->code1(LC::c_procret);
		g_lingo->define(*(yyvsp[-6].s), (yyvsp[-4].code), (yyvsp[-3].narg));
		g_lingo->clearArgStack();
		g_lingo->_indef = kStateNone;
		delete (yyvsp[-6].s); }
#line 3158 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 142:
#line 631 "engines/director/lingo/lingo-gr.y"
                        { g_lingo->codeFactory(*(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 3164 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 143:
#line 632 "engines/director/lingo/lingo-gr.y"
                  { g_lingo->_indef = kStateInArgs; }
#line 3170 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 144:
#line 633 "engines/director/lingo/lingo-gr.y"
                                                                        {
		g_lingo->code1(LC::c_procret);
		g_lingo->define(*(yyvsp[-6].s), (yyvsp[-4].code), (yyvsp[-3].narg) + 1, &g_lingo->_currentFactory);
		g_lingo->clearArgStack();
		g_lingo->_indef = kStateNone;
		delete (yyvsp[-6].s); }
#line 3181 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 145:
#line 639 "engines/director/lingo/lingo-gr.y"
                                                                     {	// D3
		g_lingo->code1(LC::c_procret);
		g_lingo->define(*(yyvsp[-7].s), (yyvsp[-6].code), (yyvsp[-5].narg));
		g_lingo->clearArgStack();
		g_lingo->_indef = kStateNone;
		g_lingo->_ignoreMe = false;

		checkEnd((yyvsp[-1].s), (yyvsp[-7].s)->c_str(), false);
		delete (yyvsp[-7].s);
		delete (yyvsp[-1].s); }
#line 3196 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 146:
#line 649 "engines/director/lingo/lingo-gr.y"
                                                 {	// D4. No 'end' clause
		g_lingo->code1(LC::c_procret);
		g_lingo->define(*(yyvsp[-5].s), (yyvsp[-4].code), (yyvsp[-3].narg));
		g_lingo->_indef = kStateNone;
		g_lingo->clearArgStack();
		g_lingo->_ignoreMe = false;
		delete (yyvsp[-5].s); }
#line 3208 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 147:
#line 657 "engines/director/lingo/lingo-gr.y"
         { g_lingo->_indef = kStateInArgs; }
#line 3214 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 148:
#line 657 "engines/director/lingo/lingo-gr.y"
                                                { (yyval.s) = (yyvsp[0].s); g_lingo->_currentFactory.clear(); g_lingo->_ignoreMe = true; }
#line 3220 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 149:
#line 659 "engines/director/lingo/lingo-gr.y"
                                { (yyval.narg) = 0; }
#line 3226 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 150:
#line 660 "engines/director/lingo/lingo-gr.y"
                                                { g_lingo->codeArg((yyvsp[0].s)); (yyval.narg) = 1; delete (yyvsp[0].s); }
#line 3232 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 151:
#line 661 "engines/director/lingo/lingo-gr.y"
                                        { g_lingo->codeArg((yyvsp[0].s)); (yyval.narg) = (yyvsp[-2].narg) + 1; delete (yyvsp[0].s); }
#line 3238 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 153:
#line 664 "engines/director/lingo/lingo-gr.y"
                                                { delete (yyvsp[0].s); }
#line 3244 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 154:
#line 665 "engines/director/lingo/lingo-gr.y"
                                        { delete (yyvsp[0].s); }
#line 3250 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 155:
#line 667 "engines/director/lingo/lingo-gr.y"
                                        { g_lingo->codeArgStore(); g_lingo->_indef = kStateInDef; }
#line 3256 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 156:
#line 669 "engines/director/lingo/lingo-gr.y"
                                {
		g_lingo->code1(LC::c_call);
		g_lingo->codeString((yyvsp[-1].s)->c_str());
		inst numpar = 0;
		WRITE_UINT32(&numpar, (yyvsp[0].narg));
		g_lingo->code1(numpar);
		delete (yyvsp[-1].s); }
#line 3268 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 157:
#line 677 "engines/director/lingo/lingo-gr.y"
                                { (yyval.narg) = 0; }
#line 3274 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 158:
#line 678 "engines/director/lingo/lingo-gr.y"
                                                { (yyval.narg) = 1; }
#line 3280 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 159:
#line 679 "engines/director/lingo/lingo-gr.y"
                                        { (yyval.narg) = (yyvsp[-2].narg) + 1; }
#line 3286 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 160:
#line 681 "engines/director/lingo/lingo-gr.y"
                                        { (yyval.narg) = 1; }
#line 3292 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 161:
#line 682 "engines/director/lingo/lingo-gr.y"
                                        { (yyval.narg) = (yyvsp[-2].narg) + 1; }
#line 3298 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 162:
#line 684 "engines/director/lingo/lingo-gr.y"
                                { (yyval.code) = (yyvsp[-1].code); }
#line 3304 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 163:
#line 686 "engines/director/lingo/lingo-gr.y"
                                { (yyval.code) = g_lingo->code2(LC::c_arraypush, 0); }
#line 3310 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 164:
#line 687 "engines/director/lingo/lingo-gr.y"
                                                { (yyval.code) = g_lingo->code2(LC::c_proparraypush, 0); }
#line 3316 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 165:
#line 688 "engines/director/lingo/lingo-gr.y"
                     { (yyval.code) = g_lingo->code1(LC::c_arraypush); (yyval.code) = g_lingo->codeInt((yyvsp[0].narg)); }
#line 3322 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 166:
#line 689 "engines/director/lingo/lingo-gr.y"
                         { (yyval.code) = g_lingo->code1(LC::c_proparraypush); (yyval.code) = g_lingo->codeInt((yyvsp[0].narg)); }
#line 3328 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 167:
#line 691 "engines/director/lingo/lingo-gr.y"
                                        { (yyval.narg) = 1; }
#line 3334 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 168:
#line 692 "engines/director/lingo/lingo-gr.y"
                                { (yyval.narg) = (yyvsp[-2].narg) + 1; }
#line 3340 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 169:
#line 694 "engines/director/lingo/lingo-gr.y"
                                        { (yyval.narg) = 1; }
#line 3346 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 170:
#line 695 "engines/director/lingo/lingo-gr.y"
                                { (yyval.narg) = (yyvsp[-2].narg) + 1; }
#line 3352 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 171:
#line 697 "engines/director/lingo/lingo-gr.y"
                                {
		g_lingo->code1(LC::c_symbolpush);
		g_lingo->codeString((yyvsp[-2].s)->c_str());
		delete (yyvsp[-2].s); }
#line 3361 "engines/director/lingo/lingo-gr.cpp"
    break;

  case 172:
#line 701 "engines/director/lingo/lingo-gr.y"
                                {
		g_lingo->code1(LC::c_stringpush);
		g_lingo->codeString((yyvsp[-2].s)->c_str());
		delete (yyvsp[-2].s); }
#line 3370 "engines/director/lingo/lingo-gr.cpp"
    break;


#line 3374 "engines/director/lingo/lingo-gr.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        if (yyreport_syntax_error (&yyctx) == 2)
          goto yyexhaustedlab;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 707 "engines/director/lingo/lingo-gr.y"


int yyreport_syntax_error(const yypcontext_t *ctx) {
	int res = 0;

	if (lex_check_parens()) {
		g_lingo->_ignoreError = true;
		return 0;
	}

	Common::String msg = "syntax error, ";

	// Report the unexpected token.
	yysymbol_kind_t lookahead = yypcontext_token(ctx);
	if (lookahead != YYSYMBOL_YYEMPTY)
		msg += Common::String::format("unexpected %s", yysymbol_name(lookahead));

	// Report the tokens expected at this point.
	enum { TOKENMAX = 10 };
	yysymbol_kind_t expected[TOKENMAX];

	int n = yypcontext_expected_tokens(ctx, expected, TOKENMAX);
	if (n < 0)
		// Forward errors to yyparse.
		res = n;
	else
		for (int i = 0; i < n; ++i)
			msg += Common::String::format("%s %s", i == 0 ? ": expected" : " or", yysymbol_name(expected[i]));

	yyerror(msg.c_str());

	return res;
}
