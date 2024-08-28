#include "Lista.h"

#include <iostream>
#include <cstdlib>

Lista::Lista()
{
    primero = NULL;
    ultimo = NULL;
    tam = 0;
}

Lista::~Lista()
{
    Vaciar();
}

void Lista::EliminarPrincipio()
{
    if (primero == nullptr)return;

    Elemento *aux = primero;
    primero = primero->sig;
    if (primero != nullptr){
        primero ->prev =nullptr;
    }else{
        ultimo = nullptr;
    }
    delete aux;
    tam--;

}

void Lista::EliminarFinal()
{
    if (ultimo == nullptr) return;

    Elemento * aux = ultimo;
    ultimo = ultimo ->prev;
    if(ultimo != nullptr){
        ultimo->sig = nullptr;
    }else{
        primero = nullptr;
    }
    delete aux;
    tam--;
}

void Lista::EliminarEnIndice(int indice)
{
    if(indice < 0 || indice >= tam) return;

    Elemento * actual = primero;
    Elemento * previo = nullptr;
    for(int i = 0; i < indice; i++){
        previo =  actual;
        actual = actual ->sig;
    }

    if(previo == nullptr){
        primero= actual->sig;
    }
    else{
        previo->sig = actual ->sig;
    }

    if(actual == ultimo){
        ultimo = previo;
    }

    delete actual;
    tam--;
}


void Lista::InsertarPrincipio(int valor)
{
    Elemento *nuevo_elemento = new Elemento(valor);
    if (primero == nullptr) {
        primero = nuevo_elemento;
        ultimo = nuevo_elemento;
    }else{
        nuevo_elemento->sig = primero;
        primero->prev = nuevo_elemento;
        primero = nuevo_elemento;
    }
    tam++;
}

void Lista::InsertarEnIndice(int indice, int valor)
{
    if (indice < 0 || indice > tam)throw ("Index out of bounds");


    if (indice == 0) {
        InsertarPrincipio(valor);
        return;
    }

    Elemento *nuevo_elemento = new Elemento(valor);
    nuevo_elemento->valor = valor;

    Elemento* actual = primero;
    for (int i = 0; i < indice - 1; ++i) {
        actual = actual->sig;
    }

    nuevo_elemento->sig = actual->sig;
    actual->sig = nuevo_elemento;

    if (nuevo_elemento->sig == nullptr) {
        ultimo = nuevo_elemento;
    }

    ++tam;
}

void Lista::InsertarFinal(int valor)
{
    Elemento* nuevo_elemento = new Elemento(valor);
    if (ultimo == nullptr) {
        primero = nuevo_elemento;
        ultimo = nuevo_elemento;
    } else {
        ultimo->sig = nuevo_elemento;
        nuevo_elemento ->prev = ultimo;
        ultimo = nuevo_elemento;
    }
    ++tam;
}
int Lista::Tam() const
{
    return tam;
}

void Lista::Imprimir()
{
    std::cout << "[ ";
    Elemento* actual = primero;
    while (actual != nullptr) {
        std:: cout << actual->valor << ", ";
        actual = actual->sig;
    }
    std::cout << "]";
    std::cout << std::endl;
}

void Lista::ImprimirReversa()
{
    std::cout << "[ ";
    Elemento* aux = ultimo;
    while(aux != nullptr){
        std::cout << aux->valor << ", ";
        aux = aux->prev;
    }
    std::cout << "]";
    std::cout << std::endl;
}

bool Lista::EstaVacia()
{
    if(primero == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Lista::Vaciar()
{
    while(!EstaVacia()){
        EliminarPrincipio();
    }
}

void Lista::Modificar(int indice, int valor)
{
    if(indice >= 0 && indice < tam){
        Elemento *actual = primero;
        for(int i = 0; i < indice; i++){
            actual = actual->sig;
        }
        actual->valor = valor;
    }
}

int Lista::BuscarValor(int valor)
{
    Elemento *actual = primero;
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

int Lista::ObtenerPrimero()
{
    return primero->valor;
}

Lista::Elemento::Elemento(int v, Elemento *s /*= NULL*/, Elemento *p): valor(v), sig(s), prev(s){}

