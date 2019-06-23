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
    char bufferSueldo[1024];
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
                if(!flagOnce)
                {
                    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
                    flagOnce=1;
                }
                    fscanf(pFile,"%[^,],%[^,],%[^,],%[^ \n]\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
                    auxEmpleado=Empleado_newConParametros(atoi(bufferId),bufferNombre,atoi(bufferHorasTrabajadas),atoi(bufferSueldo));
                    if(auxEmpleado!=NULL)
                    {
                        ll_add(listaEmpleados,auxEmpleado);
                    }
                    else
                    {
                        printf("%s,%s,%s,%s\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
                    }
            }while(!feof(pFile));
        }
    }
    fclose(pFile);
    return retorno;
}

