#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "LinkedList.h"
#include "entregas.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param this LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* this)
{
    int ret=0;
    FILE* pFile;
    pFile = fopen(path,"r");
    ret=parser_EntregasFromText(pFile, this);
    fclose(pFile);
    return ret;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param this LinkedList*
 * \return int
 *
 */
int controller_ListEntregas(LinkedList* this)
{
    int i;
    int ret=0;
    int len;
    if(this!=NULL)
    {
        if(ll_len(this)>0)
        {
            len=ll_len(this);
            for(i=0; i<len; i++)
            {
                controller_PrintEntregas(this,i);
            }
            ret=0;
        }
        else
        {
            printf("No existen registros cargados.");
        }
    }
    return ret;
}
/** \brief Imprime un empleado
 *
 * \param path char*
 * \param this LinkedList*
 * \param index int
 * \return int
 *
 */
int controller_PrintEntregas(LinkedList* this, int index)
{
    Entregas* bufferEntregas;
    int bufferId;
    char bufferTipo[4096];
    int bufferCantidad;
    float bufferPeso;
    int ret=0;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        bufferEntregas=(Entregas*)ll_get(this,index);
        entregas_getId(bufferEntregas,&bufferId);
        entregas_getTipo(bufferEntregas,bufferTipo);
        entregas_getCantidad(bufferEntregas,&bufferCantidad);
        entregas_getPeso(bufferEntregas,&bufferPeso);
        printf("%d,%s,%d,%f\n",bufferId,bufferTipo,bufferCantidad,bufferPeso);
        ret=0;
    }
    return ret;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param this LinkedList*
 * \return int
 *
 */

/*********************
Informe de ventas
********************
- Cantidad total de entregas: XX
- Cantidad de entregas por tipo: XX (STD) - XX (EXP) - XX (ECO)
- Cantidad maxima de bultos entregados: XX
- Promedio de bultos por entrega: XX
- Peso promedio por entrega: XX
*********************/
int controller_saveAsText(char* path, LinkedList* this)
{
    Entregas* bufferEntregas;
    FILE* pf;
    char bufferTipo[128];
    int bufferCantidad;
    float bufferPeso;

    int cantidadTotal=0;
    int cantidadSTD=0;
    int cantidadEXP=0;
    int cantidadECO=0;
    int cantidadMaxima=0;
    float cantidadPromedio=0;
    float pesoPromedio=0;
    int i;
    int ret=0;
    int len;
    pf=fopen(path,"w");
    if(this!=NULL && pf!=NULL)
    {

        len=ll_len(this);
        for(i=0; i<len; i++)
        {
            bufferEntregas=(Entregas*)ll_get(this,i);
            entregas_getTipo(bufferEntregas,bufferTipo);
            entregas_getCantidad(bufferEntregas,&bufferCantidad);
            entregas_getPeso(bufferEntregas,&bufferPeso);

            cantidadTotal=cantidadTotal+bufferCantidad;
            pesoPromedio=pesoPromedio+bufferPeso;
            if(!strcmp(bufferTipo,"STD"))
            {
                cantidadSTD=cantidadSTD+1;
            }
            if(!strcmp(bufferTipo,"EXP"))
            {
                cantidadEXP=cantidadEXP+1;
            }
            if(!strcmp(bufferTipo,"ECO"))
            {
                cantidadECO=cantidadECO+1;
            }
            if(cantidadMaxima<bufferCantidad)
            {
                cantidadMaxima=bufferCantidad;
            }

        }
        cantidadPromedio=(float) cantidadTotal/len;
        pesoPromedio=pesoPromedio/len;
        fprintf(pf,"/*********************\n");
        fprintf(pf,"Informe de ventas\n");
        fprintf(pf,"********************\n");
        fprintf(pf,"- Cantidad total de entregas: %d\n",cantidadTotal);
        fprintf(pf,"- Cantidad de entregas por tipo: %d (STD) - %d (EXP) - %d (ECO)\n",   cantidadSTD,
                                                                                        cantidadEXP,
                                                                                        cantidadECO);
        fprintf(pf,"- Cantidad maxima de bultos entregados: %d\n",cantidadMaxima);
        fprintf(pf,"- Promedio de bultos por entrega: %.2f\n",cantidadPromedio);
        fprintf(pf,"- Peso promedio por entrega: %.2f\n",pesoPromedio);
        fprintf(pf,"*********************/\n");
        fclose(pf);
    }
    return ret;
}
