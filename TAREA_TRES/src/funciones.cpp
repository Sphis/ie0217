#include <iostream>
#include "funciones.hpp"
#include <list>
#include <cstring>

using namespace std;


// Libro*& = Referencia de una variable tipo puntero
void agregarContacto(Contacto*& lista, int numTelefono, string nombre) {
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

// // Funcion para quitar contactos, se quita
// void HashTable::quitarElemento(int key) {
//     int hashValor = hashFunction(key);
//     auto& cell = tabla[hashValor];
//     auto iteradorInicio = begin(cell);
//     bool keyExiste = false;
//     for (; iteradorInicio != end(cell); iteradorInicio++) {
//         if (iteradorInicio->first == key) {
//             keyExiste = true;
//             cell.erase(iteradorInicio);
//             cout << "Se elimino el contacto." << endl;
//             break;
//         }
//     }

//     if (!keyExiste) {
//         cout << "No se ha encontrado contacto con ese numero.";
//     }
//     return;
// }

// TEST TO DELETE WITH NAME
// Funcion para quitar contactos, se quita
void HashTable::quitarElemento(string nombreBorrar) {
    int keyBorrar{};
    // Primero buscar el key con el nombre
    for (int i{}; i < hashGroups; i++) {
        if (tabla[i].size() == 0) continue;

        auto iteradorInicio = tabla[i].begin();
        for (; iteradorInicio != tabla[i].end(); iteradorInicio++) {
            if (iteradorInicio->second == nombreBorrar) {
                cout << "Numero de telefono: " << iteradorInicio->first << " Nombre: " << iteradorInicio->second << endl;
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

        // Funciones para la memoria de celular
// Para imprimir la memoria del celular, esto solo para ver que esta funcionando, pero no lo pide el enunciado
void imprimirCel(ContactoCel* agenda, int numContactos) {
    // Imprimir contactos de la memoria de celular
    cout << "\nAgenda:\n";
    for (int k = 0; k < numContactos; ++k) {
        cout << "Nombre: " << agenda[k].nombreCel << ", Numero de telefono: " << agenda[k].numTelefono << endl;
    }
}

// Funcion que agregar contacto a la memoria de celular usando malloc()
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

    // Set phone number
    agenda[numContactos].numTelefono = numTelefono;

    ++numContactos; // Se agrego un contacto
}

void eliminarContacto(ContactoCel* agenda, int& numContactos) {
    string nombreCel;
    string nombreBorrar;
    cout << "Digite el nombre del usuario que desea borrar" << endl;
    cin >> nombreBorrar;

    for (int k = 0; k < numContactos; ++k) {
        if (agenda[k].nombreCel == nombreBorrar) {
            free(agenda[k].nombreCel); // Borrar el nombre

            agenda[k] = agenda[numContactos - 1];

            --numContactos; // Reducir numero de contactos
            return;
        }
    }
    cout << "No se encontro un contacto con ese nombre" << endl;
}