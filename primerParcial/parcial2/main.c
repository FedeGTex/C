#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include "Ventas.h"
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "utn.h"
#include "parser.h"
#include "informes.h"
#include "controller.h"



int main()
{
    LinkedList* listaVentas;
    listaVentas=ll_newLinkedList();
    if(controller_loadFromText("data.csv",listaVentas)==0)
    {
        printf("Ventas cargadas!\n");
        if(informe_generarInforme("informes.csv",listaVentas)==0)
        {
            printf("Archivo de informes listo!\n");
        }
    }
    else
        printf("Error leyendo compras\n");


    return 0;
}

