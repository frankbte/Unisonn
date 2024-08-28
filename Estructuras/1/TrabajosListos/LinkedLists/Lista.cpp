#include "Lista.h"

#include <iostream>
#include <cstdlib>

ColaM::ColaM()
{
    primero = NULL;
    ultimo = NULL;
    tam = 0;
}

ColaM::~ColaM()
{
    Elemento* actual = primero;
    while (actual != nullptr) {
        Elemento* aux = actual;
        actual = actual->sig;
        delete aux;
    }
}

void ColaM::EliminarPrincipio()
{

    Elemento *aux = primero;
    primero = primero->sig;
    delete aux;
    tam--;

}

void ColaM::EliminarFinal()
{
    if (ultimo == nullptr) return;

    if (primero == ultimo)
    {
        delete ultimo;
        primero = ultimo = nullptr;
        tam--;
        return;
    }

    Elemento * actual = primero;
    Elemento * previo = nullptr;
    while(actual != ultimo){
        previo = actual;
        actual = actual ->sig;
    }

    ultimo = previo;
    ultimo ->sig= nullptr;
    delete actual;
    tam--;
}

void ColaM::EliminarEnIndice(int indice)
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


void ColaM::InsertarPrincipio(int valor)
{
    Elemento *nuevo_elemento = new Elemento(valor);
    nuevo_elemento->sig = primero;

    if (primero == nullptr) {
        ultimo = nuevo_elemento;
    }

    primero = nuevo_elemento;
    ++tam;
}

void ColaM::InsertarEnIndice(int indice, int valor)
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

void ColaM::InsertarFinal(int valor)
{
    Elemento* nuevo_elemento = new Elemento(valor);
    nuevo_elemento->valor = valor;
    nuevo_elemento->sig = nullptr;

    if (ultimo == nullptr) {
        primero = nuevo_elemento;
    } else {
        ultimo->sig = nuevo_elemento;
    }

    ultimo = nuevo_elemento;
    ++tam;
}
int ColaM::Tam() const
{
    return tam;
}

void ColaM::Imprimir()
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

bool ColaM::EstaVacia()
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

void ColaM::Vaciar()
{
    while(!EstaVacia()){
        EliminarPrincipio();
    }
}

void ColaM::Modificar(int indice, int valor)
{
    if(indice >= 0 && indice < tam){
        Elemento *actual = primero;
        for(int i = 0; i < indice; i++){
            actual = actual->sig;
        }
        actual->valor = valor;
    }
}

int ColaM::BuscarValor(int valor)
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

ColaM::Elemento::Elemento(int v, Elemento *s /*= NULL*/): valor(v), sig(s){}

