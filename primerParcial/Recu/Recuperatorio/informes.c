#include "informes.h"
#include "Llamadas.h"
#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include "LinkedList.h"

int informe_generarInforme1(char* fileName, LinkedList* lista)
{
    int retorno=-1;
    if(llamada_generarArchivo1(fileName,lista)==0)
    {
        retorno=0;
    }
    return retorno;
}


int informe_generarInforme2(char* fileName, LinkedList* lista)
{
    int retorno=-1;
    if(llamada_generarArchivo2(fileName,lista)==0)
    {
        retorno=0;
    }
    return retorno;
}

int informe_generarInforme3(char* fileName, LinkedList* lista)
{
    int retorno=-1;
    if(llamada_generarArchivo3(fileName,lista)==0)
    {
        retorno=0;
    }
    return retorno;
}

int informe_generarInforme4(char* fileName, LinkedList* lista)
{
    int retorno=-1;
    if(llamada_generarArchivo4(fileName,lista)==0)
    {
        retorno=0;
    }
    return retorno;
}

int informe_generarInforme5(char* fileName, LinkedList* lista)
{
    int retorno=-1;
    if(llamada_generarArchivo5(fileName,lista)==0)
    {
        retorno=0;
    }
    return retorno;
}
