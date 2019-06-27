#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "entregas.h"

static int lastId=0;

void entregas_idInit(int id)
{
    lastId=id+1;
}

int entregas_idGenerator()
{
    return lastId++;
}

int entregas_setIdStr(Entregas* this,char* idStr)
{
    int ret=-1;
    int bufferId;
    if(this!=NULL && idStr!=NULL)
    {
        if(utn_isValidInt(idStr))
        {
            bufferId = atoi(idStr);
            if(!entregas_setId(this,bufferId))
            {
                ret=0;
            }
        }
    }
    return ret;
}

int entregas_setId(Entregas* this,int id)
{
    int ret=-1;
    if(this!=NULL && id>=0)
    {
        this->id=id;
        ret=0;
    }
    return ret;
}

int entregas_getId(Entregas* this,int* id)
{
    int ret=-1;
    if(this!=NULL&&id!=NULL)
    {
        *id=this->id;
        ret=0;
    }
    return ret;
}

Entregas* entregas_new()
{
    return (Entregas*)malloc(sizeof(Entregas));
}

int entregas_delete(Entregas* this)
{
    int ret=-1;
    if(this!=NULL)
    {
        free(this);
        ret=0;
    }
    return ret;
}

int entregas_compareId(void* pElementA,void* pElementB)
{
    int ret = 0;
    if(((Entregas*)pElementA)->id > ((Entregas*)pElementB)->id)
    {
        ret = 1;
    }
    if(((Entregas*)pElementA)->id < ((Entregas*)pElementB)->id)
    {
        ret = -1;
    }
    return ret;
}

int entregas_setTipo(Entregas* this,char* tipo)
{
    int ret=-1;
    if(this != NULL && utn_isValidName(tipo))
    {
        strncpy(this->tipo,tipo,sizeof(this->tipo));
        ret=0;
    }
    return ret;
}

int entregas_getTipo(Entregas* this,char* tipo)
{
    int ret=-1;
    if(this!=NULL && tipo!=NULL)
    {
        strncpy(tipo,this->tipo,sizeof(this->tipo));
        ret=0;
    }
    return ret;
}

int entregas_compareTipo(void* pElementA,void* pElementB)
{
    int ret = 0;
    if(strcmp(((Entregas*)pElementA)->tipo,((Entregas*)pElementB)->tipo)>0)
    {
        ret = 1;
    }
    if(strcmp(((Entregas*)pElementA)->tipo,((Entregas*)pElementB)->tipo)<0)
    {
        ret = -1;
    }
    return ret;
}

int entregas_setCantidadStr(Entregas* this,char* cantidadStr)
{
    int ret=-1;
    int bufferCantidad;
    if(this!=NULL)
    {
        if(utn_isValidInt(cantidadStr))
        {
            bufferCantidad = atoi(cantidadStr);
            if(!entregas_setCantidad(this,bufferCantidad))
            {
                ret=0;
            }
        }
    }
    return ret;
}

int entregas_setCantidad(Entregas* this,int cantidad)
{
    int ret=-1;
    if(this!=NULL && cantidad>=0)
    {
        this->cantidad=cantidad;
        ret=0;
    }
    return ret;
}

int entregas_getCantidad(Entregas* this,int* cantidad)
{
    int ret=-1;
    if(this!=NULL && cantidad!=NULL)
    {
        *cantidad=this->cantidad;
        ret=0;
    }
    return ret;
}

int entregas_compareCantidad(void* pElementA,void* pElementB)
{
    int ret = 0;
    if(((Entregas*)pElementA)->cantidad > ((Entregas*)pElementB)->cantidad)
    {
        ret = 1;
    }
    if(((Entregas*)pElementA)->cantidad < ((Entregas*)pElementB)->cantidad)
    {
        ret = -1;
    }
    return ret;
}

int entregas_setPesoStr(Entregas* this,char* pesoStr)
{
    int ret=-1;
    int bufferPeso;
    if(this!=NULL)
    {
        if(utn_isValidFloat(pesoStr))
        {
            bufferPeso = atof(pesoStr);
            if(!entregas_setPeso(this,bufferPeso))
            {
                ret=0;
            }
        }
    }
    return ret;
}

int entregas_setPeso(Entregas* this,float peso)
{
    int ret=-1;
    if(this!=NULL && peso>=0)
    {
        this->peso=peso;
        ret=0;
    }
    return ret;
}

int entregas_getPeso(Entregas* this,float* peso)
{
    int ret=-1;
    if(this!=NULL && peso!=NULL)
    {
        *peso=this->peso;
        ret=0;
    }
    return ret;
}

int entregas_comparePeso(void* pElementA,void* pElementB)
{
    int ret = 0;
    if(((Entregas*)pElementA)->peso > ((Entregas*)pElementB)->peso)
    {
        ret = 1;
    }
    if(((Entregas*)pElementA)->peso < ((Entregas*)pElementB)->peso)
    {
        ret = -1;
    }
    return ret;
}

Entregas* entregas_newParametros(char* idStr,char* tipoStr,char* cantidadStr,char* pesoStr)
{
    Entregas* aux;
    aux=entregas_new();
    if(aux!=NULL)
    {
        if(entregas_setIdStr(aux,idStr)||entregas_setTipo(aux,tipoStr)||entregas_setCantidadStr(aux,cantidadStr)||entregas_setPesoStr(aux,pesoStr))
        {
            entregas_delete(aux);
            aux=NULL;
        }
    }
    return aux;
}

