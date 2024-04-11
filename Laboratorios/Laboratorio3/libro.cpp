#include "libro.hpp"
#include <iostream>

using namespace std;

// Libro*& = Referencia de una variable tipo puntero
void agregarLibro(Libro*& lista) {
    Libro* nuevoLibro = new Libro; // Nuevo puntero del tipo puntero. New = pedir memoria dinamica

    cout << "Ingrese el titulo del libro: " << endl;
    cin.ignore(); // Sino se muestran 2 opciones a la vez
    getline(cin, nuevoLibro->titulo); // getline para pedir todo lo que ingresa el usuario, no solo la palabra

    cout << "Ingrese el autor del libro: " << endl;
    getline(cin, nuevoLibro->autor);

    cout << "Ingrese el genero del libro: " << endl;
    getline(cin, nuevoLibro->genero);

    nuevoLibro->siguiente = lista; // Agregar el nuevo libro

    lista = nuevoLibro;

    cout << "Libro agregado correctamente " << endl;
}

void mostrarLibros(Libro* lista) {
    if(lista == nullptr) {
        cout << "La libreria no tiene libros." << endl;
        return; // Para que se salga de funcion
    }

    cout << "Lista de libros: " << endl;
    while (lista != nullptr) {
        cout << "Titulo: " << lista->titulo << endl;
        cout << "Autor: " << lista->autor << endl;
        cout << "Genero: " << lista->genero << endl << endl;
        lista = lista->siguiente;
    }
}

void liberarMemoria(Libro*& lista) {
    // Revisar si hay otra lista a la cual apuntar
    // Eliminar lista para que no ocupe memoria, una vez que ya se haya usado la direccion esta guardado en temp
    while (lista != nullptr) {
        Libro* temp = lista;
        lista = lista->siguiente;
        delete temp; // Si no hay un valor a apuntar se libera la memoria
    }
}