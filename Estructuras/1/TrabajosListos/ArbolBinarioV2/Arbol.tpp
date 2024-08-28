#include "Arbol.h"

#include <iostream>
#include <cstdlib>

template <typename T>
ABB<T>::ABB()
{
    raiz = NULL;
    numNodos = 0;
}

template <typename T>
ABB<T>::~ABB()
{
    if(raiz != NULL){
        delete raiz;
    }
}

template<typename T>
void ABB<T>::Insertar(T valor)
{
    Insertar(raiz,valor);
}

template<typename T>
void ABB<T>::Eliminar(T valor)
{
    Eliminar(raiz, valor);
}

template<typename T>
void ABB<T>::ImprimirInOrden()
{
    ImprimirInOrden(raiz);
}

template<typename T>
void ABB<T>::ImprimirInOrdenInverso()
{
    ImprimirInOrdenInverso(raiz);
}

template<typename T>
void ABB<T>::ImprimirPostOrden()
{
    ImprimirPostOrden(raiz);
}

template<typename T>
void ABB<T>::ImprimirPostOrdenInverso()
{
    ImprimirPostOrdenInverso(raiz);
}

template<typename T>
void ABB<T>::ImprimirPreOrden()
{
    ImprimirPreOrden(raiz);
}

template<typename T>
void ABB<T>::ImprimirPreOrdenInverso()
{
    ImprimirPreOrdenInverso(raiz);
}

template<typename T>
bool ABB<T>::Buscar(T valor)
{
    return Buscar(raiz, valor);
}




/////////////////////////////////////////////////

template<typename T>
void ABB<T>::Insertar(Nodo *& r, T valor)
{
    if(r == NULL){
        r = new Nodo(valor);
        ++numNodos;
    }else
    if(valor < r->valor) Insertar(r->hijoIzq, valor);
    else if(valor > r->valor) Insertar(r->hijoDer,valor);
}

template<typename T>
typename ABB<T>::Nodo*& ABB<T>::Eliminar(Nodo *&r, T valor)
{
    if(r == NULL){
        return NULL;
    }

    if(valor < r->valor){
        r->hijoIzq = Eliminar(r->hijoIzq, valor);
    }else if (valor > r->valor){
        r->hijoDer = Eliminar(r->hijoDer, valor);
    }else{
        if(r->hijoIzq == NULL){
            Nodo* aux = r->hijoDer;
            delete r;
            return aux;
        }else if (r->hijoDer == NULL){
            Nodo* aux = r->hijoIzq;
            delete r;
            return aux;
        }

        Nodo* sucesor = BuscarMenor(r->hijoDer);
        r->valor = sucesor->valor;
        r->hijoDer = Eliminar(r->hijoDer, sucesor->valor);
    }

    return r;

    /*if(raiz == NULL){
        return raiz;
    }

    if(valor < raiz->valor){
        raiz->hijoIzq = Eliminar(raiz->hijoIzq, valor);
    }else if(valor > raiz->valor){
        raiz->hijoDer = Eliminar(raiz->hijoDer, valor);
    }else{
        if(raiz->hijoIzq == NULL){
            Nodo* aux = raiz->hijoDer;
            delete raiz;
            return aux;
        }else if(raiz->hijoDer == NULL){
            Nodo* aux = raiz->hijoIzq;
            delete raiz;
            return aux;
        }
        Nodo * aux = BuscarMenor(raiz->hijoDer);
        raiz->valor = aux->valor;
        raiz ->hijoDer = Eliminar(raiz->hijoDer, aux->valor);
    }
    return raiz;*/
}


template<typename T>
void ABB<T>::Podar(Nodo *& r)
{
    if(r != NULL){
        Podar(r->hijoIzq);
        Podar(r->hijoDer);
        delete r;
        r = NULL;
        --numNodos;
    }
}

template<typename T>
void ABB<T>::Vaciar()
{
    Podar(raiz);
}

template<typename T>
void ABB<T>::ImprimirInOrden(Nodo *& r)
{
    if(r != NULL){
        ImprimirInOrden(r->hijoIzq);
        std::cout  << r->valor << " ";
        ImprimirInOrden(r->hijoDer);
    }
}

template<typename T>
void ABB<T>::ImprimirInOrdenInverso(Nodo *& r)
{
    if(r != NULL){
        ImprimirInOrdenInverso(r->hijoDer);
        std::cout  << r->valor << " ";
        ImprimirInOrdenInverso(r->hijoIzq);
    }
}

template<typename T>
void ABB<T>::ImprimirPostOrden(Nodo *& r)
{
    if(r != NULL){
        ImprimirPostOrden(r->hijoIzq);
        ImprimirPostOrden(r->hijoDer);
        std::cout  << r->valor << " ";

    }
}

template<typename T>
void ABB<T>::ImprimirPostOrdenInverso(Nodo *& r)
{
    if(r != NULL){
        ImprimirPostOrdenInverso(r->hijoDer);
        ImprimirPostOrdenInverso(r->hijoIzq);
        std::cout  << r->valor << " ";

    }
}

template<typename T>
void ABB<T>::ImprimirPreOrden(Nodo *& r)
{
    if(r != NULL){
        std::cout  << r->valor << " ";
        ImprimirPreOrden(r->hijoIzq);
        ImprimirPreOrden(r->hijoDer);

    }
}

template<typename T>
void ABB<T>::ImprimirPreOrdenInverso(Nodo *& r)
{
    if(r != NULL){
        std::cout  << r->valor << " ";
        ImprimirPreOrdenInverso(r->hijoDer);
        ImprimirPreOrdenInverso(r->hijoIzq);

    }
}

template<typename T>
void ABB<T>::CopiarPreOrden(Nodo *& r)
{
    if(r!= NULL){
        Insertar(r->valor);
        CopiarPreOrden(r->hijoIzq);
        CopiarPreOrden(r->hijoDer);
    }
}

template<typename T>
typename ABB<T>::Nodo*& ABB<T>::BuscarMenor(Nodo *& r)
{
    if(r== NULL || r->hijoIzq == NULL) return r;
    return BuscarMenor(r->hijoIzq);
}

template<typename T>
typename ABB<T>::Nodo*& ABB<T>::BuscarMayor(Nodo *&r)
{
    if(r== NULL || r->hijoDer == NULL) return r;
    return BuscarMenor(r->hijoDer);
}

template<typename T>
bool ABB<T>::Buscar(Nodo *& r, T valor)
{
    if(raiz == NULL){
        return false;
    }

    if(valor == r->valor){
        return true;
    }else if(valor < raiz->valor){
        return Buscar(raiz->hijoIzq, valor);
    }else{
        return Buscar(raiz->hijoDer, valor);
    }
}


template<typename T>
ABB<T>::Nodo::Nodo(T v, Nodo* hIzq /*= NULL*/, Nodo* hDer): valor(v), hijoIzq(hIzq), hijoDer(hDer){}

