#include "ColaMed.h"

Cola::Cola()
{
    tam = 0;
    primero = nullptr;
    ultimo = nullptr;
}

Cola::~Cola()
{
    Vaciar();
}

void Cola::Encolar(std::string valor)
{
   Elemento *nuevo = new Elemento;
   nuevo ->valor = valor;
   nuevo ->siguiente = nullptr;
   if(EstaVacia()){
        primero = ultimo = nuevo;
   }else{
        ultimo ->siguiente = nuevo;
   }
   ultimo = nuevo;
   ultimo ->siguiente = primero;
   tam++;
}

void Cola::Desencolar()
{
    if(EstaVacia()){
        std::cout << "Error: la cola esta vacia...";
        return;
    }
    Elemento *aux = primero;
    primero = primero -> siguiente;
    delete aux;
    tam--;
    if (primero == nullptr) {
        ultimo = nullptr;
    }else{
        ultimo->siguiente = primero;
    }
}

int Cola::ObtenerTam()
{
    return tam;
}

std::string Cola::ObtenerPrimero()
{
    if(EstaVacia()){
        std::cout << "Nadie";
        return std::string(); // Devuelve un valor predeterminado de tipo T si la cola está vacía
    }

    return primero->valor; // Devuelve el valor del primer elemento de la cola
}


bool Cola::EstaVacia()
{
    return(tam == 0);
}

void Cola::Vaciar()
{
    while(!EstaVacia()){
        Desencolar();
    }
}

void Cola::Imprimir()
{
    if (!EstaVacia()) {
        Elemento* temp = primero->siguiente; // Empezamos desde el segundo elemento
        do {
            std::cout << temp->valor << std::endl; // Imprimimos el valor del elemento
            temp = temp->siguiente; // Movemos al siguiente elemento
        } while (temp != primero); // Seguimos imprimiendo hasta llegar al inicio de la cola
    } else {
        std::cout << "La cola esta vacia." << std::endl;
    }
}
