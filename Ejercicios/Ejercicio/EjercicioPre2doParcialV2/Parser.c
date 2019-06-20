#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Empleado.h"

int parser_parseEmpleados(FILE* pFile, LinkedList* listaEmpleados)
{

    int retorno=-1;
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];
    int flagOnce=0;
    Empleado* auxEmpleado;
    if(pFile!=NULL && listaEmpleados!=NULL)
    {
        retorno=0;
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
    return retorno;
}

