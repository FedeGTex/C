#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#include "LinkedList.h"

typedef struct{
    int idLlamada;
    char fechaLlamada[2000];
    int numeroCliente;
    int idProblema;
    char solucionado[2000];
}Llamada;

Llamada* Llamadas_new();
void Llamadas_delete();
Llamada* Llamadas_newConParametros(char*idLlamada,char*fechaLlamada,char*numeroCliente,char*idProblema,char*solucionado);

int Llamadas_setId_Llamada(Llamada* this,char* idLlamada);
int Llamadas_getId_Llamada(Llamada* this,int* idLlamada);

int Llamadas_setFecha_Llamada(Llamada* this,char* fechaLlamada);
int Llamadas_getFecha_Llamada(Llamada* this,char* fechaLlamada);

int Llamadas_setNumeroCliente(Llamada* this,char* numeroCliente);
int Llamadas_getNumeroCliente(Llamada* this,int* numeroCliente);

int Llamadas_setId_problema(Llamada* this,char* idProblema);
int Llamadas_getId_problema(Llamada* this,int* idProblema);

int Llamadas_setSolucionado(Llamada* this,char* solucionado);
int Llamadas_getSolucionado(Llamada* this,char* solucionado);

int Llamadas_Mostrar(void* pLlamada);
int Llamadas_MostrarFile(void* pLlamada,FILE* pFile);

int problema1(void* pElement);
int problema2(void* pElement);
int problema3(void* pElement);
int problema4(void* pElement);
int problema5(void* pElement);


int llamada_generarArchivo1(char* fileName,LinkedList* lista);
int llamada_generarArchivo2(char* fileName,LinkedList* lista);
int llamada_generarArchivo3(char* fileName,LinkedList* lista);
int llamada_generarArchivo4(char* fileName,LinkedList* lista);
int llamada_generarArchivo5(char* fileName,LinkedList* lista);


#endif // VENTAS_H_INCLUDED
