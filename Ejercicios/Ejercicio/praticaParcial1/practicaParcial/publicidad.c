#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pantalla.h"
#include "publicidad.h"
#include "utn.h"
#define DIAS_MAX 31

static int proximoId();
static int buscarLugarLibre(Publicidad* arrayPublicidad,int limite);


int publicidad_init(Publicidad* arrayPublicidad,int limite)
{
    int retorno=-1;
    int i;
    if(arrayPublicidad!=NULL && limite>0)
    {
        for(i=0;i<limite;i++)
        {
            retorno=0;
            arrayPublicidad[i].isEmpty=1;
        }
    }
    return retorno;
}


int publicidad_mostrar(Publicidad* arrayPublicidad,int limite)
{
    int retorno=-1;
    int i;
    if(arrayPublicidad!=NULL && limite>0)
    {
        for(i=0;i<limite;i++)
        {
            retorno=0;
            if(!arrayPublicidad[i].isEmpty)
            {
                printf("Cuit: %s \nDias: %d \nArchivo: %s \nId Publicidad: %d",
                                                            arrayPublicidad[i].cuit,
                                                            arrayPublicidad[i].dias,
                                                            arrayPublicidad[i].archivo,
                                                            arrayPublicidad[i].idPublicidad);
            }
        }
    }
    return retorno;
}

int publicidad_alta(Publicidad* arrayPublicidad,int limite,int idPantalla)
{
    int retorno=-1;
    char auxArchivo[128];
    char auxCuitCliente[128];
    int auxDias;
    int i;

    if(arrayPublicidad != NULL && limite >0)
    {
       i=buscarLugarLibre(arrayPublicidad,limite);
       if(i>=0)
       {

        if(!utn_getCuit(auxCuitCliente,128,2,"\nIngrese su cuit\n","Ingrese cuit valido!"))
        {
            if(!utn_getEntero(&auxDias,2,"Ingrese la cantidad de Dias que desea: ","\nEsa no es una cantidad valida\n",-1,DIAS_MAX))
            {
                if(!utn_getLetrasYNumeros(auxArchivo,128,"Ingrese nombre del video: "))
                {
                    strncpy(arrayPublicidad[i].archivo,auxArchivo,sizeof(arrayPublicidad[i].archivo));
                    strncpy(arrayPublicidad[i].cuit,auxCuitCliente,sizeof(arrayPublicidad[i].cuit));
                    arrayPublicidad[i].dias=auxDias;
                    arrayPublicidad[i].idPublicidad=proximoId();
                    arrayPublicidad[i].idPantalla=idPantalla;
                    arrayPublicidad[i].isEmpty=0;
                    retorno =0;

                }

            }
        }
      }
      retorno=-2;
    }
    return retorno;
}



int publicidad_buscarPorId(Publicidad* arrayPublicidad,int limite,int id)
{
    int retorno=-1;
    int i;
    if(arrayPublicidad!=NULL && limite>0)
    {
        retorno=-2;
        for(i=0;i<limite;i++)
        {
            if(!arrayPublicidad[i].isEmpty && arrayPublicidad[i].idPublicidad==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int publicidad_buscarPublicidadPorIdyCuit(Publicidad* arrayPublicidad,int limite,int idPantalla,char* cuit)
{
    int retorno=-1;
    int i;

    if(arrayPublicidad!=NULL && limite>0 && idPantalla>=0 && cuit!=NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(!arrayPublicidad[i].isEmpty)
            {
                if(arrayPublicidad[i].idPantalla==idPantalla && strcmp(arrayPublicidad[i].cuit,cuit)==0)
                {
                    retorno=i;
                    break;
                }
            }
        }
    }

    return retorno;
}

int publicidad_imprimirPublicidadCuit(Publicidad* arrayPublicidad,int limite,Pantalla* arrayPantalla,int limite2,char* cuitVacio)
{
    char cuit[20];
    int retorno=-1;
    int i=0;
    int posicion;
    //printf("Ingrese su CUIT: ");
    if(!utn_getCuit(cuit,limite,2,"Ingrese su cuit","Ingrese un cuit valido"))
    {
        strcpy(cuitVacio,cuit);
        if(arrayPublicidad != NULL && limite > 0)
        {
            for(i=0;i<limite;i++)
            {
                if(arrayPublicidad[i].isEmpty==0 && strcmp(arrayPublicidad[i].cuit,cuit)==0)
                {
                    posicion=pantalla_buscarPorId(arrayPantalla,limite2,arrayPublicidad[i].idPantalla);
                    pantalla_mostrarUnIndice(arrayPantalla,limite2,posicion);
                    retorno=0;
                    printf("-Dias: %d\n",arrayPublicidad[i].dias);
                }

            }

        }
    }

    return retorno;
}

int publicidad_borrarPublicidad(Publicidad* arrayPublicidad,int limite,int indicePublicidad)
{
        int retorno=-1;
       if(arrayPublicidad!=NULL && limite > 0)
       {
            if(!arrayPublicidad[indicePublicidad].isEmpty)
            {
                if(arrayPublicidad[indicePublicidad].idPublicidad==indicePublicidad)
                {
                    arrayPublicidad[indicePublicidad].isEmpty=1;
                    retorno=0;
                }
            }

       }

    return retorno;
}

int publicidad_modificarIndice(Publicidad* arrayPublicidad,int indicePublicidad,int limite)
{
    int retorno=-1;
    int auxDias;

    if(indicePublicidad >=0)
    {
        if(arrayPublicidad!= NULL && limite >0)
        {
                if(!utn_getEntero(&auxDias,2,"Ingrese la nueva cantidad de Dias que desea: ","\nEsa no es una cantidad valida\n",0,DIAS_MAX))
                {
                    arrayPublicidad[indicePublicidad].dias=auxDias;
                }
        }
    }else
    {
        printf("El Indice es incorrecto\n");
    }
    return retorno;
}


int publicidad_calcularFacturaciones(Publicidad* arrayPublicidad,int limite,Pantalla* arrayPantalla,int limite2)
{
    char cuit[20];
    int retorno=-1;
    int i=0;
    int posicion;
    float total;
    //printf("Ingrese su CUIT: ");
    if(utn_getCuit(cuit,20,2,"\nIngrese su cuit: ","\nIngrese un cuit valido")==0)
    {
        if(arrayPublicidad != NULL && limite > 0)
        {
            for(i=0;i<limite;i++)
            {
                if(arrayPublicidad[i].isEmpty==0 && strcmp(arrayPublicidad[i].cuit,cuit)==0)
                {
                    posicion=pantalla_buscarPorId(arrayPantalla,limite2,arrayPublicidad[i].idPantalla);
                    total=arrayPublicidad[i].dias * arrayPantalla[posicion].precio;
                    pantalla_mostrarUnIndice(arrayPantalla,limite2,posicion);
                    printf("-El precio de la facturacion es: %.2f\n",total);
                    retorno=0;
                }

            }

        }
    }

    return retorno;
}

int publicidad_mostrarIndices(Publicidad* arrayPublicidad,int limite, Pantalla* arrayPantalla, int limite2)
{
    int retorno=-1;
    int posicion;
    int i=0;
    if(arrayPantalla != NULL && limite2 > 0 && arrayPublicidad!=NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
                if(arrayPublicidad[i].isEmpty==0)
                {
                    posicion=pantalla_buscarPorId(arrayPantalla,limite2,arrayPublicidad[i].idPantalla);
                    printf("\n-El nombre de la pantalla es: %s",arrayPantalla[posicion].nombre);
                    printf("\n-El nombre del video es: %s", arrayPublicidad[i].archivo);
                    printf("\n-La cantidad de dias es: %d", arrayPublicidad[i].dias);
                    printf("\n-El cuit del cliente es: %s\n", arrayPublicidad[i].cuit);
                    retorno=0;
                }
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

static int buscarLugarLibre(Publicidad* arrayPublicidad,int limite)
{
    int retorno=-1;
    int i;
    if(arrayPublicidad!=NULL && limite>0)
    {
        for(i=0;i<limite;i++)
        {
            if(arrayPublicidad[i].isEmpty == 1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
