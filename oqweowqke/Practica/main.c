#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Cliente.h"
#include "utn.h"
#include "controller.h"

/****************************************************
    Menu:
        1. Cargar datos desde data.csv
        2. Listar Clientes
        3. Ordenar por nombre y apellido
        4. Ordenar por mail
        5. Agregar un Cliente
        6. Elimina un Cliente
        7. Modificar Cliente (Nombre, Apellido y Mail)
        8. Listar Clientes
        9. Guardar datos en data.csv (modo texto)
       10. Guardar datos en data.bin (modo binario)
*****************************************************/


int main()
{

    ArrayList* pArrayClientes;
    pArrayClientes = al_newArrayList();

    int menuOpcionElegida;
    char menuPrinsipalMensaje[] =
                "   \n1. Cargar datos desde data.csv\
                    \n2. Listar Clientes\
                    \n3. Ordenar por nombre y apellido\
                    \n4. Ordenar por mail\
                    \n5. Agregar un Cliente\
                    \n6. Elimina un Cliente\
                    \n7. Modificar Cliente (Nombre, Apellido y Mail)\
                    \n8. -\
                    \n9. Guardar datos en data.csv (modo texto)\
                    \n10. Guardar datos en data.bin (modo binario)\
                    \n11. Salir\n\
                    \nIngrese opcion: ";

    char menuPrinsipalMensajeError[] = "\nSe debe elegir una opcion del 1 al 10";

    do
    {
        menuOpcionElegida = 0;
        getValidInt(menuPrinsipalMensaje,menuPrinsipalMensajeError, &menuOpcionElegida , 0 , 11 , 2 );

        switch(menuOpcionElegida)
        {
        case 1:
            controller_leerArchivoClientes("data.csv",pArrayClientes);
            break;
        case 2:
            controller_listarClientes(pArrayClientes);
            break;
        case 3:
            controller_ordenarClientesNombreApellido(pArrayClientes);
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            controller_guardarClientesArchivo("data2.csv",pArrayClientes);
            break;
        case 10:
            break;
        case 11:
            exit(1);
            break;
        default:
            printf("\nNO ES UNA OPCION VALIDA!!!\n\n");
            pause();
            break;
        }

    }while(menuOpcionElegida != 11);

    return 0;

}

