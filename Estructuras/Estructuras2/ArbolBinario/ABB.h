#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

class ArbolBinBusqueda {

    public:
        ArbolBinBusqueda();
        ArbolBinBusqueda(const ArbolBinBusqueda &arbol);
        ~ArbolBinBusqueda();
        ArbolBinBusqueda &operator=(const ArbolBinBusqueda &arbol);

        void Agregar(int valor);
        void Imprimir();
        void Vaciar();
        void ImprimirPorNiveles();
        bool EstaVacio();

    private:
        int numNodos;
        struct Nodo {
            Nodo (int valor, Nodo *izq = nullptr, Nodo *der = nullptr)
                : valor(valor), izq(izq), der(der) {}
            int valor;
            Nodo *izq, *der;
        };
        Nodo *raiz;

    private:
        void AgregarUtil(int valor, Nodo *&subRaiz);
        void ImprimirAscendente(Nodo *subRaiz);
        void Vaciar(Nodo *& subRaiz);
};

#endif // ABB_H_INCLUDED
