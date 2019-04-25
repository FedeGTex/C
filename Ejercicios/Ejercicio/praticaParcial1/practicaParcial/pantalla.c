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
                printf("ID: %d \nNombre: %s \nDireccion: %s \nPrecio: %.2f \nTipo: %d",
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
                                strncpy(arrayPantalla[indiceAModificar].nombre,auxNombre,50);
                                strncpy(arrayPantalla[indiceAModificar].direccion,auxDireccion,50);
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
