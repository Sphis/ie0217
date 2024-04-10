/**
* @file main.cpp
* Archivo main donde se ejecutan las funciones o donde se hace el llamado de las clases y sus métodos.
* También es donde se tiene el menú principal.
*/
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
    int opcion; ///< Opcion para el menu ingresado por el usuario
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
                // int test = pais1.getPib();
                // std::cout << test << std::endl;

                // PaisPrimerMundo test = PaisPrimerMundo(1, 500000, true, true, false);
                // bool network = test.tiene5G();
                // std::cout << network << std::endl;

                // bool aero = test.tieneAeropuerto();
                // std::cout << aero << std::endl;

                // bool centro = test.tieneCID();
                // std::cout << centro << std::endl;

                Continentes test;
                test.infoGeneral();


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
