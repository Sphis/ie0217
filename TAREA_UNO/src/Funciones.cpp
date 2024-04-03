/**
* @file Funciones.cpp
* Archivo encargado de almacenar todas las funciones a usar.
*/

#include "Funciones.hpp"
#include <vector>
#include <random>
#include <chrono>
#include <string>
#include <cctype>
#include <iostream>

/**
 * Funcion usada para agregar palabras al arreglo de palabras iniciales
 * @param[in] palabras
 * @param[in] numPalabras
 * @param[out] juego
*/
void agregarPalabra(std::vector<std::string>& palabras, int numPalabras) {
    std::cout << "Ingrese la palabra nueva que desea agregar: ";
    std::string nuevaPalabra;

    std::cin >> nuevaPalabra;
    palabras.push_back(nuevaPalabra);
    for (int i = 0; i < numPalabras; ++i) {
        std::cout << palabras[i] << "\n";
    }
}

/**
 * Funcion para mostrar palabras que hay en en arreglo
 * @param[in] palabras
 * @param[in] numPalabras
*/
void mostrarPalabras(const std::vector<std::string>& palabras, int numPalabras) {
    std::cout << "Diccionario de palabras:\n";
    for (int i = 0; i < numPalabras; ++i) {
        std::cout << palabras[i] << "\n";
    }
}

/**
 * Funcion para inicializar el juego, se encarga de tomar una palabra aleatoria y generar otro dato que es la misma palabra
 * pero con guiones bajos.
 * @param[in] min
 * @param[in] max
 * @param[in] palabras
 * @param[in] juego
 * @param[out] juego
*/
Partida init(int min, int max, const std::vector<std::string>& palabras, Partida& juego) {
    // Obtener el tiempo actual
    auto tiempoActual = std::chrono::system_clock::now();
    auto duracion = tiempoActual.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duracion).count();

    // Generar semilla basado en el tiempo actual
    std::mt19937 gen(static_cast<unsigned int>(millis));

    // Se define la distribucion para que todos los posibles numeros tengan la misma probabilidad de salir
    std::uniform_int_distribution<> dis(min, max);

    int numeroAleatorio = dis(gen);

    // Usar puntero para escoger la palabra
    const std::string* randomWordPtr = &palabras[numeroAleatorio];

    std::string palabra = *randomWordPtr;

    int tamanoPalabra = palabra.size();

    std::string palabraAdivinar = "";

    for (int i = 0; i < tamanoPalabra; i++) {
        palabraAdivinar.append("_");
    }
    
    std::cout << palabraAdivinar << std::endl;

    juego.palabra = palabra; // Guardar la palabra en el struct
    juego.estadoActual = palabraAdivinar; // Guardar los guiones bajos en el struct

    return juego;
}

/**
 * Funcion usada para modificar la dificultad del juego.
 * @param[in] juego
 * @param[out] juego
*/
Partida dificultad(Partida& juego) {
    std::string dificultad;
    bool opcionValida = false;

    std::cout << "Eliga la dificultad:\n"
    "1. Facil: 7 intentos permitidos.\n"
    "2. Intermedio: 5 intentos permitidos.\n"
    "3. Dificil: 3 intentos permitidos.\n";
    std::cin >> dificultad;

    while (opcionValida == false) {
        if (dificultad == "Facil") {
            juego.intentosMax = 7;
            opcionValida == true;
            break;
        } else if (dificultad == "Intermedio") {
            juego.intentosMax = 5;
            opcionValida == true;
            break;
        } else if (dificultad == "Dificil") {
            juego.intentosMax = 3;
            opcionValida == true;
            break;
        } else {
            std::cout << "Debe seleccionar Facil, Intermedio o Dificil\n";
            std::cin >> dificultad;
        }
    }
 
    std::cout << "Intentos = " << juego.intentosMax;
    return juego;
}

/**
 * Funcion encargada de pedirle al usuario que ingrese letras y ver si la letra ingresada coincide con
 * la palabra a adivinar.
 * @param[in] juego
 * @param[out] juego
*/
Partida adivinar(Partida& juego) {
    int tamanoPalabra = juego.palabra.size();
    char letra;
    int correctas = 0;
    bool letraEncontrada = false;

    char* adivinarPtr = &juego.estadoActual[0]; // Puntero para la palabra con guines bajos
    char* originalPtr = &juego.palabra[0]; // Puntero para la palabra original con letras

    while (juego.intentosActual < juego.intentosMax) {
        std::cout << "Ingrese una letra:\n";
        std::cin >> letra;

        for (int k = 0; k < tamanoPalabra; k++) {
            if (originalPtr[k] == letra) {
                adivinarPtr[k] = originalPtr[k]; // Reemplazar guion por letra
                std::cout << "Letra correcta.\n";
                correctas++;
                letraEncontrada = true;
            } else {
                if ((k == (tamanoPalabra - 1)) && (letraEncontrada == false)) {
                    // Solo cuando se haya revisado todas las letras es que puede haber error
                    ++juego.intentosActual; // Caso donde no acierta
                    std::cout << "Letra incorrecta, intente de nuevo.\n";
                }
            }
        }
        letraEncontrada = false;
        std::cout << adivinarPtr << std::endl;

        if (correctas == tamanoPalabra) {
            break; // Ver si ha ganado para no seguir revisando el bucle
        }
    }
    juego.estadoActual = adivinarPtr; // Guardar estado de la palabra adivinada

    return juego;
}

/**
 * Funcion para verificar si el jugador ha ganado o perdido.
 * @param[in] juego
 * @param[out] juego
*/
Partida verificar(Partida juego) {
    if (juego.intentosActual == juego.intentosMax) {
        std::cout << "Ha perdido la partida, se han agotado los intentos." << std::endl;
    } else {
        std::cout << "Ha ganado la partida, la palabra es: " << juego.palabra << std::endl;
    }
    return juego;
}