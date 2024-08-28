#include "ListaEnlazada.h"

//****** Metodos indispensables
template<typename T>
ListaEnlazada<T>::~ListaEnlazada() {
    Vaciar();
}

//****** Metodos Agregar *******
template<typename T>
void ListaEnlazada<T>::AgregarEnInicio(T valor) {
    Elemento *nuevo = new Elemento(valor, primero);
    nuevo ->valor = valor;
    nuevo->siguiente = nullptr;
    if(EstaVacia()){
        primero = ultimo=  nuevo;
    }
    ultimo ->siguiente = nuevo;
    ultimo = nuevo;
    ++tam;
}

template<typename T>
void ListaEnlazada<T>::AgregarAlFinal(T valor) {
    Elemento *nuevo = new Elemento(valor);
    if (ultimo) {
        ultimo->siguiente = nuevo;
    } else {
        primero = nuevo;
    }
    ultimo = nuevo;
    tam++;
}

template<typename T>
void ListaEnlazada<T>::AgregarEnIndice(unsigned int pos, T valor) {
    if (pos == 0) {
        AgregarEnInicio(valor);
    } else if (pos >= tam) {
        AgregarAlFinal(valor);
    } else {
        Elemento *anterior = primero;
        for (unsigned int i = 0; i < pos - 1; i++) {
            anterior = anterior->siguiente;
        }
        Elemento *nuevo = new Elemento(valor, anterior->siguiente);
        anterior->siguiente = nuevo;
        tam++;
    }
}


//***** Metodos eliminar *******
template<typename T>
void ListaEnlazada<T>::EliminarEnInicio() {
    if (primero) {
        Elemento *temp = primero;
        primero = primero->siguiente;
        if (primero == nullptr) {
            ultimo = nullptr;
        }
        delete temp;
        tam--;
    }
}

template<typename T>
void ListaEnlazada<T>::EliminarDelFinal() {
    if (primero) {
        if (primero == ultimo) {
            delete primero;
            primero = ultimo = nullptr;
        } else {
            Elemento *anterior = primero;
            while (anterior->siguiente != ultimo) {
                anterior = anterior->siguiente;
            }
            delete ultimo;
            ultimo = anterior;
            ultimo->siguiente = nullptr;
        }
        tam--;
    }
}

template<typename T>
void ListaEnlazada<T>::EliminarEnIndice(unsigned int pos) {
    if (pos == 0) {
        EliminarEnInicio();
    } else if (pos < tam) {
        Elemento *anterior = primero;
        for (unsigned int i = 0; i < pos - 1; i++) {
            anterior = anterior->siguiente;
        }
        Elemento *temp = anterior->siguiente;
        anterior->siguiente = temp->siguiente;
        if (temp == ultimo) {
            ultimo = anterior;
        }
        delete temp;
        tam--;
    }
}

template<typename T>
void ListaEnlazada<T>::Eliminar(T valor) {
    /*Elemento *current = primero;
    Elemento *anterior = nullptr;

    while (current != nullptr && current->valor != valor) {
        anterior = current;
        current = current->siguiente;
    }

    if (current != nullptr) {
        if (anterior == nullptr) {
            primero = current->siguiente;
            if (primero == nullptr) {
                ultimo = nullptr;
            }
        } else {
            anterior->siguiente = current->siguiente;
            if (current == ultimo) {
                ultimo = anterior;
            }
        }
        delete current;
        tam--;
    }*/
}

template<typename T>
void ListaEnlazada<T>::EliminarTodos(T valor) {
    /*Elemento *current = primero;
    Elemento *anterior = nullptr;

    while (current != nullptr) {
        if (current->valor == valor) {
            if (anterior == nullptr) {
                primero = current->siguiente;
                if (primero == nullptr) {
                    ultimo = nullptr;
                }
            } else {
                anterior->siguiente = current->siguiente;
                if (current == ultimo) {
                    ultimo = anterior;
                }
            }
            Elemento *temp = current;
            current = current->siguiente;
            delete temp;
            tam--;
        } else {
            anterior = current;
            current = current->siguiente;
        }
    }*/
}

template<typename T>
void ListaEnlazada<T>::Vaciar() {
    while(primero != nullptr){
        Elemento *actual = primero;
        primero = primero ->siguiente;
        delete actual;
    }
}

template<typename T>
bool ListaEnlazada<T>::EstaVacia(){
    return tam == 0;
}

template<typename T>
T ListaEnlazada<T>::ObtenerPrimero(){
    if (primero) {
        return primero->valor;
    }
    throw std::out_of_range("La lista está vacía");
}

template<typename T>
T ListaEnlazada<T>::ObtenerUltimo(){
    if (ultimo) {
        return ultimo->valor;
    }
    throw std::out_of_range("La lista está vacía");
}

template<typename T>
T ListaEnlazada<T>::ObtenerEnPosicion(int pos){
    if (pos < 0 || pos >= tam) {
        throw std::out_of_range("Índice fuera de rango");
    }
    Elemento *current = primero;
    for (int i = 0; i < pos; i++) {
        current = current->siguiente;
    }
    return current->valor;
}

template<typename T>
void ListaEnlazada<T>::ModificarEnPos(int pos, T valor) {
    if (pos < 0 || pos >= tam) {
        throw std::out_of_range("Índice fuera de rango");
    }
    Elemento *current = primero;
    for (int i = 0; i < pos; i++) {
        current = current->siguiente;
    }
    current->valor = valor;
}

template<typename T>
T ListaEnlazada<T>::operator[](unsigned int pos) const {
    return ObtenerEnPosicion(pos);
}

template<typename T>
T& ListaEnlazada<T>::operator[](unsigned int pos) {
    if (pos < 0 || pos >= tam) {
        throw std::out_of_range("Índice fuera de rango");
    }
    Elemento *current = primero;
    for (unsigned int i = 0; i < pos; i++) {
        current = current->siguiente;
    }
    return current->valor;
}

template<typename T>
void ListaEnlazada<T>::Imprimir(){
    if(EstaVacia()){
        throw std::out_of_range("La lista esta vacia, no se puede eliminar ningun elemento.");
        return;
    }
    Elemento *actual = primero;
    std::cout << "Lista: [";
    while(actual != nullptr){
        std::cout << actual->valor << ", ";
        actual = actual->siguiente;
    }
    std::cout << "]";
    std::cout << std::endl;
}

template<typename T>
int ListaEnlazada<T>::ObtenerTam(){
    return tam;
}

/*template<typename T>
bool ListaEnlazada<T>::EncontrarValor(T valor){
    Elemento *current = primero;
    while (current != nullptr) {
        if (current->valor == valor) {
            return true;
        }
        current = current->siguiente;
    }
    return false;
}*/
