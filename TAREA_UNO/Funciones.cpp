#include "Funciones.hpp"
#include <vector>
#include <random>
#include <chrono>
#include <string>
#include <cctype>
#include <iostream>

void agregarPalabra(std::vector<std::string>& palabras, int numPalabras) {
    std::cout << "Ingrese la palabra nueva que desea agregar: ";
    std::string nuevaPalabra;

    std::cin >> nuevaPalabra;
    palabras.push_back(nuevaPalabra);
    for (int i = 0; i < numPalabras; ++i) {
        std::cout << palabras[i] << "\n";
    }
}

void mostrarPalabras(const std::vector<std::string>& palabras, int numPalabras) {
    std::cout << "Diccionario de palabras:\n";
    for (int i = 0; i < numPalabras; ++i) {
        std::cout << palabras[i] << "\n";
    }
}

Partida init(int min, int max, const std::vector<std::string>& palabras) {
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
    //std::cout << tamanoPalabra << std::endl;

    std::string palabraAdivinar = "";

    for (int i = 0; i < tamanoPalabra; i++) {
        palabraAdivinar.append("_ ");
    }
    
    std::cout << palabraAdivinar << std::endl;

    Partida juego;

    juego.palabra = palabra; // Guardar la palabra en el struct

    return juego;
}

Partida dificultad(Partida juego) {
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
        } else if (dificultad == "Dificil") {
            juego.intentosMax = 3;
            opcionValida == true;
        } else {
            std::cout << "Debe seleccionar Facil, Intermedio o Dificil\n";
            std::cin >> dificultad;
        }
    }
 
    std::cout << "Intentos = " << juego.intentosMax;
    return juego;
}
// int adivinar(std::string palabra) {
//     int incorrecto, correcto = 0;
//     int tamanoPalabra = palabra.size();
//     char letra;

//     std::cout << "Ingrese una letra\n";
//     std::cin >> letra;

//     for (int k = 0; k < tamanoPalabra; k++)
//     {
//         if (palabra[k] == letra) {
//             correcto++;
//         }
//     }
// }

// std::string init(const std::vector<std::string>& palabras) {
//     std::random_device rd; // Seed for the random number engine
//     std::mt19937 gen(rd()); // Mersenne Twister pseudo-random number generator
//     std::uniform_int_distribution<> dis(0, palabras.size() - 1); // Uniform distribution of integers between 0 and palabras.size()-1

//     int randomIndex = dis(gen); // Generate a random index

//     // Use pointer arithmetic to access the random word
//     const std::string* randomWordPtr = &palabras[randomIndex];

//     // Dereference the pointer to get the random word
//     return *randomWordPtr;
// }

// void buscarContacto(const Partida listaPalabras[], int numPalabras) {
//     std::string nombreBusqueda;
//     std::cout << "Ingrese el nombre a buscar: ";
//     std::cin >> nombreBusqueda;
//     bool encontrado = false;
//     for (int i = 0; i < numPalabras; i++) {
//         if(listaPalabras[i].nombre == nombreBusqueda) {
//             std::cout << "Nombre: " << listaPalabras[i].nombre << ", Telefono: " << listaPalabras[i].telefono << "\n";
//             encontrado = true;
//             break;
//         }
//     }
//     if (!encontrado)
//     {
//         std::cout << "Partida no encontrado.\n";
//     }
    
// }