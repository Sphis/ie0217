#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP

#include <string>

class Empleado {
    protected: // Solo accesible dentro de la clase y sus derivados
        std::string nombre;
        int edad;
        double salario;

    public: // Son accesibles desde afuera de la clase
        Empleado(std::string _strgin, int _edad, double _salario);
        virtual ~Empleado() {} // Deconstructor, se ejecuta cuando el objeto se sale del scope
        virtual double calcularPago() const = 0; // Metodo virtual puro (si o si ocupa ser sobreescrita por clases derivadas), se hace puro por const = 0
        virtual void mostrarDetalles() const;
};

#endif // EMPLEADO_HPP