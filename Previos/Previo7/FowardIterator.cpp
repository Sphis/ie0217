#include <iostream>
#include <forward_list>
using namespace std;

int main() {

    forward_list<int> nums{1, 2, 3, 4};

    // initialize an iterator to point
    // to beginning  of a forward list
    forward_list<int>::iterator itr = nums.begin();

    while (itr != nums.end()) {
        // access iterator value using indirection operator
        int original_value = *itr; // Obtener el contenido del puntero en ese momento

        // assign new value using indirection operator
        *itr = original_value * 2; // Luego el valor obtenido se multiplica por 2

        // forward the iterator to next position
        itr++; // itr es un PUNTERO, por lo que se esta aumentando en un PUNTERO en
        // lugar de una UNIDAD
    }

    // display the contents of nums
    for (int num: nums) {
        cout << num << ", ";
    }
    // En este caso num es un entero que es una copia de cada elemento del contenedor nums,
    // la notacion ":" es que se quiere iterar sobre cada elemento de nums

    return 0;
}