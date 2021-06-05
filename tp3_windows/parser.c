#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	char nombreAux [5000];
	char sueldoAux [5000];
	char horasTrabajadas [5000];
	char idAux [5000];
	Employee* pEmployee = NULL;
	int indice=-1;
	int idMaxAux;
	if (pFile!=NULL && pArrayListEmployee!= NULL)
	{
		do
		{
			indice =0;
			if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreAux, horasTrabajadas, sueldoAux)==4)
			{
				if(esNumerica(idAux, 5000)==1)
				{
					pEmployee= employee_newParametrosTxt(idAux, nombreAux, horasTrabajadas, sueldoAux);
					if(pEmployee != NULL)
					{
						ll_add(pArrayListEmployee, pEmployee);
					}
					if(indice==0)
						idMaxAux= atoi(idAux);
					else if(atoi(idAux) > idMaxAux)
						idMaxAux = atoi(idAux);
					indice++;
				}
			}
		}while(!feof(pFile));
	}
    return idMaxAux;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* pE=NULL;
	int indice =-1;
	int idMaxAux;
	int idAux;
	int flag;
	if (pFile!=NULL && pArrayListEmployee!=NULL)
	{
		do
		{
			pE = employee_new();
			if(pE != NULL && fread(pE, sizeof(Employee), 1, pFile)==1)
			{
				ll_add(pArrayListEmployee, pE);
				idAux= employee_getId(pE, &flag);
				if(indice==0)
				idMaxAux= idAux;
				else if(idAux > idMaxAux)
				idMaxAux = idAux;
				indice++;
			}
			else
			{
				employee_delete2(pE);
			}
		}while(feof(pFile)==0);
	}
    return idMaxAux;
}
