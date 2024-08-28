#include "Lista.h"

//*************Buen funcionamiento de la clase***********

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

//*********** Metodos de agregar ***********

template<typename T>
void Lista<T>::AgregarAlFinal(T valor)
{
    Elemento* nuevo = new Elemento;
    nuevo->valor = valor;
    nuevo->siguiente = nullptr;
    nuevo->anterior = ultimo;

    if (EstaVacia()) {
        primero = nuevo;
    } else {
        ultimo->siguiente = nuevo;
    }

    ultimo = nuevo;
    ++tam;
}

template<typename T>
void Lista<T>::AgregarEnInicio(T valor)
{
    Elemento* nuevo = new Elemento;
    nuevo->valor = valor;
    nuevo->siguiente = primero;
    nuevo->anterior = nullptr;

    if (EstaVacia()) {
        ultimo = nuevo;
    } else {
        primero->anterior = nuevo;
    }

    primero = nuevo;
    ++tam;
}

template<typename T>
void Lista<T>::AgregarEnIndice(int indice, T valor)
{
    if (indice < 0 || indice > tam) {
        throw std::out_of_range("El indice esta fuera de los limites de la lista.");
        return;
    }

    if (indice == 0) {
        AgregarEnInicio(valor);
        return;
    }

    if (indice == tam) {
        AgregarAlFinal(valor);
        return;
    }

    Elemento *nuevo = new Elemento;
    nuevo->valor = valor;

    Elemento *aux = primero;
    for (int i = 1; i < indice; ++i) {
        aux = aux->siguiente;
    }

    nuevo->siguiente = aux->siguiente;
    nuevo->anterior = aux;
    aux->siguiente->anterior = nuevo;
    aux->siguiente = nuevo;

    ++tam;

}

//********** Metodos de eliminar ***********

template<typename T>
void Lista<T>::EliminarDeInicio()
{
  if (EstaVacia()) {
        throw std::out_of_range("La lista esta vacia, no se puede eliminar ningun elemento.");
        return;
    }

    Elemento *aux = primero;
    primero = primero->siguiente;

    if (primero)
        primero->anterior = nullptr;
    else
        ultimo = nullptr;

    delete aux;
    --tam;
}

template<typename T>
void Lista<T>::EliminarDeFinal()
{
    if (EstaVacia()) {
        throw std::out_of_range("La lista esta vacia, no se puede eliminar ningun elemento.");
        return;
    }

    Elemento *aux = ultimo;
    ultimo = ultimo->anterior;

    if (ultimo)
        ultimo->siguiente = nullptr;
    else
        primero = nullptr;

    delete aux;
    --tam;
}

template<typename T>
void Lista<T>::EliminarEnIndice(int indice)
{
    if (indice < 0 || indice >= tam) {
        throw std::out_of_range("El indice esta fuera de los limites de la lista.");
        return;
    }

    if (indice == 0) {
        EliminarDeInicio();
        return;
    }

    if (indice == tam - 1) {
        EliminarDeFinal();
        return;
    }

    Elemento *aux = primero;
    for (int i = 0; i < indice; ++i)
        aux = aux->siguiente;

    aux->anterior->siguiente = aux->siguiente;
    aux->siguiente->anterior = aux->anterior;

    delete aux;
    --tam;
}

template <typename T>
void Lista<T>::EliminarPrimeraOcurrencia(T valor)
{
    if (EstaVacia()) {
        return;
    }
    Elemento *actual = primero;
    while(actual != nullptr){
        Elemento *siguiente = actual ->siguiente;
        if(actual ->valor == valor){
            if(actual == primero){
                primero = siguiente;
                if(primero->anterior == nullptr)
                    delete actual;
                return;
            } else if(actual == ultimo){
                ultimo = actual -> anterior;
                ultimo ->siguiente = nullptr;
                delete actual;
                return;
            } else{
                actual ->anterior ->siguiente = actual->siguiente;
                actual ->siguiente ->anterior = actual ->anterior;
                Elemento *aux = actual ->siguiente;
                delete actual;
                return;
            }
        } else {
            actual = actual ->siguiente;
        }
    }
}


//********** Demás metodos ***************

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
bool Lista<T>::BuscarValor(T valor)
{
    Elemento *aux = primero;
    while (aux != nullptr) {
        if (aux->valor == valor)
            return true;
        aux = aux->siguiente;
    }
    return false;
}

template<typename T>
int Lista<T>::BuscarPos(T valor)
{
    Elemento *aux = primero;
    int indice = 0;
    while (aux != nullptr) {
        if (aux->valor == valor)
            return indice;
        aux = aux->siguiente;
        ++indice;
    }
    return -1;
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
void Lista<T>::ImprimirReversa()
{
    if (EstaVacia()) {
        std::cout << "[]" << std::endl;
        return;
    }
    Elemento *actual = ultimo;
    std::cout << "Lista: [";
    while(actual != nullptr){
        std::cout << actual->valor;
        if(actual->anterior != nullptr) {
            std::cout << ", ";
        }
        actual = actual->anterior;
    }
    std::cout << "]" << std::endl;
}

template<typename T>
int Lista<T>::Tamano()
{
    return tam;
}

//******** Obtener valores ************

template<typename T>
T Lista<T>::ObtenerPrimero()
{
    if (EstaVacia()) {
        throw std::out_of_range("La lista esta vacia.");
    }
    return primero->valor;
}

template<typename T>
T Lista<T>::ObtenerUltimo()
{
    if (EstaVacia()) {
        throw std::out_of_range("La lista esta vacia.");
    }
    return ultimo->valor;
}

template<typename T>
T Lista<T>::ObtenerValorEnIndice(int indice)
{
    if (EstaVacia()) {
        throw std::out_of_range("La lista esta vacia.");
    }
    if(indice < 0 || indice >= tam){
        throw std::out_of_range("El indice esta fuera de los limites de la lista");
            return -1;
    }

    Elemento *aux = primero;
    for(int i = 0; i < indice; ++i){
        aux = aux->siguiente;
    }

    return aux->valor;
}

template<typename T>
void Lista<T>::ModificarValorEnIndice(int indice, T nuevoValor)
{
    if (indice < 0 || indice >= tam) {
        throw std::out_of_range("El indice esta fuera de los limites de la lista.");
    }
    Elemento *aux = primero;
    for (int i = 0; i < indice; ++i) {
        aux = aux->siguiente;
    }
    aux->valor = nuevoValor;
}

template <typename T>
void Lista<T>::OrdenarAscendente() {
    if (EstaVacia() || tam == 1) {
        return;
    }

    Elemento* actual;
    Elemento* siguiente = nullptr;

    bool ordenado = false;
    while (!ordenado) {
        ordenado = true;

        actual = primero;
        while (actual->siguiente != siguiente) {
            if (actual->valor > actual->siguiente->valor) {
                T temp = actual->valor;
                actual->valor = actual->siguiente->valor;
                actual->siguiente->valor = temp;
                ordenado = false;
            }
            actual = actual->siguiente;
        }
        siguiente = actual;
    }
}

template<typename T>
T& Lista<T>::operator[](int indice) {
    if (indice < 0 || indice >= tam) {
        throw std::out_of_range("Indice fuera de rango");
    }

    Elemento *actual = primero;
    for (int i = 0; i < indice; ++i) {
        actual = actual->siguiente;
    }
    return actual->valor;
}

template<typename T>
const T& Lista<T>::operator[](int indice) const {
    if (indice < 0 || indice >= tam) {
        throw std::out_of_range("Indice fuera de rango");
    }

    Elemento *actual = primero;
    for (int i = 0; i < indice; ++i) {
        actual = actual->siguiente;
    }
    return actual->valor;
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

template<typename T>
void Lista<T>::Intercambiar(Lista<T>& otraLista) {
    Elemento* tempPrimero = primero;
    primero = otraLista.primero;
    otraLista.primero = tempPrimero;

    Elemento* tempUltimo = ultimo;
    ultimo = otraLista.ultimo;
    otraLista.ultimo = tempUltimo;

    int tempTam = tam;
    tam = otraLista.tam;
    otraLista.tam = tempTam;
}

template<typename T>
void Lista<T>::IntercambiarElementos(int indiceInicio, int indiceFin, Lista<T>& otraLista, int indiceInicioOtraLista, int indiceFinOtraLista) {
    if (indiceInicio < 0 || indiceFin < 0 || indiceInicioOtraLista < 0 || indiceFinOtraLista < 0 || indiceInicio >= tam || indiceFin >= tam || indiceInicioOtraLista >= otraLista.tam || indiceFinOtraLista >= otraLista.tam) {
        throw std::invalid_argument("Índices inválidos");
    }

    if (indiceFin - indiceInicio != indiceFinOtraLista - indiceInicioOtraLista) {
        throw std::invalid_argument("Los rangos de los índices no tienen la misma longitud");
    }

    if (indiceInicio > indiceFin || indiceInicioOtraLista > indiceFinOtraLista) {
        throw std::invalid_argument("Los índices de inicio deben ser menores o iguales que los índices finales");
    }

    for (int i = indiceInicio, j = indiceInicioOtraLista; i <= indiceFin; ++i, ++j) {
        T tempValor = ObtenerValorEnIndice(i);
        ModificarValorEnIndice(i, otraLista.ObtenerValorEnIndice(j));
        otraLista.ModificarValorEnIndice(j, tempValor);
    }
}

template<typename T>
void Lista<T>::IntercambiarElementos2(int indiceInicio, Lista<T>& otraLista, int indiceInicioOtraLista) {
    if (indiceInicio < 0 || indiceInicio >= tam || indiceInicioOtraLista < 0 || indiceInicioOtraLista >= otraLista.tam) {
        throw std::invalid_argument("Índices inválidos");
    }

    // Intercambiar los elementos entre las listas
    for (int i = indiceInicio, j = indiceInicioOtraLista; i < tam && j < otraLista.tam; ++i, ++j) {
        T tempValor = ObtenerValorEnIndice(i);
        ModificarValorEnIndice(i, otraLista.ObtenerValorEnIndice(j));
        otraLista.ModificarValorEnIndice(j, tempValor);
    }
}


