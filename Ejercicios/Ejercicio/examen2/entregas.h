#ifndef Entregas_H_INCLUDED
#define Entregas_H_INCLUDED
typedef struct
{
    int id;
    char tipo[128];
    int cantidad;
    float peso;
}Entregas;

void entregas_idInit(int id);
int entregas_idGenerator();

Entregas* entregas_new();
int entregas_delete(Entregas* this);

int entregas_setIdStr(Entregas* this,char* idStr);
int entregas_setId(Entregas* this,int id);
int entregas_getId(Entregas* this,int* id);
int entregas_compareId(void* pEntregasA,void* pEntregasB);

int entregas_setTipo(Entregas* this,char* entregas);
int entregas_getTipo(Entregas* this,char* entregas);

int entregas_setCantidadStr(Entregas* this,char* cantidadStr);
int entregas_setCantidad(Entregas* this,int cantidad);
int entregas_getCantidad(Entregas* this,int* cantidad);
int entregas_compareCantidad(void* pEntregasA,void* pEntregasB);

int entregas_setPesoStr(Entregas* this,char* pesoStr);
int entregas_setPeso(Entregas* this,float peso);
int entregas_getPeso(Entregas* this,float* peso);
int entregas_comparePeso(void* pEntregasA,void* pEntregasB);

Entregas* entregas_newParametros(char* idStr,char* tipoStr,char* cantidadStr,char* pesoStr);


#endif
