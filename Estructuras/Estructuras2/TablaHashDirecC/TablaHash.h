#ifndef TABLAHASH_H_INCLUDED
#define TABLAHASH_H_INCLUDED

#include <iostream>
#include <string>
#include "Lista.h"
#include "utilerias.h"

struct Elemento
{
    std::string Nombre;
    int Id;
};


class TablaHashDC{
public:
    TablaHashDC(int capacidad);
    TablaHashDC(const TablaHashDC& otraTabla);
    TablaHashDC& operator=(const TablaHashDC& otraTabla);
    ~TablaHashDC();
    void Insertar(const Elemento& elemento);
    void Eliminar(int matricula);
    void Vaciar();
    void Imprimir() const;
    std::string ObtenerNombreElemento(int matricula)const;
    int NumeroDeElementos() const;
    bool EstaVacia() const;
    bool Buscar(int matricula) const;
    int CapacidadTabla() const;
    const Lista<Elemento>& ObtenerListaEnlazada(int indice) const;

private:
    int FuncionHash(int matricula) const;
    int FuncionHash(int matricula, int capacidad) const;
    void Redimensionar();

    Lista<Elemento>* tabla;
    int Capacidad;
    int CapacidadMaxima;
    int NumeroElementos;
};
#endif // TABLAHASH_H_INCLUDED
