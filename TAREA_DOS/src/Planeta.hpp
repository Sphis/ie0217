#ifndef PLANETA_HPP
#define PLANETA_HPP

#include <iostream>
#include <string>
#include <cstdlib> // Para generar números aleatorios
#include <ctime> // Semilla aleatoria para que sea diferente cada ejecucion

class Planeta {

};

class Continentes {

};

class PaisEnDesarrollo {

};

class PaisPrimerMundo {

};

class Pais {
    protected:
        int identificador;
        double pib;

    public:
        int habitantes;
        Pais(int identificador, int habitantes) : identificador(identificador), habitantes(habitantes) {
            pib = rand() % 100000 + 50; // Numero aleatorio entre 50 y 100000 para el PIB
        }

        double getPib() const {
            return pib; // Devolver PIB
        }

        // Sobrecarga de operador para ver si un pais tiene el mismo identificador que otro
        bool operator==(const Pais& otro) const {
            return this->identificador == otro.identificador;
        }
};



#endif // PLANETA_HPP