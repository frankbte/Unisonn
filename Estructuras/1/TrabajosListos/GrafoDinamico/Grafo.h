#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include "Arista.h"
#include "Vertice.h"
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <limits>
#include <unordered_set>

using namespace std;

class Grafo{
    Vertice* primero;
    int tamano;


public:
    Grafo();
    bool EstaVacio();
    int ObtenerTamano();
    Vertice* ObtenerVertice(string  _nombre);
    void InsertarVertice(string nombre);
    void InsertarArista(string ori, string dest, int precio);
    void MostrarListaAdyacencia();
    void EliminarVertice(string nombre);
    void EliminarArista(string ori, string dest);
    void EliminarAristas(Vertice* vertice);
    void Vaciar();
    void EliminarAristasDestino(string dest);
    void Prim (string origen);
};

#endif // GRAFO_H_INCLUDED
