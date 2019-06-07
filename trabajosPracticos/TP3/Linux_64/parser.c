#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];
    int flagOnce=0;
    Employee* auxEmployee;
    if(pFile!=NULL && pArrayListEmployee!=NULL)
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
            auxEmployee=employee_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
            if(auxEmployee!=NULL)
            {
                ll_add(pArrayListEmployee,auxEmployee);
            }
            else
            {
                printf("%s,%s,%s,%s\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
            }
        }while(!feof(pFile));
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int retorno=-1;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        do
        {
            auxEmployee=employee_new();

            if(fread(auxEmployee,sizeof(Employee),1,pFile)==1 && !employee_validarEmpleado(auxEmployee))
            {
                ll_add(pArrayListEmployee,auxEmployee);
            }
            else
            {
                employee_delete(auxEmployee);
            }
        }while(!feof(pFile));
        retorno=0;
    }
    return retorno;
}
