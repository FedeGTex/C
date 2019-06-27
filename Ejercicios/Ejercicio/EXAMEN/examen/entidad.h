#ifndef ENTIDAD_H_INCLUDED
#define ENTIDAD_H_INCLUDED

typedef struct{
    int id;
    char tipo[1024];
    int cantidad;
    float peso;
}Entidad;


Entidad* Entidad_new();
void Entidad_delete();
Entidad* Entidad_newConParametros(int id,char* tipo,int cantidad,float peso);

int Entidad_setId(Entidad* this,int id);
int Entidad_getId(Entidad* this,int* id);

int Entidad_setTipo(Entidad* this,char* nombre);
int Entidad_getTipo(Entidad* this,char* nombre);

int Entidad_setCantidad(Entidad* this,int cantidad);
int Entidad_getCantidad(Entidad* this,int* cantidad);

int Entidad_setPeso(Entidad* this,float peso);
int Entidad_getPeso(Entidad* this,float* peso);

void Entidad_Mostrar(void* pEntidad);
int Entidad_cantidadTotalDeEntregas(void* pElement);

#endif // ENTIDAD_H_INCLUDED
