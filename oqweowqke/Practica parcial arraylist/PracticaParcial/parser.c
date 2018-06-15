#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"
#include "destinatario.h"
#include "parser.h"
#include "utn.h"

int parser_leerArchivoDestinatario(char* path, ArrayList* pArrayDestinatario)
{
    char nombre[4096];
    char email[4096];
    Destinatario* pDestinatario;
    FILE* pFile;
    int retorno = -1;
    pFile = fopen(path,"r");
    if(pFile != NULL )
    {
        retorno = 0;
        fscanf(pFile,"%[^,],%[\n]\n",nombre,email);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[\n]\n",nombre,email);
            pDestinatario = destinatario_newParametros(nombre,email);
            al_add(pArrayDestinatario,pDestinatario);
        }
    }
    fclose(pFile);
    return retorno;
}


int parser_listarDestinatarios(ArrayList* pArrayDestinatario)
{
    int retorno = -1;
    int i;
    Destinatario* auxiliarDestinatario;
    char nombre[64];
    char email[256];
    for(i=0;i<al_len(pArrayDestinatario);i++)
    {
        auxiliarDestinatario = al_get(pArrayDestinatario,i);
        destinatario_getNombre(auxiliarDestinatario,nombre);
        destinatario_getEmail(auxiliarDestinatario,email);
        printf("\n%s - %s - ",nombre,email);
    }
    return retorno;
}
