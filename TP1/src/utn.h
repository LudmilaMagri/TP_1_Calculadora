/*
 * utn.h
 *
 *  Created on: 5 abr. 2021
 *      Author: Ludmila Magri
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero (char* pTextoOperacion, char* pTextoNumA, char* pTextoNumB, char* pTextoError, int* pNumeroA, int* pNumeroB, char* pOperacion);
int utn_getSumar (int operadorA, int operadorB, int* pResultado);
int utn_getRestar (int operadorA, int operadorB, int* pResultado);
int utn_getMultiplicar (int operadorA, int operadorB, int* pResultado);
int utn_getDividir (int operadorA, int operadorB, float* pResultado);
int utn_getFactorear (int operadorA, int operadorB, int* pResultadoA, int* pResultadoB);


#endif /* UTN_H_ */
