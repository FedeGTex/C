#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "entidad.h"

int parser_parseEntidad(char* fileName, LinkedList* listaEntidad)
{

    int retorno=-1;
    FILE* pFile;
    char bufferId[1024];
    char bufferTipo[1024];
    char bufferCantidad[1024];
    char bufferPeso[1024];
    int flagOnce=0;
    Entidad* auxEntidad;
    if(fileName!=NULL && listaEntidad!=NULL)
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
                    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferTipo,bufferCantidad,bufferPeso);
                    flagOnce=1;
                }
                    fscanf(pFile,"%[^,],%[^,],%[^,],%[^ \n]\n",bufferId,bufferTipo,bufferCantidad,bufferPeso);
                    auxEntidad=Entidad_newConParametros(atoi(bufferId),bufferTipo,atoi(bufferCantidad),atof(bufferPeso));
                    if(auxEntidad!=NULL)
                    {
                        ll_add(listaEntidad,auxEntidad);
                        retorno=1;
                    }
                    else
                    {
                        printf("%s,%s,%s,%s\n",bufferId,bufferTipo,bufferCantidad,bufferPeso);
                    }
            }while(!feof(pFile));
        }
    }
    fclose(pFile);
    return retorno;
}
