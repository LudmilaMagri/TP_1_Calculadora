/*
 * utn.c
 *
 *  Created on: 5 abr. 2021
 	 Author : Ludmila Magri
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

/*	\brief : Mostrar menu
 *  \param char* pTextoMenu: Texto del menu
 *  \param int* pNumeroMenu: Ingresar el numero del menu de opciones
 *  \return retorno = -1 error, retorno = 0 exito
*/

int utn_getMenu (char* pTextoMenu, int* pNumeroMenu)
{
	int retorno = -1;
		printf ("%s", pTextoMenu);
		fflush(stdin);
		if (scanf ("%d", pNumeroMenu)==1)
		{
			if (pNumeroMenu != NULL)
			{
				retorno = 0;
			}
		}

	return retorno;
}

/*	\brief : Pedir el primer numero
 *  \param char* pTextoNumA: Texto para pedir un numero
 *  \param char* pTextoError: Indica si lo que ingreso el usuario no es un numero
 *  \param int* pNumeroA: Es el primer numero ingresado
 *  \return retorno = -1 error, retorno = 0 exito
*/
int utn_getNumeroA (char* pTextoNumA, char* pTextoError, int* pNumeroA)
{
	int retorno = -1;

		printf ("%s \n", pTextoNumA);
		fflush(stdin);
		if (scanf ("%d", pNumeroA) ==1)
		{
			if (pNumeroA != NULL)
			{
				retorno= 0;
			}
			else
			{
				printf ("%s", pTextoError);
			}
		}
		else
		{
			printf ("%s", pTextoError);
		}

	return retorno;
}

/*	\brief : Pedir el segundo numero
 *  \param char* pTextoNumB: Texto para pedir un numero
 *  \param char* pTextoError: Indica si lo que ingreso el usuario no es un numero
 *  \param int* pNumeroB: Es el primer numero ingresado
 *  \return retorno = -1 error, retorno = 0 exito
 */
int utn_getNumeroB (char* pTextoNumB, char* pTextoError, int* pNumeroB)
{
	int retorno = -1;

		printf ("%s \n", pTextoNumB);
		fflush(stdin);
		if (scanf ("%d", pNumeroB) ==1)
		{
			if (pNumeroB != NULL)
			{
				retorno= 0;
			}
			else
			{
				printf ("%s", pTextoError);
			}
		}
		else
		{
			printf ("%s", pTextoError);
		}

	return retorno;
	}

/*	\brief : realizar la suma
 *  \param int operadorA: Primer numero ingresado
 *  \param int operadorB: Segundo numero ingresado
 *  \param int* pResultado: Resultado de la suma
 *  \return retorno = -1 error, retorno = 0 exito
*/

int utn_getSumar (int operadorA, int operadorB, int* pResultado)
{
	int retorno = -1;
	if (pResultado != NULL)
	{
		*pResultado = operadorA+operadorB;
		retorno = 0;
	}
	return retorno;
}

/*	\brief : Realizar la resta
 *  \param int operadorA: Primer numero ingresado
 *  \param int operadorB: Segundo numero ingresado
 *  \param int* pResultado: Resultado de la resta
 *  \return retorno = -1 error, retorno = 0 exito
*/
int utn_getRestar (int operadorA, int operadorB, int* pResultado)
{
	int retorno = -1;
	if (pResultado != NULL)
	{
		*pResultado = operadorA-operadorB;
		retorno = 0;
	}
	return retorno;
}


/*	\brief : realizar la multiplicacion
 *  \param int operadorA: Primer numero ingresado
 *  \param int operadorB: Segundo numero ingresado
 *  \param int* pResultado: Resultado de la multiplicacion
 *  \return retorno = -1 error, retorno = 0 exito
*/
int utn_getMultiplicar (int operadorA, int operadorB, int* pResultado)
{
	int retorno = -1;
	if (pResultado != NULL)
	{
		*pResultado = operadorA*operadorB;
		retorno = 0;
	}
	return retorno;
}

/*	\brief : realizar la division
 *  \param int operadorA: Primer numero ingresado
 *  \param int operadorB: Segundo numero ingresado
 *  \param int* pResultado: Resultado de la division
 *  \return retorno = -1 error, retorno = 0 exito
*/
int utn_getDividir (int operadorA, int operadorB, float* pResultado)
{
	int retorno = -1;
	if (pResultado != NULL && operadorB != 0)
	{
		*pResultado = (float)operadorA/operadorB;
		retorno = 0;
	}
	else
	{
		printf ("\nNo es posible dividir por 0");
	}
	return retorno;
}

/*	\brief : realizar el factoreo
 *  \param int operadorA: Primer numero ingresado
 *  \param int operadorB: Segundo numero ingresado
 *  \param int* pResultadoA: Resultado del factoreo del primer numero ingresado
 *  \param int* pResultadoB: Resultado del factoreo del segundo numero ingresado
 *  \return retorno = -1 error, retorno = 0 exito
*/
int utn_getFactorear (int operadorA, int operadorB, int* pResultadoA, int* pResultadoB)
{
	int retorno = -1;
	int factorialX = 1;
	int factorialY = 1;

	if (pResultadoA != NULL && pResultadoB != NULL && operadorA >0 && operadorB >0)
	{
		retorno = 0;
		for (int x = operadorA; x>1; x--)
		{
			factorialX*= x;
			*pResultadoA = factorialX;
		}
		for (int y = operadorB; y>1; y--)
		{
			factorialY*= y;
			*pResultadoB = factorialY;
		}
	}
	else
	{
		printf ("\nNo es posible realizar un factorial de un negativo");
	}
	return retorno;
}
