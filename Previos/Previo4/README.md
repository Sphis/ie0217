# Previo 4
Este es el cuarto previo respecto al curso de Estructuras Abstractas de Datos y Algoritmos para Ingeniería. Este previo consiste en el tema de clases y objetos, inicialmente sus conceptos y cosas como boilerplate, destructor, tipos de acceso y después temas un poco más complejos como sobrecarga de operaciones, herencia y clases amigas.

## Indicaciones para ejecución
Todos los archivos se compilan con el siguiente comando (recuerde estar en la dirección/ruta correcta):
```
g++ -o <nombre del exe> <nombre del cpp>
```
La única excepción son los archivos de `main.cpp` y `persona.cpp`, ya que para ello se usó un archivo encabezado, para compilarlo se usa el siguiente commando:
```
g++ -o <nombre del exe> .\main.cpp .\persona.cpp
```
En ambos casos, una vez compilado, se corre el archivo ejecutable creado.

De forma resumida, todos los ejecutables se compilan usando el siguiente commando (ejecutar una línea a la vez).
```
g++ -o <nombre del exe> .\Animal.cpp
g++ -o <nombre del exe> .\class.cpp
g++ -o <nombre del exe> .\fraccion.cpp
g++ -o <nombre del exe> .\friend_class.cpp
g++ -o <nombre del exe> .\friend_func.cpp
g++ -o <nombre del exe> .\friend_func_2class.cpp
g++ -o <nombre del exe> .\funcionVirtual.cpp
g++ -o <nombre del exe> .\jerarquia herencia1.cpp
g++ -o <nombre del exe> .\jerarquia_herencia2.cpp
g++ -o <nombre del exe> .\jerarquia_herencia3.cpp
g++ -o <nombre del exe> .\main.cpp .\persona.cpp
g++ -o <nombre del exe> .\perro.cpp
g++ -o <nombre del exe> .\protected_members.cpp
g++ -o <nombre del exe> .\students.cpp
g++ -o <nombre del exe> .\students2.cpp
```