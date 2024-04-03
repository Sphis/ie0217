/**
* @file Partida.hpp
* Archivo que posee el formato de la estructuras a usar en este programa.
*/

#ifndef PARTIDA_HPP
#define PARTIDA_HPP

#include <iostream>
#include <string>

struct Partida {
    std::string palabra;
    std::string estadoActual = ""; // Estado de la palabra con aciertos
    int intentosMax = 7; // Por predeterminado se empieza en facil
    int intentosActual = 0; // Lleva conteo de adivinanzas incorrectas
};

#endif // PARTIDA_HPP