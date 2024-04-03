#ifndef PARTIDA_HPP
#define PARTIDA_HPP

#include <iostream>
#include <string>

struct Partida {
    std::string palabra;
    int estadoActual = 0; // Cantidad de aciertos
    int intentosMax = 7; // Por predeterminado se empieza en facil
    int intentosActual = 0;
};

#endif // PARTIDA_HPP