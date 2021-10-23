%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"
#include "lista.h"
#include "coladinamica.h"


int yystopparser=0;
FILE* yyin;

///    ts      ///
void imprimir_tabla_de_simbolos_en_archivo();
void crear_tabla_simbolos();
void borrar_tabla_simbolos();

/// FUNCIONES PARA CODIGO INTERMEDIO ///////
void crear_archivo_para_codigo_intermedio();
void insertar_en_polaca( char* cadena);
void avanzar();
void apilar_celda_actual();
void desapilar_posicion( int *posicion );
void escribir_en_celda(int pos, int valor);


/// LISTA DE TABLA DE SIMBOLOS ////////////

t_lista listaTS;

///DE TODO UN POCO  ///////
int posicion_celda_actual=0;
void encolar_id_para_tipificar (char *id);
void tipificar_ids_en_tabla_de_simbolos();
void apilar_tipos_datos (char *dato);



/// PILAS PARA DECLARACION DE VARIABLES //////
t_cola  cola_de_ids_declaracion; 
t_pila  pila_de_tipos_declaracion; 


/// FUNCIONES PARA ASIGNACION ////////
void realizar_asignacion();

/// VARIABLES PARA ASIGNACION ///////
	t_cola  cola_de_ids_asig;
	char tipo_dato_asig [30];

/// ERROR SEMANTICO ///////////////
int errorSemantico();


int yyerror();

int yylex();	
%}

%union {
	char str_val[100];
	
}

/// VARIABLES
%token <str_val>ID

/// CONSTANTES 
%token <str_val>CTE_STRING
%token <str_val>CTE_ENT
%token <str_val>CTE_REAL
%token <str_val>T_FLOAT
%token <str_val>T_STRING
%token <str_val>T_INT

//*******************************************
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

%token EQUMAX
%token EQUMIN
%token LONG


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



dec_var:	DIM COR_A lista_simetrica COR_C				  	{ printf("\n<dec_var> -> DIM COR_A <lista_simetrica> COR_C"); 
																tipificar_ids_en_tabla_de_simbolos();
}
;

lista_simetrica: ID COMA lista_simetrica COMA tipo_dato		{ printf("\n<lista_simetrica> -> ID COMA <lista_simetrica> COMA <tipo_dato> ");
																//apilar_id_para_tipificar($1);		
																encolar_id_para_tipificar($1);
																}
;
lista_simetrica: ID COR_C AS COR_A tipo_dato			{ printf("\n<lista_simetrica> -> ID COR_C AS COR_A <tipo_dato> "); 
																//apilar_id_para_tipificar($1);
																encolar_id_para_tipificar($1);
																}
;

tipo_dato: T_INT 														{ printf("\n<tipo_dato> -> T_INT"); apilar_tipos_datos( "int");}
		|	T_FLOAT														{ printf("\n<tipo_dato> -> T_FLOAT"); apilar_tipos_datos( "float");}
		|	T_STRING													{ printf("\n<tipo_dato> -> T_STRING"); apilar_tipos_datos( "string");}
;


asignacion:		lista_de_asignaciones OP_ASIG expresion 					{insertar_en_polaca("@aux_asig");}	
																			{ printf("\n<asignacion> -> <lista_de_asignaciones> OP_ASIG <expresion>"); 
																			insertar_en_polaca(":=");
																			strcpy(tipo_dato_asig, "numerico");
																			realizar_asignacion();
																			}
;

asignacion:		lista_de_asignaciones OP_ASIG CTE_STRING 								
																			{ printf("\n<asignacion> --> <lista_de_asignaciones> OP_ASIG <CONST_STRING>");
																			  insertar_en_polaca("@aux_asig");
																			  insertar_en_polaca($3);
																			  insertar_en_polaca(":=");
																			  strcpy(tipo_dato_asig, "string");
																			  realizar_asignacion();
																			}
;

lista_de_asignaciones:		ID 												{ printf("\n<lista_de_asignaciones> -> ID"); 
																			encolar( &cola_de_ids_asig, yylval.str_val);
																			}
						| lista_de_asignaciones OP_ASIG ID 					{ printf("\n<lista_de_asignaciones> -> <lista_de_asignaciones> OP_ASIG ID");
																			encolar( &cola_de_ids_asig, yylval.str_val); }
;


impresion:		DISPLAY ID 													{ printf("\n<impresion> -> DISPLAY ID");insertar_en_polaca( yylval.str_val ); }
				| DISPLAY constante 										{ printf("\n<impresion> -> DISPLAY <constante>"); }
;

lectura:		GET ID 													{ printf("\n<lectura> -> GET ID");insertar_en_polaca( yylval.str_val ); }
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
				| ID 											{ printf("\n<equfactor> -> ID ");insertar_en_polaca( yylval.str_val ); }
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

comparador:		OP_MEN 											{ printf("\n<comparador> -> <"); 
																	insertar_en_polaca("CMP");
																	 insertar_en_polaca("BGE");
																	 apilar_celda_actual();
																	  avanzar();} 		
																	  
				|OP_MAY 										{ printf("\n<comparador> -> >");
																 insertar_en_polaca("CMP");
																  insertar_en_polaca("BLE");
																  apilar_celda_actual();
																  avanzar(); }
																  
				|OP_MEN_IG 										{ printf("\n<comparador> -> <=");
																 insertar_en_polaca("CMP");
																  insertar_en_polaca("JA");
																  apilar_celda_actual();
																  avanzar();  }
																  
				|OP_MAY_IG 										{ printf("\n<comparador> -> >=");
																 insertar_en_polaca("CMP");
																  insertar_en_polaca("JB");
																  apilar_celda_actual();
																  avanzar();
																  }
																  
				|OP_IGUAL 										{ printf("\n<comparador> -> ==");
																 insertar_en_polaca("CMP");
																  insertar_en_polaca("JNE");
																  apilar_celda_actual();
																  avanzar(); }
																  
				|OP_DIST										{ printf("\n<comparador> -> !=");
																 insertar_en_polaca("CMP");
																 insertar_en_polaca("JE");
																 apilar_celda_actual();
																 avanzar(); }
;


expresion:		expresion OP_SUM termino  						{ printf("\n<expresion> -> <expresion> + <termino>");insertar_en_polaca("+"); }
				| expresion OP_RES termino 						{ printf("\n<expresion> -> <expresion> - <termino>");insertar_en_polaca("-"); }
				| termino 										{ printf("\n<expresion> -> <termino>"); }
				| LONG PA COR_A lista_id COR_C PC				{ printf("\n<expresion> -> LONG PA COR_A <lista_id> COR_C PC"); }
;

expresion: 		OP_RES expresion  %prec MENOS_UNARIO 			{ printf("\n<expresion> -> OP_RES <expresion>");
																	insertar_en_polaca("-1");
																	insertar_en_polaca("*"); }
; 					

lista_id: 	ID												{ printf("\n<lista_id> -> ID");insertar_en_polaca( yylval.str_val ); }
			|lista_id COMA ID 								{ printf("\n<lista_id> -> lista_id COMA ID");insertar_en_polaca( yylval.str_val ); }


termino:		termino OP_MULT factor 							{ printf("\n<termino> -> <termino> * <factor>"); insertar_en_polaca("*"); }
				| termino OP_DIV factor 						{ printf("\n<termino> -> <termino> / <factor>");insertar_en_polaca("/"); }
				| factor 										{ printf("\n<termino> -> <factor>"); }
;

factor:			PA expresion PC  								{ printf("\n<factor> -> ( <expresion> )"); }
				| constante 									{ printf("\n<factor> -> constante "); }
				| ID 											{ printf("\n<factor> -> ID ");insertar_en_polaca( $1 ); }
				
;



constante:		constante_num   		{ printf("\n<constante> -> <constante_num>"); }
				| CTE_STRING  		{ printf("\n<constante> -> CTE_STRING");insertar_en_polaca( $1 ); }
;

constante_num:	CTE_ENT   			{ printf("\n<constante_num> -> CTE_ENT");insertar_en_polaca( $1 ); }
				| CTE_REAL			{ printf("\n<constante_num> -> CTE_REAL");insertar_en_polaca( $1 ); }
;



%%
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

void insertar_en_polaca( char* cadena)
{
	FILE * arch= fopen("intermedia.txt", "a" );
	fprintf(arch, "%s ||", cadena);
	fclose(arch);
}

//*****************************************
void avanzar () 
{
	//// COMPLETAR	
}

void apilar_celda_actual()
{
	////COMPLETAR
}
void desapilar_posicion( int *posicion )
{
	/// COMPLETAR
}

void escribir_en_celda(int pos, int valor)
{
	////COMPLETAR
}

//*********************************************

/// FUNCIONALIDADES DE DECLARACION DE VARIABLES

/*void apilar_id_para_tipificar (char *dato)
{
	apilar ( &pila_de_ids_declaracion, dato);
}*/

void encolar_id_para_tipificar (char *dato)
{
	encolar ( &cola_de_ids_declaracion, dato);
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
					insertar_en_polaca("@aux_asig");
					insertar_en_polaca(id);
										
					insertar_en_polaca(":=");
				}
				else
				{
					sprintf(mensaje, "Error:Tipos de Dato Diferentes: Esta intentando asignar a %s un tipo de dato diferente al de su declaracion.", lexema_id.nombre);
					errorSemantico(mensaje);
				}
			}
			else
			{
				if( strcmp(lexema_id.tipo, "int") == 0 || strcmp(lexema_id.tipo, "float") == 0  )
				{
					insertar_en_polaca("@aux_asig");
					insertar_en_polaca(id);
									
					insertar_en_polaca(":=");
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

void inicializar_variables_y_archivos_de_compilacion()
{
	crear_lista(&listaTS);
    crear_archivo_para_codigo_intermedio();
	crearCola (&cola_de_ids_declaracion);
	crear_pila (&pila_de_tipos_declaracion);
	crearCola (&cola_de_ids_asig);

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


/// ERRORES 

int yyerror(void)
{
	printf("\nError Sintactico");
	borrar_tabla_simbolos();
	destruir_archivo_codigo_intermedio();
	exit(1);
}

/// ERROR SEMANTICO 
int errorSemantico(char* mensaje)
{
	printf("\nERROR SEMANTICO");
	printf("\n%s", mensaje);
	borrar_tabla_simbolos();
	destruir_archivo_codigo_intermedio();
	exit(2);
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
		imprimir_tabla_de_simbolos_en_archivo();
    }
    fclose(yyin);
    return 0;
}