#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include "Envio.h"
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "utn.h"
#include "parser.h"
#include "informes.h"
#include "controller.h"



int main()
{


    int menu;
    LinkedList* listaEnvio;
    listaEnvio=ll_newLinkedList();

    do
    {
        utn_getEntero(&menu,3,"\n1.Cargar archivo\n2.Imprimir envios\n3.Generar archivo de llamadas\n4.Salir\n","\nNo valida\n",1,4);
        switch(menu)
        {
            case 1:
                    if(controller_loadFromText("data.csv",listaEnvio)==0)
                    {
                            printf("Ventas cargadas!\n");
                            //ll_map(listaLlamada,Llamadas_Mostrar);
                    }
                    else
                    {
                         printf("Error leyendo compras\n");
                    }
                break;
            case 2:
                   ll_map(listaEnvio,Envios_Mostrar);
                break;
            case 3:
                if(informe_generarInforme1("informe.csv",listaEnvio)==0)
                {
                    printf("Se ha generado el archivo informe!\n");
                }
                else
                {
                    printf("Error al generar el archivo!\n");
                }
                break;
            case 4:
                break;
        }

    }while(menu != 4);

    return 0;
    /*
    if(controller_loadFromText("data.csv",listaVentas)==0)
    {
        printf("Ventas cargadas!\n");
        ll_map(listaVentas,Ventas_Mostrar);
        if(informe_generarInforme("informes.csv",listaVentas)==0)
        {
            printf("Archivo de informes listo!\n");
        }
    }
    else
        printf("Error leyendo compras\n");
 return 0;*/
}





