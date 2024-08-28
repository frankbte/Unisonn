/*
Nombre: Calcular Volumenes
Autor: Francisco Yanez Bustamante
Fecha
Descripción:
*/

#include <iostream>
#include <cstdlib>
#include <limits>
#include "Menu.h"
#include "Utileria.h"
#include "GestionVolumenes.h"
#include "Volumenes.h"

using namespace std;

int main()
{
    int respuesta;

    do{
        respuesta = Menu();

        switch (respuesta){
        case SALIR :
            cout << "Vuelva pronto" << endl;
            break;
        case ESFERA :
            GestionVolEsfera();
            break;
        case CUBO :
            GestionVolCubo();
            break;
        case PIRAMIDE :
            GestionVolPiramide();
            break;
        case CILINDRO :
            GestionVolCilindro();
        }


        system("pause");
    }while(respuesta != SALIR);
	return 0;
}
