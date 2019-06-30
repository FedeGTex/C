#include "informes.h"
#include "Ventas.h"
#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include "LinkedList.h"

int informe_generarInforme(char* fileName, LinkedList* lista)
{
    int retorno=-1;
    if(venta_generarArchivo(fileName,lista)==0)
    {
        retorno=0;
    }
    return retorno;
}
