#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#define QTY_PERSONA 1000

int main()
{
    Persona* arrayPersona[QTY_PERSONA];
    /*Persona* arrayPersona[QTY_ARRAYPER];
    persona_initArray(arrayPersona,QTY_ARRAYPER);
    persona_addPersona(arrayPersona,QTY_ARRAYPER,"\nDATO NO VALIDO\n",3);
    */

    parserPersona("data.csv",arrayPersona,QTY_PERSONA);

    return 0;
}
