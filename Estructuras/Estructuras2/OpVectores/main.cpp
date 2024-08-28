#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
    try{

        Vector v, w, suma;

        cout << "Programa que suma 2 vectores de dimension 3" << endl;
        cout << endl;

        cout << "Capturando el primer vector de dimension " << v.ObtenerDim() << ": " << endl;
        cin >> v;

        cout << "Capturando el segundo vector de dimension " << w.ObtenerDim() << ": " << endl;
        cin >> w;

        suma = v + w;

        cout << "Vector resultante: " << endl;
        cout << suma;
        cout << endl;
        cout << endl;

        Vector p;
        p = v * 5.3;
        cout << v;
        cout << " * " << 5.3 << " = ";
        cout << p;

        cout << endl;

    }catch(const char *msn){
        cerr << "Error: " << msn << endl;
    }

    return 0;
}
/* los constructores son los unicos metodos de clase que aceptan inicializadores.
    Los iniciailizadores van despues de la declaracion del metodo y empieza con dos puntos,
    y despues el atributo a inicializar seguido del valor en parentesis.
    Los inicializadores son obligatorios, para inicializar un atributo constante,
    para inicializar un atributo estatico, cuando se inicilizara la parte heredada de una funcion.

*/
