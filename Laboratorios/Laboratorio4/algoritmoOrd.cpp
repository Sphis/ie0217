#include "algoritmoOrd.hpp"

// Implementacion del sorteo bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Implementacion del selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

// Implementacion del insertion sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Implementacion del partition sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

// Implementacion del quick sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Se comparan algoritmos entre ellas
void generateRandomArray(int arr[], int n) {
    srand(time(0)); // Inicializar semilla
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 10000; // A los arreglos se les manda la referencia del primer elemento, por eso
        // no falta una referencia
    }
}

// Estoy recibiendo un funcion que recibe el puntero de adonde empieza una funcion
void measuringSortingTime(void (*sortingAlgorithm)(int[], int), int arr[], int n, string algorithmName) {
    
    high_resolution_clock::time_point start = high_resolution_clock::now(); // Tipo, nombre de variable, funcion
    sortingAlgorithm(arr, n);
    high_resolution_clock::time_point stop = high_resolution_clock::now(); // Tipo, nombre de variable, funcion
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    // Otra opcion para evitar la linea de arriba:
    // auto declaration = duration_cast<microseconds>(stop - start);

    cout << "Tiempo de " << algorithmName << ": " << duration.count() << " microsegundos" << endl;
}

// Para medir el tiempo del quick sort
void measuringQuickSortTime(void (*sortingAlgorithm)(int[], int, int), int arr[], int low, int high, string algorithmName) {
    high_resolution_clock::time_point start = high_resolution_clock::now(); // Tipo, nombre de variable, funcion
    sortingAlgorithm(arr, low, high);
    high_resolution_clock::time_point stop = high_resolution_clock::now(); // Tipo, nombre de variable, funcion
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    // Otra opcion para evitar la linea de arriba:
    // auto declaration = duration_cast<microseconds>(stop - start);

    cout << "Tiempo de " << algorithmName << ": " << duration.count() << " microsegundos" << endl;
}