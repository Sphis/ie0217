/**
* @file funciones.cpp
* Este archivo es donde se encuentran la lógica de todas las funciones dentro del problema.
*/

#include <iostream>
#include "funciones.hpp"
#include <list>
#include <cstring>

using namespace std;

// Funciones para la lista enlazada:
/**
 * Esta funcion se encarga de tomar la referencia del punter de la lista de contactos y
 * modificarla para agregar un contacto usando su nombre y número de teléfono.
 */
void agregarContacto(Contacto*& lista, int numTelefono, string nombre) {
    Contacto* nuevoContacto = new Contacto; // Pedir memoria dinamica para guardar un contacto

    nuevoContacto->numeroTelefonoLista = numTelefono; // Agregar telefono al contacto
    nuevoContacto->nombreLista = nombre; // Agregar nombre al contacto

    nuevoContacto->siguiente = lista; // Agregar el nuevo Contacto

    lista = nuevoContacto;

    cout << "Contacto agregado correctamente " << endl;
}


/**
 * Funcion que toma un nombre ingresado por el usuario para eliminar contacto de
 * la lista enlazada.
*/
void eliminarContactoLista(Contacto*& lista, string nombre) {
    if (lista == nullptr) {
        cout << "La lista esta vacida" << endl;
        return;
    }

    Contacto* temp = lista; // Apunta al primer elemento
    Contacto* previo = nullptr; // Puntero que apunta al nodo anterior de interes

    // Caso donde el elemento a eliminar es el primero
    if (temp != nullptr && temp->nombreLista == nombre) {
        lista = temp->siguiente;
        delete temp;
        return;
    }

    // Iterar sobre los contactos a ver si esta el nombre ingresado
    while (temp != nullptr && temp->nombreLista != nombre) {
        previo = temp;
        temp = temp->siguiente;
    }

    if (temp == nullptr) {
        cout << "El nombre ingresado " << nombre << " no fue encontrado." << endl;
        return;
    }

    previo->siguiente = temp->siguiente; // Actualizar el puntero para "brincarse" el que se quiere elminar

    delete temp; // Liberar memoria

    cout << "Se ha eliminado " << nombre << " existosamente." << endl;
}


/**
 * Funcion para mostrar los contactos de la lista enlazada.
*/
void mostrarContactos(Contacto* lista) {
    if(lista == nullptr) {
        cout << "La libreria no tiene Contactos." << endl;
        return; // Para que se salga de funcion
    }

    cout << "Memoria cloud (lista enlazada): " << endl;
    while (lista != nullptr) {
        cout << "Nombre: " << lista->nombreLista;
        cout << " Telefono: " << lista->numeroTelefonoLista << endl;
        lista = lista->siguiente;
    }
}

/**
 * Funcion para liberar la memoria de la lista enlazada una vez terminado el programa.
*/
void liberarMemoria(Contacto*& lista) {
    // Revisar si hay otra lista a la cual apuntar
    // Eliminar lista para que no ocupe memoria, una vez que ya se haya usado la direccion esta guardado en temp
    while (lista != nullptr) {
        Contacto* temp = lista;
        lista = lista->siguiente;
        delete temp; // Si no hay un valor a apuntar se libera la memoria
    }
}

// Funciones del hash table:
/**
 * Funcion para saber si la lista esta vacia.
*/
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

/**
 * Funcion hash para encargada de crear una llaves a partir del número de teléfono.
*/
int HashTable::hashFunction(int key) {
    return key % hashGroups; // En este caso si llega 905, la funcion devuelve 5, este seria el key.
}


/**
 * Funcion para agregar contactos nuevos al hash table.
*/
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

/**
 * Funcion para eliminar contactos del hash table basado en un nombre que ingresa el usuario.
*/
void HashTable::quitarElemento(string nombreBorrar) {
    int keyBorrar{};
    // Primero buscar el key con el nombre
    for (int i{}; i < hashGroups; i++) {
        if (tabla[i].size() == 0) continue;

        auto iteradorInicio = tabla[i].begin();
        for (; iteradorInicio != tabla[i].end(); iteradorInicio++) {
            if (iteradorInicio->second == nombreBorrar) {
                keyBorrar = iteradorInicio->first;
                break;
            }
        }
    }

    // Ahora borrar ese key con ese nombre
    int hashValor = hashFunction(keyBorrar);
    auto& cell = tabla[hashValor];
    auto iteradorInicio = begin(cell);
    bool keyExiste = false;

    for (; iteradorInicio != end(cell); iteradorInicio++) {
        if (iteradorInicio->first == keyBorrar) {
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

/**
 * Funcion para imprimir los contactos del hashtable
*/
void HashTable::imprimirTabla() {
    cout << endl << "Memoria cloud (hash table)" << endl;
    for (int i{}; i < hashGroups; i++) {
        if (tabla[i].size() == 0) continue;

        auto iteradorInicio = tabla[i].begin();
        for (; iteradorInicio != tabla[i].end(); iteradorInicio++) {
            cout << "Numero de telefono: " << iteradorInicio->first << " Nombre: " << iteradorInicio->second << endl;
        }
    }
    return;
}

// Funciones para la memoria de celular:
/**
 * Para imprimir la memoria del celular, esto solo para ver que esta funcionando, pero no lo pide el enunciado.
*/
void imprimirCel(ContactoCel* agenda, int numContactos) {
    // Imprimir contactos de la memoria de celular
    cout << "\nMemoria Celular (malloc):\n";
    for (int k = 0; k < numContactos; ++k) {
        cout << "Nombre: " << agenda[k].nombreCel << ", Numero de telefono: " << agenda[k].numTelefono << endl;
    }
}

/**
 * Funcion que agrega contactos a la memoria de celular usando malloc().
*/
void memCel(ContactoCel* agenda, int& numContactos, int numTelefono, const char* nombreCel, int capacidad) {
    // Esto es para ver si se ha superado la capacidad, si es asi, solicitar mas memoria
    if (numContactos >= capacidad) {
        capacidad *= 2; // Aumentar capacidad en doble al inicial
        agenda = (ContactoCel*)realloc(agenda, capacidad * sizeof(ContactoCel)); // Solicitar mas memoria porque se ha superado la capacidad
        if (!agenda) {
            cerr << "Hubo un fallo en la reasignacion de memoria." << endl; // Esto para indicar que hubo un error
            exit(1); // Salir con error
        }
    }

    // Asignar memoria para el nombre del contacto
    agenda[numContactos].nombreCel = (char*)malloc(strlen(nombreCel) + 1); // Solicitar memoria basado en la cantidad de contactos que hay
    if (!agenda[numContactos].nombreCel) {
        cerr << "Hubo un fallo en la asignacion de memoria." << endl;
        exit(1);
    }
    strcpy(agenda[numContactos].nombreCel, nombreCel); // Copiar lo ingresado al nombre del stuct

    // Asignar numero de telefono
    agenda[numContactos].numTelefono = numTelefono;

    ++numContactos; // Se agrego un contacto
}

/**
 * Función que elimina los contactos de la agenda basado en un nombre ingresado por el usuario
 * de la memoria celular (malloc).
*/
void eliminarContacto(ContactoCel* agenda, int& numContactos, string nombreBorrar) {
    for (int k = 0; k < numContactos; ++k) {
        if (agenda[k].nombreCel == nombreBorrar) {
            free(agenda[k].nombreCel); // Borrar el nombre

            agenda[k] = agenda[numContactos - 1];

            --numContactos; // Reducir numero de contactos
            cout << "Se ha eliminado " << nombreBorrar << " exitosamente del cloud (lista enlazada)." << endl;
            return;
        }
    }
    cout << "No se encontro un contacto con ese nombre" << endl;
}

/**
 * Algoritmo de insertion sort para ordenar alfabéticamente el nombre de los contactos 
*/
void insertionSort(ContactoCel arreglo[], int n) {
    // Iterar sobre todos los elementos iniciando desde el segundo
    for (int i = 1; i < n; ++i) {
        ContactoCel copia = arreglo[i]; // Guardar una copia del elemento
        int j = i - 1; // Indice del ultimo elemento de los elementos ordenados

        // Revisar si estan ordenados, de ser asi se desplaza hacia la derecha
        while (j >= 0 && strcmp(arreglo[j].nombreCel, copia.nombreCel) > 0) {
            arreglo[j + 1] = arreglo[j];
            --j;
        }
        arreglo[j + 1] = copia;
    }
}

