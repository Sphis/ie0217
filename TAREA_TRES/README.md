# Instrucciones de ejecución

# Parte teórica
**1. ¿Qué es un algoritmo y cuáles son sus características principales?**

Un algoritmo es un conjunto de instrucciones bien definidas para resolver un problema particular. Toma un conjunto de entradas y produce el resultado deseado. Algunas características son:
- La entrada y la salida deben definirse con precisión.
- Cada paso del algoritmo debe ser claro e inequívoco.
- Los algoritmos deberían ser más eficaces entre muchas formas diferentes de resolver un problema.
- Un algoritmo no debería incluir código informático. El algoritmo debe escribirse de tal manera que pueda usarse en diferentes lenguajes de programación.

**2. Explica la diferencia entre un algoritmo eficiente y uno ineficiente.**

La eficiencia de un algoritmo se refiere a la capacidad del algoritmo para utilizar de manera efectiva los recursos disponibles. Un algoritmo eficiente es aquel que realiza una tarea en la menor cantidad de tiempo y utilizando la menor cantidad de memoria posible. Un algoritmo ineficiente es aquel que haría lo contrario, es decir, consume muchos recursos para la tarea que realiza.

**3. ¿Qué es una estructura de datos y por qué son importantes?**

Una estructura de datos es un almacenamiento que se utiliza para almacenar y organizar datos. Es una forma de organizar los datos en una computadora para que se pueda acceder a ellos y actualizarlos de manera eficiente

**4. Describe las diferencias entre una estructura de datos estática y una dinámica.**

Una estructura estática es aquel que tiene un tamaño definido, los contenidos de los datos se pueden cambiar, pero la memoria asignado a el no (ejemplo un arreglo). Una estructura dinámica es todo lo contrario, es decir, el tamaño de la estructura no es fija y puede ser modificada.
https://www.geeksforgeeks.org/static-data-structure-vs-dynamic-data-structure/

**5. ¿Qué es la memoria dinámica y cómo se gestiona en lenguajes de programación como C++, explique las operaciones que se pueden realizar?**

En C++ muchas veces se establece la cantidad de memoria necesaria antes de la ejecución del programa, por ejemplo en la declaración de una variable, sin embargo, hay casos donde la cantidad de memoria necesaria solo se puede conocer durante ejecución (ejemplo que dependa de lo que ingrese el usuario). La forma en que se gestiona es utilizando los operadores `new` para asignar memoria (allocate memory) y `delete` para liberarla o desasignar la (deallocate).
https://cplusplus.com/doc/tutorial/dynamic/

**6. ¿Cuáles son las ventajas y desventajas de la memoria dinámica en comparación con la memoria estática?**
- *Ventajas*
    - Mayor flexibilidad en el tamaño según las necesidades del programa.
    - Aumenta la eficiencia de la memoria para ciertos programas.
    - Poder controlar memoria significa que el programa se puede diseñar de tal forma que se adapte a diferentes casos.
- *Desventajas*
    - Si no se tiene cuidado se puede generar un memory leak.
    - Aumenta la complejidad.
    - Es posible hacer bloques de memoria que no se estén usando por error, haciendo que se gasten recursos.

**7. Explique qué es un árbol binario y cuáles son sus principales características.**

Un árbol binario es una estructura de datos de árbol en la que cada nodo padre puede tener como máximo dos hijos. Cada nodo de un árbol binario consta de tres elementos: datos, dirección del hijo izquierdo, dirección del hijo derecho.

**8. ¿Qué es una cola (queue) y en qué situaciones se utiliza comúnmente?**

Queue o cola en español es similar a la cola de entradas fuera de una sala de cine, donde la primera persona que entra es la primera persona que recibe la entrada. La cola sigue la regla Primero en entrar, primero en salir (FIFO: First-In, First-Out). El elemento que entra primero es el elemento que sale primero. Algunos situaciones donde se utiliza comúnmente son:
- Sistemas de atención al cliente.
- Gestión de procesos en los sistemas operativos.

**9. ¿Cuál es la diferencia entre una cola (queue) y una pila (stack)?**

La diferencia cae en el principio que siguen, la cola sigue el principio FIFO, mientras que el stack sigue el principio LIFO, esto significa que el último elemento insertado dentro de la pila se elimina primero.

**10. Describe cómo funciona el algoritmo de inserción (insert) en una tabla hash.**

Para insertar un par key/valor, primero hay que utilizar la función hash para asignar el key a un índice de la tabla hash. Dado un key, la función hash puede sugerir un índice donde encontrar o almacenar el valor. https://www.freecodecamp.org/news/hash-tables/

**11. ¿Qué es la función de dispersión (hash function) y por qué es importante en las tablas hash?**

En una tabla hash, se procesa un nuevo índice utilizando los keys. Y el elemento correspondiente a ese ley se almacena en el índice. Este proceso se llama hashing. Hashing (o hash function) es una técnica que permite asignar un gran conjunto de datos arbitrarios a índices tabulares mediante una función hash. Es un método para representar diccionarios para grandes conjuntos de datos. https://www.programiz.com/dsa/hash-table

**12. ¿Cuál es la complejidad temporal promedio de búsqueda en una tabla hash bien implementada?**

Para las operaciones de búsqueda, inserción y eliminación, las tablas hash tienen una complejidad temporal media de O(1). Sin embargo, en el peor de los casos, estas operaciones pueden requerir un tiempo O(n), donde n es el número de elementos de la tabla. Esto es porque, en condiciones *ideales*, el tiempo necesario para buscar un elemento en la tabla hash no depende del número de elementos en la tabla. https://www.geeksforgeeks.org/hash-table-data-structure/

**13. Explica cómo se realiza la operación de inserción (push) en una pila (stack).**

La operación push agrega un elemento a la parte superior de una pila, al elemento que se le ha hecho el último push va a ser el elemento más reciente en la pila. Para realizarlo primero se prepara el dato que se quiere almacenar, para realizar un push se necesita espacio en memoria, una vez que se tiene el espacio se coloca el elemento en la parte superior de la pila.

**14. ¿Cuál es la complejidad temporal de las operaciones de apilar (push) y desapilar (pop) en una pila?**

Ambos `push` y `pop` tienen una complejidad temporal de O(1). https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/#complexity-analysis-of-stack-operations

**15. Describe cómo funciona una lista enlazada y cuáles son sus ventajas y desventajas.**

Una lista enlazada es una estructura de datos lineal que incluye una serie de nodos conectados. Cada nodo almacena los datos y la dirección del siguiente nodo.

**16. ¿Qué es un nodo en una lista enlazada y qué contiene?**

Un nodo es lo que almacena los datos y la dirección del siguiente nodo. https://www.programiz.com/dsa/linked-list

**17. ¿Cuál es la diferencia entre una lista enlazada simple y una lista enlazada doblemente enlazada?**

Como se explicó anteriormente, una lista enlazada simple contiene nodos que almacenan 1 solo dato y la dirección del nodo siguiente, en una lista enlazada doblemente enlazada cada nodo posee la dirección del nodo anterior y el del nodo siguiente. https://www.geeksforgeeks.org/data-structures/linked-list/doubly-linked-list/


**18. ¿Cómo se realiza la eliminación (delete) de un nodo en una lista enlazada?**

Depende del nodo que se quiere eliminar, a continuación se presentan los 3 casos:
- Nodo al principio de la lista:
El puntero del inicio de la lista se cambia al del segundo nodo de la lista.

- Nodo al final de la lista:
Se actualiza el puntero al penúltimo nodo de la lista.

- Nodo en medio de la lista:
Se ajusta el puntero al nodo previo al nodo que se va a eliminar y se cambia para que apunte al nodo que le sigue al nodo que se va a eliminar.
https://www.programiz.com/dsa/linked-list-operations#delete

**19. Explica cómo funciona el algoritmo de recorrido (traversal) en un árbol binario.**

Este proceso consiste en visitar cada nodo de una forma sistemática u ordenada. Hay tres tipos:

- Recorrido en orden: Primero, todos los nodos en el subárbol izquierdo. Luego, el nodo raíz. Finalmente todos los nodos en el subárbol derecho.

- Recorrido de pre-orden: Primero, el nodo raíz. Luego, todos los nodos en el subárbol izquierdo. Finalmente todos los nodos en el subárbol derecho.

- Recorrido post-orden: Primero, todos los nodos en el subárbol izquierdo. Luego, todos los nodos en el subárbol derecho. Finalmente, el nodo raíz.

https://www.programiz.com/dsa/tree-traversal

**20. ¿Cuál es la complejidad temporal del recorrido en preorden, en orden y en postorden en un árbol binario balanceado?**

En todos los casos se tiene una complejidad temporal de O(n), donde nn es el número de nodos en el árbol.
https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/

**21. Explique la diferencia entre la notación Big O (O) y la notación Omega () en el análisis de la complejidad temporal de los algoritmos. Proporciona un ejemplo de un algoritmo y determina su complejidad temporal utilizando ambas notaciones Big O y Omega.**

La notación **Big-O** representa el límite superior del tiempo de ejecución de un algoritmo.
Por tanto, proporciona la complejidad del peor de los casos de un algoritmo. Por otro lado la notación **omega** representa el límite inferior del tiempo de ejecución de un algoritmo.
Por lo tanto, proporciona el mejor caso de complejidad de un algoritmo.