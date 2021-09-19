
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
     WHILE = 258,
     ENDWHILE = 259,
     IF = 260,
     THEN = 261,
     ELSE = 262,
     ENDIF = 263,
     GET = 264,
     DISPLAY = 265,
     DIM = 266,
     AS = 267,
     T_INT = 268,
     T_FLOAT = 269,
     T_STRING = 270,
     ID = 271,
     CTE_STRING = 272,
     CTE_ENT = 273,
     CTE_REAL = 274,
     OP_SUM = 275,
     OP_RES = 276,
     OP_MULT = 277,
     OP_DIV = 278,
     OP_ASIG = 279,
     OP_MAY = 280,
     OP_MAY_IG = 281,
     OP_MEN = 282,
     OP_MEN_IG = 283,
     OP_IGUAL = 284,
     OP_DIST = 285,
     OP_AND = 286,
     OP_OR = 287,
     OP_NOT = 288,
     PA = 289,
     PC = 290,
     PYC = 291,
     COMA = 292,
     DOS_PUNT = 293,
     COR_A = 294,
     COR_C = 295,
     MENOS_UNARIO = 296
   };
#endif
/* Tokens.  */
#define WHILE 258
#define ENDWHILE 259
#define IF 260
#define THEN 261
#define ELSE 262
#define ENDIF 263
#define GET 264
#define DISPLAY 265
#define DIM 266
#define AS 267
#define T_INT 268
#define T_FLOAT 269
#define T_STRING 270
#define ID 271
#define CTE_STRING 272
#define CTE_ENT 273
#define CTE_REAL 274
#define OP_SUM 275
#define OP_RES 276
#define OP_MULT 277
#define OP_DIV 278
#define OP_ASIG 279
#define OP_MAY 280
#define OP_MAY_IG 281
#define OP_MEN 282
#define OP_MEN_IG 283
#define OP_IGUAL 284
#define OP_DIST 285
#define OP_AND 286
#define OP_OR 287
#define OP_NOT 288
#define PA 289
#define PC 290
#define PYC 291
#define COMA 292
#define DOS_PUNT 293
#define COR_A 294
#define COR_C 295
#define MENOS_UNARIO 296




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


