#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include "Llamadas.h"
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "utn.h"
//static int isValidId(char* employeeId);
//static int isValidPrecioUnitario(char* precioUnitario);
//static int isValidCantidad(char* precioUnitario);
//static int isValidFecha(char* fecha);
//static int isValidTipoFoto(char* tipoFoto);
//static int isValidCuitCliente(char* cuitCliente);
static int isValidInt(char* pBuffer);
static int isValidFecha(char* pBuffer);
static int isValidSolucion(char* pBuffer);


Llamada* Llamadas_new()
{
    Llamada* this;
    this=malloc(sizeof(Llamada));
    return this;
}

void Llamadas_delete(Llamada* this)
{
    free(this);
}

Llamada* Llamadas_newConParametros(char*idLlamada,char*fechaLlamada,char*numeroCliente,char*idProblema,char*solucionado)
{
    Llamada* this;
    this=Llamadas_new();

    if(
        !Llamadas_setId_Llamada(this,idLlamada)&&
        !Llamadas_setFecha_Llamada(this,fechaLlamada)&&
        !Llamadas_setNumeroCliente(this,numeroCliente)&&
        !Llamadas_setId_problema(this,idProblema)&&
        !Llamadas_setSolucionado(this,solucionado))
        return this;

    Llamadas_delete(this);
    return NULL;
}

int Llamadas_setId_Llamada(Llamada* this,char*idLlamada)
{
    int retorno=-1;
    int id;
    if(this!=NULL && !isValidInt(idLlamada))
    {
        id=atoi(idLlamada);
        if( id >=0)
        {
            this->idLlamada=id;
            retorno=0;
        }
    }
    return retorno;
}

int Llamadas_getId_Llamada(Llamada* this,int* idLlamada)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idLlamada=this->idLlamada;
        retorno=0;
    }
    return retorno;
}

int Llamadas_setFecha_Llamada(Llamada* this,char*fechaLlamada)
{
    int retorno=-1;
    if(this!=NULL && !isValidFecha(fechaLlamada))
    {
        strcpy(this->fechaLlamada,fechaLlamada);
        retorno=0;
    }
    return retorno;
}

int Llamadas_getFecha_Llamada(Llamada* this,char* fechaLlamada)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(fechaLlamada,this->fechaLlamada);
        retorno=0;
    }
    return retorno;
}


int Llamadas_setNumeroCliente(Llamada* this,char*numeroCliente)
{
    int retorno=-1;
    int num;
    if(this!=NULL && !isValidInt(numeroCliente))
    {
        num=atoi(numeroCliente);
        if(num>=0)
        {
            this->numeroCliente=num;
            retorno=0;
        }
    }
    return retorno;
}

int Llamadas_getNumeroCliente(Llamada* this,int* numeroCliente)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *numeroCliente=this->numeroCliente;
        retorno=0;
    }
    return retorno;
}

int Llamadas_setId_problema(Llamada* this,char*idProblema)
{
    int retorno=-1;
    int id;
    if(this!=NULL && !isValidInt(idProblema))
    {
        id=atoi(idProblema);
        if(id>0)
        {
            this->idProblema=id;
            retorno=0;
        }
    }
    return retorno;
}

int Llamadas_getId_problema(Llamada* this,int* idProblema)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idProblema=this->idProblema;
        retorno=0;
    }
    return retorno;
}

int Llamadas_setSolucionado(Llamada* this,char* solucionado)
{
    int retorno=-1;
    if(this!=NULL && !isValidSolucion(solucionado))
    {
        strcpy(this->solucionado,solucionado);
        retorno=0;
    }
    return retorno;
}

int Llamadas_getSolucionado(Llamada* this,char* solucionado)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(solucionado,this->solucionado);
        retorno=0;
    }
    return retorno;
}
int Llamadas_Mostrar(void* pLlamada)
{
    int bufferId;
    char bufferFecha[50];
    int bufferNumeroCliente;
    int bufferIdProblema;
    char bufferSolucionado[50];
    if(pLlamada!=NULL)
    {
        Llamadas_getId_Llamada(pLlamada,&bufferId);
        Llamadas_getFecha_Llamada(pLlamada,bufferFecha);
        Llamadas_getNumeroCliente(pLlamada,&bufferNumeroCliente);
        Llamadas_getId_problema(pLlamada,&bufferIdProblema);
        Llamadas_getSolucionado(pLlamada,bufferSolucionado);
        printf("%d - %s - %d - %d - %s \n",bufferId,bufferFecha,bufferNumeroCliente,bufferIdProblema,bufferSolucionado);
    }
    return 0;
}

int Llamadas_MostrarFile(void* pLlamada,FILE* pFile)
{
    int bufferId;
    char bufferFecha[50];
    int bufferNumeroCliente;
    int bufferIdProblema;
    char bufferSolucionado[50];
    if(pLlamada!=NULL && pFile!=NULL)
    {
        Llamadas_getId_Llamada(pLlamada,&bufferId);
        Llamadas_getFecha_Llamada(pLlamada,bufferFecha);
        Llamadas_getNumeroCliente(pLlamada,&bufferNumeroCliente);
        Llamadas_getId_problema(pLlamada,&bufferIdProblema);
        Llamadas_getSolucionado(pLlamada,bufferSolucionado);
        fprintf(pFile,"%d - %s - %d - %d - %s\n",bufferId,bufferFecha,bufferNumeroCliente,bufferIdProblema,bufferSolucionado);
    }
    return 0;
}


int problema1(void* pElement)
{
    int retorno;
    int problema;
    if(pElement!=NULL)
    {
        Llamadas_getId_problema(pElement,&problema);
        if(problema==1)
        {
            retorno=1;
        }
        else
            retorno=0;
    }
    return retorno;
}

int problema2(void* pElement)
{
    int retorno;
    int problema;
    if(pElement!=NULL)
    {
        Llamadas_getId_problema(pElement,&problema);
        if(problema==2)
        {
            retorno=1;
        }
        else
            retorno=0;
    }
    return retorno;
}

int problema3(void* pElement)
{
    int retorno;
    int problema;
    if(pElement!=NULL)
    {
        Llamadas_getId_problema(pElement,&problema);
        if(problema==3)
        {
            retorno=1;
        }
        else
            retorno=0;
    }
    return retorno;
}

int problema4(void* pElement)
{
    int retorno;
    int problema;
    if(pElement!=NULL)
    {
        Llamadas_getId_problema(pElement,&problema);
        if(problema==4)
        {
            retorno=1;
        }
        else
            retorno=0;
    }
    return retorno;
}

int problema5(void* pElement)
{
    int retorno;
    int problema;
    if(pElement!=NULL)
    {
        Llamadas_getId_problema(pElement,&problema);
        if(problema==5)
        {
            retorno=1;
        }
        else
            retorno=0;
    }
    return retorno;
}


int llamada_generarArchivo1(char* fileName,LinkedList* lista)
{
    int retorno=-1;
    LinkedList* listaFiltrada1;
    FILE* pFile;
    pFile=fopen(fileName,"w+");
    if(pFile !=NULL)
    {
        retorno=0;
        listaFiltrada1=ll_filter(lista,problema1);
        ll_mapPrint(pFile,listaFiltrada1,Llamadas_MostrarFile);
        /*totalCantidad=ll_countInt(lista,venta_cantidadAContarTotal);
        MayoresCientoCincuenta=ll_countInt(lista,venta_cantidadAContarMayor150);
        MayoresTrescientos=ll_countInt(lista,venta_cantidadAContarMayor300);
        cantPola=ll_countInt(lista,venta_cantidadPolaroid);
        fprintf(pFile,"Cantidad de fotos reveladas totales: %d\n",totalCantidad);
        fprintf(pFile,"Cantidad de ventas con un monto mayor a $150: %d\n",MayoresCientoCincuenta);
        fprintf(pFile,"Cantidad de ventas con un monto mayor a $300: %d\n",MayoresTrescientos);
        fprintf(pFile,"Cantidad de fotos polaroids reveladas: %d\n",cantPola);*/

    }
    fclose(pFile);
    return retorno;
}

int llamada_generarArchivo2(char* fileName,LinkedList* lista)
{
    int retorno=-1;
    LinkedList* listaFiltrada2;
    FILE* pFile;
    pFile=fopen(fileName,"w+");
    if(pFile !=NULL)
    {
        retorno=0;
        listaFiltrada2=ll_filter(lista,problema2);
        ll_mapPrint(pFile,listaFiltrada2,Llamadas_MostrarFile);
        /*totalCantidad=ll_countInt(lista,venta_cantidadAContarTotal);
        MayoresCientoCincuenta=ll_countInt(lista,venta_cantidadAContarMayor150);
        MayoresTrescientos=ll_countInt(lista,venta_cantidadAContarMayor300);
        cantPola=ll_countInt(lista,venta_cantidadPolaroid);
        fprintf(pFile,"Cantidad de fotos reveladas totales: %d\n",totalCantidad);
        fprintf(pFile,"Cantidad de ventas con un monto mayor a $150: %d\n",MayoresCientoCincuenta);
        fprintf(pFile,"Cantidad de ventas con un monto mayor a $300: %d\n",MayoresTrescientos);
        fprintf(pFile,"Cantidad de fotos polaroids reveladas: %d\n",cantPola);*/

    }
    fclose(pFile);
    return retorno;
}


int llamada_generarArchivo3(char* fileName,LinkedList* lista)
{
    int retorno=-1;
    LinkedList* listaFiltrada3;
    FILE* pFile;
    pFile=fopen(fileName,"w+");
    if(pFile !=NULL)
    {
        retorno=0;
        listaFiltrada3=ll_filter(lista,problema3);
        ll_mapPrint(pFile,listaFiltrada3,Llamadas_MostrarFile);
        /*totalCantidad=ll_countInt(lista,venta_cantidadAContarTotal);
        MayoresCientoCincuenta=ll_countInt(lista,venta_cantidadAContarMayor150);
        MayoresTrescientos=ll_countInt(lista,venta_cantidadAContarMayor300);
        cantPola=ll_countInt(lista,venta_cantidadPolaroid);
        fprintf(pFile,"Cantidad de fotos reveladas totales: %d\n",totalCantidad);
        fprintf(pFile,"Cantidad de ventas con un monto mayor a $150: %d\n",MayoresCientoCincuenta);
        fprintf(pFile,"Cantidad de ventas con un monto mayor a $300: %d\n",MayoresTrescientos);
        fprintf(pFile,"Cantidad de fotos polaroids reveladas: %d\n",cantPola);*/

    }
    fclose(pFile);
    return retorno;
}

int llamada_generarArchivo4(char* fileName,LinkedList* lista)
{
    int retorno=-1;
    LinkedList* listaFiltrada4;
    FILE* pFile;
    pFile=fopen(fileName,"w+");
    if(pFile !=NULL)
    {
        retorno=0;
        listaFiltrada4=ll_filter(lista,problema4);
        ll_mapPrint(pFile,listaFiltrada4,Llamadas_MostrarFile);
        /*totalCantidad=ll_countInt(lista,venta_cantidadAContarTotal);
        MayoresCientoCincuenta=ll_countInt(lista,venta_cantidadAContarMayor150);
        MayoresTrescientos=ll_countInt(lista,venta_cantidadAContarMayor300);
        cantPola=ll_countInt(lista,venta_cantidadPolaroid);
        fprintf(pFile,"Cantidad de fotos reveladas totales: %d\n",totalCantidad);
        fprintf(pFile,"Cantidad de ventas con un monto mayor a $150: %d\n",MayoresCientoCincuenta);
        fprintf(pFile,"Cantidad de ventas con un monto mayor a $300: %d\n",MayoresTrescientos);
        fprintf(pFile,"Cantidad de fotos polaroids reveladas: %d\n",cantPola);*/

    }
    fclose(pFile);
    return retorno;
}

int llamada_generarArchivo5(char* fileName,LinkedList* lista)
{
    int retorno=-1;
    LinkedList* listaFiltrada5;
    FILE* pFile;
    pFile=fopen(fileName,"w+");
    if(pFile !=NULL)
    {
        retorno=0;
        listaFiltrada5=ll_filter(lista,problema5);
        ll_mapPrint(pFile,listaFiltrada5,Llamadas_MostrarFile);
        /*totalCantidad=ll_countInt(lista,venta_cantidadAContarTotal);
        MayoresCientoCincuenta=ll_countInt(lista,venta_cantidadAContarMayor150);
        MayoresTrescientos=ll_countInt(lista,venta_cantidadAContarMayor300);
        cantPola=ll_countInt(lista,venta_cantidadPolaroid);
        fprintf(pFile,"Cantidad de fotos reveladas totales: %d\n",totalCantidad);
        fprintf(pFile,"Cantidad de ventas con un monto mayor a $150: %d\n",MayoresCientoCincuenta);
        fprintf(pFile,"Cantidad de ventas con un monto mayor a $300: %d\n",MayoresTrescientos);
        fprintf(pFile,"Cantidad de fotos polaroids reveladas: %d\n",cantPola);*/

    }
    fclose(pFile);
    return retorno;
}

///retorno=0 esta ok retorno=1 esta mal

static int isValidInt(char* pBuffer)
{
    int retorno=1;
    int i;
    if(pBuffer!=NULL)
    {
        for(i=0; i<strlen(pBuffer); i++)
        {
            if(pBuffer[i]>'9' || pBuffer[i]<'0' )
            {
                break;
            }
        }
    }
    if( i == strlen(pBuffer))
        retorno = 0;
    return retorno;
}




static int isValidFecha(char* pBuffer)
{
    int retorno=1;
    int i;
    int flagCont=0;
    if(pBuffer!=NULL)
    {
        for(i=0; i<strlen(pBuffer); i++)
        {
            if(pBuffer[i]=='-' || pBuffer[i]=='/')
            {
                flagCont++;
                continue;
            }
            if(pBuffer[i]>'9' || pBuffer[i]<'0')
            {
                break;
            }
        }
    }
    if(i==strlen(pBuffer) && flagCont==2)
        retorno=0;
    return retorno;
}


static int isValidSolucion(char* pBuffer)
{
    int retorno=1;
    int i;
    int flagCont=0;
    if(pBuffer!=NULL)
    {
        for(i=0; i<strlen(pBuffer); i++)
        {
            if(pBuffer[i]=='-')
            {
                flagCont++;
                continue;
            }
            if(pBuffer[i]>'9' || pBuffer[i]<'0')
            {
                break;
            }
        }
    }
    if(i==strlen(pBuffer) && flagCont==2)
        retorno=0;
    return retorno;
}
