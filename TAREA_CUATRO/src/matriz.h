#ifndef __TAREA_CUATRO__
#define __TAREA_CUATRO__

#include <iostream>
#include <string>
#include <vector>

using std::vector;

class Matriz {
    private:
        unsigned filasMatriz;
        unsigned columnasMatriz;
        vector<vector<double> > m_matrix;

    public:
        Matriz(unsigned, unsigned, double);
        Matriz(const Matriz &);
        ~Matriz();
        void setDimensiones(int filas, int columnas);
        void llenarMatriz();

  // Operadores de matriz
    Matriz operator+(Matriz &);
    Matriz operator-(Matriz &);
    Matriz operator*(Matriz &);

    double& operator()(const unsigned &, const unsigned &);
    void print() const;
    unsigned getRows() const;
    unsigned getCols() const;
};
    
#endif