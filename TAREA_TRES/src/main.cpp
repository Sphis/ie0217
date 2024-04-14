/**
* @file main.cpp
* Archivo main donde se ejecutan las funciones o donde se hace el llamado de las clases y sus métodos.
* También es donde se tiene el menú principal.
*/
#include <iostream>
#include "funciones.hpp"
using namespace std;

enum Operaciones {
    AGREGAR = 1,
    ELIMINAR,
    IMPRIMIR,
    MOSTRAR,
    SALIR
};

int main() {
    Contacto* listaContactos = nullptr;
    int opcion; ///< Opcion para el menu ingresado por el usuario

    do {
        cout << "\nMenu: \n";
        cout << "1. Agregar contacto.\n";
        cout << "2. Eliminar contacto.\n";
        cout << "3. Imprimir almacenamiento cloud (Hash Table y lista enlazada).\n";
        cout << "4. Mostrar todos los contactos.\n";
        cout << "5. Salir \n";
        cin >> opcion;

        switch(opcion) {
            case AGREGAR: {
                agregarContacto(listaContactos);
                break;
            }
            case ELIMINAR:
                // eliminarContacto();
                break;
            case IMPRIMIR:
                // imprimirContactos();
                break;
            case MOSTRAR:
                mostrarContactos(listaContactos);
                break;
            case SALIR:
                cout << "Saliendo del programa... \n";
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo..\n";
                break;
        }
    } while (opcion != SALIR);

    void liberarMemoria();
    return 0;
}
