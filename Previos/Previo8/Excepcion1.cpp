#include <iostream>
using namespace std;

int main() {

    double numerator, denominator, divide;

    cout << "Enter numerator: ";
    cin >> numerator;

    cout << "Enter denominator: ";
    cin >> denominator;

    // Aqui se intenta de ejecutar el codigo con lo que ingresa el usuario
    try {

        // throw an exception if denominator is 0
        if (denominator == 0)
            throw 0; // Brincar al catch

        // not executed if denominator is 0
        divide = numerator / denominator;
        cout << numerator << " / " << denominator << " = " << divide << endl;
    } 
    // Catch para ver como se maneja la excepcion. El argumento es lo que pasa el throw, en este caso seria el 0. Solo se ejecuta con el throw
    catch (int num_exception) {
        cout << "Error: Cannot divide by " << num_exception << endl;
    }

    return 0;
}