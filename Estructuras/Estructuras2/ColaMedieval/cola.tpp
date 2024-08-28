#include <cstdlib>

template<typename T>
Cola<T>::Cola()
{
    tam = 0;
    primero = nullptr;
    ultimo = nullptr;
}

template<typename T>
Cola<T>::~Cola()
{
    Vaciar();
}

template<typename T>
Cola<T>::Cola(const Cola<T> &c)
{

}

template<typename T>
Cola<T>::operator=(const Cola<T> &c)
{
    if(this == &c) return *this;
    Vaciar();
    Elemento *actual = c.primero;
    while(actual != nullptr){
        Encolar(actual->valor);
        actual = actual ->siguiente;
    }
    return *this;
}

template<typename T>
void Cola<T>::Encolar(T valor)
{
   Elemento *nuevo = new Elemento;
   nuevo ->valor = valor;
   nuevo ->siguiente = nullptr;
   if(EstaVacia()){
        primero = ultimo = nuevo;
   }else{
        ultimo ->siguiente = nuevo;
        ultimo = nuevo;
   }
   tam++;
}

template<typename T>
void Cola<T>::Desencolar()
{
    if(EstaVacia()){
        std::cout << "Error: la cola esta vacia...";
        return;
    }
    Elemento *aux = primero;
    primero = primero -> siguiente;
    delete aux;
    if (primero == nullptr) {
        ultimo = nullptr;
    }
    tam--;
}

template<typename T>
int Cola<T>::ObtenerTam()
{
    return tam;
}

template<typename T>
T Cola<T>::ObtenerPrimero()
{
    if(EstaVacia()){
        std::cout << "Error: la cola esta vacia...";
        return -1;
    }

    return primero ->valor;
}

template<typename T>
T Cola<T>::ObtenerUltimo()
{
    if(EstaVacia()){
        std::cout << "Error: la cola esta vacia...";
        return -1;
    }

    return ultimo ->valor;
}

template<typename T>
bool Cola<T>::EstaVacia()
{
    return(tam == 0);
}

template<typename T>
void Cola<T>::Vaciar()
{
    while(!EstaVacia()){
        Desencolar();
    }
}

template<typename T>
void Cola<T>::Imprimir()
{
    if(EstaVacia()){
        std::cout << "Error: La cola esta vacia..." << std::endl;
        return;
    }
    Elemento *actual = primero;
    std::cout << "Cola: ";
    std::cout << "[ ";
    while(actual != nullptr){
        std::cout << actual->valor << ", ";
        actual = actual ->siguiente;
    }
    std::cout << "]";
    std::cout << std::endl;
}

