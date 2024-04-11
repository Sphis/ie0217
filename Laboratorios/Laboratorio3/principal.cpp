#include <iostream>
#include <string>
#include "libro.hpp"

using namespace std;

// Enumeraciones para las opciones del menu
enum opciones {
    AGREGARLIBRO = 1,
    MOSTRAR_LIBROS,
    SALIR,
    OPCIONE_MAX
};

int main() {
    Libro* listaLibros = nullptr;
    int opcion;

    do {
        cout << "Selecciona su opcion: " << endl;
        cout << "1. Agregar libro: " << endl;
        cout << "2. Mostrar todos los libros" << endl;
        cout << "3. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case AGREGARLIBRO:
                agregarLibro(listaLibros);
                break;
            case MOSTRAR_LIBROS:
                mostrarLibros(listaLibros);
                break;
            case SALIR:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no permitida." << endl;
                break;
        }
    } while (opcion != SALIR);

    liberarMemoria(listaLibros);

    return 0;
}