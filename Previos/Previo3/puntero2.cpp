#include <iostream>
using namespace std;
int main() {
    int var = 5;
    int* pointVar;

    // store address of var
    pointVar = &var;

    // print var
    cout << "var = " << var << endl;

    // print *pointVar
    cout << "*pointVar = " << *pointVar << endl << endl;

    cout << "Changing value of var to 7: " << endl;

    // Change value of var to 7
    var = 7;

    // print var
    cout << "var = " << var << endl;

    // print *pointVar
    cout << "*pointVar = " << *pointVar << endl << endl;

    cout << "Changing value of var to 16: " << endl;

    // Change value of var to 16
    *pointVar = 16; // Modificar el contenido que hay en la posicion de mem *pointVar

    // print var
    cout << "var = " << var << endl;

    // print *pointVar
    cout << "*pointVar = " << *pointVar << endl;

    return 0;
}