#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#define TRUE 1
#define FALSE 0
typedef struct s_nodo_ids
{
    int valor;
    struct s_nodo_ids* anterior;
}t_nodo_ids;

typedef t_nodo_ids* t_pila_ids;

void crear_pila_ids(t_pila_ids *dirPila);
int apilar_ids( t_pila_ids* dirPila, char* valor);
int desapilar_ids( t_pila_ids* dirPila, char* valor);
int pila_vacia_ids ( t_pila_ids *dirPila);

void crear_pila_ids(t_pila_ids *dirPila)
{
    *dirPila = NULL;
}

int apilar_ids( t_pila_ids* dirPila, char *valor)
{
    t_nodo_ids *nueNodo = (t_nodo_ids*)malloc(sizeof(t_nodo_ids));
    if( ! nueNodo )
    {
        return FALSE;
    }
    nueNodo->valor= *valor;
    nueNodo->anterior = *dirPila;
    *dirPila=nueNodo;
    return TRUE;
}

int desapilar_ids( t_pila_ids* dirPila, char* valor)
{
    t_nodo_ids *dirNodoElim;
    if(*dirPila == NULL)
        return FALSE;
    *valor = (*dirPila)->valor;
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

#endif // PILA_H_INCLUDED
