#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "utn.h"
#include "cliente.h"


int controller_leerArchivoClientes(char* path, ArrayList* pArrayClientes)
{
    char bNombre[4096];
    char bApellido[4096];
    char bEmail[4096];
    char bGenero[4096];
    char bProfesion[4096];
    char bNacionalidad[4096];
    char bUsuario[4096];
    char bId[4096];
    Cliente* pAuxiliarCliente;
    FILE* pFile;
    int retorno = -1;
    pFile = fopen(path,"r");
    if(pFile != NULL)
    {
        retorno = 0;
        fscanf(pFile,"  %[^,],%[^,],%[^,],\
                %[^,],%[^,],%[^,],\
                %[^,],%[\n]\n",
                    bId,
                    bNombre,
                    bApellido,
                    bEmail,
                    bGenero,
                    bProfesion,
                    bUsuario,
                    bNacionalidad
                    );
        while(!feof(pFile))
        {
            fscanf(pFile,"  %[^,],%[^,],%[^,],\
                            %[^,],%[^,],%[^,],\
                            %[^,],%[\n]\n",
                                bId,
                                bNombre,
                                bApellido,
                                bEmail,
                                bGenero,
                                bProfesion,
                                bUsuario,
                                bNacionalidad
                                );


            pAuxiliarCliente = cliente_newParametros(   bNombre,
                                                        bApellido,
                                                        bEmail,
                                                        bGenero,
                                                        bProfesion,
                                                        bNacionalidad,
                                                        bUsuario,
                                                        atoi(bId));

            al_add(pArrayClientes,pAuxiliarCliente);
        }
    }
    fclose(pFile);
    return retorno;
}

int controller_listarClientes(ArrayList* pArrayClientes)
{
    int retorno = -1;
    int i;
    Cliente* auxiliarCliente;
    char nombre[64];
    char apellido[64];
    char email[256];
    char genero;
    char profesion[256];
    char nacionalidad[256];
    char usuario[64];
    int id;

    for(i=0;i<al_len(pArrayClientes);i++)
    {
        auxiliarCliente = al_get(pArrayClientes,i);
        cliente_getNombre(auxiliarCliente,nombre);
        cliente_getApellido(auxiliarCliente,apellido);
        printf("\n%s - %s - %d",nombre,apellido,i);
    }




    return retorno;
}

int controller_ordenarClientesNombreApellido(ArrayList* pArrayClientes)
{
    int retorno = -1;
    if(pArrayClientes != NULL)
    {
        retorno = 0;
        al_sort(pArrayClientes,cliente_ordenarNombreApellido,1);
    }
    return retorno;
}


int controller_guardarClientesArchivo(char* path, ArrayList* pArrayClientes)
{
    int retorno = -1;
    int i;
    Cliente* auxiliarCliente;
    char nombre[64];
    char apellido[64];
    char email[256];
    char genero;
    char profesion[256];
    char nacionalidad[256];
    char usuario[64];
    int id;
    FILE* pFile;
    pFile = fopen(path,"w");
    if(pFile != NULL)
    {
    fprintf(pFile,"id,nombre,apellido,email,genero,profesion,usuario,nacionalidad\n");
        for(i=0;i<al_len(pArrayClientes);i++)
        {
            auxiliarCliente = al_get(pArrayClientes,i);
            cliente_getNombre(auxiliarCliente,nombre);
            cliente_getApellido(auxiliarCliente,apellido);
            cliente_getEmail(auxiliarCliente,email);
            cliente_getGenero(auxiliarCliente,&genero);
            cliente_getProfesion(auxiliarCliente,profesion);
            cliente_getNacionalidad(auxiliarCliente,nacionalidad);
            cliente_getUsuario(auxiliarCliente,usuario);
            cliente_getId(auxiliarCliente,&id);
            fprintf(stdout,"%d,%s,%s,%s,%c,%s,%s,%s\n",
                    id,nombre,apellido,email,genero,
                    profesion,usuario,nacionalidad);

        }
    }
    fclose(pFile);


    return retorno;
}










