//Ezequiel Isaac Rodriguez Tenorio
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "ColaMedieval.h"

using namespace std;

int main() {
srand(time(nullptr));

// Creación de la cola medieval
ColaMedieval cola(10);

cout << "Encolando :" << endl << endl;
// Simulación de la llegada de ciudadanos a la cola
for (int i = 1; i <= 10; i++) {
    bool noble = rand() % 2;
    if (noble==false)
    {
        cola.agregar_plebeyo(i);    
    }else if(noble == true)
    {
        cola.agregar_noble(i);
    }
    
    cout << "Llega " << (noble ? "el noble " : "el plebeyo ") << i << endl;
}
cout << endl;
cout << "Asi se ve la cola medieval: "<< endl << endl;
// Impresión de la cola medieval
cola.imprimir();
cout << endl;
cout << "Atendiendo a la cola medieval: " << endl << endl;
// Simulación de la atención del Rey Arturo
simular_atencion(cola);

return 0;
}