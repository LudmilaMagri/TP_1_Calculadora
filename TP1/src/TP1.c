/*
 ============================================================================
 Name        : TP1.c
 Author      : Ludmila Magri

Hacer una calculadora. Para ello el programa iniciar� y contar� con un men� de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) �El resultado de A+B es: r�
b) �El resultado de A-B es: r�
c) �El resultado de A/B es: r� o �No es posible dividir por cero�
d) �El resultado de A*B es: r�
e) �El factorial de A es: r1 y El factorial de B es: r2�
5. Salir
 ============================================================================
 */

/** \brief Pedir tipo de operacion, dos numeros y mostrar resutados
 *  \param int limite: Limite del array
 *  \param int indice: Indica en que posicion cargar los datos
 *  \param char[] nombre: Es el nombre de la persona
 *  \param char[] apellido: Es el apellido de la persona
 *  \param float altura: Es la altura de la persona expresada en metros
 *  \param float peso: Es el peso de la persona expresado en kilos
 *  \return int
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"



int main(void) {

	setbuf (stdout, NULL);

	int numeroA, numeroB;
	char operacion;
	int resultadoSuma, resultadoResta, resultadoMultiplicacion, resultadoFactorialA, resultadoFactorialB;
	float resultadoDivision;
	int respuesta;


	do
		{
			respuesta = utn_getNumero("Ingrese el tipo de operacion [+, - , *, /, !]", "\nIngrese un numero", "\nIngrese otro numero","Error, no es un numero", &numeroA, &numeroB, &operacion);

			if (respuesta == 0)
			{
				switch (operacion)
				{
					case '+':
						utn_getSumar(numeroA, numeroB, &resultadoSuma);
						printf ("\nEl resultado de %d + %d es: %d", numeroA, numeroB, resultadoSuma);
						break;
					case '-':
						utn_getRestar(numeroA, numeroB, &resultadoResta);
						printf ("\nEl resultado de %d - %d es: %d", numeroA, numeroB, resultadoResta);
						break;
					case '*':
						utn_getMultiplicar(numeroA, numeroB, &resultadoMultiplicacion);
						printf ("\nEl resultado de %d * %d es: %d", numeroA, numeroB, resultadoMultiplicacion);
						break;
					case '/':
						respuesta= utn_getDividir(numeroA, numeroB, &resultadoDivision);
						if (respuesta == 0 && respuesta == utn_getDividir(numeroA, numeroB, &resultadoDivision))
						printf ("\nEl resultado de %d / %d es: %2.f", numeroA, numeroB, resultadoDivision);
						break;
					case '!':
						respuesta = utn_getFactorear(numeroA, numeroB, &resultadoFactorialA, &resultadoFactorialB);
						if (respuesta == 0 && respuesta == utn_getFactorear(numeroA, numeroB, &resultadoFactorialA, &resultadoFactorialB))
						printf ("\nEl factorial de %d! es: %d y el factorial de %d! es: %d", numeroA, resultadoFactorialA, numeroB, resultadoFactorialB);
						break;

				}
			}
		}while (operacion != '+' && operacion != '-' && operacion != '*' && operacion != '/' && operacion != '!');

}

