#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "entidad.h"
#include "LinkedList.h"
#include "parser.h"

/*********************
Informe de ventas
********************
- Cantidad total de entregas: XX
- Cantidad de entregas por tipo: XX (STD) - XX (EXP) - XX (ECO)
- Cantidad maxima de bultos entregados: XX
- Promedio de bultos por entrega: XX
- Peso promedio por entrega: XX
***/

void main_menu(int* option);
int generarInforme(FILE* pFile,LinkedList* this);
int saveAsText(char* path , LinkedList* this);

int main()
{
    // Definir lista de empleados
    LinkedList* listaEntidad;
    listaEntidad=ll_newLinkedList();

    // Crear lista empledos
    //...

    // Leer empleados de archivo data.csv
    if(parser_parseEntidad("data.csv",listaEntidad)==1)
    {
        // Calcular sueldos
        printf("Calculando total de entregas\n");
        //ll_map(listaEntidad,Entidad_cantidadTotalDeEntregas);

        // Generar archivo de salida
        if(saveAsText("cantidad.csv",listaEntidad)==1)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");
    }
    else
        printf("Error leyando empleados\n");


    return 0;
}




int saveAsText(char* path , LinkedList* this)
{
    FILE*pArchivo;
    int retorno=-1;
    if(path != NULL && this != NULL)
    {
        pArchivo=fopen(path,"w");
        if(pArchivo != NULL && !generarInforme(pArchivo,this))
        {
            fclose(pArchivo);
            printf("Guardado exitoso");
            getchar();
            retorno=0;
        }
        else
        {
            printf("No se pudo abrir el archivo...");
        }
    }
    return retorno;
}

int generarInforme(FILE* pFile,LinkedList* this)
{

    int retorno=-1;
    //int cantidadTotalDeEntregas;
    //int cantidadDeEntregasPorTipo;
    //int cantidadMaximaDeBultosEntregados;
    //int promedioDeBultosPorEntrega;
    //int pesoPromedioPorEntrega;
    if(pFile!=NULL && this!= NULL)
    {
        //cantidadTotalDeEntregas=ll_map(this,Entidad_cantidadTotalDeEntregas);
        fprintf(pFile,"***************************\nInforme\n**************************\n");
        //fprintf(pFile,"-Cantidad total de entregas: %d\n",cantidadTotalDeEntregas);
        fprintf(pFile,"********************************");
        retorno=0;
  }
    return retorno;
}

