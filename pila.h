#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#define TRUE 1
#define FALSE 0
#include <string.h>

typedef struct s_nodo_pila
{
    char cad[100];
    struct s_nodo_pila* anterior;
}t_nodo_pila;

typedef t_nodo_pila* t_pila;


void crear_pila (t_pila  *dirPila);
int apilar ( t_pila * dirPila, char* cad);
int desapilar ( t_pila * dirPila, char* cad);
int pila_vacia  ( t_pila  *dirPila);

void crear_pila (t_pila  *dirPila)
{
    *dirPila = NULL;
}

int apilar ( t_pila * dirPila, char *cad)
{
    t_nodo_pila  *nueNodo = (t_nodo_pila *)malloc(sizeof(t_nodo_pila ));
    if( ! nueNodo )
    {
        return FALSE;
    }
    strcpy(nueNodo->cad, cad);
    nueNodo->anterior = *dirPila;
    *dirPila=nueNodo;
    return TRUE;
}

int desapilar ( t_pila * dirPila, char* cad)
{
    t_nodo_pila  *dirNodoElim;
    if(*dirPila == NULL)
        return FALSE;
     strcpy(cad, (*dirPila)->cad);
     dirNodoElim= *dirPila;
     *dirPila = (*dirPila)->anterior;
     free(dirNodoElim);
    return TRUE;
}

int pila_vacia  ( t_pila  *dirPila)
{
    if(  !*dirPila )
        return TRUE;
    return FALSE;
}


#endif // PILA_STRINGS_H_INCLUDED
