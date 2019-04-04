#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/**suma x cantidad de numeros float.
parametros (array,cantidad de numeros en el array,direccion de variable donde guardar resultado)
*/
int sumaNumeros(float numeros[],int cantidad,float *resultado);
/** Resta dos numeros:
parametros (array,subindice del primer numero,subindice del segundo numero,puntero a guardar el resultado)
*/
int restaDosNumeros(float numeros[],int primerNumero,int segundoNumero,float *resultado);
/** multiplica numeros:
parametros (array,cantidad de subindices a multiplicar "desde el numero indicado hacia adelante",puntero a guardar el resultado)
*/
int multiplicaNumeros(float numeros[],int cantidad,float *resultado);
/** divide dos numeros:
parametros (array,subindices del dividendo,subindice del divisor,puntero a guardar el resultado)
return :retorna -1 si el divisor es 0 "no se puede dividir x 0"
*/
int divideDosNumeros(float numeros[],int dividendo,int divisor,float *resultado);
/** calcula factorial:
verifica si el numero es Natural positivo.De no ser asi devuelve 0 como resultado
parametros (array,subindices,puntero a guardar el resultado)
*/
int calcularFactorial(float numeros[],int ubicacion,int unsigned long *resultado);
/** Mostrar menu:
Muestra un menu de una calculadora donde muestra los dos operandos
verifica que el numero ingresado este dentro de los valores del 1-5.y devuelve el resultado
parametros (operando 1,operando 2,puntero a guardar el resultado)
*/
int mostrarMenu(float numeroA,float numeroB,int *respuesta);
/** Verificador de numero float:
pide al usuario el ingreso de un numero, de no ser asi muestra un error y se vuelve a pedir el ingreso.
la funcion termina solo cuando ingrese un numero y lo devuelve
parametros (puntero a guardar el numero obtenido)
*/
int verificaNumeroFloat(float *resultado);

#endif // FUNCIONES_H_INCLUDED
