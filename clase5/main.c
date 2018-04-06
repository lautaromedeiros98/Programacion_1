#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANTIDAD 10
int main()
{
   int i;
   int arrayEnteros[CANTIDAD];
   int auxiliarInt;
   for(i=0;i<CANTIDAD;i++)
   {
       getInt("Ingrese un numero\n", "Fuera de rango\n" , 2, 0, 100 , &auxiliarInt);
       arrayEnteros[i] = auxiliarInt;
   }




    return 0;
}
