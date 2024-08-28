#include "utilerias.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::numeric_limits;

// Funci�n para capturar un n�mero real de doble precisi�n desde la consola
long double CapturarRealDoble(const char solicitud[])
{
    long double numero;
    do
    {
        gotoxy(1,1);
        cout << "                                                                                                ";
        gotoxy(1,1);
        cout << solicitud;  // Mostrar solicitud al usuario
        CambiaCursor(ENCENDIDO);
        cin >> numero;  // Capturar el n�mero desde la consola

        if (cin.bad())  // Verificar si hubo una p�rdida de datos en el flujo de entrada
        {
            throw "  P\202rdida de datos en el flujo.";  // Lanzar una excepci�n indicando la p�rdida de datos
        }

        if (cin.fail())  // Verificar si el dato introducido no es un n�mero
        {
            cout << "  Error: El dato introducido no es un n\243mero.                                                     " << endl << endl;  // Mostrar mensaje de error
            cin.clear();  // Limpiar los indicadores de error del flujo de entrada
            cin.ignore(numeric_limits<int>::max(), '\n');  // Ignorar el resto de la l�nea inv�lida
            continue;  // Volver al inicio del bucle y solicitar nuevamente el n�mero
        }

        // Verificar si hay caracteres no num�ricos en el b�fer
        string remainingInput;
        getline(cin, remainingInput);  // Leer el resto de la l�nea introducida

        bool containsNonNumeric = false;
        for (char c : remainingInput)
        {
            if (!isdigit(c) && c != '-' && c != '.' && c != 'e' && c != 'E')
            {
                containsNonNumeric = true;
                break;
            }
        }

        if (containsNonNumeric)  // Si hay caracteres no num�ricos en el b�fer, mostrar mensaje de error
        {
            cout << "  Error: El dato introducido no es un n\243mero.                                                      " << endl << endl;
            continue;  // Volver al inicio del bucle y solicitar nuevamente el n�mero
        }

        break;  // Salir del bucle si el n�mero es v�lido

    }
    while (true);

    return numero;  // Devolver el n�mero capturado
}

// Funci�n para capturar un n�mero entero desde la consola
int CapturaEntero(const char solicitud[])
{

    int numero;
    long double aux;

    do
    {
        gotoxy(1,1);
        cout << "                                                                                                " ;
        gotoxy(1,1);

        aux = CapturarRealDoble(solicitud);  // Capturar un n�mero real de doble precisi�n
        numero = static_cast<int>(aux);  // Convertir el n�mero capturado a entero

        if (numero != aux)  // Verificar si el n�mero no es exactamente un entero
        {
            cout << "  Error: Debe ser un n\243mero entero.                                                        " << endl << endl;  // Mostrar mensaje de error
        }

    }
    while (numero != aux);    // Repetir el bucle mientras el n�mero no sea exactamente un entero

    return numero;  // Devolver el n�mero entero capturado
}
// Funci�n para capturar un n�mero entero desde la consola
int CapturaUnsignedInt(const char solicitud[])
{

    int numero;
    long double aux;

    do
    {
        gotoxy(1,1);
        cout << "                                                                                                " ;
        gotoxy(1,1);
        aux = CapturarRealDoble(solicitud);  // Capturar un n�mero real de doble precisi�n
        numero = static_cast<int>(aux);  // Convertir el n�mero capturado a entero

        if (numero != aux)  // Verificar si el n�mero no es exactamente un entero
        {
            cout << "  Error: Debe ser un n\243mero entero.                                            " << endl << endl;  // Mostrar mensaje de error
        }
        if (numero < 0) // Verificar si el n�mero tiene algun signo.
        {

            cout << "  Error: El valor no puede ser negativo.                                                 " << endl << endl; // Mostrar mensaje de error
        }

    }
    while (numero != aux || numero < 0);    // Repetir el bucle mientras el n�mero no sea exactamente un entero

    gotoxy(1,2);
    cout << "                                                                                                " ;
    return numero;  // Devolver el n�mero entero capturado
}

// Funci�n para posicionar el cursor en una posici�n espec�fica de la consola
void gotoxy(unsigned short x, unsigned short y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // Obtener el identificador del flujo de salida
    COORD coord = { static_cast<SHORT>(x - 1), static_cast<SHORT>(y - 1) };  // Crear una estructura COORD con las coordenadas
    SetConsoleCursorPosition(handle, coord);  // Establecer la posici�n del cursor en la consola
}

// Funci�n para cambiar el estado y modo del cursor en la consola
void CambiaCursor(estadoCursor estado, modoCursor modo)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  // Obtener el identificador del flujo de salida
    CONSOLE_CURSOR_INFO ConCurInf;

    ConCurInf.dwSize = modo;  // Establecer el tama�o del cursor
    ConCurInf.bVisible = estado;  // Establecer la visibilidad del cursor

    SetConsoleCursorInfo(hOut, &ConCurInf);  // Establecer la informaci�n del cursor en la consola
}

// Funci�n para borrar varias l�neas en la consola
void borrador()
{
    for(int i = 0; i < 50; ++i)
    {
        std::cout <<"                                                                                                             " << std::endl;  // Imprimir espacios en blanco para borrar una l�nea
    }
}

// Funcion que espera unos segundos antes de borrar una l�nea en la consola.
void borradorTemp()
{
    Sleep(2500);
    std::cout <<"                                                                                                                 " << std::endl;  // Imprimir espacios en blanco para borrar una l�nea

}

// Funci�n para cambiar el color del texto en la consola
void color(int X)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), X);  // Establecer el atributo de color del texto en la consola
}
