#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>

using namespace std;

int main() {
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
                
                break;

            case 2:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion no válida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 2);

    return 0;
}
