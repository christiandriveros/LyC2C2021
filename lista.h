#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <string.h>
#define TRUE 1
#define FALSE 0
#define LEXEMA_TIPIFICADO 4
#define LEXEMA_YA_DECLARADO 5
#define LEXEMA_NO_ENCONTRADO 6
#define CAMPO_VACIO ""

typedef struct{
char nombre[100];
char tipo[100];
char valor[100];
char longitud[100];
}t_lexema;

typedef struct s_nodo{
t_lexema lex;
struct s_nodo *sig;
}t_nodo_l;

typedef t_nodo_l* t_lista;

void crear_lista (t_lista *dirLista)
{
    *dirLista= NULL;
}

int insertar_en_lista (t_lista *dirLista, t_lexema *lexema)
{
    t_nodo_l *nueNodo= (t_nodo_l*)malloc(sizeof(t_nodo_l));
    if( ! nueNodo)
        return FALSE;
    strcpy( nueNodo->lex.nombre, lexema->nombre);
    strcpy( nueNodo->lex.tipo, lexema->tipo );
    strcpy( nueNodo->lex.valor, lexema->valor);
    strcpy( nueNodo->lex.longitud, lexema->longitud);

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

int extraer_primero_de_lista ( t_lista *dirLista, t_lexema *dirLexema )
{
    t_nodo_l* nodoElim;
    if( *dirLista == NULL )
        return FALSE;

    strcpy(dirLexema->nombre, (*dirLista)->lex.nombre);
    strcpy(dirLexema->tipo, (*dirLista)->lex.tipo);
    strcpy(dirLexema->valor, (*dirLista)->lex.valor);
    strcpy(dirLexema->longitud, (*dirLista)->lex.longitud);

    nodoElim= *dirLista;
    *dirLista= (*dirLista)->sig;
    free(nodoElim);
    return TRUE;

}

int buscar_en_lista (t_lista *dirLista, char *nombre, t_lexema *dirLexema)
{

    if(  *dirLista == NULL)
        return FALSE;
    while( *dirLista != NULL )
    {
        if( strcmp( (*dirLista)->lex.nombre, nombre) == 0 )
        {
            strcpy(dirLexema->nombre, (*dirLista)->lex.nombre);
            strcpy(dirLexema->tipo, (*dirLista)->lex.tipo);
            strcpy(dirLexema->valor, (*dirLista)->lex.valor);
            strcpy(dirLexema->longitud, (*dirLista)->lex.longitud);
            return TRUE;
        }
        dirLista = &((*dirLista)->sig);

    }
    return FALSE;
}

int lista_vacia(t_lista *dirLista)
{
    if( *dirLista == NULL)
        return TRUE;
    return FALSE;
}

int asignar_tipo_a_lexema ( t_lista *dirLista, char *nombre, char* tipo )
{
    while( *dirLista != NULL )
    {
        if( strcmp( (*dirLista)->lex.nombre, nombre) == 0 )
        {

            if( strcmp( (*dirLista)->lex.tipo, CAMPO_VACIO) == 0)
            {
                strcpy((*dirLista)->lex.tipo, tipo);
                return LEXEMA_TIPIFICADO;
            }
            else
            {
                return LEXEMA_YA_DECLARADO;
            }

        }
        dirLista = &((*dirLista)->sig);
    }
    return LEXEMA_NO_ENCONTRADO;
}

int volcar_lista_a_tabla_de_simbolos(t_lista *dirLista)
{
    FILE *ts=fopen("ts.txt", "w+");
    t_lexema lexemaRecuperado;

    if( ts == NULL)
        return FALSE;

    fprintf(ts, "%s||%s||%s||%s\n", "NOMBRE", "TIPO", "VALOR", "LONGITUD");
    while( ! lista_vacia(dirLista) )
    {
        extraer_primero_de_lista(dirLista, &lexemaRecuperado);
        fprintf(ts, "%s||%s||%s||%s\n", lexemaRecuperado.nombre, lexemaRecuperado.tipo, lexemaRecuperado.valor, lexemaRecuperado.longitud );
    }
    return TRUE;
}

#endif // LISTA_H_INCLUDED
