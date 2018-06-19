#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct{
    char nombre[40];
    char apellido[40];
    char dni[20];
    int idCliente;

}Cliente;
#endif // CLIENTE_H_INCLUDED
#include "ArrayList.h"

void cliente_delete(Cliente* this);


Cliente* cliente_new();


Cliente* cliente_newLoad(char* nombre,char* apellido,char* dni,int id);
int cliente_getId(Cliente *this, int* id);
int cliente_setNombre(Cliente *this, char* nombre);
int cliente_getNombre(Cliente *this, char* nombre);
int cliente_setApellido(Cliente *this, char* apellido);
int cliente_getApellido(Cliente *this, char* apellido);
int cliente_setDni(Cliente *this, char* dni);
int cliente_getDni(Cliente *this, char* dni);
Cliente* cliente_newAlta(char* nombre, char* apellido,char* dni);
int cliente_alta(ArrayList* this);
int cliente_listarClientes(ArrayList* this);
