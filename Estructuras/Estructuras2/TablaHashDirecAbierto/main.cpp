#include <iostream>
#include "ListaEnlazada.h"

using namespace std;

int main()
{
    try{
        ListaEnlazada<int> lista;
        lista.AgregarEnInicio(10);
        lista.AgregarAlFinal(200);
        lista.AgregarEnInicio(1);
        lista.Imprimir();
        lista.EliminarEnInicio();
        lista.Imprimir();
        lista.EliminarDelFinal();
        lista.Imprimir();
        lista.Vaciar();
        lista.Imprimir();
        lista.AgregarEnInicio(25);
        lista.Imprimir();

    }catch(const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
