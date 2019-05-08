//#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "employee.h"
#define EMPLOYEE_LEN 1000
#define TEXTO_MENU "       MENU\n\
1)Cargar un empleado\n\
2)Modificar un empleado\n\
3)Borrar un empleado\n\
4)Imprimir lista de empleados\n\
5)Calcular salario: Total/Promedio/Mayores al promedio\n\
6)Salir\n\
Elija una opcion: "


int main()
{
    int indiceVacio;
    int opcion;
    int id;
    int salir=0;
    int flag=0;
    Employee pEmployee[EMPLOYEE_LEN];
    employee_cargarDatosVacio(pEmployee,EMPLOYEE_LEN);
    employee_altaForzada(pEmployee,EMPLOYEE_LEN,"Cristina","Castro",3,9000);
    employee_altaForzada(pEmployee,EMPLOYEE_LEN,"Elsa","Badillo",2,12000);
    employee_altaForzada(pEmployee,EMPLOYEE_LEN,"Kevin","Chuca",3,25000);
    employee_altaForzada(pEmployee,EMPLOYEE_LEN,"Homero","Simpson",1,22000);
    employee_altaForzada(pEmployee,EMPLOYEE_LEN,"Armando","Barrera",2,30000);
    employee_altaForzada(pEmployee,EMPLOYEE_LEN,"Elsa","Polindo",1,35000);
    employee_altaForzada(pEmployee,EMPLOYEE_LEN,"Aquiles","Brinco",2,17000);

    do
    {
        system("cls");
        fflush(stdin);
        if(employee_checkIndiceVacio(pEmployee,EMPLOYEE_LEN)==-1)
        {
            flag=1;
        }else
        {
            flag=0;
        }
        utn_getEntero(&opcion,2,TEXTO_MENU,"Esa no es una opcion valida\n",0,7);
        switch(opcion)
        {
            case 1:
                    system("cls");
                    if(employee_obtenerIndiceVacio(pEmployee,EMPLOYEE_LEN,&indiceVacio)==0)
                    {
                        employee_cargarIndice(pEmployee,indiceVacio,EMPLOYEE_LEN);
                        break;
                    }
                    else
                    {
                        printf("No hay lugar");
                        system("pause");
                    }
                    fflush(stdin);
                    break;
                case 2:
                    if(flag==1)
                    {
                        system("cls");
                        if(utn_getEntero(&id,2,"Ingrese el ID del empleado que desea modificar: ","Ese no es un ID valido\n",-1,EMPLOYEE_LEN)==0)
                        {
                            if(employee_buscarEmployeePorId(pEmployee,EMPLOYEE_LEN,id)!= -1)
                            {
                                employee_modificarIndice(pEmployee,id,EMPLOYEE_LEN);
                            }else
                            {
                                printf("\nEl ID no existe\n");
                                system("pause");
                            }

                        }
                    }else
                    {
                        printf("\n||No hay datos cargados||\n");
                        system("pause");
                    }
                    fflush(stdin);
                    break;
                case 3:
                     if(flag==1)
                    {
                        system("cls");
                        if(utn_getEntero(&id,2,"Ingrese el ID del empleado que desea borrar: ","Ese no es un ID valido\n",-1,EMPLOYEE_LEN)==0)
                        {
                            if(employee_buscarEmployeePorId(pEmployee,EMPLOYEE_LEN,id)!= -1)
                            {
                              employee_borrarEmployee(pEmployee,EMPLOYEE_LEN,id);
                            }else
                            {
                                 printf("\nEl ID no existe\n");
                                 system("pause");
                            }
                        }
                    }else
                    {
                        printf("\n||No hay datos cargados||\n");
                        system("pause");
                    }
                    fflush(stdin);
                    break;
                case 4:
                     if(flag==1)
                    {
                        system("cls");
                        employee_mostrarIndice(pEmployee,EMPLOYEE_LEN);
                        system("pause");
                    }else
                    {
                        printf("\n||No hay datos cargados||\n");
                        system("pause");
                    }
                     fflush(stdin);
                    break;
                case 5:

                    if(flag==1)
                    {
                        system("cls");
                        employee_calcularSalario(pEmployee,EMPLOYEE_LEN);
                    }else
                    {
                        printf("\n||No hay datos cargados||\n");
                        system("pause");
                    }
                    fflush(stdin);
                    break;
                case 6:
                salir = 1;

        }
    }while(salir==0);

    return 0;
}
