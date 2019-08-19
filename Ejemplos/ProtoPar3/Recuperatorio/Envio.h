#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#include "LinkedList.h"

typedef struct{
    int idEnvio;
    char nombreProducto[2000];
    int kmRecorrido;
    int tipoProducto;
    int costo;
}Envio;

Envio* Envios_new();
void Envios_delete();
Envio* Envios_newConParametros(char*idEnvio,char*nombreProducto,char*kmRecorrido,char*tipoProducto);

int Envios_setId_Envio(Envio* this,char* idEnvio);
int Envios_getId_Envio(Envio* this,int* idEnvio);

int Envios_setNombre_producto(Envio* this,char* nombreProducto);
int Envios_getNombre_producto(Envio* this,char* nombreProducto);

int Envios_setKm_recorrido(Envio* this,char* kmRecorrido);
int Envios_getKm_recorrido(Envio* this,int* kmRecorrido);

int Envios_setTipo_producto(Envio* this,char* tipoProducto);
int Envios_getTipo_producto(Envio* this,int* tipoProducto);


int Envios_Mostrar(void* pEnvio);
int Envios_MostrarFile(void* pEnvio,FILE* pFile);

int calcularCosto(void* pEnvio);

int Envios_fprinf(void* pEnvio,FILE* pFile);

int Envio_generarArchivo1(char* fileName,LinkedList* lista);



#endif // VENTAS_H_INCLUDED
