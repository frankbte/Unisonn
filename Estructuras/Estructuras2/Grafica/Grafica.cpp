#include "Grafica.h"
#include <iostream>

using namespace std;

/*           METODOS PUBLICOS PARA NODOS  */


Grafica::Grafica(): numNodos(0), numAristas(0)
{
    primero = nullptr;
}

Grafica::~Grafica() {
    Nodo *actual = primero;
    while (actual != nullptr) {
        Nodo *temp = actual;
        actual = actual->siguiente;
        while (temp->primera != nullptr) {
            EliminarArista(temp->nombre, temp->primera->adyacente->nombre);
        }
        delete temp;
    }
}

Grafica::Grafica(const Grafica &g) : numNodos(0), numAristas(0), primero(nullptr), ultimo(nullptr) {
    Nodo *nodoActual = g.primero;
    while (nodoActual != nullptr) {
        AgregarNodo(nodoActual->nombre);
        Arista *aristaActual = nodoActual->primera;
        while (aristaActual != nullptr) {
            AgregarArista(nodoActual->nombre, aristaActual->adyacente->nombre);
            aristaActual = aristaActual->siguiente;
        }
        nodoActual = nodoActual->siguiente;
    }
}



///////////////////////////////////////////////////////////
void Grafica::AgregarNodo(char nombre)
{
    if(!BuscarNodo(nombre)){
        Nodo * nuevo = new Nodo(nombre, nullptr, ultimo);
        (EstaVacia() ? primero : ultimo->siguiente) = nuevo;
        ultimo = nuevo;
        ++numNodos;
    }
}


////////////////////////////////////////////////////////////
void Grafica::EliminarNodo(char nom)
{
    Nodo *porBorrar = BuscarDireccion(nom);
    if(porBorrar == nullptr) return;
    porBorrar->Aislar();

    (porBorrar == primero ? primero : porBorrar->anterior->siguiente) = porBorrar ->siguiente;
    (porBorrar == ultimo ? ultimo: porBorrar->siguiente ->anterior) = porBorrar ->anterior;

    delete porBorrar;
    --numNodos;
}


////////////////////////////////////////////////////////////
void Grafica::VaciarNodo(char nom){
    Nodo *actual = primero;
    while (actual != nullptr) {
        actual->Aislar();
        actual = actual->siguiente;
    }
}

int Grafica::NumNodos() {
    return numNodos;
}


//////////////////////////////////////////////////////////
bool Grafica::BuscarNodo(char nom)
{
    Nodo *actual = primero;
    while (actual != nullptr) {
        if (actual->nombre == nom)
            return true;
        actual = actual->siguiente;
    }
    return false;
}


/////////////////////////////////////////////////////////////
int Grafica::Grado(char nom) {
    Nodo *nodo = BuscarDireccion(nom);
    if (nodo == nullptr) {
        return -1;
    }
    return nodo->grado;
}


/*              METODOS PUBLICOS PARA ARISTAS             */


void Grafica::AgregarArista(char inicio, char fin)
{
    Nodo *ptrInicio = BuscarDireccion(inicio);
    if(ptrInicio == nullptr) return;
    Nodo *ptrFin = BuscarDireccion(fin);
    if(ptrFin == nullptr) return;
    if(BuscarArista(inicio, fin))return;
    ptrInicio->Agregar(ptrFin);
    ptrFin->Agregar(ptrInicio);
    ++numAristas;
}


////////////////////////////////////////////////////////////
void Grafica::EliminarArista(char inicio, char fin)
{
    Nodo *ptrInicio = BuscarDireccion(inicio);
    if(ptrInicio == nullptr) return;
    Nodo *ptrFin = BuscarDireccion(fin);
    if(ptrFin == nullptr) return;
    ptrFin->Eliminar(ptrInicio);
    ptrInicio->Eliminar(ptrFin);
    --numAristas;
}


/////////////////////////////////////////////////////////////
bool Grafica::EstaVacia()
{
    return primero == nullptr;
}


//////////////////////////////////////////////////////////////
int Grafica::NumAristas() {
    return numAristas;
}

///////////////////////////////////////////////////////////////
bool Grafica::BuscarArista(char inicio, char fin)
{
    Nodo *ptrInicio = BuscarDireccion(inicio);
    if (ptrInicio == nullptr)
        return false;
    Nodo *ptrFin = BuscarDireccion(fin);
    if (ptrFin == nullptr)
        return false;

    Arista *arista = ptrInicio->BuscarDir(ptrFin);
    return (arista != nullptr);
}


///////////////////////////////////////////////////////////////////
void Grafica::Vaciar() {
    Nodo *actual = primero;
    while (actual != nullptr) {
        while (actual->primera != nullptr) {
            EliminarArista(actual->nombre, actual->primera->adyacente->nombre);
        }
        actual = actual->siguiente;
    }
    while (primero != nullptr) {
        EliminarNodo(primero->nombre);
    }
}


////////////////////////////////////////////////////////////////////
void Grafica::Imprimir() {
    if (EstaVacia()) {
        cout << "La grafica esta vacia." << endl;
        return;
    }

    Nodo *actual = primero;
    while (actual != nullptr) {
        cout << "Nodo " << actual->nombre << ":";
        if (actual->primera == nullptr) {
            cout << " sin aristas" << endl;
        } else {
            cout << " aristas: ";
            Arista *arista = actual->primera;
            while (arista != nullptr) {
                cout << "(" << actual->nombre << "," << arista->adyacente->nombre << ") ";
                arista = arista->siguiente;
            }
            cout << endl;
        }
        actual = actual->siguiente;
    }
}

/*                  METODOS PRIVADOS PARA ARISTA                    */

//////////////////////////////////////////////////////////////////////////
Grafica::Arista::Arista(Grafica::Nodo *ady,
    Grafica::Arista *sig, Grafica::Arista *ant):
    adyacente(ady), siguiente(sig), anterior(ant)
{

}


/*                  METODOS PRIVADOS PARA NODO                      */


////////////////////////////////////////////////////////////////////////////
Grafica::Nodo::Nodo(char nom, Grafica::Nodo *sig, Grafica::Nodo *ant):
    nombre(nom), grado(0), primera(nullptr), ultima(nullptr),siguiente(sig), anterior(ant)
{

}


///////////////////////////////////////////////////////////////////////////////////
void Grafica::Nodo::Agregar(Grafica::Nodo *ady)
{
    Grafica::Arista *nueva = new Grafica::Arista(ady, nullptr,ultima);
    (EstaVacio() ? primera : ultima ->siguiente) = nueva;
    ultima = nueva;
    ++grado;
}


///////////////////////////////////////////////////////////////////
void Grafica::Nodo::Eliminar(Grafica::Nodo *ady)
{
    Arista *porBorrar = BuscarDir(ady);
    if(porBorrar == nullptr) return;
    (porBorrar == primera ? primera : porBorrar->anterior->siguiente) = porBorrar->siguiente;
    (porBorrar ==ultima ? ultima : porBorrar->siguiente->anterior) = porBorrar->anterior;
    delete porBorrar;
    --grado;
}


////////////////////////////////////////////////////////////////
bool Grafica::Nodo::EstaVacio()
{
    return (primera == nullptr);
}


////////////////////////////////////////////////////////////////////
bool Grafica::Nodo::esAislado()
{
    return grado == 0;
}


///////////////////////////////////////////////////////////////////
int Grafica::Nodo::Aislar()
{
    int num = grado;
    while(!esAislado()){
        primera->adyacente->Eliminar(this);
        Eliminar(primera->adyacente);
    }
    return num;
}


///////////////////////////////////////////////////////////////////////
Grafica::Arista * Grafica::Nodo::BuscarDir(Nodo *ady)
{
    Arista* actual = primera;
    while(actual != nullptr && actual->adyacente != ady){
        actual = actual ->siguiente;
    }
    return actual;
}


////////////////////////////////////////////////////////////////////////////
Grafica::Nodo *Grafica::BuscarDireccion(char nom)
{
    Nodo *actual = primero;
    while(actual != nullptr && actual ->nombre != nom){
        actual = actual ->siguiente;
    }
    return actual;
}

