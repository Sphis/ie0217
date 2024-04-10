#include "Planeta.hpp"
#include <iostream>
#include <cstdlib> // Para generar números aleatorios
#include <ctime> // Semilla aleatoria para que sea diferente cada ejecucion

////// Clase de pais
Pais::Pais(int _identificador, int _habitantes) :
    identificador(_identificador), habitantes(_habitantes) {
    // Generar PIB aleatoriamente
    pib = rand() % 10000 + 1000; // PIB entre 1000 y 10000
}

double Pais::getPib() const {
    return pib; // Devolver PIB
}

// Sobrecarga de operador para ver si un pais tiene el mismo identificador que otro
bool Pais::operator==(const Pais& otro) const {
    return this->identificador == otro.identificador;
}

////// Clase de PaisPrimerMundo
PaisPrimerMundo::PaisPrimerMundo(int _identificador, int _poblacion, bool _tecnologia5G, bool _Aeropuerto, bool _CID)
        : Pais(_identificador, _poblacion), tecnologia5G(_tecnologia5G), Aeropuerto(_Aeropuerto), CID(_CID) {}

// Método para obtener si tiene tecnología 5G
bool PaisPrimerMundo::tiene5G() const {
    return tecnologia5G;
}

// Método para obtener si tiene aeropuerto
bool PaisPrimerMundo::tieneAeropuerto() const {
    return Aeropuerto;
}

// Método para obtener si tiene centro de investigación y desarrollo
bool PaisPrimerMundo::tieneCID() const {
    return CID;
}