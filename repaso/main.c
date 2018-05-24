#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

int main()
{
    int cantidadClientes=0;
    Cliente* punteroArrayC;
    punteroArrayC=(Cliente*)malloc(sizeof(Cliente));

    cliente_alta(punteroArrayC,&cantidadClientes);
    cliente_mostrar(punteroArrayC,cantidadClientes);

    return 0;
}
