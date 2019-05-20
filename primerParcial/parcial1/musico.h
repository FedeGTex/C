#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED
#include "instrumento.h"
#include "orquesta.h"

typedef struct{
    int isEmpty;
    int idMusico;
    char nombre[31];
    char apellido[31];
    int edad;
    int idOrquesta;
    int idInstrumento;
}Musico;


int musico_init(Musico* arrayMusico,int limite);
int musico_mostrar(Musico* arrayMusico,int limite);
int musico_alta(Musico* arrayMusico,int limite,Orquesta* arrayOrquesta,int limiteOrquesta,Instrumento* arrayInstrumento,int limiteInstrumento);
int musico_baja(Musico* arrayMusico,int limite, int id);
int musico_modificacion(Musico* arrayMusico,int limite, int id);
int musico_ordenar(Musico* arrayMusico,int limite, int orden);
int musico_buscarPorId(Musico* arrayMusico,int limite, int id);
int musico_altaForzada(Musico* arrayMusico,int limite,char* nombre,char* apellido,int edad,int idOrquesta,int idInstrumento);
int musico_bajaPorOrquesta(Musico* arrayMusico,int limite,int id);
int musicos_listarPorOrquesta(Musico* pMusico,int limite,int id);

#endif // MUSICO_H_INCLUDED
