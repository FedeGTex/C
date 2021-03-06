#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"
#include "informes.h"
#define QTY_ORQUESTA 50
#define QTY_MUSICO 20
#define QTY_INSTRUMENTO 1000


int main()
{

    int menu;
    int auxiliarId;
    int respuesta;
    char lugar[21];
    //int auxTipo;

    Orquesta pOrquesta[QTY_ORQUESTA];
    Musico pMusico[QTY_MUSICO];
    Instrumento pInstrumento[QTY_INSTRUMENTO];


    orquesta_init(pOrquesta,QTY_ORQUESTA);
    musico_init(pMusico,QTY_MUSICO);
    instrumento_init(pInstrumento,QTY_INSTRUMENTO);

    orquesta_altaForzada(pOrquesta,QTY_ORQUESTA,"Orquesta1","Lugar1",1);
    orquesta_altaForzada(pOrquesta,QTY_ORQUESTA,"Orquesta2","Lugar1",1);
    orquesta_altaForzada(pOrquesta,QTY_ORQUESTA,"Orquesta3","Lugar2",1);
    orquesta_altaForzada(pOrquesta,QTY_ORQUESTA,"Orquesta4","Lugar3",1);

    musico_altaForzada(pMusico,QTY_MUSICO,"Mus1","Amus1",30,1,2);
    musico_altaForzada(pMusico,QTY_MUSICO,"Mus2","Amus2",20,2,5);
    musico_altaForzada(pMusico,QTY_MUSICO,"Mus3","Amus3",25,4,2);
    musico_altaForzada(pMusico,QTY_MUSICO,"Mus4","Amus4",27,4,1);
    musico_altaForzada(pMusico,QTY_MUSICO,"Mus5","Amus5",22,1,3);
    musico_altaForzada(pMusico,QTY_MUSICO,"Mus6","Amus6",35,3,4);

    instrumento_altaForzada(pInstrumento,QTY_INSTRUMENTO,"Inst1",1);
    instrumento_altaForzada(pInstrumento,QTY_INSTRUMENTO,"Inst2",2);
    instrumento_altaForzada(pInstrumento,QTY_INSTRUMENTO,"Inst3",2);
    instrumento_altaForzada(pInstrumento,QTY_INSTRUMENTO,"Inst4",3);
    instrumento_altaForzada(pInstrumento,QTY_INSTRUMENTO,"Inst4",4);


    do
    {
        utn_getEntero(&menu,3,"\n1.Agregar orquesta\n2.Eliminar orquesta\n3.Imprimir orquesta\n4.Agregar musico\n5.Modificar musico\n6.Eliminar musico\n7.Imprimir musicos\n8.Agregar instrumento\n9.Imprimir instrumento\n10.Orquesta con mas de 5 musicos\n11.Musicos mayores a 30\n12.Orquesta de un lugar determinado\n13.Orquesta completa\n14.Musicos de orquestas\n15.Orquesta con mas musicos\n16.Musicos que tocan cuerda\n17.Promedio.\n","\nNo valida\n",1,31);
        switch(menu)
        {
            case 1:
                orquesta_alta(pOrquesta,QTY_ORQUESTA);
                break;
            case 2:
                orquesta_mostrar(pOrquesta,QTY_ORQUESTA);
                utn_getEntero(&auxiliarId,3,"\nIngrese la id de la orquesta que desea eliminar\n","Ingrese una id valida!",1,50);
                if(!utn_getEntero(&respuesta,2,"\nDesea eliminar la orquesta junto con todos los musicos?\n\n1.Eliminar.\n2.No eliminar.\n","No es una opcion correcta\n",1,2))
                {
                    if(respuesta==1)
                    {
                        orquesta_baja(pOrquesta,QTY_ORQUESTA,auxiliarId);
                        musico_bajaPorOrquesta(pMusico,QTY_MUSICO,auxiliarId);
                    }
                }
                break;
            case 3:
                orquesta_mostrar(pOrquesta,QTY_ORQUESTA);
                break;
            case 4:
                musico_alta(pMusico,QTY_MUSICO,pOrquesta,QTY_ORQUESTA,pInstrumento,QTY_INSTRUMENTO);
                break;
            case 5:
                musico_mostrar(pMusico,QTY_MUSICO);
                if(!utn_getEntero(&auxiliarId,3,"\nIngrese la id del musico que desea modificar\n","Ingrese una id valida!",1,1000))
                {
                    musico_modificacion(pMusico,QTY_MUSICO,auxiliarId);
                }
                break;
            case 6:
                musico_mostrar(pMusico,QTY_MUSICO);
                utn_getEntero(&auxiliarId,3,"\nIngrese la id del musico que desea eliminar\n","Ingrese una id valida!",1,1000);
                if(!utn_getEntero(&respuesta,2,"\nIngrese el numero de la opcion que desea realizar?\n\n1.Eliminar.\n2.No eliminar.\n","No es una opcion correcta\n",1,2))
                {
                    if(respuesta==1)
                    {
                        musico_baja(pMusico,QTY_MUSICO,auxiliarId);
                    }
                }
                break;
            case 7:
                musico_mostrar(pMusico,QTY_MUSICO);//modificar para que imprima nombre y tipo de instrumento
                break;
            case 8:
                instrumento_alta(pInstrumento,QTY_INSTRUMENTO);
                break;
            case 9:
                instrumento_mostrar(pInstrumento,QTY_INSTRUMENTO);
                break;
            case 10:
                informes_orquestaMasDe5Musicos(pOrquesta,QTY_ORQUESTA,pMusico,QTY_MUSICO);
                break;
            case 11:
                informes_listarMusicosMasDe30Anios(pMusico,QTY_MUSICO,pOrquesta,QTY_ORQUESTA,pInstrumento,QTY_INSTRUMENTO);
                break;
            case 12:
                orquesta_mostrar(pOrquesta,QTY_ORQUESTA);
                if(!utn_getLetrasYNumeros(lugar,20,"\nIngrese un lugar: "))
                {
                    informes_listarOrquestasDeUnLugarDeterminado(pOrquesta,QTY_ORQUESTA,lugar);
                }
                else
                {
                    printf("\nNo hay orquestas en ese lugar!");
                }
                break;
            case 13:
                informes_orquestaCompleta(pOrquesta,QTY_ORQUESTA,pMusico,QTY_MUSICO,pInstrumento,QTY_INSTRUMENTO);
                break;
            case 14:
                orquesta_mostrar(pOrquesta,QTY_ORQUESTA);
                if(!utn_getEntero(&auxiliarId,3,"\nIngrese la id de la orquesta\n","Ingrese una id valida!",1,1000))
                {
                    informes_listarOrquestaConMusicosPorId(pOrquesta,QTY_ORQUESTA,pMusico,QTY_MUSICO,auxiliarId);
                }
                break;
            case 15:
                informes_orquesta_con_mas_musicos(pOrquesta,QTY_ORQUESTA,pMusico,QTY_MUSICO);
                break;
            case 16:
                informes_listarMusicosCuerda(pMusico,QTY_MUSICO,pInstrumento,QTY_INSTRUMENTO);
                break;
            case 17:
                informes_imprimirPromedioMusicosPorOrquesta(pOrquesta,QTY_ORQUESTA,pMusico,QTY_MUSICO);
                break;
        }

    }while(menu != 30);

    return 0;
}
