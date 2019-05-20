#include <stdio.h>
//#include <stdio_ext.h>
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

