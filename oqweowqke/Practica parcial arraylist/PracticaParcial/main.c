#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"
#include "destinatario.h"
#include "parser.h"
#include "utn.h"

int main()
{
    ArrayList* listaCompleta;
    ArrayList* listaNegra;
    ArrayList* listaBlanca;

    listaCompleta=al_newArrayList();
    listaNegra=al_newArrayList();
    listaBlanca=al_newArrayList();

    parser_leerArchivoDestinatario("destinatarios",listaCompleta);
    parser_listarDestinatarios(listaCompleta);

    return 0;
}



