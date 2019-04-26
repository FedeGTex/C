//#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pantalla.h"
#include "utn.h"
#define T_LCD 0
#define T_LED 1

static int buscarLugarLibre(Pantalla* arrayPantalla,int limite);
static int proximoId();

int pantalla_init(Pantalla* arrayPantalla,int limite)
{
    int retorno=-1;
    int i;
    if(arrayPantalla!=NULL && limite>0)
    {
        for(i=0;i<limite;i++)
        {
            retorno=0;
            arrayPantalla[i].isEmpty=1;
        }
    }
    return retorno;
}

int pantalla_mostrar(Pantalla* arrayPantalla,int limite)
{
    int retorno=-1;
    int i;
    if(arrayPantalla!=NULL && limite>0)
    {
        for(i=0;i<limite;i++)
        {
            retorno=0;
            if(!arrayPantalla[i].isEmpty)
            {
                printf("\nID: %d Nombre: %s Direccion: %s Precio: %.2f Tipo: %d\n",
                            arrayPantalla[i].idPantalla,
                            arrayPantalla[i].nombre,
                            arrayPantalla[i].direccion,
                            arrayPantalla[i].precio,
                            arrayPantalla[i].tipo);
            }
        }
    }
    return retorno;
}

int pantalla_alta(Pantalla* arrayPantalla,int limite)
{
    int retorno=-1;
    int i;
    char auxNombre[50];
    char auxDireccion[50];
    float auxPrecio;
    int auxTipo;
    if(arrayPantalla!=NULL && limite>0)
    {
        i=buscarLugarLibre(arrayPantalla,limite);
        if(i>=0)
        {
            if(!utn_getLetras(auxNombre,50,2,"\nIngrese un nombre: ","Ingrese un nombre compuesto por letras!"))
            {
                if(!utn_getLetrasYNumeros(auxDireccion,50,"Ingrese una direccion: "))
                {
                    if(!utn_getFloat(&auxPrecio,2,"Ingrese un precio: ","Ingrese un precio valido!",0,999999))
                        {
                            if(!utn_getEntero(&auxTipo,
                                              2,
                                              "Ingrese un tipo 0)LCD o 1)LED\n",
                                              "Ingrese 0 para LCD o 1 para LED\n",0,1))
                            {
                                retorno=0;
                                strncpy(arrayPantalla[i].nombre,auxNombre,50);
                                strncpy(arrayPantalla[i].direccion,auxDireccion,50);
                                arrayPantalla[i].precio=auxPrecio;
                                arrayPantalla[i].tipo=auxTipo;
                                arrayPantalla[i].isEmpty=0;
                                arrayPantalla[i].idPantalla=proximoId();

                                printf("\nLa id de la nueva pantalla es: %d\n",arrayPantalla[i].idPantalla);
                            }
                        }
                }
            }
        }
        retorno=-2;
    }
    return retorno;
}

int pantalla_buscarPorId(Pantalla* arrayPantalla,int limite,int id)
{
    int retorno=-1;
    int i;
    if(arrayPantalla!=NULL && limite>0)
    {
        retorno=-2;
        for(i=0;i<limite;i++)
        {
            if(!arrayPantalla[i].isEmpty && arrayPantalla[i].idPantalla==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int pantalla_modificar(Pantalla* arrayPantalla,int limite,int id)
{
    int retorno=-1;
    int indiceAModificar;
    char auxNombre[50];
    char auxDireccion[50];
    float auxPrecio;
    int auxTipo;

    if(arrayPantalla!=NULL && limite>0 && id>=0)
    {
        indiceAModificar=pantalla_buscarPorId(arrayPantalla,limite,id);
        if(indiceAModificar>=0)
        {
            if(!utn_getLetras(auxNombre,50,2,"Ingrese un nombre: ","Ingrese un nombre compuesto por letras!"))
            {
                if(!utn_getLetrasYNumeros(auxDireccion,50,"Ingrese una direccion: "))
                {
                    if(!utn_getFloat(&auxPrecio,2,"Ingrese un precio: ","Ingrese un precio valido!",0,999999))
                        {
                            if(!utn_getEntero(&auxTipo,
                                              2,
                                              "Ingrese un tipo 0)LCD o 1)LED",
                                              "Ingrese 0 para LCD o 1 para LED",0,1))
                            {
                                retorno=0;
                                strncpy(arrayPantalla[indiceAModificar].nombre,auxNombre,sizeof(arrayPantalla[indiceAModificar].nombre));
                                strncpy(arrayPantalla[indiceAModificar].direccion,auxDireccion,sizeof(arrayPantalla[indiceAModificar].direccion));
                                arrayPantalla[indiceAModificar].precio=auxPrecio;
                                arrayPantalla[indiceAModificar].tipo=auxTipo;

                                printf("Modificacion exitosa!");
                            }
                            retorno=-2;
                            printf("No se ha podido modificar!");
                        }
                }
            }
          }
    }
     return retorno;
}

int pantalla_baja(Pantalla* arrayPantalla,int limite,int id)
{
    int indiceAEliminar;
    int retorno=-1;
    if(arrayPantalla!=NULL && limite>0 && id>=0)
    {
        indiceAEliminar = pantalla_buscarPorId(arrayPantalla,limite,id);
        if(indiceAEliminar>=0)
        {
            arrayPantalla[indiceAEliminar].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}

/*int pantalla_ordenar(Pantalla* arrayPantalla,int limite,int order)
{
    int retorno=-1;
    int i;
    int flagSwap;
    Pantalla auxEstructura;
    if(arrayPantalla!=NULL && limite>0)
    {
            flagSwap=0;
            for(i=0;i<limite-1;i++)
            {
                if(!arrayPantalla[i].isEmpty && !arrayPantalla[i+1].isEmpty)
                {
                    if((strcmp(arrayPantalla[i].nombre,arrayPantalla[i+1].nombre) > 0 && orden) || (strcmp(arrayPantalla[i].nombre,arrayPantalla[i+1].nombre) < 0 && !orden))
                    {
                        auxEstructura = arrayPantalla[i];
                        arrayPantalla[i] = arrayPantalla[i+1];
                        arrayPantalla[i+1] = auxEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;

    }
}
*/

int pantalla_altaForzada(Pantalla* arrayPantalla,int limite,char* nombre,char* direccion,float precio,int tipo)
{
    int retorno = -1;
    int i;

    if(limite > 0 && arrayPantalla != NULL)
    {
        i = buscarLugarLibre(arrayPantalla,limite);
        if(i >= 0)
        {
            retorno = 0;
            strncpy(arrayPantalla[i].nombre,nombre,50);
            strncpy(arrayPantalla[i].direccion,direccion,50);
            arrayPantalla[i].precio=precio;
            arrayPantalla[i].tipo=tipo;
            //------------------------------
            //------------------------------
            arrayPantalla[i].idPantalla = proximoId();
            arrayPantalla[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}



int pantalla_mostrarUnIndice(Pantalla* arrayPantalla,int limite,int indice)
{
    int retorno=-1;
    if(arrayPantalla != NULL && limite > 0)
    {
        if(arrayPantalla[indice].isEmpty==0)
        {
            printf("\n-El ID de la pantalla es: %d", arrayPantalla[indice].idPantalla);
            printf("\n-El nombre de la pantalla es: %s",arrayPantalla[indice].nombre);
            printf("\n-El tipo de la pantalla es(LCD:1, LED:0): %d ",arrayPantalla[indice].tipo);
            printf("\n-El precio de la pantalla es: %.2f por dia",arrayPantalla[indice].precio);
            printf("\n-La direccion de la pantalla es: %s\n",arrayPantalla[indice].direccion);
            retorno=0;
        }

    }

    return retorno;
}

static int proximoId()
{
    static int proximoId;
    proximoId++;
    return proximoId;
}

static int buscarLugarLibre(Pantalla* arrayPantalla,int limite)
{
    int retorno=-1;
    int i;
    if(arrayPantalla!=NULL && limite>0)
    {
        for(i=0;i<limite;i++)
        {
            if(arrayPantalla[i].isEmpty == 1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
