#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <string>

using namespace std;

struct Contacto {
    string nombre;
    string numeroTelefono;
    Contacto* siguiente; // Puntero que devuelve el siguiente libro. Este puntero se va a usar para la lista enlazada.
};

void agregarContacto(Contacto*& lista);
//void eliminarContacto();
//void imprimirContactos();
void mostrarContactos(Contacto* lista);
void liberarMemoria(Contacto*& lista);

#endif