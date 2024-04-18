#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <string>
#include <list>
#include <cstring>

using namespace std;

// Contacto para la memoria celular
struct ContactoCel {
    char* nombreCel;
    int numTelefono;
};

// Contacto a usar para la nube (lista enlazada)
struct Contacto {
    string nombreLista; // Nombre de la persona en la lista enlazada
    int numeroTelefonoLista; // Numero de la persona en la lista enlazada
    Contacto* siguiente; // Puntero que devuelve el siguiente libro. Este puntero se va a usar para la lista enlazada.
};

        // Funciones de lista enlazada
void agregarContacto(Contacto*& lista, int numTelefono, string nombre);
void mostrarContactos(Contacto* lista);
void eliminarContactoLista(Contacto* lista, string nombre);
//void imprimirContactos();
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
        void quitarElemento(string nombreBorrar);
        void imprimirTabla();
};

        // Funciones para la memoria celular
// Para imprimir la memoria del celular, esto solo para ver que esta funcionando, pero no lo pide el enunciado
void imprimirCel(ContactoCel* agenda, int numContactos);
// Funcion que agregar contacto a la memoria de celular usando malloc()
void memCel(ContactoCel* agenda, int& numContactos, int numTelefono, const char* nombreCel, int capacidad);
void eliminarContacto(ContactoCel* agenda, int& numContactos);

#endif