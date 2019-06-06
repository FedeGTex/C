#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "LinkedList.h"
#include "utn.h"
#include "Employee.h"

static int isValidId(char* employeeId);
static int isValidNombre(char* nombre);
static int isValidSueldo(char* sueldo);
static int isValidHorasTrabajadas(char* horasTrabajadas);

Employee* employee_new(void)
{
    Employee* this;
    this=malloc(sizeof(Employee));
    return this;
}

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

Employee* employee_newParametros(char* id,char* nombre,char* horasTrabajadas,char* sueldo)
{
    Employee* this;
    this=employee_new();
    if(this!=NULL)
    {
        if( employee_setNombre(this,nombre)==-1 ||
            employee_setId(this,id)==-1 ||
            employee_setHorasTrabajadas(this,horasTrabajadas) == -1 ||
            employee_setSueldo(this,sueldo) == -1)
        {

            employee_delete(this);
            this=NULL;
        }
    }
    return this;
}

int employee_setId(Employee* this,char* id)
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
}

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

static int isValidId(char* employeeId)
{
    int i=0;
    int retorno=0;
    int contadorDeGuiones=0;
    while(employeeId[i] != '\0')
    {
        if(employeeId[i] == '-' && contadorDeGuiones==0)
        {
            contadorDeGuiones++;
            i++;
            continue;
        }
        if(employeeId[i] < '0' || employeeId[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;
}

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

static int isValidNombre(char* nombre)
{
    int i=0;
    int retorno=0;
    int flag=0;
    while(nombre[i] != '\0')
    {
        if(flag==0)
        {
            nombre[i]=toupper(nombre[i]);
            flag=1;
        }else if ((nombre[i] < 'A' || nombre[i] > 'Z') &&
                (nombre[i] < 'a' || nombre[i] > 'z'))
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas)
{
    int retorno=-1;
    if(this != NULL && !isValidHorasTrabajadas(horasTrabajadas))
    {
        this->horasTrabajadas=atoi(horasTrabajadas);
        retorno=0;
    }
    return retorno;
}

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

static int isValidHorasTrabajadas(char* horasTrabajadas)
{
    int i=0;
    int retorno=0;
    while(horasTrabajadas[i] != '\0')
    {
        if(horasTrabajadas[i] < '0' || horasTrabajadas[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}

int employee_setSueldo(Employee* this,char* sueldo)
{
    int retorno=-1;
    if(this != NULL && !isValidSueldo(sueldo))
    {
        this->sueldo=atoi(sueldo);
        retorno=0;
    }
    return retorno;
}

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

static int isValidSueldo(char* sueldo)
{
    int i=0;
    int retorno=0;
    while(sueldo[i] != '\0')
    {
        if(sueldo[i] < '0' || sueldo[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}


