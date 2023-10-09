// Lab3 Pt2 Plataformas - Mario Reyes
// Programa para encontrar mínimo y máximo en array desordenado

#include <stdio.h>

// Funciones implementadas antes del main no requieren declarar prototipos

// Función para encontrar mínimo
int encontrarMin(int arr[], int size) {
	int min = arr[0]; //se asume primer elemento como mínimo
	for (int i = 1; i < size; i++) { //loop para buscar mínimo real
		if (arr[i] < min) {
			min = arr[i]; //si se encuentra menor, se actualiza valor mínimo
		}
	}
	return min;
}

// Función para encontrar máximo
int encontrarMax(int arr[], int size) {
        int max = arr[0]; //se asume primer elemento como máximo
        for (int i = 1; i < size; i++) { //loop para buscar máximo real
                if (arr[i] > max) {
                        max = arr[i]; //si se encuentra mayor, se actualiza valor máximo
                }
        }
        return max;
}

// Función para encontrar mínimo y máximo usando punteros
void encontrarMinMax(int *arr, int *min, int *max, int size) {
	// Se desreferencian los punteros min y max para inicializar contenido de memoria
	*min = arr[0];
	*max = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] < *min) {
			*min = arr[i]; //se actualiza valor al que apunta el puntero min
		}
		else if (arr[i] > *max) {
			*max = arr[i]; //se actualiza contenido de memoria al que apunta max
		}
	}
	// La función no retorna valores pero modifica directamente el contenido/valor de la 
	// memoria usando las direcciones pasadas mediante los punteros min y max
}

int main() {
	int arr[] = {21, 24, 65, 3, 56, 12, 35, 15};
	int size = sizeof(arr) / sizeof(arr[0]);
	int minimo = encontrarMin(arr, size);
	printf("\n1. Función mínimo:\nEl valor mínimo es %d\n", minimo);
	int maximo = encontrarMax(arr, size);
        printf("\n2. Función máximo:\nEl valor máximo es %d\n", maximo);
	int min_ptr;
	int max_ptr;
	encontrarMinMax(arr, &min_ptr, &max_ptr, size); //se usa operador & para pasar dirección de variables
	printf("\n3. Función con punteros:\nEl valor mínimo es %d\n", min_ptr);
	printf("El valor máximo es %d\n", max_ptr);

	return 0;
}
