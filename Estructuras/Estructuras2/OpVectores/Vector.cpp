#include <iostream>
#include "Vector.h"

Vector::Vector(int dim)
{
    EstablecerDim(dim);
    try{
    componente = new double[dim];
        for(int i = 0; i < dim; ++i)
        {
            componente[i] = 0;
        }
    }catch(std::bad_alloc &){
        throw "No es posible construir el vector";
    }
}

Vector::~Vector()
{
    delete[]componente;
}

Vector & Vector::operator=(const Vector &v)
{
    if(this == &v) return *this;
    if(dim != v.dim){
        delete[] componente;
        dim = v.dim;
        componente = new double[dim];
    }
    for(int i = 0; i < dim; ++i){
        componente[i] = v.componente[i];
    }
    return *this;
}

void Vector::EstablecerDim(int dim)
{
    if(dim < 1) throw "Valor fuera de rango";
    this->dim = dim;
}

int Vector::ObtenerDim() const
{
    return dim;
}

void Vector::Capturar()
{
    for(int i = 0; i < dim; ++i)
    {
        std::cin >> componente[i];
    }
}

void Vector::Imprimir() const
{
    std::cout << "( ";
    for(int i = 0; i < dim; ++i)
    {
        std::cout << componente[i] << ", ";
    }
    std::cout << "\b\b)";
}

Vector Vector::operator+(Vector v) const
{
    if(dim != v.dim) throw "Dimensiones incompatibles";
    Vector s(dim);
    for(int i =0; i < dim; ++i){
        s.componente[i] = componente[i] + v.componente[i];
    }
    return s;
}

Vector Vector::operator-(Vector v)
{
    if(dim != v.dim) throw "Dimensiones incompatibles";
    Vector r(dim);
    for(int i = 0; i < dim; ++i){
        r.componente[i] = componente[i] - v.componente[i];
    }
    return r;
}

Vector Vector::operator*(double esc) const
{
    Vector resultado(dim);
    for(int i = 0; i < dim; ++i){
        resultado.componente[i] = componente[i] * esc;
    }
    return resultado;

}

double Vector::operator*(Vector v)
{
    double resultado;
    for(int i = 0; i < dim; ++i){
        resultado += componente[i] * v.componente[i];
    }
    return resultado;
}

std::ostream & operator<<(std::ostream &out, Vector v)
{
    out << "(";
    for(int i = 0; i < v.dim; ++i){
        out << v.componente[i] << ", ";
        }
        out << "\b\b)";
        return out;
}

std::istream & operator>>(std::istream &in, Vector &v)
{
    for(int i = 0; i < v.dim; ++i){
        in >> v.componente[i];
    }
    return in;
}

