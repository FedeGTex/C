#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int sumaNumeros(float numeros[],int cantidad,float *resultado)
{
    float sumas;
    cantidad--;
    for(sumas=0;cantidad>=0;cantidad--)
    {
        sumas+=numeros[cantidad];
    }
    *resultado=sumas;
    return 0;
}
//resta dos float A-B
int restaDosNumeros(float numeros[],int primerNumero,int segundoNumero,float*resultado)
{
    float resta;
    resta=numeros[primerNumero]-numeros[segundoNumero];
    *resultado=resta;
    return 0;
}
//multiplica x cantidad de numeros
int multiplicaNumeros(float numeros[],int cantidad,float *resultado)
{
    float multiplicacion;
    cantidad--;
    for(multiplicacion=1;cantidad>=0;cantidad--)
    {
        multiplicacion*=numeros[cantidad];
    }
    *resultado=multiplicacion;
    return 0;
}
int divideDosNumeros(float numeros[],int dividendo,int divisor,float *resultado)
{
    float division;
    int retorno=0;

    if (numeros[divisor]==0)
        retorno=-1;
    else
        division=numeros[dividendo]/numeros[divisor];
    *resultado=division;
    return retorno;
}
int calcularFactorial(float numeros[],int ubicacion,int unsigned long *resultado)
{
    int unsigned long factorial=1;
    int i;
    if (numeros[ubicacion]<0||numeros[ubicacion]!=(int)numeros[ubicacion])
        factorial=0;
    else if(numeros[ubicacion]==0||numeros[ubicacion]==1)
        factorial=1;
    else{
        factorial=numeros[ubicacion];
        for (i=numeros[ubicacion];i>0;i--){
            factorial=factorial*i;
        }
    }
    *resultado=factorial;
    return 0;
}
int mostrarMenu(float numeroA,float numeroB,int *respuesta)
{
        int opcion;
        printf("1. Ingresar 1er operando (A=%.2f)\n",numeroA);
        printf("2. Ingresar 2do operando (B=%.2f)\n",numeroB);
        printf("3. Calcular todas las operaciones siguentes:\n");
        printf("\t a) Calcular la suma\n");
        printf("\t b) Calcular la resta (A-B)\n");
        printf("\t c) Calcular la division (A/B)\n");
        printf("\t d) Calcular la multiplicacion (A*B)\n");
        printf("\t e) Calcular el factorial (A!)\n");
        printf("4. Informar los resultados\n");
        printf("5. Salir\n");
        printf("INGRESE UNA OPCION :\n");
        if (scanf("%d",&opcion)!=1||(opcion<1||opcion>5))
        {
            fflush(stdin);
            system("cls");
            printf("ERRO, INGRESE UNA OPCION ENTRE [1-5]\n\n");
            mostrarMenu(numeroA,numeroB,&opcion);
        }
        system("cls");
        *respuesta=opcion;
        return 0;
}
int verificaNumeroFloat(float *resultado)
{
    float numeroFloat;
    printf("Ingrese un operando;\n");
    while(scanf("%f",&numeroFloat)!=1)
    {
        fflush(stdin);
        system("cls");
        printf("ERROR, POR FAVOR INGRESE SOLO NUMEROS\n\n");
        printf("Ingrese el operando;\n");
    }
    *resultado=numeroFloat;
    return 0;
}
