#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"

int main()
{
    /*Persona* arrayPersona[QTY_ARRAYPER];
    persona_initArray(arrayPersona,QTY_ARRAYPER);
    persona_addPersona(arrayPersona,QTY_ARRAYPER,"\nDATO NO VALIDO\n",3);
    */
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferApellido[1024];
    char bufferEdad[1024];
    int lenList=0;
    int i=0;
    FILE *pArchivo;
    Persona* pListaPersona[1000];
    pArchivo= fopen("data.csv","r");
    if(pArchivo!= NULL)
    {

        do{
            fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferApellido,bufferEdad);
            //printf("\n%s %s %s %s\n",bufferId,bufferNombre,bufferApellido,bufferEdad);
            pListaPersona[lenList]=persona_newParametros(bufferId,bufferNombre,bufferApellido,bufferEdad);
            if(pListaPersona!=NULL)
            {
                lenList++;
            }
        }while(!feof(pArchivo));
        for(i=0;i<lenList;i++)
        {
            printf("%d - %s - %s - %d\n",pListaPersona[i]->id,pListaPersona[i]->nombre,pListaPersona[i]->apellido,pListaPersona[i]->edad);
        }
        fclose(pArchivo);
    }

    return 0;
}
