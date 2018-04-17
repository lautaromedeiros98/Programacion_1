#include <stdio.h>
#include <stdlib.h>

int getInt(char* mensaje,char* mensajeError,int reIntentos,int minimo,int maximo,int* resultado);
void menu();
int sumaEnteros(int primerNumero,int segundoNumero ,int *resultado);
int restaEnteros(int primerNumero,int segundoNumero ,int *resultado);
int multiplicacionEnteros(int primerNumero, int segundoNumero, int* resultado);
int divisionEnteros(int primerNumero, int segundoNumero, float* resultadoDivision);
int factorial(int primerNumero,int* resultado);
int esEntero(char *str);
int ordenarArrayInt(int * array,int cantidad,int orden);
int mostrarArrayInt(int * array,int cantidad);
int ordenarArrayIntInsertion(int * array,int cantidad,int orden);

