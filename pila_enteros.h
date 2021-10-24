#ifndef PILA_ENTEROS_H_INCLUDED
#define PILA_ENTEROS_H_INCLUDED
#define TRUE 1
#define FALSE 0
typedef struct s_nodo_ent
{
    int valor;
    struct s_nodo_ent* anterior;
}t_nodo_ent;

typedef t_nodo_ent* t_pila_ent;

void crear_pila_ent(t_pila_ent *dirPila);
int apilar_ent( t_pila_ent* dirPila, int* valor);
int desapilar_ent( t_pila_ent* dirPila, int* valor);
int pila_vacia_ent ( t_pila_ent *dirPila);

void crear_pila_ent(t_pila_ent *dirPila)
{
    *dirPila = NULL;
}

int apilar_ent( t_pila_ent* dirPila, int *valor)
{
    t_nodo_ent *nueNodo = (t_nodo_ent*)malloc(sizeof(t_nodo_ent));
    if( ! nueNodo )
    {
        return FALSE;
    }
    nueNodo->valor= *valor;
    nueNodo->anterior = *dirPila;
    *dirPila=nueNodo;
    return TRUE;
}

int desapilar_ent( t_pila_ent* dirPila, int* valor)
{
    t_nodo_ent *dirNodoElim;
    if(*dirPila == NULL)
        return FALSE;
    *valor = (*dirPila)->valor;
     dirNodoElim= *dirPila;
     *dirPila = (*dirPila)->anterior;
     free(dirNodoElim);
    return TRUE;
}

int pila_vacia_ent ( t_pila_ent *dirPila)
{
    if(  !*dirPila )
        return TRUE;
    return FALSE;
}

int ver_tope_pila_ent( t_pila_ent *dirPila, int *dirInt )
{
    if( dirPila == NULL )
        return FALSE;
    *dirInt= (*dirPila)->valor;
    return TRUE;
}

#endif // PILA_H_INCLUDED
