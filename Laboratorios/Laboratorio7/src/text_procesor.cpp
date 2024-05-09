#include "text_procesor.hpp"
#include <fstream>
#include <regex>

// Constructor
TextProcessor::TextProcessor(const std::string& input_filename, const std::string& output_filename)
  : input_filename(input_filename), output_filename(output_filename){}

// Funcion para reemplazar un patron ingresado por el usuario y generar un archivo de salida con el texto reemplazado
void TextProcessor::replace(const std::string& search_pattern, const std::string& replace_string){
    std::ifstream input_file(input_filename); // ifstream = input file stream
    std::ofstream output_file(output_filename); // ofstream = output file stream
    std::string line;

    std::regex pattern(search_pattern);

    if(input_file && output_file) {
        while(getline(input_file, line)){
            std::string replaced = std::regex_replace(line, pattern, replace_string);
            output_file << replaced << "\n";
        }
    }
}