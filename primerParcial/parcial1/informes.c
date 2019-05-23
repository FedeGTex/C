#include <stdio.h>
//#include <stdio_ext.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "musico.h"
#include "orquesta.h"
#include "instrumento.h"


/** \brief Se ingresa id de orquesta y se imprime los musicos que la componen
 * \param Orquesta* array de orquesta
 * \param limiteO int cantidad de elementos del array de orquesta
 * \param Musico* array de musico
 * \param limiteM int cantidad de elementos del array de musicos
 * \param Id ingresado por el usuario
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int informes_listarOrquestaConMusicosPorId(Orquesta* pOrquesta,int limiteO,Musico* pMusico,int limiteM,int id)
{
    int retorno=-1;

    if(pOrquesta!=NULL && limiteO>0 && pMusico!=NULL && limiteM>0)
    {
        retorno=0;
        orquesta_imprimirPorId(pOrquesta,limiteO,id);
        musicos_listarPorOrquesta(pMusico,limiteM,id);
    }
    return retorno;
}



/** \brief Lista los musicos por tipo de instrumento
 * \param Musico* array de musicos
 * \param Limite cantidad de elementos del array de musicos
 * \param Instrumento* array de instrumentos
 * \param limite int cantidad de elementos del array de instrumentos
 * \param tipo-tipo de instrumento
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int informes_listarMusicosPorTipoDeInstrumento(Musico* pMusico,int limiteM,Instrumento* pInstrumento,int limiteI,int tipo)
{
    int retorno=-1;
    int i,j;
    Musico auxMusico;
    if(pMusico!=NULL && limiteM>0 && pInstrumento!=NULL && limiteI>0)
    {
        for(i=0;i<limiteM;i++)//recorrer para buscar musicos
        {
            for(j=0;j<limiteI;j++)//recorrer para buscar instrumentos del musico
            {
                if(pMusico[i].idInstrumento==pInstrumento[j].idInstrumento && pInstrumento[j].tipo==tipo)
                {
                    auxMusico=pMusico[i];
                    retorno=0;
                    printf("\nId: %d - Nombre: %s - Apellido: %s - Edad: %d - Id Orquesta: %d - Id Instrumento: %d",auxMusico.idMusico,auxMusico.nombre,auxMusico.apellido,auxMusico.edad,auxMusico.idOrquesta,auxMusico.idInstrumento);
                }
            }
        }
    }
    return retorno;
}

/** \brief Calcula la cantidad de musicos de una orquesta
 * \param idOrquesta
 * \param Musicos* array de Musicos
 * \param limite int cantidad de elementos del array de musicos
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int informes_orquesta_cant_musicos(int idOrquesta,Musico* pMusico,int limiteMusico)
{
    int i;
    int cantMusicos = 0;

    if(pMusico!=NULL && limiteMusico>0)
    {
        for(i=0;i<limiteMusico;i++)
        {
            musicos_ordenar_por_idOrquesta(pMusico,limiteMusico);
            if(!pMusico[i].isEmpty)
            {
                if(pMusico[i].idOrquesta == idOrquesta)
                {
                    cantMusicos ++;
                }
            }
        }
    //printf("%d",cantMusicos);
    }
    return cantMusicos;
}



/** \brief Muestra la Orquesta con mas musicos
 * \param Orquesta* array de orquestas
 * \param limite int cantidad de elementos del array de Orquesta
 * \param Musicos* array de Musicos
 * \param limite int cantidad de elementos del array de musicos
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int informes_orquesta_con_mas_musicos(Orquesta* pOrquesta,int limiteO,Musico* pMusico,int limiteM)
{
    int i,cantMusicos;
    int retorno = -1;
    int maximoMusicos = -1;

    if((limiteO > 0 && pOrquesta != NULL) && (limiteM > 0 && pMusico != NULL))
    {
        for(i=0;i<limiteO;i++)
        {
            if(!pOrquesta[i].isEmpty)
            {
                cantMusicos = informes_orquesta_cant_musicos(pOrquesta[i].idOrquesta,pMusico,limiteM);
                if(maximoMusicos < cantMusicos)
                {
                    maximoMusicos = cantMusicos;
                    retorno = 0;
                }
            }
        }
        for(i=0;i<limiteO;i++)
        {
            if(!pOrquesta[i].isEmpty)
            {
                cantMusicos = informes_orquesta_cant_musicos(pOrquesta[i].idOrquesta,pMusico,limiteM);
                if(maximoMusicos == cantMusicos)
                {
                    printf("La orquesta %s %s tiene la mayor cantidad de musicos: %d\n",pOrquesta[i].nombre,pOrquesta[i].lugar,maximoMusicos);
                }
            }
        }
    }
    return retorno;
}

/** \brief Muestra la Orquesta con mas de 5 musicos
 * \param Orquesta* array de orquestas
 * \param limite int cantidad de elementos del array de Orquesta
 * \param Musicos* array de Musicos
 * \param limite int cantidad de elementos del array de musicos
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int informes_orquestaMasDe5Musicos(Orquesta* pOrquesta,int limiteO,Musico* pMusico,int limiteM)
{
    int retorno=-1;
    int cantM;
    int i;

    if(pOrquesta!=NULL && limiteO>0 && pMusico!=NULL && limiteM>0)
    {
        for(i=0;i<limiteO;i++)
        {
            cantM=informes_orquesta_cant_musicos(pOrquesta[i].idOrquesta,pMusico,limiteM);
            if(!pOrquesta[i].isEmpty && cantM>=5)
            {
                retorno=0;
                printf("\nLa orquesta con mas de 5 musicos es Id: %d - Nombre: %s - Lugar: %s - tipo: %d\n",pOrquesta[i].idOrquesta,pOrquesta[i].nombre,pOrquesta[i].lugar,pOrquesta[i].tipo);
            }
        }
    }
    return retorno;
}


/** \brief Lista los musicos mayores a 30 años imprimiendo el nombre de la orquesta e intrumento
 * \param Musico* array de musicos
 * \param limiteM int cantidad de elementos del array de musicos
 * \param Orquesta* array de orquestas
 * \param limiteO int cantidad de elementos del array de orquestas
 * \param Instrumento* array de instrumentos
 * \param limiteI cantidad de elementos del array de instrumentos
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int informes_listarMusicosMasDe30Anios(Musico* pMusico,int limiteM,Orquesta* pOrquesta,int limiteO,Instrumento* pInstrumento,int limiteI)
{
    int retorno=-1;
    int i;
    int posicionO;
    int posicionI;

    if(pMusico!=NULL && limiteM>0)
    {
        for(i=0;i<limiteM;i++)
        {
            if(!pMusico[i].isEmpty && pMusico[i].edad>30)
            {
                retorno=0;
                posicionO=orquesta_buscarPorId(pOrquesta,limiteO,pMusico[i].idOrquesta);
                posicionI=instrumento_buscarPorId(pInstrumento,limiteI,pMusico[i].idInstrumento);

                printf("Id: %d - Nombre: %s - Apellido: %s - Edad: %d - Nombre Instrumento: %s - Nombre orquesta: %s\n",pMusico[i].idMusico,pMusico[i].nombre,pMusico[i].apellido,pMusico[i].edad,pInstrumento[posicionI].nombre,pOrquesta[posicionO].nombre);
            }
        }
    }
    return retorno;
}


/** \brief Lista las orquestas ingresadas por el lugar
 * \param Orquesta* array de orquestas
 * \param limite int cantidad de elementos del array de Orquesta
 * \param lugar* lugar ingresado por el usuario
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int informes_listarOrquestasDeUnLugarDeterminado(Orquesta* pOrquesta,int limiteO,char* lugar)
{
    int retorno=-1;
    int i;

    if(pOrquesta!=NULL && limiteO>0)
    {
        for(i=0;i<limiteO;i++)
        {
            if(!pOrquesta[i].isEmpty && strcmp(pOrquesta[i].lugar,lugar)==0)
            {
                retorno=0;
                printf("Id: %d - Nombre: %s - Lugar: %s - tipo: %d\n",pOrquesta[i].idOrquesta,pOrquesta[i].nombre,pOrquesta[i].lugar,pOrquesta[i].tipo);
            }
        }
    }
    return retorno;
}

/** \brief Lista orquestas completa =o+5inst cuerda =o+3viento =o+percusion
 * \param Orquesta* array de orquesta
 * \param limiteO int cantidad de elementos del array de orquesta
 * \param Musico* array de musicos
 * \param limiteM int cantidad de elementos del array de musicos
 * \param Instrumento* array de instrumentos
 * \param limiteI cantidad de elementos del array de instrumentos
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int informes_orquestaCompleta(Orquesta* pOrquesta,int limiteO,Musico* pMusico,int limiteM,Instrumento* pInstrumento,int limiteI)
{
    int retorno=-1;
    int cuerda,viento,percusion,tipo;
    int i,j;

    if(pOrquesta!=NULL && limiteO>0 && pInstrumento!=NULL && limiteI>0 && pMusico!=NULL && limiteM>0)
    {
        for(i=0;i<limiteO;i++)
        {
            cuerda=0;
            viento=0;
            percusion=0;
            for(j=0;j<limiteM;j++)
            {
                if(pOrquesta[i].idOrquesta==pMusico[j].idOrquesta && !pOrquesta[i].isEmpty)
                {
                    tipo=instrumento_retornarTipoPorId(pInstrumento,limiteI,pMusico[j].idInstrumento);
                    switch(tipo)
                    {
                        case 1:
                            cuerda++;
                            break;
                        case 2:
                        case 3:
                            viento++;
                            break;
                        case 4:
                            percusion++;
                            break;
                    }

                }
            }
            if(cuerda>=5&&viento>=3&&percusion>=2)
            {
                retorno=0;
                printf("Id: %d - Nombre: %s - Lugar: %s - tipo: %d\n",pOrquesta[i].idOrquesta,pOrquesta[i].nombre,pOrquesta[i].lugar,pOrquesta[i].tipo);
            }
        }
    }
    return retorno;
}

/** \brief Lista los musicos que tocan instrumentos de cuerda
 * \param Musico* array de musicos
 * \param limiteM int cantidad de elementos del array de musicos
 * \param Instrumento* array de instrumentos
 * \param limiteI cantidad de elementos del array de instrumentos
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int informes_listarMusicosCuerda(Musico* pMusico,int limiteM,Instrumento* pInstrumento,int limiteI)
{
    int retorno=-1;
    int i;
    int tipo;
    int posicion;

    if(pMusico!=NULL && limiteM>0 && pInstrumento!=NULL && limiteI)
    {
        for(i=0;i<limiteM;i++)
        {
           tipo=instrumento_retornarTipoPorId(pInstrumento,limiteI,pMusico[i].idInstrumento);
            if(!pMusico[i].isEmpty && tipo==1)
            {
                retorno=0;
                posicion=instrumento_buscarPorId(pInstrumento,limiteI,pMusico[i].idInstrumento);
                printf("\nNombre: %s - apellido: %s - edad: %d - Nombre Instrumento: %s - Tipo Inst: %d",pMusico[i].nombre,pMusico[i].apellido,pMusico[i].edad,pInstrumento[posicion].nombre,pInstrumento[posicion].tipo);
            }
        }
    }
    return retorno;
}

/** \brief Calcula el promedio de musicos por orquesta
 * \param Musico* array de musicos
 * \param limiteM int cantidad de elementos del array de musicos
 * \param Orquesta* array de orquestas
 * \param limiteO int cantidad de elementos del array de orquestas
 * \return Si devuelve 0 salio todo bien. Si devuelve un numero negativo hay error
 *
 */
int informes_imprimirPromedioMusicosPorOrquesta(Orquesta* pOrquesta,int limiteO,Musico* pMusico,int limiteM)
{
    int retorno=-1;
    int i;
    int cantM=0;
    int cantO=0;
    float promedio;

    if(pOrquesta!=NULL && limiteO>0 && pMusico!=NULL && limiteM>0)
    {
        for(i=0;i<limiteO;i++)
        {
            if(!pOrquesta[i].isEmpty)
            {
                cantM+=informes_orquesta_cant_musicos(pOrquesta[i].idOrquesta,pMusico,limiteM);
                cantO++;
            }
        }
        promedio=(float)cantM/(float)cantO;
        printf("\nEl promedio es: %.2f",promedio);
    }
    return retorno;
}

