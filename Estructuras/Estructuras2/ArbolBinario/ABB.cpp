#include "ABB.h"
//#include "Cola.h"
#include <iostream>

ArbolBinBusqueda::ArbolBinBusqueda(): numNodos(0), raiz(nullptr)
{

}

ArbolBinBusqueda::ArbolBinBusqueda(const ArbolBinBusqueda &arbol): numNodos(0), raiz(nullptr)
{

}

ArbolBinBusqueda::~ArbolBinBusqueda()
{
    Vaciar();
}

ArbolBinBusqueda & ArbolBinBusqueda::operator=(const ArbolBinBusqueda &arbol)
{

}

bool ArbolBinBusqueda::EstaVacio()
{

}

void ArbolBinBusqueda::Imprimir()
{
    ImprimirAscendente(raiz);
}

void ArbolBinBusqueda::Agregar(int valor)
{
    AgregarUtil(valor,raiz);
}

void ArbolBinBusqueda::AgregarUtil(int valor, Nodo *&subRaiz)
{
    if (subRaiz == nullptr){
        subRaiz = new Nodo(valor, nullptr, nullptr);
        numNodos++;
    }
    else if (valor < subRaiz->valor){
        AgregarUtil(valor, subRaiz->izq);
    }
    else if (valor > subRaiz->valor){
        AgregarUtil(valor, subRaiz->der);
    }
}

void ArbolBinBusqueda::ImprimirAscendente(Nodo *subRaiz){
    if(subRaiz != nullptr){
        ImprimirAscendente(subRaiz->izq);
        std::cout << subRaiz->valor << "\t";
        ImprimirAscendente(subRaiz->der);
    }
}
void ArbolBinBusqueda::Vaciar()
{
    Vaciar(raiz);
}

void ArbolBinBusqueda::Vaciar(Nodo *& subRaiz)
{
    if(subRaiz != nullptr){
        Vaciar(subRaiz->izq);
        Vaciar(subRaiz->der);
        delete subRaiz;
        subRaiz = nullptr;
        --numNodos;
    }
}

/*void ArbolBinBusqueda::ImprimirPorNiveles()
{
    if(EstaVacio()) return;
    Cola<Nodo *> cola;
    Nodo *actual;
    cola.Encolar(raiz);
    while(!cola.EstaVacia()){
        actual = cola.ObtenerPrimero();
        cola.Desencolar();
        std::cout<< actual->valor << "\t";
        if(actual->izq!= nullptr)
            cola.Encolar(actual->izq);
        if(actual->der != nullptr)
            cola.Encolar(actual->der);
    }
}*/

