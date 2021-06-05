#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/*
// ORDEN
// opcion 1 (leer texto)
// opcion 6 (listar)
// opcion 9 (escribir binario)
// opcion 2 (leer binario)
// opcion 8 (escribir texto)
// ABM
// Ordenar
 * */

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);

    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int idMax;

    do{
    	if (!utn_getNumeroInt(&option,
							"\n\n"
							"\n\t---------------------------------------------------------------------------------"
							"\n\t\t		***** MENU *****							\n"
							"\n\t*	1. Cargar los datos de los empleados desde el archivo (modo texto).\t*"
							"\n\t*	2. Cargar los datos de los empleados desde el archivo (modo binario).\t*"
							"\n\t*	3. Alta de empleado\t\t\t\t\t\t\t*"
							"\n\t*	4. Modificar datos de empleado\t\t\t\t\t\t*"
							"\n\t*	5. Baja de empleado\t\t\t\t\t\t\t*"
							"\n\t*	6. Listar empleados\t\t\t\t\t\t\t*"
							"\n\t*	7. Ordenar empleados\t\t\t\t\t\t\t*"
							"\n\t*	8. Guardar los datos de los empleados en el archivo (modo texto).\t*"
							"\n\t*	9. Guardar los datos de los empleados en el archivo (modo binario).\t*"
							"\n\t*	10. Salir\t\t\t\t\t\t\t\t*"
							"\n\t--------------------------------------------------------------------------------\n\n\n\n\n",
							"\nError opcion invalida", 0, 11, 2))
    	{
			switch(option)
			{
				case 1:
					controller_loadFromText("data.csv",listaEmpleados, &idMax);
					break;
				case 2:
					controller_loadFromBinary("dataBinario.bin", listaEmpleados, &idMax);
					break;
				case 3:
					controller_addEmployee(listaEmpleados);
					break;
				case 4:
					controller_editEmployee(listaEmpleados);
					break;
				case 5:
					controller_removeEmployee(listaEmpleados);
					break;
				case 6:
					controller_ListEmployee(listaEmpleados);
					break;
				case 7:
					controller_sortEmployee(listaEmpleados);
					break;
				case 8:
					controller_saveAsText("data.csv", listaEmpleados);
					break;
				case 9:
					controller_saveAsBinary("dataBinario.bin", listaEmpleados);
					break;
			}
    	}
    }while(option != 10);

    return 0;
}

