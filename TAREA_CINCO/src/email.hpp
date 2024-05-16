/**
 * @file email.hpp
 * Aqui es donde van todos los prototipos de las funciones, clases, metodos utilizados para este programa.
*/
#include <string>
#include <stdexcept>
#include <regex>

using namespace std;

#ifndef __TAREA_CINCO__
#define __TAREA_CINCO__

// Excepciones
/**
 * Clase usada para manejar el error de cuando se ingresa un correo incorrecto
 * @param[in] message
*/
class ExcepcionCorreo : public runtime_error {
public:
    explicit ExcepcionCorreo(const string& message) : runtime_error(message) {}
};

/**
 * Clase usada para manejar el error de cuando se ingresa un nombre incorrecto
 * @param[in] message
*/
class ExcepcionNombre : public ExcepcionCorreo {
public:
    explicit ExcepcionNombre(const string& message) : ExcepcionCorreo("Nombre invalido: " + message) {}
};

/**
 * Clase usada para manejar el error de cuando se ingresa un dominio incorrecto
 * @param[in] message
*/
class ExcepcionDominio : public ExcepcionCorreo {
public:
    explicit ExcepcionDominio(const string& message) : ExcepcionCorreo("Dominio invalido: " + message) {}
};

/**
 * Clase usada para manejar el error de cuando se ingresa un extensión incorrecta
 * @param[in] message
*/
class ExcepcionExtension : public ExcepcionCorreo {
public:
    explicit ExcepcionExtension(const string& message) : ExcepcionCorreo("Extension invalida: " + message) {}
};

/**
 * Clase base con sus métodos.
*/
class ValidadorEmail {
public:
    void validarCorreo(const string& correo); //!< a validarCorreo function.

private:
    void validarNombre(const string& nombre); //!< a validarNombre function.

    void validarDominio(const string& dominio); //!< a validarDominio function.

    void validarExtension(const string& extension); //!< a validarExtension function.
};
    
#endif