#include "informes.h"
#include "Envio.h"
#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include "LinkedList.h"

int informe_generarInforme1(char* fileName, LinkedList* lista)
{
    int retorno=-1;

    if(Envio_generarArchivo1(fileName,lista)==0)
    {
        retorno=0;
    }
    return retorno;
}

