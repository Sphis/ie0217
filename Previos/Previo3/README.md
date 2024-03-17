# Previo3
Este archivo incluye el uso de funciones y es basado en el video C++ Parte 2.

### Ejemplo 1
Para este ejemplo se crea una función propia `sum` y se llama desde otro archivo (en este caso desde _Previo3.cpp_) logrando así un código más ordenado, para compilar recuerde pasar los archivos correspondientes para que compile de forma correcta, puede usar:
>g++ -o sum.exe ./Previo3.cpp ./sum.cpp

### Ejemplo 2
En este ejemplo se estudian enum (corto para enumeraciones en inglés), esto es un tipo de dato creado por el usuario en el que se asocia una variable con un valor. Es útil cuando se quiere usar una cantidad determinada de opciones que se relacionan entre sí. Para los mismos si no se les agrega un valor entero, automáticamente se les asigna el valor del dato con su índice correspondiente. Para compilar:
>g++ -o enum.exe .\enum.cpp