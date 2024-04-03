#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Partida.hpp"
#include <vector>

void agregarPalabra(std::vector<std::string>& palabras, int numPalabras);
void mostrarPalabras(const std::vector<std::string>& palabras, int numPalabras);
//void buscarContacto(const Partida listaPalabras[], int numPalabras);
Partida init(int min, int max, const std::vector<std::string>& palabras);
Partida dificultad(Partida juego);

#endif // FUNCIONES_HPP