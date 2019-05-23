#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int informes_listarOrquestaConMusicosPorId(Orquesta* pOrquesta,int limiteO,Musico* pMusico,int limiteM,int id);
int informes_listarMusicosPorTipoDeInstrumento(Musico* pMusico,int limiteM,Instrumento* pInstrumento,int limiteI,int tipo);
int informes_orquesta_cant_musicos(int idOrquesta,Musico* pMusico,int limiteMusico);
int informes_orquesta_con_mas_musicos(Orquesta* pOrquesta,int limiteO,Musico* pMusico,int limiteM);



int informes_orquestaConMasDe5(Orquesta* pOrquesta,int limiteO,Musico* pMusico,int limiteM);
int informes_cant_musicosMas30(Musico* pMusico,int limiteM);
int informes_orquestasDeUnLugar(Orquesta* pOrquesta,int limite,int lugar);

#endif // INFORMES_H_INCLUDED
