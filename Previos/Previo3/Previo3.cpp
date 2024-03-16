#include <iostream>
#include "sum.hpp" // Note que lo que se incluye es la declaracion
using namespace std;

// Recuerde que para compilar el archivo hay que pasarle el Previo.cpp y el sum.cpp

int main() {
    int num1 = 5;
    int num2 = 7;
    int result = num1 + num2;

    cout << "El resultado de la suma " << num1 << " + " << num2 << " es igual a: " << result << endl;

    return 0;
}

