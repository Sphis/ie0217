// Este es el ejemplo de como hacer un programa robusto que se vio al final de la clase.
// Uno no robusto seria aquel en donde a la hora de hacer la division no hay ningun 
// manejo de excepciones.
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    int numerador, denominador, resultado;

    cout << "Ingrese el numerador: ";
    cin >> numerador;

    cout << "Ingrese el denominador: ";
    cin >> denominador;

    try {
        if (denominador == 0) {
            throw runtime_error("Error: el denominador no puede ser cero."); // Tirar error de tipo runtime que es un error que pasa en tiempo
            // de ejecucion y es parte de la libreria estandar
        }
        resultado = numerador / denominador;
        cout << "El resultado es: " << resultado << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl; // wjat es usado para retornar un string que explica la excepcion
    }

return 0;

}