%{
#include <stdio.h>
#include <stdlib.h>
int yystopparser=0;
FILE* yyin;
int yyerror();
int yylex();
void crear_tabla_simbolos();
void borrar_tabla_simbolos();
%}

/// PALABRAS RESERVADAS
%token WHILE 				
%token ENDWHILE
%token IF
%token THEN				
%token ELSE 				
%token ENDIF 					
%token GET
%token DISPLAY
%token DIM
%token AS
%token T_INT
%token T_FLOAT
%token T_STRING
%token EQUMAX
%token EQUMIN
%token LONG

/// VARIABLES Y CTES
%token ID
%token CTE_STRING
%token CTE_ENT
%token CTE_REAL

/// OPERADORES
%token OP_SUM
%token OP_RES
%token OP_MULT
%token OP_DIV
%token OP_ASIG
%token OP_MAY
%token OP_MAY_IG
%token OP_MEN
%token OP_MEN_IG
%token OP_IGUAL
%token OP_DIST
%token OP_AND
%token OP_OR 
%token OP_NOT


/// TOKENS CARACTERES ESP
%token PA
%token PC
%token PYC
%token COMA
%token DOS_PUNT
%token COR_A
%token COR_C

/// PRIORIDADES
%right OP_IGUAL
%left OP_AND OP_OR
%left OP_RES OP_SUM
%left OP_MULT OP_DIV
%nonassoc OP_NOT
%right MENOS_UNARIO

/// START
%start inicio

%%
inicio:			programa										{ printf("\nCOMPILACION EXITOSA"); }


programa:		sentencia 										{ printf("\n<programa> -> <sentencia>"); }
;

programa:		programa sentencia 								{ printf("\n<programa> -> <programa> <sentencia>"); }
;

sentencia:		dec_var						{ printf("\n<sentencia> -> <declaracion de variables>"); }
				| impresion  									{ printf("\n<sentencia> -> <impresion>"); }
				| lectura  										{ printf("\n<sentencia> -> <lectura>"); }
				| condicional 									{ printf("\n<sentencia> -> <condicional>"); }
				| iteracion 									{ printf("\n<sentencia> -> <iteracion>"); }
				| asignacion  									{ printf("\n<sentencia> -> <asignacion>"); }
;



dec_var:	DIM COR_A lista_simetrica COR_C				  	{ printf("\n<dec_var> -> DIM COR_A <lista_simetrica> COR_C"); }
;

lista_simetrica: ID COMA lista_simetrica COMA tipo_dato		{ printf("\n<lista_simetrica> -> ID COMA <lista_simetrica> COMA <tipo_dato> "); }
;
lista_simetrica: ID COR_C AS COR_A tipo_dato			{ printf("\n<lista_simetrica> -> ID COR_C AS COR_A <tipo_dato> "); }
;

tipo_dato: T_INT 														{ printf("\n<tipo_dato> -> T_INT"); }
		|	T_FLOAT														{ printf("\n<tipo_dato> -> T_FLOAT"); }
		|	T_STRING													{ printf("\n<tipo_dato> -> T_STRING"); }
;


asignacion:		lista_de_asignaciones OP_ASIG expresion 					{ printf("\n<asignacion> -> <lista_de_asignaciones> OP_ASIG <expresion>"); }
;

lista_de_asignaciones:		ID 												{ printf("\n<lista_de_asignaciones> -> ID"); }
						| lista_de_asignaciones OP_ASIG ID 					{ printf("\n<lista_de_asignaciones> -> <lista_de_asignaciones> OP_ASIG ID"); }
;


impresion:		DISPLAY ID 													{ printf("\n<impresion> -> DISPLAY ID"); }
				| DISPLAY constante 										{ printf("\n<impresion> -> DISPLAY <constante>"); }
;

lectura:		GET ID 													{ printf("\n<lectura> -> GET ID"); }
;

condicional:		IF PA condicion PC THEN programa ELSE  programa ENDIF 		{ printf("\n<condicional> -> IF( <condicion> )THEN <programa> ELSE <programa> ENDIF "); }
;

condicional:		IF PA equ PC THEN programa ENDIF 						{ printf("\n<condicional> -> IF( <equ> ) THEN <programa> ENDIF"); }
;

condicional:		IF PA equ PC THEN programa ELSE  programa ENDIF 		{ printf("\n<condicional> -> IF( <equ> )THEN <programa> ELSE <programa> ENDIF "); }
;

equ: EQUMAX PA expresion PYC COR_A lista_factores COR_C PC				{ printf("\n<equ> -> EQUMAX PA expresion PYC COR_A lista_factores COR_C PC"); }
;
equ: EQUMIN PA expresion PYC COR_A lista_factores COR_C PC				{ printf("\n<equ> -> EQUMIN PA expresion PYC COR_A lista_factores COR_C PC"); }
;

lista_factores: equfactor									{ printf("\n<lista_factores> -> <equfactor> "); }
				| lista_factores COMA equfactor				{ printf("\n<lista_factores> -> <lista_factores> COMA <equfactor> "); }
;

equfactor:		constante_num 									{ printf("\n<equfactor> -> <constante_num> "); }
				| ID 											{ printf("\n<equfactor> -> ID "); }
;


condicional:		IF PA condicion PC THEN programa ENDIF 						{ printf("\n<condicional> -> IF( <condicion>) THEN <programa> ENDIF"); }
;

iteracion:		WHILE PA condicion PC programa ENDWHILE 		 			{ printf("\n<iteracion> -> WHILE ( <condicion> ) <programa> ENDWHILE}"); }
;

condicion: 		OP_NOT  condicion_simple 									{ printf("\n<condicion> -> NOT <condicion_simple>"); }
				| condicion_multiple 										{ printf("\n<condicion> -> <condicion_multiple>"); }
				| condicion_simple											{ printf("\n<condicion> -> <condicion_simple>"); }
;

condicion_multiple:	comparacion OP_AND comparacion							{ printf("\n<condicion_multiple> -> <comparacion> AND <comparacion>"); }
						|  comparacion OP_OR comparacion 					{ printf("\n<comparacion_multiple> -> <comparacion> OR <comparacion>"); }
;

condicion_simple:	comparacion 											{ printf("\n<condicion_simple> -> <comparacion>");}					
;

comparacion:	expresion comparador expresion 								{ printf("\n<comparacion> -> <expresion> <comparador> <expresion>"); }
;

comparador:		OP_MEN 											{ printf("\n<comparador> -> <"); } 								
				|OP_MAY 										{ printf("\n<comparador> -> >"); }
				|OP_MEN_IG 										{ printf("\n<comparador> -> <="); }
				|OP_MAY_IG 										{ printf("\n<comparador> -> >="); }
				|OP_IGUAL 										{ printf("\n<comparador> -> =="); }
				|OP_DIST										{ printf("\n<comparador> -> !="); }
;


expresion:		expresion OP_SUM termino  						{ printf("\n<expresion> -> <expresion> + <termino>"); }
				| expresion OP_RES termino 						{ printf("\n<expresion> -> <expresion> - <termino>"); }
				| termino 										{ printf("\n<expresion> -> <termino>"); }
				| LONG PA COR_A lista_id COR_C PC				{ printf("\n<expresion> -> LONG PA COR_A <lista_id> COR_C PC"); }
;

expresion: 		OP_RES expresion  %prec MENOS_UNARIO 			{ printf("\n<expresion> -> OP_RES <expresion>"); }
; 					

lista_id: 	ID												{ printf("\n<lista_id> -> ID"); }
			|lista_id COMA ID 								{ printf("\n<lista_id> -> lista_id COMA ID"); }


termino:		termino OP_MULT factor 							{ printf("\n<termino> -> <termino> * <factor>"); }
				| termino OP_DIV factor 						{ printf("\n<termino> -> <termino> / <factor>"); }
				| factor 										{ printf("\n<termino> -> <factor>"); }
;

factor:			PA expresion PC  								{ printf("\n<factor> -> ( <expresion> )"); }
				| constante 									{ printf("\n<factor> -> constante "); }
				| ID 											{ printf("\n<factor> -> ID "); }
				
;



constante:		constante_num   		{ printf("\n<constante> -> <constante_num>"); }
				| CTE_STRING  		{ printf("\n<constante> -> CTE_STRING"); }
;

constante_num:	CTE_ENT   			{ printf("\n<constante_num> -> CTE_ENT"); }
				| CTE_REAL			{ printf("\n<constante_num> -> CTE_REAL"); }
;



%%

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

int main (int argc, char *argv[])
{
	if(( yyin= fopen (argv[1], "rt")) == NULL )
    {
        printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
    }
    else
    {
		crear_tabla_simbolos();
        yyparse();
    }
    fclose(yyin);
    return 0;
}

int yyerror(void)
{
	printf("\nError Sintactico");
	borrar_tabla_simbolos();
	exit(1);
}


