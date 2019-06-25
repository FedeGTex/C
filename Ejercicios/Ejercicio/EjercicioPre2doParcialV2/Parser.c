#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Empleado.h"

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{

    int retorno=-1;
    FILE* pFile;
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    //char bufferSueldo[1024];
    int flagOnce=0;
    Empleado* auxEmpleado;
    if(fileName!=NULL && listaEmpleados!=NULL)
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
                    fscanf(pFile,"%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferHorasTrabajadas);
                    flagOnce=1;
                }
                    fscanf(pFile,"%[^,],%[^,],%[^ \n]\n",bufferId,bufferNombre,bufferHorasTrabajadas);
                    auxEmpleado=Empleado_newConParametros(atoi(bufferId),bufferNombre,atoi(bufferHorasTrabajadas),0);
                    if(auxEmpleado!=NULL)
                    {
                        ll_add(listaEmpleados,auxEmpleado);
                        retorno=1;
                    }
                    else
                    {
                        printf("%s,%s,%s\n",bufferId,bufferNombre,bufferHorasTrabajadas);
                    }
            }while(!feof(pFile));
        }
    }
    fclose(pFile);
    return retorno;
}

