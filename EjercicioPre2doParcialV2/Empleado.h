#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "ArrayList.h"

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;

int em_calcularSueldo(ArrayList* listaEmpleados,int* sueldo);
Empleado* empleado_new();
void empleado_delete(Empleado* this);
int empleado_getHoras(Empleado* this, int* horas);
int empleado_setHoras(Empleado* this, int horas);
int empleado_getNombre(Empleado* this, char* nombre);
int empleado_setNombre(Empleado* this, char* nombre);
Empleado* empleado_newLoad(int id, char* nombre,int horasTrabajadas);

#endif // EMPLEADO_H_INCLUDED
