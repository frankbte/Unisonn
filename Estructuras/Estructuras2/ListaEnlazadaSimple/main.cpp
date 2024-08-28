#include <iostream>
#include "ListaSimple.h"

using namespace std;

int main()
{
    try{
        Lista lista;
        lista.AgregarEnInicio(10);
        lista.Imprimir();
        lista.EliminarDeInicio();
        lista.Imprimir();
    }catch(const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
