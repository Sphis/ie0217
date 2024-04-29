#include <iostream>
using namespace std;

int main() {
    
    double numerator, denominator, arr[4] = {0.0, 0.0, 0.0, 0.0};
    int index;
    
    cout << "Enter array index: ";
    cin >> index;
    
    try {
        
        // throw exception if array out of bounds
        if (index >= 4)
            throw "Error: Array out of bounds!"; // Aqui se lanza un string
            
        // not executed if array is out of bounds
        cout << "Enter numerator: ";
        cin >> numerator;
    
        cout << "Enter denominator: ";
        cin >> denominator;

        // throw exception if denominator is 0
        if (denominator == 0)
            throw 0; // Aqui se lanza un entero

        // not executed if denominator is 0
        arr[index] = numerator / denominator;
        cout << arr[index] << endl;
    }

    // catch "Array out of bounds" exception
    // Este catch se ejecuta cuando throw es un string
    catch (const char* msg) {
        cout << msg << endl;
    }

    // catch "Divide by 0" exception
    // Este catch se ejecuta cuando throw es un entero
    catch (int num) {
        cout << "Error: Cannot divide by " << num << endl;
    }

    // catch any other exception
    // Este catch se ejecuta cuando no se cumplen ninguno de los otros throw. Funciona similar al default de un switch case
    catch (...) {
        cout << "Unexpected exception!" << endl;
    }
    
    return 0;    
}