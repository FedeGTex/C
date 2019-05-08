#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "employee.h"
#define MENU_MODIFICAR "Ingrese la opcion que desea modificar:\n\
1)Nombre\n\
2)Apellido\n\
3)Sector\n\
4)Salario\n\
5)Terminar\n\
Elija:"

static int proximoId();

int employee_altaForzada(Employee* pEmployee,int limite,char* name, char* lastName,int sector, float salary)
{
    int retorno=-1;
    int indice;
    employee_obtenerIndiceVacio(pEmployee,limite,&indice);

    if(pEmployee!=NULL && limite>0)
    {
          if(indice >= 0)
          {
            strncpy(pEmployee[indice].name,name,50);
            strncpy(pEmployee[indice].lastName,lastName,50);
            pEmployee[indice].sector=sector;
            pEmployee[indice].salary=salary;
            pEmployee[indice].idEmployee=proximoId();
            pEmployee[indice].isEmpty=0;
            retorno =0;
          }

    }


    return retorno;
}

int employee_cargarDatosVacio(Employee* pEmployee, int limite)
{
    int retorno=-1;
    int i;
    if(pEmployee != NULL && limite >0)
    {
        for(i=0;i<limite;i++)
        {
            pEmployee[i].isEmpty=-1;
        }
        retorno=0;
    }

    return retorno;
}
int employee_cargarIndice(Employee* pEmployee,int indice,int limite)
{
    int retorno=-1;
    char auxName[50];
    char auxLastName[50];
    int auxSector;
    float auxSalary;

    if(pEmployee!=NULL && limite>0)
    {
        if(utn_getLetras(auxName,50,2,"Ingrese nombre del empleado: ","Ese no es un nombre valido\n")==0)
        {
            strncpy(pEmployee[indice].name,auxName,50);
            if(utn_getLetras(auxLastName,50,2,"Ingrese apellido del empleado: ","Ese no es un apellido valido \n")==0)
            {
                strncpy(pEmployee[indice].lastName,auxLastName,50);
                if(utn_getEntero(&auxSector,2,"Ingrese el sector del empleado(1-Sistemas,2-Administracion,3-RRHH): ","Ese sector no existe\n",0,4)==0)
                {
                    pEmployee[indice].sector=auxSector;

                    if(utn_getFloat(&auxSalary,2,"Ingrese el salario del empleado: ","Ese no es un salario valido\n",0,9999999)==0)
                    {
                        pEmployee[indice].salary=auxSalary;
                        pEmployee[indice].idEmployee=proximoId();
                        pEmployee[indice].isEmpty=0;
                        retorno =0;

                    }
                }
            }
        }
    }
    return retorno;
}

int employee_modificarIndice(Employee* pEmployee,int id, int limite)
{
    int retorno=-1;
    char auxName[50];
    char auxLastName[50];
    int auxSector;
    float auxSalary;
    int indice;
    int opcion;
    int salir;
    indice=employee_buscarEmployeePorId(pEmployee,limite,id);
    if(indice>=0)
    {
        if(pEmployee!=NULL && limite>0)
        {
            do
            {
                system("cls");
                fflush(stdin);
                if(utn_getEntero(&opcion,2,MENU_MODIFICAR,"Esa no es una opcion valida\n",0,6)==0)
                {
                    switch(opcion)
                    {
                        case 1:
                            system("cls");
                            if(utn_getLetras(auxName,50,2,"Ingrese el nuevo nombre del empleado: ","Ese no es un nombre valido\n")==0)
                            {
                                strncpy(pEmployee[indice].name,auxName,50);
                            }
                            fflush(stdin);
                            break;
                        case 2:
                            system("cls");
                            if(utn_getLetras(auxLastName,50,2,"Ingrese el nuevo apellido del empleado: ","Ese no es un apellido valido\n")==0)
                            {
                                    strncpy(pEmployee[indice].lastName,auxLastName,50);
                            }
                            fflush(stdin);
                            break;
                        case 3:
                            system("cls");
                            if(utn_getEntero(&auxSector,2,"Ingrese el nuevo sector del empleado(1-Fabrica,2-Administracion,3-Tesoreria): ","Ese sector no existe\n",0,4)==0)
                            {
                                pEmployee[indice].sector=auxSector;
                            }
                            fflush(stdin);
                            break;
                        case 4:
                            system("cls");
                            if(utn_getFloat(&auxSalary,2,"Ingrese el nuevo salario del empleado: ","Ese no es un salario valido",0,9999999)==0)
                            {
                                pEmployee[indice].salary=auxSalary;
                            }
                            fflush(stdin);
                            break;
                        case 5:
                            salir=1;
                    }

                 }
            }while(salir==0);
            retorno=0;

        }

    }else
    {
        printf("El ID no existe\n");
        system("pause");
    }
    return retorno;
    return 0;
}

int employee_buscarEmployeePorId(Employee* pEmployee,int limite,int id)
{
    int retorno=-1;
    int i;

    for(i=0;i<limite;i++)
    {
        if(pEmployee[i].isEmpty==0)
        {
            if(pEmployee[i].idEmployee==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int employee_borrarEmployee(Employee* pEmployee,int limite,int id)
{
    int retorno=-1;
    int i;

    for(i=0;i<limite;i++)
    {
        if(pEmployee[i].isEmpty==0)
        {
            if(pEmployee[i].idEmployee==id)
            {
                pEmployee[i].isEmpty=-1;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int employee_mostrarIndice(Employee* pEmployee,int limite)
{
    int retorno=-1;
    int i;
    if(pEmployee != NULL && limite > 0)
    {
        if(employee_ordenarEmployeePorSectorApellido(pEmployee,limite)==0)
        {
            for(i=0;i<limite;i++)
            {
                if(pEmployee[i].isEmpty==0)
                {
                    printf("\nEl ID del empleado es: %d", pEmployee[i].idEmployee);
                    printf("\nEl nombre del empleado es: %s",pEmployee[i].name);
                    printf("\nEl apellido del empleado es: %s",pEmployee[i].lastName);
                    printf("\nEl sector del empleado es: %d",pEmployee[i].sector);
                    printf("\nEl salario del empleado es: %.2f\n",pEmployee[i].salary);
                    retorno=0;
                }
            }
        }
    }

    return retorno;
}

int employee_ordenarEmployeePorSectorApellido(Employee* pEmployee, int limite)
{
    int retorno=-1;
    int i=0;
    int flagSwap;
    Employee auxEmployee;
    if(pEmployee != NULL && limite > 0)
    {
        retorno=0;
        if(pEmployee[i].isEmpty==0)
        {
            do
            {
                flagSwap=0;
                for(i=0;i<limite-1;i++)
                {
                    if((pEmployee[i].sector > pEmployee[i+1].sector) ||
                        (pEmployee[i].sector == pEmployee[i+1].sector && strcmp(pEmployee[i].lastName,pEmployee[i+1].lastName)>0))
                    {
                        flagSwap=1;
                        auxEmployee=pEmployee[i];
                        pEmployee[i]=pEmployee[i+1];
                        pEmployee[i+1]=auxEmployee;
                    }
                }
            }while(flagSwap==1);

        }
    }
    return retorno;
}

int employee_obtenerIndiceVacio(Employee* pEmployee,int limite,int* indiceVacio)
{
    int i=0;
    int retorno = -1;
    if(pEmployee != NULL && limite > 0)
    {
         while(i<limite)
        {
            if(pEmployee[i].isEmpty==-1)
            {
                *indiceVacio=i;
                retorno = 0;
                break;
            }
            i++;
        }
    }

    return retorno;
}

int employee_checkIndiceVacio(Employee* pEmployee,int limite)
{
    int i=0;
    int retorno = 0;
    if(pEmployee != NULL && limite > 0)
    {
         while(i<limite)
        {
            if(pEmployee[i].isEmpty==0)
            {
                retorno = -1;
                break;
            }
            i++;
        }
    }
    return retorno;
}

int employee_calcularSalario(Employee* pEmployee,int limite)
{
    int retorno=-1;
    int i;
    float total=0;
    float cantSalarios=0;
    int cantMayorPromedio=0;
    float promedio;
    int flag=0;

    if(pEmployee != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pEmployee[i].isEmpty==0)
            {
                total=total + pEmployee[i].salary;
                cantSalarios++;
            }
        }

        promedio=total/cantSalarios;

        for(i=0;i<limite;i++)
        {
            if(pEmployee[i].isEmpty==0)
            {
                if(pEmployee[i].salary>promedio)
                {
                    cantMayorPromedio++;
                    flag=1;
                }
            }
        }

    }

    if(cantSalarios > 0)
    {
        printf("El total de los salarios es: %.2f",total);
        printf(" y el promedio es: %.2f\n",promedio);
    }else
    {
        printf("No hay salarios cargados\n");
        system("pause");
    }
    if(flag==1)
    {
        printf("La cantidad de salarios que superan el promedio es de: %d\n",cantMayorPromedio);
        system("pause");
    }else
    {
        printf("Ningun salario supera el promedio");
        system("pause");
    }
    return retorno;
}


static int proximoId()
{
    static int proximoId;
    proximoId++;
    return proximoId;
}
