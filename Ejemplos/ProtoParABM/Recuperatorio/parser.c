#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include "Envio.h"
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
int parser_EnvioFromText(FILE* pFile , LinkedList* this)
{
    int retorno=-1;
    char bufferId[500];
    char bufferNombre[1200];
    char bufferKm[1200];
    char bufferTipo[1200];
    int flagOnce=0;
    Envio* pEnvio;
    if(pFile != NULL && this != NULL){
        retorno=0;
        do{
            if(!flagOnce){
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferKm,bufferTipo);
                flagOnce=1;
            }
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferKm,bufferTipo);
            pEnvio=Envios_newConParametros(bufferId,bufferNombre,bufferKm,bufferTipo);
            if(pEnvio!=NULL){
                ll_add(this,pEnvio);
                //Ventas_Mostrar(pVenta);
                //getchar();
            }else{
                printf("%s,%s,%s,%s\n",bufferId,bufferNombre,bufferKm,bufferTipo);
                //getchar();
            }
        }while(!feof(pFile));
    }
    return retorno;
}
