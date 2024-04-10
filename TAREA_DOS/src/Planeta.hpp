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

        Pais(int _identificador, int _habitantes);
        
        double getPib() const;

        // Sobrecarga de operador para ver si un pais tiene el mismo identificador que otro
        bool operator==(const Pais& otro) const;
};

#endif // PLANETA_HPP