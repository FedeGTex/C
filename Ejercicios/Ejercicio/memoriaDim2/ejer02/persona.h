#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct{
    int id;
    char nombre[32];
    char apellido[32];
    int edad;
}Persona;


Persona* Persona_new();
void Persona_delete(Persona* this);
Persona* Persona_newConParametros(int id,char*nombre,char* apellido,int edad);

int Persona_setId(Persona* this,int id);
int Persona_getId(Persona* this,int* id);

int Persona_setNombre(Persona* this,char* nombre);
int Persona_getNombre(Persona* this,char* nombre);

int Persona_setApellido(Persona* this,char* apellido);
int Persona_getApellido(Persona* this,char* apellido);

int Persona_setEdad(Persona* this,int edad);
int Persona_getEdad(Persona* this,int* edad);

int Persona_buscarLugarVacio(Persona* arrayPersona[], int limite);
int Persona_inicializarArray(Persona* arrayPersona[], int limite);

int Persona_alta(Persona* arrayPersona,int limite);
void Persona_mostrar(Persona* this);

#endif // PERSONA_H_INCLUDED
