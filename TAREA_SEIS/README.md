# Instrucciones de ejecución

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