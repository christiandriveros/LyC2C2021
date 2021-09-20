%{
#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <float.h>
#include "y.tab.h"
#include "ts.h"

#define LONG_MAX_CTE_STRING 30
#define MAX_NUM_ENT  32767
#define LONG_MAX_ID  30

FILE *yyin;
int yylval;
char *yyltext;

void errorLexico(char* mensaje);
/// PALABRAS RESERVADAS
%}

%option noyywrap
%option yylineno

LETRA [a-zA-Z]
DIGITO [0-9]

WHILE 				(w|W)(h|H)(i|I)(l|L)(e|E)
ENDWHILE			(e|E)(n|N)(d|D)(w|W)(h|H)(i|I)(l|L)(e|E)
IF 					(i|I)(f|F)
THEN				(t|T)(h|H)(e|E)(n|N)
ELSE 				(e|E)(l|L)(s|S)(e|E)
ENDIF				(e|E)(n|N)(d|D)(i|I)(f|F)

LONG				(l|L)(o|O)(n|N)(g|G)
EQUMAX				(e|E)(q|Q)(u|U)(m|M)(a|A)(x|X)
EQUMIN				(e|E)(q|Q)(u|U)(m|M)(i|I)(n|N)
GET 				(g|G)(e|E)(t|T)
DISPLAY 			(d|D)(i|I)(s|S)(p|P)(l|L)(a|A)(y|Y)

DIM					(d|D)(i|I)(m|M)
AS					(a|A)(s|S)

T_FLOAT				(f|F)(l|L)(o|O)(a|A)(t|T)
T_INT  				(i|I)(n|N)(t|T)
T_STRING 			(s|S)(t|T)(r|R)(i|I)(n|N)(g|G)


APERT_COM			"\*""\/"
CIERRE_COM			"\/""\*"



COMENTARIO			{APERT_COM}([^*\n]|"*"[^/])*{CIERRE_COM}
COMENTARIO_ANIDADO	{APERT_COM}([^*\n]|"*"[^/]|{COMENTARIO})*{CIERRE_COM}



ID 					{LETRA}({LETRA}|{DIGITO}|"_"({LETRA}|{DIGITO}))*

CTE_ENT			{DIGITO}+
CTE_REAL		({DIGITO}+"."{DIGITO}*|{DIGITO}*"."{DIGITO}+)
CTE_STRING		"\""[^"]*"\""


OP_SUM              "\+"
OP_RES              "\-"
OP_MULT             "\*"
OP_DIV              "\/"
OP_ASIG             ":="
OP_MAY 				">"
OP_MAY_IG 			">="
OP_MEN 				"<"
OP_MEN_IG 			"<="
OP_IGUAL 			"=="
OP_DIST 			"<>"

OP_AND 				(a|A)(n|N)(d|D)
OP_OR 				(o|O)(r|R)
OP_NOT				(n|N)(o|O)(t|T)


PA					"("
PC					")"
PYC				";"
COMA 				","
DOS_PUNT			":"
COR_A 				"["
COR_C				"]"


%%

{COMENTARIO_ANIDADO}	

{COMENTARIO}		

{IF} 				{  return IF; }

{THEN}				{	return THEN;	}

{ELSE} 				{	return ELSE; }

{ENDIF}				{  return ENDIF; }


{WHILE} 			{ return WHILE;  }

{ENDWHILE}			{ return ENDWHILE; }


{LONG}			{ return LONG; }
{EQUMAX}		{return EQUMAX; }
{EQUMIN}		{return EQUMIN; }
{GET}			{ return GET; }
{DISPLAY} 			{  return DISPLAY; }


{T_INT}				{ return T_INT; }
{T_FLOAT} 			{ return T_FLOAT; }
{T_STRING} 			{return T_STRING; }

{DIM}			{ return DIM; }
{AS}			{ return AS;}

{OP_AND} 			{  return OP_AND; }
{OP_OR} 			{  return OP_OR; } 
{OP_NOT}			{  return OP_NOT; }


{OP_SUM}            {  return OP_SUM;
					}  
{OP_RES}            {  return OP_RES;
					}
{OP_MULT}           {  return OP_MULT;
					}
{OP_DIV}            {  return OP_DIV;
					}
{OP_ASIG}           {  return OP_ASIG;
					}

{OP_MAY} 			{  return OP_MAY;
					}
{OP_MAY_IG} 		{  return OP_MAY_IG;
					}
{OP_MEN} 			{  return OP_MEN;
					}
{OP_MEN_IG} 		{  return OP_MEN_IG;
					}
{OP_IGUAL} 			{  return OP_IGUAL;	
					}
{OP_DIST} 			{  return OP_DIST;
					}

{PYC}				{ return PYC;}
{PA}				{ return PA; }
{PC}				{ return PC; }
{DOS_PUNT}			{ return DOS_PUNT; }
{COMA}				{ return COMA; }
{COR_C}				{ return COR_C; }
{COR_A}				{ return COR_A; }


{CTE_STRING}  {   
					char mensaje[200];
					int longitud_string= strlen(yytext) - 2; /// -2 por para obviar las comillas.
					char cad_long[10];
					int base= 10;
					if( longitud_string > LONG_MAX_CTE_STRING )
					{
						sprintf(mensaje, 
						"ERROR LEXICO: Linea %d: Constante string %s: Longitud maxima de caracteres superada %d.",yylineno, yytext, LONG_MAX_CTE_STRING );
						errorLexico(mensaje);
					}
					else
					{
						itoa(longitud_string, cad_long, base);
						agregar_lexema("" , "" ,yytext , cad_long);
						return CTE_STRING;
					}
                 }

{CTE_REAL}		{
						char mensaje[200];
						char* endptr=NULL;
                    	errno=0;
                    	strtof(yytext, &endptr);
                    	if( errno == ERANGE)
                   		{
                    	    sprintf(mensaje,"\nERROR LEXICO: Linea %d: Constante Real %s: Valor maximo de representacion de constantes reales superado",yylineno, yytext);
                        	errorLexico(mensaje);
                   		}
                   		else
                    	{
							agregar_lexema("","",yytext,"");
                    		return CTE_REAL;
                    	}
                    }


{CTE_ENT}			{
						char mensaje[200];
						char* endptr=NULL;
                    	int base=10;
                    	long valor;
                    	errno=0;
                    	valor=strtol(yytext, &endptr, base);
                    	if( errno == ERANGE || valor > MAX_NUM_ENT )
                    	{
                        	sprintf(mensaje,"\nERROR LEXICO: Linea %d: Constante Entera %s: Valor maximo de representacion de constantes enteras superado %d.",yylineno, yytext, MAX_NUM_ENT);
          					errorLexico(mensaje);          		
                    	}
                    	else
                    	{
							agregar_lexema("","",yytext,"");
                    		return CTE_ENT;
                    	}
					}


{ID} 				{	char mensaje[200];
						int longitud_id= strlen(yytext);
						if( longitud_id > LONG_MAX_ID )
						{
							sprintf(mensaje,"\nERROR LEXICO: Linea %d: Variable %s: Longitud maxima de nombre de variable superado (%d).",yylineno, yytext, LONG_MAX_ID);
							errorLexico(mensaje);
						}
						else
						{
							agregar_lexema(yytext,"","","");
							return ID;	
						}
						
					}


" "
"\n"
"\t"
"\n\t"
"\r\n"

. { char mensaje[200];
	sprintf(mensaje, "\nError Lexico: Linea %d: Caracter o conjunto de caracteres no es un token: %s", yylineno, yytext);
	errorLexico(mensaje);
	exit(1);}


%%

void errorLexico(char* mensaje)
{
	printf("%s",mensaje);
}
