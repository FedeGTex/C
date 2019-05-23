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

    orquesta_altaForzada(pOrquesta,QTY_ORQUESTA,"Orquesta Chistosa","Boedo",2);
    orquesta_altaForzada(pOrquesta,QTY_ORQUESTA,"Orquesta Matematica","Belgrano",1);
    orquesta_altaForzada(pOrquesta,QTY_ORQUESTA,"Orquesta Quilombera","Caballito",1);
    orquesta_altaForzada(pOrquesta,QTY_ORQUESTA,"Orquesta Silenciosa","Constitucion",3);
    orquesta_altaForzada(pOrquesta,QTY_ORQUESTA,"Orquesta Muda","Bernal",2);

    musico_altaForzada(pMusico,QTY_MUSICO,"Gonzalo","Perez",22,1,1);
    musico_altaForzada(pMusico,QTY_MUSICO,"Federico","Gonzalez",31,1,2);
    musico_altaForzada(pMusico,QTY_MUSICO,"Miriam","Martinez",33,1,3);
    musico_altaForzada(pMusico,QTY_MUSICO,"Romina","Gomez",40,1,4);
    musico_altaForzada(pMusico,QTY_MUSICO,"Ariel","Dominguez",18,1,5);
    musico_altaForzada(pMusico,QTY_MUSICO,"Gabriel","Gimenez",54,1,2);
    musico_altaForzada(pMusico,QTY_MUSICO,"Sergio","Az",22,1,1);
    musico_altaForzada(pMusico,QTY_MUSICO,"Carlos","Pe",31,1,2);
    musico_altaForzada(pMusico,QTY_MUSICO,"Jessica","Ka",33,1,3);
    musico_altaForzada(pMusico,QTY_MUSICO,"Sabrina","Te",40,1,4);
    musico_altaForzada(pMusico,QTY_MUSICO,"Emanuel","Zi",18,1,5);
    musico_altaForzada(pMusico,QTY_MUSICO,"Sebastian","Mu",54,1,2);
     musico_altaForzada(pMusico,QTY_MUSICO,"Gabriel","Gimenez",54,1,2);
    musico_altaForzada(pMusico,QTY_MUSICO,"Sergio","Az",22,1,1);
    musico_altaForzada(pMusico,QTY_MUSICO,"Carlos","Pe",31,2,2);
    musico_altaForzada(pMusico,QTY_MUSICO,"Jessica","Ka",33,3,3);
    musico_altaForzada(pMusico,QTY_MUSICO,"Sabrina","Te",40,2,4);
    musico_altaForzada(pMusico,QTY_MUSICO,"Emanuel","Zi",18,2,5);
    musico_altaForzada(pMusico,QTY_MUSICO,"Sebastian","Mu",54,2,2);
     musico_altaForzada(pMusico,QTY_MUSICO,"Gabriel","Gimenez",54,2,2);
    musico_altaForzada(pMusico,QTY_MUSICO,"Sergio","Az",22,1,1);
    musico_altaForzada(pMusico,QTY_MUSICO,"Carlos","Pe",31,2,2);
    musico_altaForzada(pMusico,QTY_MUSICO,"Jessica","Ka",33,3,3);
    musico_altaForzada(pMusico,QTY_MUSICO,"Sabrina","Te",40,2,4);
    musico_altaForzada(pMusico,QTY_MUSICO,"Emanuel","Zi",18,2,5);
    musico_altaForzada(pMusico,QTY_MUSICO,"Sebastian","Mu",54,2,2);
     musico_altaForzada(pMusico,QTY_MUSICO,"Gabriel","Gimenez",54,2,2);
    musico_altaForzada(pMusico,QTY_MUSICO,"Sergio","Az",22,1,1);
    musico_altaForzada(pMusico,QTY_MUSICO,"Carlos","Pe",31,2,2);
    musico_altaForzada(pMusico,QTY_MUSICO,"Jessica","Ka",33,3,3);
    musico_altaForzada(pMusico,QTY_MUSICO,"Sabrina","Te",40,2,4);
    musico_altaForzada(pMusico,QTY_MUSICO,"Emanuel","Zi",18,2,5);
    musico_altaForzada(pMusico,QTY_MUSICO,"Sebastian","Mu",54,2,2);

    instrumento_altaForzada(pInstrumento,QTY_INSTRUMENTO,"Tambor",4);
    instrumento_altaForzada(pInstrumento,QTY_INSTRUMENTO,"Arpa",1);
    instrumento_altaForzada(pInstrumento,QTY_INSTRUMENTO,"Flauta",2);
    instrumento_altaForzada(pInstrumento,QTY_INSTRUMENTO,"Trompeta",3);
    instrumento_altaForzada(pInstrumento,QTY_INSTRUMENTO,"Clarinete",3);
    instrumento_altaForzada(pInstrumento,QTY_INSTRUMENTO,"Bateria",4);
    instrumento_altaForzada(pInstrumento,QTY_INSTRUMENTO,"Tambor",4);
    instrumento_altaForzada(pInstrumento,QTY_INSTRUMENTO,"Arpa",1);
    instrumento_altaForzada(pInstrumento,QTY_INSTRUMENTO,"Flauta",2);
    instrumento_altaForzada(pInstrumento,QTY_INSTRUMENTO,"Trompeta",3);
    instrumento_altaForzada(pInstrumento,QTY_INSTRUMENTO,"Clarinete",3);
    instrumento_altaForzada(pInstrumento,QTY_INSTRUMENTO,"Bateria",4);


    do
    {
        utn_getEntero(&menu,3,"\n1.Agregar orquesta\n2.Eliminar orquesta\n3.Imprimir orquesta\n4.Agregar musico\n5.Modificar musico\n6.Eliminar musico\n7.Imprimir musicos\n8.Agregar instrumento\n9.Imprimir instrumento\n10.Salir.\n","\nNo valida\n",1,31);
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
                if(!utn_getLetras(lugar,20,2,"\nIngrese un lugar: ","\nIngrese un lugar valido!"))
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
