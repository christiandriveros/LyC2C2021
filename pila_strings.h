#ifndef PILA_STRINGS_H_INCLUDED
#define PILA_STRINGS_H_INCLUDED
#define TRUE 1
#define FALSE 0
#include <string.h>
typedef struct s_nodo_str
{
    char cad[100];
    struct s_nodo_str* anterior;
}t_nodo_str;

typedef t_nodo_str* t_pila_str;

void crear_pila_str(t_pila_str *dirPila);
int apilar_str( t_pila_str* dirPila, char* cad);
int desapilar_str( t_pila_str* dirPila, char* cad);
int pila_vacia_str ( t_pila_str *dirPila);

void crear_pila_str(t_pila_str *dirPila)
{
    *dirPila = NULL;
}

int apilar_str( t_pila_str* dirPila, char *cad)
{
    t_nodo_str *nueNodo = (t_nodo_str*)malloc(sizeof(t_nodo_str));
    if( ! nueNodo )
    {
        return FALSE;
    }
    strcpy(nueNodo->cad, cad);
    nueNodo->anterior = *dirPila;
    *dirPila=nueNodo;
    return TRUE;
}

int desapilar_str( t_pila_str* dirPila, char* cad)
{
    t_nodo_str *dirNodoElim;
    if(*dirPila == NULL)
        return FALSE;
     strcpy(cad, (*dirPila)->cad);
     dirNodoElim= *dirPila;
     *dirPila = (*dirPila)->anterior;
     free(dirNodoElim);
    return TRUE;
}

int pila_vacia_str ( t_pila_str *dirPila)
{
    if(  !*dirPila )
        return TRUE;
    return FALSE;
}

void vaciar_pila_str( t_pila_str *dirPila )
{
    t_nodo_str *nodoAEliminar;
    while( *dirPila != NULL )
    {
        nodoAEliminar= *dirPila;
        *dirPila= nodoAEliminar->anterior;
        free(nodoAEliminar);
    }

}

#endif // PILA_STRINGS_H_INCLUDED
