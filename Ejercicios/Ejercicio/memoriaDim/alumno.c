#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"


static int empleado_isValidNombre(char* nombre);
static int empleado_isValidLegajo(int* legajo);
static int empleado_isValidStatus(int* status);


Alumno* alumno_new()
{
    return (Alumno*) malloc(sizeof(Alumno));
}

Alumno* alumno_newParametros(int id,int legajo,int status,char* nombre)
{
    Alumno* this;
    this=alumno_new();
    if( this== NULL ||
        alumno_setNombre(this,nombre) ||
        alumno_setLegajo(this,legajo) ||
        alumno_setStatus(this,status))
    {
            alumno_delete(this);
            this= NULL;
    }
    return this;
}

int alumno_delete(Alumno* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int alumno_setNombre(Alumno* this,char* nombre){
    int retorno=-1;
    if(this != NULL && alumno_isValidNombre(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}
int alumno_getNombre(Alumno* this,char* nombre){
    int retorno=-1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}
static int empleado_isValidNombre(char* nombre)
{
    return 1;
}

int alumno_setId(Alumno* this, int value)
{
    int retorno = -1;
    if(this != NULL && value >= 0)
    {
        this->id = value;
        retorno = 0;
    }
    return retorno;
}


int alumno_getId(Alumno* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value != NULL)
    {
        *value = this->id;
        retorno = 0;
    }
    return retorno;
}













