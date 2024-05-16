/**
 * @file email.cpp
 * Este archivo contiene las implementaciones de la clase y sus metodos, lógica del programa y también es donde se encuentra el manejo
 * de exepciones.
*/

#include "email.hpp"

void ValidadorEmail::validarCorreo(const string& correo) {
    // Primero se busca si hay y en donde está el @
    size_t atPos = correo.find('@');
    // En este caso no se encontró @
    if (atPos == string::npos) {
        throw ExcepcionCorreo("La direccion de correo electronico debe tener un '@'");
    }

    string nombre = correo.substr(0, atPos); // Guardar el nombre haciendo un slice (antes del @)
    string dominioYExtension = correo.substr(atPos + 1); // Guardar el dominio y la extension

    // Verificar que tenga un punto (para el dominio)
    size_t dotPos = dominioYExtension.rfind('.');
    if (dotPos == string::npos) {
        throw ExcepcionDominio("El dominio debe tener al menos un punto '.'");
    }

    string dominio = dominioYExtension.substr(0, dotPos); // Guardar el dominio (antes del punto)
    string extension = dominioYExtension.substr(dotPos + 1); // Guardar la extension (despues del punto)

    validarNombre(nombre);
    validarDominio(dominio);
    validarExtension(extension);
}

void ValidadorEmail::validarNombre(const string& nombre) {
    // Para validar el nombre (antes del @)
    regex nombreRegex("^[a-zA-Z0-9][a-zA-Z0-9._-]{0,13}[a-zA-Z0-9]$");
    if (!regex_match(nombre, nombreRegex)) {
        throw ExcepcionNombre("Debe contener letras, números, puntos, guiones o guiones bajos. No debe comenzar ni terminar con un carácter especial, y no debe tener más de 15 caracteres.");
    }
    // Revisar por caracteres consecutivos de acuerdo al enunciado
    if (nombre.find("..") != string::npos || nombre.find("--") != string::npos || nombre.find("__") != string::npos) {
        throw ExcepcionNombre("No debe contener dos caracteres especiales consecutivos");
    }
}

void ValidadorEmail::validarDominio(const string& dominio) {
    // Para validar el dominio (despues del @, pero antes del punto)
    regex dominioRegex("^[a-zA-Z]+(\\.[a-zA-Z]+)*$");
    // Casos de acuerdo al enunciado
    if (!regex_match(dominio, dominioRegex)) {
        throw ExcepcionDominio("Debe contener únicamente letras y puntos. El punto no puede estar al inicio ni al final.");
    }
    if (dominio.length() < 3 || dominio.length() > 30) {
        throw ExcepcionDominio("Debe tener entre 3 y 30 caracteres excluyendo los puntos.");
    }
    if (dominio.find("..") != string::npos) {
        throw ExcepcionDominio("No debe contener segmentos consecutivos separados por un único punto.");
    }
}

void ValidadorEmail::validarExtension(const string& extension) {
    // Para validar la extension
    regex extensionRegex("^[a-zA-Z]{2,6}(\\.[a-zA-Z]{2,6})?$");
    if (!regex_match(extension, extensionRegex)) {
        throw ExcepcionExtension("Debe contener entre 2 y 6 letras, ademas, no se permiten números ni caracteres especiales, pero puede ser compuesta.");
    }
}