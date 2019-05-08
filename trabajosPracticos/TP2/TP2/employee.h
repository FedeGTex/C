#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

typedef struct{
    int idEmployee;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

/**
    @brief realizar una carga de datos de manera automatica al iniciar el programa
    @param pEmployee: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param name: guarda una cadena de caracteres recibida
    @param lastName: guarda una cadena de caracteres recibida
    @param sector: guarda un int recibido
    @param sector: guarda un float recibido
    @return return 0 OK, -1 error.
*/
int employee_altaForzada(Employee* pEmployee,int limite,char* name, char* lastName,int sector, float salary);
/**
    @brief carga un valor en el mismo campo de todas las posiciones del array recibido
    @param pEmployee: guarda el array recibido
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int employee_cargarDatosVacio(Employee* pEmployee,int limite);
/**
    @brief carga valores en la posicion del array recibida
    @param pEmployee: guarda el array recibido
    @param indice: guarda el int de la posicion del array
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int employee_cargarIndice(Employee* pEmployee,int indice,int limite);
/**
    @brief muestra los datos de todas las posiciones del array
    @param pEmployee: guarda el array recibido
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int employee_mostrarIndice(Employee* pEmployee,int limite);
/**
    @brief busca dentro del array hasta encontrar un indice vacio donde cargar datos
    @param pEmployee: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param indiceVacio: guarda el indice de la posicion vacia del array
    @return return 0 OK, -1 error.
*/
int employee_obtenerIndiceVacio(Employee* pEmployee,int limite,int* indiceVacio);
/**
    @brief recibe un ID para modificar una posicion del array
    @param pEmployee: guarda el array recibido
    @param id:guarda el int recibido del ID a modificar
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int employee_modificarIndice(Employee* pEmployee,int id, int limite);
/**
    @brief recibe un ID para buscar un empleado
    @param pEmployee: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param id:guarda el int del empleado a buscar
    @return return el indice del array donde esta el empleado
*/
int employee_buscarEmployeePorId(Employee* pEmployee,int limite,int id);
/**
    @brief recibe un ID para borrar un empleado
    @param pEmployee: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param id:guarda el int del empleado a borrar
    @return return 0 OK, -1 error.
*/
int employee_borrarEmployee(Employee* pEmployee,int limite,int id);
/**
    @brief recibe el array de empleados y realizar operaciones con el salario
    (total, promedio y salarios mayores al promedio)
    @param pEmployee: guarda el array recibido
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int employee_calcularSalario(Employee* pEmployee,int limite);
/**
    @brief recibe el array para checkear si esta cargado o no
    @param pEmployee: guarda el array recibido
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int employee_checkIndiceVacio(Employee* pEmployee,int limite);
/**
    @brief recibe el array para ordenarlo con Burbujeo por Sector y Apellido
    @param pEmployee: guarda el array recibido
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int employee_ordenarEmployeePorSectorApellido(Employee* pEmployee, int limite);

#endif // EMPLOYEE_H_INCLUDED
