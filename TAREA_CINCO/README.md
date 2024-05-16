# Instrucciones de ejecución
Para compilar el código para esta tarea se utiliza un Makefile. Para que funcione de forma correcta debe estar ubicado en la carpeta de `TAREA_CINCO`, seguidamente se pueden ejecutar los siguientes comandos:

`mingw32-make all` Este comando compila y corre el programa.

`mingw32-make run` Este comando es para ejecutar el programa.

`mingw32-make clean` Este comando es para limpiar los arcivos ejecutables (los .exe). Tenga en cuenta que después de ejecutar este comando, hay que seleccionar la opción `Y` para confirmar.

`mingw32-make build` Este comando compila el código fuente y genera un ejecutable llamado tarea5.x.


# Parte teórico
1. ¿Qué es una expresión regular y cuál es su propósito en programación?

Las expresiones regulares (también conocidas como regex o regexp) son patrones utilizados para buscar y manipular cadenas de texto
de una manera más flexible y poderosa. Permiten realizar búsquedas de patrones dentro de texto, validar cadenas, realizar sustituciones
y mucho más.

2. ¿Qué significan los caracteres especiales . y * en una expresión regular?

- `.`: El punto coincide con cualquier carácter, excepto un salto de línea. Por ejemplo, la expresión regular ca. coincidirá con "cat", "car", "cap", etc.

- `*`: El asterisco representa cero o más repeticiones del elemento anterior. Por ejemplo, la expresión regular ca*t coincidirá con "ct", "cat", "caat", "caa...t", etc.

3. ¿Cómo se pueden agrupar subexpresiones en una expresión regular?

Los paréntesis `()` se utilizan para agrupar elementos en subexpresiones. Esto permite aplicar cuantificadores a grupos enteros y capturar
subcadenas coincidentes. Por ejemplo, (ab)+ coincidirá con "ab", "abab", "ababab", etc., y capturará "ab" como grupo coincidente

4. ¿Qué función cumple la barra invertida \ en una expresión regular?

La barra invertida `\` (llamado escape) se usa si se desea buscar un carácter especial de expresión regular como un carácter literal, debes escaparlo con una barra invertida \. Por ejemplo, \. coincidirá con un punto literal en el texto.

5. Explique cómo se pueden capturar coincidencias usando paréntesis en una expresión regular.

Como se mencionó anteriormente en la pregunta 3, cuando se usan paréntesis en una expresión regular, se crean grupos de captura. Estos grupos se pueden referenciar en operaciones de sustitución.

6. ¿Cuál es la diferencia entre \d y \D en una expresión regular?

`\d` representa cualquier dígito del 0-9, mientras que `\D` representa cualquier caracter que no sea un dígito.

7. ¿Cómo se representa una clase de caracteres en una expresión regular?

Una clase de caracteres se representa mediante el uso de corchetes `[]`, especificando un conjunto de caracteres permitidos en esa posición.

8. ¿Cuál es el propósito del modificador $ en una expresión regular?

El carácter `$` se usa para indicar que la coincidencia debe terminar al final de la cadena. Eje: xyz$ coincidirá solo si la cadena
termina con "xyz".

9. Describa cómo validar una dirección de correo electrónico usando expresiones regulares en C++.

Primero se debe recordar importar la librería de regex, seguidamente se sabe que el un correo está separado por lo general en 4 segmentos, el primero es lo que va antes del símbolo @, esto puede incluir letras, números y símbolo, después de @ sigue la misma lógica, sin embargo, ahora se espera un `.`, después del punto por lo general va un .com, pero sería mejor buscar cualquier texto. La expresión regular se podría ver de la siguiente forma:
(a-zA-Z0-9_.+-]+)@(a-zA-Z0-9_.+-]+)+\.(a-zA-Z0-9_.+-]+)

10. Discuta las implicaciones de rendimiento de utilizar expresiones regulares en aplicaciones de software. ¿Qué técnicas se pueden aplicar para optimizar una expresión regular compleja, especialmente en contextos donde el tiempo de ejecución es crítico?

A veces, el rendimiento se puede ver afectado a la hora de usar expresiones regulares, e inclusive en puede parecer que deja de funcionar, a medida que busca expresiones. Algunas formas de mitigar lo anterior si se dieran estos problemas son los siguientes:
- Considerar la fuente del archivo.
- Usar expresiones regulares estáticas.
- Simplificación de patrones.

https://learn.microsoft.com/en-us/dotnet/standard/base-types/best-practices-regex

11. ¿Qué es un Makefile y cuál es su función en un proyecto de C++?

Los Makefile se utilizan para ayudar a decidir qué partes de un programa grande deben volver a compilarse. En la gran mayoría de los
casos, se compilan archivos C o C++. Es decir, automatizan la compilación.

12. ¿Cuál es la diferencia entre una regla implícita y una regla explícita en un Makefile?

Una regla explícita es aquella que se declara de forma manual en un Makefile (es decir, por el usuario), por otro lado, la implícita son comandos que make infiere automáticamente.

https://www.gnu.org/software/make/manual/html_node/Implicit-Rules.html

13. Explique el propósito de las macros (variables) en un Makefile.

Son utilizados para hacer el código reutilizable, esto ayuda a que el make sea más fácil de manejar y aumenta modularidad.

14. ¿Qué es un objetivo (target) en un Makefile y cómo se define?

Los targets son los resultados que se desean obtener al ejecutar el Makefile. Por ejemplo, un target podría ser compilar un programa o
limpiar archivos generados previamente.

15. ¿Por qué es útil dividir un proyecto de C++ en múltiples archivos fuente y cómo ayuda el uso de Makefiles en este enfoque?

Esto es porque hace que el proyecto sea más ordenado, un proyecto más ordenado es un proyecto que es más fácil de manejar y el que se le hacen más fácil hacer cambios, es decir, aumenta la modularidad, además, los Makefile solo recompilan los archivos modificados, esto facilita la compilación.

16. ¿Cómo se pueden definir dependencias entre los archivos fuente en un Makefile?

Las dependencias son archivos o elementos que el target necesita para construirse. Si una dependencia cambia, Make sabe que debe
reconstruir el target. Esto es esencial para evitar compilaciones innecesarias. Para definirlas se sigue la siguiente estructura:
`target: dependencia1 dependencia2`

17. Explique cómo se puede compilar un proyecto en diferentes sistemas operativos usando un solo Makefile.

Para ello se debe tener en consideración algunas cosas:
- Usar comandos que están disponibles en ambos systemas operativos (en el caso del curso se usa MinGW para usar comandos de Linux).
- Evitar usar rutas definidas, es decir, como `C:\Programs\(...)`, ya que, el formato de rutas cambia de una OS a otra.
- Dentro de make se pueden usar sentencias condicionales para manejar diferentes OS, algunos comandos son `$(shell)` o `$(OS)`. 

https://renenyffenegger.ch/notes/development/make/detect-os

18. ¿Cuál es el propósito de los comandos clean y all en un Makefile?

`Clean` se usa para eliminar archivos generados y es muy útil para volver a compilar desde cero. El comando `all` se usa para correr un make por predeterminado, es decir, si no se le pasan argumentos al make, se va a correr lo que haya en all.

19. Describa cómo se pueden pasar argumentos desde la línea de comandos a un Makefile.

Para pasar argumentos se puede usar argv, de esta forma se maneja los archivos ingresados por el usuario, otra forma es usando variables dentro del makefile, si se tiene una variable definida como en el siguiente caso:
```
VARIABLE := nombre_predeterminado
```
Se puede sobreescribir en la línea de comando de la siguiente forma:
```
make VARIABLE=nuevo_nombre
```

20. Proporcione un ejemplo de una regla en un Makefile que compile un archivo fuente .cpp a un archivo objeto .o.

Un ejemplo sencillo se puede realizar de la siguiente forma:
```
%.o: %.cpp
    g++ -c $< -o $@
```
Donde los caracteres especiales `$<` y `$@` representan el primer requisito y el target de la regla actual respectivamente. En este caso entonces, `$<` representa que los archivos .cpp son los requisitos mientras que `$@` .o son los targets.

# Parte teórica (Makefile)
1. ¿Qué suelen contener las variables CC, CFLAGS, CXXFLAGS y LDFLAGS en un Makefile?
- CC: El compilador que se va a usar (ej: g++).
- CFLAGS: Similar a CXXFLAGS, son opciones de compilación, pero en este caso es para los archivos fuente en C.
- CXXFLAGS: Opciones de compilación para C++, por ejemplo, `CXXFLAGS = -Wall -std=c++11` indica enseñar todos los warnings a la hora de compilar y qué versión del compilador usar (en este caso c++11). 
- LDFLAGS: Esto es una opción para el linker y son pasados al compilador automáticamente cuando el compilador lo llama. Es común para especificar dónde se pueden encontrar los directorios de ciertas librerías.

https://earthly.dev/blog/make-flags/

2. ¿De qué se compone una regla en un Makefile?

Las reglas son instrucciones que dicen cómo crear un target a partir de un conjunto de archivos fuente. Cada regla consta de tres
partes: un target, una lista de dependencias y comandos para construir el target

3. Defina qué es un target y cómo se relaciona con sus prerequisitos.

Los targets son los resultados que se desean obtener al ejecutar el Makefile. Por ejemplo, un target podría ser compilar un programa o
limpiar archivos generados previamente. Los targets son las reglas que definirás en tu Makefile. Los prerequisitos son los archivos necesarios para generar un target.

4. ¿Para qué se utiliza la bandera -I, -c y -o del compilador gcc?

- `-o`: Usado para indicar el nombre del archivo de salida.
- `-I`: Para especificar la ruta de inclusión de los archivos de encabezados.
- `-c`: Para indicar realizar una compilación sin enlazar.

https://linuxhandbook.com/gcc-flags/

5. ¿Cómo se definen y se utilizan las variables en un Makefile? ¿Qué utilidad tienen?

Las variables se declaran como ``VARIABLE = valor`, se referencian dentro del mismo make usando el símbolo `$` (por ejemplo, $(VARIABLE)).
Son útiles para no repetir código, además hace que el código sea más fácil de mantener y modificar ya que, no hay que cambiar partes del código, sino que solo el valor de la variable.

6. ¿Qué utilidad tiene un @ en un Makefile?

Se usa para no imprimir comandos, ejemplos, si tengo `@echo "compiling"` esto significa que la terminal no va a mostrar `compiling`. 

https://anukulverma.wordpress.com/2022/08/14/makefile-symbols/

7. ¿Para qué se utiliza .PHONY en un Makefile?

Los phony targets son targets que no representan archivos físicos, sino acciones que deben realizarse. Por ejemplo, clean es un phony
target clásico que se utiliza para eliminar archivos generados.