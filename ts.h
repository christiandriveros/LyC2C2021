#ifndef TS_H_INCLUDED
#define TS_H_INCLUDED
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define READ_FILE "r"
#define APPEND_FILE "a"
#define READ_AND_WRITE_FILE "r+"
#define LEXEMA_TIPIFICADO 1
#define LEXEMA_YA_ESTABA_DECLARADO 2
#define LEXEMA_NO_ENCONTRADO 0

void inicializar_tab_simb(FILE *fp)
{
    fprintf(fp, "%s||%s||%s||%s\n", "NOMBRE", "TIPO", "VALOR", "LONGITUD");
}

void guardar_en_tab_simb(char *text, char *type, char *value, char *length)
{
    FILE *fp = fopen("ts.txt", READ_FILE);
    if (!fp)
    {
        fp = fopen("ts.txt", APPEND_FILE);
        inicializar_tab_simb(fp);
        fprintf(fp, "%s||%s||%s||%s\n", text, type, value, length);
        fclose(fp);
    }
    else
    {
        fp = fopen("ts.txt", APPEND_FILE);
        fprintf(fp, "%s||%s||%s||%s\n", text, type, value, length);
        fclose(fp);
    }
}

int buscar_lexema_en_tab_simb(char *text){

	char buffer [300];
	FILE *fp = fopen("ts.txt", READ_FILE);
    if(fp!= NULL)
	{

   		while( fscanf(fp, "%[^\n]\n", buffer) != EOF)
  		{
  		      if(strcmp(buffer,text)==0)
    		  {
					fclose(fp);
					return 1;
			  }
		}

	}
	fclose(fp);
	return 0;
}

void incluir_lexema_en_tab_simb(char *text, char *type, char *value, char *length)
{
	char nue_lexema [300];
	sprintf(nue_lexema, "%s||%s||%s||%s", text, type, value, length);
	if (buscar_lexema_en_tab_simb(nue_lexema) == 0)
	{
		guardar_en_tab_simb(text,type,value,length);
	}
}

void destruir_tab_simb()
{
	remove("ts.txt");
}
	
#endif // TS_H_INCLUDED
