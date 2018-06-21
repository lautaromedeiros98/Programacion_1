#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "ArrayList.h"

Empleado* empleado_new()
{
    return (Empleado*)malloc(sizeof(Empleado));
}

void empleado_delete(Empleado* this)
{
    free(this);
}

int em_calcularSueldo(ArrayList* listaEmpleados,int* sueldo)
{
    int retorno=-3;
    int i;
    int horas;
    if(listaEmpleados!=NULL)
    {
        retorno=-2;
        Empleado* auxiliar=empleado_new();
        for(i=0;i<al_len(listaEmpleados);i++)
        {
            auxiliar=al_get(listaEmpleados,i);
            empleado_getHoras(auxiliar,&horas);
            if(horas<120)
            {
                retorno=-1;
                *sueldo= (180*horas);
            }
            else
            {
                if(horas>=120 && horas<160)
                {
                    retorno=0;
                    *sueldo=(240*horas);
                }
                if(horas>=160 && horas<240)
                {
                    retorno=1;
                    *sueldo=(350*horas);
                }
            }
        }
    }
return retorno;
}

int empleado_setHoras(Empleado* this,int horas)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        this->horasTrabajadas = horas;
    }
    return retorno;
}

int empleado_getHoras(Empleado* this, int* horas)
{
    int retorno = -1;
    if(this != NULL && horas!= NULL)
    {
        retorno = 0;
        *horas = this->horasTrabajadas;
    }
    return retorno;
}

int empleado_setNombre(Empleado* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        retorno = 0;
        strcpy(this->nombre,nombre);
    }
    return retorno;
}

int empleado_getNombre(Empleado* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        retorno = 0;
        strcpy(nombre,this->nombre);
    }
    return retorno;
}


Empleado* empleado_newLoad(int id, char* nombre,int horasTrabajadas)
{
    Empleado* auxiliar= empleado_new();
    if(!empleado_setNombre(auxiliar,nombre) && !empleado_setHoras(auxiliar,horasTrabajadas))
    {
        return auxiliar;
    }
    empleado_delete(auxiliar);
    return NULL;
}
