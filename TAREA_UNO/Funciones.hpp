#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Partida.hpp"
#include <vector>

void agregarPalabra(std::vector<std::string>& palabras, int numPalabras);
void mostrarPalabras(const std::vector<std::string>& palabras, int numPalabras);
void buscarContacto(const Partida listaPalabras[], int numPalabras);

#endif // FUNCIONES_HPP