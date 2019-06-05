//#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "utn.h"

//static int generarId(void);
static int isValidEdad(char* edad);
static int isValidId(char* personaId);

Persona* persona_new()
{
    return (Persona*) malloc(sizeof(Persona));
}

Persona* persona_newParametros(char*id,char* nombre,char* apellido,char* edad)
{
    Persona* per=persona_new();
    if(per!=NULL)
    {

        persona_setId(per,id);
        persona_setNombre(per,nombre);
        persona_setApellido(per,apellido);
        persona_setEdad(per,edad);

    }
    return per;
}

int persona_delete(Persona* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int persona_setId(Persona* this,char* id)
{
    int retorno=-1;
    static int proximoId=-1;
    int idAuxiliar;
    if(this != NULL && isValidId(id)==0)
    {
        idAuxiliar=atoi(id);
        if(idAuxiliar==-1)
        {
            proximoId++;
            this->id=proximoId;
            retorno=0;
        }else if(idAuxiliar>proximoId)
        {
            proximoId=idAuxiliar;
            this->id=proximoId;
            retorno=0;
        }

    }
    return retorno;
}

int persona_setIdString(Persona* this, char* value)
{
    int retorno = -1;
    int auxId;
    if(this != NULL)
    {
        auxId=atoi(value);
        this->id = auxId;
        retorno = 0;
    }
    return retorno;
}



int persona_setEdad(Persona* this, char* value)
{
    int auxEdad;
    int retorno = -1;
    if(this != NULL && !isValidEdad(value))
    {
        auxEdad=atoi(value);
        this->edad = auxEdad;
        retorno = 0;
    }
    return retorno;
}

int persona_setNombre(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(this->nombre,value,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int persona_setApellido(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(this->apellido,value,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}

int persona_getId(Persona* this, int* value)
{
    int retorno = -1;
    if(this != NULL)
    {
        *value = this->id;
        retorno = 0;
    }
    return retorno;
}


int persona_getEdad(Persona* this, int* value)
{
    int retorno = -1;
    if(this != NULL)
    {
        *value = this->edad;
        retorno = 0;
    }
    return retorno;
}

int persona_getNombre(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(value,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int persona_getApellido(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(value,this->apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}

int persona_addPersona(Persona* arrayPersona[],int lenPersona)
{
    int indexFree;
    char bufferName[32];
    char bufferApellido[32];
    char bufferId[32];
    char bufferEdad[32];
    //int auxEdad;
    //int auxId;
    int retorno=-1;
    if(lenPersona>0 && arrayPersona!=NULL)
    {
        indexFree=persona_findFree(arrayPersona,lenPersona);
        if(indexFree!=-1)
        {
            if((!utn_getLetras(bufferName,32,2,"\nIngrese Nombre: ","\nIngrese un nombre valido!\n"))
                    &&(!utn_getLetras(bufferApellido,32,2,"\nIngrese Apellido: ","\nIngrese un apellido valido!\n"))
                       &&(!utn_getLetrasYNumeros(bufferEdad,32,"\nIngrese una edad: ")))
            {
                arrayPersona[indexFree]=persona_newParametros(bufferId,bufferName,
                                                               bufferApellido,
                                                               bufferEdad);
                /*persona_setId(arrayPersona[indexFree],generarId());
                persona_getNombre(arrayPersona[indexFree],nombre);
                persona_getApellido(arrayPersona[indexFree],apellido);
                persona_getEdad(arrayPersona[indexFree],&edad); //edad = arrayPersona[indexFree].edad;

                printf("\nSe dio de alta a:\n"
                        "Nombre: %s\nApellido: %s\n"
                        "Edad: %d\n",
                        nombre,
                        apellido,
                        edad);*/
                retorno=0;
            }
        }

    }
    return retorno;
}

int persona_initArray(Persona* arrayPer[],int lenPer)
{
    int i;
    int retorno=-1;
    if(arrayPer!=NULL&&lenPer>0)
    {
        for(i=0; i<lenPer; i++)
        {
            arrayPer[i]=NULL;
        }
        retorno=0;

    }
    return retorno;
}

int persona_findFree(Persona* arrayPersona[], int lenPersona)
{
    int i;
    int ret=-1;
    if(arrayPersona!=NULL && lenPersona>0)
    {
        for(i=0; i<lenPersona; i++)
        {
            if(arrayPersona[i]==NULL)
            {
                ret=i;
                printf("\n----Se encontro lugar libre----\n");
                break;
            }
        }
    }
    return ret;
}


int parserPersona(char* pFile,Persona* aPers[],int len)
{
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferApellido[1024];
    char bufferEdad[1024];
    int lenList=0;
    //int i=0;
    FILE *pArchivo;
    //Persona* pListaPersona[1000];
    pArchivo= fopen("data.csv","r");
    if(pArchivo!= NULL)
    {
     fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferApellido,bufferEdad);
        do{
            fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferApellido,bufferEdad);
            //printf("\n%s %s %s %s\n",bufferId,bufferNombre,bufferApellido,bufferEdad);
            aPers[lenList]=persona_newParametros(bufferId,bufferNombre,bufferApellido,bufferEdad);
            if(aPers!=NULL)
            {
                printf("%d - %s - %s - %d\n",aPers[lenList]->id,aPers[lenList]->nombre,aPers[lenList]->apellido,aPers[lenList]->edad);

                lenList++;
            }
        }while(!feof(pArchivo));
        fclose(pArchivo);

    }
    return lenList;
}


int persona_guardarTexto(Persona* arrayPersona[],int limite,char* path)
{
    int retorno=-1;
    int i;
    int id;
    char* nombre[1024];
    char* apellido[1024];
    int edad;

    FILE* pFile;
    pFile=fopen(path,"w+");

    //Persona* auxPersona;
    if(pFile !=NULL && arrayPersona!=NULL && limite>0)
    {
        retorno=0;
        for(i=0;i<limite;i++)
        {
            persona_getId(arrayPersona[i],&id);
            persona_getEdad(arrayPersona[i],&edad);
            persona_getNombre(arrayPersona[i],nombre);
            persona_getApellido(arrayPersona[i],apellido);
            fprintf(pFile,"%d,%s,%s,%d\n",id,nombre,apellido,edad);
            //printf("%d,%s,%s,%d\n",id,nombre,apellido,edad);

        }
    }
    fclose(pFile);
    return retorno;
}


static int isValidEdad(char* edad)
{
    int i=0;
    int retorno=0;
    while(edad[i] != '\0')
    {
        if(edad[i] < '0' || edad[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;
}

static int isValidId(char* personaId)
{
    int i=0;
    int retorno=0;
    int contadorDeGuiones=0;
    while(personaId[i] != '\0')
    {
        if(personaId[i] == '-' && contadorDeGuiones==0)
        {
            contadorDeGuiones++;
            i++;
            continue;
        }
        if(personaId[i] < '0' || personaId[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;
}

/*static int generarId(void)
{
    static int idPer=0;
    return idPer++;
}*/
