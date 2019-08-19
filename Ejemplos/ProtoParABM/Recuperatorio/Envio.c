#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include "Envio.h"
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "utn.h"

Envio* Envios_new()
{
    Envio* this;
    this=malloc(sizeof(Envio));
    return this;
}

void Envios_delete(Envio* this)
{
    free(this);
}

Envio* Envios_newConParametros(char*idEnvio,char*nombreProducto,char*kmRecorrido,char*tipoProducto)
{
    Envio* this;
    this=Envios_new();

    if  (!Envios_setId_Envio(this,idEnvio) &&
         !Envios_setNombre_producto(this,nombreProducto) &&
         !Envios_setKm_recorrido(this,kmRecorrido) &&
         !Envios_setTipo_producto(this,tipoProducto))
         return this;

    Envios_delete(this);

    return NULL;
}

int Envios_setId_Envio(Envio* this,char*idEnvio)
{
    int retorno=-1;
    int auxId;
    static int proximoId=-1;
    auxId=atoi(idEnvio);
    if(this!=NULL && auxId==-1)
    {
        proximoId++;
        this->idEnvio=proximoId;
        retorno=0;
    }
    else
    {
        this->idEnvio=auxId;
        retorno=0;
    }

    if(auxId>proximoId)
    {
        proximoId=auxId;
        retorno=0;
    }
    return retorno;
}

int Envios_getId_Envio(Envio* this,int* idEnvio)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idEnvio=this->idEnvio;
        retorno=0;
    }
    return retorno;
}

int Envios_setNombre_producto(Envio* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(this->nombreProducto,nombre);
        retorno=0;
    }
    return retorno;
}

int Envios_getNombre_producto(Envio* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(nombre,this->nombreProducto);
        retorno=0;
    }
    return retorno;
}


int Envios_setKm_recorrido(Envio* this,char*km)
{
    int retorno=-1;
    int num;
    if(this!=NULL)
    {
        num=atoi(km);
        if(num>=0)
        {
            this->kmRecorrido=num;
            retorno=0;
        }
    }
    return retorno;
}

int Envios_getKm_recorrido(Envio* this,int* km)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *km=this->kmRecorrido;
        retorno=0;
    }
    return retorno;
}

int Envios_setTipo_producto(Envio* this,char*tipo)
{
    int retorno=-1;
    int num;
    if(this!=NULL)
    {
        num=atoi(tipo);
        if(num>0)
        {
            this->tipoProducto=num;
            retorno=0;
        }
    }
    return retorno;
}

int Envios_getTipo_producto(Envio* this,int* tipo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *tipo=this->tipoProducto;
        retorno=0;
    }
    return retorno;
}

int Envios_fprinf(void* pEnvio,FILE* pFile)
{
    int bufferId;
    char bufferNombre[1024];
    int bufferKm;
    int bufferTipo;
    if(pEnvio!=NULL)
    {
        Envios_getId_Envio(pEnvio,&bufferId);
        Envios_getNombre_producto(pEnvio,bufferNombre);
        Envios_getKm_recorrido(pEnvio,&bufferKm);
        Envios_getTipo_producto(pEnvio,&bufferTipo);
        fprintf(pFile,"%d - %s - %d - %d - % d \n",bufferId,bufferNombre,bufferKm,bufferTipo,((Envio*)pEnvio)->costo);
    }
    return 0;
}

int calcularCosto(void* pEnvio)
{
    int retorno = -1;
    int bufferKm;
    int bufferTipo;
    int costo;
    if(pEnvio!=NULL)
    {
        Envios_getKm_recorrido(pEnvio,&bufferKm);
        Envios_getTipo_producto(pEnvio,&bufferTipo);
        if(bufferKm<50)
        {
            costo=bufferKm*67;
        }
        else
        {
            costo=bufferKm*80;
        }
        switch(bufferTipo)
        {
            case 1:
                costo=costo+330;
                break;
            case 2:
                costo=costo+560;
                break;
            case 3:
                costo=costo+80;
                break;
        }
        ((Envio*)pEnvio)->costo=costo;
        return 0;
    }
    return retorno;
}

int Envios_Mostrar(void* pEnvio)
{
    int bufferId;
    char bufferNombre[1024];
    int bufferKm;
    int bufferTipo;

    if(pEnvio!=NULL)
    {
        Envios_getId_Envio(pEnvio,&bufferId);
        Envios_getNombre_producto(pEnvio,bufferNombre);
        Envios_getKm_recorrido(pEnvio,&bufferKm);
        Envios_getTipo_producto(pEnvio,&bufferTipo);
        printf("%d - %s - %d - %d - % d \n",bufferId,bufferNombre,bufferKm,bufferTipo,((Envio*)pEnvio)->costo);
    }
    return 0;
}

int Envio_generarArchivo1(char* fileName,LinkedList* lista)
{
    int retorno=-1;
    //LinkedList* listaFiltrada1;
    FILE* pFile;
    pFile=fopen(fileName,"w+");
    if(pFile !=NULL)
    {
        retorno=0;
        ll_map(lista,calcularCosto);
        ll_mapPrint(pFile,lista,Envios_fprinf);
    }
    fclose(pFile);
    return retorno;
}


int Envios_alta(void* this)
{
    int retorno=-1;
    Envio* pEnvio;
    char nombreProducto[1024];
    char kmRecorrido[1024];
    char tipoProducto[1024];

    if(this!=NULL)
    {
        if(!utn_getLetras(nombreProducto,20,2,"Ingrese nombre: \n","Ingrese un nombre valido!\n"))
        {
            if(!utn_getLetrasYNumeros(kmRecorrido,50,"Ingrese los km: \n"))
            {
                if(!utn_getLetrasYNumeros(tipoProducto,50,"Ingres el tipo: \n"))
                {
                    pEnvio=Envios_newConParametros("-1",nombreProducto,kmRecorrido,tipoProducto);
                    if(pEnvio!=NULL)
                    {
                        ll_add(this,pEnvio);
                        retorno=0;
                    }
                }
            }
        }
    }
    return retorno;
}

int Envios_modificar(void* this)
{
    int retorno=-1;
    int i;
    char nombreProducto[1024];
    char kmRecorrido[1024];
    char tipoProducto[1024];
    Envio* punteroAElemento;
    int id;
    if(this!=NULL)
    {
        if(!utn_getEntero(&id,2,"Ingrese el id a modificar: \n","Ingrese un id valido!\n",0,999999))
        {
            for(i=0;i<ll_len(this);i++)
            {
                punteroAElemento=ll_get(this,i);
                if(!Envios_buscarPorId(punteroAElemento,id))
                {
                    if(!utn_getLetras(nombreProducto,20,2,"Ingrese nuevo nombre: \n","Ingrese un nombre valido!\n")&&
                       !utn_getLetrasYNumeros(kmRecorrido,50,"Ingrese los nuevos km: \n")&&
                       !utn_getLetrasYNumeros(tipoProducto,50,"Ingres el nuevo tipo: \n"))
                    {
                        Envios_setNombre_producto(punteroAElemento,nombreProducto);
                        Envios_setKm_recorrido(punteroAElemento,kmRecorrido);
                        Envios_setTipo_producto(punteroAElemento,tipoProducto);
                        retorno=0;
                        break;
                    }
                }
            }
        }
    }
    return retorno;
}

int Envios_baja(void* this)
{
    int retorno=-1;
    int i;
    Envio* punteroAElemento;
    int id;
    if(this!=NULL)
    {
        if(!utn_getEntero(&id,2,"Ingrese el id a dar de baja: \n","Ingrese un id valido!\n",0,999999))
        {
            for(i=0;i<ll_len(this);i++)
            {
                punteroAElemento=ll_get(this,i);
                if(!Envios_buscarPorId(punteroAElemento,id))
                {
                    ll_remove(this,i);
                    retorno=0;
                    break;
                }
            }
        }
    }
    return retorno;
}


int Envios_buscarPorId(Envio* pElement,int id)
{
    int retorno=-1;
    int auxId;
    if(pElement!=NULL && id>=0)
    {
        Envios_getId_Envio(pElement,&auxId);
        if(auxId==id)
        {
            retorno=0;
        }
    }
    return retorno;
}
