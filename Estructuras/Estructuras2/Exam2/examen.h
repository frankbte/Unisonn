#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED

template<typename T>
class ListaCD
{
private:
    struct Elemento
    {
        T valor;
        Elemento* siguiente;
        Elemento* anterior;
        Elemento(T v, Elemento* s = nullptr,Elemento* a = nullptr) : valor(v), siguiente(s),anterior(a) {}
    };
    Elemento* cabeza;
    int tam;

public:
    // Constructor por defecto
    ListaCD();
    // Constructor copia
    ListaCD(const ListaCD& otra);
    // Operador de asignación
    ListaCD& operator=(const ListaCD& otra);
    // Destructor
    ~ListaCD();
    // Agregar un elemento despues de la cabeza
    void Agregar(const T& valor);
    //Agregar un elemento en la posicion de la cabeza
    void AgregarEnCabeza(const T& valor);
    //Eliminar el Elemento de la cabeza
    void EliminarCabeza();
    //Eliminar Elemento dado
    void Eliminar(const T& valor);
    //Avanzar la Cabeza
    void AvanzarCabeza();
    //Retroceder la Cabeza
    void RetrocederCabeza();
    //Conocer el valor en la Cabeza
    T ValorCabeza() const;
    //Buscar un Elemento
    bool Buscar(const T& valor) const;
    //Conocer Tamaño de la lista
    int ObtenerTam() const;
    //Conocer si la lista esta vacia
    bool EstaVacia() const;
    //Vaciar la Lista
    void Vaciar();
    // Imprimir la Lista
    void Imprimir() const;
    //Borrar Toda ocurrencia de un elemento
    void BorrarTodosElemento(const T& valor);

};

#include "examen.tpp"

#endif // EXAMEN_H_INCLUDED
