//#include "stdio.h"
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "persona.h"
#include "utn.h"



Persona* Persona_new()
{
    Persona* this;
    this=(Persona*)malloc(sizeof(Persona));
    return this;
}

void Persona_delete(Persona* this)
{
    free(this);
}


Persona* Persona_newConParametros(int id,char*nombre,char* apellido,int edad)
{
    Persona* this;
    this=Persona_new();

    if(
    !Persona_setId(this,id)&&
    !Persona_setNombre(this,nombre)&&
    !Persona_setApellido(this,apellido)&&
    !Persona_setEdad(this,edad))
        return this;

    Persona_delete(this);
    return NULL;
}




int Persona_setId(Persona* this,int id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int Persona_getId(Persona* this,int* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}



int Persona_setNombre(Persona* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Persona_getNombre(Persona* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Persona_setApellido(Persona* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(this->apellido,apellido);
        retorno=0;
    }
    return retorno;
}

int Persona_getApellido(Persona* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(apellido,this->apellido);
        retorno=0;
    }
    return retorno;
}

int Persona_setEdad(Persona* this,int edad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->edad=edad;
        retorno=0;
    }
    return retorno;
}

int Persona_getEdad(Persona* this,int* edad)
{
    int retorno=-1;
    if(this!=NULL && edad!=NULL)
    {
        *edad=this->edad;
        retorno=0;
    }
    return retorno;
}




int Persona_buscarLugarVacio(Persona* arrayPersona[], int limite)
{
    int retorno=-1;
    int i;
    if(arrayPersona != NULL && limite>0)
    {
        for(i=0;i<limite;i++)
        {
            if(arrayPersona[i]==NULL)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int Persona_inicializarArray(Persona* arrayPersona[], int limite)
{
    int retorno=-1;
    int i;
    if(arrayPersona!=NULL && limite>0)
    {
        retorno=0;
        for(i=0;i<limite;i++)
        {
            arrayPersona[i]=NULL;
        }
    }
    return retorno;
}


int Persona_alta(Persona* arrayPersona,int limite)
{
    int retorno=-1;
    char auxNombre[31];
    char auxApellido[31];
    int auxEdad;

    Persona* auxPersona;

    if(arrayPersona!=NULL&&limite>0)
    {
        auxPersona=Persona_new();
        if(auxPersona!=NULL)
        {

            if(!utn_getLetras(auxNombre,31,2,"\nIngrese un nombre: ","\nIngrese un nombre valido!")&&
               !utn_getLetras(auxApellido,31,2,"\nIngrese un apellido: ","\nIngrese un nombre valido!")&&
               !utn_getEntero(&auxEdad,2,"\nEdad: ","\nERROR",1,100))
            {
               if(!Persona_setNombre(auxPersona,auxNombre)||
                          !Persona_setApellido(auxPersona,auxNombre)||
                          !Persona_setEdad(auxPersona,auxEdad))
                  {
                    Persona_delete(auxPersona);
                  }
                  else
                  {
                    retorno=0;
                  }

            }
         }
      }
    return retorno;
}


void Persona_mostrar(Persona* this)
{
    printf("\n%d - %s  -%s  -%d  ",this->id,this->nombre,this->apellido,this->edad);
}

