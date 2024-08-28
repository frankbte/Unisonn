#include "Grafo.h"

Grafo::Grafo()
{
    primero = NULL;
    tamano =0;
}

bool Grafo::EstaVacio()
{
    return tamano == 0;
}

int Grafo::ObtenerTamano()
{
    return tamano;
}

Vertice* Grafo::ObtenerVertice(string nombre)
{
    Vertice* i = primero;

    while(i != NULL)
    {
        if(i->nombre == nombre)
        {
            return i;
        }
        i = i->sig;
    }

    return NULL;
}

void Grafo::InsertarVertice(string nombre)
{
    if(ObtenerVertice(nombre) == NULL)
    {
        Vertice* nuevo= new Vertice(nombre);

        if(EstaVacio())
        {
            primero = nuevo;
        }
        else
        {
            Vertice* i = primero;

            while(i->sig != NULL)
                i = i->sig;

            i->sig = nuevo;
        }
        cout << "Vertice añadido con exito." << endl;
        tamano++;
    }
    else
        cout << "Ese vertice ya existe en el grafo..." << endl;
}

void Grafo::InsertarArista(string ori, string dest, int precio)
{
    Vertice* vori = ObtenerVertice(ori);
    Vertice* vdest = ObtenerVertice(dest);

    if (vori == NULL)
    {
        cout << "El vertice origen no existe" << endl;
    }

    if(vdest == NULL)
    {
        cout << "El vertice destino no existe" << endl;
    }

    if(vori != NULL && vdest != NULL)
    {
        Arista* nueva = new Arista(vdest,precio);

        if(vori->ari == NULL)
        {
            vori->ari = nueva;
        }
        else
        {
            Arista* j = vori->ari;

            while(j->sig != NULL)
            {
                j= j->sig;
            }
            j->sig = nueva;
        }
    }
    cout << "Arista añadida con exito." << endl;
}

void Grafo::MostrarListaAdyacencia()
{
    Vertice* i = primero;

    while(i != NULL)
    {
        Arista* j = i->ari;
        cout << i->nombre << "= ";

        while(j != NULL)
        {
            cout <<  i->nombre << "->" << j->precio << "->" << j->dest->nombre<< ", ";
            j = j->sig;
        }
        cout << endl;
        i = i->sig;
    }
}

void Grafo::EliminarAristas(Vertice* vertice)
{
    if(vertice == NULL)
        return;

    Arista* i = vertice->ari;
    while(vertice->ari != NULL)
    {
        i = vertice->ari;
        vertice->ari = vertice->ari->sig;
        cout << "Arista " << vertice->nombre << "->" << i->dest->nombre << " eliminada" << endl;
        delete(i);
    }
}
void Grafo::EliminarVertice(string nombre)
{
    if(primero->nombre == nombre)
    {
        Vertice* i = primero;
        primero = primero->sig;
        EliminarAristas(i);
        EliminarAristasDestino(i->nombre);
        cout << "Vertice " << nombre << " fue eliminado..." << endl;
        delete(i);
        tamano--;
    }

    else
    {
        Vertice* i = primero;
        Vertice* j = i->sig;
        bool existe = false;

        while(j != NULL)
        {
            if(j->nombre == nombre)
            {
                i->sig = j->sig;
                EliminarAristas(j);
                EliminarAristasDestino(j->nombre);
                cout << "Vertice " << nombre << " fue eliminado" << endl;
                delete(j);
                tamano--;
                existe = true;
                break;
            }
            i = j;
            j = j->sig;
        }
        if(!existe)
            cout << "El vertice especificado no existe..." << endl;
    }
}

void Grafo::EliminarArista(string ori, string dest)
{
    Vertice* vori = ObtenerVertice(ori);
    Vertice* vdest = ObtenerVertice(dest);

    if (vori == NULL)
    {
        cout << "El vertice origen no existe" << endl;
    }

    if(vdest == NULL)
    {
        cout << "El vertice destino no existe" << endl;
    }

    if(vori != NULL && vdest != NULL)
    {
        if(vori->ari->dest == vdest)
        {
            Arista* i = vori->ari;
            vori->ari = vori->ari->sig;
            cout << "Arista" << ori << "-> " << dest << " eliminada" << endl;
            delete(i);
        }
        else
        {
            Arista* i  = vori->ari;
            Arista* j = i->sig;

            while(j != NULL)
            {
                if(j->dest == vdest)
                {
                    i->sig = j->sig;
                    cout << "Arista" << ori << "-> " << dest << " eliminada" << endl;
                    delete(j);
                    break;
                }

                i =j;
                j = j->sig;
            }
        }
    }
}

void Grafo::EliminarAristasDestino(string dest)
{
    Vertice* i = primero;

    while(i != NULL)
    {
        if(i->nombre == dest || i->ari == NULL)
        {
            i =i->sig;
            continue;
        }
        if(i->ari->dest->nombre == dest)
        {
            Arista* j = i->ari;
            i->ari = i->ari->sig;
            cout << "Arista " << i->nombre << "->" << dest << " eliminada"<< endl;
            delete(j);
        }
        else
        {
            Arista* x = i->ari;
            Arista* y = x->sig;

            while(y != NULL)
            {
                if(y->dest->nombre == dest)
                {
                    x->sig = y->sig;
                    cout << "Arista" << i->nombre << "->" << dest << " eliminada" << endl;
                    delete(y);
                }

                x = y;
                y = y->sig;
            }
        }

        i = i->sig;
    }
}

void Grafo::Vaciar()
{
    Vertice* i = primero;

    while(primero != NULL)
    {
        i = primero;
        primero = primero->sig;
        EliminarAristas(i);
        EliminarAristasDestino(i->nombre);
        cout << "Vertice " << i->nombre << " eliminado" << endl;
        delete(i);
        tamano--;
    }
}

void Grafo::Prim(string origen)
{
    Vertice* vOrigen = ObtenerVertice(origen);

    if(vOrigen == NULL)
    {
        cout << "El vertice no existe..." << endl;
        return;
    }

    map<Vertice*, map<Vertice*, int>> matrizAdy;
    list<pair<Vertice*, pair<Vertice*, int>>> listaSolucion;
    unordered_set<Vertice*> visitados;

    Vertice* vi = primero;

    while(vi != NULL)
    {
        Vertice* vj = primero;

        while(vj != NULL)
        {
            matrizAdy[vi][vj] = 0;
            vj = vj->sig;
        }

        Arista* aj = vi->ari;

        while(aj != NULL)
        {
            matrizAdy[vi][aj->dest] = aj->precio;
            aj = aj->sig;
        }

        vi = vi->sig;
    }

    visitados.insert(vOrigen);
    int aristas =1;

    while(aristas < tamano)
    {
        Vertice* vMinOrigen, *vMinDestino;
        int precioMin = numeric_limits<int>::max();

        for(unordered_set<Vertice*>::iterator i =visitados.begin(); i!= visitados.end(); i++)
        {
            for(map<Vertice*, int>::iterator j =matrizAdy[*i].begin(); j != matrizAdy[*i].end(); j++)
            {
                if(j->second < precioMin && j->second != 0 && visitados.count(j->first) == 0)
                {
                    precioMin = j->second;
                    vMinOrigen = *i;
                    vMinDestino = j->first;
                }
            }
        }

        listaSolucion.push_back(pair<Vertice*, pair<Vertice*, int>>(vMinOrigen, pair<Vertice*, int>(vMinDestino, precioMin)));
        visitados.insert(vMinDestino);
        aristas++;
    }

    for(list<pair<Vertice*, pair<Vertice*, int>>>::iterator i = listaSolucion.begin(); i != listaSolucion.end(); i++)
    {
        cout << i->first->nombre << " <-> " << i->second.second << " <-> "  << i->second.first->nombre << endl;
    }
}
