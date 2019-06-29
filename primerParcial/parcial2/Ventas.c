#include <stdio_ext.h>
#include <stdlib.h>
#include "Ventas.h"
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "utn.h"
static int isValidId(char* employeeId);
static int isValidPrecioUnitario(char* precioUnitario);
static int isValidCantidad(char* precioUnitario);
static int isValidFecha(char* fecha);
static int isValidTipoFoto(char* tipoFoto);
static int isValidCuitCliente(char* cuitCliente);


Venta* venta_new()
{
    Venta* this;
    this=malloc(sizeof(Venta));
    return this;
}

void venta_delete(Venta* this)
{
    free(this);
}

Venta* venta_newConParametros(char* idVenta,char* fechaVenta,char* tipoFoto,char* cantidad,char* precioUnitario,char* cuitCliente)
{
    Venta* p;
    p=venta_new();
    if(p!=NULL)
    {
        if( venta_setIdVenta(p,idVenta)==-1 ||
            venta_setFechaVenta(p,fechaVenta)==-1 ||
            venta_setTipoFoto(p,tipoFoto)==-1 ||
            venta_setPrecioUnitario(p,precioUnitario) == -1 ||
            venta_setCantidad(p,cantidad)==-1 ||
            venta_setCuitCliente(p,cuitCliente)== -1)
        {
            venta_delete(p);
            p=NULL;
        }
    }
    return p;
    return NULL;
}

int venta_setIdVenta(Venta* this,char* idVenta)
{
    int retorno=-1;
    if(this!=NULL && isValidId(idVenta)==0)
    {
        this->idVenta=atoi(idVenta);
        retorno=0;
    }
    return retorno;
}

int venta_getIdVenta(Venta* this,int* idVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idVenta=this->idVenta;
        retorno=0;
    }
    return retorno;
}

static int isValidId(char* idVenta)
{
    int i=0;
    int retorno=0;
    while(idVenta[i] != '\0')
    {
        if(idVenta[i] < '0' || idVenta[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;
}

int venta_setFechaVenta(Venta* this,char* fechaVenta)
{
    int retorno=-1;
    if(this!=NULL && fechaVenta!=NULL && isValidFecha(fechaVenta)==0)
    {
        strcpy(this->fechaVenta,fechaVenta);
        retorno=0;
    }
    return retorno;
}

int venta_getFechaVenta(Venta* this,char* fechaVenta)
{
    int retorno=-1;
    if(this!=NULL && fechaVenta!=NULL)
    {
        strcpy(fechaVenta,this->fechaVenta);
        retorno=0;
    }
    return retorno;
}

static int isValidFecha(char* fecha)
{
    int i=0;
    int retorno=0;
    int contadorBarras=0;
    while(fecha[i] != '\0')
    {
        if(fecha[i]=='/' && contadorBarras<2)
        {
            contadorBarras++;
        }
        else if (fecha[i] < '0' || fecha[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;
}

int venta_setTipoFoto(Venta* this,char* tipoFoto)
{
    int retorno=-1;
    if(this!=NULL && tipoFoto!=NULL && isValidTipoFoto(tipoFoto)==0)
    {
        strcpy(this->tipoFoto,tipoFoto);
        retorno=0;
    }
    return retorno;
}

int venta_getTipoFoto(Venta* this,char* tipoFoto)
{
    int retorno=-1;
    if(this!=NULL && tipoFoto!=NULL)
    {
        strcpy(tipoFoto,this->tipoFoto);
        retorno=0;
    }
    return retorno;
}

static int isValidTipoFoto(char* tipoFoto)
{
    int i=0;
    int retorno=0;
    int contadorGuiones=0;
    while(tipoFoto[i] != '\0')
    {
        if(tipoFoto[i]=='_' &&tipoFoto==0)
        {
            contadorGuiones++;
        }
        else if (tipoFoto[i] < 'A' || tipoFoto[i] > 'Z')
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}

int venta_setPrecioUnitario(Venta* this,char* precioUnitario)
{
    int retorno=-1;
    if(this != NULL && isValidPrecioUnitario(precioUnitario)==0)
    {
        this->precioUnitario=atof(precioUnitario);
        retorno=0;
    }
    return retorno;
}

int venta_getPrecioUnitario(Venta* this,float* precioUnitario)
{
    int retorno=-1;
    if(this!=NULL && precioUnitario != NULL)
    {
        *precioUnitario=this->precioUnitario;
        retorno=0;
    }
    return retorno;
}

static int isValidPrecioUnitario(char* precioUnitario)
{
    int i=0;
    int retorno=0;
    int contadorDePuntos=0;
    while(precioUnitario[i] != '\0')
    {
        if(precioUnitario[i] == '.' && contadorDePuntos==0)
        {
            contadorDePuntos++;
            i++;
            continue;
        }
        if(precioUnitario[i] < '0' || precioUnitario[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;
}

int venta_setCantidad(Venta* this,char* cantidad)
{
    int retorno=-1;
    if(this!=NULL && isValidCantidad(cantidad)==0)
    {
        this->cantidad=atoi(cantidad);
        retorno=0;
    }
    return retorno;
}

int venta_getCantidad(Venta* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

static int isValidCantidad(char* cantidad)
{
    int i=0;
    int retorno=0;
    while(cantidad[i] != '\0')
    {
        if(cantidad[i] < '0' || cantidad[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;
}

int venta_setCuitCliente(Venta* this,char* cuitCliente)
{
    int retorno=-1;
    if(this!=NULL && cuitCliente!=NULL && isValidCuitCliente(cuitCliente)==0)
    {
        strcpy(this->cuitCliente,cuitCliente);
        retorno=0;
    }
    return retorno;
}

int venta_getCuitCliente(Venta* this,char* cuitCliente)
{
    int retorno=-1;
    if(this!=NULL && cuitCliente!=NULL)
    {
        strcpy(cuitCliente,this->cuitCliente);
        retorno=0;
    }
    return retorno;
}

static int isValidCuitCliente(char* cuitCliente)
{
    int i=0;
    int retorno=0;
    int contadorGuiones=0;
    while(cuitCliente[i] != '\0')
    {
        if(cuitCliente[i]=='-' && contadorGuiones<2)
        {
            contadorGuiones++;
        }
        else if (cuitCliente[i] < '0' || cuitCliente[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }

    return retorno;
}

int venta_buscarPorId(LinkedList* listaVentas, int idVenta)
{
    int retorno=-1;
    int i;
    Venta* auxVenta;
    int size=ll_len(listaVentas);
    if(listaVentas!=NULL)
    {
        for(i=0;i<size;i++)
        {
            auxVenta=ll_get(listaVentas,i);
            if(auxVenta!=NULL && auxVenta->idVenta== idVenta)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int venta_cantidadAContarTotal(void* pElement)
{
    int retorno=0;
    int bufferId;
    char bufferFechaVenta[2000];
    char bufferTipoFoto[2000];
    float bufferPrecioUnitario;
    int bufferCantidad;
    char bufferCuitCliente[2000];
    if(pElement!=NULL)
    {
        venta_getIdVenta(pElement,&bufferId);
        venta_getFechaVenta(pElement,bufferFechaVenta);
        venta_getTipoFoto(pElement,bufferTipoFoto);
        venta_getPrecioUnitario(pElement,&bufferPrecioUnitario);
        venta_getCantidad(pElement,&bufferCantidad);
        venta_getCuitCliente(pElement,bufferCuitCliente);
        retorno = bufferCantidad;
        printf("sadsads");

    }
    return retorno;
}

int venta_cantidadAContarMayor150(void* pElement)
{
    int retorno=0;
    float total;
    if(pElement != NULL)
    {
        total=((Venta*)pElement)->cantidad * ((Venta*)pElement)->precioUnitario;
        if(total > 150)
        {
            retorno=1;
        }
    }
    return retorno;
}

int venta_cantidadAContarMayor300(void* pElement)
{
    int retorno=0;
    float total;
    int cantidad;
    float precioUnitario;
    if(pElement != NULL)
    {
        venta_getCantidad(pElement,&cantidad);
        venta_getPrecioUnitario(pElement,&precioUnitario);
        total=cantidad * precioUnitario;
        if(total > 300)
        {
            retorno=1;
        }
    }
    return retorno;
}



int venta_cantidadPolaroid(void* pElement)
{
    int retorno=0;
    int bufferId;
    char bufferFechaVenta[2000];
    char bufferTipoFoto[2000];
    float bufferPrecioUnitario;
    int bufferCantidad;
    char bufferCuitCliente[2000];
    if(pElement!=NULL)
    {
        venta_getIdVenta(pElement,&bufferId);
        venta_getFechaVenta(pElement,bufferFechaVenta);
        venta_getTipoFoto(pElement,bufferTipoFoto);
        venta_getPrecioUnitario(pElement,&bufferPrecioUnitario);
        venta_getCantidad(pElement,&bufferCantidad);
        venta_getCuitCliente(pElement,bufferCuitCliente);
        if((!strcmp(bufferTipoFoto,"POLAROID_11x9")) && (!strcmp(bufferTipoFoto,"POLAROID_10x10")))
          retorno = bufferCantidad;
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
