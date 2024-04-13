// Selection sort in C++

#include <iostream>
using namespace std;

// function to swap the the position of two elements
void swap(int *a, int *b) { // Se trabaja con enteros punteros
    int temp = *a; // Guardar temporalmente porque sino se pierde el dato. Note que se guarda el CONTENIDO DE a
    *a = *b;
    *b = temp;
}

// function to print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}


void selectionSort(int array[], int size) {
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step; // Indice menor es donde se inicia el paso
        for (int i = step + 1; i < size; i++) {
            // To sort in descending order, change > to < in this line.
            // Select the minimum element in each loop.
            if (array[i] < array[min_idx]) // Condicion para buscar el menor numero
                min_idx = i; // Guardar el valor del indice donde esta el menor numero
        }
    
        // put min at the correct position
        swap(&array[min_idx], &array[step]); // Pasar referencia a la funcion swap (direccion de mem)
    }
}

// driver code
int main() {
    int data[] = {20, 12, 10, 15, 2};
    int size = sizeof(data) / sizeof(data[0]);
    selectionSort(data, size);
    cout << "Sorted array in Acsending Order: \n";
    printArray(data, size);
}
