#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include "Llamadas.h"
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
    int respuesta;
    LinkedList* listaLlamada;
    listaLlamada=ll_newLinkedList();

    do
    {
        utn_getEntero(&menu,3,"\n1.Cargar archivo\n2.Imprimir llamadas\n3.Generar archivo de llamadas\n4.Salir\n","\nNo valida\n",1,4);
        switch(menu)
        {
            case 1:
                    if(controller_loadFromText("DATA_final1.csv",listaLlamada)==0)
                    {
                            printf("Ventas cargadas!\n");
                            ll_map(listaLlamada,Llamadas_Mostrar);
                    }
                    else
                    {
                         printf("Error leyendo compras\n");
                    }
                break;
            case 2:
                    ll_map(listaLlamada,Llamadas_Mostrar);
                break;
            case 3:
                if(!utn_getEntero(&respuesta,2,"\n1.Pcs que no encienden\n2.No funcionan mouse\n3.No funciona teclado\n4.No hay internet\n5.No funciona tel\n6.Salir\n","No es una opcion correcta\n",1,6))
                {
                    switch(respuesta)
                    {
                        case 1:
                            informe_generarInforme1("informes1.csv",listaLlamada);
                            break;
                        case 2:
                            informe_generarInforme2("informes2.csv",listaLlamada);
                            break;
                        case 3:
                            informe_generarInforme3("informes3.csv",listaLlamada);
                            break;
                        case 4:
                            informe_generarInforme4("informes4.csv",listaLlamada);
                            break;
                        case 5:
                            informe_generarInforme5("informes5.csv",listaLlamada);
                            break;
                        case 6:
                            break;
                    }
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





