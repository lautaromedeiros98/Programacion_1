#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "cliente.h"
#include "utn.h"
#include "parser.h"

int main()
{
    ArrayList* clientes=al_newArrayList();
    parser_leerDelArchivo("clientes.txt",clientes);
    int menu;
    do
    {
        getValidInt("1.alta cliente\n2.modificacion cliente\n3.baja cliente\n4.listar clientes\n5.realizar una venta\n6.anular una venta\n7.informar ventas\n8.informar ventas por producto\n","error\n",&menu,0,20,10);
        switch(menu)
        {
        case 1:
            cliente_alta(clientes);
            parser_guardarEnArchivo("clientes.txt",clientes);
            break;
        case 4:
            cliente_listarClientes(clientes);
            break;
        }
    }while(menu!=11);

    return 0;
}
