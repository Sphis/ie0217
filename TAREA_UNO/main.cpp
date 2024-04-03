#include <iostream>
#include <vector>
#include "Partida.hpp"
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
    std::vector<std::string> palabras = {"curso", "computadoras", "hola", "verde", "perro", "gato"}; // Palabras iniciales

    Partida listaPalabras[MAX_PALABRAS];

    int numPalabras = 6; // Cantidad de palabras iniciales
    int opcion;

    Partida juego; // Crear datos iniciales del struct

    do {
        std::cout << "\nMenu: \n";
        std::cout << "1. Elegir la dificultad del juego (numero de intentos).\n";
        std::cout << "2. Iniciar el juego.\n";
        std::cout << "3. Agregar palabras al arreglo de palabras que se escogen aleatoriamente.\n";
        std::cout << "4. Ver diccionario de palabras.\n";
        std::cout << "5. Salir del programa.\n";
        std::cin >> opcion;

        switch(opcion) {
            case DIFICULTAD:
            {
                dificultad(juego);
                break;
            }
            case JUGAR:
            {
                //const std::string* palabraAleatoria = init(0, 5, palabras); // Escoger una palabra aleatoria
                Partida juego = init(0, 5, palabras); // Solo hay 6 palabras incialmente, por eso 0, 5
                std::cout << juego.palabra << std::endl;
                break;
            }
            case AGREGAR:
            {
                numPalabras++;
                agregarPalabra(palabras, numPalabras);
                break;
            }
            case DICCIONARIO:
            {
                mostrarPalabras(palabras, numPalabras);
                break;
            }
            case SALIR:
            {
                std::cout << "Saliendo del programa... \n";
                break;
            }
            default:
            {
                std::cout << "Opcion no valida. Intente de nuevo..\n";
                break;
            }
        }
    } while (opcion != SALIR);

    return 0;
}