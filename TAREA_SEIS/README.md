# Instrucciones
En esta tarea se utiliza MySQL, el resultado de dicha tarea se va a adjuntar a continuación. La forma en que se va a trabajar es que se van a seguir los pasos que se encuentran en el enunciado y se van a adjuntar imágenes de dicho procedimiento mostrando un antes y después de la ejecucion de los comando y una explicación breve. Algunos cursos se toman del plan de licenciatura de ingeniería eléctrica, sin embargo solo se van a incluir los que sean necesarios para cumplir con lo solicitado por la tarea, ya que este proceso demora mucho tiempo.

# Solución de la tarea 6
### 1. Creación de la base de datos y tablas
Basado en la siguiente figura, se observa que, se crea la base de datos mediante el comando ``CREATE DATABASE`` y se usa la palabra clave ``USE`` para indicar que esta es la base de datos a usar. Seguidamente se utiliza el comando ``CREATE TABLE IF NOT EXISTS`` y se escribe el nombre de la tabla a usar. Se usa este comando para indicar de que si la tabla ya fue creada, no volver a crear otra. Finalmente se agregan las características correspondientes a los atributos solicitados por el enunciado. Las palabras claves ``NOT NULL`` y ``UNIQUE`` se usan para no permitir valores nulos en esta columna (porque no tiene sentido que un curso no tenga nombre) y que sea único (porque no tiene sentido que el mismo curso esté 2 veces).

La razón por la que en la imagen los valores salen como "NULL" es debido a que aún no se han agregado valores a la tabla, solo se ha creado.
### Insertar imagen 1

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
### Insertar imagen 2
### Insertar imagen 3

### 2. Inserción de datos
Para este caso se empiezan a agregar datos, para agregar datos a una tabla hay que utilizar el comando `INSERT INTO` seguido de la tabla al que se le quieren insertar los datos. Puesto que queremos ingresar datos a la tabla de `Cursos` el comando completo sería de la forma `INSERT INTO Cursos (Sigla, Nombre, Semestre, Creditos) VALUES` donde después de `VALUES` se agrega los valores en el mismo orden de los atributos que están dentro del paréntesis, entonces `('IE-0579', 'Administracion de sistemas', 9, 4)` estaría agregando un curso con las siglas IE-0579 con el nombre de Administracion de sistemas, está en el semestre 9 y vale 4 créditos. El resultado de ejecutar esto se observa en la siguiente imagen:
### Insertar imagen 4
Se observa que los datos se guardaron de forma correcta en la figura.

Las otras tablas trabajan de la misma forma, solo hay que tener en cuenta que sus atributos cambian de acuerdo a la tabla. Otro punto importante es que las otra tablas deben referenciar a Cursos, para esto se utiliza el comando 
```
INSERT INTO Requisitos (CursoID, RequisitoCursoID) VALUES
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0679'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0579'))
```
Este comando ingresa datos a la tabla de Requisitos. Primeramente realiza una busqueda de la tabla `Cursos`, seguidamente en esa tabla busca la columna `Sigla` continua buscando en esa columna la fila que contenga el valor `IE-0679`. Una vez determinado que los valores existen crea un vínculo indicando que el curso `IE-0679` tiene como requisito el curso `IE-0579`, es decir, Ciencia de datos va a tener como requisito el curso de Administración de sistemas. El resultado de ingresar los datos se muestra en la siguiente imagen:
### Insertar imagen 5
Se observa que las tablas se actualizaron y basado en la imagen anterior (imagen 4) se verifica que los vínculos se crearon de forma adecuada, ya que la columna de `CursoID` contiene los valores 3 y 4, que corresponden a los cursos de Ciencia de datos y Desarrollo de aplicaciones web tienen como requisito (columna de RequisitoCursoID) 1 y 2 que son Administración de sistemas y Seguridad Ocupacional, esto concuerda con el análisis realizado anteriormente.

La tabla de Descripciones funciona como una combinación de los 2 casos anteriores, es decir, se realiza una busqueda la sigla del curso, se agrega valores de descripción y el nivel de dificultad. El resultado se muestra a continuación:
### Insertar imagen 6

### 3. Consultas
- **Consulta para listar todos los cursos con su sigla, nombre, semestre, créditos, descripción y dificultad.**

- **Consultas para listar todos los requisitos de un curso espec´ıfico..**

- **Consulta para listar los cursos que no son optativos.**

- **Listar los cursos que pertenecen al semestre X.**

### 4. Actualizaciones

### 5. Eliminaciones



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