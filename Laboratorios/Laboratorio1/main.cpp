#include <iostream>
#include "Contacto.hpp"
#include "Funciones.hpp"

using namespace std;

#define MAX_CONTACTOS 100

enum Operaciones {
    AGREGAR = 1,
    MOSTRAR,
    BUSCAR,
    SALIR
};

int main() {
    Contacto listaContactos[MAX_CONTACTOS];

    int numContactos = 0;
    int opcion;

    do {
        std::cout << "\nMenu: \n";
        std::cout << "1. Agregar Contacto\n";
        std::cout << "2. Mostrar Contactos\n";
        std::cout << "3. Buscar Contacto\n";
        std::cout << "4. Salir \n";
        std::cin >> opcion;

        switch(opcion) {
            case AGREGAR:
                agregarContacto(listaContactos, numContactos);
                break;
            case MOSTRAR:
                mostrarContactos(listaContactos, numContactos);
                break;
            case BUSCAR:
                buscarContacto(listaContactos, numContactos);
                break;
            case SALIR:
                agregarContacto(listaContactos, numContactos);
                std::cout << "Saliendo del programa... \n";
                break;
            default:
                std::cout << "Opcion no valida. Intente de nuevo..\n";
                break;
        }
    } while (opcion != SALIR);

    return 0;
}