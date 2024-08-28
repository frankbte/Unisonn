#include <cstdlib>

#include "Cola.h"
#include <iostream>

Cola::Cola() {
    tam = 0;
    primero = nullptr;
    ultimo = nullptr;
}

Cola::~Cola() {
    Vaciar();
}


void Cola::Encolar(std::string valor, bool esNoble) {
    Elemento *nuevo = new Elemento;
    nuevo->valor = valor;
    nuevo->esNoble = esNoble;
    nuevo->siguiente = nullptr;

    if (EstaVacia()) {
        primero = ultimo = nuevo;
    } else {
        if (esNoble) {
            Elemento *actual = primero;
            Elemento *ultimoNoble = nullptr;
            while (actual != nullptr && actual->esNoble) {
                ultimoNoble = actual;
                actual = actual->siguiente;
            }
            if (ultimoNoble != nullptr) {
                nuevo->siguiente = ultimoNoble->siguiente;
                ultimoNoble->siguiente = nuevo;
                if (ultimoNoble == ultimo) {
                    ultimo = nuevo;
                }
            } else {
                nuevo->siguiente = primero;
                primero = nuevo;
            }
        } else {
            Elemento *actual = primero;
            Elemento *ultimoNoble = nullptr;
            while (actual != nullptr && actual->esNoble) {
                ultimoNoble = actual;
                actual = actual->siguiente;
            }
            if (ultimoNoble != nullptr) {
                nuevo->siguiente = ultimoNoble->siguiente;
                ultimoNoble->siguiente = nuevo;
                if (ultimoNoble == ultimo) {
                    ultimo = nuevo;
                }
            } else {
                ultimo->siguiente = nuevo;
                ultimo = nuevo;
            }
        }
    }
    tam++;
}





void Cola::Desencolar() {
    if (EstaVacia()) {
        std::cout << "Error: la cola está vacía..." << std::endl;
        return;
    }

    Elemento *aux = primero;
    primero = primero->siguiente;
    delete aux;

    if (primero == nullptr) {
        ultimo = nullptr;
    }

    tam--;
}

int Cola::ObtenerTam() {
    return tam;
}

Persona Cola::ObtenerPrimero() {
    if (EstaVacia()) {
        std::cout << "Error: la cola está vacía..." << std::endl;
        return Persona("", false);
    }
    return Persona(primero->valor, primero->esNoble);
}


bool Cola::EstaVacia() {
    return (tam == 0);
}

void Cola::Vaciar() {
    while (!EstaVacia()) {
        Desencolar();
    }
}

void Cola::Imprimir() {
    if (EstaVacia()) {
        std::cout << "Error: La cola está vacía..." << std::endl;
        return;
    }
    Elemento *actual = primero;
    std::cout << "Cola Medieval:" << std::endl;
    while (actual != nullptr) {
        std::cout << actual->valor << " (" << (actual->esNoble ? "noble" : "plebeyo") << ")" << std::endl;
        actual = actual->siguiente;
    }
}

