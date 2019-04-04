#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define NUMEROS_LEN 10
#define MAXIMO 100
#define MINIMO 0
/*
    Ejercicio:
    Hacer un programa que le pida 10 numeros al usuario y los guarde en un array
    1) Analizar el array e imprimir:
    promedio
    maximo
    minimo

    2)Pedirle al usuario que ingrese un numero e indicar si el mismo esta o no en el array.

    3)Imprimir el array ordenado de mayor a menor
*/
int main()
{
    int numero[NUMEROS_LEN];
    int i;
    int minimo;
    int maximo;
    float promedio;
    int numeroBuscar;

    for(i=0;i<NUMEROS_LEN;i++)
    {
         utn_getEntero(&numero[i],2,"\nIngrese un numero: ","ERROR! solo se aceptan numeros de 0 a 100",MINIMO,MAXIMO);
    }
    utn_mostrarArray(numero,NUMEROS_LEN);

    utn_calcularNumeroMaximo(numero,NUMEROS_LEN,&maximo);
    utn_calcularNumeroMinimo(numero,NUMEROS_LEN,&minimo);
    utn_promedioArray(numero,NUMEROS_LEN,&promedio);

    printf("\n\nEl maximo es: %d\n",maximo);
    printf("\nEl minimo es: %d\n",minimo);
    printf("\nEl promedio es: %.2f\n",promedio);

    utn_getEntero(&numeroBuscar,2,"\nIngrese el numero a buscar: ","Ha supero el maximo!",MINIMO,MAXIMO);

    if(utn_buscarNumeroEnArray(numero,NUMEROS_LEN,numeroBuscar)==0)
    {
        printf("El numero a buscar se encuentra en el array y es: %d ",numeroBuscar);
    }
    else
    {
        printf("El numero a buscar no se encuentra en el array!");
    }

    if(utn_ordenarArray(numero,NUMEROS_LEN,0)==-1)
    {
        printf("El numero o el limite ingresado son incorrectos!");
    }
    else
    {
        printf("\nEl array ordenado es: ");
        utn_mostrarArray(numero,NUMEROS_LEN);
    }



    return 0;
}
