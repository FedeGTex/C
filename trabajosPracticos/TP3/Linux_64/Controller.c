#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno=-1;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"r");
        if(pFile!=NULL)
        {
            parser_EmployeeFromText(pFile,pArrayListEmployee);
            fclose(pFile);
            retorno=0;
        }
        else
        {
            printf("\nNo se pudo abrir el archivo!\n");
        }
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"rb");
        if(pFile!=NULL)
        {
            parser_EmployeeFromBinary(pFile,pArrayListEmployee);
            retorno=0;
        }
        else
        {
            printf("\nEl archivo no pudo abrirse!!\n");
        }
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    char bufferNombre[1024];
    int auxHorasTrabajadas;
    int auxSueldo;
    Employee* auxEmployee;
    if(pArrayListEmployee!=NULL &&
       !utn_getLetras(bufferNombre,50,2,"\nIngrese un nombre: ","\nIngrese un nombre valido!")&&
       !utn_getEntero(&auxHorasTrabajadas,2,"\nIngrese las horas trabajadas: ","\nIngrese horas validas!",10,500)&&
       !utn_getEntero(&auxSueldo,2,"\nIngrese el sueldo: ","\nIngrese un sueldo valido!",10,9999999))
    {
        auxEmployee=employee_new();
        if(auxEmployee!=NULL && !employee_setNombre(auxEmployee,bufferNombre)&&
           !employee_setId(auxEmployee,-1)&& !employee_setSueldo(auxEmployee,auxSueldo)&&
           !employee_setHorasTrabajadas(auxEmployee,auxHorasTrabajadas))
           {
                retorno=0;
                ll_add(pArrayListEmployee,auxEmployee);
           }
           else
           {
            employee_delete(auxEmployee);
            auxEmployee=NULL;
           }
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int limite;
    int i;
    char bufferNombre[1024];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    int bufferId;
    int auxId;
    Employee* auxEmployee;
    if(pArrayListEmployee!=NULL && !utn_getEntero(&auxId,3,"\nIngrese la id del empleado a modificar: ","\nIngrese un id valido!",0,999999))
    {
       limite=ll_len(pArrayListEmployee);
       for(i=0;i<limite;i++)
       {
            auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(auxEmployee,&bufferId);
            if(bufferId==auxId &&!utn_getLetras(bufferNombre,1024,2,"\nIngrese un nombre: ","\nIngrese un nombre valido!")&&
                !utn_getEntero(&bufferHorasTrabajadas,2,"\nIngrese las horas trabajadas: ","\nIngrese horas validas!",10,999)&&
                !utn_getEntero(&bufferSueldo,2,"\nIngrese el sueldo: ","\nIngrese un sueldo valido!",10,999999)&&
                !employee_setNombre(auxEmployee,bufferNombre)&&
                !employee_setSueldo(auxEmployee,bufferSueldo)&&
                !employee_setHorasTrabajadas(auxEmployee,bufferHorasTrabajadas))
                {
                    retorno=0;
                    break;
                }
       }
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int limite;
    int i;
    int bufferId;
    int auxId;
    Employee* auxEmployee;
    if(pArrayListEmployee!=NULL &&!utn_getEntero(&auxId,2,"\nIngrese el id del empleado a borrar: ","\nIngrese un id valido!",0,99999))
    {
        limite=ll_len(pArrayListEmployee);
        for(i=0;i<limite;i++)
        {
            auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(auxEmployee,&bufferId);
            if(bufferId==auxId)
            {
                ll_remove(pArrayListEmployee,i);
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int limite;
    int i;
    int bufferId;
    int bufferSueldo;
    int bufferHorasTrabajadas;
    char bufferNombre[1024];
    Employee* auxEmployee;
    if(pArrayListEmployee!=NULL)
    {
        retorno=0;
        limite=ll_len(pArrayListEmployee);
        for(i=0;i<limite;i++)
        {
            auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getNombre(auxEmployee,bufferNombre);
            employee_getId(auxEmployee,&bufferId);
            employee_getSueldo(auxEmployee,&bufferSueldo);
            employee_getSueldo(auxEmployee,&bufferSueldo);
            employee_getHorasTrabajadas(auxEmployee,&bufferHorasTrabajadas);
            printf("Id - %d,Nombre - %s,Horas - %d,Sueldo - %d\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
        }
        getchar();
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if(pArrayListEmployee!=NULL)
    {
        ll_sort(pArrayListEmployee,employee_criterioNombre,1);
        retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile!=NULL && !employee_guardarTexto(pFile,pArrayListEmployee))
        {
            fclose(pFile);
            printf("\nSe ha guardado con exito!\n");
            retorno=0;
        }
        else
        {
            printf("\nNo se pudo abrir el archivo!\n");
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"wb");
        if(pFile!=NULL && !employee_guardarBinario(pFile,pArrayListEmployee))
        {
            fclose(pFile);
            printf("\nSe ha guardado con exito!\n");
            retorno=0;
        }
        else
        {
            printf("\nNo se pudo abrir el archivo!\n");
        }
    }
    return retorno;
}

