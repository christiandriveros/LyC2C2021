
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     CTE_STRING = 259,
     CTE_ENT = 260,
     CTE_REAL = 261,
     T_FLOAT = 262,
     T_STRING = 263,
     T_INT = 264,
     WHILE = 265,
     ENDWHILE = 266,
     IF = 267,
     THEN = 268,
     ELSE = 269,
     ENDIF = 270,
     GET = 271,
     DISPLAY = 272,
     DIM = 273,
     AS = 274,
     EQUMAX = 275,
     EQUMIN = 276,
     LONG = 277,
     OP_SUM = 278,
     OP_RES = 279,
     OP_MULT = 280,
     OP_DIV = 281,
     OP_ASIG = 282,
     OP_MAY = 283,
     OP_MAY_IG = 284,
     OP_MEN = 285,
     OP_MEN_IG = 286,
     OP_IGUAL = 287,
     OP_DIST = 288,
     OP_AND = 289,
     OP_OR = 290,
     OP_NOT = 291,
     PA = 292,
     PC = 293,
     PYC = 294,
     COMA = 295,
     DOS_PUNT = 296,
     COR_A = 297,
     COR_C = 298,
     MENOS_UNARIO = 299
   };
#endif
/* Tokens.  */
#define ID 258
#define CTE_STRING 259
#define CTE_ENT 260
#define CTE_REAL 261
#define T_FLOAT 262
#define T_STRING 263
#define T_INT 264
#define WHILE 265
#define ENDWHILE 266
#define IF 267
#define THEN 268
#define ELSE 269
#define ENDIF 270
#define GET 271
#define DISPLAY 272
#define DIM 273
#define AS 274
#define EQUMAX 275
#define EQUMIN 276
#define LONG 277
#define OP_SUM 278
#define OP_RES 279
#define OP_MULT 280
#define OP_DIV 281
#define OP_ASIG 282
#define OP_MAY 283
#define OP_MAY_IG 284
#define OP_MEN 285
#define OP_MEN_IG 286
#define OP_IGUAL 287
#define OP_DIST 288
#define OP_AND 289
#define OP_OR 290
#define OP_NOT 291
#define PA 292
#define PC 293
#define PYC 294
#define COMA 295
#define DOS_PUNT 296
#define COR_A 297
#define COR_C 298
#define MENOS_UNARIO 299




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 203 "Sintactico.y"

	char str_val[100];
	



/* Line 1676 of yacc.c  */
#line 147 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


