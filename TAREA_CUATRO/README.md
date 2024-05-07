# Instrucciones de ejecución

# Parte teórica
### Templates
1. Definición de Templates: Explique el concepto de plantillas en C++ y proporcione un ejemplo simple.

Un template son una característica del lenguaje que permiten crear código genérico que puede trabajar con diferentes tipos de datos y estructuras de datos. En otras palabras, utilizar templates permite escribir funciones y clases que pueden ser usadas con distintos tipos de datos sin necesidad de escribir código específico para cada tipo. Un ejemplo sencillo es si creo un programa que calcula la suma de dos números ingresados por un usuario, en este caso no hay forma de saber si el usuario quiere hacer una suma de enteros o flotantes, por lo que el uso de un template sería ideal en este caso.

2. Sobrecarga de Plantillas: ¿Cómo se realiza la sobrecarga de funciones con plantillas en C++?

Para ello, simplemente se definen funciones con el mismo nombre, pero que reciben distintos parámetros, similar a como se hace con solo funciones. El compilador se encarga de saber cual utilizar basado en los parámetros que se le han pasado.

https://www.geeksforgeeks.org/overloading-function-templates-in-c/

3. Plantillas de Clases: Explique cómo se pueden utilizar plantillas en la definición de clases en C++.

De forma similar a  los functions templates, es posible utilizar class templates para crear una única clase y poder trabajar con distintos tipos de datos. Para ello se define la clase utilizando los parámetros de la plantilla (variable que se crea usando typename), después dentro de la clase se utilizan estos parámetros en lugar de los tipos de datos que normalmente habrían en la clase.

### Excepciones
4. Manejo de Excepciones: Describa los bloques try, catch y throw y cómo se utilizan para el manejo de excepciones en C++.

- try: Aquí iría el código que podría generar una excepción
- throw: Lanza una excepción cuando se detecta un error (no es obligatoria, especialmente si usamos excepciones estándar de C++) además, puede lanzar un objeto de cualquier tipo, generalmente se lanza un objeto que hereda de la clase std::exception.
- catch: Código que maneja la excepción lanzada por throw. Cada bloque de catch indica el tipo de excepción que puede manejar y el código que se ejecutará en caso de que esa excepción suceda.

5. Excepciones Estándar: Nombre al menos tres excepciones estándar proporcionadas por C++ y proporcione ejemplos de situaciones en las que podrían ser útiles.

- std::invalid_argument: Excepción usada para indicar que un argumento dado a una función no es válido, útil cuando el programa le solicita datos al usuario que, por ejemplo, solicitar un numerador y denominador para una división y que el denominador sea 0.
- std::runtime_error: Utilizado para indicar errores que ocurren durante ejecución y que no pueden ser detectados cuando se compila. Por ejemplo si se quiere abrir un archivo el compilador no va a decir nada, por lo que es útil en este escenario.
- std::out_of_range: Indica cuando se intenta de acceder elementos fuera de un rango, por ejemplo, si se le solicita al usuario que escoja el elemento de un arreglo y que esté afuera del rango de dicho arreglo.

6. Política de Manejo de Excepciones: ¿Qué es una política de manejo de excepciones y por qué es importante considerarla al diseñar software?

Es un concepto utilizado para manejar errores que pueden ocurrir durante un programa, esto es porque cuando un error se detecta, el flujo normal del programa se detiene y el mismo crea un objeto de tipo "excepción" que contiene información sobre el error. El proceso de responder a esta excepción es lo que se conoce como manejo de excepciones.
Es importante en software porque ayuda a que el programa sea robusto, más seguro, mejor para el usuario y aumenta su mantebilidad.
https://www.geeksforgeeks.org/exception-handling-in-programming/

7. Noexcept: Explique el propósito de la palabra clave noexcept y cómo se utiliza en C++.

En C++, el operador noexcept es un operador en tiempo de compilación que se utiliza para comprobar si una expresión lanzará una excepción. Comprueba la especificación de excepción de las funciones, pero las funciones no se llaman ni se evalúan en tiempo de ejecución. El compilador comprueba los resultados basándose en la declaración de la función.
Su sintaxis para usarlo es `noexcept(expresión)`, la expresión es la expresión que se quiere evaluar. Esta función no devuelve un valor, sino devuelve `true` si la expresión se garantiza de que no va a arrojar excepciones o `false` en el caso contrario.
https://www.geeksforgeeks.org/noexcept-operator-in-cpp-11/

8. Explique la diferencia entre las excepciones std::logic_error y std::runtime_error.

La excepción de std::logic_error está dado por errores que suceden en la lógica del código en el programa. Son errores que se resuelven revisando el diseño implementado, por ejemplo dividir por cero, argumento inválido de una función, etc.
std::runtime_error son errores que ocurren durante ejecución y que no pueden ser detectados cuando se compila, son impredecibles. Por ejemplo si se quiere abrir un archivo el compilador no va a decir nada, por lo que es útil en este escenario, agotamiento de memoria, etc.

9. Explique qué ocurre cuando una excepción no es capturada.

Se dice que una excepción no es capturada cuando no se encuentra ningún bloque try-catch que maneje la excepción. Lo que ocurre depende de como esté configurado el manejo de excepciones. Algunos ejemplos de que puede ocurrir:
- Impresión de mensaje de error.
- Terminación del programa.

https://cplusplus.com/doc/tutorial/exceptions/

### STL (Standard Template Library)
10. Contenedores STL: Nombre cinco contenedores diferentes de la STL y explique brevemente en qué situaciones sería apropiado usar cada uno.
- std::vector: Cuando se requiere un contenedor dinámico, es decir, su tamaño puede crecer o reducir.

- std::map: Son apropiados cuando se necesita asociar una llave con un valor, por ejemplo asociar el número de un apartamento con el nombre de la persona que recide ahí.

- std::list: Útil cuando se ocupa una estructura de datos que permite de manera fácil la inserción de elementos al final o principio de la lista y que no se requiere acceso aleatorio a los elementos.

- std::queue: Se utiliza cuando se requiere una estructura de datos que sigue la política de FIFO (First in first out), por lo general, es usado para modelar procesos secuenciales.

- std::set: Esta estructura es útil cuando se ocupa almacenar elementos únicos en un contenedor (es decir, que no se quieran elementos duplicados), pero no se requiere acceder a dichos elementos por posición.

https://www.programiz.com/cpp-programming/stl-containers

11. Iteradores en STL: Explique el concepto de iteradores en la STL y cómo se utilizan para acceder a elementos en contenedores.

Un iterador es un objeto similar a un puntero que representa la posición de un elemento en un contenedor. Se utiliza para iterar sobre elementos en un contenedor. Se usa en combinación con sus funciones miembros:
- nums.begin() apunta al primer elemento del vector, es decir, el índice 0.

- nums.begin() + i apunta al elemento en el índice i.

- nums.end() apunta a un elemento más allá del elemento final en el vector.

12. Algoritmos STL: Proporcione ejemplos de al menos tres algoritmos de la STL y describa sus funciones básicas.
- find: Busca un elemento en un rango.
- binary_search: Realiza una búsqueda binaria en un rango ordenado.
- count: Cuenta el número de ocurrencias de un elemento en un rango.
- find_if: Busca el primer elemento que cumple con cierto criterio.
- copy: Copia elementos de un rango a otro.


13. Algoritmos Personalizados: ¿Cómo podría utilizar un algoritmo personalizado con la STL?

Lo primero que se debe hacer es agregar una función que haga el algoritmo que se desea (similar a un algoritmo de STL). Seguidamente hay que utilizar iteradores para poder definir el rango de los elementos, es decir, se ocupa que reconozca iteradores para poder hacer operaciones sobre los elementos. Una vez hecho esto, se procede a usarlo con los algoritmos de STL. Es importante usar un template para que el algoritmo sea genérico.

https://www.geeksforgeeks.org/the-c-standard-template-library-stl/