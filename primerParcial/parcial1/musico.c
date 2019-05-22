#include <stdio.h>
//#include <stdio_ext.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "musico.h"
#include "orquesta.h"
#include "instrumento.h"

//Funciones Privadas
static int proximoId();
static int buscarLugarLibre(Musico* arrayMusico,int limite);
////////////////////


/** \brief Inicia cada musico como vacio
 * \param arrayMusico Musico* arrayMusico de musicos
 * \param limite int cantidad de elementos del arrayMusico de musico
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int musico_init(Musico* arrayMusico,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayMusico != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            arrayMusico[i].isEmpty=1;
        }
    }
    return retorno;
}


/** \brief Muestra todos las musicos que no esten vacios
 * \param arrayMusico Musico* arrayMusico de musicos
 * \param limite int cantidad de elementos del arrayMusico de musicos
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int musico_mostrar(Musico* arrayMusico,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayMusico != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!arrayMusico[i].isEmpty)
                printf("Id: %d - Nombre: %s - Apellido: %s - idInstrumento: %d\n",arrayMusico[i].idMusico,arrayMusico[i].nombre,arrayMusico[i].apellido,arrayMusico[i].idInstrumento);
        }
    }
    return retorno;
}


/** \brief Alta de un musico
 * \param arrayMusico Musico* arrayMusico de musicos
 * \param limite int cantidad de elementos del arrayMusico de musicos
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int musico_alta(Musico* arrayMusico,int limite,Orquesta* arrayOrquesta,int limiteOrquesta,Instrumento* arrayInstrumento,int limiteInstrumento)
{
    int retorno = -1;
    int i;
    char nombre[31];
    char apellido[31];
    int edad;
    int idOrquesta;
    int idInstrumento;
    if(limite > 0 && arrayMusico != NULL)
    {
        i = buscarLugarLibre(arrayMusico,limite);
        if(i >= 0)
        {
            if(!utn_getLetras(nombre,31,2,"\nNombre? ","\nEso no es un nombre"))
            {
                if(!utn_getLetras(apellido,31,2,"\nApellido? ","\nEso no es un apellido"))
                {
                    if(!utn_getEntero(&edad,2,"\nEdad","\nIngrese una edad valida!\n",1,110))
                    {
                        if(!utn_getEntero(&idOrquesta,2,"\nIngrese la id de la orquesta","\nIngrese una id correcta!\n",1,50))
                        {

                            if(!utn_getEntero(&idInstrumento,2,"\nIngrese la id del instrumento","\nIngrese una id valida!\n",1,20))
                            {
                                if(arrayOrquesta[i].idOrquesta==idOrquesta && arrayInstrumento[i].idInstrumento==idInstrumento)
                                {
                                    retorno = 0;
                                    arrayMusico[i].idOrquesta=idOrquesta;
                                    arrayMusico[i].idInstrumento=idInstrumento;
                                    strcpy(arrayMusico[i].nombre,nombre);
                                    strcpy(arrayMusico[i].apellido,apellido);
                                    arrayMusico[i].edad=edad;
                                    //------------------------------
                                    //------------------------------
                                    arrayMusico[i].idMusico = proximoId();
                                    arrayMusico[i].isEmpty = 0;

                                    printf("\nEl ID de la nueva musico es: %d\n",arrayMusico[i].idMusico);
                                }

                            }
                            else
                            {
                                retorno = -3;
                            }

                        }

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


/** \brief Baja de una musico
 * \param arrayMusico Musico* arrayMusico de musicos
 * \param limite int cantidad de elementos del arrayMusico de musicos
 * \param id id del musico a dar de baja
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int musico_baja(Musico* arrayMusico,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    if(arrayMusico!=NULL && limite>0)
    {
        indiceAEliminar = musico_buscarPorId(arrayMusico,limite,id);
        if(indiceAEliminar>=0)
        {
            arrayMusico[indiceAEliminar].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Modificacion de un musico
 * \param arrayMusico Musicos* arrayMusico de musicos
 * \param limite int cantidad de elementos del arrayMusico de musicos
 * \param id id del musico a modificar
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int musico_modificacion(Musico* arrayMusico,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    int edad;
    int idOrquesta;
    if(arrayMusico!=NULL && limite>0)
    {
        indiceAModificar = musico_buscarPorId(arrayMusico,limite,id);
        if(indiceAModificar>=0)
        {
            if(!utn_getEntero(&edad,2,"\nIngrese la nueva edad: ","\nIngrese una edad valida!\n",1,110))
            {
                if(!utn_getEntero(&idOrquesta,2,"\nIngrese la id de la nueva orquesta: ","\nIngrese una id valida",1,50))
                {
                    retorno = 0;
                    arrayMusico[indiceAModificar].edad=edad;
                    arrayMusico[indiceAModificar].idOrquesta=idOrquesta;
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


/** \brief Ordena por nombre las musicos que no esten vacios
 * \param arrayMusico Musicos* arrayMusico de musicos
 * \param limite int cantidad de elementos del arrayMusico de musicos
 * \param orden orden para arrayMusico(ascendente/descendente)
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int musico_ordenarPorNombre(Musico* arrayMusico,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Musico auxiliarEstructura;

    if(limite > 0 && arrayMusico != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!arrayMusico[i].isEmpty && !arrayMusico[i+1].isEmpty)
                {
                    if((strcmp(arrayMusico[i].nombre,arrayMusico[i+1].nombre) > 0 && orden) || (strcmp(arrayMusico[i].nombre,arrayMusico[i+1].nombre) < 0 && !orden))
                    {
                        auxiliarEstructura = arrayMusico[i];
                        arrayMusico[i] = arrayMusico[i+1];
                        arrayMusico[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}


/** \brief Busca un lugar libre en el arrayMusico musicos
 * \param arrayMusico Musico* arrayMusico de musicos
 * \param limite int cantidad de elementos del arrayMusico de musico
 * \return Si devuelve un numero negativo no hay lugar libre sino devuelve el indice libre del arrayMusico
 *
 */
static int buscarLugarLibre(Musico* arrayMusico,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayMusico != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(arrayMusico[i].isEmpty==1)
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


/** \brief Busca por id un elemento en el arrayMusico
 * \param arrayMusico Musico* arrayMusico de musico
 * \param limite int cantidad de elementos del arrayMusico de musico
 * \param id id del musico a buscar
 * \return Si devuelve un numero negativo no existe ese id sino devuelve el indice en donde esta ubicado ese id en el arrayMusico
 *
 */
int musico_buscarPorId(Musico* arrayMusico,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayMusico != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!arrayMusico[i].isEmpty && arrayMusico[i].idMusico==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


/** \brief Da de alta musicos sin necesidad del ingreso del usuario
 * \param arrayMusico Musico* arrayMusico de musico
 * \param limite int cantidad de elementos del arrayMusico de musicos
 * \param char* nombre nombre de la musico
 * \param char* apellido apellido del musico
 * \param char* cuit cuit del musico
 * \return Si devuelve un numero negativo no existe ese id sino devuelve el indice en donde esta ubicado ese id en el arrayMusico
 *
 */
int musico_altaForzada(Musico* arrayMusico,int limite,char* nombre,char* apellido,int edad,int idOrquesta,int idInstrumento)
{
    int retorno = -1;
    int i;

    if(limite > 0 && arrayMusico != NULL)
    {
        i = buscarLugarLibre(arrayMusico,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(arrayMusico[i].nombre,nombre);
            strcpy(arrayMusico[i].apellido,apellido);
            arrayMusico[i].edad=edad;
            arrayMusico[i].idOrquesta=idOrquesta;
            arrayMusico[i].idInstrumento=idInstrumento;
            //------------------------------
            //------------------------------
            arrayMusico[i].idMusico = proximoId();
            arrayMusico[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief Ordena por idOrqestat los musicos que no esten vacios
 * \param Musicos* array de musicos
 * \param limite int cantidad de elementos del array de musicos
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int musicos_ordenar_por_idOrquesta(Musico* arrayMusico,int limite)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Musico auxiliarEstructura;

    if(limite > 0 && arrayMusico != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!arrayMusico[i].isEmpty && !arrayMusico[i+1].isEmpty)
                {
                    if(arrayMusico[i].idOrquesta > arrayMusico[i+1].idOrquesta)
                    {
                        auxiliarEstructura = arrayMusico[i];
                        arrayMusico[i] = arrayMusico[i+1];
                        arrayMusico[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}


int musico_bajaPorOrquesta(Musico* arrayMusico,int limite,int id)
{
    int retorno=-1;
    int i;
    int flagExiste=0;

    if(arrayMusico!=NULL && limite>0)
    {
        for(i=0;i<limite;i++)
        {
            if(arrayMusico[i].idOrquesta==id)
            {
                arrayMusico[i].isEmpty=1;
                flagExiste=1;
                retorno=0;
            }
        }
        if(flagExiste==0)
        {
            printf("\nNo hay musicos en esta orquesta\n");
        }
    }
    return retorno;
}

int musicos_listarPorOrquesta(Musico* pMusico,int limite,int id)
{
    int retorno=-1;
    int i;
    Musico auxMusico;

    if(pMusico!=NULL && limite>0)
    {
        printf("\nMUSICOS\n");
        for(i=0;i<limite;i++)
        {
            if(pMusico[i].idOrquesta==id)
            {
                auxMusico=pMusico[i];
                retorno=0;
                printf("\nId: %d - nombre: %s - apellido: %s - edad: %d - id orquesta: %d\n",auxMusico.idMusico,auxMusico.nombre,auxMusico.apellido,auxMusico.edad,auxMusico.idOrquesta);
            }
        }
    }
    return retorno;
}
