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

Venta* Ventas_new();
void Ventas_delete();
Venta* Ventas_newConParametros(char*idVenta,char*fechaVenta,char*tipoFoto,char*cantidad,char*precioUnitario,char*cuitCliente);

int Ventas_setId_Venta(Venta* this,char* idVenta);
int Ventas_getId_Venta(Venta* this,int* idVenta);

int Ventas_setFecha_Venta(Venta* this,char* fechaVenta);
int Ventas_getFecha_Venta(Venta* this,char* fechaVenta);

int Ventas_setTipoFoto(Venta* this,char* tipoFoto);
int Ventas_getTipoFoto(Venta* this,char* tipoFoto);

int Ventas_setCantidad(Venta* this,char* cantidad);
int Ventas_getCantidad(Venta* this,int* cantidad);

int Ventas_setPrecio_Unitario(Venta* this,char* precioUnitario);
int Ventas_getPrecio_Unitario(Venta* this,float* precioUnitario);

int Ventas_setCuit_Cliente(Venta* this,char* cuitCliente);
int Ventas_getCuit_Cliente(Venta* this,char* cuitCliente);

int Ventas_Mostrar(void* pVenta);
int venta_buscarPorId(LinkedList* listaVentas, int idVenta);
int venta_generarArchivo(char* fileName,LinkedList* lista);
int venta_cantidadAContarTotal(void* pElement);
int venta_cantidadAContarMayor150(void* pElement);
int venta_cantidadAContarMayor300(void* pElement);
int venta_cantidadPolaroid(void* pElement);

#endif // VENTAS_H_INCLUDED
