#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <string>
#include <list>
#include <cstring>

using namespace std;

// Contacto a usar para estructuras de datos
struct Contacto {
    string nombre;
    string numeroTelefono;
    Contacto* siguiente; // Puntero que devuelve el siguiente libro. Este puntero se va a usar para la lista enlazada.
};

void agregarContacto(Contacto*& lista);
//void eliminarContacto();
//void imprimirContactos();
void mostrarContactos(Contacto* lista);
//void liberarMemoria(Contacto*& lista);

// Clase utilizada para el hash table
class HashTable {
    private:
        static const int hashGroups = 10;
        list<pair<int, string>> tabla[hashGroups]; // Lista 1, indice 0, lista 2, indice 1, (...), cada par tiene un entero (numero de telefono) 
        // y un nombre

    public:
        bool estaVacio() const;
        int hashFunction(int key);
        void agregarElemento(int key, string value);
        void quitarElemento(int key);
        void imprimirTabla();
};

#endif