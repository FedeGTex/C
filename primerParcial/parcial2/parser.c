#include <stdio_ext.h>
#include <stdlib.h>
#include "Ventas.h"
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "utn.h"

int parser_parseVentas(char* fileName, LinkedList* lista)
{

    int retorno=-1;
    FILE* pFile;
    char bufferId[1024];
    char bufferFechaVenta[1024];
    char bufferTipoFoto[1024];
    char bufferCantidad[1024];
    char bufferPrecioUnitario[1024];
    char bufferCuitCliente[1024];
    int flagOnce=0;
    Venta* auxVenta;
    if(fileName!=NULL && lista!=NULL)
    {
        retorno=0;
        pFile=fopen(fileName,"r");
        if(pFile!=NULL)
        {
            do
            {
                retorno=0;
                if(!flagOnce)
                {
                    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferFechaVenta,bufferTipoFoto,bufferCantidad,bufferPrecioUnitario,bufferCuitCliente);
                    flagOnce=1;
                }
                    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferFechaVenta,bufferTipoFoto,bufferCantidad,bufferPrecioUnitario,bufferCuitCliente);
                    auxVenta=venta_newConParametros(bufferId,bufferFechaVenta,bufferTipoFoto,bufferCantidad,bufferPrecioUnitario,bufferCuitCliente);
                    if(auxVenta!=NULL)
                    {
                        ll_add(lista,auxVenta);
                        retorno=1;
                    }
                    else
                    {
                        printf("%s,%s,%s,%s,%s,%s\n",bufferId,bufferFechaVenta,bufferTipoFoto,bufferCantidad,bufferPrecioUnitario,bufferCuitCliente);
                    }
            }while(!feof(pFile));
        }
    }
    fclose(pFile);
    return retorno;
}
