#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Partida.hpp"
#include <vector>

void agregarPalabra(std::vector<std::string>& palabras, int numPalabras);
void mostrarPalabras(const std::vector<std::string>& palabras, int numPalabras);
//void buscarContacto(const Partida listaPalabras[], int numPalabras);
const std::string* init(int min, int max, const std::vector<std::string>& words);

#endif // FUNCIONES_HPP