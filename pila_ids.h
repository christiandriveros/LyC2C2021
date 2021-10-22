#ifndef PILA_ids_H_INCLUDED
#define PILA_ids_H_INCLUDED
#define TRUE 1
#define FALSE 0
#include <string.h>
typedef struct s_nodo_ids
{
    char cad[100];
    struct s_nodo_ids* anterior;
}t_nodo_ids;

typedef t_nodo_ids* t_pila_ids;


void crear_pila_ids(t_pila_ids *dirPila);
int apilar_ids( t_pila_ids* dirPila, char* cad);
int desapilar_ids( t_pila_ids* dirPila, char* cad);
int pila_vacia_ids ( t_pila_ids *dirPila);

void crear_pila_ids(t_pila_ids *dirPila)
{
    *dirPila = NULL;
}

int apilar_ids( t_pila_ids* dirPila, char *cad)
{
    t_nodo_ids *nueNodo = (t_nodo_ids*)malloc(sizeof(t_nodo_ids));
    if( ! nueNodo )
    {
        return FALSE;
    }
    strcpy(nueNodo->cad, cad);
    nueNodo->anterior = *dirPila;
    *dirPila=nueNodo;
    return TRUE;
}

int desapilar_ids( t_pila_ids* dirPila, char* cad)
{
    t_nodo_ids *dirNodoElim;
    if(*dirPila == NULL)
        return FALSE;
     strcpy(cad, (*dirPila)->cad);
     dirNodoElim= *dirPila;
     *dirPila = (*dirPila)->anterior;
     free(dirNodoElim);
    return TRUE;
}

int pila_vacia_ids ( t_pila_ids *dirPila)
{
    if(  !*dirPila )
        return TRUE;
    return FALSE;
}


#endif // PILA_STRINGS_H_INCLUDED
