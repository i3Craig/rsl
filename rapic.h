/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
#line 325 "rapic.y"

  Charlen token;

#line 179 "rapic.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE rapiclval;


int rapicparse (void);


#endif /* !YY_RAPIC_RAPIC_H_INCLUDED  */
