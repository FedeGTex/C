//#include "stdio.h"
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "persona.h"
#include "utn.h"
#define QTY_PERSONA 100


int main()
{
    Persona* listaPersona[QTY_PERSONA];
    Persona* auxPersona;
    //char nombreAux[31];
    //int indexVacio;

    Persona_inicializarArray(listaPersona,QTY_PERSONA);
    auxPersona=Persona_new();
    //indexVacio=Persona_buscarLugarVacio(listaPersona,QTY_PERSONA);
    if(auxPersona!=NULL)
    {
        Persona_alta(auxPersona,QTY_PERSONA);
        Persona_mostrar(auxPersona);
        //Persona_setNombre(auxPersona,"Juan");
        //listaPersona[indexVacio]=auxPersona;
        //Persona_getNombre(listaPersona[indexVacio],nombreAux);
        //printf("%s",nombreAux);
    }
    return 0;
}
