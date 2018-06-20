#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "cliente.h"

int parser_guardarEnArchivo(char* path,ArrayList* clientes)
{
    Cliente* auxiliar;
    int i;
    int retorno=-1;
    char nombre[50];
    char apellido[50];
    char dni[50];
    int id;
    FILE* pFile;
    pFile=fopen(path,"w");
    if(clientes!=NULL && pFile!=NULL)
    {
        retorno=0;
        for(i=0;i<al_len(clientes);i++)
        {
            auxiliar=al_get(clientes,i);
            cliente_getNombre(auxiliar,nombre);
            cliente_getApellido(auxiliar,apellido);
            cliente_getDni(auxiliar,dni);
            cliente_getId(auxiliar,&id);
            fprintf(pFile,"%s,%s,%s,%d\n",nombre,apellido,dni,id);
        }
        fclose(pFile);
    }
    return retorno;
}

int parser_leerDelArchivo(char* path,ArrayList* clientes)
{
    Cliente* auxiliar;
    char nombre[50];
    char apellido[50];
    char dni[20];
    char id[50];
    int retorno=-1;
    FILE* pFile;
    pFile=fopen(path,"r");
    if(pFile!=NULL)
    {
        retorno=0;
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",nombre,apellido,dni,id);
            auxiliar=cliente_newLoad(nombre,apellido,dni,atoi(id));
            al_add(clientes,auxiliar);
        }
    }
    fclose(pFile);
    return retorno;
}
