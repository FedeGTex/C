#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include "Ventas.h"
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "utn.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
*
 * \param path FILE* puntero al archivo a leer
 * \param pArrayListEmployee LinkedList* puntero a linkedlist
 * \return int 0 todo bien -1 error al guardar
 *
 */
int parser_VentasFromText(FILE* pFile , LinkedList* this)
{
    int retorno=-1;
    char bufferId[500];
    char bufferFecha[1200];
    char bufferTipoFoto[1200];
    char bufferCantidad[1200];
    char bufferPrecio[1200];
    char bufferCuit[1200];
    int flagOnce=0;
    Venta* pVenta;
    if(pFile != NULL && this != NULL){
        retorno=0;
        do{
            if(!flagOnce){
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,]%[^\n]\n",bufferId,bufferFecha,bufferTipoFoto,bufferCantidad,bufferPrecio,bufferCuit);
                flagOnce=1;
            }
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,]%[^\n]\n",bufferId,bufferFecha,bufferTipoFoto,bufferCantidad,bufferPrecio,bufferCuit);
            pVenta=Ventas_newConParametros(atoi(bufferId),bufferFecha,bufferTipoFoto,atoi(bufferCantidad),atof(bufferPrecio),bufferCuit);
            if(pVenta!=NULL){
                ll_add(this,pVenta);
            }else{
                printf("%s,%s,%s,%s,%s,%s\n",bufferId,bufferFecha,bufferTipoFoto,bufferCantidad,bufferPrecio,bufferCuit);
                getchar();
            }
        }while(!feof(pFile));
    }
    return retorno;
}
