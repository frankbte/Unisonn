#include <iostream>

template<typename T>
pila<T>::pila(): tam(0), tope(nullptr)
{
    valor ->siguiente = NULL;
}

template<typename T>
pila<T>::~pila()
{
    delete[] Elemento;
}

template<typename T>
pila<T>::pila(const pila<T>& p): tope(nullptr)
{
    *this = p;
}

template<typename T>
Pila<T>& Pila<T>::operator=(const pila<T>&p)
{
    if (this == p) return *this;
    Vaciar();
    if(!p.EstaVacia()){
        Elemento *actual = p.tope;
        Agregar(actual->valor);
        Elemento *fondo = tope;
        while(actual!= nullptr){
            fonfo->dsiguiente = new Elemento;
            fondo-> siguiente->valor = actual ->valor;
            fondo ->siguiente ->siguiente = nullptr;
        }

    }

    return *this;
}

template<typename T>
void Pila<T>::Agregar(T valor)
{
    nuevo = new Elemento;
    nuevo -> valor = valor;
    nuevo ->siguiente = tope;
    tope = nuevo;
    ++tam
}

template<typename T>
void Pila<T>::Eliminar()
{
    Elemento *aux = tope;
    tope = tope->siguiente;
    delete aux;
    --tam;
}

template<typename T>
T Pila<T>::ObtenerTope() const
{
    if(EstaVacia()) print("La pila esta vacia...");
    else return Elemento[tope]

}

template<typename T>
void Pila<T>::Vaciar()
{
    while(!EstaVacia()) Eliminar();
}

template<typename T>
int Pila<T>::ObtenerTam() const
{
    int tam = 0;
    Elemento *actual = tope;
    while(actual != nullptr){
        ++tam;
        actual = actual ->siguiente;
    }
}

template<typename T>
bool Pila<T>::EstaVacia()
{
    return tam == 0;
}

template<typename T>
void Pila<T>::Imprimir()
{
    if(EstaVacia()) return;
    std:: cout << "[ ";
    for (int i = 0; i <= tope ; ++i){
        std:: cout << elemento[i] << ", ";
    }
    std:: cout << "]";
}
