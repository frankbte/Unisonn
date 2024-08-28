#include <iostream>

#define VACIA (-1)

template <typename T>
std::ostream& operator<<(std::ostream& os, const Pila<T>& p)
{
    os << "[";
    if (!p.EstaVacia()) {
        os << p.ObtenerTope();
        for (int i = p.tope - 1; i >= 0; --i) {
            os << ", " << p.elemento[i];
        }
    }
    os << "]";
    return os;
}
template <typename T>
bool Pila<T>::operator==(const Pila<T>& otra) const {
    if (tope != otra.tope) {
        return false;
    }
    for (int i = 0; i <= tope; i++) {
        if (elemento[i] != otra.elemento[i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
const char * Pila<T>::PilaVacia::what() const noexcept
{
    return "La pila est\240 vac\241a";
}
template <typename T>
Pila<T>::Pila() : tope(-1), Capacidad(10)
{
    elemento = new T[Capacidad];
}


template <typename T>
Pila<T>::Pila(const Pila &p) : tope(p.tope), Capacidad(p.Capacidad)
{
    elemento = NULL;
    *this = p;
}

template <typename T>
Pila<T>::~Pila()
{
    delete [] elemento;
}

template <typename T>
Pila<T> & Pila<T>::operator=(const Pila &p)
{
    if (this == &p)
        return *this;

    delete [] elemento;
    tope = p.tope;
    Capacidad = p.Capacidad;
    elemento = new T[Capacidad];

    for (int i = 0; i <= tope; ++i)
        elemento[i] = p.elemento[i];

    return *this;
}

template <typename T>
void Pila<T>::Apilar(const T & valor)
{
    if (EstaLLena())
        redimensionar();
    elemento[++tope] = valor;
}

template <typename T>
void Pila<T>::Desapilar()
{
    if (EstaVacia() == "Si")
        throw PilaVacia();
    --tope;
}

template <typename T>
bool Pila<T>::EstaLLena() const
{
    return tope + 1 == Capacidad;
}

template <typename T>
bool Pila<T>::EstaVacia() const
{
    return tope == VACIA;
}

template <typename T>
void Pila<T>::Vaciar()
{
    tope = VACIA;
}

template <typename T>
int Pila<T>::NumElementos() const
{
    return tope + 1;
}

template <typename T>
const T & Pila<T>::ObtenerTope() const
{
    if (EstaVacia())
        throw PilaVacia();
    return elemento[tope];
}

template <typename T>
void Pila<T>::Imprimir() const
{
    for (int i = tope; i >= 0 ; --i)
        std::cout << "[" << elemento[i] << "]" << std::endl;
}

template <typename T>
void Pila<T>::redimensionar()
{
    T * temp = elemento;
    Capacidad *= 2;
    elemento = new T[Capacidad];

    for (int i = 0; i <= tope; ++i)
        elemento[i] = temp[i];

    delete [] temp;
}



