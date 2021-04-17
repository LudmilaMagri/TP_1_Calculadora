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
a) El resultado de A+B es: r
b) El resultado de A-B es: r
c) El resultado de A/B es: r o No es posible dividir por cero
d) El resultado de A*B es: r
e) �El factorial de A es: r1 y El factorial de B es: r2�
5. Salir
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"


int main(void) {

	setbuf (stdout, NULL);

	int numeroA, numeroB;
	int menu;
	int resultadoSuma, resultadoResta, resultadoMultiplicacion, resultadoFactorialA, resultadoFactorialB;
	float resultadoDivision;
	int respuesta;
	int flagNumA = 0;
	int flagNumB = 0;

	do
	{
		respuesta = utn_getMenu("\n1. Ingresar 1er operando (A=x)"
								"\n2. Ingresar 2do operando (B=y)"
								"\n3. Calcular todas las operaciones "
								"\n4. Informar resultados\n5. Salir\n", &menu);
		switch (menu)
		{
			case 1:
				if (respuesta == 0 && respuesta == utn_getNumeroA ("Ingrese el 1er operando", "Error. Lo que ingreso no es valido. Escriba un numero\n", &numeroA))
				{
					printf ("El 1er operando es : %d \n", numeroA);
					flagNumA = 1;
				}
				break;
			case 2:
				if (respuesta == 0 && respuesta == utn_getNumeroB ("Ingrese el 2do operando", "Error. Lo que ingreso no es valido. Escriba un numero\n", &numeroB))
				{
					printf ("El 2do operando es: %d \n", numeroB);
					flagNumB = 1;
				}

				break;
			case 3:
				if (flagNumA == 0 || flagNumB == 0)
				{
					printf ("\nPor favor ingrese la opcion (1) y (2) para ingresar numeros antes de calcular las operaciones\n");
				}
				else
				{
					printf ("\nPulse el numero 4 para obtener los resultados de las operaciones\n");
				}
				break;
			case 4:
				if (flagNumA == 0 || flagNumB == 0)
				{
					printf ("\nPor favor ingrese la opcion (1) y (2) para ingresar numeros antes de informar los resultados\n");
				}
				else
				{
					if (respuesta == 0 && respuesta == utn_getSumar (numeroA, numeroB, &resultadoSuma))
						printf ("\nEl resultado de %d + %d es: %d", numeroA, numeroB, resultadoSuma);
					if (respuesta == 0 && respuesta == utn_getRestar (numeroA, numeroB, &resultadoResta))
						printf ("\nEl resultado de %d - %d es: %d", numeroA, numeroB, resultadoResta);
					if (respuesta == 0 && respuesta == utn_getDividir(numeroA, numeroB, &resultadoDivision))
						printf ("\nEl resultado de %d / %d es:%.2f", numeroA, numeroB, resultadoDivision);
					if (respuesta == 0 && respuesta == utn_getMultiplicar(numeroA, numeroB, &resultadoMultiplicacion))
						printf ("\nEl resultado de %d * %d es: %d", numeroA, numeroB, resultadoMultiplicacion);
					if (respuesta == 0 && respuesta == utn_getFactorear(numeroA, numeroB, &resultadoFactorialA, &resultadoFactorialB))
						printf ("\nEl factorial de %d! es: %d y el factorial de %d! es: %d \n", numeroA, resultadoFactorialA, numeroB, resultadoFactorialB);
				}
				break;
			}
	}while (menu!=5);


return EXIT_SUCCESS;
}

