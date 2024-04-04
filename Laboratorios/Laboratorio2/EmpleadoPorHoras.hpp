#ifndef EMPLEADOPORHORAS_HPP
#define EMPLEADOPORHORAS_HPP

#include "Empleado.hpp"

class EmpleadoPorHoras : public Empleado {
    private: // Solo puede ser accedido por la funcion o clases amigas
        int horasTrabajadas;

        public:
            EmpleadoPorHoras(std::string _nombre, int _edad, double _salario, int _horasTrabajadas);
            double calcularPago() const override; // Ocupo implementar esta funcion porque es metodo puro
};

#endif // EMPLEADOPORHORAS_HPP