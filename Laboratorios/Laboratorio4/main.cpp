#include "algoritmoOrd.hpp"

// Aqui se calculan los tiempos de diferentes algoritmos de ordenamiento
int main() {
    const int SIZE = 10000;
    int arr[SIZE];
    generateRandomArray(arr, SIZE); // Generar arreglo aleatoriamente
    measuringSortingTime(bubbleSort, arr, SIZE, "Bubble Sort"); // Medir tiempo del algoritmo
    generateRandomArray(arr, SIZE); // Hay que generar otro arreglo porque sino le llega ordenado al otro algoritmo
    measuringSortingTime(selectionSort, arr, SIZE, "Selection Sort");
    generateRandomArray(arr, SIZE);
    measuringSortingTime(insertionSort, arr, SIZE, "Insertion Sort");
    generateRandomArray(arr, SIZE);
    measuringQuickSortTime(quickSort, arr, 0, SIZE - 1, "Quick Sort");

    return 0;
}