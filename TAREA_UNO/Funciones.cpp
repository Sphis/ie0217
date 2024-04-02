#include "Funciones.hpp"
#include <vector>

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

void buscarContacto(const Partida listaPalabras[], int numPalabras) {
    std::string nombreBusqueda;
    std::cout << "Ingrese el nombre a buscar: ";
    std::cin >> nombreBusqueda;
    bool encontrado = false;
    for (int i = 0; i < numPalabras; i++) {
        if(listaPalabras[i].nombre == nombreBusqueda) {
            std::cout << "Nombre: " << listaPalabras[i].nombre << ", Telefono: " << listaPalabras[i].telefono << "\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado)
    {
        std::cout << "Partida no encontrado.\n";
    }
    
}