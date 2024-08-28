#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED


class Grafica{
public:

private:
    int numAristas;
    int numNodos;
    struct Nodo{
        string nombre;
        Nodo* siguiente;
        struct Arista{
            Arista* sig;
            Nodo* adyacente;

        }*primera, *ultima;
    };
};

#endif // AVL_H_INCLUDED
