#ifndef PLANETA_HPP
#define PLANETA_HPP

#include <iostream>
#include <string>
#include <cstdlib> // Para generar números aleatorios
#include <ctime> // Semilla aleatoria para que sea diferente cada ejecucion

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

class Planeta {

};

class Continentes {

};

// Esta clase se hereda de pais
class PaisEnDesarrollo : public Pais {
    public:
        PaisEnDesarrollo(int identificador, int poblacion) : Pais(identificador, poblacion) {}
};

// Esta clase se hereda de pais
class PaisPrimerMundo : public Pais {
private:
    bool tecnologia5G;
    bool Aeropuerto;
    bool CID;

public:
    PaisPrimerMundo(int identificador, int poblacion, bool tecnologia5G, bool Aeropuerto, bool CID);

    // Método para obtener si tiene tecnología 5G
    bool tiene5G() const;

    // Método para obtener si tiene aeropuerto
    bool tieneAeropuerto() const;

    // Método para obtener si tiene centro de investigación y desarrollo
    bool tieneCID() const;
    
};

#endif // PLANETA_HPP