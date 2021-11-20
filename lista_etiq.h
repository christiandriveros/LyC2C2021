#ifndef LISTA_ETIQ_H_INCLUDED
#define LISTA_ETIQ_H_INCLUDED
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef struct s_nodo_l_etq{
char nombre[100];
int numeroCelda;
struct s_nodo_l_etq *ant;
}t_nodo_l_etq;

typedef t_nodo_l_etq* t_lista_etq;

void crear_lista_etiq (t_lista_etq *dirLista)
{
    *dirLista= NULL;
}

int buscar_etiqueta_en_lista(t_lista_etq *dirLista, int numeroDeCelda)
{
    while( *dirLista != NULL)
    {
        if( (*dirLista)->numeroCelda == numeroDeCelda )
            return TRUE;
        dirLista= &((*dirLista)->ant);
    }
    return FALSE;
}

int insertar_en_lista_etq (t_lista_etq *dirLista, char *nombreEtq, int numeroDeCelda)
{
    t_nodo_l_etq *nueNodo= (t_nodo_l_etq*)malloc(sizeof(t_nodo_l_etq));
    if( ! nueNodo)
        return FALSE;
    strcpy( nueNodo->nombre, nombreEtq );
    nueNodo->numeroCelda = numeroDeCelda;
    nueNodo->ant=*dirLista;
    *dirLista= nueNodo;
    return TRUE;
}

int insertar_en_lista_etq_sin_duplic (t_lista_etq *dirLista, char *nombreEtq, int numeroDeCelda)
{
    if( buscar_etiqueta_en_lista(dirLista, numeroDeCelda) == FALSE )
    {
        if( insertar_en_lista_etq(dirLista, nombreEtq, numeroDeCelda) == FALSE )
            return FALSE;
    }
    return TRUE;
}

void vaciar_lista_etiquetas ( t_lista_etq *dirLista )
{
    t_nodo_l_etq *nodoElim;
    while( *dirLista != NULL )
    {
        nodoElim = *dirLista;
        *dirLista= nodoElim->ant;
        free(nodoElim);
    }
}

int extraer_ultima_de_lista (t_lista_etq *dirLista, t_nodo_l_etq *etiquetaRescatada)
{
    t_nodo_l_etq *nodoElim;
    if( *dirLista == NULL)
        return FALSE;
    nodoElim=*dirLista;
    strcpy(etiquetaRescatada->nombre, nodoElim->nombre);
    etiquetaRescatada->numeroCelda = nodoElim->numeroCelda;
    *dirLista = nodoElim->ant;
    free(nodoElim);
    return TRUE;
}

int lista_etiquetas_vacia( t_lista_etq *dirLista )
{
    if( *dirLista == NULL )
        return TRUE;
    return FALSE;
}

#endif // LISTA_ETIQ_H_INCLUDED
