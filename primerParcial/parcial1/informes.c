//#include <stdio.h>
#include <stdio_ext.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "musico.h"
#include "orquesta.h"
#include "instrumento.h"

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
                    printf("La orquesta %s %s tipo %d tiene la mayor cantidad de musicos: %d\n",pOrquesta[i].nombre,pOrquesta[i].lugar,pOrquesta[i].tipo,maximoMusicos);
                }
            }
        }
    }
    return retorno;
}


int informes_orquestaConMasDe5(Orquesta* pOrquesta,int limiteO,Musico* pMusico,int limiteM)
{
    int i;
    int cantidad=0;
    int cantM;
    if(pMusico!=NULL && limiteM>0&& pOrquesta!=NULL && limiteO>0)
    {
        for(i=0;i<limiteM;i++)
        {
            cantM=informes_orquesta_cant_musicos(pOrquesta[i].idOrquesta,pMusico,limiteM);
            if(!pMusico[i].isEmpty && 5<cantM)
            {
                cantidad++;
            }
        }
        if(!cantidad)
        {
            printf("\nNinguna orquesta tiene mas de 5 musicos\n");
        }else {
            printf("\nLa cantidad de orquestas que tienen mas de 5 musicos son: %d",cantidad-1);
            orquesta_imprimirPorId(pOrquesta,limiteO,pOrquesta[i].idOrquesta);
        }
    }
    return 0;
}

int informes_cant_musicosMas30(Musico* pMusico,int limiteM)
{
    int i;
    int masTreinta = 0;
    if(pMusico!=NULL && limiteM>0)
    {
        for(i=0;i<limiteM;i++)
        {
            if(!pMusico[i].isEmpty && pMusico[i].edad>30)
            {
                masTreinta ++;
            }
        }
    }
    return masTreinta;
}


int informes_musicosMasDe30(Musico* pMusico,int limiteM,Orquesta* pOrquesta,int limiteO,Instrumento* pInstrumento,int limiteI)
{
    int retorno=-1;
    int i;
    int indiceMayor;
    int idOrq;
    int idInst;

    if(pMusico!=NULL && limiteM>0 && pOrquesta!=NULL && limiteO>0 && pInstrumento!=NULL && limiteI>0)
    {
        for(i=0;i<limiteM;i++)
        {

            if(!pMusico[i].isEmpty)
            {
                retorno=0;
                indiceMayor=informes_cant_musicosMas30(pMusico,limiteM);
                idOrq=orquesta_buscarPorId(pOrquesta,limiteO,pMusico[i].idOrquesta);
                idInst=instrumento_buscarPorId(pInstrumento,limiteI,pMusico[i].idInstrumento);
                printf("\nid%d - nombre%s - apellido%s - edad%d nombI%s nombO%s",pMusico[indiceMayor].idMusico,pMusico[indiceMayor].nombre,pMusico[indiceMayor].apellido,pMusico[indiceMayor].edad,pInstrumento[idInst].nombre,pOrquesta[idOrq].nombre);
            }
        }
    }
    return retorno;
}


/*int informes_orquestasDeUnLugar(Orquesta* pOrquesta,int limite,int lugar)
{
    int retorno=-1;
    int i;

    if(pOrquesta!=NULL && limite>0)
    {
        for(i=0;i<limite;i++)
        {
            if(!pOrquesta[i].isEmpty && (strncpy(pOrquesta[i].lugar,lugar,20)))
            {
                retorno=0;
                orquesta_mostrar(pOrquesta,limite);

            }
        }
    }
    return retorno;
}
*/


