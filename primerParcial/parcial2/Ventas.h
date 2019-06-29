#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#include "LinkedList.h"

typedef struct{
    int idVenta;
    char fechaVenta[2000];
    char tipoFoto[2000];
    int cantidad;
    float precioUnitario;
    char cuitCliente[2000];
}Venta;

Venta* venta_new();
void venta_delete(Venta* this);

Venta* venta_newConParametros( char* idVenta,char* fechaVenta,
                                char* tipoFoto,char* cantidad,char* precioUnitario,char* cuitCliente);

int venta_setIdVenta(Venta* this,char* idVenta);
int venta_getIdVenta(Venta* this,int* idVenta);

int venta_setFechaVenta(Venta* this,char* fechaVenta);
int venta_getFechaVenta(Venta* this,char* fechaVenta);

int venta_setTipoFoto(Venta* this,char* tipoFoto);
int venta_getTipoFoto(Venta* this,char* tipoFoto);

int venta_setPrecioUnitario(Venta* this,char* precioUnitario);
int venta_getPrecioUnitario(Venta* this,float* precioUnitario);

int venta_setCantidad(Venta* this,char* cantidad);
int venta_getCantidad(Venta* this,int* cantidad);

int venta_setCuitCliente(Venta* this,char* cuitCliente);
int venta_getCuitCliente(Venta* this,char* cuitCliente);


int venta_buscarPorId(LinkedList* listaVentas, int idVenta);
int venta_generarArchivo(char* fileName,LinkedList* lista);
int venta_cantidadAContarTotal(void* pElement);
int venta_cantidadAContarMayor150(void* pElement);
int venta_cantidadAContarMayor300(void* pElement);
int venta_cantidadPolaroid(void* pElement);

#endif // VENTAS_H_INCLUDED
