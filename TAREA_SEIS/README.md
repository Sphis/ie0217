# Instrucciones
En esta tarea se utiliza MySQL, el resultado de dicha tarea se va a adjuntar a continuación. La forma en que se va a trabajar es que se van a seguir los pasos que se encuentran en el enunciado y se van a adjuntar imágenes de dicho procedimiento mostrando un antes y después de la ejecucion de los comando y una explicación breve. Algunos cursos se toman del plan de licenciatura de ingeniería eléctrica, sin embargo solo se van a incluir los que sean necesarios para cumplir con lo solicitado por la tarea, ya que este proceso demora mucho tiempo (es decir, solo se incluyen lo escencial y no todo el plan).

# Solución de la tarea 6
### 1. Creación de la base de datos y tablas
Basado en la siguiente figura, se observa que, se crea la base de datos mediante el comando ``CREATE DATABASE`` y se usa la palabra clave ``USE`` para indicar que esta es la base de datos a usar. Seguidamente se utiliza el comando ``CREATE TABLE IF NOT EXISTS`` y se escribe el nombre de la tabla a usar. Se usa este comando para indicar de que si la tabla ya fue creada, no volver a crear otra. Finalmente se agregan las características correspondientes a los atributos solicitados por el enunciado. Las palabras claves ``NOT NULL`` y ``UNIQUE`` se usan para no permitir valores nulos en esta columna (porque no tiene sentido que un curso no tenga nombre) y que sea único (porque no tiene sentido que el mismo curso esté 2 veces).

![1](https://github.com/Sphis/ie0217/assets/116931494/cd570627-a4bc-4c74-97a3-703764789bd3)

La razón por la que en la imagen los valores salen como "NULL" es debido a que aún no se han agregado valores a la tabla, solo se ha creado.

El commando ``SELECT * FROM Cursos`` es usado para mostrar la tabla de Cursos en específico, sin embargo se va a utilizar más adelante para mostrar las demás tablas.

Las demás tablas siguen el formato explicado anteriormente, por lo que no se va a entrar mucho a detalle, la única consideración es utilizar las funciones correctas de acuerdo al enunciado. El código para crear las demás tablas se presenta a continuación:
```
-- Creacion de la tabla Requisitos
CREATE TABLE IF NOT EXISTS Requisitos (
    RequisitoID INT AUTO_INCREMENT PRIMARY KEY,
    CursoID INT NOT NULL,
    RequisitoCursoID INT NOT NULL,
    FOREIGN KEY (CursoID) REFERENCES Cursos(CursoID),
    FOREIGN KEY (RequisitoCursoID) REFERENCES Cursos(CursoID)
);

-- Creacion de la tabla Descripciones
CREATE TABLE IF NOT EXISTS Descripciones (
    DescripcionID INT AUTO_INCREMENT PRIMARY KEY,
    CursoID INT NOT NULL,
    Descripcion TEXT NOT NULL,
    Dificultad ENUM('Fácil', 'Media', 'Difícil') NOT NULL,
    FOREIGN KEY (CursoID) REFERENCES Cursos(CursoID)
);

-- Mostrar tablas
SELECT * FROM Cursos;
SELECT * FROM Requisitos;
SELECT * FROM Descripciones;
```

Con esto se crean las tablas correspondientes al primer paso, como se observa en las siguientes imágenes:

![2](https://github.com/Sphis/ie0217/assets/116931494/5e58fbe8-7d21-498d-a10f-56490e556b5e)

![3](https://github.com/Sphis/ie0217/assets/116931494/f3701d7a-db5b-436a-a6ed-63980a6c9891)


### 2. Inserción de datos
Para este caso se empiezan a agregar datos, para agregar datos a una tabla hay que utilizar el comando `INSERT INTO` seguido de la tabla al que se le quieren insertar los datos. Puesto que queremos ingresar datos a la tabla de `Cursos` el comando completo sería de la forma `INSERT INTO Cursos (Sigla, Nombre, Semestre, Creditos) VALUES` donde después de `VALUES` se agrega los valores en el mismo orden de los atributos que están dentro del paréntesis, entonces `('IE-0579', 'Administracion de sistemas', 9, 4)` estaría agregando un curso con las siglas IE-0579 con el nombre de Administracion de sistemas, está en el semestre 9 y vale 4 créditos. El resultado de ejecutar esto se observa en la siguiente imagen:

![4](https://github.com/Sphis/ie0217/assets/116931494/95a8d48f-d0c0-4ef5-bdfe-1bebb7e2dc8f)

Se observa que los datos se guardaron de forma correcta en la figura.

Las otras tablas trabajan de la misma forma, solo hay que tener en cuenta que sus atributos cambian de acuerdo a la tabla. Otro punto importante es que las otra tablas deben referenciar a Cursos, para esto se utiliza el comando 
```
INSERT INTO Requisitos (CursoID, RequisitoCursoID) VALUES
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0679'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0579'))
```
Este comando ingresa datos a la tabla de Requisitos. Primeramente realiza una busqueda de la tabla `Cursos`, seguidamente en esa tabla busca la columna `Sigla` continua buscando en esa columna la fila que contenga el valor `IE-0679`. Una vez determinado que los valores existen crea un vínculo indicando que el curso `IE-0679` tiene como requisito el curso `IE-0579`, es decir, Ciencia de datos va a tener como requisito el curso de Administración de sistemas. El resultado de ingresar los datos se muestra en la siguiente imagen:

![5](https://github.com/Sphis/ie0217/assets/116931494/9701b8c5-0264-4fd3-81fa-94648e3b2bdd)

Se observa que las tablas se actualizaron y basado en la imagen anterior (imagen 4) se verifica que los vínculos se crearon de forma adecuada, ya que la columna de `CursoID` contiene los valores 3 y 4, que corresponden a los cursos de Ciencia de datos y Desarrollo de aplicaciones web tienen como requisito (columna de RequisitoCursoID) 1 y 2 que son Administración de sistemas y Seguridad Ocupacional, esto concuerda con el análisis realizado anteriormente.

La tabla de Descripciones funciona como una combinación de los 2 casos anteriores, es decir, se realiza una busqueda la sigla del curso, se agrega valores de descripción y el nivel de dificultad. El resultado se muestra a continuación:

![6](https://github.com/Sphis/ie0217/assets/116931494/07d1c4b3-9a13-4080-88b1-8dcb02810672)


### 3. Consultas
- **Consulta para listar todos los cursos con su sigla, nombre, semestre, créditos, descripción y dificultad.**

Para este punto, se debe considerar que los cursos están en la tabla de `Cursos`, pero las descripciones y dificultades están en la tabla de `Descripciones`, por lo que se requiere un comando para "unir" las tablas y así, poder cumplir con lo solicitado. Para unir 2 tablas se utiliza el comando `JOIN`, en este caso se usa la el comando `FROM Cursos` seguido de `JOIN Descripciones` me indica que voy a unir ambas tablas, lo que sigue después de `ON` indica bajo que condición quiero que se una, para `Cursos.CursoID = Descripciones.CursoID` esto sería que quiero que se una donde la columna de `CursoID` de la tabla `Cursos` coincide con la columna de `CursoID` de la tabla `Descripciones`. Finalmente `SELECT` para escoger las columnas que quiero tener en esta nueva tabla o solicitud. También es importante saber que ambos de estos datos son compartidos, es decir, tiene el mismo valor (Cursos.CursoID y Descripciones.CursoID). El resultado se muestra en la siguente imágen:

![7](https://github.com/Sphis/ie0217/assets/116931494/8946eb06-1a1d-4a42-884b-c9c05bdb2edd)

Se observa que la consulta se realiza de forma correcta mostrando los 5 cursos que se habían agregado anteriormente a pesar de que no se ha creado esta tabla (porque es una consulta).

- **Consultas para listar todos los requisitos de un curso específico.**

En este caso el flujo de lógica es como sigue, se realiza una consulta a la tabla de `Requisitos`, después se hace un `JOIN` de la tabla de `Requisitos` con la tabla de `Cursos`, en este caso la tabla de `Cursos` se le hace un aliasing (que es cambiarle el nombre para que sea más fácil de manejar, en este contexto `c1` es lo mismo que `Cursos`) llamado `c1`, entonces se tiene una tabla que enlaza `CursoID` en `Requisitos` a `CursoID` en `Cursos`, esto para obtener los detalles de los cursos. Lo mismo sucede con `c2`, lo que cambia es que se hace un enlace de `RequisitoCursoID` en `Requisitos` a `CursoID` en `Cursos` para obtener los requisitos. En la condición de `WHERE` se específica el curso que se quiere consultar. Todo esto genera el siguiente resultado:

![8](https://github.com/Sphis/ie0217/assets/116931494/6a859df3-b96d-47f2-8c9a-5ab32eb47501)

Lo cual, se observa que va de acuerdo con el plan de estudios (en este caso no se insertó el otro requisito, ya que sería repetir código para el otro curso).

- **Consulta para listar los cursos que no son optativos.**

Para este apartado se realizaron modificaciones, ya que no se habían agregado optativas, sin embargo no se van a explicar porque se utilizaron los mismos comandos para agregar cursos y descripciones de los incisos anteriores, las datos nuevos de las tablas se observa a continuación:

![11](https://github.com/Sphis/ie0217/assets/116931494/b218f2f4-3e61-4934-9e98-5f36a08d4909)

![12](https://github.com/Sphis/ie0217/assets/116931494/f96c57f3-f3d5-41c3-9cf4-1e1333ef83bc)

![13](https://github.com/Sphis/ie0217/assets/116931494/f270c436-9843-4187-a4ed-9c6522c62ffb)

Ya con los datos disponibles se utiliza el siguiente comando para ver listar los cursos que no son optativos.

![14](https://github.com/Sphis/ie0217/assets/116931494/6a8e638f-660a-4df5-9558-3f53d7d35ecb)

En este caso, se usa `C` como una alias a `Cursos` y `D` como una alias a `Descripciones` (para que no haya que escribir estas dos palabras cada vez), seguidamente se realiza una union entre las tablas de `Cursos` y `Descripciones` mediante la identificación del curso (esto para mostrar toda la información respecto a dicho curso y no solamente una de las tablas) y se realiza una búsqueda condicional usando un `WHERE`, específicamente se busca en la columna de `Descripcion` para ver si hay alguna celda que contiene la palabra clave de `Optativa`, si es así que no se incluya en el query. Se observa que ninguno de los optativas (IE-0117, IE-0217, IE-0365) aparecen en el resultado.

- **Listar los cursos que pertenecen al semestre X.**

Para esto se hace una busqueda condicional (`WHERE`) donde el valor de `Semestre` sea igual a un valor X, en este caso se toma el décimo semestre. A continuación se presenta el resultado junto con el código.

![10](https://github.com/Sphis/ie0217/assets/116931494/955c8a60-2043-4238-aa67-ce2a54199de5)

### 4. Actualizaciones
**Actualiza el nombre y creditos de 3 de los cursos optativos**

Para realizar esto, se hace uso del comando `UPDATE` para actualizar valores existentes y se usa `SET` para establecer el valor un valor nuevo en la columna `Nombre` y el valor de `Creditos`, esto donde (uso de `WHERE`) la sigla coincide con lo indicado que en este caso son las 3 optativas agregadas. El resultado es el siguiente:

![15](https://github.com/Sphis/ie0217/assets/116931494/2234557b-eb93-4575-aca5-1a346f11de05)

Se observa que se cambian los créditos y descripciones de las optativas que se tenían en la tercera imagen del inciso 3.

**Actualiza la descripción y dificultad de 3 cursos existentes**

Esto es similar al caso anterior, se tiene que actualizar valores existentes, lo único que cambia son las tablas/columnas a modificar, el resultado se muestra en la siguiente figura:

![16](https://github.com/Sphis/ie0217/assets/116931494/370b27e3-4792-4897-9e11-c36cc667d41a)

Se observa que se actualizaron los valores de forma correcta, también se puede verificar con la quinta imagen del inciso anterior.

### 5. Eliminaciones
**Elimina un curso inventado y 2 cursos del plan y asegúrate de que también se eliminen sus descripciones asociadas.**

Para eliminar un dato en SQL se utiliza la palabra `DELETE` para indicar que se va a borrar seguido de `FROM` para indicar de que tabla se va a eliminar el dato. En la primera línea, se elimina la fila donde se encuentra el curso `CI-0137` de la tabla de Cursos. En el caso de la segunda línea, en la sección de código `= (SELECT CursoID FROM Cursos WHERE Sigla = 'CI-0137')`, esto es una forma de decir que estoy buscando el CursoID del curso con la sigla CI-0137, en conjunto con el resto, quiere decir que estoy borrando la fila donde se encuentra dicho dato en la tabla de `Descripciones`. En resumen uno es para eliminar el curso y el otro su descripción. La primera eliminación es para el curso inventado y las otras dos son del plan. En el caso del curso IE-0679 también hay que eliminar sus requisitos, de no ser así se generan errores. A continuación se muestra que se borraron efectivamente de la tabla de cursos y de descripciones:

![17](https://github.com/Sphis/ie0217/assets/116931494/b3fd1ea7-2164-469d-a11d-4aaf4b6ddfd3)

![18](https://github.com/Sphis/ie0217/assets/116931494/26b64199-f2ed-4b83-98d6-95a1df0e772b)

**Elimina requisitos específicos de 2 cursos existentes.**

Este caso es similar al anterior, simplemente se busca el `CursoID` mediante las siglas del curso. Puesto que los requisitos solo se encuentran en la tabla de `Requisitos` solo hay que borrar una vez. La primera de las 2 consultas que se hacen después (con el AND) es para buscar el CursoID con las siglas IE-0117, mediante el uso del AND se obliga a que solo se va a borrar si este resultado está también en RequisitoCursoID (condición de requisito). Se observa en la siguiente imagen que efectivamente se borraron los cursos:

![19](https://github.com/Sphis/ie0217/assets/116931494/6185cedc-9e93-473f-9444-2edf11532a3d)

# Parte teórica
1. ¿Qué es una base de datos relacional y cuáles son sus características fundamentales?

Una base de datos relacional es un sistema organizado de almacenamiento de datos que utiliza tablas para organizar los datos. Sus características fundamentales es que cada tabla tiene filas (registros) y columnas (atributos).

2. ¿Cuál es la diferencia entre una clave primaria y una clave candidata en una base de datos relacional?

Una clave primaria es un conjunto de atributos utilizado para identificar de manera única cada tupla en una tabla. Debe ser elegido entre las claves candidatas y es el principal identificador de la tabla. Por otro lado, una clave candidata son un conjunto de atributos que puede identificar de manera única una tabla. Puede haber más de una clave candidata en una tabla. Su diferencia se puede explicar diciendo que toda clave primaria es una clave candidata, pero no todas las claves candidatas son claves primarias. 

3. ¿Qué son las claves foráneas y cómo se utilizan para mantener la integridad referencial en una base de datos?

Una clave foránea es un campo que establece una relación entre dos tablas. La forma en que lo hace es que una clave foránea es un atributo o conjunto de atributos que hacen referencia a la clave primaria de otra tabla. La forma en que se mantiene la integridad referencial es que se utilizan restricciones, lo que impide que se crea un registro en una tabla hija si ese mismo valor no existe en la tabla padre.

4. ¿Qué es una transacción en el contexto de bases de datos y cuáles son las propiedades ACID que debe cumplir?

Una transacción es como un conjunto de operaciones relacionadas lógicamente. Es el resultado de una petición realizada por el usuario para acceder al contenido de la base de datos y realizar operaciones sobre él. Consta de varias operaciones y tiene varios estados en su recorrido de finalización. También tiene algunas propiedades específicas que deben seguirse para mantener la coherencia de la base de datos. Las propiedades ACID que se deben cumplir son garantizar Atomicidad, Consistencia, Aislamiento y Durabilidad de las transacciones (ACID: Atomicity, Consistency, Isolation and Durability).
https://www.geeksforgeeks.org/transaction-in-dbms/

5. ¿Qué son las vistas (views) en SQL y cuáles son los beneficios y limitaciones de su uso?

Las vistas son tablas virtuales que resulta de una consulta sobre una o más tablas. Dentro de sus beneficios se encuentra la simplificación de consultas (a veces hay tablas con muchos datos, las vistas ayudan a que sean más legibles), seguridad (se puede restringir el acceso a datos), modularidad (se pueden agrupar datos de diferentes tablas en una sola vista).

6. ¿Qué es la normalización en bases de datos y cuáles son las diferentes formas normales (normal forms)?

La normalización de un sistema de base de datos es un proceso para racionalizar correctamente los datos de la base de datos. Esto se debe a que se supera la redundancia, el mal funcionamiento y la integridad de los datos. En otras palabras, la normalización reorganiza la base de datos dividiendo las tablas para encontrar realmente los efectos prácticos de la gestión de datos.

Las diferentes formas normales son:
- 1NF
- 2NF
- 3NF
- BCNF
- 4NF
- 5NF

https://www.geeksforgeeks.org/what-is-normalization-in-dbms/

7. ¿Cómo funcionan los índices en SQL y cuál es su impacto en el rendimiento de las consultas?

Funcionan como los índices de un libro, es decir, permiten localizar información sin tener que buscar toda la tabla (o todo el libro en este caso). Cuando se utiliza, se almacena por separado de los datos de la tabla. Si se tiene una tabla muy grande con muchos datos, se cargarían solamente los registros relevantes.

8. ¿Qué es SQL Injection y cuáles son las mejores prácticas para prevenir este tipo de ataque?

SQL Injection es una técnica en la que los comandos SQL se ejecutan desde los campos de entrada del formulario o los parámetros de consulta de URL.
Esto conduce a un acceso no autorizado a la base de datos (un tipo de piratería).
Las mejores prácticas para prevenir esto son:
- Restringir los procedimientos y el código de las bases de datos.
- Validar y desinfectar las entradas de la base de datos.
- Acceso con privilegios mínimos.

https://www.cloudflare.com/learning/security/threats/how-to-prevent-sql-injection/

9. ¿Qué son los procedimientos almacenados (stored procedures) en SQL y cómo pueden mejorar la eficiencia y seguridad de las operaciones de base de datos?

Un procedimiento almacenado es un código SQL preparado que se puede guardar, de modo que el código pueda reutilizarse una y otra vez.
Si hay una consulta SQL que se utiliza una y otra vez, se puede guardar como un procedimiento almacenado, y luego llamarlo para ejecutarlo.
También se pueden pasar parámetros a un procedimiento almacenado, de forma que el procedimiento almacenado pueda actuar basándose en los valores de los parámetros pasados, por lo que funciona bastante similar a una función.

Mejoran la eficiencia porque los comandos de un procedimiento se ejecutan como un único lote de código. Esto puede reducir significativamente el tráfico de red entre el servidor y el cliente, ya que sólo se envía a través de la red la llamada para ejecutar el procedimiento.

Mejoran la seguridad porque varios usuarios y programas cliente pueden realizar operaciones en objetos de base de datos subyacentes a través de un procedimiento, aunque los usuarios y programas no tengan permisos directos sobre esos objetos subyacentes. El procedimiento controla qué procesos y actividades se realizan y protege los objetos de base de datos subyacentes. Esto elimina la necesidad de conceder permisos a nivel de objeto individual y simplifica las capas de seguridad.

https://learn.microsoft.com/en-us/sql/relational-databases/stored-procedures/stored-procedures-database-engine?view=sql-server-ver16

10. ¿Cómo se implementan las relaciones uno a uno, uno a muchos y muchos a muchos en una base de datos relacional y qué consideraciones se deben tener en cuenta en cada caso?

- Relaciones uno a uno: Se implementa mediante el uso de claves foráneas. La tabla hija que referencia la clave primaria de la tabla padre.

- Uno a muchos: Se implementa utilizando una clave foránea en la tabla hija que referencia la clave primaria de la tabla padre, pero a diferencia del caso anterior, la clave foránea no tiene restricción de `UNIQUE` en la tabla hija, ya que una entidad padre puede tener múltiples entidades hijas asociadas.

- Muchos a muchos: Se implementa utilizando dos tablas de unión (join tables) que contienen claves foráneas que referencian las claves primarias de las tablas.

Algunas consideraciones es que las relaciones muchos a muchos son menos comunes que las relaciones uno a uno y uno a muchos, pero pueden ser utilizadas en algunos casos. Por otro lado, las tablas de unión pueden contener atributos adicionales que describen la relación entre las entidades A y B.
