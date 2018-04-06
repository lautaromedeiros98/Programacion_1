#include <stdio.h>
#include <stdlib.h>
#include "CalculadoraTipoH.h"


int main()
{
    int resultado;
    int sePudo;
    resultado=dividirEnteros(100,4);
    printf("%d",resultado);
    sePudo=(retornoValorEntre(-40 , 40 ,*resultado));
    char* mensaje;
    printf("Ingrese un valor");
    scanf("%s",&mensaje)
    if(sePudo==0)
    {
        printf("%d",resultado);
    }
    else
    {
        printf("no se pudo");
    }

}
