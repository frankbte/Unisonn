#include "Lista.h"

//*********Metodos Indispensables *********

template<typename T>
Lista<T>::Lista()
{
    tam = 0;
    primero = nullptr;
    ultimo = nullptr;
}

template<typename T>
Lista<T>::~Lista()
{
    Vaciar();
}

template<typename T>
Lista<T>::Lista(const Lista<T> &l)
{
    Elemento* nodoActual = l.primero;
    while(nodoActual != nullptr){
        AgregarEnInicio(nodoActual->valor);
        nodoActual = nodoActual -> siguiente;
    }
}

template<typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& otraLista) {
    if (this != &otraLista) {
        Vaciar();
        Elemento *actualOtra = otraLista.primero;
        while (actualOtra != nullptr) {
            AgregarAlFinal(actualOtra->valor);
            actualOtra = actualOtra->siguiente;
        }
    }
    return *this;
}

//********* Metodos Agregar *********

template<typename T>
void Lista<T>::AgregarAlFinal(T valor)
{
    Elemento* nuevo = new Elemento;
    nuevo->valor = valor;
    nuevo->siguiente = nullptr;

    if (EstaVacia()) {
        primero = nuevo;
    } else {
        ultimo->siguiente = nuevo;
    }

    ultimo = nuevo;
    ++tam;
}

//********** Metodos Eliminar *************

template<typename T>
void Lista<T>::EliminarDeInicio()
{
    if (EstaVacia()) {
        throw std::out_of_range("La lista esta vacia, no se puede eliminar ningun elemento.");
    }
    Elemento* aux = primero;
    primero = primero->siguiente;
    if (primero == nullptr) {
        ultimo = nullptr;
    }
    delete aux;
    --tam;
}

template<typename T>
void Lista<T>::EliminarDeFinal()
{
    if (EstaVacia()) {
        throw std::out_of_range("La lista esta vacia, no se puede eliminar ningun elemento.");
    }

    Elemento* aux = ultimo;

    if (primero == ultimo) {
        primero = ultimo = nullptr;
    } else {
        Elemento* penultimo = primero;
        while (penultimo->siguiente != ultimo) {
            penultimo = penultimo->siguiente;
        }
        penultimo->siguiente = nullptr;
        ultimo = penultimo;
    }

    delete aux;
    --tam;
}

template<typename T>
void Lista<T>::EliminarEnIndice(int indice)
{
    if (indice < 0 || indice >= tam) {
        throw std::out_of_range("Indice fuera de rango.");
    }

    if (indice == 0) {
        EliminarDeInicio();
        return;
    }

    Elemento* actual = primero;
    for (int i = 0; i < indice - 1; ++i) {
        actual = actual->siguiente;
    }

    Elemento* aux = actual->siguiente;
    actual->siguiente = aux->siguiente;

    if (aux == ultimo) {
        ultimo = actual;
    }

    delete aux;
    --tam;
}


//******** Demas metodos *************

template<typename T>
void Lista<T>::Vaciar()
{
    if(primero = nullptr)
    {
        throw std::out_of_range("La Lista ya esta vacia.");
    }
    while(primero != nullptr){
        Elemento *actual = primero;
        primero = primero ->siguiente;
        delete actual;
    }
    ultimo = nullptr;
    tam = 0;
}


template<typename T>
bool Lista<T>::EstaVacia()
{
    return tam == 0;
}

template<typename T>
void Lista<T>::Imprimir()
{
    if (EstaVacia()) {
        std::cout << "[]" << std::endl;
        return;
    }

    Elemento *actual = primero;
    std::cout << "Lista: [";
    while(actual != nullptr){
        std::cout << actual->valor;
        if(actual->siguiente != nullptr) {
            std::cout << ", ";
        }
        actual = actual->siguiente;
    }
    std::cout << "]" << std::endl;
}

template<typename T>
T Lista<T>::operator[](const unsigned int pos) const
{
    if (EstaVacia())
        throw ListaVacia(); // Lanza una excepción si la lista está vacía
    if (pos < 0 || pos >= tam)
        throw FueraDeRango(); // Lanza una excepción si la posición está fuera de rango
    Elemento *actual = primero;
    for (unsigned int i = 1; i <= pos; ++i)
    {
        actual = actual->siguiente; // Avanza al siguiente elemento hasta llegar a la posición dada
    }
    return actual->valor; // Devuelve el valor del elemento en la posición dada
}

template<typename T>
T& Lista<T>::operator[](const unsigned int pos)
{
    if (EstaVacia())
        throw ListaVacia(); // Lanza una excepción si la lista está vacía
    if (pos < 0 || pos >= tam)
        throw FueraDeRango(); // Lanza una excepción si la posición está fuera de rango
    Elemento *actual = primero;
    for (unsigned int i = 1; i <= pos; ++i)
    {
        actual = actual->siguiente; // Avanza al siguiente elemento hasta llegar a la posición dada
    }
    return actual->valor; // Devuelve una referencia al valor del elemento en la posición dada
}

//********* Obtener tamaño ************
template<typename T>
int Lista<T>::Tamano()
{
    return tam;
}

//*********** Metodo para excepciones *************

template<typename T>
const char *Lista<T>::ListaVacia::what() const noexcept
{
    return "La lista est\240 vac\241a";
}

template<typename T>
const char *Lista<T>::FueraDeRango::what() const noexcept
{
    return "Valor fuera de rango";
}



