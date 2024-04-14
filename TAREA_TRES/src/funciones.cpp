#include <iostream>
#include "funciones.hpp"
using namespace std;

// Libro*& = Referencia de una variable tipo puntero
void agregarContacto(Contacto*& lista) {
    Contacto* nuevoContacto = new Contacto; // Nuevo puntero del tipo puntero. New = pedir memoria dinamica

    cout << "Ingrese el nombre del contacto: " << endl;
    cin.ignore(); // Sino se muestran 2 opciones a la vez
    getline(cin, nuevoContacto->nombre); // getline para pedir todo lo que ingresa el usuario, no solo la palabra

    cout << "Ingrese el numero de telefono: " << endl;
    getline(cin, nuevoContacto->numeroTelefono);

    nuevoContacto->siguiente = lista; // Agregar el nuevo Contacto

    lista = nuevoContacto;

    cout << "Contacto agregado correctamente " << endl;
}

void mostrarContactos(Contacto* lista) {
    if(lista == nullptr) {
        cout << "La libreria no tiene Contactos." << endl;
        return; // Para que se salga de funcion
    }

    cout << "Lista de Contactos: " << endl;
    while (lista != nullptr) {
        cout << "Titulo: " << lista->nombre << endl;
        cout << "Autor: " << lista->numeroTelefono << endl;
        lista = lista->siguiente;
    }
}

void liberarMemoria(Contacto*& lista) {
    // Revisar si hay otra lista a la cual apuntar
    // Eliminar lista para que no ocupe memoria, una vez que ya se haya usado la direccion esta guardado en temp
    while (lista != nullptr) {
        Contacto* temp = lista;
        lista = lista->siguiente;
        delete temp; // Si no hay un valor a apuntar se libera la memoria
    }
}