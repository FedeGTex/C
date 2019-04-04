#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    float numeros[2];
    float suma;
    float resta;
    float multiplicacion;
    float division;
    int unsigned long factorialA;
    int unsigned long factorialB;
    int opcion;
    int banderaCalculos=0;

    numeros[0]=0;
    numeros[1]=0;
    do{
        mostrarMenu(numeros[0],numeros[1],&opcion);
        switch (opcion)
        {
            case 1:
                verificaNumeroFloat(&numeros[0]);
                system("cls");
                break;
            case 2:
                verificaNumeroFloat(&numeros[1]);
                system("cls");
                break;
            case 3:
                banderaCalculos++;
                sumaNumeros(numeros,2,&suma);
                restaDosNumeros(numeros,0,1,&resta);
                multiplicaNumeros(numeros,2,&multiplicacion);
                divideDosNumeros(numeros,0,1,&division);
                calcularFactorial(numeros,0,&factorialA);
                calcularFactorial(numeros,1,&factorialB);
                break;
            case 4:
                system("cls");
                if(banderaCalculos==0){
                    printf("Primero debe realizar los calculos (opcion 3)\n");
                    printf("Pulse una tecla para continuar...\n");
                    getchar();
                    getchar();
                    system("cls");
                    break;
                }
                printf("A= %.2f    B= %.2f\n",numeros[0],numeros[1]);
                printf("La suma de los operandos es A+B: %.2f \n",suma);
                printf("La resta de los operandos es A-B: %.2f \n",resta);
                printf("La multiplicacion de los operandos es A*B: %.2f \n",multiplicacion);
                if (divideDosNumeros(numeros,0,1,&division)==-1)
                    printf("No se puede dividir por cero \n");
                else
                    printf("La division de los operandos es A/B: %.2f\n",division);
                if (factorialA==0)
                    printf("A :No se puede calcular factorial de numeros decimales o negativo\n");
                else
                    printf("El factorial de A es: %lu\n",factorialA);
                if (factorialB==0)
                    printf("B: No se puede calcular factorial de numeros decimales o negativo\n");
                else
                    printf("El factorial de B es: %lu\n\n",factorialB);
                printf("Pulse una tecla para continuar...\n");
                getchar();
                getchar();
                system("cls");
                break;
            }
    }while(opcion!=5);
    return 0;
}
