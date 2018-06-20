#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayList.h"
static int cliente_setId(Cliente*this, int id);


Cliente* cliente_new()
{
    return (Cliente*) malloc(sizeof(Cliente));
}

void cliente_delete(Cliente* this)
{
    free(this);
}

Cliente* cliente_newAlta(char* nombre, char* apellido,char* dni)
{
    Cliente*auxArray = cliente_new();
    cliente_setNombre(auxArray, nombre);
    cliente_setApellido(auxArray, apellido);
    cliente_setDni(auxArray,dni);
    cliente_setId(auxArray, -1);
    return auxArray;
}
/*
Cliente* cliente_newMod(char* nombre, char* apellido,char* dni, int id)
{
    Cliente*auxArray = cliente_new();
    cliente_setNombre(auxArray, nombre);
    cliente_setApellido(auxArray, apellido);
    cliente_setDni(auxArray,dni);
    cliente_setId(auxArray, id);
    return auxArray;
}
*/

int cliente_setNombre(Cliente*this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}
int cliente_getNombre(Cliente*this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }
    return retorno;
}
int cliente_setApellido(Cliente*this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL)
    {
        strcpy(this->apellido, apellido);
        retorno = 0;
    }
    return retorno;
}
int cliente_getApellido(Cliente*this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL)
    {
        strcpy(apellido, this->apellido);
        retorno = 0;
    }
    return retorno;
}
int cliente_setDni(Cliente*this, char* dni)
{
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(this->dni,dni);
        retorno = 0;
    }
    return retorno;
}
int cliente_getDni(Cliente*this, char* dni)
{
    int retorno = -1;
    if(this != NULL && dni != NULL)
    {
        strcpy(dni, this->dni);
        retorno = 0;
    }
    return retorno;
}

static int cliente_setId(Cliente*this, int id)
{
    int retorno = -1;
    static int maximoId = -1;
    if(this != NULL)
    {
        retorno = 0;
        if(id >= 0)
        {
            if(id > maximoId)
                maximoId = id;
            this->idCliente= id;
        }
        else
        {
            maximoId++;
            this->idCliente= maximoId;
        }
    }
    return retorno;
}


int cliente_getId(Cliente*this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->idCliente;
        retorno = 0;
    }
    return retorno;
}

Cliente* cliente_newLoad(char* nombre,char* apellido,char* dni,int id)
{
    Cliente* auxCliente= cliente_new();
    if(!cliente_setNombre(auxCliente, nombre)&&!cliente_setApellido(auxCliente,apellido)
       &&!cliente_setId(auxCliente, id) && !cliente_setDni(auxCliente,dni))
    {
        return auxCliente;
    }
    cliente_delete(auxCliente);
    return NULL;
}

int cliente_alta(ArrayList* this)
{
    int retorno=-1;
    char nombre[50];
    char apellido[50];
    char dni[20];
    Cliente* auxiliar;
    if(this!=NULL)
    {
        retorno=-2;
        if(getString("nombre?\n",nombre))
        {
            if(getString("apellido?\n",apellido))
            {
                if(getStringNumeros("dni?\n",dni))
                {
                    retorno=0;
                    auxiliar=cliente_newAlta(nombre,apellido,dni);
                    al_add(this,auxiliar);
                }
            }
        }
    }
    return retorno;
}

int cliente_listarClientes(ArrayList* this)
{
    Cliente* auxiliar;
    int retorno=-1;
    int i;
    char nombre[50];
    char apellido[50];
    char dni[50];
    int id;
    if(this!=NULL)
    {
        retorno=0;
        for(i=0;i<al_len(this);i++)
        {
            auxiliar=al_get(this,i);
            cliente_getNombre(auxiliar,nombre);
            cliente_getApellido(auxiliar,apellido);
            cliente_getDni(auxiliar,dni);
            cliente_getId(auxiliar,&id);
            printf("Nombre: %s Apellido :%s Dni :%s Id: %d\n",nombre,apellido,dni,id);
        }
    }
    return retorno;
}

int cliente_baja(ArrayList* this,int index)
{
    int retorno=-1;
    Cliente* clienteAuxiliar=NULL;
    int idAuxiliar;
    int i;
    if(this!=NULL && index>=0)
    {
        retorno=0;
        for(i=0;i<al_len(this);i++)
        {
            clienteAuxiliar=al_get(this,i);
            idAuxiliar=cliente_getId(clienteAuxiliar,&index);
            if(i==idAuxiliar)
            {
                al_remove(this,i);
            }
        }
    }
    return retorno;
}

int cliente_modificacion(ArrayList* this,int index)
{
    Cliente* auxiliar;
    int retorno=-1;
    char nombre[50];
    char apellido[50];
    char dni[20];
    if(this!=NULL && index>=0)
    {
        retorno=-2;
        if(getString("Nombre?\n",nombre))
        {
            if(getString("Apellido?\n",apellido))
            {
                if(getString("Dni?\n",dni))
                {
                    retorno=0;
                    auxiliar=al_get(this,index);
                    cliente_setNombre(auxiliar,nombre);
                    cliente_setApellido(auxiliar,apellido);
                    cliente_setDni(auxiliar,dni);
                }
            }
        }
    }
    return retorno;
}
