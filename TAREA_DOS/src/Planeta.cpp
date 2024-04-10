#include "Planeta.hpp"
#include <iostream>
#include <cstdlib> // Para generar números aleatorios
#include <ctime> // Semilla aleatoria para que sea diferente cada ejecucion

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