#include <iostream>
#include "Contacto.hpp"
#include "Funciones.hpp"

using namespace std;

#define MAX_PALABRAS 100 // Hay capacidad de 100 palabras

enum Operaciones {
    DIFICULTAD = 1,
    JUGAR,
    AGREGAR,
    DICCIONARIO,
    SALIR
};

int main() {
    std::string palabras[MAX_PALABRAS] = {"curso", "computadoras", "hola", "verde", "perro", "gato"}; // Palabras iniciales

    Contacto listaPalabras[MAX_PALABRAS];

    int numContactos = 6; // Cantidad de palabras iniciales
    int opcion;

    do {
        std::cout << "\nMenu: \n";
        std::cout << "1. Elegir la dificultad del juego (número de intentos).\n";
        std::cout << "2. Iniciar el juego.\n";
        std::cout << "3. Agregar palabras al arreglo de palabras que se escogen aleatoriamente.\n";
        std::cout << "4. Ver diccionario de palabras.\n";
        std::cout << "5. Salir del programa.\n";
        std::cin >> opcion;

        switch(opcion) {
            case DIFICULTAD:
                //std::cout << "Primera palabra: " << palabras[1];
                agregarContacto(listaPalabras, numContactos);
                break;
            case JUGAR:
                mostrarContactos(palabras, numContactos);
                break;
            case AGREGAR:
                buscarContacto(listaPalabras, numContactos);
                break;
            case DICCIONARIO:
                agregarContacto(listaPalabras, numContactos);
                std::cout << "Saliendo del programa... \n";
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