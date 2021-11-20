#ifndef PILA_CELDAS_ASSEMBLER_H_INCLUDED
#define PILA_CELDAS_ASSEMBLER_H_INCLUDED
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef struct s_nodo_p_assem{
char cadena[100];
char tipo [20];
struct s_nodo_p_assem *anterior;
}t_nodo_p_assem;

typedef t_nodo_p_assem* t_pila_celdas;

void crear_pila_assem (t_pila_celdas *dirPila)
{
    *dirPila= NULL;
}

int apilar_celda_assem( t_pila_celdas* dirPila, char *cadena, char *tipo)
{
    t_nodo_p_assem *nueNodo = (t_nodo_p_assem*)malloc(sizeof(t_nodo_p_assem));
    if( ! nueNodo )
    {
        return FALSE;
    }
    strcpy(nueNodo->cadena, cadena);
    strcpy(nueNodo->tipo, tipo);
    nueNodo->anterior = *dirPila;
    *dirPila=nueNodo;
    return TRUE;
}

int desapilar_celda_assem( t_pila_celdas* dirPila, char* cadena, char *tipo)
{
    t_nodo_p_assem *dirNodoElim;
    if(*dirPila == NULL)
        return FALSE;

     strcpy(cadena, (*dirPila)->cadena);
     strcpy(tipo, (*dirPila)->tipo);
     dirNodoElim= *dirPila;
     *dirPila = (*dirPila)->anterior;
     free(dirNodoElim);

    return TRUE;
}

int pila_vacia_assem ( t_pila_celdas *dirPila)
{
    if(  !*dirPila )
        return TRUE;
    return FALSE;
}

#endif // PILA_CELDAS_ASSEMBLER_H_INCLUDED
