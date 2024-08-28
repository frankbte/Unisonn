#include "Lista.h"

#include <iostream>
#include <cstdlib>

Lista::Lista()
{
    cabeza = NULL;
    ultimo = NULL;
    tam = 0;
}

Lista::~Lista()
{
    Elemento* actual = cabeza;
    while (actual != nullptr) {
        Elemento* aux = actual;
        actual = actual->sig;
        delete aux;
    }
}

Lista::Lista(const Lista& l)
{
    cabeza = NULL;
    tam = 0;
    if(l.cabeza == NULL){
        return;
    }
    Elemento* aux = l.cabeza;
    do{
        InsertarEnCabeza(aux->valor);
        aux =  aux->sig;
    }while(aux!= l.cabeza);
}

/*void Lista::EliminarPrincipio()
{
    if (cabeza == nullptr)return;

    Elemento *aux = cabeza;
    cabeza = cabeza->sig;
    if (cabeza != nullptr){
        cabeza ->prev =nullptr;
    }else{
        ultimo = nullptr;
    }
    delete aux;
    tam--;

}*/

/*void Lista::EliminarFinal()
{
    if (ultimo == nullptr) return;

    Elemento * aux = ultimo;
    ultimo = ultimo ->prev;
    if(ultimo != nullptr){
        ultimo->sig = nullptr;
    }else{
        cabeza = nullptr;
    }
    delete aux;
    tam--;
}*/

/*void Lista::EliminarEnIndice(int indice)
{
    if(indice < 0 || indice >= tam) return;

    Elemento * actual = cabeza;
    Elemento * previo = nullptr;
    for(int i = 0; i < indice; i++){
        previo =  actual;
        actual = actual ->sig;
    }

    if(previo == nullptr){
        cabeza= actual->sig;
    }
    else{
        previo->sig = actual ->sig;
    }

    if(actual == ultimo){
        ultimo = previo;
    }

    delete actual;
    tam--;
}*/


/*void Lista::InsertarPrincipio(int valor)
{
    Elemento *nuevo_elemento = new Elemento(valor);
    if (cabeza == nullptr) {
        cabeza = nuevo_elemento;
        ultimo = nuevo_elemento;
    }else{
        nuevo_elemento->sig = cabeza;
        cabeza->prev = nuevo_elemento;
        cabeza = nuevo_elemento;
    }
    tam++;
}*/

void Lista::InsertarEnCabeza(int valor)
{
    Elemento* nuevo_elemento = new Elemento(valor);
    nuevo_elemento ->valor = valor;
    if(cabeza == NULL){
        cabeza = nuevo_elemento;
        cabeza->sig = cabeza;
        cabeza->prev = cabeza;
    }else{
        ultimo = cabeza->prev;
        ultimo->sig = nuevo_elemento;
        nuevo_elemento->prev = ultimo;
        nuevo_elemento->sig = cabeza;
        cabeza->prev = nuevo_elemento;
    }
    tam++;
}

void Lista::EliminarCabeza()
{
    if(cabeza == NULL){
        return;
    }else if(cabeza->sig == cabeza){
        delete cabeza;
        cabeza = NULL;
        tam = 0;
    }else{
        Elemento* nueva_cabeza = cabeza->sig;
        ultimo = cabeza->prev;
        ultimo->sig= nueva_cabeza;
        nueva_cabeza ->prev = ultimo;
        delete cabeza;
        cabeza = nueva_cabeza;
        tam--;
    }
}

void Lista::EliminarPorValor(int valor)
{
    if (cabeza == NULL){
        return;
    }
    Elemento* aux = cabeza;
    do{
        if(aux->valor == valor){
            if(aux == cabeza){
                EliminarCabeza();
                return;
            }else{
                Elemento* nodoPrev = aux->prev;
                Elemento* nodoSig = aux->sig;
                nodoPrev ->sig = nodoSig;
                nodoSig->prev = nodoPrev;
                delete aux;
                tam--;
                return;
            }
        }
        aux = aux->sig;
    }while(aux!= cabeza);
}

/*void Lista::InsertarEnIndice(int indice, int valor)
{
    if (indice < 0 || indice > tam)throw ("Index out of bounds");


    if (indice == 0) {
        InsertarPrincipio(valor);
        return;
    }

    Elemento *nuevo_elemento = new Elemento(valor);
    nuevo_elemento->valor = valor;

    Elemento* actual = cabeza;
    for (int i = 0; i < indice - 1; ++i) {
        actual = actual->sig;
    }

    nuevo_elemento->sig = actual->sig;
    actual->sig = nuevo_elemento;

    if (nuevo_elemento->sig == nullptr) {
        ultimo = nuevo_elemento;
    }

    ++tam;
}*/

/*void Lista::InsertarFinal(int valor)
{
    Elemento* nuevo_elemento = new Elemento(valor);
    if (ultimo == nullptr) {
        cabeza = nuevo_elemento;
        ultimo = nuevo_elemento;
    } else {
        ultimo->sig = nuevo_elemento;
        nuevo_elemento ->prev = ultimo;
        ultimo = nuevo_elemento;
    }
    ++tam;
}*/
int Lista::Tam() const
{
    return tam;
}

void Lista::Imprimir()
{
    if(cabeza == NULL){
        std::cout << "La lista esta vacia...";
        return;
    }

    Elemento* aux = cabeza;
    std::cout << "";
    do{
        std::cout << "[";
        std::cout << aux->valor << "] ";
        aux = aux ->sig;
    }while(aux != cabeza);
    std::cout << std::endl;
}

void Lista::ImprimirReversa()
{
    Elemento* aux = ultimo;
    std::cout << "";
    do{
        std::cout << "[";
        std::cout << aux->valor << "] ";
        aux = aux ->prev;
    }while(aux != ultimo);
    std::cout << std::endl;


    /*std::cout << "[ ";
    Elemento* aux = ultimo;
    while(aux != nullptr){
        std::cout << aux->valor << ", ";
        aux = aux->prev;
    }
    std::cout << "]";
    std::cout << std::endl;*/
}

bool Lista::EstaVacia()
{
    return cabeza == nullptr;
}

void Lista::Vaciar()
{
    if(cabeza == NULL){
        return;
    }
    Elemento* aux = cabeza;
    do{
        Elemento* nodoSig  = aux->sig;
        delete aux;
        aux = nodoSig;
        tam--;
    }while(aux != cabeza);
    cabeza = NULL;
}

/*void Lista::Modificar(int indice, int valor)
{
    if(indice >= 0 && indice < tam){
        Elemento *actual = cabeza;
        for(int i = 0; i < indice; i++){
            actual = actual->sig;
        }
        actual->valor = valor;
    }
}*/

int Lista::BuscarValor(int valor)
{
    Elemento *actual = cabeza;
    int indice = 0;
    while(actual != nullptr){
        if(actual->valor == valor){
            return indice;
        }
        actual = actual ->sig;
        indice++;
    }
    return -1;
}

int Lista::ObtenerCabeza()
{
    if(cabeza == NULL){
        return -1;
    }
    return cabeza->valor;
}

void Lista::MoverCabezaSig()
{
    if(cabeza == NULL){
        std::cout << "La lista esta vacia..." << std::endl;
        return;
    }
    cabeza = cabeza->sig;
    ultimo = ultimo->sig;
}

void Lista::MoverCabezaAnt()
{
    if(cabeza == NULL){
        std::cout << "La lista esta vacia..." << std::endl;
        return;
    }
    cabeza = cabeza->prev;
    cabeza = ultimo ->prev;
}


Lista::Elemento::Elemento(int v, Elemento *s /*= NULL*/, Elemento *p): valor(v), sig(s), prev(s){}

