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
Employee* employee_newParametrosTxt(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
Employee* employee_newParametros(int idStr,char* nombreStr, int horasTrabajadasStr, int sueldo);

void employee_delete(Employee* this);
int employee_delete2(Employee* this);

int employee_setId(Employee* this,int id);
int employee_setIdTxt(Employee* this,char* id);
int employee_getId(Employee* this,int* flagError);
int employee_getIdTxt(Employee* this,char* id);
int employee_isValidId(char* id);


int employee_setNombre(Employee* this,char* nombre);
char* employee_getNombre(Employee* this, int* flagError);
int employee_getNombre2(Employee* this, char* nombre);
int employee_isValidNombre(char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_setHorasTrabajadasTxt(Employee* this,char* horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* flagError);
int employee_getHorasTrabajadasTxt(Employee* this,char* horasTrabajadas);
int employee_isValidHorasTrabajadas(char* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_setSueldoTxt(Employee* this,char* sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
int employee_getSueldoTxt(Employee* this, char* sueldo);
int employee_isValidSueldo(char* sueldo);

int emp_initArray (Employee* arrayEmp[], int limite);
int emp_buscarIndiceVacio (Employee* arrayEmp[], int limite);
int emp_generarId(void);
int emp_alta (Employee* arrayEmp [], int limite);
void emp_altaForzada(Employee* empleados[],int len);
int emp_imprimirLista (Employee* arrayEmp [], int limite);
void employee_valorInicialId(int id);
int employee_generarId(void);

int employee_initArray (Employee* this[], int limite);
void employee_print (Employee* this);
int employee_getId2(Employee* this,int* flagError);
int employee_funcionCriterioSueldo (void* a, void* b);
int employee_funcionCriterioNombre (void* a, void* b);
int employee_funcionCriterioId (void* a, void* b);
int employee_funcionCriterioHoras (void* a, void* b);


#endif // employee_H_INCLUDED
