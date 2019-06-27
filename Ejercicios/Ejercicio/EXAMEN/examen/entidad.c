#include "entidad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Entidad* Entidad_new()
{
    Entidad* this;
    this=malloc(sizeof(Entidad));
    return this;
}

void Entidad_delete(Entidad* this)
{
    free(this);
}

Entidad* Entidad_newConParametros(int id,char* tipo,int cantidad,float peso)
{
    Entidad* this;
    this=Entidad_new();

    if(
    !Entidad_setId(this,id)&&
    !Entidad_setTipo(this,tipo)&&
    !Entidad_setCantidad(this,cantidad)&&
    !Entidad_setPeso(this,peso))
        return this;

    Entidad_delete(this);
    return NULL;
}




int Entidad_setId(Entidad* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

int Entidad_getId(Entidad* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Entidad_setTipo(Entidad* this,char* tipo)
{
    int retorno=-1;
    if(this!=NULL && tipo!=NULL)
    {
        strcpy(this->tipo,tipo);
        retorno=0;
    }
    return retorno;
}

int Entidad_getTipo(Entidad* this,char* tipo)
{
    int retorno=-1;
    if(this!=NULL && tipo!=NULL)
    {
        strcpy(tipo,this->tipo);
        retorno=0;
    }
    return retorno;
}

int Entidad_setCantidad(Entidad* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int Entidad_getCantidad(Entidad* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

int Entidad_setPeso(Entidad* this,float peso)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->peso=peso;
        retorno=0;
    }
    return retorno;
}

int Entidad_getPeso(Entidad* this,float* peso)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *peso=this->peso;
        retorno=0;
    }
    return retorno;
}





void Entidad_Mostrar(void* pEntidad)
{
    int bufferId;
    char bufferTipo[50];
    int bufferCantidad;
    float bufferPeso;
    if(pEntidad!=NULL)
    {
        Entidad_getId(pEntidad,&bufferId);
        Entidad_getTipo(pEntidad,bufferTipo);
        Entidad_getCantidad(pEntidad,&bufferCantidad);
        Entidad_getPeso(pEntidad,&bufferPeso);
        printf("%d -%s -%d-%.2f\n",bufferId,bufferTipo,bufferCantidad,bufferPeso);
    }
}
