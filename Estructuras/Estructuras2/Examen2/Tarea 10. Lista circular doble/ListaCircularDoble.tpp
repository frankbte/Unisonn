

template<typename T>
ListaCD<T>::ListaCD() : cabeza(nullptr), tam(0) {}

template<typename T>
ListaCD<T>::ListaCD(const ListaCD& otra)
{
    cabeza = nullptr;
    tam = 0;
    Elemento* actual = otra.cabeza;
    for (int i = 0; i < otra.tam; i++)
    {
        Agregar(actual->valor);
        actual = actual->siguiente;
    }
}

template<typename T>
ListaCD<T>& ListaCD<T>::operator=(const ListaCD<T>& otra)
{
    if (this != &otra)
    {
        Vaciar();

        Elemento* actual = otra.cabeza;
        for (int i = 0; i < otra.tam; i++)
        {
            Agregar(actual->valor);
            actual = actual->siguiente;
        }
    }
    return *this;
}

template<typename T>
ListaCD<T>::~ListaCD()
{
    Vaciar();
}


template<typename T>
void ListaCD<T>::Agregar(const T& valor)
{
    if (EstaVacia())
    {
        cabeza = new Elemento(valor);
        cabeza->siguiente = cabeza->anterior = cabeza;
    }
    else
    {
        Elemento* nuevo = new Elemento(valor, cabeza->siguiente, cabeza);
        cabeza->siguiente->anterior = nuevo;
        cabeza->siguiente = nuevo;
    }
    ++tam;
}
template<typename T>
void ListaCD<T>::AgregarEnCabeza(const T& valor)
{
    Elemento* nuevo = new Elemento(valor);
    if (EstaVacia())
    {
        cabeza = nuevo;
        cabeza->siguiente = cabeza->anterior = cabeza;
    }
    else
    {
        nuevo->siguiente = cabeza;
        nuevo->anterior = cabeza->anterior;
        cabeza->anterior->siguiente = nuevo;
        cabeza->anterior = nuevo;
        cabeza = nuevo;
    }
    ++tam;
}


template<typename T>
void ListaCD<T>::Eliminar(const T& valor)
{
    if (EstaVacia())
    {
        throw std::out_of_range("La lista est\240 vac\241a");
    }

    Elemento* Eliminando = nullptr;

    if (tam == 1)
    {
        if (cabeza->valor == valor)
        {
            Eliminando = cabeza;
            cabeza = nullptr;
        }
    }
    else
    {
        Elemento* p = cabeza;
        while (p != cabeza->anterior)
        {
            if (p->valor == valor)
            {
                Eliminando = p;
                break;
            }
            p = p->siguiente;
        }
    }

    if (Eliminando != nullptr)
    {
        if (Eliminando == cabeza)
        {
            cabeza = cabeza->siguiente;
        }
        Eliminando->anterior->siguiente = Eliminando->siguiente;
        Eliminando->siguiente->anterior = Eliminando->anterior;
        delete Eliminando;
        --tam;
    }
    else
    {
        throw std::invalid_argument("El valor no se encuentra en la lista");
    }
}

template<typename T>
void ListaCD<T>::EliminarCabeza()
{
    if (EstaVacia())
    {
        throw std::out_of_range("La lista est\240 vac\241a");
    }

    Elemento* Eliminando = cabeza;

    if (tam == 1)
    {
        cabeza = nullptr;
    }
    else
    {
        cabeza->anterior->siguiente = cabeza->siguiente;
        cabeza->siguiente->anterior = cabeza->anterior;
        cabeza = cabeza->siguiente;
    }

    delete Eliminando;
    --tam;
}

template<typename T>
void ListaCD<T>::AvanzarCabeza()
{
    if (cabeza != nullptr)
    {
        cabeza = cabeza->siguiente;
    }
    else
    {
        throw std::out_of_range("La lista est\240 vac\241a");
    }
}

template<typename T>
void ListaCD<T>::RetrocederCabeza()
{
    if (cabeza != nullptr)
    {
        cabeza = cabeza->anterior;
    }
    else
    {
        throw std::out_of_range("La lista est\240 vac\241a");
    }
}

template<typename T>
T ListaCD<T>::ValorCabeza() const
{
    if (EstaVacia())
    {
        throw std::out_of_range("La lista est\240 vac\241a");
    }

    return cabeza->valor;
}

template<typename T>
int ListaCD<T>::ObtenerTam()const
{
    return tam;
}

template<typename T>
bool ListaCD<T>::Buscar(const T& valor) const
{
    if (EstaVacia())
    {
        throw std::out_of_range("La lista est\240 vac\241a");
    }

    Elemento* actual = cabeza;
    do
    {
        if (actual->valor == valor)
        {
            return true;
        }
        actual = actual->siguiente;
    }
    while (actual != cabeza);

    return false;
}

template<typename T>
bool ListaCD<T>::EstaVacia() const
{
    return tam == 0;
}

template<typename T>
void ListaCD<T>::Vaciar()
{
    while (!EstaVacia())
    {
        EliminarCabeza();
    }
}

template<typename T>
void ListaCD<T>::Imprimir() const
{
    if (EstaVacia())
    {
        std::cout << "La lista está vacía" << std::endl;
        return;
    }

    Elemento* actual = cabeza;
    std::cout << "Elementos de la lista: ";
    for (int i = 0; i < tam; i++)
    {
        std::cout << actual->valor;
        if (i < tam - 1)
        {
            std::cout << ", ";
        }
        actual = actual->siguiente;
    }
    std::cout << std::endl;
}


template<typename T>
void ListaCD<T>::BorrarTodosElemento(const T& valor)
{
    if (EstaVacia())
    {
        throw std::runtime_error("No se puede borrar elementos de una lista vac\241a.");
    }

    // Comprobar si la cabeza de la lista debe ser borrada
    while (cabeza->valor == valor)
    {
        Elemento* temp = cabeza;
        cabeza = cabeza->siguiente;
        cabeza->anterior = temp->anterior;
        temp->anterior->siguiente = cabeza;
        delete temp;
        --tam;
    }

    // Continuar con el resto de la lista
    Elemento* actual = cabeza->siguiente;

    do
    {
        if (actual->valor == valor)
        {
            actual->anterior->siguiente = actual->siguiente;
            actual->siguiente->anterior = actual->anterior;
            Elemento* temp = actual;
            actual = actual->siguiente;
            delete temp;
            --tam;
        }
        else
        {
            actual = actual->siguiente;
        }
    }
    while (actual != cabeza);
}


