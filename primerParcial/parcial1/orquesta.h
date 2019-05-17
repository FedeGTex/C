#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED

typedef struct{
    int isEmpty;
    int idOrquesta;
    char nombre[31];
    char lugar[31];
    int tipo;
}Orquesta;


int orquesta_init(Orquesta* array,int limite);
int orquesta_mostrar(Orquesta* array,int limite);
int orquesta_alta(Orquesta* array,int limite);
int orquesta_baja(Orquesta* array,int limite, int id);
int orquesta_modificacion(Orquesta* array,int limite, int id);
int orquesta_ordenar(Orquesta* array,int limite, int orden);
int orquesta_buscarPorId(Orquesta* array,int limite, int id);
int orquesta_altaForzada(Orquesta* array,int limite,char* nombre,char* lugar,int tipo);


#endif // ORQUESTA_H_INCLUDED
