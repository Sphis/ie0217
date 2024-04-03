#ifndef PARTIDA_HPP
#define PARTIDA_HPP

#include <iostream>
#include <string>

struct Partida {
    std::string palabra;
    int estadoActual;
    int intentosMax;
    int intentosActual;
};

#endif // PARTIDA_HPP