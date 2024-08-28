#include "Monticulo.h"

signed int obtener_indice_padre(signed int indice)
{
  return (indice - 1) / 2;
}

signed int obtener_hijo_izquierda(signed int indice)
{
	return ((2 * indice) + 1);
}

signed int obtener_hijo_derecha(signed int indice)
{
  return ((2 * indice) + 2);
}

template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
bool min(const T &a, const T &b)
{
  return a <= b;
}

template <typename T>
bool max(const T &a, const T &b)
{
  return a >= b;
}

//Metodos Privados

template <typename T, bool (*F)(const T &a, const T &b)>
void Heap<T, F>::_cambiar_hacia_arriba(signed int indice)
{
    while (indice > 0)
    {
        if (F(this->_elementos[obtener_indice_padre(indice)], this->_elementos[indice]))
        {
            swap(this->_elementos[obtener_indice_padre(indice)], this->_elementos[indice]);
            indice = obtener_indice_padre(indice);
        }
        else break;
    }
}

template <typename T, bool (*F)(const T &a, const T &b)>
void Heap<T, F>::_cambiar_hacia_abajo(signed int indice)
{
    signed int indiceMaximo = indice;

    signed int izquierda = obtener_hijo_izquierda(indice);
    if (izquierda < this->_ultimo && F(this->_elementos[izquierda], this->_elementos[indiceMaximo])) {
        indiceMaximo = izquierda;
    }

    signed int derecha = obtener_hijo_derecha(indice);
    if (derecha < this->_ultimo && F(this->_elementos[derecha], this->_elementos[indiceMaximo])) {
        indiceMaximo = derecha;
    }

    if (indice != indiceMaximo) {
        swap(this->_elementos[indice], this->_elementos[indiceMaximo]);
        this->_cambiar_hacia_abajo(indiceMaximo);
    }
}

template <typename T, bool (*F)(const T &a, const T &b)>
void Heap<T, F>::_redimensionar()
{
    unsigned int num = this->ObtenerNumeroElementos();
    unsigned int altura = ((unsigned int)round(log2(num + 1) - 1));
    unsigned int nueva_altura = altura + 1;
    unsigned int nueva_capacidad = 0;
    for (unsigned int n = 0; n <= nueva_altura; n++)
        nueva_capacidad += pow(2, n);
    T *nuevo_arreglo = new T[nueva_capacidad];
    for (unsigned int i = 0; i < nueva_capacidad; i++)
    {
        if (i < this->_capacidad)
            nuevo_arreglo[i] = this->_elementos[i];
        else
            nuevo_arreglo[i] = 0;
    }
    this->_elementos = nuevo_arreglo;
    this->_capacidad = nueva_capacidad;
}

//Metodos publicos

template <typename T, bool (*F)(const T &a, const T &b)>
Heap<T, F>::Heap(unsigned int niveles/* = 5*/)
{
    unsigned int capacidad = 0;
    for (unsigned int n = 0; n < niveles; n++)
        capacidad += pow(2, n);
    this->_capacidad = capacidad;
    this->_elementos = this->_capacidad > 0 ? new T[this->_capacidad] : NULL;
    this->_ultimo = -1;
}

template <typename T, bool (*F)(const T &a, const T &b)>
Heap<T, F>::Heap(const Heap<T, F> &heap)
{
    this->_ultimo = heap._ultimo;
    this->_capacidad = heap._capacidad;
    this->_elementos = NULL;
    if (this->_capacidad > 0)
    {
        this->_elementos = new T[this->_capacidad];
        for (signed int i = 0; i <= heap._ultimo; i++)
            this->_elementos[i] = heap._elementos[i];
    }
}

template <typename T, bool (*F)(const T &a, const T &b)>
Heap<T, F>::~Heap()
{
    if (!this->EstaVacio())
        this->Vaciar();
}

template <typename T, bool (*F)(const T &a, const T &b)>
void Heap<T, F>::Agregar(const T elemento)
{
    unsigned int num = this->ObtenerNumeroElementos();
    if (num == this->_capacidad)
        this->_redimensionar();
    this->_ultimo++;
    this->_elementos[this->_ultimo] = elemento;
    this->_cambiar_hacia_arriba(this->_ultimo);
}

template <typename T, bool (*F)(const T &a, const T &b)>
void Heap<T, F>::EliminarRaiz()
{
    if (this->EstaVacio())
        throw ExcepcionHeapVacio();
    this->_elementos[0] = this->_elementos[this->_ultimo];
    this->_ultimo--;
    this->_cambiar_hacia_abajo(0);
}

template <typename T, bool (*F)(const T &a, const T &b)>
T Heap<T, F>::ObtenerRaiz()
{
    if (this->EstaVacio())
        throw new ExcepcionHeapVacio();
    return _elementos[0];
}

template <typename T, bool (*F)(const T &a, const T &b)>
bool Heap<T, F>::EstaVacio()
{
    return this->_ultimo == -1;
}

template <typename T, bool (*F)(const T &a, const T &b)>
void Heap<T, F>::Vaciar()
{
    if (this->EstaVacio())
        return;
    delete this->_elementos;
    this->_elementos = NULL;
    this->_capacidad = 0;
    this->_ultimo = -1;
}

template <typename T, bool (*F)(const T &a, const T &b)>
unsigned int Heap<T, F>::ObtenerNumeroElementos()
{
    return this->_ultimo + 1;
}

template <typename T, bool (*F)(const T &a, const T &b)>
unsigned int Heap<T, F>::ObtenerCapacidad()
{
    return this->_capacidad;
}

template <typename T, bool (*F)(const T &a, const T &b)>
void Heap<T, F>::Imprimir()
{
    if (this->EstaVacio())
    {
        std::cout << "[ ]\n";
        return;
    }
    std::cout << "capacidad: " << this->_capacidad << "\n";
    std::cout << "[\n";
    for (unsigned int i = 0; i <= this->_ultimo; i++)
    {
        std::cout << "\t(valor = " << this->_elementos[i] << ", ";
        std::cout << "padre = ";
        if (this->_elementos[i] == this->_elementos[obtener_indice_padre(i)])
            std::cout << "NULL, ";
        else
            std::cout << this->_elementos[obtener_indice_padre(i)] << ", ";
        signed int hijo_izq_index = obtener_hijo_izquierda(i);
        std::cout << "hijo izquierda = ";
        if (hijo_izq_index > this->_capacidad)
            std::cout << "0, ";
        else
            std::cout << this->_elementos[hijo_izq_index] << ", ";
        signed int hijo_der_index = obtener_hijo_derecha(i);
        std::cout << "hijo derecha = ";
        if (hijo_der_index > this->_capacidad)
            std::cout << "0)\n";
        else
            std::cout << this->_elementos[hijo_der_index] << ")\n";

    }
    std::cout << "]\n";
}

template <typename T, bool (*F)(const T &a, const T &b)>
void Heap<T, F>::ImprimirLista()
{
    if (this->EstaVacio())
    {
        std::cout << "[ ]\n";
        return;
    }
    std::cout << "capacidad: " << this->_capacidad << "\n";
    std::cout << "[ ";
    for (unsigned int i = 0; i <= this->_ultimo; i++)
    {
        std::cout << this->_elementos[i] << ", ";
    }
    std::cout << "\b\b ]\n";
}

template <typename T, bool (*F)(const T &a, const T &b)>
Heap<T, F> &Heap<T,F>::operator=(const Heap<T, F> &heap)
{
    if (!this->EstaVacio())
        this->Vaciar();
    this->_capacidad = heap._capacidad;
    this->_elementos = new T[this->_capacidad];
    for (signed int i = 0; i <= heap._ultimo; i++)
        this->_elementos[i] = heap._elementos[i];
    return *this;
}
