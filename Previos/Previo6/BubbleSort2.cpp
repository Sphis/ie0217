// Algoritmo de bubble sort optimizado
#include <iostream>
using namespace std;

// perform bubble sort
void bubbleSort(int array[], int size) {

    // loop to access each array element
    for (int step = 0; step < (size-1); ++step) {
        
        // Bandera para verificar de que el cambio se ha dado
        int swapped = 0;

        // loop to compare two elements
        for (int i = 0; i < (size-step-1); ++i) {

            // compare two array elements
            // change > to < to sort in descending order
            if (array[i] > array[i + 1]) {

                //swapping occurs if elements
                // are not in intended-order
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;

                swapped = 1;
            }
        }

    // no swapping means the array is already sorted
    // so no need of further comparison
    if (swapped == 0) 
        break; // Este if es por si no se ha dado un cambio, que continue con la siguiente
        // iteracion para ahorrar tiempo.
    }
}

// print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << " " << array[i];
    }
    cout << "\n";
}

int main() {
    int data[] = {-2, 45, 0, 11, -9}; // Arreglo de prueba

    // find the array's length
    int size = sizeof(data) / sizeof(data[0]);

    bubbleSort (data, size); // Llamado de funcion de ordenamiento

    cout << "Sorted Array in Ascending Order: \n";
    printArray(data, size);
}
