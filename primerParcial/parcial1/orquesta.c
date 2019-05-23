#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "orquesta.h"

//Funciones Privadas
static int proximoId();
static int buscarLugarLibre(Orquesta* array,int limite);
////////////////////


/** \brief Inicia cada orquesta como vacio
 * \param array Orquesta* array de orquestas
 * \param limite int cantidad de elementos del array de orquesta
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int orquesta_init(Orquesta* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}


/** \brief Muestra todos las orquestas que no esten vacios
 * \param array Orquesta* array de orquestas
 * \param limite int cantidad de elementos del array de orquestas
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int orquesta_mostrar(Orquesta* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("Id: %d - Nombre: %s - Lugar: %s - tipo: %d\n",array[i].idOrquesta,array[i].nombre,array[i].lugar,array[i].tipo);
        }
    }
    return retorno;
}


/** \brief Alta de un orquesta
 * \param array Orquesta* array de orquestas
 * \param limite int cantidad de elementos del array de orquestas
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int orquesta_alta(Orquesta* array,int limite)
{
    int retorno = -1;
    int i;
    char nombre[31];
    char lugar[31];
    int tipo;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!utn_getLetras(nombre,31,2,"\nNombre? ","\nEso no es un nombre"))
            {
                if(!utn_getLetras(lugar,31,2,"\nLugar? ","\nEso no es un lugar"))
                {
                    if(!utn_getEntero(&tipo,2,"\nIngrese tipo: 1)Sinfonica 2)Filarmonica 3)Camara ","\nDato invalido!,verifique\n",1,3))
                    {
                        retorno = 0;
                        strcpy(array[i].nombre,nombre);
                        strcpy(array[i].lugar,lugar);
                        array[i].tipo=tipo;
                        //------------------------------
                        //------------------------------
                        array[i].idOrquesta = proximoId();
                        array[i].isEmpty = 0;

                        printf("\nEl ID de la nueva orquesta es: %d\n",array[i].idOrquesta);
                    }
                    else
                    {
                        retorno = -3;
                    }
                }
            }
        }
        else
        {
            retorno = -2;
        }
    }
    return retorno;
}


/** \brief Baja de una orquesta
 * \param array Orquesta* array de orquestas
 * \param limite int cantidad de elementos del array de orquestas
 * \param id id del orquesta a dar de baja
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int orquesta_baja(Orquesta* array,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    if(array!=NULL && limite>0)
    {
        indiceAEliminar = orquesta_buscarPorId(array,limite,id);
        if(indiceAEliminar>=0)
        {
            array[indiceAEliminar].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Modificacion de un orquesta
 * \param array Orquestas* array de orquestas
 * \param limite int cantidad de elementos del array de orquestas
 * \param id id del orquesta a modificar
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 *
int orquesta_modificacion(Orquesta* array,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char nombre[50];
    char apellido[50];
    char cuit[50];
    indiceAModificar = orquesta_buscarPorId(array,limite,id);
    if(indiceAModificar>=0)
    {
        if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
        {
            if(!getValidString("\nApellido? ","\nEso no es un apellido","El maximo es 40",apellido,40,2))
            {
                if(!getValidStringNumerico("\nCuit? ","\nEso no es un cuit","El maximo es 15",cuit,15,2))
                {
                    retorno = 0;
                    strcpy(array[indiceAModificar].nombre,nombre);
                    strcpy(array[indiceAModificar].apellido,apellido);
                    strcpy(array[indiceAModificar].cuit,cuit);
                    //------------------------------
                    //------------------------------
                }
                else
                {
                    retorno = -2;
                }
            }
        }
    }
    return retorno;
}
*/

/** \brief Ordena por nombre las orquestas que no esten vacios
 * \param array Orquestas* array de orquestas
 * \param limite int cantidad de elementos del array de orquestas
 * \param orden orden para array(ascendente/descendente)
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int orquesta_ordenar(Orquesta* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Orquesta auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden))
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}


/** \brief Busca un lugar libre en el array orquestas
 * \param array Orquesta* array de orquestas
 * \param limite int cantidad de elementos del array de orquesta
 * \return Si devuelve un numero negativo no hay lugar libre sino devuelve el indice libre del array
 *
 */
static int buscarLugarLibre(Orquesta* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


/** \brief Genera un proximo id
 * \return Devuelve el numero para el proximo id
 *
 */
static int proximoId()
{
    static int proximoId = 0;
    proximoId++;
    return proximoId;
}


/** \brief Busca por id un elemento en el array
 * \param array Orquesta* array de orquesta
 * \param limite int cantidad de elementos del array de orquesta
 * \param id id del orquesta a buscar
 * \return Si devuelve un numero negativo no existe ese id sino devuelve el indice en donde esta ubicado ese id en el array
 *
 */
int orquesta_buscarPorId(Orquesta* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idOrquesta==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


/** \brief Da de alta orquestas sin necesidad del ingreso del usuario
 * \param array Orquesta* array de orquesta
 * \param limite int cantidad de elementos del array de orquestas
 * \param char* nombre nombre de la orquesta
 * \param char* apellido apellido del orquesta
 * \param char* cuit cuit del orquesta
 * \return Si devuelve un numero negativo no existe ese id sino devuelve el indice en donde esta ubicado ese id en el array
 *
 */
int orquesta_altaForzada(Orquesta* array,int limite,char* nombre,char* lugar,int tipo)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].nombre,nombre);
            strcpy(array[i].lugar,lugar);
            array[i].tipo=tipo;
            //------------------------------
            //------------------------------
            array[i].idOrquesta = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}



int orquesta_imprimirPorId(Orquesta* pOrquesta,int limite,int id)
{
    int retorno=-1;
    int indiceAImprimir;
    Orquesta orquesta;
    if(pOrquesta!=NULL && limite>0)
    {
        printf("\nORQUESTA\n");
        indiceAImprimir=orquesta_buscarPorId(pOrquesta,limite,id);
        if(indiceAImprimir>=0)
        {
            orquesta = pOrquesta[indiceAImprimir];
            printf("\nID: %d - nombre: %s - lugar: %s - tipo: %d\n",orquesta.idOrquesta,orquesta.nombre,orquesta.lugar,orquesta.tipo);
            retorno=0;
        }
    }
    return retorno;
}
