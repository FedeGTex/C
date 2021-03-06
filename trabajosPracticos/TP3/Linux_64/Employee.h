#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* id,char* nombre,char* horasTrabajadas,char* sueldo);
int employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
//int employee_setId(Employee* this,char* id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
//int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
//int employee_setSueldo(Employee* this,char* sueldo);
int employee_getSueldo(Employee* this,int* sueldo);



int employee_guardarBinario(FILE* pFile,LinkedList* pArrayListEmployee);
int employee_guardarTexto(FILE* pFile,LinkedList* pArrayListEmployee);
int employee_criterioNombre(void* thisA,void* thisB);
int employee_validarEmpleado(Employee* auxEmployee);


#endif // employee_H_INCLUDED
