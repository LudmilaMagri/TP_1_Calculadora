/*
 * utn.h
 *
 *  Created on: 5 abr. 2021
 *      Author: Ludmila Magri
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getMenu (char* pTextoMenu, int* pNumeroMenu);
int utn_getNumeroA (char* pTextoNumA, char* pTextoError, int* pNumeroA);
int utn_getNumeroB (char* pTextoNumB, char* pTextoError, int* pNumeroB);
int utn_getSumar (int operadorA, int operadorB, int* pResultado);
int utn_getRestar (int operadorA, int operadorB, int* pResultado);
int utn_getMultiplicar (int operadorA, int operadorB, int* pResultado);
int utn_getDividir (int operadorA, int operadorB, float* pResultado);
int utn_getFactorear (int operadorA, int operadorB, int* pResultadoA, int* pResultadoB);

#endif /* UTN_H_ */
