#include <stdio.h>
#include <stdlib.h>

int getInt(char* mensaje,char* mensajeError,int reintentos,long minimo,long maximo,int* resultado)
{
    int retorno=-1;
    long dato;
    int intentos=reintentos;

    do
    {
        printf("%s",mensaje);
        scanf("%d",&dato);

        intentos--;

        if(dato<minimo|| dato>maximo)
        {
            retorno=-1;
            printf("%s\n",mensajeError);
        }
        else
            retorno=0;
    }while(retorno!=0 && intentos>0);

    if(intentos==0)
        retorno=-1;
    else
    {
        retorno=0;
        *resultado=dato;
    }

    return retorno;
}

int mostrarArrayInt(int* array , int cantidad)
{
    int retorno=-1;
    int i;
    if (cantidad > 0)
    {
        printf("\n%d",array[i]);
    }
    return retorno;
}


