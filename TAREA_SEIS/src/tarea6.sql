-- Creacion de la base de datos
CREATE DATABASE PlanDeEstudios;

-- Seleccionar la base de datos a utilizar
USE PlanDeEstudios;

-- 1. CREACION DE LAS TABLAS
-- Creacion de la tabla Cursos
CREATE TABLE IF NOT EXISTS Cursos (
	CursoID INT AUTO_INCREMENT PRIMARY KEY,
    Sigla VARCHAR(10) NOT NULL UNIQUE,
    Nombre VARCHAR(50) NOT NULL UNIQUE,
    Semestre INT NOT NULL,
    Creditos INT NOT NULL
);

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

-- Insertar datos en la tabla Cursos
INSERT INTO Cursos (Sigla, Nombre, Semestre, Creditos) VALUES
-- Agregando 3 cursos del documento de licenciatura
('IE-0579', 'Administracion de sistemas', 9, 4),
('IE-0541', 'Seguridad ocupacional', 10, 3),
('IE-0679', 'Ciencia de datos para la est. y pron. de eventos', 10, 3),
-- Agregando 2 cursos nuevos inventados
('CI-0137', 'Desarrollo de aplicaciones web', 6, 4),
('CI-0140', 'Calidad del software', 6, 4),
-- Agregando 3 cursos optativos cualesquiera del plan
('IE-0117', 'Programación bajo plataformas abiertas', 9, 3),
('IE-0217', 'Estructuras abs. de datos y algoritmos para ing.', 9, 3),
('IE-0365', 'Transmisión de potencia', 10, 3);

-- Relacion de requisitos para los cursos agregados
INSERT INTO Requisitos (CursoID, RequisitoCursoID) VALUES
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0679'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0579')),
((SELECT CursoID FROM Cursos WHERE Sigla = 'CI-0137'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0541')),
-- Requisitos de optativas
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0117'), (SELECT CursoID FROM Cursos WHERE Sigla = 'CI-0137')),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0217'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0117'));

-- Agregando descripciones para los cursos agregados
INSERT INTO Descripciones (CursoID, Descripcion, Dificultad) VALUES
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0579'), 'Curso para aprender a manejar sistemas.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0541'), 'Curso para aprender sobre la seguridad ocupacional.', 'Facil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0679'), 'Curso para aprender acerca de la ciencia de los datos.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'CI-0137'), 'Curso para aprender a desarrollar aplicaciones web.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'CI-0140'), 'Curso para mejorar la calidad de software.', 'Dificil'),
-- Agregando descripciones de los 3 cursos optativos
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0117'), 'Optativa de potencia.', 'Facil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0217'), 'Optativa de potencia.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0365'), 'Optativa de potencia.', 'Dificil');

-- Consulta para listar todos los cursos
SELECT Sigla, Nombre, Semestre, Creditos, Descripcion, Dificultad
FROM Cursos
JOIN Descripciones ON Cursos.CursoID = Descripciones.CursoID;

-- Consulta para los requisitos de un curso
SELECT c1.Sigla AS Curso, c2.Sigla AS Requisito
FROM Requisitos
JOIN Cursos c1 ON Requisitos.CursoID = c1.CursoID
JOIN Cursos c2 ON Requisitos.RequisitoCursoID = c2.CursoID
WHERE c1.Sigla = 'IE-0679'; -- Aqui es donde se realiza la consulta, ingresar siglas deseadas

SELECT C.Sigla, C.Nombre, C.Semestre, C.Creditos, D.Descripcion, D.Dificultad
FROM Cursos C
INNER JOIN Descripciones D ON C.CursoID = D.CursoID
WHERE D.Descripcion NOT LIKE '%Optativa%';

-- Listar los cursos que pertenecen al semestre X
SELECT * FROM Cursos WHERE Semestre = 10; -- En este caso semestre 10

-- Actualiza el nombre y creditos de 3 de los cursos optativos
UPDATE Cursos SET Nombre = 'Diseño de software para ingeniería', Creditos = 2 WHERE Sigla = 'IE-0117';
UPDATE Cursos SET Nombre = 'Laboratorio de control automatico', Creditos = 2 WHERE Sigla = 'IE-0217';
UPDATE Cursos SET Nombre = 'Instrumentación industrial', Creditos = 1 WHERE Sigla = 'IE-0365';

-- Actualiza la descripción y dificultad de 3 cursos existentes
UPDATE Descripciones SET Descripcion = 'Curso para aprender acerca del diseño de software', Dificultad = 'Difícil' WHERE CursoID = (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0579');
UPDATE Descripciones SET Descripcion = 'Laboratorio del área de automatización', Dificultad = 'Media' WHERE CursoID = (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0541');
UPDATE Descripciones SET Descripcion = 'Para aprender sobre el uso de herramientas para mediciones', Dificultad = 'Fácil' WHERE CursoID = (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0679');

-- Eliminar un curso inventado y 2 cursos del plan junto con su descripción
DELETE FROM Descripciones WHERE CursoID = (SELECT CursoID FROM Cursos WHERE Sigla = 'CI-0140'); -- Descripción del curso inventado
DELETE FROM Cursos WHERE Sigla = 'CI-0140'; -- Curso inventado
DELETE FROM Requisitos WHERE CursoID = (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0679'); -- Requisito del curso del plan
DELETE FROM Descripciones WHERE CursoID = (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0679'); -- Descripción del curso del plan
DELETE FROM Cursos WHERE Sigla = 'IE-0679'; -- Curso del plan
DELETE FROM Descripciones WHERE CursoID = (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0365'); -- Descripción del curso del plan
DELETE FROM Cursos WHERE Sigla = 'IE-0365'; -- Curso del plan

-- Eliminar requisitos específicos de 2 cursos existentes
DELETE FROM Requisitos WHERE CursoID = (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0117') AND RequisitoCursoID = (SELECT CursoID FROM Cursos WHERE Sigla = 'CI-0137');
DELETE FROM Requisitos WHERE CursoID = (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0217') AND RequisitoCursoID = (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0117');

-- Mostrar tablas
SELECT * FROM Cursos;
SELECT * FROM Requisitos;
SELECT * FROM Descripciones;