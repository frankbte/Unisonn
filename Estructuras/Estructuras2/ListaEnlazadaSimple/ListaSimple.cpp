#include "ListaSimple.h"

//*************Buen funcionamiento de la clase***********
Lista::Lista()
{
    tam = 0;
    primero = nullptr;
    ultimo = nullptr;
}

Lista::~Lista()
{
    Vaciar();
}

Lista::Lista(const Lista &l)
{
    Elemento* nodoActual = l.primero;
    while(nodoActual != nullptr){
        AgregarEnInicio(nodoActual->valor);
        nodoActual = nodoActual -> siguiente;
    }
}

//*********** Metodos de agregar ***********

void Lista::AgregarAlFinal(int valor)
{
    Elemento *nuevo = new Elemento;
    nuevo ->valor = valor;
    nuevo->siguiente = nullptr;
    if(EstaVacia()){
        primero = ultimo=  nuevo;
    }
    ultimo ->siguiente = nuevo;
    ultimo = nuevo;
    ++tam;
}

void Lista::AgregarEnInicio(int valor)
{
    Elemento *nuevo = new Elemento;
    nuevo->valor = valor;
    nuevo->siguiente = primero;

    if(EstaVacia()){
        primero = ultimo = nuevo;
    }else{
        primero = nuevo;
    }
    ++tam;
}

void Lista::AgregarEnIndice(int indice, int valor)
{
    if(indice < 0 || indice < tam) throw std::out_of_range("El indice esta fuera de los limites de la lista.");
    if(indice == 0) AgregarEnInicio(valor);
    else if(indice == tam) AgregarAlFinal(valor);
    else{
        Elemento *aux = primero;
        for(int i = 0; i < indice; ++i){
            aux = aux->siguiente;
        }
        Elemento *nuevo = new Elemento;
        nuevo->valor = valor;
        nuevo->siguiente = aux->siguiente;
        aux->siguiente = nuevo;
        ++tam;
    }

}

//********** Metodos de eliminar ***********

void Lista::EliminarDeInicio()
{
  if (EstaVacia()) {
        throw std::out_of_range("La lista está vacía, no se puede eliminar ningún elemento.");
        return;
    }

    Elemento *aux = primero;
    primero = primero->siguiente;
    delete aux;
    --tam;

    if (primero == nullptr) {
        ultimo = nullptr;
    }
}

void Lista::EliminarDeFinal()
{
    if(EstaVacia()){
        throw std::out_of_range("La lista esta vacia, no se puede eliminar ningun elemento.");
        return;
    }

    if(primero == ultimo){
        delete primero;
        primero = ultimo = nullptr;
        --tam;
        return;
    }

    Elemento *aux = primero;
    while(aux->siguiente != ultimo){
        aux = aux->siguiente;
    }

    delete ultimo;
    ultimo = aux;
    ultimo ->siguiente = nullptr;
    --tam;

}

void Lista::EliminarEnIndice(int indice)
{
    if(indice < 0 || indice >= tam) throw std::out_of_range("El indice esta fuera de los limites de la lista");
    if(indice == 0) EliminarDeInicio();
    else if(indice == tam-1)EliminarDeFinal();
    else{
        Elemento *aux = primero;
        for(int i = 1; i < indice; ++i){
            aux = aux->siguiente;
        }
        Elemento *porBorrar = aux->siguiente;
        aux->siguiente = porBorrar->siguiente;
        delete porBorrar;
        --tam;
    }
}

//********** Demás metodos ***************


void Lista::Vaciar()
{
    while(primero != nullptr){
        Elemento *actual = primero;
        primero = primero ->siguiente;
        delete actual;
    }
}

bool Lista::EstaVacia()
{
    return tam == 0;
}

void Lista::Imprimir()
{
    if(EstaVacia()){
        throw std::out_of_range("La lista esta vacia, no se puede eliminar ningun elemento.");
        return;
    }
    Elemento *actual = primero;
    std::cout << "Lista: [";
    while(actual != nullptr){
        std::cout << actual->valor << ", ";
        actual = actual->siguiente;
    }
    std::cout << "]";
    std::cout << std::endl;
}
int Lista::Tamano()
{
    return tam;
}

//******** Obtener valores ************

int Lista::ObtenerPrimero()
{
    return primero->valor;
}

int Lista::ObtenerUltimo()
{
    return ultimo->valor;
}

int Lista::ObtenerValorEnIndice(int indice)
{
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

void Lista::ModificarValorEnIndice(int indice, int nuevoValor)
{
    if(indice < 0 || indice >= tam){
        std::cout << "Error: El indice esta fuera de los limites de la lista..." << std::endl;
        return;
    }

    Elemento *aux = primero;
    for(int i = 0; i < indice; ++i){
        aux = aux->siguiente;
    }

    aux->valor = nuevoValor;
}
