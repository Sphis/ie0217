# Intrucciones de ejecución

# Parte Teórica
**1. ¿Cuál es la principal diferencia entre C y C++?**

Su principal diferencia es que C es un lenguaje de programación procedural es decir, se basa principalmente en procesos y funciones, por otro lado C++ es un lenguaje de programación orientado a objetos. https://www.freecodecamp.org/news/c-vs-cpp-whats-the-difference/

**2. Explique el propósito y el uso de los siguientes comandos de Git: git init, git add, git commit, git push, git pull, git clone, git branch, git merge.**
- `git init`: Transforma cualquier directorio en un repositorio.
- `git add`: Agregar un archivo a su siguiente commit (stage). (stage o staged hace referencia al contenido agregado que el usuario le ha dicho a Git que quiere incluir).
- `git commit`: Realiza un commit al contenido que está "staged".
- `git push`: Transmite los cambios locales registrados (repositorio local) al repositorio remoto.
- `git pull`: Se hace un fetch y merge de cualquier contenido o cambio realizado al branch remoto en questión.
- `git clone`: Se usa cuando un repositorio ya existe de forma remota y se quiere de forma local.
- `git branch`: Comando que hace un listado de todos los branches disponibles y el que se está actualmente por medio del símbolo *.
- `git merge`: Junta los cambios de un branch específico al branch actual.
https://education.github.com/git-cheat-sheet-education.pdf

**3. ¿Qué es Git y cuál es su propósito en el desarrollo de software?**

Git es un sistema de control de versiones distribuido, gratuito y de código abierto, diseñado para gestionar con rapidez y eficacia desde proyectos pequeños a muy grandes. 
Su propósito en el desarrollo de software se debe a que cada persona puede tener una copia local de código y trabajar de forma simultánea, además, el uso de branches permite tener uno principal en donde el código es estable y funcional y otros branches con "features" o trabajo en progreso que se agregan al branch principal una vez terminado.

https://learn.microsoft.com/en-us/devops/develop/git/what-is-git

**4. ¿Qué es un conflicto de fusión (merge conflict) en Git y cómo se resuelve?**

Este conflicto se debe a que 2 branches diferentes al que les se está haciendo tienen cambios en la misma sección del código/archivo. En un escenario donde una persona A y B han hechos cambios y ambos intentan de hacer merge existen 4 soluciones:
- Mantener los cambios realizadas por la otra persona.
- Quitar los cambios realizados por la otra persona y mantener cambios propios.
- Mantener ambos cambios.
- Quitar ambos cambios.
Todo esto depende del contenido del código y lo que se quiere cambiar, por ejemplo, si 2 personas resuelven el mismo problema no tiene sentido añadir un segundo cambio y es preferible eliminar el cambio.
https://www.freecodecamp.org/news/resolve-merge-conflicts-in-git-a-practical-guide/

**5. ¿Qué es un archivo .gitignore y para qué se utiliza?**

Un archivo de gitignore es un archivo de texto que indica cuales archivos o carpetas se van a ignorar en un proyecto. Es utilizado para descartar archivos que van a ser temporales, por ejemplo un ejecutable después de compilar.
https://www.freecodecamp.org/news/gitignore-what-is-it-and-how-to-add-to-repo/

**6. ¿Qué es una solicitud de extracción (pull request) en GitHub y cómo se utiliza?**

Es una propuesta para hacer un merge de un conjunto de cambios de un branch a otro (por lo general es para incorporar un branch remoto en el main branch). Dentro de la misma propuesta los colaboladores discuten los cambios antes de que se integren al código principal, se hace de esta forma porque la persona que está haciendo los cambios no tiene acceso a hacer un push al main branch. Si se desea hacer un pull request después de haber hecho un fork y los cambios correspondiente, se ingresa a la página de GitHub y se selecciona la opción de "Pull request".
https://www.atlassian.com/git/tutorials/making-a-pull-request

**7. ¿Cuáles son las diferencias fundamentales entre un lenguaje de programación compilado y uno interpretado? Proporcione ejemplos de situaciones en las que sería más óptimo utilizar un lenguaje compilado y otras en las que sería más adecuado un lenguaje interpretado.**

Un lenguaje compilado es aquel que convierte el código en lenguaje de máquina, que puede ser ejecutado por el procesador. Es por esta razón que tiende a ser más eficiente y rápido, además le dan al usuario un mayor control sobre el hardware como CPU y uso de memoria. Como lo indica su nombre debe ser compilado ante cada cambio. Por otro lado un lenguaje interpretado corre cada línea del código y ejecuta cada comando, por un intérprete en tiempo de ejecución.
- Lenguaje compilado:
```
Sistemas operativos.
Drivers.
Firmware (FPGAs o microcontroladores).
```
- Lenguaje interpretado:
```
Desarollo de aplicaciones web.
Scripting y automatizacion.
Educación (son más sencillos de comprender).
```
https://www.freecodecamp.org/news/compiled-versus-interpreted-languages/

**8. Explique qué es un linker en el contexto de un lenguaje de programación compilado. ¿Cuál es su función principal y por qué es esencial en el proceso de compilación?**

Cuando se compila un código el mismo se convierte en lenguaje máquina y estas instrucciones se guardan en un archivo objeto. Un linker es un programa que se encarga de juntar múltiples archivos objeto en un solo archivo de salida deseado, típicamente es un ejecutable. Es de suma importancia porque permite integrar diversos módulos, se asegura de que todas las referencias externas están bien definidas (por ejemplo funciones definidas en otros archivos).
https://www.geeksforgeeks.org/linker/

**9. Describa el flujo de trabajo básico en Git para agregar cambios a un repositorio.**

El flujo de trabajo consiste en:
1. Clonar el repositorio.
2. Modificar o crear archivos.
3. Agregar modificaciones usando `add`.
4. Hacer commit de dichas modificaciones.
5. Hacer `push` una vez asegurado las modificaciones deseadas.
En cualquier punto se puede usar `git status` para saber el estado en el que se está.

**10. Defina qué significa inicializar y declarar una variable.**

La declaración de una variable significa especificar su nombre y tipo antes de que se utilice en el programa, por otro lado, inicializar una variable es darle un valor inicial.
https://www.geeksforgeeks.org/variables-programming/

**11. ¿Qué es la sobrecarga de funciones en C++ y cuáles son sus beneficios?**

Es cuando hay 2 o más funciones que tienen el mismo nombre, pero diferentes parámetros. El compilador se encarga de escoger cuales de las funciones es mejor basado en los parámetros que se la pasan. Sus beneficios incluyen mejor legibilidad, reutilización, flexibilidad, ahorro de memoria, etc.
https://www.geeksforgeeks.org/advantages-and-disadvantages-of-function-overloading-in-cpp/

**12. ¿Qué es un puntero y cómo se utiliza? Explique con un ejemplo de la vida real.**

Un puntero es una variable que almacena la dirección de memoria de otra variable. Un ejemplo real sería tener un código asociado a cada libro de una biblioteca, el código es la referencia que me indica en qué parte de la biblioteca está el libro, en este caso, cada código sería un puntero.

**13. ¿Qué es un branch (rama) en Git y cómo se utiliza?**

Un branch es una versión separada al repositorio principal, esto es sumamente importante porque si quiere probar algo o añadir un feature nuevo, lo puedo hacer sin alterar el main branch, una vez que se termine el feature y se verifica que funciona de forma adecuada se puede hacer un merge para agregarlo al main branch. Para crear una rama nueva se usa el comando:
```
git branch <nombre del branch>
```

**14. ¿Cuál es la principal diferencia entre un bucle do-while y un bucle while?**

Un bucle do-while ejecuta el contenido del bucle al menos una vez, mientras que un bucle while solamenete se ejecuta si se cumple la condición que se le ha dado al bucle.

**15. Explique por qué es útil y común dividir el código en archivos .hpp, .cpp y main.cpp en C++. Describa el propósito específico de cada tipo de archivo.**


Ayuda a mantener el código legible y ordenado, esto se da mucho cuando una persona va a trabajar en un proyecto, no ocupa saber como funciona todo el código, sino que solo le interesa el resultado que recibe de una función ayudando a que el código sea más modular.

_.hpp_ es el archivo encabezado que contiene la declaración de clases, funciones, variables, contantes, etc. Es importante agregar `#ifndef` para que solo se compile una vez.

_.cpp_ es el archvio que contiene las implementaciones de las clases y funciones declarados en el .hpp.

_main.cpp_ es el archivo que posee la función `main()` y es encargado de hacer el llamado de la funciones definidas en los otros archivos, por lo general es donde se tiene el flujo de la lógica del código.  
https://learn.microsoft.com/en-us/cpp/cpp/header-files-cpp?view=msvc-170

**16. ¿Dónde y cómo se guardan las variables que se crean en C++? Explique la diferencia entre el almacenamiento de variables locales y globales.**

Las variables se guardan en memoria del dispositivo, ya que probablemente se usen después. Las variables locales difieren de las globales porque se definen dentro de un bloque de código donde se pretende utilizar y son eliminadas cuando se salen del bloque, es por esta razón que se almacenan en la pila. Por otro lado, las globales se declararan fuera de cualquier función porque son accesibles en cualquier lugar del programa y solamente se eliminan cuando el programa se termina de ejecutar.

**17. ¿Cuál es la diferencia entre pasar parámetros por valor, por referencia y por puntero?**

- Valor: En este caso se manda el valor almacenado en la variable, además el valor de la variable no es modificado, es decir, se mantiene.

- Referencia: Cuando es por referencia se usa el `&`, esto porque lo que se está enviando es la dirección en memoria de la variable, de esta forma se estaría modificando el contenido original de la variable.

- Puntero: Cuando se trabaja con punteros se le está pasando la dirección en memoria de la variable, sin embargo se trabaja con una variable de tipo puntero, por lo que la sintaxis difiere al caso de referencia, en este caso se usa `*`.

El caso de referencia y puntero son similares, pero es importante saber que una referencia no es lo mismo que un puntero, ambos son tipos de datos diferentes.

**18. Cuando se usa un puntero para apuntar a un arreglo en C++, ¿a qué valor o dirección apunta inicialmente? Describa cómo sería la forma de acceder a todos los datos de ese arreglo mediante el puntero.**

El puntero inicia de forma predeterminada a la dirección donde está ubicado el primer elemento del arreglo. Si se quisiera acceder a todos los datos y asumiendo que el puntero está apuntando al primer elemento del arreglo, simplemente se tiene que sumarle una unidad a este valor, el compilador entiende que se está haciendo referencia al siguiente elemento del arreglo.
```
puntero = &arreglo[0]
puntero + 1 = &arreglo[1]
puntero + 2 = &arreglo[2]
(...)
```

**19. Explique para qué son empleados los punteros dobles en C++. Proporcione ejemplos de situaciones en las que los punteros dobles son necesarios o beneficiosos.**

Un puntero es un tipo de dato utilizado para almacenar la dirección de memoria de una variable, entonces cuando se utiliza punteros dobles el primero almacena la dirección de memoria de la variable, mientras que el segundo almacena la dirección de memoria del primer puntero. Hay pocos usos para esto y tras investigar es inclusive una mala práctica, uno de ellos es la asignación dinámica de memoria o arreglos de múltiples dimensiones.
https://www.geeksforgeeks.org/cpp-pointer-to-pointer-double-pointer/

**20. ¿Para qué se utiliza la directiva #ifndef?**

Se utiliza para evitar la inclusión repetida de un encabezado, además, mejora tiempos de compilación y facilidad de mantenimiento del código ya que se evita recompilación innecesaria.
https://marketsplash.com/tutorials/cpp/cplusplus-ifndef/

**21. ¿Qué es el puntero this en C++?**

El puntero `this` es un puntero accesible sólo dentro de las funciones miembro no estáticas de una `class`, `struct` o `union`. Apunta al objeto para el que se llama a la función miembro. Las funciones miembro estáticas no tienen un puntero `this`.
https://learn.microsoft.com/en-us/cpp/cpp/this-pointer?view=msvc-170

**22. ¿Cuál es la diferencia entre un arreglo y una lista en C++?**

- Arreglos
    - Tamaño fijo establecido durante creación.
    - Todos los elementos del arreglo deben ser del mismo tipo.
    - No es tan fácil cambiar su tamaño.
    - Se podría desperdiciar memoria si el arreglo es más grande de lo necesitado.

- Lista
    - Tamaño dinámico y variable.
    - Los elementos del arreglo pueden ser de diferente tipo.
    - Es fácil agregar o quitar elementos.
    - Es más eficiente en términos de memoria porque el tamaño se puede cambiar.

https://www.geeksforgeeks.org/what-is-the-difference-between-lists-and-arrays/

**23. ¿Investigue qué es un memory leak?**

Un "memory leak" se da cuando se asigna memoria utilizando la palabra clave `new` y se olvida de desasignar la memoria utilizando la función `delete()` o el operador `delete[]`. Una de las mayores fugas de memoria se produce en C++ por el uso incorrecto del operador delete. 
El operador `delete` debería usarse para liberar un único espacio de memoria asignado, mientras que el operador `delete[]` debería usarse para liberar un array de valores de datos.

https://www.geeksforgeeks.org/memory-leak-in-c-and-how-to-avoid-it/