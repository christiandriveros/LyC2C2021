#ifndef LISTA_STR_H_INCLUDED
#define LISTA_STR_H_INCLUDED
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef struct s_nodo_l_str{
char cadena[100];
char tipo [20];
struct s_nodo_l_str *sig;
}t_nodo_l_str;

typedef t_nodo_l_str* t_lista_cod_inter;

void crear_lista_inter (t_lista_cod_inter *dirLista)
{
    *dirLista= NULL;
}

int insertar_en_lista_inter (t_lista_cod_inter *dirLista, char *cadena, char* tipo)
{
    t_nodo_l_str *nueNodo= (t_nodo_l_str*)malloc(sizeof(t_nodo_l_str));
    if( ! nueNodo)
        return FALSE;
    strcpy( nueNodo->cadena, cadena );
    strcpy( nueNodo->tipo, tipo );
    nueNodo->sig=NULL;
    if( *dirLista == NULL )
    {
        *dirLista= nueNodo;
        return TRUE;
    }
    while(  (*dirLista)->sig != NULL  )
    {
        dirLista= &((*dirLista)->sig);
    }
    (*dirLista)->sig= nueNodo;
    return TRUE;

}

int extraer_primero_de_lista_inter ( t_lista_cod_inter *dirLista, char *cadena, char *tipo )
{
    t_nodo_l_str* nodoElim;
    if( *dirLista == NULL )
        return FALSE;

    strcpy(cadena, (*dirLista)->cadena);
    strcpy(tipo, (*dirLista)->tipo);
    nodoElim= *dirLista;
    *dirLista= (*dirLista)->sig;
    free(nodoElim);
    return TRUE;
}

int actualizar_contenido_de_celda ( t_lista_cod_inter *dirLista, int numCelda, char* cadenaReemplazo )
{
    int celdaActual=0;
    if( *dirLista == NULL )
        return FALSE;

    while( *dirLista != NULL && celdaActual != numCelda )
    {
            dirLista= &(*dirLista)->sig;
            celdaActual++;
    }
    if( *dirLista == NULL )
    {
        return FALSE;
    }
    if( numCelda == celdaActual )
    {
        strcpy((*dirLista)->cadena, cadenaReemplazo);
        return TRUE;
    }
    return FALSE;
}

int lista_inter_vacia(t_lista_cod_inter *dirLista)
{
    if( *dirLista == NULL)
        return TRUE;
    return FALSE;
}

int crear_archivo_notacion_intermedia( t_lista_cod_inter *dirLista)
{
    char buffer[100];
    FILE* pf= fopen("intermedia.txt", "w+");
    char tipo[30];
    if( pf == NULL)
        return FALSE;
    while( ! lista_inter_vacia(dirLista) )
    {
        extraer_primero_de_lista_inter(dirLista, buffer, tipo );
        fprintf(pf, "%s||", buffer );
    }
    fclose(pf);
    return TRUE;
}

void duplicar_lista_cod_intermedio( t_lista_cod_inter *dirListaOrig, t_lista_cod_inter *dirListaDuplicado )
{
    crear_lista_inter(dirListaDuplicado);
    while( (*dirListaOrig) != NULL)
    {
        insertar_en_lista_inter(dirListaDuplicado, (*dirListaOrig)->cadena, (*dirListaOrig)->tipo );
        dirListaOrig=&((*dirListaOrig)->sig);
    }
}

#endif // LISTA_STR_H_INCLUDED
