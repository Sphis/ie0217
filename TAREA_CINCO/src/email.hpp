/**
 * @file email.h
 * Aqui es donde van todos los prototipos de las funciones, clases, metodos utilizados para este programa.
*/
#include <string>
#include <stdexcept>
#include <regex>

using namespace std;

#ifndef __TAREA_CINCO__
#define __TAREA_CINCO__

// Excepciones
class ExcepcionCorreo : public runtime_error {
public:
    explicit ExcepcionCorreo(const string& message) : runtime_error(message) {}
};

class ExcepcionNombre : public ExcepcionCorreo {
public:
    explicit ExcepcionNombre(const string& message) : ExcepcionCorreo("Nombre invalido: " + message) {}
};

class ExcepcionDominio : public ExcepcionCorreo {
public:
    explicit ExcepcionDominio(const string& message) : ExcepcionCorreo("Dominio invalido: " + message) {}
};

class ExcepcionExtension : public ExcepcionCorreo {
public:
    explicit ExcepcionExtension(const string& message) : ExcepcionCorreo("Extensión invalida: " + message) {}
};

class ValidadorEmail {
public:
    void validarCorreo(const string& correo);

private:
    void validarNombre(const string& nombre);

    void validarDominio(const string& dominio);

    void validarExtension(const string& extension);
};
    
#endif