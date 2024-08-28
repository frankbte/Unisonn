
#ifndef PRIMERA_PILA_PILA_H
#define PRIMERA_PILA_PILA_H
#define VACIA (-1)


#include <iostream>

template <typename T >

class Pila
{
public:


    class PilaVacia : public std::exception
    {
    public:
        const char * what() const noexcept override;
    };

// Constructor por defecto
    Pila();

// Constructor de copia
    Pila(const Pila &p);

// Destructor
    virtual ~Pila();

// Operador de asignación
    Pila & operator=(const Pila &p);

    bool operator==(const Pila<T>& otra) const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Pila<U>& p);


// Apila un elemento en la pila
    void Apilar(const T & valor);

// Desapila un elemento de la pila
    void Desapilar();

// Verifica si la pila está vacía
    bool EstaVacia() const;

// Vacía la pila
    void Vaciar();

// Obtiene el número de elementos en la pila
    int NumElementos() const;

// Obtiene el tope de la pila
    const T & ObtenerTope() const;

// Imprime los elementos de la pila en orden LIFO
    void Imprimir() const;
private:

// Redimensiona el arreglo de elementos de la pila
    void redimensionar();

// Verifica si la pila está llena
    bool EstaLLena() const;
    int tope;
    int Capacidad;
    T * elemento;
};
#endif //PRIMERA_PILA_PILA_H

#include "Pila.tpp"


