#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

// Se crea el template de una clase
template <typename T> // Declaracion de template
class Statistics {
    public:
        Statistics(const std::vector<T>& data) : data(data) {
            // Si me llega un vector vacido se ejecuta esto
            if(data.empty()) {
                throw std::invalid_argument("La lista de datos debe contener elementos"); // Mandar al catch si el vector esta
                // vacido
            }
        }
        
        // Funcion que calcula el promedio de los elementos en el vector
        double mean() const{
            T sum = 0;
            // Iterar sobre todos los elemento del vector (data) y guarde su suma
            for (const T& value : data) {
                sum += value;
            }
            return static_cast<double>(sum) / data.size(); // Divido la suma del vector entre la cantidad
            // de elementos para obtener el promedio
        }

        // Funcion que calcula la desviacion estandar del vector
        double standardDeviation() const {
            double meanValue = mean();
            double sumSquares = 0;

            for (const T& value : data) {
                sumSquares += (value - meanValue) * (value - meanValue);
            }

            return std::sqrt(sumSquares / data.size());
        }
    private:
        std::vector<T> data;
};

int main() {
    try {
        std::vector<int> intData = {1, 2, 3, 4, 5};

        // Le estamos pasando el tipo al template
        Statistics<int> statsInt(intData); // Crear instancia de la clase de int

        std::cout << "Media de intData: " << statsInt.mean() << std::endl;
        std::cout << "Desviacion estandar de intData: " << statsInt.standardDeviation() << std::endl; // Sin el parentesis del metodo
        // se estaria mandando la direccion de memoria

        std::vector<double> doubleData = {1.5, 2.5, 3.5, 4.5, 5.5};

        Statistics<double> statsDouble(doubleData); // Crear instancia de la clase de double

        std::cout << "Media de doubleData: " << statsDouble.mean() << std::endl;
        std::cout << "Desviacion estandar de doubleData: " << statsDouble.standardDeviation()<< std::endl;

        /********************/
        std::vector<int> emptyData;
        Statistics<int> statsEmpty(emptyData);

    } catch (const std::invalid_argument& e) {
        std::cerr << "Excepcion encontrada: " << e.what() << std::endl;
    }

    return 0;
}