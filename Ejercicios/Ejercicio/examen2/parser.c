#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "entregas.h"
/** \brief Parsea los datos de los entregas desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param this LinkedList*
 * \return int
 *
 */
int parser_EntregasFromText(FILE* pFile, LinkedList* this)
{
    int ret= 0;
    Entregas *pElement;
    char bufferId[4096];
    char bufferTipo[4096];
    char bufferCantidad[4096];
    char bufferPeso[4096];

    if(pFile!=NULL && this!=NULL)
    {
        fscanf(pFile,"[^\n]\n");
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,bufferTipo,bufferCantidad,bufferPeso);

            pElement = entregas_newParametros(bufferId,bufferTipo,bufferCantidad,bufferPeso);

            if(pElement != NULL)
            {
                if(!ll_add(this,pElement))
                {
                    ret++;
                }
            }
        }
    }
    return ret;
}

