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
    Contacto* listaContactos = nullptr; // Inicialmente no hay contactos
    int opcion; ///< Opcion para el menu ingresado por el usuario
    HashTable HT;
    int numTelefono;
    string nombre;
    int key;

    int capacidad = 5; // Capacidad inicial (se pueden agregar 5 contactos), si se supera este valor la capacidad se duplica
    int numContactos = 0; // Numero de contactos en la memoria de celular
    int numCel = 0; // Numero de contactos en la memoria de celular
    ContactoCel* agenda = (ContactoCel*)malloc(capacidad * sizeof(ContactoCel)); // Agenda seria el puntero que sostiene los contactos
    char nombreCel[100]; // Esto significa que el usuario puede usar 99 caracteres para un nombre

    // En este caso se devuelve puntero nulo
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
                    getline(cin, nombre);
                    strcpy(nombreCel, nombre.c_str());

                    //cin.ignore(); // Sino se muestran 2 opciones a la vez

                    cout << "Ingrese el numero de telefono: " << endl;
                    cin >> numTelefono;
                    cin.ignore(); // Ignorar \n

                    // ARREGLAR nombre cel
                    memCel(agenda, numContactos, numTelefono, nombreCel, capacidad);
                    // HT.agregarElemento(numTelefono, nombre);
                    // agregarContacto(listaContactos, numTelefono, nombre);
                break;
            }
            case ELIMINAR:
                    cout << "Digite el numero de telefono que desea eliminar." << endl;
                    cin >> key;
                    // HT.quitarElemento(key);
                    eliminarContacto(agenda, numContactos);
                break;
            case IMPRIMIR:
                // imprimirContactos();
                // HT.imprimirTabla();
                imprimirCel(agenda, numContactos);
                break;
            case MOSTRAR:
                mostrarContactos(listaContactos);
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
