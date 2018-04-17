#include <stdio.h>
#include <stdlib.h>

int getInt(char* mensaje,char* mensajeError,int reIntentos,int minimo,int maximo,int* resultado)
{
    int retorno = -1;
    char buffer[4096];
    long auxiliarLong;
    do
    {
        printf("%s",mensaje);
        scanf("%4095s",buffer);
        if(esEntero(buffer) == 1)
        {
            auxiliarLong = atol(buffer);
            if(auxiliarLong >= minimo && auxiliarLong <= maximo)
            {
                *resultado = (int)auxiliarLong;
                retorno = 0;
                break;
            }
        }
        printf("%s",mensajeError);
        reIntentos--;
    }while(reIntentos >= 0);
    return retorno;
}


int esEntero(char *str)
{
    int i;
    for(i=0;str[i] != '\0';i++)
    {
        if(str[i] > '9' || str[i] < '0')
            return 0;
    }
    return 1;
}

void menuTP()
{
        printf("*****INGRESE...***** \n");
        printf("1- Ingresar 1er operando \n");
        printf("2- Ingresar 2do operando \n");
        printf("3- Calcular la suma \n");
        printf("4- Calcular la resta \n");
        printf("5- Calcular la division \n");
        printf("6- Calcular la multiplicacion \n");
        printf("7- Calcular el factorial \n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

}

int sumaEnteros(int primerNumero, int segundoNumero, int* resultado)
{
    long resultadoAuxiliar;
    int retorno= -1;
    resultadoAuxiliar=primerNumero+segundoNumero;
    if(resultadoAuxiliar<32676 && resultadoAuxiliar>-32676 )
    {
        *resultado=resultadoAuxiliar;
        retorno=0;

    }
    else
    {
        retorno=-1;
        printf("ERROR fuera de rango \n");
    }
    return retorno;
}

int restaEnteros(int primerNumero, int segundoNumero, int* resultado)
{
    long resultadoAuxiliar;
    int retorno= -1;
    resultadoAuxiliar=primerNumero-segundoNumero;
    if(resultadoAuxiliar<32676 && resultadoAuxiliar>-32676 )
    {
        *resultado=resultadoAuxiliar;
        retorno=0;
    }
    else
    {
        retorno=-1;
        printf("ERROR fuera de rango \n");
    }
    return retorno;
}

int multiplicacionEnteros(int primerNumero, int segundoNumero, int* resultado)
{
    long resultadoAuxiliar;
    int retorno= -1;
    resultadoAuxiliar=primerNumero*segundoNumero;
    if(resultadoAuxiliar<32676 && resultadoAuxiliar>-32676 )
    {
        *resultado=resultadoAuxiliar;
        retorno=0;
    }
    else
    {
        retorno=-1;
        printf("ERROR fuera de rango \n");
    }
    return retorno;
}

int divisionEnteros(int primerNumero, int segundoNumero, float* resultadoDivision)
{
    float resultadoAuxiliar;
    int retorno= -1;
    resultadoAuxiliar=(float)primerNumero/(float)segundoNumero;
    if(resultadoAuxiliar>0 )
    {
        *resultadoDivision=resultadoAuxiliar;
        retorno=0;
    }
    else
    {
        retorno=-1;
        printf("ERROR fuera de rango \n");
    }
    return retorno;
}

int factorial(int primerNumero,int* resultado)
{

    int retorno= -1;
    int i;
    long acumulador=1;
    for(i=1;i<=primerNumero;i++)
    {
        acumulador=acumulador*i;
    }
    if(acumulador<2147483647 && acumulador>-2147483648)
    {
        *resultado=acumulador;
        retorno=0;
    }
    else
    {
        retorno=-1;
        printf("ERROR fuera de rango \n");
    }
    return retorno;
}

int ordenarArrayInt(int * array,int cantidad,int orden)
{
    int i;
    int flagSwap;
    int auxiliar;

    do
    {
        flagSwap = 0;
        for(i=0;i< cantidad-1;i++)
        {
            if((array[i]>array[i+1] && orden == 0) || (array[i]<array[i+1] && orden == 1))
            {
                auxiliar = array[i];
                array[i] = array[i+1];
                array[i+1] = auxiliar;
                flagSwap = 1;
            }

        }
    }while(flagSwap);

    return 0;
}

int mostrarArrayInt(int * array,int cantidad)
{
    int i;
    printf(" ------ ");
    for(i=0;i<cantidad;i++)
    {
        printf("%d ",array[i]);
    }
    return 0;
}

int ordenarArrayIntInsertion(int * array,int cantidad,int orden)
{
	int auxiliar;
    int j, i;

	for(i = 1; i < cantidad; i++) {
		auxiliar = array[i];
		j = i;
		while(j > 0 && auxiliar < array[j - 1])
        {
			array[j] = array[j - 1];
			j--;
		}
		array[j] = auxiliar;
	}
    return 0;
}
