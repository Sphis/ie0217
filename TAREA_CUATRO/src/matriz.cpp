#include "matriz.h"
using namespace std;

// Constructor para la matriz
Matriz::Matriz(unsigned filaTamano, unsigned columnaTamano, double valoresIni){
    filasMatriz = filaTamano;
    columnasMatriz = columnaTamano;
    m_matrix.resize(filaTamano);
    for (unsigned i = 0; i < m_matrix.size(); i++)
    {
        m_matrix[i].resize(columnaTamano, valoresIni);
    }
}

// Constructor copia
Matriz::Matriz(const Matriz &B)
{
    this->columnasMatriz = B.getCols();
    this->filasMatriz = B.getRows();
    this->m_matrix = B.m_matrix;
}

// Descontructor
Matriz::~Matriz(){

}

// Método para establecer las dimensiones de la matriz
void Matriz::setDimensiones(int filas, int columnas) {
    if (filas <= 0 || columnas <= 0) {
        throw std::invalid_argument("Las dimensiones de la matriz deben ser mayores que cero.");
    }
}

// Función para asignar valores a elementos de la matriz
void Matriz::llenarMatriz() {
    int valor;
    std::cout << "Ingrese los elementos de la matriz:" << std::endl;
    for (unsigned i = 0; i < filasMatriz; ++i) {
        for (unsigned j = 0; j < columnasMatriz; ++j) {
            std::cout << "Elemento (" << i << ", " << j << "): ";
            if (!(std::cin >> valor)) {
                throw std::runtime_error("Error: Se esperaba un valor del tipo adecuado.");
            }
            m_matrix[i][j] = valor;
        }
    }
}

////////////////////////////////////////

// Suma de matrices
Matriz Matriz::operator+(Matriz &B){
    if (filasMatriz != B.filasMatriz || columnasMatriz != B.columnasMatriz){
        throw std::invalid_argument("Error: Las matrices no tienen las mismas dimensiones.");
    }
    Matriz suma(columnasMatriz, filasMatriz, 0.0);
    unsigned i,j;
    for (i = 0; i < filasMatriz; i++)
    {
        for (j = 0; j < columnasMatriz; j++)
        {
            suma(i,j) = this->m_matrix[i][j] + B(i,j);
        }
    }
    return suma;
}

// Resta de matrices
Matriz Matriz::operator-(Matriz & B){
    if (filasMatriz != B.filasMatriz || columnasMatriz != B.columnasMatriz){
        throw std::invalid_argument("Error: Las matrices no tienen las mismas dimensiones.");
    }
    Matriz resta(columnasMatriz, filasMatriz, 0.0);
    unsigned i,j;
    for (i = 0; i < filasMatriz; i++)
    {
        for (j = 0; j < columnasMatriz; j++)
        {
            resta(i,j) = this->m_matrix[i][j] - B(i,j);
        }
    }
    
    return resta;
}

// Multiplicacion
Matriz Matriz::operator*(Matriz & B){
    Matriz multiplicacion(filasMatriz, B.getCols(), 0.0);
    if(columnasMatriz == B.getRows())
    {
        unsigned i, j, k;
        double temp = 0.0;
        for (i = 0; i < filasMatriz; i++)
        {
            for (j = 0; j < B.getCols(); j++)
            {
                temp = 0.0;
                for (k = 0; k < columnasMatriz; k++)
                {
                    temp += m_matrix[i][k] * B(k,j);
                }
                multiplicacion(i,j) = temp;
            }
        }
        return multiplicacion;
    }
    else
    {
        throw std::invalid_argument("Error: Las matrices no tienen dimensiones compatibles para la multiplicación.");
    }
}

// Para retorna el valor de un elemento del arreglo de la forma A(x,y)
double& Matriz::operator()(const unsigned &rowNo, const unsigned & colNo)
{
    return this->m_matrix[rowNo][colNo];
}

// Returna cantidad de filas
unsigned Matriz::getRows() const
{
    return this->filasMatriz;
}

// Returna cantidad de columnas
unsigned Matriz::getCols() const
{
    return this->columnasMatriz;
}

// Imprimir la matriz
void Matriz::print() const
{
    cout << "Matriz: " << endl;
    for (unsigned i = 0; i < filasMatriz; i++) {
        for (unsigned j = 0; j < columnasMatriz; j++) {
            cout << "[" << m_matrix[i][j] << "] ";
        }
        cout << endl;
    }
}