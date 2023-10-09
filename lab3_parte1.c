// Lab. 3, parte 1 - Mario Reyes
// Este programa busca en un arreglo ordenado, un valor ingresado por el usuario
// Usa tres métodos cada uno en una función aparte: búsqueda lineal, búsqueda binaria
// y búsqueda binaria con recursividad

#include <stdio.h>

// Function prototypes para evitar error de implicit declaration
int busqueda_lineal (int arr[], int size, int userval);
int busqueda_binaria (int arr[], int size, int userval);
int busqueda_recursiva (int arr[], int izq, int der, int userval);

// La función main recibe el valor a buscar y llama a las funciones de búsqueda
int main () {
	int arr[] = {2, 4, 6, 23, 56, 79}; //arreglo ordenado dado
	int size = sizeof(arr) / sizeof(arr[0]); //obtiene cantidad de elementos de arr
	int userval;
	printf("Ingrese un valor entero: ");
	scanf("%d", &userval); //se usa operador & porque scanf recibe puntero
	
	//printf("El valor ingresado es: %d\n", userval);

	int posicion_lineal = busqueda_lineal (arr, size, userval);

	if (posicion_lineal == -1) {
		printf("\n[Búsqueda lineal] El valor %d no fue encontrado\n", userval);
	}
	else {
		printf("\n[Búsqueda lineal] El valor %d está en la posición %d\n", userval, posicion_lineal);
	}
	
	int posicion_binaria = busqueda_binaria (arr, size, userval);

	if (posicion_binaria == -1) {
                printf("\n[Búsqueda binaria] El valor %d no fue encontrado\n", userval);
        }
        else {
                printf("\n[Búsqueda binaria] El valor %d está en la posición %d\n", userval, posicion_binaria);
        }

	int posicion_recursiva = busqueda_recursiva (arr, 0, size - 1, userval);

        if (posicion_recursiva == -1) {
                printf("\n[Búsqueda recursiva] El valor %d no fue encontrado\n", userval);
        }
        else {
                printf("\n[Búsqueda recursiva] El valor %d está en la posición %d\n", userval, posicion_recursiva);
        }


	return 0;


}

// Implementación de las funciones

// 1. Función de búsqueda líneal
// Busca el valor haciendo un barrido por los índices del arreglo
int busqueda_lineal (int arr[], int size, int userval) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == userval) {
			//printf("Valor (%d) encontrado en posición: %d\n", userval, i);
			return i; //si encuentra el valor devuelve posición en arreglo
		}
	}
	//printf("Valor no encontrado\n");
	return -1; //código de error de valor no encontrado
}

// 2. Búsqueda binaria
// Utiliza algoritmo de búsqueda binaria => encuentra el elemento medio del arreglo
// y lo compara para determinar en cuál mitad del arreglo seguir buscando
int busqueda_binaria (int arr[], int size, int userval) {
	// Límites de búsqueda
	int izq = 0;
	int der = size - 1;
	while (izq <= der) {
		int medio = izq + (der - izq) / 2;
		if (arr[medio] == userval) {
			return medio;
		}
		else if (arr[medio] < userval) {
			izq = medio + 1; //valor estaría en mitad superior
		
		}
		else {
			der = medio - 1; //valor estaría en mitad inferior
		}
	}
	return -1; 
}

// 3. Búsqueda binaria recursiva
// Mismo algoritmo de búsqueda binaria, pero en lugar de usar un while loop para repetir la comparación,
// se vuelve a llamar a la función con los nuevos límites (división en mitades)
int busqueda_recursiva (int arr[], int izq, int der, int userval) {
	if (izq <= der) {
		int medio = izq + (der - izq) / 2;
		if (arr[medio] == userval) {
                        return medio;
                }
		// Llamados recursivos a la función hasta encontrar valor
                else if (arr[medio] < userval) {
                        return busqueda_recursiva (arr, medio + 1, der, userval);

                }
                else {
                        return busqueda_recursiva (arr, izq, medio - 1, userval);
                }
	}
	return -1;
}


