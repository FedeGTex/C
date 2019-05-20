#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int informes_listarOrquestaConMusicosPorId(Orquesta* pOrquesta,int limiteO,Musico* pMusico,int limiteM,int id);
int informes_listarMusicosPorTipoDeInstrumento(Musico* pMusico,int limiteM,Instrumento* pInstrumento,int limiteI,int tipo);



#endif // INFORMES_H_INCLUDED
