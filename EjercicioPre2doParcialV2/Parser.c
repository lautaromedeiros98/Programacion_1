#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "ArrayList.h"

int parser_parseEmpleados(char* path, ArrayList* listaEmpleados)
{
    int retorno=-1;
    FILE* pFile;
    char id[128];
    char nombre[128];
    char horasTrabajadas[128];
    Empleado* auxiliar;
    pFile=fopen(path,"r");
    if(pFile!=NULL)
    {
        retorno=0;
        {
            while(!feof(pFile))
            {
                fscanf(pFile,"%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas);
                auxiliar=empleado_newLoad(atoi(id),nombre,atoi(horasTrabajadas));
                al_add(listaEmpleados,auxiliar);
            }
        }
    }
    fclose(pFile);
    return retorno;
}

