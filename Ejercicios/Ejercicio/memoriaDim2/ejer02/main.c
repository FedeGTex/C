//#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "persona.h"
#define QTY_PERSONA 1002

int main()
{
    int menu;
    //char* nombre[50];
    Persona* arrayPersona[QTY_PERSONA];
    persona_initArray(arrayPersona,QTY_PERSONA);
    /*Persona* arrayPersona[QTY_ARRAYPER];
    persona_initArray(arrayPersona,QTY_ARRAYPER);
    persona_addPersona(arrayPersona,QTY_ARRAYPER,"\nDATO NO VALIDO\n",3);
    */
    do
    {
        utn_getEntero(&menu,2,"\n1)Cargar Persona\n2)Alta Persona: \n3)Guargar texto \n4) \n5) \n6 \n7)\n8)Salir\n","Ingrese opcion valida!",1,11);
       switch(menu)
       {
            case 1:
                parserPersona("data.csv",arrayPersona,QTY_PERSONA);
                break;
            case 2:

                //persona_getNombre(arrayPersona[1],nombre);
                //printf("%s",nombre);
               persona_addPersona(arrayPersona,QTY_PERSONA);
                break;
            case 3:
                persona_guardarTexto(arrayPersona,QTY_PERSONA,"data2.csv");
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
       }
    }while(menu!=8);

    return 0;
}
