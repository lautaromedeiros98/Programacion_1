#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h"
#include <string.h>
static int cliente_setId(Cliente* this);

Cliente* cliente_new()
{
    return (Cliente*)malloc(sizeof(Cliente));
}

Cliente* cliente_newForzado(char* nombre,char* apellido,int edad)
{
    Cliente* nuevoCliente;
    nuevoCliente=cliente_new();
    cliente_setApellido(nuevoCliente,apellido);
    cliente_setNombre(nuevoCliente,nombre);
    cliente_setEdad(nuevoCliente,edad);
    cliente_setId(nuevoCliente);

    return nuevoCliente;
}

void cliente_delete(Cliente* this)
{
    free(this);
}

//setters
int cliente_setApellido(Cliente* this,char* apellido)
{
    int retorno= -1;
    if(this!=NULL)
    {
        strcpy(this->apellido,apellido);
        retorno=0;
    }
    return retorno;
}

int cliente_setNombre(Cliente* this,char* nombre)
{
    int retorno= -1;
    if(this!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

static int cliente_setId(Cliente* this)
{
    int retorno=-1;
    static int ultimoId=-1;
    if(this!=NULL)
    {
        ultimoId++;
        this->idCliente = ultimoId;
        retorno=0;
    }
    return retorno;
}

int cliente_setEdad(Cliente* this,int edad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->edad = edad;
        retorno=0;
    }
    return retorno;
}
//seters

//getters
int cliente_getNombre(Cliente* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(nombre, this->nombre);
        retorno=0;
    }
    return retorno;
}

int cliente_getApellido(Cliente* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(apellido, this->apellido);
        retorno=0;
    }
    return retorno;
}

int cliente_getEdad(Cliente* this,int* edad)
{
    int retorno=-1;
    if(this!=NULL && edad!=NULL)
    {
        *edad = this->edad;
        retorno=0;
    }
    return retorno;
}

int cliente_getId(Cliente* this,int* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL)
    {
        *id=this->idCliente;
        retorno=0;
    }
    return retorno;
}
//getters


int cliente_alta(Cliente* punteroArrayC[], int* cantidadArrayC)
{
    char nombre[50];
    char apellido[50];
    int edad;
    int retorno=-1;
    if(punteroArrayC!=NULL)
    {
        getValidString("Nombre?","Nombre invalido","Overflow",nombre,50,10);
        getValidString("Apellido?","Apellido invalido","Overflow",apellido,50,10);
        getValidInt("Edad?","Edad no valida",&edad,0,100,10);

        punteroArrayC[*cantidadArrayC] = cliente_newForzado(nombre,apellido,edad);
        *cantidadArrayC = *cantidadArrayC+1;

        retorno=0;
    }
    return retorno;
}

int cliente_mostrar(Cliente* punteroArrayC[],int cantidad)
{
    char nombre[50];
    char apellido[50];
    int edad;
    int i;
    int id;
    int retorno=-1;
    if(punteroArrayC!=NULL)
    {
        retorno=0;
        for(;cantidad>0;punteroArrayC++,cantidad--)
        {
            cliente_getNombre(*punteroArrayC,&nombre);
            printf("Nombre:%s     ",nombre);

            cliente_getApellido(*punteroArrayC,&apellido);
            printf("Apellido:%s    ",apellido);

            cliente_getEdad(*punteroArrayC,&edad);
            printf("Edad:%d    ",edad);

            cliente_getId(*punteroArrayC,&id);
            printf("ID:%d    ",id);
        }
    }
    return retorno;
}

