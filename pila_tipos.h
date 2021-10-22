#ifndef PILA_TIPOS_H_INCLUDED
#define PILA_TIPOS_H_INCLUDED
#define TRUE 1
#define FALSE 0
#include <string.h>
typedef struct s_nodo_tipos
{
    char cad[100];
    struct s_nodo_tipos* anterior;
}t_nodo_tipos;

typedef t_nodo_tipos* t_pila_tipos;


void crear_pila_tipos(t_pila_tipos *dirPila);
int apilar_tipos( t_pila_tipos* dirPila, char* cad);
int desapilar_tipos( t_pila_tipos* dirPila, char* cad);
int pila_vacia_tipos ( t_pila_tipos *dirPila);

void crear_pila_tipos(t_pila_tipos *dirPila)
{
    *dirPila = NULL;
}

int apilar_tipos( t_pila_tipos* dirPila, char *cad)
{
    t_nodo_tipos *nueNodo = (t_nodo_tipos*)malloc(sizeof(t_nodo_tipos));
    if( ! nueNodo )
    {
        return FALSE;
    }
    strcpy(nueNodo->cad, cad);
    nueNodo->anterior = *dirPila;
    *dirPila=nueNodo;
    return TRUE;
}

int desapilar_tipos( t_pila_tipos* dirPila, char* cad)
{
    t_nodo_tipos *dirNodoElim;
    if(*dirPila == NULL)
        return FALSE;
     strcpy(cad, (*dirPila)->cad);
     dirNodoElim= *dirPila;
     *dirPila = (*dirPila)->anterior;
     free(dirNodoElim);
    return TRUE;
}

int pila_vacia_tipos ( t_pila_tipos *dirPila)
{
    if(  !*dirPila )
        return TRUE;
    return FALSE;
}


#endif // PILA_STRINGS_H_INCLUDED
