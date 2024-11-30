/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         rapicparse
#define yylex           rapiclex
#define yyerror         rapicerror
#define yydebug         rapicdebug
#define yynerrs         rapicnerrs
#define yylval          rapiclval
#define yychar          rapicchar

/* First part of user prologue.  */
#line 23 "rapic.y"

#define USE_RSL_VARS
#include "rapic_routines.h"
#include "rsl.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

int rapicerror(char *s);
int rapicwrap(char *s);
int rapicwrap(char *s);
int yywrap(char *s);
int rapiclex(void);

int nsweep = 0;
float angres;
Radar *radar, *rapic_radar = NULL;
Volume *volume;
Sweep *sweep;
Ray *ray;

/* Rapic format declarations. */
Rapic_sweep_header rh;
Rapic_sweep *rs;

unsigned char outbuf[2000000];
int outbytes;
float azim, elev;
float save_elev;
int delta_time;
int nray = 0;
int ifield;
int ivolume, isweep, iray;
int station_id;

int sweepcount[5];

extern int radar_verbose_flag;
float rapic_nyquist;
  

#line 120 "rapic.c"

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
#ifndef YY_RAPIC_RAPIC_H_INCLUDED
# define YY_RAPIC_RAPIC_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int rapicdebug;
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
    IMAGE = 258,                   /* IMAGE  */
    IMAGESCANS = 259,              /* IMAGESCANS  */
    IMAGESIZE = 260,               /* IMAGESIZE  */
    IMAGEEND = 261,                /* IMAGEEND  */
    SCAN = 262,                    /* SCAN  */
    IMAGEHEADEREND = 263,          /* IMAGEHEADEREND  */
    NUMBER = 264,                  /* NUMBER  */
    ALPHA = 265,                   /* ALPHA  */
    FLOATNUMBER = 266,             /* FLOATNUMBER  */
    BRACKETNUM = 267,              /* BRACKETNUM  */
    COUNTRY = 268,                 /* COUNTRY  */
    NAME = 269,                    /* NAME  */
    STNID = 270,                   /* STNID  */
    LATITUDE = 271,                /* LATITUDE  */
    LONGITUDE = 272,               /* LONGITUDE  */
    HEIGHT = 273,                  /* HEIGHT  */
    DATE = 274,                    /* DATE  */
    TIME = 275,                    /* TIME  */
    TIMESTAMP = 276,               /* TIMESTAMP  */
    VERS = 277,                    /* VERS  */
    FREQUENCY = 278,               /* FREQUENCY  */
    PRF = 279,                     /* PRF  */
    PULSELENGTH = 280,             /* PULSELENGTH  */
    RNGRES = 281,                  /* RNGRES  */
    ANGRES = 282,                  /* ANGRES  */
    ANGLERATE = 283,               /* ANGLERATE  */
    CLEARAIR = 284,                /* CLEARAIR  */
    ON = 285,                      /* ON  */
    OFF = 286,                     /* OFF  */
    VIDRES = 287,                  /* VIDRES  */
    STARTRNG = 288,                /* STARTRNG  */
    ENDRNG = 289,                  /* ENDRNG  */
    PRODUCT = 290,                 /* PRODUCT  */
    PASS = 291,                    /* PASS  */
    IMGFMT = 292,                  /* IMGFMT  */
    ELEV = 293,                    /* ELEV  */
    VIDEO = 294,                   /* VIDEO  */
    VELLVL = 295,                  /* VELLVL  */
    NYQUIST = 296,                 /* NYQUIST  */
    UNFOLDING = 297,               /* UNFOLDING  */
    AT = 298,                      /* AT  */
    VOLUMETRIC = 299,              /* VOLUMETRIC  */
    NORMAL = 300,                  /* NORMAL  */
    OF = 301,                      /* OF  */
    REFL = 302,                    /* REFL  */
    VEL = 303,                     /* VEL  */
    UNCORREFL = 304,               /* UNCORREFL  */
    ZDR = 305,                     /* ZDR  */
    WID = 306,                     /* WID  */
    NONE = 307,                    /* NONE  */
    RAYDATA = 308,                 /* RAYDATA  */
    ENDRADARIMAGE = 309            /* ENDRADARIMAGE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IMAGE 258
#define IMAGESCANS 259
#define IMAGESIZE 260
#define IMAGEEND 261
#define SCAN 262
#define IMAGEHEADEREND 263
#define NUMBER 264
#define ALPHA 265
#define FLOATNUMBER 266
#define BRACKETNUM 267
#define COUNTRY 268
#define NAME 269
#define STNID 270
#define LATITUDE 271
#define LONGITUDE 272
#define HEIGHT 273
#define DATE 274
#define TIME 275
#define TIMESTAMP 276
#define VERS 277
#define FREQUENCY 278
#define PRF 279
#define PULSELENGTH 280
#define RNGRES 281
#define ANGRES 282
#define ANGLERATE 283
#define CLEARAIR 284
#define ON 285
#define OFF 286
#define VIDRES 287
#define STARTRNG 288
#define ENDRNG 289
#define PRODUCT 290
#define PASS 291
#define IMGFMT 292
#define ELEV 293
#define VIDEO 294
#define VELLVL 295
#define NYQUIST 296
#define UNFOLDING 297
#define AT 298
#define VOLUMETRIC 299
#define NORMAL 300
#define OF 301
#define REFL 302
#define VEL 303
#define UNCORREFL 304
#define ZDR 305
#define WID 306
#define NONE 307
#define RAYDATA 308
#define ENDRADARIMAGE 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 326 "rapic.y"

  Charlen token;

#line 285 "rapic.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE rapiclval;


int rapicparse (void);


#endif /* !YY_RAPIC_RAPIC_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IMAGE = 3,                      /* IMAGE  */
  YYSYMBOL_IMAGESCANS = 4,                 /* IMAGESCANS  */
  YYSYMBOL_IMAGESIZE = 5,                  /* IMAGESIZE  */
  YYSYMBOL_IMAGEEND = 6,                   /* IMAGEEND  */
  YYSYMBOL_SCAN = 7,                       /* SCAN  */
  YYSYMBOL_IMAGEHEADEREND = 8,             /* IMAGEHEADEREND  */
  YYSYMBOL_NUMBER = 9,                     /* NUMBER  */
  YYSYMBOL_ALPHA = 10,                     /* ALPHA  */
  YYSYMBOL_FLOATNUMBER = 11,               /* FLOATNUMBER  */
  YYSYMBOL_BRACKETNUM = 12,                /* BRACKETNUM  */
  YYSYMBOL_COUNTRY = 13,                   /* COUNTRY  */
  YYSYMBOL_NAME = 14,                      /* NAME  */
  YYSYMBOL_STNID = 15,                     /* STNID  */
  YYSYMBOL_LATITUDE = 16,                  /* LATITUDE  */
  YYSYMBOL_LONGITUDE = 17,                 /* LONGITUDE  */
  YYSYMBOL_HEIGHT = 18,                    /* HEIGHT  */
  YYSYMBOL_DATE = 19,                      /* DATE  */
  YYSYMBOL_TIME = 20,                      /* TIME  */
  YYSYMBOL_TIMESTAMP = 21,                 /* TIMESTAMP  */
  YYSYMBOL_VERS = 22,                      /* VERS  */
  YYSYMBOL_FREQUENCY = 23,                 /* FREQUENCY  */
  YYSYMBOL_PRF = 24,                       /* PRF  */
  YYSYMBOL_PULSELENGTH = 25,               /* PULSELENGTH  */
  YYSYMBOL_RNGRES = 26,                    /* RNGRES  */
  YYSYMBOL_ANGRES = 27,                    /* ANGRES  */
  YYSYMBOL_ANGLERATE = 28,                 /* ANGLERATE  */
  YYSYMBOL_CLEARAIR = 29,                  /* CLEARAIR  */
  YYSYMBOL_ON = 30,                        /* ON  */
  YYSYMBOL_OFF = 31,                       /* OFF  */
  YYSYMBOL_VIDRES = 32,                    /* VIDRES  */
  YYSYMBOL_STARTRNG = 33,                  /* STARTRNG  */
  YYSYMBOL_ENDRNG = 34,                    /* ENDRNG  */
  YYSYMBOL_PRODUCT = 35,                   /* PRODUCT  */
  YYSYMBOL_PASS = 36,                      /* PASS  */
  YYSYMBOL_IMGFMT = 37,                    /* IMGFMT  */
  YYSYMBOL_ELEV = 38,                      /* ELEV  */
  YYSYMBOL_VIDEO = 39,                     /* VIDEO  */
  YYSYMBOL_VELLVL = 40,                    /* VELLVL  */
  YYSYMBOL_NYQUIST = 41,                   /* NYQUIST  */
  YYSYMBOL_UNFOLDING = 42,                 /* UNFOLDING  */
  YYSYMBOL_AT = 43,                        /* AT  */
  YYSYMBOL_VOLUMETRIC = 44,                /* VOLUMETRIC  */
  YYSYMBOL_NORMAL = 45,                    /* NORMAL  */
  YYSYMBOL_OF = 46,                        /* OF  */
  YYSYMBOL_REFL = 47,                      /* REFL  */
  YYSYMBOL_VEL = 48,                       /* VEL  */
  YYSYMBOL_UNCORREFL = 49,                 /* UNCORREFL  */
  YYSYMBOL_ZDR = 50,                       /* ZDR  */
  YYSYMBOL_WID = 51,                       /* WID  */
  YYSYMBOL_NONE = 52,                      /* NONE  */
  YYSYMBOL_RAYDATA = 53,                   /* RAYDATA  */
  YYSYMBOL_ENDRADARIMAGE = 54,             /* ENDRADARIMAGE  */
  YYSYMBOL_55_ = 55,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_rapic_recognized = 57,          /* rapic_recognized  */
  YYSYMBOL_sweeps = 58,                    /* sweeps  */
  YYSYMBOL_sweep = 59,                     /* sweep  */
  YYSYMBOL_sweepheader = 60,               /* sweepheader  */
  YYSYMBOL_imageend = 61,                  /* imageend  */
  YYSYMBOL_complete_header = 62,           /* complete_header  */
  YYSYMBOL_imageheader = 63,               /* imageheader  */
  YYSYMBOL_imageheader_item = 64,          /* imageheader_item  */
  YYSYMBOL_scanlist = 65,                  /* scanlist  */
  YYSYMBOL_rays = 66,                      /* rays  */
  YYSYMBOL_ray = 67,                       /* ray  */
  YYSYMBOL_scanheader = 68,                /* scanheader  */
  YYSYMBOL_scanheaditem = 69,              /* scanheaditem  */
  YYSYMBOL_real = 70,                      /* real  */
  YYSYMBOL_number = 71,                    /* number  */
  YYSYMBOL_seqno = 72,                     /* seqno  */
  YYSYMBOL_scanno = 73,                    /* scanno  */
  YYSYMBOL_imgno = 74,                     /* imgno  */
  YYSYMBOL_datetime = 75,                  /* datetime  */
  YYSYMBOL_dc = 76,                        /* dc  */
  YYSYMBOL_elev = 77,                      /* elev  */
  YYSYMBOL_fieldno = 78,                   /* fieldno  */
  YYSYMBOL_offset = 79,                    /* offset  */
  YYSYMBOL_size = 80,                      /* size  */
  YYSYMBOL_datno = 81,                     /* datno  */
  YYSYMBOL_code = 82,                      /* code  */
  YYSYMBOL_namestr = 83,                   /* namestr  */
  YYSYMBOL_idno = 84,                      /* idno  */
  YYSYMBOL_lat = 85,                       /* lat  */
  YYSYMBOL_lon = 86,                       /* lon  */
  YYSYMBOL_alt = 87,                       /* alt  */
  YYSYMBOL_hhmm = 88,                      /* hhmm  */
  YYSYMBOL_yyyymoddhhmmss = 89,            /* yyyymoddhhmmss  */
  YYSYMBOL_versionNumber = 90,             /* versionNumber  */
  YYSYMBOL_freq = 91,                      /* freq  */
  YYSYMBOL_prf = 92,                       /* prf  */
  YYSYMBOL_len = 93,                       /* len  */
  YYSYMBOL_gatewidth = 94,                 /* gatewidth  */
  YYSYMBOL_angle = 95,                     /* angle  */
  YYSYMBOL_anglerate = 96,                 /* anglerate  */
  YYSYMBOL_clearair = 97,                  /* clearair  */
  YYSYMBOL_res = 98,                       /* res  */
  YYSYMBOL_rng = 99,                       /* rng  */
  YYSYMBOL_typeid = 100,                   /* typeid  */
  YYSYMBOL_noofnscans = 101,               /* noofnscans  */
  YYSYMBOL_no = 102,                       /* no  */
  YYSYMBOL_nscans = 103,                   /* nscans  */
  YYSYMBOL_type = 104,                     /* type  */
  YYSYMBOL_field = 105,                    /* field  */
  YYSYMBOL_level = 106,                    /* level  */
  YYSYMBOL_nyq = 107,                      /* nyq  */
  YYSYMBOL_ratio = 108                     /* ratio  */
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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_uint8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   194

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   309


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   334,   334,   346,   347,   349,   359,   372,   374,   413,
     414,   415,   418,   429,   430,   437,   440,   450,   451,   452,
     455,   507,   508,   509,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     545,   546,   547,   550,   551,   553,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   567,   568,   569,
     570,   571,   572,   573,   575,   576,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   591,   592,
     593,   594,   596,   597,   598,   599,   600,   602,   603,   605,
     606
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IMAGE", "IMAGESCANS",
  "IMAGESIZE", "IMAGEEND", "SCAN", "IMAGEHEADEREND", "NUMBER", "ALPHA",
  "FLOATNUMBER", "BRACKETNUM", "COUNTRY", "NAME", "STNID", "LATITUDE",
  "LONGITUDE", "HEIGHT", "DATE", "TIME", "TIMESTAMP", "VERS", "FREQUENCY",
  "PRF", "PULSELENGTH", "RNGRES", "ANGRES", "ANGLERATE", "CLEARAIR", "ON",
  "OFF", "VIDRES", "STARTRNG", "ENDRNG", "PRODUCT", "PASS", "IMGFMT",
  "ELEV", "VIDEO", "VELLVL", "NYQUIST", "UNFOLDING", "AT", "VOLUMETRIC",
  "NORMAL", "OF", "REFL", "VEL", "UNCORREFL", "ZDR", "WID", "NONE",
  "RAYDATA", "ENDRADARIMAGE", "':'", "$accept", "rapic_recognized",
  "sweeps", "sweep", "sweepheader", "imageend", "complete_header",
  "imageheader", "imageheader_item", "scanlist", "rays", "ray",
  "scanheader", "scanheaditem", "real", "number", "seqno", "scanno",
  "imgno", "datetime", "dc", "elev", "fieldno", "offset", "size", "datno",
  "code", "namestr", "idno", "lat", "lon", "alt", "hhmm", "yyyymoddhhmmss",
  "versionNumber", "freq", "prf", "len", "gatewidth", "angle", "anglerate",
  "clearair", "res", "rng", "typeid", "noofnscans", "no", "nscans", "type",
  "field", "level", "nyq", "ratio", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,    13,    13,    13,    13,    24,   152,     5,   -65,   -65,
     -65,   -65,    13,   -65,   -65,   -65,   -29,   -65,    13,    19,
      13,    -4,    -4,    -4,    13,    -4,    13,    -4,    13,    13,
      -4,    13,    -4,    -4,   -10,    13,    13,    13,     2,    13,
      27,    -4,     8,    -4,    -4,    -3,    58,   -65,   -11,   152,
     -65,   -65,   -65,   -65,   -65,    13,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
      40,   -65,   -65,     7,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,    14,
     -65,    13,   -65,   -65,   -65,    12,   -65,   -65,    13,   -65,
      13,    13,    13,   -65,   -65,   -65,    22,   -65,   -65,   -65,
     -65,   -65,   -65,    -4,    13,   -65,    22,    13,   -65,    13,
     -65,   -65
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      11,     0,     0,     0,     0,     0,    23,     0,     9,    15,
      55,    56,     0,    13,    14,    57,     0,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,    23,     3,    19,     6,
      21,     8,    10,    58,    12,     0,    67,    25,    68,    24,
      69,    26,    54,    70,    53,    27,    71,    28,    72,    29,
      66,    30,    73,    31,    74,    32,    75,    33,    76,    34,
      77,    35,    78,    36,    79,    37,    80,    40,    81,    38,
      82,    83,    39,    84,    41,    85,    42,    43,    86,    87,
       0,    89,    46,     0,    91,    51,    62,    47,    92,    93,
      94,    95,    96,    50,    97,    48,    98,    49,    99,     0,
      52,     0,     4,     2,    20,     0,    17,    22,     0,    44,
       0,     0,     0,     5,    18,    59,     0,    90,    88,   100,
       7,    61,    60,     0,     0,    63,     0,     0,    64,     0,
      65,    16
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,   -65,    17,   -65,   -65,   -65,   -65,    53,   -65,
     -65,   -58,   -65,    39,    18,    -1,   -51,   -65,   -64,   -65,
     -57,   -42,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,    65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,    46,    47,    48,   123,     6,     7,     8,     9,
     125,   126,    49,    50,   106,    64,    12,    16,    54,   136,
     143,   107,   146,   149,   151,    71,    57,    59,    61,    65,
      67,    69,    73,    75,    77,    79,    81,    83,    85,    87,
      89,    92,    94,    96,   100,   102,   103,   138,   105,   113,
     115,   117,   120
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      11,    13,    14,    15,   128,    10,    10,    62,     1,     2,
       3,    53,     4,    51,     1,     2,     3,    56,     4,    60,
      90,    91,    10,    70,    17,    74,    55,    78,    80,    58,
      84,    10,   141,    62,    93,    95,    95,   104,   101,    63,
      66,    68,   124,    72,   119,    76,    98,    99,    82,   118,
      86,    88,   129,   130,    11,   108,   109,   110,   111,   112,
      52,   114,   116,   122,   121,   124,   133,   134,   140,   131,
     132,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,   127,   147,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,   144,    97,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,     0,     0,     0,     0,     0,     0,   135,     0,   137,
     139,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   145,     0,     0,   148,     0,   150,     0,
       0,     0,     0,     0,   142,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     0,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45
};

static const yytype_int16 yycheck[] =
{
       1,     2,     3,     4,    55,     9,     9,    11,     3,     4,
       5,    12,     7,     8,     3,     4,     5,    18,     7,    20,
      30,    31,     9,    24,     0,    26,    55,    28,    29,    10,
      31,     9,    10,    11,    35,    36,    37,    10,    39,    21,
      22,    23,    53,    25,    45,    27,    44,    45,    30,    52,
      32,    33,    12,    46,    55,    47,    48,    49,    50,    51,
       7,    43,    44,    46,     6,    53,    54,   125,   132,    55,
     121,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    49,   146,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   143,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,    -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,   130,
     131,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,    -1,    -1,   147,    -1,   149,    -1,
      -1,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   146,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     7,    57,    62,    63,    64,    65,
       9,    71,    72,    71,    71,    71,    73,     0,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    58,    59,    60,    68,
      69,     8,    64,    71,    74,    55,    71,    82,    10,    83,
      71,    84,    11,    70,    71,    85,    70,    86,    70,    87,
      71,    81,    70,    88,    71,    89,    70,    90,    71,    91,
      71,    92,    70,    93,    71,    94,    70,    95,    70,    96,
      30,    31,    97,    71,    98,    71,    99,    99,    44,    45,
     100,    71,   101,   102,    10,   104,    70,    77,    47,    48,
      49,    50,    51,   105,    70,   106,    70,   107,    52,    71,
     108,     6,    59,    61,    53,    66,    67,    69,    72,    12,
      46,    55,    72,    54,    67,    71,    75,    71,   103,    71,
      74,    10,    70,    76,    77,    71,    78,    76,    71,    79,
      71,    80
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    60,    61,    62,    63,
      63,    63,    64,    64,    64,    64,    65,    66,    66,    66,
      67,    68,    68,    68,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    70,    70,    71,    72,    73,    74,    75,
      76,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    97,    98,    99,   100,   100,   101,   102,
     103,   104,   105,   105,   105,   105,   105,   106,   107,   108,
     108
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     1,     2,     3,     1,     3,     2,     1,
       2,     0,     3,     2,     2,     1,    11,     1,     2,     0,
       1,     1,     2,     0,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     1,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
  case 2: /* rapic_recognized: complete_header sweeps imageend  */
#line 335 "rapic.y"
{
  if (radar_verbose_flag) fprintf(stderr, "SUCCESSFUL parse\n");
  sprintf(radar->h.name, "%s", rh.namestr);
  sprintf(radar->h.radar_name, "%s", rh.namestr);

  radar = fill_header(radar);
  radar = RSL_prune_radar(radar);
  rapic_radar = radar;
  YYACCEPT;
}
#line 1510 "rapic.c"
    break;

  case 5: /* sweep: sweepheader rays ENDRADARIMAGE  */
#line 350 "rapic.y"
{
  /* Attach the sweep to the volume. */
  if (radar_verbose_flag) fprintf(stderr, "Attach the sweep %d to the volume %d.\n",
		  isweep, ivolume);
  radar->v[ivolume]->sweep[isweep] = sweep;
  radar->v[ivolume]->h.f    = sweep->h.f;
  radar->v[ivolume]->h.invf = sweep->h.invf;
}
#line 1523 "rapic.c"
    break;

  case 6: /* sweepheader: scanheader  */
#line 360 "rapic.y"
{
  /*  float c =  RSL_SPEED_OF_LIGHT; */
  if (rh.angle_resolution != 0) 
	sweep = RSL_new_sweep((int)(360.0/rh.angle_resolution+0.5));
  if (fabs(rh.elev - save_elev) > .5) { /* New sweep elevation. */
	isweep++;
	save_elev = rh.elev;
  }
  nray = 0;
  /* rapic_nyquist = c*((float)rh.prf/10.)/(4.*(float)rh.freq*100000.0); */
}
#line 1539 "rapic.c"
    break;

  case 8: /* complete_header: imageheader IMAGEHEADEREND  */
#line 375 "rapic.y"
{
  if (radar_verbose_flag) fprintf(stderr, "sweepcount[0] = %d\n", sweepcount[0]);
  if (sweepcount[0] > 0) {
	radar->v[DZ_INDEX] = RSL_new_volume(sweepcount[0]);
	radar->v[DZ_INDEX]->h.type_str = strdup("Reflectivity");
  }
  if (radar_verbose_flag) fprintf(stderr, "sweepcount[1] = %d\n", sweepcount[1]);
  if (sweepcount[1] > 0) {
	volume = radar->v[VR_INDEX] = RSL_new_volume(sweepcount[1]);
	volume->h.type_str = strdup("Velocity");
	volume->h.calibr_const = 0.0;
  }
  if (radar_verbose_flag) fprintf(stderr, "sweepcount[2] = %d\n", sweepcount[2]);
  if (sweepcount[2] > 0) {
	radar->v[SW_INDEX] = RSL_new_volume(sweepcount[2]);
	volume->h.type_str = strdup("Spectral Width");
	volume->h.calibr_const = 0.0;
  }
  if (radar_verbose_flag) fprintf(stderr, "sweepcount[3] = %d\n", sweepcount[3]);
  if (sweepcount[3] > 0) {
	radar->v[ZD_INDEX] = RSL_new_volume(sweepcount[3]);
	volume->h.type_str = strdup("Reflectivity Depolarization Ratio");
	volume->h.calibr_const = 0.0;
  }
  if (radar_verbose_flag) fprintf(stderr, "sweepcount[4] = %d\n", sweepcount[4]);
  if (sweepcount[4] > 0) {
	radar->v[ZT_INDEX] = RSL_new_volume(sweepcount[4]);
	volume->h.type_str = strdup("Total Reflectivity");
	volume->h.calibr_const = 0.0;
  }
  isweep = -1; /* It keeps track of the sweep number across all field
                * types; volumes.  It is immediately bumped to 0 when
                * the sweepheader is parsed.
				*/
  save_elev = 99999;
}
#line 1580 "rapic.c"
    break;

  case 12: /* imageheader_item: IMAGE seqno imgno  */
#line 419 "rapic.y"
{
  radar = RSL_new_radar(MAX_RADAR_VOLUMES);
  sweepcount[0] = 0;
  sweepcount[1] = 0;
  sweepcount[2] = 0;
  sweepcount[3] = 0;
  sweepcount[4] = 0;
  radar->h.number = atoi((yyvsp[-1].token.s));
}
#line 1594 "rapic.c"
    break;

  case 14: /* imageheader_item: IMAGESIZE number  */
#line 431 "rapic.y"
{
  if (atoi((yyvsp[0].token.s)) <= 0) {
	fprintf(stderr, "RAPIC: /IMAGESIZE == %d.  RAPIC ingest returning NULL.\n", atoi((yyvsp[0].token.s)));
	YYERROR;
  }
}
#line 1605 "rapic.c"
    break;

  case 16: /* scanlist: SCAN scanno ':' seqno datetime dc elev fieldno dc offset size  */
#line 441 "rapic.y"
{
  ifield = atoi((yyvsp[-3].token.s));
  sweepcount[ifield]++;
}
#line 1614 "rapic.c"
    break;

  case 20: /* ray: RAYDATA  */
#line 456 "rapic.y"
 {

   /*   fprintf(stderr, "YACC len=%d text=<", yylval.token.len); */
   /*   binprint(yylval.token.s, yylval.token.len); */
   /*   fprintf(stderr, ">\n"); */

   /* Quiet the compilier, because I only use the rsl_f_list and rsl_invf_list. */
   RSL_ftype[0] = RSL_ftype[0];

   /* Use yylval.token.s and yylval.token.len */
   memset(outbuf, '\0', sizeof(outbuf));
   rapic_decode((unsigned char *)yylval.token.s, yylval.token.len, outbuf, &outbytes,
				&azim, &elev, &delta_time);
   /*   fprintf(stderr, "RAYDATA: ray %d, ivol %d, isweep %d, azim %f, elev %f, dtime %d, size=%d\n", nray, ivolume, isweep, azim, elev, delta_time, outbytes); */

   ray = RSL_new_ray(outbytes);
   rapic_load_ray_header(rh, nray, isweep, elev, azim, &ray->h); /* Mostly from the scanheader (rh). */
   ray->h.azimuth = azim;
   /*    if (39<azim && azim <40) { */
   ray->h.elev = elev;
   ray->h.sec += delta_time;
   ray->h.f    = RSL_f_list[ivolume]; /* Data conversion function. f(x). */
   ray->h.invf = RSL_invf_list[ivolume]; /* invf(x). */

   rapic_fix_time(ray);
   rapic_load_ray_data(outbuf, outbytes, ivolume, ray);
#define DODO
#undef DODO
#ifdef DODO
   if (ray->h.ray_num == 0 && ivolume == 1 && isweep == 0)
	 { int i;
   fprintf(stderr, "RAYDATA: ray %d, ivol %d, isweep %d, azim %f, elev %f, dtime %d, size=%d\n", nray, ivolume, isweep, azim, elev, delta_time, outbytes);
	 for (i=0; i<ray->h.nbins; i++) {
	   fprintf(stderr,"YACCray->range[%d] = %d  %f\n", i, (int)ray->range[i],
			   ray->h.f(ray->range[i]));
	 }
	 }
#endif
   /* Attach the ray to the sweep. */
   sweep->ray[nray]      = ray;
   sweep->h.beam_width   = ray->h.beam_width;
   sweep->h.vert_half_bw = sweep->h.beam_width / 2.0;
   sweep->h.horz_half_bw = sweep->h.beam_width / 2.0;
   sweep->h.sweep_num    = isweep;
   sweep->h.elev         = ray->h.elev;
   sweep->h.f            = ray->h.f;
   sweep->h.invf         = ray->h.invf;
   nray++;
   /*   } */
}
#line 1669 "rapic.c"
    break;

  case 24: /* scanheaditem: NAME namestr  */
#line 515 "rapic.y"
                      { memmove(rh.namestr,(yyvsp[0].token.s),(yyvsp[0].token.len)); }
#line 1675 "rapic.c"
    break;

  case 25: /* scanheaditem: COUNTRY code  */
#line 516 "rapic.y"
                      { rh.country       = atoi((yyvsp[0].token.s)); }
#line 1681 "rapic.c"
    break;

  case 26: /* scanheaditem: STNID idno  */
#line 517 "rapic.y"
                          { rh.station_id_no = atoi((yyvsp[0].token.s)); }
#line 1687 "rapic.c"
    break;

  case 27: /* scanheaditem: LATITUDE lat  */
#line 518 "rapic.y"
                          { rh.lat           = atof((yyvsp[0].token.s)); }
#line 1693 "rapic.c"
    break;

  case 28: /* scanheaditem: LONGITUDE lon  */
#line 519 "rapic.y"
                          { rh.lon           = atof((yyvsp[0].token.s)); }
#line 1699 "rapic.c"
    break;

  case 29: /* scanheaditem: HEIGHT alt  */
#line 520 "rapic.y"
                          { rh.height        = atof((yyvsp[0].token.s)); }
#line 1705 "rapic.c"
    break;

  case 30: /* scanheaditem: DATE datno  */
#line 521 "rapic.y"
                          { rh.datno         = atoi((yyvsp[0].token.s)); }
#line 1711 "rapic.c"
    break;

  case 31: /* scanheaditem: TIME hhmm  */
#line 522 "rapic.y"
                          { rh.hhmm          = atof((yyvsp[0].token.s)); }
#line 1717 "rapic.c"
    break;

  case 32: /* scanheaditem: TIMESTAMP yyyymoddhhmmss  */
#line 523 "rapic.y"
                                 { memmove(rh.yyyymoddhhmmss,(yyvsp[0].token.s),(yyvsp[0].token.len)); }
#line 1723 "rapic.c"
    break;

  case 33: /* scanheaditem: VERS versionNumber  */
#line 524 "rapic.y"
                                 { rh.versionNumber    = atof((yyvsp[0].token.s)); }
#line 1729 "rapic.c"
    break;

  case 34: /* scanheaditem: FREQUENCY freq  */
#line 525 "rapic.y"
                             { rh.freq             = atoi((yyvsp[0].token.s)); }
#line 1735 "rapic.c"
    break;

  case 35: /* scanheaditem: PRF prf  */
#line 526 "rapic.y"
                             { rh.prf              = atoi((yyvsp[0].token.s)); }
#line 1741 "rapic.c"
    break;

  case 36: /* scanheaditem: PULSELENGTH len  */
#line 527 "rapic.y"
                             { rh.pulselen         = atof((yyvsp[0].token.s)); }
#line 1747 "rapic.c"
    break;

  case 37: /* scanheaditem: RNGRES gatewidth  */
#line 528 "rapic.y"
                                 { rh.range_resolution = atoi((yyvsp[0].token.s)); }
#line 1753 "rapic.c"
    break;

  case 38: /* scanheaditem: ANGLERATE anglerate  */
#line 529 "rapic.y"
                                 { rh.anglerate        = atof((yyvsp[0].token.s)); }
#line 1759 "rapic.c"
    break;

  case 39: /* scanheaditem: CLEARAIR clearair  */
#line 530 "rapic.y"
                                 { memmove(rh.clearair,(yyvsp[0].token.s),(yyvsp[0].token.len));}
#line 1765 "rapic.c"
    break;

  case 40: /* scanheaditem: ANGRES angle  */
#line 531 "rapic.y"
                                 { rh.angle_resolution = atof((yyvsp[0].token.s)); }
#line 1771 "rapic.c"
    break;

  case 41: /* scanheaditem: VIDRES res  */
#line 532 "rapic.y"
                                 { rh.video_resolution = atoi((yyvsp[0].token.s)); }
#line 1777 "rapic.c"
    break;

  case 42: /* scanheaditem: STARTRNG rng  */
#line 533 "rapic.y"
                                 { rh.start_range      = atoi((yyvsp[0].token.s)); }
#line 1783 "rapic.c"
    break;

  case 43: /* scanheaditem: ENDRNG rng  */
#line 534 "rapic.y"
                                 { rh.end_range        = atoi((yyvsp[0].token.s)); }
#line 1789 "rapic.c"
    break;

  case 44: /* scanheaditem: PRODUCT typeid BRACKETNUM  */
#line 535 "rapic.y"
                                    { memmove(rh.product_type,(yyvsp[-1].token.s),(yyvsp[-1].token.len)); }
#line 1795 "rapic.c"
    break;

  case 47: /* scanheaditem: ELEV elev  */
#line 538 "rapic.y"
                        { rh.elev    = atof((yyvsp[0].token.s)); }
#line 1801 "rapic.c"
    break;

  case 48: /* scanheaditem: VELLVL level  */
#line 539 "rapic.y"
                        { rh.vellvl  = atof((yyvsp[0].token.s)); }
#line 1807 "rapic.c"
    break;

  case 49: /* scanheaditem: NYQUIST nyq  */
#line 541 "rapic.y"
{
  rh.nyquist = atof((yyvsp[0].token.s));
  rapic_nyquist = rh.nyquist;
}
#line 1816 "rapic.c"
    break;

  case 50: /* scanheaditem: VIDEO field  */
#line 545 "rapic.y"
                        { memmove(rh.video,(yyvsp[0].token.s),(yyvsp[0].token.len)); }
#line 1822 "rapic.c"
    break;

  case 51: /* scanheaditem: IMGFMT type  */
#line 546 "rapic.y"
                        { memmove(rh.imgfmt,(yyvsp[0].token.s),(yyvsp[0].token.len)); }
#line 1828 "rapic.c"
    break;

  case 89: /* no: number  */
#line 592 "rapic.y"
                    {rh.scannum = atoi((yyvsp[0].token.s));}
#line 1834 "rapic.c"
    break;

  case 90: /* nscans: number  */
#line 593 "rapic.y"
                    {rh.ofscans = atoi((yyvsp[0].token.s));}
#line 1840 "rapic.c"
    break;

  case 92: /* field: REFL  */
#line 596 "rapic.y"
                  {ivolume = DZ_INDEX; volume = radar->v[ivolume];}
#line 1846 "rapic.c"
    break;

  case 93: /* field: VEL  */
#line 597 "rapic.y"
                  {ivolume = VR_INDEX; volume = radar->v[ivolume];}
#line 1852 "rapic.c"
    break;

  case 94: /* field: UNCORREFL  */
#line 598 "rapic.y"
                  {ivolume = ZT_INDEX; volume = radar->v[ivolume];}
#line 1858 "rapic.c"
    break;

  case 95: /* field: ZDR  */
#line 599 "rapic.y"
                  {ivolume = ZD_INDEX; volume = radar->v[ivolume];}
#line 1864 "rapic.c"
    break;

  case 96: /* field: WID  */
#line 600 "rapic.y"
                  {ivolume = SW_INDEX; volume = radar->v[ivolume];}
#line 1870 "rapic.c"
    break;

  case 99: /* ratio: NONE  */
#line 605 "rapic.y"
                    {rh.ratio1 = 0; rh.ratio2 = 0;}
#line 1876 "rapic.c"
    break;

  case 100: /* ratio: number ':' number  */
#line 606 "rapic.y"
                    {rh.ratio1 = atoi((yyvsp[-2].token.s)); rh.ratio2 = atoi((yyvsp[0].token.s));}
#line 1882 "rapic.c"
    break;


#line 1886 "rapic.c"

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
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

#line 610 "rapic.y"


int rapicerror(char *s)
{
  fprintf(stderr, "RAPIC ERROR: <%s> on token <", s);
  binprint(yylval.token.s, yylval.token.len);
  fprintf(stderr, ">\n");
  return 1;
}

int rapicwrap(char *s)
{
  yywrap(s);
  return 1;
}
