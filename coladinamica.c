#include "coladinamica.h"

  void crearCola(t_cola *p)
  {

        p->pri=NULL;
        p->ult=NULL;

  }

  int colaVacia(const t_cola *p)
  {
  return (p->pri==NULL);

  }


   int colaLlena(const t_cola *p)
   {
       t_nodo *aux=malloc(sizeof(t_nodo));
       free(aux);

      return (aux==NULL);

   }


     int ponerEnCola(t_cola *p ,const t_info *d)
    {
        t_nodo *nue=(t_nodo *)malloc(sizeof(t_nodo));


        if(nue==NULL)
            return 0;

        nue->info= *d;
        nue->sig=NULL;

        if(p->pri==NULL)
            {
                p->pri=nue;
            }
        else
            {
                p->ult->sig=NULL;
            }

    p->ult=nue;

    return 1;
    }

      int sacarDeCola(t_cola *p,t_info *d)
      {
        t_nodo *aux;

       if(p->pri==NULL)
        return 0;

        aux=p->pri;
        *d=aux->info;

        if(aux->sig==NULL)
        {
            p->pri=NULL;
            p->ult=NULL;
        }
        else
        {
            p->pri=aux->sig;
        }


        free(aux);
        return 1;
      }

      void vaciarCola(t_cola *p)
      {
          t_nodo *aux;

        while(p->pri)
            {
                aux=p->pri;
                p->pri=aux->sig;
                free(aux);

            }
            p->ult=NULL;
      }



    int verPrimero(const t_cola *p,t_info *d)
        {
            if(p->pri==NULL)
                return 0;

            *d=p->pri->info;

            return 1;
        }
