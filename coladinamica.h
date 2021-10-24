#ifndef COLADINAMICA_H_INCLUDED
#define COLADINAMICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_nodo_cola
{

   char cad[100];
   struct s_nodo_cola* sig;

}t_nodo;

typedef struct
{
    t_nodo *pri,
           *ult;
}t_cola;


  void crearCola(t_cola *p);
  int colaVacia(t_cola *p);
  int encolar(t_cola *p ,char* cad);
  int desacolar(t_cola *p,char* cad);

void crearCola(t_cola *p)
	{

        p->pri=NULL;
        p->ult=NULL;

	}
  
 int colaVacia(t_cola *p)
  {
  return (p->pri==NULL);

  }

int encolar(t_cola *p ,char *cad)
    {
        t_nodo *nue=(t_nodo *)malloc(sizeof(t_nodo));

        if(nue==NULL)
            return 0;

        strcpy(nue->cad, cad);
        nue->sig=NULL;

        if(p->pri==NULL)
            {
                p->pri=nue;
            }
        else
            {
                p->ult->sig=nue;
            }

    p->ult=nue;

    return 1;
    }
	
int desacolar(t_cola *p,char *cad)
      {
        t_nodo *aux;

       if(p->pri==NULL)
        return 0;

        aux=p->pri;
        

        if(aux->sig==NULL)
        {
            p->pri=NULL;
            p->ult=NULL;
        }
        else
        {
            p->pri=aux->sig;
        }

		strcpy(cad, aux->cad);
        free(aux);
        return 1;
      }

#endif // COLADINAMICA_H_INCLUDED
