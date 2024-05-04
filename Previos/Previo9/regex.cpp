#include <iostream>
#include <regex>

int main() {
    // Note que regex no es un string, sino un dato de tipo regex, por eso es que
    // se utiliza auto.
    auto const regex = std::regex("(my|your) regex"); // | funciona como una OR, es decir, la expresion debe
    // tener my o your seguido de regex

    auto const myText = std::string("A piece of text that contains my regex.");
    bool const myTextContainsRegex = std::regex_search(myText, regex); // Le paso el texto que quiero revisar
    // y la expresion que quiero buscar y me devuelve un booleano.

    auto const yourText = std::string("A piece of text that contains your regex.");
    bool const yourTextContainsRegex = std::regex_search(yourText, regex);

    auto const theirText = std::string("A piece of text that contains their regex."); // Este texto no cumple con
    // el regex, por lo que debiera de devolver falso.
    bool const theirTextContainsRegex = std::regex_search(theirText, regex);

    // Imprimir los resultados de las expresiones.
    std::cout << std::boolalpha
              << myTextContainsRegex << '\n'
              << yourTextContainsRegex << '\n'
              << theirTextContainsRegex << '\n';
}