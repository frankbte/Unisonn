#ifndef MONTICULO_H_INCLUDED
#define MONTICULO_H_INCLUDED

#include <cstddef>
#include <iostream>
#include <cstring>
#include <cmath>


signed int obtener_indice_padre(signed int indice);

signed int obtener_hijo_izquierda(signed int indice);

signed int obtener_hijo_derecha(signed int indice);

template <typename T>
void swap(const T &a, const T &b);

template <typename T>
bool min(const T &a, const T &b);

template <typename T>
bool max(const T &a, const T &b);


template <typename T, bool (*F)(const T &a, const T &b) = min>
class Heap
{
private:

  T *_elementos;

  unsigned int _capacidad;

  signed int _ultimo;

	void _cambiar_hacia_arriba(signed int indice);

	void _cambiar_hacia_abajo(signed int indice);

	void _redimensionar();

public:

	Heap(unsigned int niveles = 5);

	Heap(const Heap<T, F> &heap);

	~Heap();

	void Agregar(const T elemento);

	void EliminarRaiz();

	T ObtenerRaiz();

	bool EstaVacio();

	void Vaciar();

    unsigned int ObtenerNumeroElementos();

    unsigned int ObtenerCapacidad();

    void Imprimir();

    void ImprimirLista();

	Heap<T, F> &operator=(const Heap<T, F> &heap);

	class ExcepcionHeapVacio : public std::exception
	{
		public:

			const char *what() const throw()
			{
				return "error: heap: el montículo está vacío";
			}
  };
};


#include "./Monticulo.tpp"

#endif // MONTICULO_H_INCLUDED
