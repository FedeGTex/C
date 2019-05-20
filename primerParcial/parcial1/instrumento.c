#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "instrumento.h"

//Funciones Privadas
static int proximoId();
static int buscarLugarLibre(Instrumento* array,int limite);
////////////////////


/** \brief Inicia cada instrumento como vacio
 * \param array Instrumento* array de instrumentos
 * \param limite int cantidad de elementos del array de instrumento
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int instrumento_init(Instrumento* array,int limite)
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


/** \brief Muestra todos las instrumentos que no esten vacios
 * \param array Instrumento* array de instrumentos
 * \param limite int cantidad de elementos del array de instrumentos
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int instrumento_mostrar(Instrumento* array,int limite)
{
    int retorno = -1;
    int i;
    int auxTipo;

    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
            {
                auxTipo=array[i].tipo;
                //printf("Id: %d - Nombre: %s - tipo: %d\n",array[i].idInstrumento,array[i].nombre,auxTipo);
                switch(auxTipo)
                {
                    //printf("Id: %d - Nombre: %s - tipo: %d\n",array[i].idInstrumento,array[i].nombre,auxTipo);
                    case 1:
                        printf("\nCuerda\n");
                        break;
                    case 2:
                        printf("\nViento-madera\n");
                        break;
                    case 3:
                        printf("\nViento-metal\n");
                        break;
                    case 4:
                        printf("\nPercusion\n");
                        break;
                }
                printf("Id: %d - Nombre: %s - tipo: %d\n",array[i].idInstrumento,array[i].nombre,auxTipo);
            }
        }
    }
    return retorno;
}


/** \brief Alta de un instrumento
 * \param array Instrumento* array de instrumentos
 * \param limite int cantidad de elementos del array de instrumentos
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int instrumento_alta(Instrumento* array,int limite)
{
    int retorno = -1;
    int i;
    char nombre[31];
    int tipo;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!utn_getLetras(nombre,31,2,"\nNombre? ","\nEso no es un nombre"))
            {
                if(!utn_getEntero(&tipo,2,"\nIngrese tipo: 1)Cuerda 2)Viento-madera 3)Viento-metal 4)Percusion ","\nDato invalido!,verifique\n",1,4))
                {
                    retorno = 0;
                    strcpy(array[i].nombre,nombre);
                    array[i].tipo=tipo;
                    //------------------------------
                    //------------------------------
                    array[i].idInstrumento = proximoId();
                    array[i].isEmpty = 0;

                    printf("\nEl ID del instrumento es: %d\n",array[i].idInstrumento);
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


/** \brief Baja de una instrumento
 * \param array Instrumento* array de instrumentos
 * \param limite int cantidad de elementos del array de instrumentos
 * \param id id del instrumento a dar de baja
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int instrumento_baja(Instrumento* array,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    if(array!=NULL && limite>0)
    {
        indiceAEliminar = instrumento_buscarPorId(array,limite,id);
        if(indiceAEliminar>=0)
        {
            array[indiceAEliminar].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Modificacion de un instrumento
 * \param array Instrumentos* array de instrumentos
 * \param limite int cantidad de elementos del array de instrumentos
 * \param id id del instrumento a modificar
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 *
int instrumento_modificacion(Instrumento* array,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char nombre[50];
    char apellido[50];
    char cuit[50];
    indiceAModificar = instrumento_buscarPorId(array,limite,id);
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


** \brief Ordena por nombre las instrumentos que no esten vacios
 * \param array Instrumentos* array de instrumentos
 * \param limite int cantidad de elementos del array de instrumentos
 * \param orden orden para array(ascendente/descendente)
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 *
int instrumento_ordenar(Instrumento* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Instrumento auxiliarEstructura;

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
}*/


/** \brief Busca un lugar libre en el array instrumentos
 * \param array Instrumento* array de instrumentos
 * \param limite int cantidad de elementos del array de instrumento
 * \return Si devuelve un numero negativo no hay lugar libre sino devuelve el indice libre del array
 *
 */
static int buscarLugarLibre(Instrumento* array,int limite)
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
 * \param array Instrumento* array de instrumento
 * \param limite int cantidad de elementos del array de instrumento
 * \param id id del instrumento a buscar
 * \return Si devuelve un numero negativo no existe ese id sino devuelve el indice en donde esta ubicado ese id en el array
 *
 */
int instrumento_buscarPorId(Instrumento* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idInstrumento==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


/** \brief Da de alta instrumentos sin necesidad del ingreso del usuario
 * \param array Instrumento* array de instrumento
 * \param limite int cantidad de elementos del array de instrumentos
 * \param char* nombre nombre de la instrumento
 * \param char* apellido apellido del instrumento
 * \param char* cuit cuit del instrumento
 * \return Si devuelve un numero negativo no existe ese id sino devuelve el indice en donde esta ubicado ese id en el array
 *
 */
int instrumento_altaForzada(Instrumento* array,int limite,char* nombre,int tipo)
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
            array[i].tipo=tipo;
            //------------------------------
            //------------------------------
            array[i].idInstrumento = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}


int instrumento_imprimirTipoPorId(Instrumento* pInstrumento,int limite,int id)
{
    int retorno=1;
    int i;

    if(pInstrumento!=NULL && limite>0)
    {
        for(i=0;i<limite;i++)
        {
            i=instrumento_buscarPorId(pInstrumento,limite,id);
            if(pInstrumento[i].idInstrumento==id)
            {
                retorno=0;
                printf("\nEl tipo es: %d",pInstrumento[i].tipo);
                break;
            }
        }
    }
    return retorno;
}
