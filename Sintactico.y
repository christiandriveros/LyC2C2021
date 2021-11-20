%{
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
inicio:			programa										{ printf("\nCOMPILACION EXITOSA");
																	genera_assembler();
																}


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
																	
																encolar_id_para_tipificar($1);
																}
;
lista_simetrica: ID COR_C AS COR_A tipo_dato			{ printf("\n<lista_simetrica> -> ID COR_C AS COR_A <tipo_dato> "); 
															
																encolar_id_para_tipificar($1);
																}
;

tipo_dato: T_INT 														{ printf("\n<tipo_dato> -> T_INT"); apilar_tipos_datos( "int");}
		|	T_FLOAT														{ printf("\n<tipo_dato> -> T_FLOAT"); apilar_tipos_datos( "float");}
		|	T_STRING													{ printf("\n<tipo_dato> -> T_STRING"); apilar_tipos_datos( "string");}
;


asignacion:		lista_de_asignaciones OP_ASIG expresion 					{printf("\n<asignacion> -> <lista_de_asignaciones> OP_ASIG <expresion>"); 
																			//insertar_en_polaca("@aux_asig", TIPO_STRING);}	
																			generarNuevoAuxiliar( "@aux_asig" );
																			insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_ENTERO);
																			insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_ENTERO);		
																			insertar_en_polaca(":=", TIPO_VACIO);
																			strcpy(tipo_dato_asig, "numerico");
																			realizar_asignacion();
																			}
;

asignacion:		lista_de_asignaciones OP_ASIG CTE_STRING 								
																			{ printf("\n<asignacion> --> <lista_de_asignaciones> OP_ASIG <CONST_STRING>");
																			  	generarNuevoAuxiliar( "@aux_asig" );
																			insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_ENTERO);
																			insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_ENTERO);
																			  insertar_en_polaca($3, TIPO_STRING);
																			  insertar_en_polaca(":=", TIPO_VACIO);
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


impresion:		DISPLAY ID 													{ printf("\n<impresion> -> DISPLAY ID");display_en_polaca( yylval.str_val, "ID" ); }
				| DISPLAY constante 										{ printf("\n<impresion> -> DISPLAY <constante>"); 																				asignar_tipo_a_lexema_en_ts ( yylval.str_val, TIPO_STRING );
																			  display_en_polaca( yylval.str_val, TIPO_STRING );}
;

lectura:		GET ID 													{ printf("\n<lectura> -> GET ID"); get_en_polaca( yylval.str_val );}
;

condicional:		IF PA condicion PC THEN programa ELSE  	{			int posDesap;
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

programa ENDIF								 					{ int posDesap;
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
;

condicional:		IF PA equ PC THEN programa ENDIF 						{ printf("\n<condicional> -> IF( <equ> ) THEN <programa> ENDIF"); }
;

condicional:		IF PA equ PC THEN programa ELSE  programa ENDIF 		{ printf("\n<condicional> -> IF( <equ> )THEN <programa> ELSE <programa> ENDIF "); }
;

equ: EQUMAX PA expresion PYC COR_A lista_factores_equmax COR_C PC				{ printf("\n<equ> -> EQUMAX PA expresion PYC COR_A lista_factores_equmax COR_C PC");
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
;

equ: EQUMIN PA expresion PYC COR_A lista_factores_equmin COR_C PC				{ printf("\n<equ> -> EQUMIN PA expresion PYC COR_A 		lista_factores_equmin COR_C PC");
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
;

lista_factores_equmin: equfactor									{ printf("\n<lista_factores_equmin> -> <equfactor> ");
																generarNuevoAuxiliar( "@min" );
																insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_ENTERO);
																insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_ENTERO); 
																	insertar_en_polaca(":=", TIPO_VACIO);}
				| lista_factores_equmin COMA equfactor				{ printf("\n<lista_factores_equmin> -> <lista_factores_equmax> COMA <equfactor> "); int posDesap;
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
				desapilar_posicion( &posDesap );actualizar_celda(posDesap, num_celda_actual + 1);};
				
;


lista_factores_equmax: equfactor									{ printf("\n<lista_factores_equmax> -> <equfactor> ");
																generarNuevoAuxiliar( "@max" );
																insertar_auxiliar_en_ts(ultimoAuxiliarGenerado, TIPO_ENTERO);
																insertar_en_polaca(ultimoAuxiliarGenerado, TIPO_ENTERO); 
																	insertar_en_polaca(":=", TIPO_VACIO);}
				| lista_factores_equmax COMA equfactor				{ printf("\n<lista_factores_equmax> -> <lista_factores_equmax> COMA <equfactor> "); int posDesap;
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
				desapilar_posicion( &posDesap );actualizar_celda(posDesap, num_celda_actual + 1);};
				
;

equfactor:		constante_num 									{ printf("\n<equfactor> -> <constante_num> "); }
				| ID 											{ printf("\n<equfactor> -> ID ");insertar_en_polaca( yylval.str_val , TIPO_STRING); }
;


condicional:		IF PA condicion PC THEN programa ENDIF 						{ printf("\n<condicional> -> IF( <condicion>) THEN <programa> ENDIF"); }
;

iteracion:		WHILE PA condicion PC programa ENDWHILE 		 			{ printf("\n<iteracion> -> WHILE ( <condicion> ) <programa> ENDWHILE}"); }
;

condicion: OP_NOT { flagOpNot=TRUE; }  condicion_simple 		 				  { printf("\n<condicion> --> NOT <condicion_simple>");
																					apilar_condicion_aplicada(CONDICION_SIMPLE);
																				}

				| condicion_multiple_and 									{	 printf("\n<condicion> --> <condicion_multiple_and>");
																				apilar_condicion_aplicada(CONDICION_MULTIPLE_AND); }
				
				| condicion_multiple_or										{		 printf("\n<condicion> --> <condicion_multiple_or>");
																					apilar_condicion_aplicada(CONDICION_MULTIPLE_OR);
																			}
				
				| condicion_simple													{ printf("\n<condicion> --> <condicion_simple>");
																						apilar_condicion_aplicada(CONDICION_SIMPLE);
																					 }
				
;

condicion_multiple_and:	condicion_simple OP_AND condicion_simple		{ printf("\n<condicion_multiple_and> --> <condicion_simple> AND <condicion_simple>"); }

condicion_multiple_or:  condicion_simple 								{ int posDesap;
										 								 insertar_en_polaca(OPERADOR_BI, TIPO_VACIO);
										 								 desapilar_posicion(&posDesap);
																		 actualizar_celda(posDesap, num_celda_actual+1);
										  								 apilar_celda_actual();
										 								 avanzar();						 
																		}

OP_OR condicion_simple 										{ printf("\n<condicion_multiple_or> --> <condicion_simple> OR <condicion_simple>");
																int posDesap, apiladoGuardado;
 													  			desapilar_posicion(&apiladoGuardado);
 													  			desapilar_posicion(&posDesap);
 													 			actualizar_celda(posDesap, num_celda_actual);
 													 			apilar_celda_especifica(apiladoGuardado);
 													 									
 													 		}
;

condicion_simple: expresion comparador expresion 									{  printf("\n<condicion_simple> --> <expresion> <comparador> <expresion>");
																			 			insertar_en_polaca(OPERADOR_CMP, TIPO_VACIO);
																			   			insertar_en_polaca(comparador_guardado, TIPO_VACIO);
																						apilar_celda_actual();
																			   			avanzar();
																			   			comparar_tipos_en_comparacion();
																					 }
;

comparador:		OP_MEN 										{ printf("\n<comparador> --> <"); 
															  guardar_comparador(OPERADOR_BGE);
															}

				|OP_MAY 								{ printf("\n<comparador> --> >");
																  		guardar_comparador(OPERADOR_BLE);
																}

				|OP_MEN_IG 							{ printf("\n<comparador> --> <=");
																  guardar_comparador(OPERADOR_BGT);
																}

				|OP_MAY_IG 							{ printf("\n<comparador> --> >=");
																  guardar_comparador(OPERADOR_BLT);
																}

				|OP_IGUAL 							{ printf("\n<comparador> --> ==");
																  guardar_comparador(OPERADOR_BNE);
																}

				|OP_DIST								{ printf("\n<comparador> --> !=");
																  guardar_comparador(OPERADOR_BEQ);
																}
;


expresion:		expresion OP_SUM termino  						{ printf("\n<expresion> -> <expresion> + <termino>");char tipoResultante[20];
																 resolver_y_apilar_tipo_de_dato_por_operacion( '+', tipoResultante );
																 insertar_en_polaca("+", tipoResultante);}
				| expresion OP_RES termino 						{ printf("\n<expresion> -> <expresion> - <termino>");char tipoResultante[20];
																 resolver_y_apilar_tipo_de_dato_por_operacion( '-', tipoResultante );
																 insertar_en_polaca("-", tipoResultante);}
				| termino 										{ printf("\n<expresion> -> <termino>"); }
				| LONG PA COR_A lista_id COR_C PC				{ printf("\n<expresion> -> LONG PA COR_A <lista_id> COR_C PC"); contar_longitud();}
;

expresion: 		OP_RES expresion  %prec MENOS_UNARIO 			{ printf("\n<expresion> -> OP_RES <expresion>");
																	insertar_en_polaca("-1", TIPO_ENTERO);
																	insertar_en_polaca("*", TIPO_VACIO); }
; 					

lista_id: 	ID												{ printf("\n<lista_id> -> ID");insertar_en_polaca( yylval.str_val, TIPO_STRING );}
			|lista_id COMA ID 								{ printf("\n<lista_id> -> lista_id COMA ID");insertar_en_polaca( yylval.str_val , TIPO_STRING); encolar_id_para_longitud("id");}

;
termino:		termino OP_MULT factor 							{ printf("\n<termino> -> <termino> * <factor>"); char tipoResultante[20];
																 resolver_y_apilar_tipo_de_dato_por_operacion( '*', tipoResultante );
																 insertar_en_polaca("*", tipoResultante);}
				| termino OP_DIV factor 						{ printf("\n<termino> -> <termino> / <factor>");char tipoResultante[20];
																 resolver_y_apilar_tipo_de_dato_por_operacion( '/', tipoResultante );
																 insertar_en_polaca("/", tipoResultante);}
				| factor 										{ printf("\n<termino> -> <factor>"); }
;

factor:			PA expresion PC  								{ printf("\n<factor> -> ( <expresion> )"); }
				| constante 									{ printf("\n<factor> -> constante "); }
				| ID 											{ printf("\n<factor> -> ID ");						   					
																guardar_tipo_de_dato_id_para_tipo_expresion_e_insertar_en_polaca( yylval.str_val ); }
				
;



constante:		constante_num   		{ printf("\n<constante> -> <constante_num>"); }
				| CTE_STRING  		{ printf("\n<constante> -> CTE_STRING");insertar_en_polaca( $1 , TIPO_STRING); asignar_tipo_a_lexema_en_ts ( $1, TIPO_STRING ); apilar_tipos_datos(TIPO_STRING);}
;

constante_num:	CTE_ENT   			{ printf("\n<constante_num> -> CTE_ENT");insertar_en_polaca( $1, TIPO_ENTERO );asignar_tipo_a_lexema_en_ts ( yylval.str_val, TIPO_ENTERO ); apilar_tipos_datos(TIPO_ENTERO);}
				| CTE_REAL			{ printf("\n<constante_num> -> CTE_REAL");insertar_en_polaca( $1, TIPO_FLOTANTE ); asignar_tipo_a_lexema_en_ts ( yylval.str_val , TIPO_FLOTANTE );apilar_tipos_datos(TIPO_FLOTANTE);}
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