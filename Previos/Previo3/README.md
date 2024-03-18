# Previo3
Este archivo incluye el uso de funciones y es basado en el video C++ Parte 2.

### Ejemplo 1
Para este ejemplo se crea una función propia `sum` y se llama desde otro archivo (en este caso desde _Previo3.cpp_) logrando así un código más ordenado, para compilar recuerde pasar los archivos correspondientes para que compile de forma correcta, puede usar:
>g++ -o sum.exe ./Previo3.cpp ./sum.cpp

### Ejemplo 2
En este ejemplo se estudian enum (corto para enumeraciones en inglés), esto es un tipo de dato creado por el usuario en el que se asocia una variable con un valor. Es útil cuando se quiere usar una cantidad determinada de opciones que se relacionan entre sí. Para los mismos si no se les agrega un valor entero, automáticamente se gles asigna el valor del dato con su índice correspondiente. Para compilar:
>g++ -o enum.exe .\enum.cpp

### Ejemplo 3
Este ejemplo consiste en el uso de punteros para su comprensión. Se realiza una demostración donde se guarda un valor y se imprime el valor guardado, la dirrección del valor, la dirrección del puntero y el contenido del puntero. Un puntero es nada mas que un tipo de dato (al igual que int, char, etc.) que guarda dirrecciones de memoria. Algunas cosas importantes por recordar, el símbolo `&` se utiliza como "la dirección de memoria de la variable", el símbolo `*` (el contenido de) se usa para declarar un puntero seguido del tipo de variable que van a apuntar, ejemplo
```
int *ptr;  // Puntero de un int
int num = 10;
ptr = &num; // Inicializar 
```

### Ejemplo 4
Cambio de valores utilizando punteros.

### Ejemplo 5
Segundo ejemplo relacionado a punteros demostrando que se puede mostrar la dirrección de un arreglo usando punteros o utilizando el operador de `&`.

### Ejemplo 6
Este sexto ejemplo consiste en que se puede hacer uso de un puntero que apunta hacia otro puntero, aunque no es algo recomendado por su manejabilidad.