/**
* @file Planeta.hpp
* Archivo donde se encuentran declaraciones de las clases.
*/

#ifndef PLANETA_HPP
#define PLANETA_HPP

#include <iostream>
#include <string>
#include <cstdlib> // Para generar números aleatorios
#include <ctime> // Semilla aleatoria para que sea diferente cada ejecucion
#include <vector>

class Pais {
    protected:
        int identificador; ///< Encargado de identificar si el pais esta en desarrollo o si es de primer mundo
        double pib; ///< Producto interno bruto de cada pais

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
    private:
        std::vector<std::string> continentesTerritorio;

    public:
        Continentes() {
            continentesTerritorio = {"America", "Europa", "Africa", "Oceania", "Asia"};
        }

        // Método para imprimir información de los países en el continente
        void infoGeneral() const {
            std::cout << "El planeta posee 5 continentes: ";
            for (int i = 0; i < 5; i++) {
                if (i < 4)
                    std::cout << continentesTerritorio[i] << ", ";
                else
                    std::cout << continentesTerritorio[i] << ". ";
            }
            std::cout << "De estos continentes, el avion pasa por los siguientes: America, Asia y Europa." << std::endl;
        }
};

// Esta clase se hereda de pais
class PaisEnDesarrollo : public Pais {
    public:
        PaisEnDesarrollo(int identificador, int poblacion) : Pais(identificador, poblacion) {}
};

// Esta clase se hereda de pais
class PaisPrimerMundo : public Pais {
private:
    bool tecnologia5G; ///< Si el pais tiene 5G es true, caso contrario no tiene 5G
    bool Aeropuerto; ///< Indica si el pais tiene aeropuerto
    bool CID; ///< Indica si hay centro de investigación

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