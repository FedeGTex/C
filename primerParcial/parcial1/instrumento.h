#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

typedef struct{
    int isEmpty;
    int idInstrumento;
    char nombre[31];
    int tipo;
}Instrumento;


int instrumento_init(Instrumento* array,int limite);
int instrumento_mostrar(Instrumento* array,int limite);
int instrumento_alta(Instrumento* array,int limite);
int instrumento_baja(Instrumento* array,int limite, int id);
int instrumento_modificacion(Instrumento* array,int limite, int id);
int instrumento_ordenar(Instrumento* array,int limite, int orden);
int instrumento_buscarPorId(Instrumento* array,int limite, int id);
int instrumento_altaForzada(Instrumento* array,int limite,char* nombre,int tipo);



int instrumento_retornarTipoPorId(Instrumento* pInstrumento,int limiteI,int id);


#endif // INSTRUMENTO_H_INCLUDED
