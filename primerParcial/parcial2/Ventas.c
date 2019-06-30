#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include "Ventas.h"
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


Venta* Ventas_new()
{
    Venta* this;
    this=malloc(sizeof(Venta));
    return this;
}

void Ventas_delete(Venta* this)
{
    free(this);
}

Venta* Ventas_newConParametros(int idVenta,char*fechaVenta,char* tipoFoto,int cantidad,float precioUnitario,char*cuitCliente)
{
    Venta* this;
    this=Ventas_new();

    if(
    !Ventas_setId_Venta(this,idVenta)&&
    !Ventas_setFecha_Venta(this,fechaVenta)&&
    !Ventas_setTipoFoto(this,tipoFoto)&&
    !Ventas_setCantidad(this,cantidad)&&
    !Ventas_setPrecio_Unitario(this,precioUnitario)&&
    !Ventas_setCuit_Cliente(this,cuitCliente))
        return this;

    Ventas_delete(this);
    return NULL;
}

int Ventas_setId_Venta(Venta* this,int idVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idVenta=idVenta;
        retorno=0;
    }
    return retorno;
}

int Ventas_getId_Venta(Venta* this,int* idVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idVenta=this->idVenta;
        retorno=0;
    }
    return retorno;
}

int Ventas_setFecha_Venta(Venta* this,char*fechaVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(this->fechaVenta,fechaVenta);
        retorno=0;
    }
    return retorno;
}

int Ventas_getFecha_Venta(Venta* this,char* fechaVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(fechaVenta,this->fechaVenta);
        retorno=0;
    }
    return retorno;
}

int Ventas_setTipoFoto(Venta* this,char*tipoFoto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(this->tipoFoto,tipoFoto);
        retorno=0;
    }
    return retorno;
}

int Ventas_getTipoFoto(Venta* this,char* tipoFoto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(tipoFoto,this->tipoFoto);
        retorno=0;
    }
    return retorno;
}

int Ventas_setCantidad(Venta* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int Ventas_getCantidad(Venta* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

int Ventas_setPrecio_Unitario(Venta* this,float precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->precioUnitario=precioUnitario;
        retorno=0;
    }
    return retorno;
}

int Ventas_getPrecio_Unitario(Venta* this,float* precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precioUnitario=this->precioUnitario;
        retorno=0;
    }
    return retorno;
}

int Ventas_setCuit_Cliente(Venta* this,char* cuitCliente)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(this->cuitCliente,cuitCliente);
        retorno=0;
    }
    return retorno;
}

int Ventas_getCuit_Cliente(Venta* this,char* cuitCliente)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(cuitCliente,this->cuitCliente);
        retorno=0;
    }
    return retorno;
}
void Ventas_Mostrar(void* pVenta){
    int bufferId;
    char bufferFecha[50];
    char bufferCodigo[50];
    int bufferCantidad;
    float bufferPrecio;
    char bufferCuit[50];
    if(pVenta!=NULL){
        Ventas_getId_Venta(pVenta,&bufferId);
        Ventas_getCantidad(pVenta,&bufferCantidad);
        Ventas_getTipoFoto(pVenta,bufferCodigo);
        Ventas_getCuit_Cliente(pVenta,bufferCuit);
        Ventas_getFecha_Venta(pVenta,bufferFecha);
        Ventas_getPrecio_Unitario(pVenta,&bufferPrecio);
        printf("%d -%s - %s -%d-%.2f-%s\n",bufferId,bufferFecha,bufferCodigo,bufferCantidad,bufferPrecio,bufferCuit);
    }
}

int venta_cantidadAContarTotal(void* pElement)
{
    int retorno;
    if(pElement!=NULL)
    {
        Ventas_getCantidad(pElement,&retorno);
    }
    return retorno;
}

int venta_cantidadAContarMayor150(void* pElement)
{
    int retorno;
    float total;
    if(pElement!=NULL)
    {
        total=((Venta*)pElement)->cantidad * ((Venta*)pElement)->precioUnitario;
        if(total>150)
        {
            retorno=1;
        }else
            retorno=0;
    }
    return retorno;
}

int venta_cantidadAContarMayor300(void* pElement)
{
    int retorno;
    float total;
    int cantidad;
    float precioUnitario;
    if(pElement!=NULL)
    {
        cantidad=((Venta*)pElement)->cantidad;
        precioUnitario=((Venta*)pElement)->precioUnitario;
        total=cantidad*precioUnitario;
        if(total>300)
        {
            retorno=1;
        }else
            retorno=0;
    }
    return retorno;
}



int venta_cantidadPolaroid(void* pElement)
{
    int retorno=0;
    char aux[1024];
    if(pElement!=NULL)
    {
        Ventas_getTipoFoto(pElement,aux);
        if((strcmp(aux,"POLAROID_11x9")==0) && (!strcmp(aux,"POLAROID_10x10")==0))
        {
            retorno=1;
        }
    }
    return retorno;

}



int venta_generarArchivo(char* fileName,LinkedList* lista)
{
    int retorno=-1;
    int totalCantidad;
    int MayoresCientoCincuenta;
    int MayoresTrescientos;
    int cantPola;
    FILE* pFile;
    pFile=fopen(fileName,"w");
    if(pFile !=NULL)
    {
        retorno=0;
        totalCantidad=ll_countInt(lista,venta_cantidadAContarTotal);
        MayoresCientoCincuenta=ll_countInt(lista,venta_cantidadAContarMayor150);
        MayoresTrescientos=ll_countInt(lista,venta_cantidadAContarMayor300);
        cantPola=ll_countInt(lista,venta_cantidadPolaroid);
        fprintf(pFile,"Cantidad de fotos reveladas totales: %d\n",totalCantidad);
        fprintf(pFile,"Cantidad de ventas con un monto mayor a $150: %d\n",MayoresCientoCincuenta);
        fprintf(pFile,"Cantidad de ventas con un monto mayor a $300: %d\n",MayoresTrescientos);
        fprintf(pFile,"Cantidad de fotos polaroids reveladas: %d\n",cantPola);

    }
    fclose(pFile);
    return retorno;
}
