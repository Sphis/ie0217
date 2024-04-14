/**
* @file main.cpp
* Archivo main donde se ejecutan las funciones o donde se hace el llamado de las clases y sus métodos.
* También es donde se tiene el menú principal.
*/
#include <iostream>

enum Operaciones {
    AGREGAR = 1,
    ELIMINAR,
    IMPRIMIR,
    MOSTRAR,
    SALIR
};

int main() {
    int opcion; ///< Opcion para el menu ingresado por el usuario

    do {
        std::cout << "\nMenu: \n";
        std::cout << "1. Agregar contacto.\n";
        std::cout << "2. Eliminar contacto.\n";
        std::cout << "3. Imprimir almacenamiento cloud (Hash Table y lista enlazada).\n";
        std::cout << "4. Mostrar todos los contactos.\n";
        std::cout << "5. Salir \n";
        std::cin >> opcion;

        switch(opcion) {
            case AGREGAR: {
                // agregar();
                break;
            }
            case ELIMINAR:
                // eliminar();
                break;
            case IMPRIMIR:
                // imprimir();
                break;
            case MOSTRAR:
                // mostrar();
                break;
            case SALIR:
                std::cout << "Saliendo del programa... \n";
                break;
            default:
                std::cout << "Opcion no valida. Intente de nuevo..\n";
                break;
        }
    } while (opcion != SALIR);

    return 0;
}
