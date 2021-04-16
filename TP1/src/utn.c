/*
 * utn.c
 *
 *  Created on: 5 abr. 2021
 	 Author : Ludmila Magri
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

/*	\brief Pedir tipo de operacion, dos numeros y mostrar resultados
 *  \param char* pTextoOperacion: Le pide al usuario que ingrese un operador
 *  \param char* pTextoNumA: Le pide al usuario que ingrese el primer numero
 *  \param char* pTextoNumB: Le pide al usuario que ingrese el segundo numero
 *  \param char* pTextoError: Indica si lo que ingreso el usuario no es un numero
 *  \param int* pNumeroA: Es el primer numero ingresado
 *  \param int* pNumeroB: Es el segundo numero ingresado
 *  \param char* pOperacion: Es el operador
 *  \return retorno = -1 error, retorno = 0 exito
*/
int utn_getNumero (char* pTextoOperacion, char* pTextoNumA, char* pTextoNumB, char* pTextoError, int* pNumeroA, int* pNumeroB, char* pOperacion)
{
	int retorno = -1;

	printf ("%s", pTextoOperacion);
	fflush(stdin);
	if (scanf ("%c", pOperacion) ==1)
	{
		if (*pOperacion == '+' || *pOperacion == '-' || *pOperacion == '*' || *pOperacion == '/' || *pOperacion == '!')
		{
			printf ("%s \n", pTextoNumA);
			fflush(stdin);
			if (scanf ("%d", pNumeroA) ==1)
			{
			    printf ("%s \n", pTextoNumB);
		        fflush(stdin);
				if (scanf ("%d", pNumeroB) ==1)
				{
				    if (pNumeroA != NULL && pNumeroB != NULL)
				    {
					    retorno= 0;
				    }
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
		}
		else
		{
			printf ("\nNo es correcto ese tipo de operacion");
		}
	}
	else
	{
		printf ("Error");
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
			*pResultadoA= factorialX;
		}
		for (int y = operadorB; y>1; y--)
		{
			factorialY*= y;
			*pResultadoB= factorialY;
		}
	}
	else
	{
		printf ("\nNo es posible realizar un factorial de un negativo");
	}
	return retorno;
}
