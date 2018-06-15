#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"
#include "destinatario.h"
#include "parser.h"
#include <string.h>

Destinatario* destinatario_new()
{
    Destinatario* this;
    this=malloc(sizeof(Destinatario));
    return this;
}

Destinatario* destinatario_newParametros(char* nombre, char* email)
{
    Destinatario* auxDestinatario = destinatario_new();
    if(!destinatario_setNombre(auxDestinatario, nombre) && !destinatario_setEmail(auxDestinatario,email))
    {
        return auxDestinatario;
    }
    destinatario_delete(auxDestinatario);
    return NULL;
}

void destinatario_delete(Destinatario* this)
{
    free(this);
}

int destinatario_setNombre(Destinatario* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int destinatario_getNombre(Destinatario* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int destinatario_setEmail(Destinatario* this,char* email)
{
    int retorno=-1;
    if(this!=NULL && email!=NULL)
    {
        strcpy(this->email,email);
        retorno=0;
    }
    return retorno;
}

int destinatario_getEmail(Destinatario* this,char* email)
{
    int retorno=-1;
    if(this!=NULL && email!=NULL)
    {
        strcpy(email,this->email);
        retorno=0;
    }
    return retorno;
}



