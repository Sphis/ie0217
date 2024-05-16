#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>

using namespace std;

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
    void validarCorreo(const string& correo) {
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

private:
    void validarNombre(const string& nombre) {
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

    void validarDominio(const string& dominio) {
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

    void validarExtension(const string& extension) {
        // Para validar la extension (despues del punto)
    }
};

int main() {
    string correo;
    int opcion;

    do {
        cout << "Menu:\n";
        cout << "1. Ingresar correo electronico.\n";
        cout << "2. Salir del programa.\n";
        cout << "Seleccione una opcion (ingrese el numero de la opcion): ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el correo electronico: ";
                cin >> correo;
                
                break;

            case 2:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 2);

    return 0;
}
