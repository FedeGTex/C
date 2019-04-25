#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pantalla.h"
#include "utn.h"
#define PANTALLA_LEN 10

int main()
{
    Pantalla arrayPantalla[PANTALLA_LEN];

    int menu,auxiliarId,respuesta;

    pantalla_init(arrayPantalla,PANTALLA_LEN);

    do
    {
        utn_getEntero(&menu,2,"1)Alta pantalla \n2)Modificar pantalla: \n3Baja pantalla: \n4)Contratar publicidad: \n5)Modificar publicacion: \n6Cancelar contratacion: \n7)Consulta facturacion: \n8)Listar contrataciones: \n9)Listar pantallas: \n10)Informes: \n11)Salir\n","Ingrese opcion valida!",1,11);
       switch(menu)
       {
       case 1:
           pantalla_alta(arrayPantalla,PANTALLA_LEN);
        break;
       case 2:
           pantalla_mostrar(arrayPantalla,PANTALLA_LEN);
           if(!utn_getEntero(&auxiliarId,2,"\nIngrese la id de la pantalla a modificar\n","Ingrese una id correcta!",0,100))
           {
               pantalla_modificar(arrayPantalla,PANTALLA_LEN,auxiliarId);
               pantalla_mostrar(arrayPantalla,PANTALLA_LEN);
           }
        break;
       case 3:
           if(!utn_getEntero(&auxiliarId,2,"\nIngrese la id de la pantalla a eliminar\n","Ingrese una id correcta!",0,100))
           {
               pantalla_mostrar(arrayPantalla,PANTALLA_LEN);
               if(!utn_getEntero(&respuesta,2,"Desea eliminar esta pantalla? 1-Si \n2-No","Elija una opcion valida",1,2))
               {
                    if(respuesta==1)
                    {
                       pantalla_baja(arrayPantalla,PANTALLA_LEN,auxiliarId);
                       pantalla_mostrar(arrayPantalla,PANTALLA_LEN);
                    }
               }
           }
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
        break;
       case 10:
        break;
       case 11:
        break;
       }

    }while(menu != 11);
    return 0;
}
