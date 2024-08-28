#include "Gestion.h"

using std::cout; // Permite utilizar el objeto cout de la biblioteca est�ndar de C++.
using std::endl; // Permite utilizar el objeto endl de la biblioteca est�ndar de C++.

int MenuDeInicio()
{
    char tecla; // Variable para almacenar la tecla presionada.
    int x = 1; // Variable para almacenar la posici�n actual en el men�.

    CambiaCursor(APAGADO); // Llama a la funci�n CambiaCursor y apaga el cursor.
    gotoxy(1, 1); // Mueve el cursor a la posici�n (1, 1) en la consola.

    cout << "  ******TABLA HASH CON DIRECCIONAMIENTO CERRADO******" << endl << endl; // Imprime un encabezado en la consola.

    color(240); // Cambia el color de la fuente a gris claro.
    cout << "  Agregar elementos a la tabla " << endl; // Imprime una opci�n en el men�.

    color(7); // Restaura el color de la fuente al predeterminado.
    // Imprime las siguientes opciones en el men�:
    cout << "  Eliminar elementos de la tabla " << endl;
    cout << "  Buscar elemento " << endl;
    cout << "  Imprimir tabla " << endl;
    cout << "  Salir " << endl;
    x = 1;
    while (true)
    {

        if (kbhit())   // Verifica si se ha presionado una tecla en el teclado
        {
            tecla = getch(); // Obtiene la tecla presionada

            if (tecla == FLECHA_ABAJO)   // Comprueba si la tecla presionada es la flecha hacia abajo
            {
                if (x < 10)
                {
                    x = x + 1; // Incrementa el valor de x si es menor que 10
                }
                else
                {
                    x = 1; // Si x es igual a 10, lo establece en 1
                }
            }

            if (tecla == FLECHA_ARRIBA)   // Comprueba si la tecla presionada es la flecha hacia arriba
            {
                if (x > 1)
                {
                    x = x - 1; // Decrementa el valor de x si es mayor que 1
                }
                else
                {
                    x = 10; // Si x es igual a 1, lo establece en 10
                }
            }

            // Comprueba la posici�n actual en el men� y muestra las opciones correspondientes resaltadas.
            for (int i = 1; i <= 10; i++)
            {
                gotoxy(1, 2 + i); // Establece la posici�n del cursor en la pantalla
                if (i == x)
                {
                    color(240); // Establece el color del texto en resaltado si i es igual a x
                }
                else
                {
                    color(7); // Establece el color del texto en blanco si i no es igual a x
                }
                switch (i)
                {
                case 1:
                    cout << "  Agregar elementos a la tabla " << endl;
                    break;
                case 2:
                    cout << "  Eliminar elementos de la tabla " << endl;
                    break;
                case 3:
                    cout << "  Buscar elemento " << endl;
                    break;
                case 4:
                    cout << "  Imprimir tabla " << endl;
                    break;
                case 5:
                    cout << "  Vaciar tabla " << endl;
                    break;
                case 10:
                    cout << "  Salir " << endl;
                    break;
                }
            }

            if (tecla == ENTER)   // Comprueba si la tecla presionada es la tecla "Enter"
            {
                return x; // Devuelve el valor de x
            }
        }
    }

}

void AgregarElementos(TablaHashDC& tabla)
{
    char opcion; // Variable para almacenar la opci�n del usuario (S/N)
    CambiaCursor(ENCENDIDO, NORMAL); // Activa el cursor y establece su apariencia normal
    do
    {
        gotoxy(1,1);
        borrador();
        std::string nombre; // Variable para almacenar el nombre ingresado por el usuario
        int matricula; // Variable para almacenar la matr�cula ingresada por el usuario

        gotoxy(1,2);
        CambiaCursor(ENCENDIDO);
        cout << "  Ingrese el nombre: "; // Solicita al usuario ingresar el nombre
        std::getline(std::cin, nombre); // Lee el nombre ingresado por el usuario
        CambiaCursor(APAGADO);
        gotoxy(1,1);
        borrador();


        matricula = CapturaUnsignedInt("  Ingrese la matr\241cula: "); // Solicita al usuario ingresar la matr�cula


        Elemento elemento = {nombre, matricula}; // Crea un objeto de tipo Elemento con el nombre y la matr�cula ingresados
        tabla.Insertar(elemento); // Inserta el elemento en la tabla hash

        do
        {
            gotoxy(1,4);
            cout <<"  \250Desea agregar otro elemento? (S/N): "; // Pregunta al usuario si desea agregar otro elemento
            std::string entrada;
            std::getline(std::cin, entrada); // Lee la opci�n ingresada por el usuario

            if (entrada.length() != 1 || (entrada[0] != 'S' && entrada[0] != 's' && entrada[0] != 'N' && entrada[0] != 'n'))
            {
                cout << "  Opci\242n no v\240lida. Por favor, ingrese 'S' para agregar otro elemento o 'N' para salir." << endl << endl; // Verifica si la opci�n ingresada es v�lida y muestra un mensaje de error si no es el caso
                gotoxy(1,4);
                cout <<"                                                                                              ";
            }
            else
            {
                opcion = entrada[0]; // Almacena la opci�n ingresada por el usuario
                break; // Sale del ciclo do-while interno y contin�a con el flujo del programa
            }
        }
        while (true); // Repite hasta que se ingrese una opci�n v�lida (S/N)

        cout << endl;
        continue; // Salta al comienzo del ciclo do-while externo

        // Limpiar el b�fer de entrada
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    while (opcion == 'S' || opcion == 's'); // Repite hasta que la opci�n ingresada sea 'N' o 'n'
    CambiaCursor(APAGADO);
    gotoxy(1,1);
    borrador();
}
void EliminarElementos(TablaHashDC& tabla)
{
    // Se llama a la funci�n CambiaCursor con los argumentos ENCENDIDO y NORMAL para cambiar la apariencia del cursor.
    CambiaCursor(ENCENDIDO, NORMAL);
    char opcion;
    do
    {
        gotoxy(1,1);
        // Se llama a la funci�n borrador para borrar la pantalla.
        borrador();
        gotoxy(1,2);
        // Si la tabla est� vac�a, se muestra un mensaje indicando que no hay elementos en la tabla y se pausa el programa.
        if (tabla.EstaVacia())
        {
            cout << "  La tabla est\240 vac\241a. No se puede eliminar elementos.                                    " << endl;
            CambiaCursor(APAGADO);
            Sleep(2500);
            // Se rompe el bucle do-while y se sale de la funci�n.
            break;
        }
        int matricula;
        // Se solicita al usuario que ingrese la matr�cula del elemento que desea eliminar.

        matricula = CapturaUnsignedInt("  Ingrese la matr\241cula del elemento que desea eliminar: ");
        // Se llama a la funci�n EliminarElemento de la tabla para eliminar el elemento con la matr�cula especificada.
        tabla.Eliminar(matricula);
        // Si la tabla no est� vac�a, se muestra un mensaje preguntando si se desea eliminar otro elemento.
        if (!tabla.EstaVacia())
        {
            do
            {
                gotoxy(1,4);
                cout <<"  \250Desea eliminar otro elemento? (S/N): ";
                std::string input;
                // Se lee la entrada del usuario.
                std::getline(std::cin, input);
                // Se verifica si la entrada es v�lida (una sola letra 'S', 's', 'N' o 'n').
                if (input.length() != 1 || (input[0] != 'S' && input[0] != 's' && input[0] != 'N' && input[0] != 'n'))
                {
                    cout << "  Opci\242n no v\240lida. Por favor, ingrese 'S' para eliminar otro elemento o 'N' para salir." << endl;
                    gotoxy(1,4);
                    cout <<"                                                                                              ";
                }
                else
                {
                    // Se asigna la opci�n seleccionada por el usuario a la variable "opcion".
                    opcion = input[0];
                    break;
                }
            }
            while (true);
        }
        else
        {
            // Si la tabla est� vac�a despu�s de eliminar un elemento, se muestra un mensaje indicando que la tabla se ha quedado sin elementos y se pausa el programa.
            CambiaCursor(APAGADO);
            cout << endl << "  La tabla se ha quedado sin elementos." << endl;
            Sleep(3500);
            gotoxy(1,1);
            borrador();
            return;
        }
        cout << endl;
        // Se utiliza "continue" para volver al inicio del bucle do-while.
        continue;
        // Limpiar el b�fer de entrada
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    while (opcion == 'S' || opcion == 's');
    gotoxy(1,1);
    // Se llama a la funci�n borrador para borrar la pantalla.
    borrador();
}

void BuscarElementos(TablaHashDC& tabla)
{
    // Se llama a la funci�n CambiaCursor con los argumentos ENCENDIDO y NORMAL para cambiar la apariencia del cursor.
    CambiaCursor(ENCENDIDO, NORMAL);
    char opcion;
    do
    {
        gotoxy(1,1);
        // Se llama a la funci�n borrador para borrar la pantalla.
        borrador();

        gotoxy(1,2);
        // Si la tabla est� vac�a, se muestra un mensaje indicando que no hay elementos en la tabla y se pausa el programa.
        if (tabla.EstaVacia())
        {
            gotoxy(1,2);
            CambiaCursor(APAGADO);
            cout << "  La tabla no tiene elementos para buscar.                                                  " << endl;
            gotoxy(5,3);
            Sleep(2500);
            // Se rompe el bucle do-while y se sale de la funci�n.
            break;
        }
        int matricula;
        // Se solicita al usuario que ingrese la matr�cula del elemento que desea buscar.
        matricula = CapturaUnsignedInt("  Ingrese la matr\241cula del elemento que desea buscar: ");
        // Se llama a la funci�n Buscar de la tabla para buscar el elemento con la matr�cula especificada.
        if (tabla.Buscar(matricula))
        {
            gotoxy(1,2);
            cout << "  Elemento encontrado: [" << tabla.ObtenerNombreElemento(matricula) << ']' << endl;
        }
        else
        {
            gotoxy(1,2);
            cout << "  El elemento con matr\241cula [" << matricula << "] no se encuentra en la tabla." << endl;
        }
        // Si la tabla no est� vac�a, se muestra un mensaje preguntando si se desea buscar otro elemento.
        if (!tabla.EstaVacia())
        {
            do
            {
                gotoxy(1,4);
                cout << "  \250Desea buscar otro elemento? (S/N): ";
                std::string entrada;
                // Se lee la entrada del usuario.
                std::getline(std::cin, entrada);
                // Se verifica si la entrada es v�lida (una sola letra 'S', 's', 'N' o 'n').
                if (entrada.length() != 1 || (entrada[0] != 'S' && entrada[0] != 's' && entrada[0] != 'N' && entrada[0] != 'n'))
                {
                    cout << "  Opci\242n no v\240lida. Por favor, ingrese 'S' para buscar otro elemento o 'N' para salir." << endl << endl;
                    gotoxy(1,4);
                    cout <<"                                                                                              ";
                }
                else
                {
                    // Se asigna la opci�n seleccionada por el usuario a la variable "opcion".
                    opcion = entrada[0];
                    break;
                }
            }
            while (true);
            cout << endl;
            // Se utiliza "continue" para volver al inicio del bucle do-while.
            continue;
        }
    }
    while (opcion == 'S' || opcion == 's');

    gotoxy(1,1);
    // Se llama a la funci�n borrador para borrar la pantalla.
    borrador();
}

void ImprimirTabla(TablaHashDC& tabla)
{
    gotoxy(1,1);
    // Se llama a la funci�n borrador para borrar la pantalla.
    borrador();

    gotoxy(1,15);
    cout << " ***Tabla Hash con Direccionamiento Cerrado***";

    gotoxy(1,17);
    // Se llama a la funci�n ImprimirTabla de la tabla para mostrar la tabla en la consola.
    tabla.Imprimir();
}

bool VaciarTabla(TablaHashDC& tabla)
{
    // Borra la pantalla y mueve el cursor a la posici�n (1,1) en la consola.
    gotoxy(1,1);
    borrador();

    // Verifica si la tabla est� vac�a. Si es as�, devuelve false.
    if (tabla.EstaVacia())
    {
        return false;
    }

    // Vac�a la tabla llamando al m�todo VaciarTabla().
    tabla.Vaciar();

    // Devuelve true para indicar que la tabla se ha vaciado correctamente.
    return true;
}
