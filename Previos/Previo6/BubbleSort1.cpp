#include <iostream>

using namespace std;

// En este bubblesort se hace un recorrido de todos los elementos
// por lo que no es eficiente.

// perform bubble sort
void bubbleSort(int array[], int size) {

    // loop to access each array element
    for (int step = 0; step < size; ++step) {

        // loop to compare array elements
        for (int i = 0; i < size - step; ++i) {

            // compare two adjacent elements
            // change > to < to sort in descending order
            if (array[i] > array[i + 1]) { // Revisar si un elemento es mayor al siguiente

                // swapping elements if elements
                // are not in the intended order
                int temp = array[i]; // Guardar el dato temporalmente
                array[i] = array[i + 1]; // Hacer el cambio de posicion del dato, aqui se borra el dato, por eso temp
                array[i + 1] = temp; // Sustituir el dato temporal
            }
        }
    }
}

// print array
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << " " << array[i];
    }
    cout << "\n";
}

int main() {
    int data[] = {-2, 45, 0, 11, -9};

    // find array's length
    int size = sizeof(data) / sizeof(data[0]); // Calcula el tamaño del dato a usar (en este caso int) y lo divide entre el primer elemento

    bubbleSort(data, size);

    cout << "Sorted Array in Ascending Order:\n";
    printArray(data, size);
}

