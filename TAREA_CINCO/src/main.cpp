/**
 * @file main.cpp
 * En este archivo es donde se ejecuta lo necesario para que el usuario pueda ingresar correos electrónicos y se verfica
 * si cumplen con ciertos criterios usando regex.
*/
#include "email.hpp"
#include <iostream>

using namespace std;

int main() {
    ValidadorEmail validador;
    string correo;
    int opcion;

    do {
        cout << "Menu:\n";
        cout << "1. Ingresar correo electronico.\n";
        cout << "2. Salir del programa.\n";
        cout << "Seleccione una opcion (ingrese el numero de la opcion): ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el correo electronico: ";
                cin >> correo;
                try {
                    validador.validarCorreo(correo);
                    cout << "El correo es valido.\n";
                } catch (const ExcepcionCorreo& ex) {
                    cout << ex.what() << endl;
                }
                break;

            case 2:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion ingresada no valida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 2);

    return 0;
}
