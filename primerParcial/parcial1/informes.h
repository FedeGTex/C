#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int informes_listarOrquestaConMusicosPorId(Orquesta* pOrquesta,int limiteO,Musico* pMusico,int limiteM,int id);
int informes_listarMusicosPorTipoDeInstrumento(Musico* pMusico,int limiteM,Instrumento* pInstrumento,int limiteI,int tipo);
int informes_orquesta_cant_musicos(int idOrquesta,Musico* pMusico,int limiteMusico);
int informes_orquesta_con_mas_musicos(Orquesta* pOrquesta,int limiteO,Musico* pMusico,int limiteM);

//InformesParcial
int informes_orquestaMasDe5Musicos(Orquesta* pOrquesta,int limiteO,Musico* pMusico,int limiteM);
int informes_listarMusicosMasDe30Anios(Musico* pMusico,int limiteM,Orquesta* pOrquesta,int limiteO,Instrumento* pInstrumento,int limiteI);
int informes_listarOrquestasDeUnLugarDeterminado(Orquesta* pOrquesta,int limiteO,char* lugar);
int informes_orquestaCompleta(Orquesta* pOrquesta,int limiteO,Musico* pMusico,int limiteM,Instrumento* pInstrumento,int limiteI);
int informes_listarMusicosCuerda(Musico* pMusico,int limiteM,Instrumento* pInstrumento,int limiteI);
int informes_imprimirPromedioMusicosPorOrquesta(Orquesta* pOrquesta,int limiteO,Musico* pMusico,int limiteM);

#endif // INFORMES_H_INCLUDED
