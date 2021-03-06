#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "utn.h"
#include "LinkedList.h"
#include "Employee.h"

//static int isValidId(char* employeeId);
static int isValidNombre(char* nombre);
static int isValidHorasTrabajadas(int horas);
static int isValidId(int id);
static int isValidSueldo(int sueldo);
static int isInnt(char *pBuffer);
static int isLettras(char*pBuffer);
//static int isValidSueldo(char* sueldo);
//static int isValidHorasTrabajadas(char* horasTrabajadas);

/** \brief crea un nuevo puntero del tipo empleado de manera dinamica
 * \return puntero nuevo o null si no se pudo crear
 */

Employee* employee_new(void)
{
    Employee* this;
    this=malloc(sizeof(Employee));
    return this;
}

/** \brief libera puntero del tipo empleado de manera dinamica
 * \param this Employee* Puntero a la estructura a borrar
 */
int employee_delete(Employee* this)
{
    int retorno=-1;
    if(this!=NULL)
    {
        free(this);
        retorno=0;
    }
    return retorno;
}

/** \brief crea un nuevo puntero del tipo empleado de manera dinamica y guarda los datos
            en cada uno de sus campos despues de validarlos
 * \param id char*
 * \param nombre char*
 * \param horastrabajadas char*
 * \param sueldo char*
 * \return puntero nuevo o null si no se pudo crear
 */

Employee* employee_newParametros(char* id,char* nombre,char* horasTrabajadas,char* sueldo)
{
    Employee* this;
    this=employee_new();
    if(!isInnt(id) && !isLettras(nombre) && !isInnt(horasTrabajadas) && !isInnt(sueldo)&&
       !employee_setId(this,atoi(id))&&
       !employee_setNombre(this,nombre)&&
       !employee_setHorasTrabajadas(this,atoi(horasTrabajadas))&&
       !employee_setSueldo(this,atoi(sueldo)))
       {
        return this;
       }
       employee_delete(this);
       return NULL;
}

/*int employee_setId(Employee* this,char* id)
{
    int retorno=-1;
    static int proximoId=-1;
    int idAuxiliar;
    if(this != NULL && isValidId(id)==0)
    {
        idAuxiliar=atoi(id);
        if(idAuxiliar==-1)
        {
            proximoId++;
            this->id=proximoId;
            retorno=0;
        }else if(idAuxiliar>proximoId)
        {
            proximoId=idAuxiliar;
            this->id=proximoId;
            retorno=0;
        }

    }
    return retorno;
}*/

/** \brief Guarda el dato en el campo id, si ya tiene valor lo guarda asi y contabiliza el maximo
            si se ingresa -1 genera uno nuevo apartir del mayor
 * \param id int
 * \return 0 todo bien 1 error
 */

int employee_setId(Employee* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1 && !isValidId(id))
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else{
        this->id=id;
        retorno=0;
    }

    if(id>proximoId)
    {
        proximoId=id;
        retorno=0;
    }
    return retorno;
}

/** \brief devuelve el dato en el campo id
 * \param id int*
 * \param this Employee* Puntero a la estructura Employee
 * \return 0 todo bien 1 error
 */

int employee_getId(Employee* this,int* id)
{
    int retorno=-1;
     if(this != NULL && id!= NULL)
     {
        *id=this->id;
        retorno=0;
     }
    return retorno;
}

static int isValidId(int id)
{
    int retorno=-1;
    if(id>-2)
    {
        retorno=0;
    }
    return retorno;
}

/** \brief guarda el dato en el campo nombre
 * \param nombre char* nombre a guardar
 * \param this Employee* Puntero a la estructura Employee
 * \return 0 todo bien 1 error
 */

int employee_setNombre(Employee* this, char* nombre)
{
    int retorno=-1;
    if(this!=NULL && !isValidNombre(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief devuelve el dato en el campo nombre
 * \param nombre char*
 * \param this Employee* Puntero a la estructura Employee
 * \return 0 todo bien 1 error
 */

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

/**
 * \brief recibe una cadena de caracteres de un nombre para validar que solo sean letras
 * \param nombre: cadena de caracteres a validar
 * \return 0 OK, -1 error.
*/

static int isValidNombre(char* nombre)
{
    int retorno=-1;
    if(nombre!= NULL && strlen(nombre)<50 && strlen(nombre)>1)
    {
        retorno=0;
    }
    return retorno;
}
/*int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas)
{
    int retorno=-1;
    if(this != NULL && !isValidHorasTrabajadas(horasTrabajadas))
    {
        this->horasTrabajadas=atoi(horasTrabajadas);
        retorno=0;
    }
    return retorno;
}*/

/** \brief guarda el dato en el campo horasTrabajadas
 * \param horasTrabajadas int horasTrabajadas a guardar
 * \param this Employee* Puntero a la estructura Employee
 * \return 0 todo bien 1 error
 */

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL && !isValidHorasTrabajadas(horasTrabajadas))
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

/** \brief devuelve el dato en el campo horas
 * \param horas int*
 * \param this Employee* Puntero a la estructura Employee
 * \return 0 todo bien 1 error
 */

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
     if(this != NULL && horasTrabajadas!= NULL)
     {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
     }
    return retorno;
}

static int isValidHorasTrabajadas(int horas)
{
    int retorno=-1;
    if(horas>0)
    {
        retorno=0;
    }
    return retorno;
}

/*int employee_setSueldo(Employee* this,char* sueldo)
{
    int retorno=-1;
    if(this != NULL && !isValidSueldo(sueldo))
    {
        this->sueldo=atoi(sueldo);
        retorno=0;
    }
    return retorno;
}*/

/** \brief guarda el dato en el campo sueldo
 * \param sueldo int sueldo a guardar
 * \param this Employee* Puntero a la estructura Employee
 * \return 0 todo bien 1 error
 */

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL && !isValidSueldo(sueldo))
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

/** \brief devuelve el dato en el campo sueldo
 * \param sueldo int*
 * \param this Employee* Puntero a la estructura Employee
 * \return 0 todo bien -1 error
 */

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this != NULL && sueldo!= NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

static int isValidSueldo(int sueldo)
{
    int retorno=-1;
    if(sueldo>0)
    {
        retorno=0;
    }
    return retorno;
}

/** \brief guarda los datos del LinkedList en la ruta del archivo recibido en modo texto
 * \param pFile puntero al archivo
 * \param pArrayListEmployee Puntero a la estructura Employee
 * \return 0 todo bien -1 error
 */

int employee_guardarTexto(FILE* pFile,LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i=0;
    int bufferId;
    char buffernombre[1024];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    int limite;
    Employee* auxEmployee;
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
        limite=ll_len(pArrayListEmployee);
        do
        {
            auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(auxEmployee,&bufferId);
            employee_getNombre(auxEmployee,buffernombre);
            employee_getHorasTrabajadas(auxEmployee,&bufferHorasTrabajadas);
            employee_getSueldo(auxEmployee,&bufferSueldo);
            fprintf(pFile,"%d,%s,%d,%d\n",bufferId,buffernombre,bufferHorasTrabajadas,bufferSueldo);
            i++;
        }while(i<limite);
        if(i==limite)
        {
            retorno=0;
        }
    }
    return retorno;
}

/** \brief guarda los datos del LinkedList en la ruta del archivo recibido en modo binario
 * \param pFile puntero al archivo
 * \param pArrayListEmployee Puntero a la estructura Employee
 * \return 0 todo bien -1 error
 */


int employee_guardarBinario(FILE* pFile,LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i;
    int limite;
    Employee* auxEmployee;
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        limite=ll_len(pArrayListEmployee);
        retorno=0;
        for(i=0;i<limite;i++)
        {
            auxEmployee=ll_get(pArrayListEmployee,i);
            if(auxEmployee!=NULL)
            {
                fwrite(auxEmployee,sizeof(Employee),1,pFile);
            }
        }
        if(i==limite)
        {
            retorno=0;
        }
    }
    return retorno;
}

/**
 *  \brief utiliza el strcmp para comparar 2 nombres y retorna el valor del strcmp
 *  \param thisA: dato uno a comparar
 *  \param thisB: dato dos a comparar
 *  \return retorno: valor del strcmp
*/

int employee_criterioNombre(void* thisA,void* thisB)
{
    int retorno=0;
    char nombreA[1024];
    char nombreB[1024];
    employee_getNombre((Employee*)thisA,nombreA);
    employee_getNombre((Employee*)thisB,nombreB);
    if(strcmp(nombreA,nombreB)>0)
    {
        retorno=1;
    }else if(strcmp(nombreA,nombreB)<0)
    {
        retorno=-1;
    }
    return retorno;
}


int employee_validarEmpleado(Employee* auxEmployee)
{
    int retorno=-1;

    if(!isValidId(auxEmployee->id)&&
        !isValidNombre(auxEmployee->nombre) &&
        !isValidHorasTrabajadas(auxEmployee->horasTrabajadas)&&
        !isValidSueldo(auxEmployee->sueldo))
        {
            retorno=0;
        }
    return retorno;
}

static int isLettras(char*pBuffer)
{
    int retorno=-1;
    int i=0;
    if(pBuffer!=NULL)
    {
        do{
            if(*(pBuffer+i)==' '||*(pBuffer+i)=='-')
            {
                i++;
                continue;
            }
            if((*(pBuffer+i)<65||*(pBuffer+i)>90) && (*(pBuffer+i)<97||*(pBuffer+i)>122))
            {
                break;
            }
            i++;
        }while(i<strlen(pBuffer));
        if(i==strlen(pBuffer))
        {
            retorno=0;
        }
    }
    return retorno;
}


static int isInnt(char *pBuffer)
{
    int retorno=-1;
    int i=0;
    do{
        if(*(pBuffer+i)<48||*(pBuffer+i)>57)
        {
                break;
        }
        i++;
    }while (i<strlen(pBuffer));
    if(i==strlen(pBuffer))
    {
        retorno=0;
    }
    return retorno;
}
