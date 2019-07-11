#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include "Llamadas.h"
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
int parser_LlamadasFromText(FILE* pFile , LinkedList* this)
{
    int retorno=-1;
    char bufferId[500];
    char bufferFecha[1200];
    char bufferNumeroCliente[1200];
    char bufferIdProblema[1200];
    char bufferSolucionado[1200];
    int flagOnce=0;
    Llamada* pLlamada;
    if(pFile != NULL && this != NULL){
        retorno=0;
        do{
            if(!flagOnce){
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^,]%[^\n]\n",bufferId,bufferFecha,bufferNumeroCliente,bufferIdProblema,bufferSolucionado);
                flagOnce=1;
            }
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferFecha,bufferNumeroCliente,bufferIdProblema,bufferSolucionado);
            pLlamada=Llamadas_newConParametros(bufferId,bufferFecha,bufferNumeroCliente,bufferIdProblema,bufferSolucionado);
            if(pLlamada!=NULL){
                ll_add(this,pLlamada);
                //Ventas_Mostrar(pVenta);
                //getchar();
            }else{
                printf("%s,%s,%s,%s,%s\n",bufferId,bufferFecha,bufferNumeroCliente,bufferIdProblema,bufferSolucionado);
                //getchar();
            }
        }while(!feof(pFile));
    }
    return retorno;
}
