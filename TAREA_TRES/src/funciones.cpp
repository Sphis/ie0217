#include <iostream>
#include "funciones.hpp"
#include <list>
#include <cstring>

using namespace std;

// Libro*& = Referencia de una variable tipo puntero
void agregarContacto(Contacto*& lista, string nombre, int numTelefono) {
    Contacto* nuevoContacto = new Contacto; // Pedir memoria dinamica para guardar un contacto

    nuevoContacto->numeroTelefonoLista = numTelefono; // agregar telefono al contacto
    nuevoContacto->nombreLista = nombre; // agregar nombre al contacto

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
        cout << "Nombre: " << lista->nombreLista << endl;
        cout << "Telefono: " << lista->numeroTelefonoLista << endl;
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

// Funcion para saber si la lista esta vacia
bool HashTable::estaVacio() const{
    int sum{};
    for (int i{}; i < hashGroups; i++) {
        sum += tabla[i].size(); // Recorrer para ver si hay algo en la tabla
    }

    if (!sum) {
        return true; // Tabla esta vacida
    }
    return false; // No esta vacida
}

int HashTable::hashFunction(int key) {
    return key % hashGroups; // En este caso si llega 905, la funcion devuelve 5, este seria el key.
}

// Funcion para agregar contactos nuevos
void HashTable::agregarElemento(int key, string value) {
    int hashValor = hashFunction(key); // Calcular el key
    auto& cell = tabla[hashValor];
    auto iteradorInicio = begin(cell); // Este iterador marca la celda inicial
    bool keyExiste = false;
    for (; iteradorInicio != end(cell); iteradorInicio++) {
        if (iteradorInicio->first == key) {
            keyExiste = true;
            iteradorInicio->second = value;
            cout << "El numero que ingreso ya existia, valor reemplazado." << endl;
            break;
        }
    }

    if (!keyExiste) {
        cell.emplace_back(key, value); // Pasar argumento al final de la lista
    }
    return;
}

// Funcion para quitar contactos, se quita
void HashTable::quitarElemento(int key) {
    int hashValor = hashFunction(key);
    auto& cell = tabla[hashValor];
    auto iteradorInicio = begin(cell);
    bool keyExiste = false;
    for (; iteradorInicio != end(cell); iteradorInicio++) {
        if (iteradorInicio->first == key) {
            keyExiste = true;
            cell.erase(iteradorInicio);
            cout << "Se elimino el contacto." << endl;
            break;
        }
    }

    if (!keyExiste) {
        cout << "No se ha encontrado contacto con ese numero.";
    }
    return;
}

void HashTable::imprimirTabla() {
    for (int i{}; i < hashGroups; i++) {
        if (tabla[i].size() == 0) continue;

        auto iteradorInicio = tabla[i].begin();
        for (; iteradorInicio != tabla[i].end(); iteradorInicio++) {
            cout << "Numero de telefono: " << iteradorInicio->first << " Nombre: " << iteradorInicio->second << endl;
        }
    }
    return;
}