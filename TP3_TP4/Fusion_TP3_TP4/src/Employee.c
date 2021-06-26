
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"

Employee* employee_new (void)
{
	return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametrosTxt(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)
{
	Employee* auxEmpleado = employee_new();
	if (auxEmpleado != NULL && idStr != NULL && nombreStr!=NULL && horasTrabajadasStr!= NULL && sueldo!=NULL)
	{
		if (employee_setNombre(auxEmpleado, nombreStr) <0 ||
			employee_setId(auxEmpleado, atoi(idStr)) <0 ||
			employee_setHorasTrabajadas(auxEmpleado,atoi(horasTrabajadasStr)) <0 ||
			employee_setSueldo(auxEmpleado, atof(sueldo)) <0 )
		{
			employee_delete2(auxEmpleado);
			auxEmpleado = NULL;
			printf("\nERROR DE SET");
		}
	}
	return auxEmpleado;
}
Employee* employee_newParametros(int idStr,char* nombreStr, int horasTrabajadasStr, float sueldo)
{
	Employee* auxEmpleado = employee_new();
	if (auxEmpleado != NULL  && nombreStr!=NULL)
	{
		if (employee_setNombre(auxEmpleado, nombreStr) <0 ||
			employee_setId(auxEmpleado, idStr) <0 ||
			employee_setHorasTrabajadas(auxEmpleado, horasTrabajadasStr) <0 ||
			employee_setSueldo(auxEmpleado, sueldo) <0 )
		{
			employee_delete2(auxEmpleado);
			auxEmpleado = NULL;
			printf("\nERROR DE SET");
		}
		else
		{
			printf("\nSET OK\n");
		}
	}
	return auxEmpleado;
}

int employee_delete2(Employee* this)
{
	int retorno = -1;
	if (this != NULL)
	{
		free (this);
		retorno = 0;
	}
	return retorno;
}

int employee_setId(Employee* this,int id)
{
	int retorno = -1;
	if (this != NULL && id>=0)
	{
		this ->id = id;
		retorno = 0;
	}
	return retorno;
}
int employee_setIdTxt(Employee* this, char* id)
{
	int retorno = -1;
	if (this != NULL && id !=NULL)
	{
		if (employee_isValidId(id))
		{
			retorno =0;
			this->id =atoi(id);
		}
	}
	return retorno;
}
int employee_getId(Employee* this,int* flagError)
{
	*flagError= -1;
	int auxId = -1;

	if (this != NULL && flagError != NULL)
	{
		auxId=this->id;
		*flagError = 0;
	}
	return auxId;
}
int employee_getId2(Employee* this,int* flagError)
{
    *flagError = -1;
    int auxId = -1;
    if(this != NULL && flagError != NULL)
    {
        auxId = this->id;
        *flagError = 0;
    }
    return auxId;
}
int employee_getIdTxt(Employee* this,char* id)
{
	int retorno= -1;
	if (this != NULL && id != NULL)
	{
		sprintf(id, "%d",this->id);
		retorno = 0;
	}
	return retorno;
}
int employee_isValidId(char* id)
{
	return 1;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if (this != NULL && nombre != NULL && employee_isValidNombre (nombre))
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}
char* employee_getNombre(Employee* this, int* flagError)
{
	*flagError= -1;
	char* auxNombre = NULL;

	if (this != NULL && flagError != NULL)
	{
		auxNombre = this->nombre;
		*flagError = 0;
	}
	return auxNombre;
}
int employee_getNombre2(Employee* this, char* nombre)
{
	int retorno = -1;
	if (this!= NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}
int employee_isValidNombre(char* nombre)
{
	int retorno = -1;
	if(nombre!=NULL && esSoloLetras(nombre, 99999)==0)
	{
		retorno = 0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
	int retorno = -1;
	if (this != NULL && horasTrabajadas>0)
	{
		this ->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}
int employee_setHorasTrabajadasTxt(Employee* this,char* horasTrabajadas)
{
	int retorno = -1;
	if (this != NULL && horasTrabajadas !=NULL)
	{
		if (employee_isValidHorasTrabajadas(horasTrabajadas))
		{
			retorno =0;
			this->horasTrabajadas =atoi(horasTrabajadas);
		}
	}
	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* flagError)
{
	*flagError= -1;
	int auxHoras = -1;

	if (this != NULL && flagError != NULL)
	{
		auxHoras=this->horasTrabajadas;
		*flagError = 0;
	}
	return auxHoras;
}

int employee_getHorasTrabajadasTxt(Employee* this,char* horasTrabajadas)
{
	int retorno= -1;
	if (this != NULL && horasTrabajadas != NULL)
	{
		sprintf(horasTrabajadas, "%d",this->horasTrabajadas);
		retorno = 0;
	}
	return retorno;
}

int employee_isValidHorasTrabajadas(char* horasTrabajadas)
{
	int retorno = -1;
	if(horasTrabajadas!=NULL && esNumerica(horasTrabajadas, 9999999)==0)
	{
		retorno =0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this, float sueldo)
{
	int retorno = -1;
	if (this != NULL && sueldo>=0)
	{
		this ->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}
int employee_setSueldoTxt(Employee* this,char* sueldo)
{
	int retorno = -1;
	if (this != NULL && sueldo !=NULL)
	{
		if (employee_isValidSueldo(sueldo))
		{
			retorno =0;
			this->sueldo =atof(sueldo);
		}
	}
	return retorno;
}
int employee_getSueldo(Employee* this,int* flagError)
{
	*flagError= -1;
	float auxSueldo = -1;

	if (this != NULL && flagError != NULL)
	{
		auxSueldo=this->sueldo;
		*flagError = 0;
	}
	return auxSueldo;
}
int employee_getSueldoTxt(Employee* this, char* sueldo)
{
	int retorno= -1;
	if (this != NULL && sueldo != NULL)
	{
		sprintf(sueldo, "%f",this->sueldo);
		retorno = 0;
	}
	return retorno;
}
int employee_isValidSueldo(char* sueldo)
{
	int retorno =-1;
	if(sueldo!=NULL && esNumericaFlotante(sueldo, 999999999)==1)
	{
		retorno = 0;
	}
	return retorno;
}

int emp_generarId(void)
{
	static int contador = 0; //mantiene su valor. no se comporta como localç
	contador++;
	return contador;
}

static int contador = 0;
void employee_valorInicialId(int id)
{
	 contador= id;
}
int employee_generarId(void)
{
	//mantiene su valor. no se comporta como localÃ§
	contador++;
	return contador;
}

/*la funcion criterio se va a llamar depende el algoritmo, muchas veces, depende de que
 * tan desordenado esta
 *
 * los trata como punteros void porque el employee no esta en linkedlist
 * */
int employee_funcionCriterioSueldo (void* a, void* b)
{
	int retorno =-1;
	Employee* pA;
	Employee* pB;

	pA = (Employee*) a;
	pB = (Employee*) b;
	float sueldo1, sueldo2;
	int flag;

	sueldo1=employee_getSueldo(pA, &flag);
	sueldo2= employee_getSueldo(pB, &flag);
	if (sueldo1>sueldo2)
	{
		retorno = 1;
	}
	else if (sueldo1==sueldo2)
	{
		retorno = 0;
	}
	else
	{
		retorno = -1;
	}
	return retorno; //return strcmp(nom1,nom2) para nombres
}
int employee_funcionCriterioHoras (void* a, void* b)
{
	int retorno =-1;
	Employee* pA;
	Employee* pB;

	pA = (Employee*) a;
	pB = (Employee*) b;
	int hora1, hora2;
	int flag;

	hora1=employee_getHorasTrabajadas(pA, &flag);
	hora2= employee_getHorasTrabajadas(pB, &flag);
	if (hora1>hora2)
	{
		retorno = 1;
	}
	else if (hora1==hora2)
	{
		retorno = 0;
	}
	else
	{
		retorno = -1;
	}
	return retorno;
}

int employee_funcionCriterioId (void* a, void* b)
{
	int retorno =-1;
	Employee* pA;
	Employee* pB;

	pA = (Employee*) a;
	pB = (Employee*) b;
	int id1, id2;
	int flag;

	id1=employee_getId(pA, &flag);
	id2= employee_getId(pB, &flag);
	if (id1>id2)
	{
		retorno = 1;
	}
	else if (id1==id2)
	{
		retorno = 0;
	}
	else
	{
		retorno = -1;
	}
	return retorno;
}
int employee_funcionCriterioNombre (void* a, void* b)
{
	int retorno =-1;
	Employee* pA = NULL;
	Employee* pB = NULL;

	pA = (Employee*) a;
	pB = (Employee*) b;
	char nombreA [100];
	char nombreB [100];

	employee_getNombre2(pA, nombreA);
	employee_getNombre2(pB, nombreB);
	if (strcmp(nombreA, nombreB)>0)
	{
		retorno = 1;
	}

	return retorno;
}


