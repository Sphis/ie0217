#include <iostream>
#include "Planeta.hpp"

enum Operaciones {
    IMPRIMIR = 1,
    COMPARAR,
    AGREGAR,
    ELIMINAR,
    SALIR
};

int main() {
    int opcion;
    Pais pais1(1, 1000);

    do {
        std::cout << "\nMenu: \n";
        std::cout << "1. Imprimir informacion de paises.\n";
        std::cout << "2. Comparar paises\n";
        std::cout << "3. Agregar pais.\n";
        std::cout << "4. Eliminar pais.\n";
        std::cout << "5. Salir \n";
        std::cin >> opcion;

        switch(opcion) {
            case IMPRIMIR: {
                int test = pais1.getPib();
                std::cout << test << std::endl;
                // imprimir();
                break;
            }
            case COMPARAR:
                // comparar();
                break;
            case AGREGAR:
                // agregar();
                break;
            case ELIMINAR:
                // eliminar();
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
