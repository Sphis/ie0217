# Intrucciones de ejecución
Para ejecutar el programa se utiliza el siguiente comando:
```
g++ -o .\test.exe .\main.cpp .\Planeta.cpp
```
Seguidamente se corre el ejecutable:
```
.\test.exe
```
Con respecto a la generación del archivo de Doxygen se agrega la carpeta con los archivos HTML, sin embargo, no se logró subir al sitio recomendado de Netlify, sin embargo, si se desea ver el resultado, simplemente se descarga la carpeta `html` y se abre el documento con el nombre de `index.html` para abrir la página principal de lo creado.

# Parte teórica
**1. ¿Qué es la programación orientada a objetos y cuáles son sus principales principios?**

Es un paradigma de programación que se basa en "objetos", las cuales son instancias de clases, los mismos pueden contener datos o código. Una clase es una especie de plantilla en la que se definen los atributos y métodos predeterminados de un tipo de objeto.

Sus principales principios son:
- Encapsulación
- Herencia
- Polimorfismo
- Abstracción

**2. Explique el concepto de ocultamiento de datos y cómo se logra en C++.**

Consiste en restringir el acceso directo a datos para protegerlos y solo permiten que se accesen mediante métodos definidos dentro de una clase. Esto es uno de los principios fundamentales de la programación orientada a objetos (OOP). Dentro de C++ hay 3 tipos de acceso, público, privado y protegido, estos modificadores se utilizan dentro de la definición de la clase para cumplir con el objetivo mencionado anteriormente.
https://www.geeksforgeeks.org/encapsulation-in-cpp/

**3. ¿Cuál es la diferencia entre una clase y un objeto en C++?**

Una clase es una especie de plantilla en la que se definen los atributos y métodos predeterminados de un tipo de objeto. Por otro lado, un objeto es una instancia de una clase que posee un conjunto de propiedades o atributos, de comportamiento y funcionalidad (métodos).

**4. ¿Qué es el polimorfismo y cómo se logra en C++?**

Se refiere a la capacidad de los objetos de una clase base de comportarse de manera diferente en función de su clase derivada. Se implementa en C++ usando un método virtual puro, esto quiere decir que el método requiere ser implementado por todas las clases derivadas, sin embargo, cada clase derivada proporciona su propia implementación del método.

**5. ¿Qué significa el término encapsulamiento en el contexto de la OOP?**

La encapsulación se refiere a la capacidad de una clase para ocultar sus datos internos y proporcionar una interfaz bien definida para interactuar con esos datos.

**6. ¿Cuál es el propósito del constructor y el destructor en una clase de C++?**

Un constructor es un miembro de la función de una clase que tiene el mismo nombre que su clase, esto sirve para inicializar los objetos de una clase. Siempre que se llama un constructor se crea una instancia de la clase. Un destructor similar a un constructor, lleva el lleva el símbolo **~** seguido del nombre de la clase (el destuctor también se llama igual que la clase). Es utilizado para liberar la memoria utilizado para dicho objeto.

https://www.geeksforgeeks.org/difference-between-constructor-and-destructor-in-c/

**7. ¿Investigue cómo se define una clase abstracta en C++ y cuál es su función?**

Una clase abstracta se utiliza cuando una función no se puede dar debido a que no se conoce su implementación, las mismas no pueden ser instanciadas, pero pueden servir como una plantilla para otras clases.
Para definirlo se debe usar la palabra clave `virtual`.

https://learn.microsoft.com/en-us/cpp/cpp/abstract-classes-cpp?view=msvc-170

**8. ¿Investigue qué es un constructor de copia y para qué se utiliza en C++?**

Es un miembro de una función que se usa para inicializar un objeto, utilizando otro objeto de la misma clase, esto significa que se crea una copia del original independiente. Se usa para inicializar miembros de un objeto nuevo creado copiando los miembros de un objeto que ya existe.
https://www.geeksforgeeks.org/copy-constructor-in-cpp/

**9. ¿Investigue qué es el polimorfismo estático y dinámico en C++ y cómo se diferencian?**

El polimorfismo estático se produce durante compilación de un programa y es causado cuando se tienen varias funciones con el mismo nombre, pero utilizan diferentes parámetros.
El dinámico es producido en tiempo real, es decir, en tiempo de ejecución, y es un procedimiento en el que la llamada de un método se le hace una sobrescritura, pero es solucionado en tiempo de ejecución.

- Diferencias:
    - Uno se resuelve en tiempo de compilación y el otro en tiempo de ejecución.
    - Es estático se da cuando hay una sobrecarga de funciones y el dinámico cuando hay una sobrescritura de funciones virtuales y punteros.

https://programmerbay.com/difference-between-static-and-runtime-polymorphism/

**10. ¿Qué son las clases anidadas y cuál es su utilidad en C++?**

Una clase puede declararse dentro del ámbito de otra clase. Una clase de este tipo se denomina "clase anidada". Las clases anidadas se consideran dentro del ámbito de la clase que las encierra y están disponibles para su uso dentro de ese ámbito. Para hacer referencia a una clase anidada desde un ámbito distinto de su ámbito inmediato, debe utilizar un nombre completo.

Es utilizado para que el código sea más ordenado, controlar el acceso a datos y también aumentar el ocultamiento.

https://learn.microsoft.com/en-us/cpp/cpp/nested-class-declarations?view=msvc-170

**11. En el contexto de la programación orientada a objetos en C++, ¿cómo se pueden utilizar los punteros para trabajar con objetos y clases? Explique también por qué los punteros a objetos son útiles en la programación orientada a objetos.**

Los punteros se pueden utilizar para accesar los miembros de una clase, pasar objetos a funciones, también se puede crear un puntero a un objeto específico.

Son útilies en OOP porque es posible asignar memoria de forma dinámica, permitiendo la creación y destrucción de objetos, aumenta el polimorfismo (se puede reutilizar más código) y permite estructuras de datos más eficientes.

https://www.geeksforgeeks.org/base-class-pointer-pointing-to-derived-class-object-in-cpp/

**12. ¿Qué es una función prototipo?**

Una declaración de función precede a la definición de función y especifica el nombre, el tipo de retorno, la clase de almacenamiento y otros atributos de una función. Para ser un prototipo, la declaración de función también debe establecer tipos e identificadores para los argumentos de la función.

https://learn.microsoft.com/en-us/cpp/c-language/function-prototypes?view=msvc-170

**13. ¿Explique los diferentes tipos de miembros que existen en la OOP?**

En el contexto de OOP, los miembros hacen referencia a los componentes de una clase, esto incluye:
- Atributos
- Métodos
- Constructores
- Destructores
Además, es posible controlar su acceso, ya sea haciendolos públicos, privados o protegidos.

**14. ¿Qué es un memory leak?**

Un "memory leak" se da cuando se asigna memoria utilizando la palabra clave `new` y se olvida de desasignar la memoria utilizando la función `delete()` o el operador `delete[]`. Una de las mayores fugas de memoria se produce en C++ por el uso incorrecto del operador delete. 
El operador `delete` debería usarse para liberar un único espacio de memoria asignado, mientras que el operador `delete[]` debería usarse para liberar un array de valores de datos.

https://www.geeksforgeeks.org/memory-leak-in-c-and-how-to-avoid-it/

**15. ¿Qué es y cuál es la importancia de la Herencia multinivel, múltiple y jerárquica de C++?**

La herencia multinivel permite que una clase herede otra clase que puede heredar otra (puede seguir heredando si quisiera), esto permite crear instancias de clases manteniendo propiedades de la clase base y si se quisiera agregando nuevas propiedades a la clase heredada.
La herencia múltiple es posible heredar métodos y atributos de la clase base, es decir, es posible heredar características de diversas fuentes.
Finalmente, la herencia jerárquica una clase base tiene varias clases derivadas, sin embargo, cada clase tiene una sola clase base.

https://www.geeksforgeeks.org/inheritance-in-c/

**16. ¿Qué es la composición y cómo se implementa en C++?**

De la misma forma que un vehículo se compone de partes más pequeñas (i.e. motor, llantas, frenos, etc.), el proceso de construir un objeto complicado a partir de otros objetos sencillos más pequeños se denomina composición de objeto. En C++ cuando se construye un objeto o una estructura estamos esencialmente construyendo un objeto complejo a partir de partes más simples, lo que es composición de objetos. Por esta razón, los structs y las clases se denominan a veces tipos compuestos.

https://www.learncpp.com/cpp-tutorial/composition/

**17. ¿Qué es la sobreescritura de funciones en C++ y cuándo es bueno usarla?**

La sobreescritura de funciones en C++ se denomina como la redefinición de la función de la clase base en su clase derivada con la misma firma, es decir, tipo de retorno y parámetros. Se incluye en la categoría de polimorfismo en tiempo de ejecución.

https://www.geeksforgeeks.org/function-overriding-in-cpp/

**18. ¿Qué es un método y un atributo y cuál es la diferencia entre ellos?**

Un método es un algoritmo asociado a un objeto , cuya ejecución se desencadena tras la recepción de un mensaje. Desde el punto de vista del
comportamiento, es lo que el objeto puede hacer. Un atributo o propiedad es un contenedor de un tipo de dato asociado a un objeto (o a una clase de objetos), que hace los datos visibles desde fuera del objeto y esto
se define como sus características predeterminadas, y cuyo valor puede ser alterado por la ejecución de algún método.
Su diferencia radica en que uno representa el comportamiento o acciones del objeto (método) mientras que el otro representa el estado o propiedades de un objeto.

**19. ¿Qué es el constructor y el destructor en una clase?**

Un constructor es un miembro de función de una clase que tiene el mismo nombre que la clase misma. Su función principal es inicializar los objetos de la clase. Cada vez que se invoca un constructor, se crea una instancia de la clase. Por otro lado, un destructor, que se designa con el símbolo **~** seguido del nombre de la clase (también tiene el mismo nombre que la clase), se utiliza para liberar la memoria utilizada por el objeto correspondiente. Es importante notar que un destructor no inicializa un objeto, sino que se encarga de limpiar los recursos asignados a dicho objeto.

**20. ¿Qué es la sobrecarga de operadores en C++ y cómo se utiliza?**

La sobrecarga de operadores en C++ es una característica de la programación orientada a objetos que permite a los desarrolladores definir el comportamiento de los operadores del lenguaje para trabajar con objetos de una clase personalizada. Esto significa que los operadores como +, -, *, /, entre otros, pueden ser utilizados con objetos de una clase personalizada, y los resultados de estas operaciones pueden ser definidos por quien programe.