// Lab3 Pt2 Plataformas - Mario Reyes
// Programa para encontrar mínimo y máximo en array desordenado

#include <stdio.h>

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

int main() {
	int arr[] = {21, 24, 65, 3, 56, 12, 35, 15};
	int size = sizeof(arr) / sizeof(arr[0]);
	int minimo = encontrarMin(arr, size);
	printf("\nEl valor mínimo es %d\n", minimo);
	int maximo = encontrarMax(arr, size);
        printf("\nEl valor máximo es %d\n", maximo);
	return 0;
}
