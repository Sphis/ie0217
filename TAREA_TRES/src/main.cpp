/**
* @file main.cpp
* Archivo main donde se ejecutan las funciones o donde se hace el llamado de las clases y sus métodos.
* También es donde se tiene el menú principal.
*/
#include <iostream>
#include <string>
#include "funciones.hpp"
using namespace std;

enum Operaciones {
    AGREGAR = 1,
    ELIMINAR,
    IMPRIMIR,
    MOSTRAR,
    SALIR
};

int main() {
    int opcion; ///< Opcion para el menu ingresado por el usuario
    int numTelefono;
    string nombre;

    // Variables para hashtable
    Contacto* listaContactos = nullptr; // Inicialmente no hay contactos
    HashTable HT; // Crear el hash table
    int key;

    // Variables para la memoria de celular (malloc)
    int capacidad = 5; // Capacidad inicial (se pueden agregar 5 contactos), si se supera este valor la capacidad se duplica
    int numContactos = 0; // Numero de contactos en la memoria de celular
    int numCel = 0; // Numero de contactos en la memoria de celular
    ContactoCel* agenda = (ContactoCel*)malloc(capacidad * sizeof(ContactoCel)); // Agenda seria el puntero que sostiene los contactos
    char nombreCel[50]; // Esto significa que el usuario puede usar 99 caracteres para un nombre

    // agenda es nullptr es porque hubo un fallor
    if (!agenda) { 
        cerr << "Hubo un fallo en la asignacion de memoria." << endl;
        exit(1); // Salir con error
    }

    do {
        cout << "\nMenu: \n";
        cout << "1. Agregar contacto.\n";
        cout << "2. Eliminar contacto.\n";
        cout << "3. Imprimir almacenamiento cloud (Hash Table y lista enlazada).\n";
        cout << "4. Mostrar todos los contactos.\n";
        cout << "5. Salir \n";
        cin >> opcion;

        switch(opcion) {
            case AGREGAR: {
                cout << "Ingrese el nombre del contacto: " << endl;
                cin.ignore(); // Limpiar el buffer sino genera problemas
                getline(cin, nombre); // Guardar nombre para cloud
                strcpy(nombreCel, nombre.c_str()); // Guardar nombre para memoria celular

                cout << "Ingrese el numero de telefono: " << endl;
                cin >> numTelefono;
                cin.ignore();

                memCel(agenda, numContactos, numTelefono, nombreCel, capacidad); // Agregar contacto al celular
                HT.agregarElemento(numTelefono, nombre); // Agregar contacto al hash table
                // agregarContacto(listaContactos, numTelefono, nombre); // Agregar contacto a la lista enlazada
                break;
            }
            case ELIMINAR:
                cout << "Digite el nombre del contacto que desea eliminar." << endl;
                cin >> nombre;
                HT.quitarElemento(nombre); // Eliminar contacto del hash table
                // eliminarContacto(agenda, numContactos); // Elminar contacto de la memoria celular
                break;
            case IMPRIMIR:
                // imprimirContactos(); // Imprimir lista enlazada
                // HT.imprimirTabla(); // Imprimir hash table
                // imprimirCel(agenda, numContactos); // Imprimir memoria celular
                break;
            case MOSTRAR:
                // mostrarContactos(listaContactos);
                break;
            case SALIR:
                cout << "Saliendo del programa... \n";
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo..\n";
                break;
        }
    } while (opcion != SALIR);

    void liberarMemoria();
    return 0;
}
