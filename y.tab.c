
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "Sintactico.y"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"
#include "lista.h"
#include "pila_enteros.h"
#include "pila_strings.h"
#include "coladinamica.h"
#include "lista_inter.h"
#include "lista_etiq.h"
//#include "lista_str.h"
#include "pila_celdas_assembler.h"

#define TIPO_ENTERO "int"
#define TIPO_STRING "string"
#define TIPO_FLOTANTE "float"
#define TIPO_VACIO ""
#define AUXILIAR_MENOS_UNARIO "@MENOS_UNARIO"

/// ETIQUETAS NOTACION INTERMEDIA

#define ETIQUETA_WHILE "#ET_WHILE"

/// OPERADORES /////////////////////

#define OPERADOR_GET "$OP_READ"
#define OPERADOR_DISPLAY "$OP_WRITE"
#define OPERADOR_CMP "$OP_CMP"
#define OPERADOR_BI "$OP_BI"
#define OPERADOR_BLT "$OP_BLT"
#define OPERADOR_BLE "$OP_BLE"
#define OPERADOR_BGT "$OP_BGT"
#define OPERADOR_BGE "$OP_BGE"
#define OPERADOR_BEQ "$OP_BEQ"
#define OPERADOR_BNE "$OP_BNE"



//// DEFINES DE ASSEMBLER ////////
#define TIPO_OPERADOR 1
#define TIPO_OPERANDO 0
#define TIPO_NO_DETERMINADO -1

//// PARA LOS CONDICIONALES ///////////////////////////////
#define CONDICION_SIMPLE 1
#define CONDICION_MULTIPLE_AND 2
#define CONDICION_MULTIPLE_OR 3

int yystopparser=0;
FILE* yyin;

////////////////////////////
//DECLARACION DE FUNCIONES//
////////////////////////////
void genera_assembler();


void apilar_operando( char *operando , char *tipo);
void desapilar_operando( char *operando, char *tipo );

void generar_cabecera_assembler(FILE *arch);
void generar_inicio_de_codigo_assembler(FILE* arch);
void generar_final_de_codigo_assembler(FILE *arch);
void generar_seccion_de_variables( FILE * archivoAssembler, t_lista *dirListaTSDuplicada );
void generar_cuerpo_de_codigo_assembler( char *cuerpoAssembler, t_lista_cod_inter * dirListaIntermDup );

void transformar_etiqueta_comparador_a_assembler( char *etiquetaIntermedia, char *comparadorAssembler );

void procesar_celda( char* cuerpoAssembler, t_lista_cod_inter *listaCodIntermedio );


void suma_assembler( char *cuerpoAssembler, char *tipoDatoResult );
void resta_assembler( char *cuerpoAssembler, char *tipoDatoResult );
void mulplicacion_assembler( char *cuerpoAssembler, char *tipoDatoResult );
void division_assembler( char *cuerpoAssembler, char *tipoDatoResult );
void operacion_matematica ( char *cuerpoAssembler, char *tipoDatoResult, char *instruccionMatematica  );

void asignacion_assembler( char *cuerpoAssembler);
void read_assembler( char *cuerpoAssembler );
void write_assembler( char *cuerpoAssembler0);
void salto_incondicional_assembler( char *cuerpoAssembler, t_lista_cod_inter *dirListaInterm);
void procesar_etiqueta_while_assembler( char * cuerpoAssembler );
void comparacion_assembler( char *cuerpoAssembler, t_lista_cod_inter *dirListaInterm );


void insertar_en_tabla_de_simbolos_auxiliares_assembler();
void extraer_celda_de_cod_intermedio (t_lista_cod_inter *dirListaInterm, char* lexema, char *tipo , char *cuerpoAssembler);
void imprimir_cuerpo_codigo_assembler( FILE* archivoAssembler, char *cuerpoAssembler );
int es_operando( char *elemento );
void desapilar_tipo_de_dato( char* tipo );
void resolver_y_apilar_tipo_de_dato_por_operacion( char operador , char* tipoDaroResult);
void guardar_comparador( char* comparador );

void get_en_polaca( char * lexema );
void display_en_polaca( char * lexema, char* tipoLex );
/// ERROR EN GENERACION DE ASSEMBLER //////
void errorEnGenerarAssembler( char* mensaje);

/////////////////////////////////
//DEFINICION DE TDAs NECESARIOS//
/////////////////////////////////

t_lista_cod_inter listaDuplicadaDeCodigoIntermedio;
t_lista listaTSDuplicada;
t_pila_celdas  pilaDeOperandosAssembler;
t_pila_ent pilaDeCondicionesAplicadas;

/// VARIABLES DE WHILE /////
t_pila_ent pilaInicioDeWhile;

/// VARIABLES PARA ANALISIS SEMANTICO ////////////////////////////////
int num_celda_actual=0;
t_lista_cod_inter listaIntermedio;

int flagOpNot= FALSE;
char comparador_guardado[20];

t_pila_str pilaTipoDeDatoIzquierdo;
t_pila_str pilaTipoDeDato;
char tipoDeDatoDeUltimaExpresion [20];

/// AUXILIARES ASSEMBLER    <----

t_pila_celdas pilaAuxiliaresAssembler;
int numAuxAssembler=0;

int numCeldaProcesada=0;
t_lista_etq listaEtiquetas;

/// UN POCO DE TODO 2 /////
void asignar_tipo_a_lexema_en_ts ( char *lexema , char *tipo );
void calcular_tipo_dato_resultante ( char *izq, char* der , char operador , char* resultado );
void guardar_tipo_de_parte_izquierda();
void guardar_tipo_de_dato_id_para_tipo_expresion_e_insertar_en_polaca( char *nombreLexema );
void recuperar_tipo_izquierdo( char* retornoTipo );
void apilar_condicion_aplicada(int condicion);

//// FUNCIONES PARA VARIABLES AUX DE TS
void insertar_auxiliar_en_ts( char* nombreAuxiliar, char* tipoDato);
void generarNuevoAuxiliar( );
	
//// GENERACION DE AUXILIARES /////////
char ultimoAuxiliarGenerado [20];
int cantAuxiliaresGenerados=0;
char tipoDatoAuxEnInlist [20];
t_pila_str pilaTiposAssembler;

///    ts      ///
void imprimir_tabla_de_simbolos_en_archivo();
void crear_tabla_simbolos();
void borrar_tabla_simbolos();
int ver_ultima_condicion_aplicada();

/// FUNCIONES PARA CODIGO INTERMEDIO ///////
void insertar_en_polaca( char* cadena, char * tipo);
void avanzar();
void apilar_celda_actual();
void desapilar_posicion( int *posicion );
int crear_archivo_notacion_intermedia( t_lista_cod_inter *dirLista);
int crear_archivo_logs( t_lista_cod_inter *dirLista);
void actualizar_celda( int numCelda, int contenidoNum );
void apilar_celda_especifica ( int celda );
void comparar_tipos_en_comparacion();


/// LISTA DE TABLA DE SIMBOLOS ////////////

t_lista listaTS;

///DE TODO UN POCO  ///////
int posicion_celda_actual=0;
void encolar_id_para_tipificar (char *id);
void encolar_id_para_longitud (char *id);
void tipificar_ids_en_tabla_de_simbolos();
void apilar_tipos_datos (char *dato);
void contar_longitud ();

/// PILAS PARA DECLARACION DE VARIABLES //////
t_cola  cola_de_ids_declaracion; 
t_cola  cola_de_ids_longitud; 
t_pila  pila_de_tipos_declaracion;
t_pila_ent pilaDeCeldas;
t_lista_cod_inter listaIntermedio;
t_pila_str pilaTiposAssembler;

/// FUNCIONES PARA ASIGNACION ////////
void realizar_asignacion();

/// VARIABLES PARA ASIGNACION ///////
	t_cola  cola_de_ids_asig;
	char tipo_dato_asig [30];

/// ERROR SEMANTICO ///////////////
int errorSemantico();


int yyerror();

int yylex();	


/* Line 189 of yacc.c  */
#line 276 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
#line 203 "Sintactico.y"

	char str_val[100];
	



/* Line 214 of yacc.c  */
#line 407 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 419 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   188

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNRULES -- Number of states.  */
#define YYNSTATES  138

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    18,
      20,    22,    27,    33,    39,    41,    43,    45,    49,    53,
      55,    59,    62,    65,    68,    69,    80,    88,    98,   107,
     116,   118,   122,   124,   128,   130,   132,   140,   147,   148,
     152,   154,   156,   158,   162,   163,   168,   172,   174,   176,
     178,   180,   182,   184,   188,   192,   194,   201,   204,   206,
     210,   214,   218,   220,   224,   226,   228,   230,   232,   234
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    47,    -1,    48,    -1,    47,    48,    -1,
      49,    -1,    54,    -1,    55,    -1,    56,    -1,    62,    -1,
      52,    -1,    18,    42,    50,    43,    -1,     3,    40,    50,
      40,    51,    -1,     3,    43,    19,    42,    51,    -1,     9,
      -1,     7,    -1,     8,    -1,    53,    27,    70,    -1,    53,
      27,     4,    -1,     3,    -1,    53,    27,     3,    -1,    17,
       3,    -1,    17,    74,    -1,    16,     3,    -1,    -1,    12,
      37,    63,    38,    13,    47,    14,    57,    47,    15,    -1,
      12,    37,    58,    38,    13,    47,    15,    -1,    12,    37,
      58,    38,    13,    47,    14,    47,    15,    -1,    20,    37,
      70,    39,    42,    60,    43,    38,    -1,    21,    37,    70,
      39,    42,    59,    43,    38,    -1,    61,    -1,    59,    40,
      61,    -1,    61,    -1,    60,    40,    61,    -1,    75,    -1,
       3,    -1,    12,    37,    63,    38,    13,    47,    15,    -1,
      10,    37,    63,    38,    47,    11,    -1,    -1,    36,    64,
      68,    -1,    65,    -1,    66,    -1,    68,    -1,    68,    34,
      68,    -1,    -1,    68,    67,    35,    68,    -1,    70,    69,
      70,    -1,    30,    -1,    28,    -1,    31,    -1,    29,    -1,
      32,    -1,    33,    -1,    70,    23,    72,    -1,    70,    24,
      72,    -1,    72,    -1,    22,    37,    42,    71,    43,    38,
      -1,    24,    70,    -1,     3,    -1,    71,    40,     3,    -1,
      72,    25,    73,    -1,    72,    26,    73,    -1,    73,    -1,
      37,    70,    38,    -1,    74,    -1,     3,    -1,    75,    -1,
       4,    -1,     5,    -1,     6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   275,   275,   280,   283,   286,   287,   288,   289,   290,
     291,   296,   301,   306,   312,   313,   314,   318,   329,   341,
     344,   349,   350,   354,   357,   357,   416,   419,   422,   439,
     456,   461,   489,   494,   521,   522,   526,   529,   532,   532,
     536,   539,   543,   549,   551,   551,   569,   578,   582,   586,
     590,   594,   598,   604,   607,   610,   611,   614,   619,   620,
     623,   626,   629,   632,   633,   634,   641,   642,   645,   646
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "CTE_STRING", "CTE_ENT",
  "CTE_REAL", "T_FLOAT", "T_STRING", "T_INT", "WHILE", "ENDWHILE", "IF",
  "THEN", "ELSE", "ENDIF", "GET", "DISPLAY", "DIM", "AS", "EQUMAX",
  "EQUMIN", "LONG", "OP_SUM", "OP_RES", "OP_MULT", "OP_DIV", "OP_ASIG",
  "OP_MAY", "OP_MAY_IG", "OP_MEN", "OP_MEN_IG", "OP_IGUAL", "OP_DIST",
  "OP_AND", "OP_OR", "OP_NOT", "PA", "PC", "PYC", "COMA", "DOS_PUNT",
  "COR_A", "COR_C", "MENOS_UNARIO", "$accept", "inicio", "programa",
  "sentencia", "dec_var", "lista_simetrica", "tipo_dato", "asignacion",
  "lista_de_asignaciones", "impresion", "lectura", "condicional", "$@1",
  "equ", "lista_factores_equmin", "lista_factores_equmax", "equfactor",
  "iteracion", "condicion", "$@2", "condicion_multiple_and",
  "condicion_multiple_or", "$@3", "condicion_simple", "comparador",
  "expresion", "lista_id", "termino", "factor", "constante",
  "constante_num", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    48,    48,
      48,    49,    50,    50,    51,    51,    51,    52,    52,    53,
      53,    54,    54,    55,    57,    56,    56,    56,    58,    58,
      59,    59,    60,    60,    61,    61,    56,    62,    64,    63,
      63,    63,    63,    65,    67,    66,    68,    69,    69,    69,
      69,    69,    69,    70,    70,    70,    70,    70,    71,    71,
      72,    72,    72,    73,    73,    73,    74,    74,    75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     4,     5,     5,     1,     1,     1,     3,     3,     1,
       3,     2,     2,     2,     0,    10,     7,     9,     8,     8,
       1,     3,     1,     3,     1,     1,     7,     6,     0,     3,
       1,     1,     1,     3,     0,     4,     3,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     6,     2,     1,     3,
       3,     3,     1,     3,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    19,     0,     0,     0,     0,     0,     0,     2,     3,
       5,    10,     0,     6,     7,     8,     9,     0,     0,    23,
      21,    67,    68,    69,    22,    66,     0,     1,     4,     0,
      65,     0,     0,    38,     0,     0,    40,    41,    42,     0,
      55,    62,    64,     0,     0,     0,     0,     0,     0,    65,
      18,    17,     0,    57,     0,     0,     0,     0,     0,     0,
       0,    48,    50,    47,    49,    51,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,     0,    39,    63,
       0,    43,     0,    53,    54,    46,    60,    61,     0,     0,
       0,     0,     0,     0,    58,     0,    37,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
      24,    36,    15,    16,    14,    12,    13,    59,    56,    35,
       0,    32,    34,     0,    30,     0,     0,     0,     0,     0,
       0,    27,     0,    33,    28,    31,    29,    25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    48,   115,    11,    12,    13,
      14,    15,   126,    45,   123,   120,   121,    16,    35,    54,
      36,    37,    58,    38,    67,    39,    95,    40,    41,    42,
      25
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -56
static const yytype_int16 yypact[] =
{
     135,   -56,   -33,   -13,    25,    70,   -12,    34,   135,   -56,
     -56,   -56,    24,   -56,   -56,   -56,   -56,     9,     5,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,    59,   -56,   -56,    15,
     -56,    47,    44,   -56,    44,    57,   -56,   -56,    43,   126,
     140,   -56,   -56,    66,    68,    75,    81,   -37,    86,   107,
     137,   145,   102,   -56,    44,    41,   135,    44,   113,    51,
      51,   -56,   -56,   -56,   -56,   -56,   -56,    44,    51,    51,
      44,    44,   133,   159,    59,   156,   -56,   173,   -56,   -56,
     104,   -56,    44,   140,   140,   145,   -56,   -56,    -7,    -1,
     135,   135,   138,   139,   -56,    83,   -56,   -56,   141,   142,
      84,    94,    82,    82,   174,   144,    64,    64,   135,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
      96,   -56,   -56,   124,   -56,   115,   135,    64,   147,    64,
     148,   -56,   125,   -56,   -56,   -56,   -56,   -56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -56,   -56,   -55,    -8,   -56,   106,    76,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -44,   -56,   169,   -56,
     -56,   -56,   -56,     4,   -56,   -27,   -56,   111,   105,   183,
     -47
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -68
static const yytype_int16 yytable[] =
{
      28,    80,    51,    74,    17,    53,    75,    55,    30,    21,
      22,    23,    30,    21,    22,    23,    59,    60,    49,    50,
      22,    23,    59,    60,    18,    43,    44,    31,    19,    32,
      26,    31,    98,    32,    27,   100,   101,    31,    99,    32,
      85,    33,    34,    88,    89,    33,    34,    30,    21,    22,
      23,    29,    34,   125,    30,    21,    22,    23,    78,   122,
     122,    81,    47,   124,    59,    60,    31,   119,    32,    22,
      23,   132,    28,    20,    21,    22,    23,    57,   -44,    79,
     122,    34,   122,   133,    52,   135,    97,     1,    34,   112,
     113,   114,    28,    28,     2,    56,     3,     1,   108,   109,
       4,     5,     6,    70,     2,    71,     3,     1,   110,   111,
       4,     5,     6,    72,     2,    96,     3,    28,     1,    73,
       4,     5,     6,   104,    28,     2,   105,     3,     1,    76,
     131,     4,     5,     6,   -20,     2,   127,     3,     1,   128,
     137,     4,     5,     6,    77,     2,    90,     3,    82,    59,
      60,     4,     5,     6,    61,    62,    63,    64,    65,    66,
     -67,   -67,   -67,   -67,   129,    68,    69,   130,    59,    60,
      83,    84,    91,    86,    87,    93,    94,   117,   102,   116,
      92,   103,   118,   106,   107,   134,   136,    46,    24
};

static const yytype_uint8 yycheck[] =
{
       8,    56,    29,    40,    37,    32,    43,    34,     3,     4,
       5,     6,     3,     4,     5,     6,    23,    24,     3,     4,
       5,     6,    23,    24,    37,    20,    21,    22,     3,    24,
      42,    22,    39,    24,     0,    90,    91,    22,    39,    24,
      67,    36,    37,    70,    71,    36,    37,     3,     4,     5,
       6,    27,    37,   108,     3,     4,     5,     6,    54,   106,
     107,    57,     3,   107,    23,    24,    22,     3,    24,     5,
       6,   126,    80,     3,     4,     5,     6,    34,    35,    38,
     127,    37,   129,   127,    37,   129,    82,     3,    37,     7,
       8,     9,   100,   101,    10,    38,    12,     3,    14,    15,
      16,    17,    18,    37,    10,    37,    12,     3,    14,    15,
      16,    17,    18,    38,    10,    11,    12,   125,     3,    38,
      16,    17,    18,    40,   132,    10,    43,    12,     3,    43,
      15,    16,    17,    18,    27,    10,    40,    12,     3,    43,
      15,    16,    17,    18,    42,    10,    13,    12,    35,    23,
      24,    16,    17,    18,    28,    29,    30,    31,    32,    33,
      23,    24,    25,    26,    40,    25,    26,    43,    23,    24,
      59,    60,    13,    68,    69,    19,     3,     3,    40,   103,
      74,    42,    38,    42,    42,    38,    38,    18,     5
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    10,    12,    16,    17,    18,    46,    47,    48,
      49,    52,    53,    54,    55,    56,    62,    37,    37,     3,
       3,     4,     5,     6,    74,    75,    42,     0,    48,    27,
       3,    22,    24,    36,    37,    63,    65,    66,    68,    70,
      72,    73,    74,    20,    21,    58,    63,     3,    50,     3,
       4,    70,    37,    70,    64,    70,    38,    34,    67,    23,
      24,    28,    29,    30,    31,    32,    33,    69,    25,    26,
      37,    37,    38,    38,    40,    43,    43,    42,    68,    38,
      47,    68,    35,    72,    72,    70,    73,    73,    70,    70,
      13,    13,    50,    19,     3,    71,    11,    68,    39,    39,
      47,    47,    40,    42,    40,    43,    42,    42,    14,    15,
      14,    15,     7,     8,     9,    51,    51,     3,    38,     3,
      60,    61,    75,    59,    61,    47,    57,    40,    43,    40,
      43,    15,    47,    61,    38,    61,    38,    15
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 275 "Sintactico.y"
    { printf("\nCOMPILACION EXITOSA");
																	genera_assembler();
																}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 280 "Sintactico.y"
    { printf("\n<programa> -> <sentencia>"); }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 283 "Sintactico.y"
    { printf("\n<programa> -> <programa> <sentencia>"); }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 286 "Sintactico.y"
    { printf("\n<sentencia> -> <declaracion de variables>"); }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 287 "Sintactico.y"
    { printf("\n<sentencia> -> <impresion>"); }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 288 "Sintactico.y"
    { printf("\n<sentencia> -> <lectura>"); }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 289 "Sintactico.y"
    { printf("\n<sentencia> -> <condicional>"); }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 290 "Sintactico.y"
    { printf("\n<sentencia> -> <iteracion>"); }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 291 "Sintactico.y"
    { printf("\n<sentencia> -> <asignacion>"); }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 296 "Sintactico.y"
    { printf("\n<dec_var> -> DIM COR_A <lista_simetrica> COR_C"); 
																tipificar_ids_en_tabla_de_simbolos();
}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 301 "Sintactico.y"
    { printf("\n<lista_simetrica> -> ID COMA <lista_simetrica> COMA <tipo_dato> ");
																	
																encolar_id_para_tipificar((yyvsp[(1) - (5)].str_val));
																}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 306 "Sintactico.y"
    { printf("\n<lista_simetrica> -> ID COR_C AS COR_A <tipo_dato> "); 
															
																encolar_id_para_tipificar((yyvsp[(1) - (5)].str_val));
																}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 312 "Sintactico.y"
    { printf("\n<tipo_dato> -> T_INT"); apilar_tipos_datos( "int");}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 313 "Sintactico.y"
    { printf("\n<tipo_dato> -> T_FLOAT"); apilar_tipos_datos( "float");}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 314 "Sintactico.y"
    { printf("\n<tipo_dato> -> T_STRING"); apilar_tipos_datos( "string");}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 318 "Sintactico.y"
    {printf("\n<asignacion> -> <lista_de_asignaciones> OP_ASIG <expresion>"); 
																			//insertar_en_polaca("@aux_asig", TIPO_STRING);}	
																			generarNuevoAuxiliar( "@aux_asig" );
																			insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_ENTERO);
																			insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_ENTERO);		
																			insertar_en_polaca(":=", TIPO_VACIO);
																			strcpy(tipo_dato_asig, "numerico");
																			realizar_asignacion();
																			}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 330 "Sintactico.y"
    { printf("\n<asignacion> --> <lista_de_asignaciones> OP_ASIG <CONST_STRING>");
																			  	generarNuevoAuxiliar( "@aux_asig" );
																			insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_ENTERO);
																			insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_ENTERO);
																			  insertar_en_polaca((yyvsp[(3) - (3)].str_val), TIPO_STRING);
																			  insertar_en_polaca(":=", TIPO_VACIO);
																			  strcpy(tipo_dato_asig, "string");
																			  realizar_asignacion();
																			}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 341 "Sintactico.y"
    { printf("\n<lista_de_asignaciones> -> ID"); 
																			encolar( &cola_de_ids_asig, yylval.str_val);
																			}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 344 "Sintactico.y"
    { printf("\n<lista_de_asignaciones> -> <lista_de_asignaciones> OP_ASIG ID");
																			encolar( &cola_de_ids_asig, yylval.str_val); }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 349 "Sintactico.y"
    { printf("\n<impresion> -> DISPLAY ID");display_en_polaca( yylval.str_val, "ID" ); }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 350 "Sintactico.y"
    { printf("\n<impresion> -> DISPLAY <constante>"); 																				asignar_tipo_a_lexema_en_ts ( yylval.str_val, TIPO_STRING );
																			  display_en_polaca( yylval.str_val, TIPO_STRING );}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 354 "Sintactico.y"
    { printf("\n<lectura> -> GET ID"); get_en_polaca( yylval.str_val );}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 357 "Sintactico.y"
    {			int posDesap;
																	int posDesapGuard;

																	if( ver_ultima_condicion_aplicada() == CONDICION_SIMPLE )
																	{
																			insertar_en_polaca(OPERADOR_BI, TIPO_VACIO);
								   											desapilar_posicion(&posDesap);
															    			actualizar_celda( posDesap, num_celda_actual+1 );
																			apilar_celda_actual();
					    													avanzar();

																	}
															    													
																	if( ver_ultima_condicion_aplicada() == CONDICION_MULTIPLE_AND )
															    	{		
															  				insertar_en_polaca(OPERADOR_BI, TIPO_VACIO);
																			desapilar_posicion(&posDesap);
																			actualizar_celda(posDesap, num_celda_actual+1);
																			desapilar_posicion(&posDesap);
																			actualizar_celda(posDesap, num_celda_actual+1);
																			apilar_celda_actual();
																			avanzar();
																	}
																														
																	if( ver_ultima_condicion_aplicada() == CONDICION_MULTIPLE_OR )
																	{
																		insertar_en_polaca(OPERADOR_BI, TIPO_VACIO);
 																		desapilar_posicion(&posDesap);
 																		actualizar_celda( posDesap, num_celda_actual+1 );
 																		apilar_celda_actual();
 																		avanzar();
																	}

															    }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 392 "Sintactico.y"
    { int posDesap;
																	printf("\n<seleccion> --> IF( <condicion> )THEN <programa> ELSE <programa> ENDIF ");
																	if( ver_ultima_condicion_aplicada() == CONDICION_SIMPLE )
																	{
																		desapilar_posicion(&posDesap);
																		actualizar_celda( posDesap, num_celda_actual );
																	}

																	if( ver_ultima_condicion_aplicada() == CONDICION_MULTIPLE_AND )
				    												{		
																		desapilar_posicion(&posDesap);
																		actualizar_celda(posDesap, num_celda_actual);
																	}

																	if( ver_ultima_condicion_aplicada() == CONDICION_MULTIPLE_OR )
																	{
		  																desapilar_posicion(&posDesap);
			   													   	actualizar_celda(posDesap, num_celda_actual);
																	}

															
																}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 416 "Sintactico.y"
    { printf("\n<condicional> -> IF( <equ> ) THEN <programa> ENDIF"); }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 419 "Sintactico.y"
    { printf("\n<condicional> -> IF( <equ> )THEN <programa> ELSE <programa> ENDIF "); }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 422 "Sintactico.y"
    { printf("\n<equ> -> EQUMAX PA expresion PYC COR_A lista_factores_equmax COR_C PC");
int posDesap;
																generarNuevoAuxiliar( "@max" );
																insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_ENTERO);
																insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_ENTERO); 
																generarNuevoAuxiliar( "@exp" );
																insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_ENTERO);
																insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_ENTERO);
insertar_en_polaca (OPERADOR_CMP, TIPO_VACIO); insertar_en_polaca (OPERADOR_BLE, TIPO_VACIO);apilar_celda_actual();avanzar();
generarNuevoAuxiliar( "@equmax" );
																insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_STRING);
																insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_STRING);
insertar_en_polaca ("TRUE", TIPO_STRING);insertar_en_polaca(":=", TIPO_VACIO);
desapilar_posicion( &posDesap );actualizar_celda(posDesap, num_celda_actual + 1);
insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_STRING); insertar_en_polaca ("FALSE", TIPO_STRING);insertar_en_polaca(":=", TIPO_VACIO);}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 439 "Sintactico.y"
    { printf("\n<equ> -> EQUMIN PA expresion PYC COR_A 		lista_factores_equmin COR_C PC");
		int posDesap;
																generarNuevoAuxiliar( "@min" );
																insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_ENTERO);
																insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_ENTERO);
																generarNuevoAuxiliar( "@exp" );
																insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_ENTERO);
																insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_ENTERO);
		insertar_en_polaca (OPERADOR_CMP, TIPO_VACIO); insertar_en_polaca (OPERADOR_BGE , TIPO_VACIO);apilar_celda_actual();avanzar();
		generarNuevoAuxiliar( "@equmin" );
																insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_STRING);
																insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_STRING);
		insertar_en_polaca ("TRUE", TIPO_STRING);insertar_en_polaca(":=", TIPO_VACIO);
		desapilar_posicion( &posDesap );actualizar_celda(posDesap, num_celda_actual + 1);
		insertar_en_polaca (ultimoAuxiliarGenerado, TIPO_STRING); insertar_en_polaca ("FALSE", TIPO_STRING);insertar_en_polaca(":=", TIPO_VACIO);}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 456 "Sintactico.y"
    { printf("\n<lista_factores_equmin> -> <equfactor> ");
																generarNuevoAuxiliar( "@min" );
																insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_ENTERO);
																insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_ENTERO); 
																	insertar_en_polaca(":=", TIPO_VACIO);}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 461 "Sintactico.y"
    { printf("\n<lista_factores_equmin> -> <lista_factores_equmax> COMA <equfactor> "); int posDesap;
																generarNuevoAuxiliar( "@aux" );
																insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_ENTERO);
																insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_ENTERO); 
				insertar_en_polaca(":=", TIPO_VACIO); 
																generarNuevoAuxiliar( "@aux" );
																insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_ENTERO);
																insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_ENTERO); 

																generarNuevoAuxiliar( "@max" );
																insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_ENTERO);
																insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_ENTERO); 
				insertar_en_polaca(OPERADOR_CMP, TIPO_VACIO); insertar_en_polaca (OPERADOR_BLE, TIPO_VACIO); 
				apilar_celda_actual();avanzar(); 
																generarNuevoAuxiliar( "@aux" );
																insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_ENTERO);
																insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_ENTERO);  
				
																generarNuevoAuxiliar( "@max" );
																insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_ENTERO);
																insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_ENTERO); 
				
				insertar_en_polaca(":=", TIPO_VACIO); 
				desapilar_posicion( &posDesap );actualizar_celda(posDesap, num_celda_actual + 1);}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 489 "Sintactico.y"
    { printf("\n<lista_factores_equmax> -> <equfactor> ");
																generarNuevoAuxiliar( "@max" );
																insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_ENTERO);
																insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_ENTERO); 
																	insertar_en_polaca(":=", TIPO_VACIO);}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 494 "Sintactico.y"
    { printf("\n<lista_factores_equmax> -> <lista_factores_equmax> COMA <equfactor> "); int posDesap;
																generarNuevoAuxiliar( "@aux" );
																insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_ENTERO);
																insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_ENTERO); 
				insertar_en_polaca(":=", TIPO_VACIO); 
																generarNuevoAuxiliar( "@aux" );
																insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_ENTERO);
																insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_ENTERO); 

																generarNuevoAuxiliar( "@max" );
																insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_ENTERO);
																insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_ENTERO); 
				insertar_en_polaca(OPERADOR_CMP, TIPO_VACIO); insertar_en_polaca (OPERADOR_BLE, TIPO_VACIO); 
				apilar_celda_actual();avanzar(); 
																generarNuevoAuxiliar( "@aux" );
																insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_ENTERO);
																insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_ENTERO);  
				
																generarNuevoAuxiliar( "@max" );
																insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_ENTERO);
																insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_ENTERO); 
				
				insertar_en_polaca(":=", TIPO_VACIO); 
				desapilar_posicion( &posDesap );actualizar_celda(posDesap, num_celda_actual + 1);}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 521 "Sintactico.y"
    { printf("\n<equfactor> -> <constante_num> "); }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 522 "Sintactico.y"
    { printf("\n<equfactor> -> ID ");insertar_en_polaca( yylval.str_val , TIPO_STRING); }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 526 "Sintactico.y"
    { printf("\n<condicional> -> IF( <condicion>) THEN <programa> ENDIF"); }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 529 "Sintactico.y"
    { printf("\n<iteracion> -> WHILE ( <condicion> ) <programa> ENDWHILE}"); }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 532 "Sintactico.y"
    { flagOpNot=TRUE; }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 532 "Sintactico.y"
    { printf("\n<condicion> --> NOT <condicion_simple>");
																					apilar_condicion_aplicada(CONDICION_SIMPLE);
																				}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 536 "Sintactico.y"
    {	 printf("\n<condicion> --> <condicion_multiple_and>");
																				apilar_condicion_aplicada(CONDICION_MULTIPLE_AND); }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 539 "Sintactico.y"
    {		 printf("\n<condicion> --> <condicion_multiple_or>");
																					apilar_condicion_aplicada(CONDICION_MULTIPLE_OR);
																			}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 543 "Sintactico.y"
    { printf("\n<condicion> --> <condicion_simple>");
																						apilar_condicion_aplicada(CONDICION_SIMPLE);
																					 }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 549 "Sintactico.y"
    { printf("\n<condicion_multiple_and> --> <condicion_simple> AND <condicion_simple>"); }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 551 "Sintactico.y"
    { int posDesap;
										 								 insertar_en_polaca(OPERADOR_BI, TIPO_VACIO);
										 								 desapilar_posicion(&posDesap);
																		 actualizar_celda(posDesap, num_celda_actual+1);
										  								 apilar_celda_actual();
										 								 avanzar();						 
																		}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 559 "Sintactico.y"
    { printf("\n<condicion_multiple_or> --> <condicion_simple> OR <condicion_simple>");
																int posDesap, apiladoGuardado;
 													  			desapilar_posicion(&apiladoGuardado);
 													  			desapilar_posicion(&posDesap);
 													 			actualizar_celda(posDesap, num_celda_actual);
 													 			apilar_celda_especifica(apiladoGuardado);
 													 									
 													 		}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 569 "Sintactico.y"
    {  printf("\n<condicion_simple> --> <expresion> <comparador> <expresion>");
																			 			insertar_en_polaca(OPERADOR_CMP, TIPO_VACIO);
																			   			insertar_en_polaca(comparador_guardado, TIPO_VACIO);
																						apilar_celda_actual();
																			   			avanzar();
																			   			comparar_tipos_en_comparacion();
																					 }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 578 "Sintactico.y"
    { printf("\n<comparador> --> <"); 
															  guardar_comparador(OPERADOR_BGE);
															}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 582 "Sintactico.y"
    { printf("\n<comparador> --> >");
																  		guardar_comparador(OPERADOR_BLE);
																}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 586 "Sintactico.y"
    { printf("\n<comparador> --> <=");
																  guardar_comparador(OPERADOR_BGT);
																}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 590 "Sintactico.y"
    { printf("\n<comparador> --> >=");
																  guardar_comparador(OPERADOR_BLT);
																}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 594 "Sintactico.y"
    { printf("\n<comparador> --> ==");
																  guardar_comparador(OPERADOR_BNE);
																}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 598 "Sintactico.y"
    { printf("\n<comparador> --> !=");
																  guardar_comparador(OPERADOR_BEQ);
																}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 604 "Sintactico.y"
    { printf("\n<expresion> -> <expresion> + <termino>");char tipoResultante[20];
																 resolver_y_apilar_tipo_de_dato_por_operacion( '+', tipoResultante );
																 insertar_en_polaca("+", tipoResultante);}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 607 "Sintactico.y"
    { printf("\n<expresion> -> <expresion> - <termino>");char tipoResultante[20];
																 resolver_y_apilar_tipo_de_dato_por_operacion( '-', tipoResultante );
																 insertar_en_polaca("-", tipoResultante);}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 610 "Sintactico.y"
    { printf("\n<expresion> -> <termino>"); }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 611 "Sintactico.y"
    { printf("\n<expresion> -> LONG PA COR_A <lista_id> COR_C PC"); contar_longitud();}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 614 "Sintactico.y"
    { printf("\n<expresion> -> OP_RES <expresion>");
																	insertar_en_polaca("-1", TIPO_ENTERO);
																	insertar_en_polaca("*", TIPO_VACIO); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 619 "Sintactico.y"
    { printf("\n<lista_id> -> ID");insertar_en_polaca( yylval.str_val, TIPO_STRING );}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 620 "Sintactico.y"
    { printf("\n<lista_id> -> lista_id COMA ID");insertar_en_polaca( yylval.str_val , TIPO_STRING); encolar_id_para_longitud("id");}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 623 "Sintactico.y"
    { printf("\n<termino> -> <termino> * <factor>"); char tipoResultante[20];
																 resolver_y_apilar_tipo_de_dato_por_operacion( '*', tipoResultante );
																 insertar_en_polaca("*", tipoResultante);}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 626 "Sintactico.y"
    { printf("\n<termino> -> <termino> / <factor>");char tipoResultante[20];
																 resolver_y_apilar_tipo_de_dato_por_operacion( '/', tipoResultante );
																 insertar_en_polaca("/", tipoResultante);}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 629 "Sintactico.y"
    { printf("\n<termino> -> <factor>"); }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 632 "Sintactico.y"
    { printf("\n<factor> -> ( <expresion> )"); }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 633 "Sintactico.y"
    { printf("\n<factor> -> constante "); }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 634 "Sintactico.y"
    { printf("\n<factor> -> ID ");						   					
																guardar_tipo_de_dato_id_para_tipo_expresion_e_insertar_en_polaca( yylval.str_val ); }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 641 "Sintactico.y"
    { printf("\n<constante> -> <constante_num>"); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 642 "Sintactico.y"
    { printf("\n<constante> -> CTE_STRING");insertar_en_polaca( (yyvsp[(1) - (1)].str_val) , TIPO_STRING); asignar_tipo_a_lexema_en_ts ( (yyvsp[(1) - (1)].str_val), TIPO_STRING ); apilar_tipos_datos(TIPO_STRING);}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 645 "Sintactico.y"
    { printf("\n<constante_num> -> CTE_ENT");insertar_en_polaca( (yyvsp[(1) - (1)].str_val), TIPO_ENTERO );asignar_tipo_a_lexema_en_ts ( yylval.str_val, TIPO_ENTERO ); apilar_tipos_datos(TIPO_ENTERO);}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 646 "Sintactico.y"
    { printf("\n<constante_num> -> CTE_REAL");insertar_en_polaca( (yyvsp[(1) - (1)].str_val), TIPO_FLOTANTE ); asignar_tipo_a_lexema_en_ts ( yylval.str_val , TIPO_FLOTANTE );apilar_tipos_datos(TIPO_FLOTANTE);}
    break;



/* Line 1455 of yacc.c  */
#line 2435 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 651 "Sintactico.y"

/// GENERACION DE CODIGO INTER-MEDIO //////////////////

void crear_archivo_para_codigo_intermedio()
{
		FILE * arch= fopen("intermedia.txt", "wt" );
		fprintf(arch,"||");
		fclose(arch);
}

void destruir_archivo_codigo_intermedio()
{
	remove("intermedia.txt");
}

void insertar_en_polaca( char* cadena, char * tipo)
{
	insertar_en_lista_inter(&listaIntermedio, cadena, tipo);
	num_celda_actual++;
}

//*****************************************
void avanzar () 
{
	insertar_en_polaca("", TIPO_VACIO);	
}

void apilar_celda_actual()
{
	apilar_ent( &pilaDeCeldas , &num_celda_actual );
}

void apilar_condicion_aplicada(int condicion)
{
	apilar_ent(&pilaDeCondicionesAplicadas, &condicion);
}

void desapilar_posicion( int *posicion )
{
	desapilar_ent( &pilaDeCeldas, posicion);
}

void actualizar_celda( int numCelda, int contenidoNum )
{
	char contenido[20];
	itoa(contenidoNum, contenido, 10);
	actualizar_contenido_de_celda ( &listaIntermedio, numCelda, contenido );
}


void apilar_celda_especifica ( int celda )
{
	apilar_ent( &pilaDeCeldas , &celda );
}

/// FUNCIONALIDADES DE DECLARACION DE VARIABLES

void encolar_id_para_tipificar (char *dato)
{
	encolar ( &cola_de_ids_declaracion, dato);
}

void encolar_id_para_longitud (char *dato)
{
	encolar ( &cola_de_ids_longitud, dato);
}

void apilar_tipos_datos (char *dato)
{
	apilar ( &pila_de_tipos_declaracion, dato);
}

// agrega el tipo del dato al lexema dentro de la TS
void tipificar_ids_en_tabla_de_simbolos()
{
	char id [100];
	char tipo_d [100];
	int resultado_de_tipificar_id;
	int resultado;
	while( ! colaVacia ( &cola_de_ids_declaracion ) )
	{
		desapilar ( &pila_de_tipos_declaracion, tipo_d);
		desacolar ( &cola_de_ids_declaracion, id);
		printf("\n****%s   ",id);
		printf("\n****%s  \n ",tipo_d);
		resultado=asignar_tipo_a_lexema(&listaTS, id, tipo_d);
		if( resultado == LEXEMA_YA_DECLARADO)
		{
			errorSemantico("Error: El id: %s\n Fue declarado mas de 1 vez", id);
		}
		if( resultado == LEXEMA_NO_ENCONTRADO )
		{
			errorSemantico("Error en la Tipificacion del ID: %s", id);
		}
	}
}
//// FUNCIONALIDADES DE ASIGNACION 
void realizar_asignacion()
{
	char id[100];
	char mensaje [300];
	t_lexema lexema_id;
	while( ! colaVacia(&cola_de_ids_asig) )
	{
		desacolar(&cola_de_ids_asig, id );
		if( buscar_en_lista (&listaTS, id, &lexema_id) == TRUE )
		{
			if( strcmp(tipo_dato_asig, "string" )==0 )
			{
				if( strcmp(lexema_id.tipo, "string") == 0 )
				{
					generarNuevoAuxiliar( "@aux_asig" );
					insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_STRING);
					insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_STRING);
					insertar_en_polaca(id, TIPO_STRING);
										
					insertar_en_polaca(":=", TIPO_VACIO);
				}
				else
				{
					sprintf(mensaje, "Error:Tipos de Dato Diferentes: Esta intentando asignar a %s un tipo de dato diferente al de su declaracion.", lexema_id.nombre);
					errorSemantico(mensaje);
				}
			}
			else
			{
				if( strcmp(lexema_id.tipo, "int") == 0 )
				{
					generarNuevoAuxiliar( "@aux_asig" );
					insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_ENTERO);
					insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_ENTERO);
					insertar_en_polaca(id, TIPO_ENTERO);
									
					insertar_en_polaca(":=", TIPO_VACIO);
				}else if(strcmp(lexema_id.tipo, "float") == 0 ){
					generarNuevoAuxiliar( "@aux_asig" );
					insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_FLOTANTE);
					insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_FLOTANTE);
					insertar_en_polaca(id, TIPO_FLOTANTE);
									
					insertar_en_polaca(":=", TIPO_VACIO);
				}
				else
				{
						sprintf(mensaje, "Error: Tipos de Dato Diferentes: Esta intentando asignar a %s un tipo de dato diferente al de su declaracion.", lexema_id.nombre);
					errorSemantico(mensaje);
				}		
			}

		}

	}
}
void contar_longitud(){
	int longitud = 1;
	char slongitud [5];
	char id[100];
	t_lexema lexema_id;
	while( ! colaVacia(&cola_de_ids_longitud) ){
		longitud++;
		desacolar(&cola_de_ids_longitud, id );
	}
	//insertar_en_polaca("@longitud", TIPO_ENTERO);
	generarNuevoAuxiliar( "@longitud" );
	insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_ENTERO);
	insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_ENTERO);
	//////////////////		
	itoa(longitud, slongitud, 10);
	insertar_en_polaca(slongitud, TIPO_STRING);
	insertar_en_polaca(":=", TIPO_VACIO);
}

void inicializar_variables_y_archivos_de_compilacion()
{
	crear_lista(&listaTS);
    crear_archivo_para_codigo_intermedio();
	crearCola (&cola_de_ids_declaracion);
	crearCola (&cola_de_ids_longitud);
	crear_pila (&pila_de_tipos_declaracion);
	crearCola (&cola_de_ids_asig);
	crear_lista_inter(&listaIntermedio);
	crear_pila_ent( &pilaDeCeldas );
	crear_pila_ent( &pilaDeCondicionesAplicadas );
	crear_pila_ent ( & pilaInicioDeWhile);
	crear_pila_str(  &pilaTipoDeDato );
	crear_pila_str( &pilaTiposAssembler );
	crear_pila_assem( &pilaDeOperandosAssembler );
	crear_pila_assem( &pilaAuxiliaresAssembler );
	crear_lista_etiq (& listaEtiquetas);

}

void imprimir_tabla_de_simbolos_en_archivo()
{
	volcar_lista_a_tabla_de_simbolos(&listaTS);
}

void crear_tabla_simbolos()
{
	FILE * ts= fopen("ts.txt", "wt" );
	fprintf(ts, "%s||%s||%s||%s\n", "NOMBRE", "TIPO", "VALOR", "LONGITUD");
	fclose(ts);
}



void borrar_tabla_simbolos()
{
	remove("ts.txt");
}

int crear_archivo_notacion_intermedia( t_lista_cod_inter *dirLista)
{
	char buffer[100];
	FILE * arch= fopen("intermedia.txt", "ab+" );
    char tipo[30];
	if( arch == NULL)
		return FALSE;
	while( ! lista_inter_vacia(dirLista) )
	{
		extraer_primero_de_lista_inter(dirLista, buffer, tipo);
		//printf("Buffer tiene: %s\n", buffer);
		fprintf(arch, "%s||", buffer );
	}
	fclose(arch);
	return TRUE;
}

int crear_archivo_logs( t_lista_cod_inter *dirLista)
{
	char buffer[100];
	FILE * arch= fopen("logs.txt", "ab+" );
    char tipo[30];
	if( arch == NULL)
		return FALSE;
	while( ! lista_inter_vacia(dirLista) )
	{
		extraer_primero_de_lista_inter(dirLista, buffer, tipo);
		//printf("Buffer tiene: %s\n", buffer);
		fprintf(arch, "%s||", buffer );
	}
	fclose(arch);
	return TRUE;
}

int main (int argc, char *argv[])
{	
	if(( yyin= fopen (argv[1], "rt")) == NULL )
    {
        printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
    }
    else
    {
    	inicializar_variables_y_archivos_de_compilacion();
		crear_tabla_simbolos();
        yyparse();
		imprimir_tabla_de_simbolos_en_archivo();
		crear_archivo_notacion_intermedia(&listaIntermedio);
    }
    fclose(yyin);
	
    return 0;
}

void genera_assembler()
{
	char celdaCodInterm[200];
	int tipoDeElementoIntermedio;
	char cuerpoCodigoAssembler[50000]="\n";
	FILE* archivoAssembler = fopen("Final.asm", "w");
	duplicar_lista_cod_intermedio(&listaIntermedio, &listaDuplicadaDeCodigoIntermedio);	

  	if(!archivoAssembler)
  	{
		errorEnGenerarAssembler("Error: No se pudo crear el archivo de codigo Assembler");
	}

	generar_cuerpo_de_codigo_assembler( cuerpoCodigoAssembler, &listaDuplicadaDeCodigoIntermedio );
	generar_cabecera_assembler( archivoAssembler );

	insertar_en_tabla_de_simbolos_auxiliares_assembler();
	duplicar_lista_ts(&listaTS, &listaTSDuplicada);

	generar_seccion_de_variables( archivoAssembler, &listaTSDuplicada );

	generar_inicio_de_codigo_assembler( archivoAssembler );
	imprimir_cuerpo_codigo_assembler( archivoAssembler, cuerpoCodigoAssembler );

	/// DEBERIA HABER TERMINADO DE LEER TODA LA NOTACION INTERMEDIA ACA
	generar_final_de_codigo_assembler(archivoAssembler);
	fclose(archivoAssembler);
}

/////

void generar_cabecera_assembler(FILE *arch)
{
  fprintf(arch, "include macros2.asm\ninclude number.asm\n\n.MODEL LARGE\n.386\n.STACK 200h\n\n");
}

void generar_inicio_de_codigo_assembler(FILE* arch)
{
	fprintf(arch, ".CODE\nSTART:\nMOV AX, @DATA\nMOV DS, AX\nMOV es,ax\nFINIT\n");
}

void generar_final_de_codigo_assembler(FILE *arch)
{
    fprintf(arch, "\n;INSTRUCCIONES QUE FINALIZAN EL PROGRAMA\nMOV AX, 4C00h\nINT 21h\n");
    //// FUNCIONES DE MANO DE STRINGS  /////////////////////////////////////////////////////////
    fprintf(arch,"\nstrlen proc near\n\tmov bx, 0\n\tstrl01:\n\tcmp BYTE PTR [si+bx],'$'\n\tje strend\n\tinc bx\n\tjmp strl01\n\tstrend:\n\tret\nstrlen endp\n");
	
	fprintf(arch,"\ncopiar proc near\n\tcall strlen\n\tcmp bx , @MAXTEXTSIZE\n\tjle copiarSizeOk\n\tmov bx , @MAXTEXTSIZE\n\tcopiarSizeOk:\n\tmov cx , bx\n\tcld\n\trep movsb\n\tmov al , '$'\n\tmov byte ptr[di],al\n\tret\ncopiar endp\n");

	fprintf(arch, "\nEND START;\n");

}

void generar_seccion_de_variables( FILE * archivoAssembler, t_lista *dirListaTSDuplicada )
{
	t_lexema lexemaExtraido;
	char cadAux [100];
	char tipoAux [20];
	char mensaje [200];


	fprintf(archivoAssembler, ".DATA\n");
	fprintf(archivoAssembler,"@MAXTEXTSIZE equ 31\n");

	/// DESCARGO LOS LEXEMAS HASTA LA GENERACION DE COD INTERMEDIO
	while( lista_vacia( dirListaTSDuplicada ) == FALSE )
	{
		extraer_primero_de_lista ( dirListaTSDuplicada, &lexemaExtraido );
		fprintf(archivoAssembler, "%s\t\t", lexemaExtraido.nombre);

        if( strcmp( lexemaExtraido.tipo, TIPO_ENTERO) ==0 )
        {
            fprintf(archivoAssembler, "dd\t\t%d\n", atoi(lexemaExtraido.valor) );
        }
        else
        {
        		if( strcmp( lexemaExtraido.tipo, TIPO_FLOTANTE) ==0 )
        		{
            		fprintf(archivoAssembler, "dd\t\t%f\n", atof(lexemaExtraido.valor));
       		 	}
       		 	else
       		 	{
       		 			if( strcmp( lexemaExtraido.tipo, TIPO_STRING) ==0 )
       		 			{
       		 				
       		 				if( strcmp(lexemaExtraido.valor, "" ) == 0 )
       		 				{
       		 					fprintf(archivoAssembler, "DB\t\t ?,'$', @MAXTEXTSIZE dup(?)\n");
       		 				}
       		 				else
       		 				{
       		 					fprintf(archivoAssembler, "DB\t\t%s,'$', @MAXTEXTSIZE dup(?)\n", lexemaExtraido.valor);
       		 				}

       		 			}
       		 			else
       		 			{	
       		 				sprintf(mensaje,"Error: Tipo desconocido en generacion de .DATA--> Nombre:%s, Tipo:-->%s", lexemaExtraido.nombre, lexemaExtraido.tipo);
       						errorEnGenerarAssembler(mensaje);
       		 			}    
       		 	}
        }
	}

	fprintf(archivoAssembler,"\n");
}

void generar_cuerpo_de_codigo_assembler( char *cuerpoAssembler , t_lista_cod_inter *dirListaInterm )
{
	char etiquetaFinal [20];
	while( lista_inter_vacia( dirListaInterm ) == FALSE )
	{
		procesar_celda( cuerpoAssembler, dirListaInterm);
	}
	/// SI HICIMOS UNA ETIQUETA DE SALTO A FINAL DE CODIGO, GENERAMOS LA ETIQUETA AL FINAL DEL CODIGO
	if( buscar_etiqueta_en_lista(&listaEtiquetas, numCeldaProcesada) == TRUE )
	{
		sprintf(etiquetaFinal, "\n@ET_%d:", numCeldaProcesada);
		strcat(cuerpoAssembler, etiquetaFinal);
	}

}

void imprimir_cuerpo_codigo_assembler( FILE* archivoAssembler, char *cuerpoAssembler )
{
	fprintf(archivoAssembler, cuerpoAssembler);
}
void procesar_celda( char* cuerpoAssembler, t_lista_cod_inter *dirListaInterm )
{
	char contenidoDeCelda[ 100 ];
	char mensaje [200];
	char tipoDeDatoCelda[20];
	
	/// EXTRAIGO UN ELEMENTO DE LA NOTACION INTERMEDIA
	extraer_celda_de_cod_intermedio ( dirListaInterm, contenidoDeCelda, tipoDeDatoCelda, cuerpoAssembler );
	
	if( es_operando(contenidoDeCelda) == TRUE || strcmp(contenidoDeCelda, "TRUE") == 0 || strcmp(contenidoDeCelda, "FALSE") == 0 )
	{
		apilar_operando(contenidoDeCelda, tipoDeDatoCelda);
		return;
	}
	
	if( strcmp( contenidoDeCelda, "+" ) == 0 )
	{
		suma_assembler(cuerpoAssembler, tipoDeDatoCelda);
		return;
	}
	
	if( strcmp( contenidoDeCelda, "-" ) == 0 )
	{
		resta_assembler(cuerpoAssembler, tipoDeDatoCelda);
		return ;		
	}
	
	if( strcmp( contenidoDeCelda, "*" ) == 0 )
	{
		mulplicacion_assembler(cuerpoAssembler, tipoDeDatoCelda);
		return ;		
	}

	if( strcmp( contenidoDeCelda, "/" ) == 0 )
	{
		division_assembler(cuerpoAssembler, tipoDeDatoCelda);
		return ;		
	}

	if( strcmp( contenidoDeCelda, ":=" ) == 0 )
	{
		asignacion_assembler(cuerpoAssembler);
		return ;		
	}

	if( strcmp( contenidoDeCelda, OPERADOR_GET ) == 0 )
	{
		read_assembler(cuerpoAssembler);
		return ;		
	}

	if( strcmp( contenidoDeCelda, OPERADOR_DISPLAY ) == 0 )
	{
		write_assembler( cuerpoAssembler );
		return ;		
	}

	if( strcmp( contenidoDeCelda, OPERADOR_CMP ) == 0 )
	{
		comparacion_assembler( cuerpoAssembler, dirListaInterm );
		return ;		
	}

	if( strcmp( contenidoDeCelda, ETIQUETA_WHILE ) == 0 )
	{
		procesar_etiqueta_while_assembler( cuerpoAssembler );
		return ;		
	}

	if( strcmp( contenidoDeCelda, OPERADOR_BI ) == 0 )
	{
		salto_incondicional_assembler( cuerpoAssembler, dirListaInterm);
		return ;
	}
	

	sprintf(mensaje, "\nError: No pude Reconocer el Operador %s", contenidoDeCelda);
	errorEnGenerarAssembler( mensaje );
}

void salto_incondicional_assembler( char *cuerpoAssembler, t_lista_cod_inter *dirListaInterm)
{
	
	char buffer [100];
	int celdaDeSaltoInt;
	char celdaDeSaltoString[20];
	char nombreEtq [20];
	char tipo[20];

	/// SACO LA PROXIMA CELDA QUE CONTIENE EL LUGAR DE SALTO
	extraer_celda_de_cod_intermedio ( dirListaInterm, celdaDeSaltoString, tipo, cuerpoAssembler );
	
	/// GENERO EL NOMBRE DE LA ETIQUETA Y LA GUARDO EN LISTA
	sprintf(nombreEtq, "@ET_%s", celdaDeSaltoString);
	insertar_en_lista_etq_sin_duplic (&listaEtiquetas, nombreEtq , atoi(celdaDeSaltoString));
	
	/// AÑADO EL CODIGO AL CUERPO ASSEMBLER
	sprintf(buffer, "\nJMP %s", nombreEtq);
	strcat(cuerpoAssembler, buffer);

}

void procesar_etiqueta_while_assembler( char * cuerpoAssembler )
{
	char buffer [100];
	char celdaDeSaltoString[20];
	char nombreEtq [20];

	sprintf(nombreEtq, "@ET_%d", numCeldaProcesada - 1); /// -1 porque la funcion de extraer celda incremento el valor de celda previamente
	sprintf(buffer, "\n%s :", nombreEtq );
	strcat(cuerpoAssembler, buffer);

	insertar_en_lista_etq_sin_duplic (&listaEtiquetas, nombreEtq , numCeldaProcesada - 1);
}

void guardar_tipo_de_dato_id_para_tipo_expresion_e_insertar_en_polaca( char *nombreLexema )
{
	t_lexema lexemaBuscado;
	buscar_en_lista ( &listaTS , nombreLexema , &lexemaBuscado);
	apilar_tipos_datos( lexemaBuscado.tipo );
	insertar_en_polaca(nombreLexema, lexemaBuscado.tipo);
}

void comparacion_assembler ( char *cuerpoAssembler, t_lista_cod_inter *dirListaInterm )
{
	char operandoLadoIzq [100];
	char tipoLadoIzquierdo [20];
	char operandoLadoDer [100];
	char tipoLadoDerecho [20];
	char comparador [20];
	char comparadorAssembler[20];
	char buffer [100];
	char tipo[20];
	int celdaDeSaltoInt;
	char celdaDeSaltoString[20];
	char nombreEtq [20];

	/// DESAPILO LADO DERECHO
	desapilar_operando( operandoLadoDer, tipoLadoDerecho );

	/// DESAPILO LADO IZQUIERDO
	desapilar_operando( operandoLadoIzq, tipoLadoIzquierdo );	

	/// ------------- CARGO LADO IZQUIERDO EN COPRO ---------------------------
	if( strcmp(tipoLadoIzquierdo, TIPO_ENTERO) ==0 )
	{
		sprintf(buffer, "\nFILD %s", operandoLadoIzq);
	}
	else
	{
		if( strcmp(tipoLadoIzquierdo, TIPO_FLOTANTE) ==0 )
		{
			sprintf(buffer, "\nFLD %s", operandoLadoIzq);
		}
		else
		{	
			errorEnGenerarAssembler("Error: Error de tipos LI en operacion de suma.");
						
		}
	}
	strcat( cuerpoAssembler, buffer );

	///-------------CARGO LADO DERECHO EN COPRO ----------------------------------

	if( strcmp(tipoLadoDerecho, TIPO_ENTERO) ==0 )
	{
		sprintf(buffer, "\nFILD %s", operandoLadoDer);
	}
	else
	{
		if( strcmp(tipoLadoDerecho, TIPO_FLOTANTE) ==0 )
		{
			sprintf(buffer, "\nFLD %s", operandoLadoDer);
		}
		else
		{
			errorEnGenerarAssembler("Error: Error de tipos LD en operacion de suma");
		}
	}
	strcat( cuerpoAssembler, buffer );


	////------------------ REALIZO LA COMPARACION -------------------------////
	strcat(cuerpoAssembler, "\nfxch \n fcom\n fstsw ax\n sahf\n");
	
	////------------------ GENERO EL SALTO POR CONDICION FALSA ------////
	extraer_celda_de_cod_intermedio ( dirListaInterm, comparador, tipo, cuerpoAssembler );

	transformar_etiqueta_comparador_a_assembler(  comparador, comparadorAssembler );

	extraer_celda_de_cod_intermedio ( dirListaInterm, celdaDeSaltoString, tipo, cuerpoAssembler );	

	sprintf(nombreEtq, "@ET_%s", celdaDeSaltoString);

	/// -------------------- GUARDO LA ETIQUETA EN UNA LISTA DE ETIQUETAS QUE CONTIENEN LAS ETQ Q SE DEBERÁ CREAR MAS ADELANTE -----///

	insertar_en_lista_etq_sin_duplic (&listaEtiquetas, nombreEtq , atoi(celdaDeSaltoString));

	///------------- IMPRIMO EN CUERPO LA INSTRUCCION DE SALTO + LA ETIQUETA -------------///
	sprintf(buffer, "%s\t%s", comparadorAssembler, nombreEtq);
	strcat(cuerpoAssembler, buffer);

}

void extraer_celda_de_cod_intermedio (t_lista_cod_inter *dirListaInterm, char* lexema, char *tipo , char *cuerpoAssembler)
{
	char buffer [40];
	//// ACA DEBERIA PREGUNTAR CON UN IF SI LA CELDA ACTUAL ES UNA CELDA QUE ES NOMBRADA EN LA LISTA DE ETIQUETAS QUE VAMOS A CREAR
	if( buscar_etiqueta_en_lista( &listaEtiquetas, numCeldaProcesada) == TRUE )
	{

		sprintf(buffer,"\n@ET_%d: ", numCeldaProcesada);
		strcat(cuerpoAssembler, buffer);
	}
	
	extraer_primero_de_lista_inter ( dirListaInterm, lexema, tipo );
	//// DEJAR SIEMPRE AL FINAL EL AUMENTO DEL NUMERO DE CELDAS PROCESADAS
	numCeldaProcesada++;	
}




int es_operando( char *elemento )
{
	t_lexema lexema;
	if( buscar_en_lista(&listaTS, elemento, &lexema ) == TRUE )
	{
		return TRUE;
	}
	return FALSE;
}

int ver_ultima_condicion_aplicada()
{
	int condicion;
	ver_tope_pila_ent( &pilaDeCondicionesAplicadas, &condicion );
	return condicion;
}

void generarAuxiliarAssembler( char *auxiliarGen, char* tipo)
{
	sprintf(auxiliarGen, "@auxAssembler%d", numAuxAssembler);
	numAuxAssembler++;
	apilar_celda_assem( &pilaAuxiliaresAssembler, auxiliarGen, tipo);
	
}


void suma_assembler( char *cuerpoAssembler, char *tipoDatoResult )
{
	operacion_matematica(cuerpoAssembler, tipoDatoResult, "FADD");
}


void resta_assembler( char *cuerpoAssembler, char *tipoDatoResult )
{
	operacion_matematica(cuerpoAssembler, tipoDatoResult, "FSUB");
}

void mulplicacion_assembler( char *cuerpoAssembler, char *tipoDatoResult )
{
	operacion_matematica(cuerpoAssembler, tipoDatoResult, "FMUL");
}

void division_assembler( char *cuerpoAssembler, char *tipoDatoResult )
{
	operacion_matematica(cuerpoAssembler, tipoDatoResult, "FDIV");
}

void operacion_matematica ( char *cuerpoAssembler, char *tipoDatoResult, char *instruccionMatematica  )
{
	char nuevoAuxiliar[100];
	char operandoLadoIzq [100];
	char tipoLadoIzquierdo [20];
	char operandoLadoDer [100];
	char tipoLadoDerecho [20];

	char buffer [100];

	///--GENERADO DEL AUXILIAR
	generarAuxiliarAssembler( nuevoAuxiliar, tipoDatoResult );

	/// DESAPILO LADO DERECHO
	desapilar_operando( operandoLadoDer, tipoLadoDerecho );

	/// DESAPILO LADO IZQUIERDO
	desapilar_operando( operandoLadoIzq, tipoLadoIzquierdo );

	strcat(cuerpoAssembler, "\n;Operacion Matematica" );
	
	/// ------------- CARGO LADO IZQUIERDO EN COPRO ---------------------------
	if( strcmp(tipoLadoIzquierdo, TIPO_ENTERO) ==0 )
	{
		sprintf(buffer, "\nFILD %s", operandoLadoIzq);
	}
	else
	{
		if( strcmp(tipoLadoIzquierdo, TIPO_FLOTANTE) ==0 )
		{
			sprintf(buffer, "\nFLD %s", operandoLadoIzq);
		}
		else
		{
			errorEnGenerarAssembler("Error: Error de tipos LI en operacion de suma.");
			//errorEnGenerarAssembler(tipoLadoIzquierdo);
		}
	}
	strcat( cuerpoAssembler, buffer );

	///-------------CARGO LADO DERECHO EN COPRO ----------------------------------

	if( strcmp(tipoLadoDerecho, TIPO_ENTERO) ==0 )
	{
		sprintf(buffer, "\nFILD %s", operandoLadoDer);
	}
	else
	{
		if( strcmp(tipoLadoDerecho, TIPO_FLOTANTE) ==0 )
		{
			sprintf(buffer, "\nFLD %s", operandoLadoDer);
		}
		else
		{
			errorEnGenerarAssembler("Error: Error de tipos LD en operacion de suma");
		}
	}
	strcat( cuerpoAssembler, buffer );

	////----------------------------------------------------


	/// ------------ OPERACION MATEMATICA EN COPRO -------------------------------------

	sprintf( buffer, "\n%s", instruccionMatematica);
	strcat( cuerpoAssembler, buffer );	

	/// ----------- GUARDO EL RESULTADO EN EL NUEVO AUXILIAR ------------------------ 
	
	if( strcmp(tipoDatoResult, TIPO_ENTERO) ==0 )
	{
		sprintf(buffer, "\nFISTP %s\n", nuevoAuxiliar);
	}
	else
	{
		if( strcmp(tipoDatoResult, TIPO_FLOTANTE) ==0 )
		{
			sprintf(buffer, "\nFSTP %s\n", nuevoAuxiliar);
		}
		else
		{
			//errorEnGenerarAssembler("Error: Error de tipos en operacion de suma");
			errorEnGenerarAssembler(tipoDatoResult);
		}
	}
	strcat( cuerpoAssembler, buffer );

	/// -------- APILO EN PILA DE OPERANDOS EL NUEVO AUXILIAR -----------------------
	apilar_operando( nuevoAuxiliar, tipoDatoResult );

	///------ FIN DE OPERACION MATEMATICA ---------------
}

void get_en_polaca( char * lexema)
{
	t_lexema lexemaRec;
	char buffer[200];
	if( buscar_en_lista (&listaTS, lexema, &lexemaRec) == TRUE)
	{
		if( strcmp( lexemaRec.tipo, TIPO_VACIO ) == 0 ) /// PREGUNTO SI EL ID FUE DECLARADA PREVIAMENTE 
		{
			sprintf( buffer, "\nError Semantico: El ID %s no fue declarado antes de usarse en la sentencia GET.", lexemaRec.nombre );
			errorSemantico(buffer);
			return;
		}
		
		insertar_en_polaca(lexema, lexemaRec.tipo);
		insertar_en_polaca(OPERADOR_GET, TIPO_VACIO);
		return;
	}
	errorSemantico("Error: Lexema No encontrado en TS");
}

void display_en_polaca( char * lexema, char * tipoLex )
{
	t_lexema lexemaRec;
	char buffer[200];
	if( buscar_en_lista (&listaTS, lexema, &lexemaRec) == TRUE)
	{
		if( strcmp( lexemaRec.tipo, TIPO_VACIO) ==0 )
		{
			sprintf(buffer, "\nLa variable %s, no fue declarada previamente", lexemaRec.nombre);
			errorSemantico();
			return;
		}

		if( strcmp( lexemaRec.tipo, TIPO_ENTERO) ==0 )
		{
			insertar_en_polaca(lexema, TIPO_ENTERO);
			insertar_en_polaca(OPERADOR_DISPLAY, TIPO_VACIO);
			return;
		}

		if( strcmp( lexemaRec.tipo, TIPO_FLOTANTE) ==0 )
		{
			insertar_en_polaca(lexema, TIPO_FLOTANTE);
			insertar_en_polaca(OPERADOR_DISPLAY, TIPO_VACIO);
			return;
		}

		if( strcmp( lexemaRec.tipo, TIPO_STRING) ==0 )
		{
			insertar_en_polaca(lexema, TIPO_STRING);
			insertar_en_polaca(OPERADOR_DISPLAY, TIPO_VACIO);
			return;
		}
	}
		errorSemantico("Error: No se pudo determinar el tipo de lexema en DISPLAY");
}


void asignacion_assembler( char *cuerpoAssembler)
{
	char operandoLadoIzq [100];
	char tipoLadoIzquierdo [20];
	char operandoLadoDer [100];
	char tipoLadoDerecho [20];

	char buffer [100];

	/// ----- DADO QUE EN LA ASIGNACION LOS OPERANDOS ESTAN INVERTIDOS PRIMERO SE SACA EL LADO IZQUIERDO Y LUEGO EL DERECHO 

	/// DESAPILO LADO IZQUIERDO
	desapilar_operando( operandoLadoIzq, tipoLadoIzquierdo );
	
	/// DESPILO LADO DERECHO
	desapilar_operando( operandoLadoDer, tipoLadoDerecho );

	//// GENERO COMENTARIO
	strcat( cuerpoAssembler, "\n; REALIZO ASIGNACION:" );

	/// CARGO EN COPRO LADO DERECHO Y ASIGNO
	/// ENTEROS
	if( strcmp( tipoLadoIzquierdo, TIPO_ENTERO ) == 0 )
	{
		sprintf(buffer, "\nFILD %s\n FISTP %s", operandoLadoDer, operandoLadoIzq);
		strcat( cuerpoAssembler, buffer );

		strcat( cuerpoAssembler, "\n" );

		return;
	}

	/// FLOTANTES
	if( strcmp( tipoLadoIzquierdo, TIPO_FLOTANTE ) == 0 )
	{
		sprintf(buffer, "\nFLD %s\n FSTP %s", operandoLadoDer, operandoLadoIzq);
		strcat( cuerpoAssembler, buffer );
		
		strcat( cuerpoAssembler, "\n" );

		return;
	}



	if( strcmp( tipoLadoIzquierdo, TIPO_STRING ) == 0 )
	{
		t_lexema lexemaString;
		buscar_en_lista(&listaTS, operandoLadoDer, &lexemaString);

		/// SI= SOURCE INDEX = inicio de cadena de origen , DI = DESTINATION INDEX = inicio de cadena de destino
		sprintf(buffer,"\n mov si, OFFSET %s", operandoLadoDer); /// INDICO A DI LA VARIABLE DE ORIGEN
		strcat( cuerpoAssembler, buffer );

		sprintf(buffer,"\n mov di, OFFSET %s", operandoLadoIzq );  /// INDICO A DI LA VARIABLE DE DESTINO
		strcat( cuerpoAssembler, buffer );

		sprintf(buffer, "\n call copiar\n" ); 
		strcat( cuerpoAssembler, buffer );		
	}
	
}


void read_assembler( char *cuerpoAssembler )
{
	char operando [100];
	char tipoOperando [20];
	char buffer [100];


	/// DESAPILO OPERANDO ANTERIOR
	desapilar_operando( operando, tipoOperando );


	/// ENTERO 
	if( strcmp( tipoOperando, TIPO_ENTERO ) == 0 )
	{		
		strcat( cuerpoAssembler, "\n;Leer un valor entero:" );
		
		sprintf(buffer, "\n getInteger %s", operando);
		strcat( cuerpoAssembler, buffer );

		sprintf(buffer, "\n newLine\n");
		strcat( cuerpoAssembler, buffer );

		return;
	}

	/// FLOTANTES
	if( strcmp( tipoOperando, TIPO_FLOTANTE ) == 0 )
	{
		strcat( cuerpoAssembler, "\n;Leer un valor flotante:" );

		sprintf(buffer, "\n getFloat %s", operando);
		strcat( cuerpoAssembler, buffer );
		
		sprintf(buffer, "\n newLine\n");
		strcat( cuerpoAssembler, buffer );

		return;
	}


	////  STRING
	if( strcmp( tipoOperando, TIPO_STRING ) == 0 )
	{
		strcat( cuerpoAssembler, "\n;Leer un valor String:" );

		sprintf(buffer, "\n getString %s", operando);
		strcat( cuerpoAssembler, buffer );

		sprintf(buffer, "\n newLine\n");
		strcat( cuerpoAssembler, buffer );

		return;
	}
}

void comparar_tipos_en_comparacion()
{
	char ladoDerecho [20], ladoIzquierdo [20], tipoResultante[20];
	char mensaje[200];
	desapilar_tipo_de_dato(ladoDerecho);
	desapilar_tipo_de_dato(ladoIzquierdo);

	if( strcmp(ladoDerecho, TIPO_VACIO) == 0 || strcmp(ladoIzquierdo, TIPO_VACIO)  == 0)
	{
		sprintf(mensaje,"Error: Alguna variable en la comparacion no fue declarada previamente.", ladoIzquierdo, ladoDerecho);
		errorSemantico(mensaje);	
	}


	if( strcmp(ladoDerecho, ladoIzquierdo) != 0 )
	{
		sprintf(mensaje,"Error de Tipos en Comparacion: El lado Izquierdo es de tipos %s , y el lado derecho es de tipo %s", ladoIzquierdo, ladoDerecho);
		errorSemantico(mensaje);
	}
	if( strcmp(ladoDerecho, TIPO_STRING) == 0 || strcmp(ladoIzquierdo, TIPO_STRING) == 0  )
	{
		sprintf(mensaje,"Error: No se pueden utilizar operandos de tipo string en comparaciones", ladoIzquierdo, ladoDerecho);
		errorSemantico(mensaje);
	}
}

void write_assembler( char *cuerpoAssembler )
{
	char operando [100];
	char tipoOperando [20];
	char buffer [200];
	/// DESAPILO OPERANDO ANTERIOR
	desapilar_operando( operando, tipoOperando );

	/// ENTERO 
	if( strcmp( tipoOperando, TIPO_ENTERO ) == 0 )
	{
		strcat( cuerpoAssembler, "\n;Mostrar valor entero:" );

		sprintf(buffer, "\nDisplayInteger %s", operando);
		strcat( cuerpoAssembler, buffer );

		sprintf(buffer, "\n newLine\n");
		strcat( cuerpoAssembler, buffer );

		return;
	}

	/// FLOTANTES
	if( strcmp( tipoOperando, TIPO_FLOTANTE ) == 0 )
	{
		strcat( cuerpoAssembler, "\n;Mostrar valor flotante:" );
		
		sprintf(buffer, "\nDisplayFloat %s ,2", operando);
		strcat( cuerpoAssembler, buffer );

		sprintf(buffer, "\n newLine \n");
		strcat( cuerpoAssembler, buffer );

		return;
	}

	////  STRING
	if( strcmp( tipoOperando, TIPO_STRING ) == 0 )
	{
		strcat( cuerpoAssembler, "\n;Mostrar valor string:" );

		sprintf(buffer, "\n displayString %s", operando);
		strcat( cuerpoAssembler, buffer );

		sprintf(buffer, "\n newLine \n");
		strcat( cuerpoAssembler, buffer );
		return;
	}

}


void apilar_operando( char *operando , char *tipo)
{
	apilar_celda_assem(&pilaDeOperandosAssembler, operando, tipo);
}

void desapilar_operando( char *operando, char *tipo )
{
	desapilar_celda_assem(&pilaDeOperandosAssembler, operando, tipo);	
}

void transformar_etiqueta_comparador_a_assembler( char *comparador, char *comparadorAssembler )
{
	if( strcmp(comparador, OPERADOR_BLT) == 0 )
	{
		strcpy(comparadorAssembler, "JB");
		return;
	}

	if( strcmp(comparador, OPERADOR_BLE) == 0 )
	{
		strcpy(comparadorAssembler, "JNA");
		return;
	}

	if( strcmp(comparador, OPERADOR_BGT) == 0 )
	{
		strcpy(comparadorAssembler, "JA");
		return;
	}

	if( strcmp(comparador, OPERADOR_BGE) == 0 )
	{
		strcpy(comparadorAssembler, "JAE");
		return;
	}

	if( strcmp(comparador, OPERADOR_BEQ) == 0 )
	{
		strcpy(comparadorAssembler, "JE");
		return;
	}

	if( strcmp(comparador, OPERADOR_BNE) == 0 )
	{
		strcpy(comparadorAssembler, "JNE");
		return;
	}
}
//// 

void insertar_en_tabla_de_simbolos_auxiliares_assembler()
{
	char auxApilado [100];
	char tipoAuxApilado [20];
	t_lexema lexema;
	strcpy(lexema.valor, "");
	strcpy(lexema.longitud, "");
	while( pila_vacia_assem(&pilaAuxiliaresAssembler) == FALSE )
	{
		desapilar_celda_assem(&pilaAuxiliaresAssembler, auxApilado, tipoAuxApilado);
		strcpy(lexema.nombre, auxApilado);
		strcpy(lexema.tipo, tipoAuxApilado);
		insertar_en_lista ( &listaTS, &lexema);
	}
}



///// POSIBLE BORRADO ///////////////////


int es_constante_usuario( char * elemento)
{
	if( buscar_en_lista(&listaTS, elemento, NULL) == TRUE && *elemento == '_' )
	{
		return TRUE;
	}
	return FALSE;
}

int es_variable_usuario( char *elemento )
{
	if( buscar_en_lista(&listaTS, elemento, NULL) == TRUE && *elemento != '_' && *elemento != '@')
	{
		return TRUE;
	}
	return FALSE;
}

int es_variable_sistema( char*  elemento )
{
	if( *elemento == '@' )
	{
		return TRUE;
	}
	return FALSE;	
}

int es_etiqueta( char *elemento)
{
	if( *elemento == '#' )
	{
		return TRUE;
	}
	return FALSE;	
}

int es_operador( char *elemento )
{
	if( *elemento == '$' || *elemento == '+' || *elemento == '-' || *elemento == '*' || *elemento == '/' || strcmp(elemento, ":=" )  )
	{
		return TRUE;
	}
	return FALSE;
}

int es_constante_de_sistema(  char *elemento )
{
	float valor;
	char *endptr;
	errno=0;
	valor=strtof(elemento, &endptr);
    if( errno != 0)
    {
    	return FALSE;
   	}
   	return TRUE;
}

void calcular_tipo_dato_resultante ( char *izq, char* der , char operador , char* resultado )
{

	if( strcmp(izq, TIPO_VACIO) == 0 || strcmp(der, TIPO_VACIO)==0 )
	{
		errorSemantico("Error: En una expresion matematica existen variables que no fueron declaradas previamente");
		return;
	}

	if( strcmp(izq, TIPO_STRING) == 0 || strcmp(der, TIPO_STRING)==0 )
	{
		errorSemantico("Error: No se pueden realizar operaciones de + - * / con operandos String");
		return;
	}

	if( operador == '+' || operador == '-' || operador == '*'  )
	{

		if( strcmp(izq, TIPO_FLOTANTE) == 0 || strcmp(der, TIPO_FLOTANTE) == 0  )
			strcpy(resultado, TIPO_FLOTANTE);
		else
			strcpy(resultado, TIPO_ENTERO);
	}

	if( operador == '/' )
	{
		strcpy(resultado, TIPO_FLOTANTE);		
	}	

}

void desapilar_tipo_de_dato( char* tipo )
{
	desapilar(&pila_de_tipos_declaracion, tipo);
}

void resolver_y_apilar_tipo_de_dato_por_operacion( char operador, char *tipoDatoResultanteRetornado )
{
	char ladoDerecho [20], ladoIzquierdo [20], tipoResultante[20];
	desapilar_tipo_de_dato(ladoDerecho);
	desapilar_tipo_de_dato(ladoIzquierdo);
	calcular_tipo_dato_resultante ( ladoIzquierdo, ladoDerecho , operador , tipoResultante );
	apilar_tipos_datos(tipoResultante);
	strcpy(tipoDatoResultanteRetornado, tipoResultante);
}

/// ERROR EN LA GENERACION DE ASSEMBLER //////////////////////////////
void errorEnGenerarAssembler( char* mensaje)
{
	printf("\nError en la generacion de codigo Assembler:\n%s", mensaje);
	exit(3);	
}

/// TRATAMIENTO DE ERRORES ////////////////////////////////////////////
int yyerror(void)
{
	printf("\nError Sintactico");
	//borrar_tabla_simbolos();
	//destruir_archivo_codigo_intermedio();
	exit(1);
}
/// ERROR SEMANTICO //////////////////////////////
int errorSemantico(char* mensaje)
{
	printf("\nERROR SEMANTICO");
	printf("\n%s", mensaje);
	//borrar_tabla_simbolos();
	//destruir_archivo_codigo_intermedio();
	exit(2);
}

void guardar_comparador( char* comparador )
{
	
	if( flagOpNot == FALSE)
	{
		strcpy(comparador_guardado, comparador);
		return;
	}

	flagOpNot = FALSE;

	if( strcmp(comparador, OPERADOR_BLT) == 0 )
	{
		strcpy(comparador_guardado, OPERADOR_BGE);
		return;
	}

	if( strcmp(comparador, OPERADOR_BLE) == 0 )
	{
		strcpy(comparador_guardado, OPERADOR_BGT);
		return;
	}

	if( strcmp(comparador, OPERADOR_BGT) == 0 )
	{
		strcpy(comparador_guardado, OPERADOR_BLE);
		return;
	}

	if( strcmp(comparador, OPERADOR_BGE) == 0 )
	{
		strcpy(comparador_guardado, OPERADOR_BLT);
		return;
	}

	if( strcmp(comparador, OPERADOR_BEQ) == 0 )
	{
		strcpy(comparador_guardado, OPERADOR_BNE);
		return;
	}

	if( strcmp(comparador, OPERADOR_BNE) == 0 )
	{
		strcpy(comparador_guardado, OPERADOR_BEQ);
		return;
	}

}

void insertar_auxiliar_en_ts( char* nombreAuxiliar, char* tipoDato)
{
	t_lexema lexema;
	strcpy( lexema.nombre, ultimoAuxiliarGenerado );
	strcpy( lexema.tipo, tipoDato );
	strcpy( lexema.valor, "" );
	strcpy( lexema.longitud, "" );
	insertar_en_lista ( &listaTS, &lexema);
}

void generarNuevoAuxiliar( char* parteInicial )
{
	sprintf( ultimoAuxiliarGenerado, "%s%d", parteInicial, cantAuxiliaresGenerados );
	cantAuxiliaresGenerados++;
}

//// FUNCIONALIDADES DE INICIALIZACION DE COMPILACION
/*
void inicializar_variables_y_archivos_de_compilacion()
{
	crear_lista(&listaTS);
    crear_archivo_para_codigo_intermedio();
	crear_pila_str(&pila_de_ids_dec_var);
	crear_pila_str(&pila_de_ids_asig);
	crear_lista_inter(&listaIntermedio);
	crear_pila_ent( &pilaDeCeldas ); 
	crear_pila_ent( &pilaDeCondicionesAplicadas );
	crear_pila_ent ( & pilaInicioDeWhile);
	crear_pila_str(  &pilaTipoDeDato );
	crear_pila_str( &pilaTiposAssembler );
	crear_pila_assem( &pilaDeOperandosAssembler );
	crear_pila_assem( &pilaAuxiliaresAssembler );
	crear_lista_etiq (& listaEtiquetas);
}*/


void imprimir_archivo_notacion_intermedia ()
{
	crear_archivo_notacion_intermedia(&listaIntermedio);
}

//// CONSTANTE ////////////////////////////////////
void asignar_tipo_a_lexema_en_ts ( char *lexema , char *tipo )
{
	int resultado;
	resultado=asignar_tipo_a_lexema ( &listaTS, lexema, tipo );
	if( resultado == LEXEMA_YA_DECLARADO || resultado == LEXEMA_TIPIFICADO  )
		return;
	errorSemantico("Error: Lexema No encontrado en TS");
}
