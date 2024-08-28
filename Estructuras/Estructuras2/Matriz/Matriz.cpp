#include "Matriz.h"
#include <iostream>

matriz::matriz(int filas, int columnas) : filas(filas), columnas(columnas) {
    datos = new int*[filas];
    for(int i = 0; i < filas; ++i) {
        datos[i] = new int[columnas];
        for(int j = 0; j < columnas; ++j) {
            datos[i][j] = 0;
        }
    }
}

matriz::~matriz() {
    for(int i = 0; i < filas; ++i) {
        delete[] datos[i];
    }
    delete[] datos;
}

matriz::matriz(const matriz &m) : filas(m.filas), columnas(m.columnas) {
    datos = new int*[filas];
    for(int i = 0; i < filas; ++i) {
        datos[i] = new int[columnas];
        for(int j = 0; j < columnas; ++j) {
            datos[i][j] = m.datos[i][j];
        }
    }
}

void matriz::Imprimir() const {
    for(int i = 0; i < filas; ++i) {
        std::cout << "[";
        for(int j = 0; j < columnas; ++j) {
            std::cout << datos[i][j];
            if(j < columnas -1){
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
}

 matriz matriz::transpuesta() const
{
    matriz t(columnas, filas);
    for( int i = 0; i < t.filas; ++i){
        for(int j = 0; j < t.columnas; ++j){
            t.datos[i][j] = this -> datos[j][i];
        }
    }
    return t;
}

void matriz::Capturar()
{
    std::cout << "Capture los valores de la matriz:" << std::endl;
    for(int i = 0; i < filas; ++i){
        for (int j = 0; j < columnas; ++j){
            std:: cout << "Valor en la posicion (" << i << ", " << j << "):" << std::endl;
            std::cin >> datos[i][j];
        }
    }
    std:: cout<< " " << std::endl;
}

matriz matriz::operator+(matriz m)
{
    if(filas != m.filas || columnas != m.columnas){
        std::cerr << "No se pueden sumar matrices de diferentes dimensiones..." << std::endl;
        return matriz(0,0);
    }
    matriz s(filas, columnas);
    for(int i = 0; i < filas; ++i){
        for(int j = 0; j < columnas; ++j){
                s.datos[i][j] = datos[i][j] + m.datos[i][j];
        }
    }
    return s;
}

matriz matriz::operator-(matriz m)
{
    if(filas != m.filas || columnas != m.columnas){
        std::cerr << "No se pueden restar matrices de diferentes dimensiones..." << std::endl;
        return matriz(0,0);
    }
    matriz r(filas, columnas);
    for(int i = 0; i < filas; ++i){
        for(int j = 0; j < columnas; ++j){
                r.datos[i][j] = datos[i][j] - m.datos[i][j];
        }
    }
    return r;
}

matriz& matriz::operator=(const matriz &m)
{
    if(this == &m) return *this;

    if(this != &m){
        for(int i = 0; i < filas; ++i){
            delete[] datos[i];
        }
        delete[] datos;

        filas = m.filas;
        columnas = m.columnas;

        datos = new int*[filas];
        for(int i = 0; i < filas; ++i){
            datos[i] = new int[columnas];
            for(int j = 0; j < columnas; ++j){
                datos[i][j] = m.datos[i][j];
            }
        }
    }

    return *this;
}

matriz matriz::operator*(double esc) const
{
    matriz m(filas, columnas);
    for(int i = 0; i < filas; ++i){
        for(int j = 0; j < columnas; ++j){
            m.datos[i][j] = datos[i][j] * esc;
        }
    }
    return m;
}

matriz matriz::Multiplicar(const matriz &m) const
{
    if(columnas != m.filas){
        throw std::invalid_argument("Las matrices no son compatibles...");
    }
    matriz resultado(filas, columnas);
    for(int i = 0; i< filas; ++i){
        for(int j = 0; j < columnas; ++j){
            int sum = 0;
            for(int k = 0; k < columnas; ++k){
                sum += datos[i][k] * m.datos[k][j];
            }
            resultado.datos[i][j] = sum;
        }
    }
    return resultado;
}



/*void matriz::Redimensionar(int nuevaFila, nuevaCol)
{

}*/
