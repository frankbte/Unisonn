#include <iostream>
#include <cstdlib>

using std::cout;
using std::string;

template <typename T>
Pila<T>:: Pila(): tam(0), tope(nullptr)
{
}

template <typename T>
Pila<T>::~Pila()
{
    while(!EstaVacia()){
        Desapilar();
    }
}

template <typename T>
Pila<T>:: Pila(const Pila& p): tam(p.tam)
{
    if (p.tope == nullptr) {
            tope = nullptr;
        } else {
            tope = new Elemento;
            tope->valor = p.tope->valor;
            Elemento* actual = tope;
            Elemento* otroActual = p.tope->siguiente;
            while (otroActual != nullptr) {
                actual->siguiente = new Elemento;
                actual = actual->siguiente;
                actual->valor = otroActual->valor;
                otroActual = otroActual->siguiente;
            }
            actual->siguiente = nullptr;
        }
}


template <typename T>
Pila<T>& Pila<T>::operator=(const Pila<T>& p)
{
    if(this == &p) return *this;
    Vaciar();
    if(!p.EstaVacia()){
        Agregar(p.ElementoTope());
        Elemento *actual = p.tope ->siguiente;
        Elemento *fondo = tope;
        while(actual!= nullptr){
            fondo ->siguiente = new Elemento{actual ->valor, nullptr};
            fondo = fondo ->siguiente;
            actual = actual ->siguiente;
        }
        tam = p.tam;
    }
    return *this;
}

template <typename T>
void Pila<T>::Apilar(T valor)
{
    Elemento* nuevo = new Elemento;
    nuevo ->valor = valor;
    nuevo ->siguiente = tope;
    tope = nuevo;
    ++tam;
}

template <typename T>
void Pila<T>::Desapilar()
{
   if(EstaVacia()){
        std::cerr << "La pila esta vacia...";
    }
    Elemento *aux = tope;
    tope = tope->siguiente;
    delete aux;
    --tam;
}

template <typename T>
bool Pila<T>::EstaLlena() const
{
    if(tope == tam-1)
    {
        return true;
    }else
    {
        return false;
    }
}

template <typename T>
bool Pila<T>::EstaVacia() const
{
    if(tam == -1)
    {
        return true;
    }else
    {
        return false;
    }
}

template <typename T>
T Pila<T>::ElementoTope() const
{
    if(EstaVacia()){
        throw std::out_of_range("La pila esta vacia...");
    }
    return tope ->valor;
}

template <typename T>
void Pila<T>::Imprimir() const
{
    if(EstaVacia())
    {
        std::cout << "la pila esta vacia..." << std::endl;
        return;
    }
    std::cout << "[";
    Elemento *actual = tope;
    while(actual != nullptr){
        std::cout << actual->valor << ", ";
        actual = actual ->siguiente;
    }
    std::cout<< "]";
    std::cout << std::endl;
}

template <typename T>
void Pila<T>::Vaciar()
{
    tope= -1;
}

template<typename T>
int Pila<T>::ObtenerElementos()
{
    if(EstaVacia()) throw "La pila esta vacia";
    return tam;
}
