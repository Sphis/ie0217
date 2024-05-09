#include <string>
// AGREGAR IFNDEF

class TextProcessor {
    private:
      // Atributos de la clase
      std::string input_filename;
      std::string output_filename;

    public:
      // Prototipo de los metodos
      TextProcessor(const std::string& input_filename, const std::string& output_filename); // Procesar el texto
      void replace(const std::string& search_pattern, const std::string& replace_string); // Reemplazar el texto
};