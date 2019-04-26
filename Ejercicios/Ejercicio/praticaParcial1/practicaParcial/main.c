#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pantalla.h"
#include "publicidad.h"
#include "utn.h"
#define PANTALLA_LEN 10
#define PUBLICIDAD_LEN 10
#define T_LCD 0
#define T_LED 1

int main()
{
    Pantalla arrayPantalla[PANTALLA_LEN];
    Publicidad arrayPublicidad[PUBLICIDAD_LEN];

    int menu,auxiliarId,respuesta;
    int indice;
    int indicePublicidad;
    char cuitVacio[11];

    pantalla_init(arrayPantalla,PANTALLA_LEN);
    publicidad_init(arrayPublicidad,PUBLICIDAD_LEN);

    pantalla_altaForzada(arrayPantalla,10,"SAMSUNG","Rivadavia 600",15000,T_LCD);
    pantalla_altaForzada(arrayPantalla,10,"LG","Sarmiento 600",17000,T_LED);
    pantalla_altaForzada(arrayPantalla,10,"HP","Belgrano 600",12000,T_LCD);

    do
    {
        utn_getEntero(&menu,2,"\n1)Alta pantalla \n2)Modificar pantalla: \n3Baja pantalla: \n4)Contratar publicidad: \n5)Modificar publicacion: \n6Cancelar contratacion: \n7)Consulta facturacion: \n8)Listar contrataciones: \n9)Listar pantallas: \n10)Informes: \n11)Salir\n","Ingrese opcion valida!",1,11);
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
               if(!utn_getEntero(&respuesta,2,"Desea eliminar esta pantalla? 1-Si o 2-No\n","\nElija una opcion valida",1,2))
               {
                    if(respuesta==1)
                    {
                       pantalla_baja(arrayPantalla,PANTALLA_LEN,auxiliarId);
                       pantalla_mostrar(arrayPantalla,PANTALLA_LEN);
                       printf("Se ha eliminado una pantalla!");
                    }
               }
           }
        break;
       case 4:
            pantalla_mostrar(arrayPantalla,PANTALLA_LEN);
            if(!utn_getEntero(&auxiliarId,2,"\nIngrese el id de la pantalla: ","\nIngrese un id valido",0,10))
            {
                indice=pantalla_buscarPorId(arrayPantalla,PANTALLA_LEN,auxiliarId);
                publicidad_alta(arrayPublicidad,PUBLICIDAD_LEN,indice);
            }
        break;
       case 5:
            if(publicidad_imprimirPublicidadCuit(arrayPublicidad,PUBLICIDAD_LEN,arrayPantalla,PANTALLA_LEN,cuitVacio)==0)
            {
                if(!utn_getEntero(&auxiliarId,2,"\nIngrese una id: ","Ingrese una id valida",0,10))
                {
                    if(!pantalla_buscarPorId(arrayPantalla,PANTALLA_LEN,auxiliarId))
                    {
                        indicePublicidad=publicidad_buscarPublicidadPorIdyCuit(arrayPublicidad,PUBLICIDAD_LEN,auxiliarId,cuitVacio);
                        publicidad_modificarIndice(arrayPublicidad,indicePublicidad,PUBLICIDAD_LEN);
                    }
                }
                else
                {
                    printf("Ese ID no existe.");
                }
            }else
             {
                printf("El CUIT no existe o no tiene contrataciones");
             }
        break;
       case 6:
            if(publicidad_imprimirPublicidadCuit(arrayPublicidad,PUBLICIDAD_LEN,arrayPantalla,PANTALLA_LEN,cuitVacio)==0)
                {
                    if(utn_getEntero(&auxiliarId,10,"\nIngrese el ID de la pantalla: ","Ese no es un ID valido",-1,PANTALLA_LEN)==0)
                    {
                        if(!pantalla_buscarPorId(arrayPantalla,PANTALLA_LEN,auxiliarId))
                        {
                                indicePublicidad=publicidad_buscarPublicidadPorIdyCuit(arrayPublicidad,PUBLICIDAD_LEN,auxiliarId,cuitVacio);
                                publicidad_borrarPublicidad(arrayPublicidad,PUBLICIDAD_LEN,indicePublicidad);
                        }
                    }else
                    {
                        printf("Ese ID no existe.");
                    }
                }else
                {
                    printf("El CUIT no existe o no tiene contrataciones");
                }
        break;
       case 7:
            publicidad_calcularFacturaciones(arrayPublicidad,PUBLICIDAD_LEN,arrayPantalla,PANTALLA_LEN);
        break;
       case 8:
            publicidad_mostrarIndices(arrayPublicidad,PUBLICIDAD_LEN,arrayPantalla,PANTALLA_LEN);
        break;
       case 9:
            pantalla_mostrar(arrayPantalla,PANTALLA_LEN);
        break;
       case 10:
        break;
       case 11:
        break;
       }

    }while(menu != 11);
    return 0;
}
