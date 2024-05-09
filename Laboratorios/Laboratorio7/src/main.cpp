#include <iostream>
#include "text_procesor.hpp"

int main(int argc, char* argv[]){
    // Obligar a que se ingresen al menos 5 parametros
    if(argc < 5){
        std::cerr << "Usage: " << argv[0] << "-f <filename> -o <outputfile> -search <search_pattern> - replace <replace_string>\n";
    }

    // Guardar parametros ingresados
    std::string filename = argv[2];
    std::string outputfile = argv[4];
    std::string search_pattern = argv[6];
    std::string replace_string = argv[8];

    TextProcessor processor(filename, outputfile);
    processor.replace(search_pattern, replace_string);

    return 0;
}