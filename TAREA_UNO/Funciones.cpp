#include "Funciones.hpp"

void agregarContacto(Contacto listaPalabras[], int &numContactos) {
    Contacto nuevoContacto;
    std::cout << "Ingrese el nombre del contacto: ";
    std::cin >> nuevoContacto.nombre;
    std::cout << "Ingrese el numero de telefono: ";
    std::cin >> nuevoContacto.telefono;

    listaPalabras[numContactos++] = nuevoContacto;
}

void mostrarPalabras(const std::string listaPalabras[], int numContactos) {
    std::cout << "Diccionario de palabras:\n";
    for (int i = 0; i < numContactos; ++i) {
        std::cout << listaPalabras[i] << "\n";
    }
}

void buscarContacto(const Contacto listaPalabras[], int numContactos) {
    std::string nombreBusqueda;
    std::cout << "Ingrese el nombre a buscar: ";
    std::cin >> nombreBusqueda;
    bool encontrado = false;
    for (int i = 0; i < numContactos; i++) {
        if(listaPalabras[i].nombre == nombreBusqueda) {
            std::cout << "Nombre: " << listaPalabras[i].nombre << ", Telefono: " << listaPalabras[i].telefono << "\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado)
    {
        std::cout << "Contacto no encontrado.\n";
    }
    
}