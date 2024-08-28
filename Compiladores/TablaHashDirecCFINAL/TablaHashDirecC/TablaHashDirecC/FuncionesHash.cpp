#include "FuncionesHash.h"
#include "InterfazGrafica.h"
#include "utilerias.h"

using namespace std;

int MenuDeInicio()
{
    char tecla; // Variable para almacenar la tecla presionada.
    int x = 1; // Variable para almacenar la posición actual en el menú.

    CambiaCursor(APAGADO); // Llama a la función CambiaCursor y apaga el cursor.
    gotoxy(1, 1); // Mueve el cursor a la posición (1, 1) en la consola.
    cout << "|-----------------------------------------------------|" <<endl;
    cout << "|";
    gotoxy(8, 2);
    cout << "TABLA HASH CON DIRECCIONAMIENTO CERRADO        |" << endl; // Imprime un encabezado en la consola.
    cout << "|-----------------------------------------------------|" <<endl;

    color(240); // Cambia el color de la fuente a gris claro.
    cout << "  1) Agregar elementos a la tabla " << endl; // Imprime una opción en el menú.

    color(7); // Restaura el color de la fuente al predeterminado.
    // Imprime las siguientes opciones en el menú:
    cout << "| 2) Eliminar elementos de la tabla " << endl;
    cout << "| 3) Buscar elemento " << endl;
    cout << "| 4) Imprimir tabla " << endl;
    cout << "| 5) Imprimir estad\241sticas " << endl;
    cout << "| 6) Guardar copia de la tabla " << endl;
    cout << "| 7) Restaurar \243ltima copia " << endl;
    cout << "| 8) Vaciar tabla " << endl;
    cout << "| 9) Eliminar copia " << endl;
    cout << "| 0) Salir " << endl;
    for(int i = 4; i < 14; i++){
        gotoxy(55,i);
        cout<<"|";
    }

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

            // Comprueba la posición actual en el menú y muestra las opciones correspondientes resaltadas.
            for (int i = 1; i <= 10; i++)
            {
                gotoxy(1, 2 + i); // Establece la posición del cursor en la pantalla
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
                    gotoxy(1, 4);
                    cout << "| 1) Agregar elementos a la tabla                     |" << endl;
                    break;
                case 2:
                    gotoxy(1, 5);
                    cout << "| 2) Eliminar elementos de la tabla                   |" << endl;
                    break;
                case 3:
                    gotoxy(1, 6);
                    cout << "| 3) Buscar elemento                                  |" << endl;
                    break;
                case 4:
                    gotoxy(1, 7);
                    cout << "| 4) Imprimir tabla                                   |" << endl;
                    break;
                case 5:
                    gotoxy(1, 8);
                    cout << "| 5) Imprimir estad\241sticas                            |" << endl;
                    break;
                case 6:
                    gotoxy(1, 9);
                    cout << "| 6) Guardar copia de la tabla                        |" << endl;
                    break;
                case 7:
                    gotoxy(1, 10);
                    cout << "| 7) Restaurar \243ltima copia                           |" << endl;
                    break;
                case 8:
                    gotoxy(1, 11);
                    cout << "| 8) Vaciar tabla                                     |" << endl;
                    break;
                case 9:
                    gotoxy(1, 12);
                    cout << "| 9) Eliminar copia                                   |" << endl;
                    break;
                case 10:
                    gotoxy(1, 13);
                    cout << "| 0) Salir                                            |" << endl;
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
    char opcion; // Variable para almacenar la opción del usuario (S/N)
    CambiaCursor(ENCENDIDO, NORMAL); // Activa el cursor y establece su apariencia normal
    do
    {
        gotoxy(1,1);
        borrador();
        std::string nombre; // Variable para almacenar el nombre ingresado por el usuario
        int matricula; // Variable para almacenar la matrícula ingresada por el usuario

        gotoxy(1,2);
        CambiaCursor(ENCENDIDO);
        do {
            imprimirTexto("=== Agregar entrada. ===", 0, -8);
            imprimirTexto("o Ingrese el nombre: ", -5, -3);
            std::getline(std::cin, nombre); // Lee el nombre ingresado por el usuario
            CambiaCursor(APAGADO);
            gotoxy(1,1);
            borrador();
            gotoxy(1,1);
            if (nombre.empty()) {
                imprimirTexto("  El nombre no puede estar vac\241o. Por favor, ingrese un nombre v\240lido.", 0, -1);
                CambiaCursor(ENCENDIDO);
            }
        } while (nombre.empty());


        matricula = palabraAscii(nombre); // Solicita al usuario ingresar la matrícula


        Elemento elemento = {nombre, matricula}; // Crea un objeto de tipo Elemento con el nombre y la matrícula ingresados
        tabla.Insertar(elemento); // Inserta el elemento en la tabla hash

        do
        {
            CambiaCursor(ENCENDIDO);
            imprimirTexto("=== Agregar entrada. ===", 0, -8);
            imprimirTexto("  \250Desea agregar otro elemento? (S/N): ", 0, -3); // Pregunta al usuario si desea agregar otro elemento
            std::string entrada;
            std::getline(std::cin, entrada); // Lee la opción ingresada por el usuario

            if (entrada.length() != 1 || (entrada[0] != 'S' && entrada[0] != 's' && entrada[0] != 'N' && entrada[0] != 'n'))
            {
                imprimirTexto("  Opci\242n no v\240lida. Por favor, ingrese 'S' para agregar otro elemento o 'N' para salir.", 0, -5);
                //std::cout <<  << std::endl << std::endl; // Verifica si la opción ingresada es válida y muestra un mensaje de error si no es el caso
                gotoxy(1,4);
            }
            else
            {
                opcion = entrada[0]; // Almacena la opción ingresada por el usuario
                break; // Sale del ciclo do-while interno y continúa con el flujo del programa
            }
        }
        while (true); // Repite hasta que se ingrese una opción válida (S/N)

        std::cout << std::endl;
        continue; // Salta al comienzo del ciclo do-while externo

        // Limpiar el búfer de entrada
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    while (opcion == 'S' || opcion == 's'); // Repite hasta que la opción ingresada sea 'N' o 'n'
    CambiaCursor(APAGADO);
    gotoxy(1,1);
    borrador();
}
void AgregarElementosAleatorios(TablaHashDC& tabla)
{
    int cantidad;

    // Lista de nombres predefinidos
    std::vector<std::string> nombres = {
    "Juan", "Ana", "Luis", "Marta", "Pedro", "Lucia", "Carlos", "Sofia",
    "Miguel", "Laura", "Jose", "Maria", "Antonio", "Elena", "Fernando", "Claudia",
    "Jorge", "Raquel", "Ricardo", "Patricia", "Andres", "Gabriela", "Manuel", "Isabel",
    "David"
    };

    // Inicializar la semilla del generador de números aleatorios
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Conjunto para almacenar los nombres ya utilizados
    std::unordered_set<std::string> nombresUsados;

    CambiaCursor(ENCENDIDO);
    imprimirTexto("=== Agregar Elementos Aleatorios ===", 0, -8);
    imprimirTexto("o Ingrese la cantidad de elementos a agregar: ", -1, -5);
    cout << endl;
    gotoxy(60,14);
    cin >> cantidad;

    int intentos = 0;
    while (nombresUsados.size() < cantidad && intentos < cantidad * 2) {
        // Seleccionar un nombre aleatorio de la lista
        int indice = std::rand() % nombres.size();
        std::string nombre = nombres[indice];

        // Verificar si el nombre ya ha sido usado
        if (nombresUsados.find(nombre) == nombresUsados.end()) {
            // Generar la matrícula basada en la suma de los códigos ASCII del nombre
            int matricula = palabraAscii(nombre);

            // Crear un objeto de tipo Elemento con el nombre y la matrícula
            Elemento elemento = {nombre, matricula};

            // Insertar el elemento en la tabla hash
            tabla.Insertar(elemento);

            // Marcar el nombre como usado
            nombresUsados.insert(nombre);
        }

        // Incrementar el contador de intentos
        ++intentos;
    }

    // Verificar si se pudieron agregar todos los elementos solicitados
    if (nombresUsados.size() < cantidad) {
        std::cout << "No se pudieron agregar todos los elementos solicitados. La lista de nombres es demasiado pequeña." << std::endl;
    }
    else
    {
        borrador();
        imprimirTexto("=== Agregar Elementos Aleatorios ===", 0, -8);
        imprimirTexto("Nombres agregados con exito ", -1, -5);
        imprimirTexto("Presione cualquier tecla para volver al menu", 0, -1);
            _getch();

    }
}
void EliminarElementos(TablaHashDC& tabla)
{
    // Se llama a la funci�n CambiaCursor con los argumentos ENCENDIDO y NORMAL para cambiar la apariencia del cursor.
    CambiaCursor(ENCENDIDO, NORMAL);
    char opcion;
    do
    {
        // Se llama a la funci�n borrador para borrar la pantalla.
        borrador();
        // Si la tabla est� vac�a, se muestra un mensaje indicando que no hay elementos en la tabla y se pausa el programa.
        if (tabla.EstaVacia())
        {
            imprimirTexto("=== Eliminar Elemento ===", 0, -8);
            imprimirTexto("o La tabla est\240 vac\241a. No se puede eliminar elementos.  ", 0, -3);
            CambiaCursor(APAGADO);
            imprimirTexto("Presione cualquier tecla para volver al menu", 0, -1);
            _getch();
            // Se rompe el bucle do-while y se sale de la función.
            break;
        }
        string nombre;
        // Se solicita al usuario que ingrese el nombre del elemento que desea eliminar.
        do {
            imprimirTexto("=== Eliminar Elemento ===", 0, -8);
            imprimirTexto("o Ingrese el nombre a eliminar: ", 0, -3);
            std::getline(std::cin, nombre); // Lee el nombre ingresado por el usuario
            CambiaCursor(APAGADO);
            gotoxy(1,1);
            borrador();
            gotoxy(1,1);
            if (nombre.empty()) {
                imprimirTexto("  El nombre no puede estar vac\241o. Por favor, ingrese un nombre v\240lido.", 0, -1);
                CambiaCursor(ENCENDIDO);
            }
        } while (nombre.empty());

        borrador();
        int matricula = palabraAscii(nombre);
        // Se llama a la funci�n EliminarElemento de la tabla para eliminar el elemento con la matr�cula especificada.
        tabla.Eliminar(matricula);
        // Si la tabla no est� vac�a, se muestra un mensaje preguntando si se desea eliminar otro elemento.
        if (!tabla.EstaVacia())
        {
            do
            {

                std::string input;
                imprimirTexto("=== Eliminar Elemento ===", 0, -8);
                imprimirTexto(" \250Desea eliminar otro elemento? (S/N): ", 0, -3);

                // Se lee la entrada del usuario.
                cin >> input;
                // Se verifica si la entrada es v�lida (una sola letra 'S', 's', 'N' o 'n').
                if (input.length() != 1 || (input[0] != 'S' && input[0] != 's' && input[0] != 'N' && input[0] != 'n'))
                {
                    borrador();
                    imprimirTexto(" Opci\242n no encontrada en la lista. Por favor, ingrese 'S' para eliminar otro elemento o 'N' para salir.", 0, -5);
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
            imprimirTexto("  La tabla se ha quedado sin elementos.", 0, -5);
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
    imprimirTexto("=== Vaciar Tabla ===", 0, -8);

    // Vac�a la tabla llamando al m�todo VaciarTabla().
    tabla.Vaciar();
    imprimirTexto("Presione cualquier tecla para volver al menu", 0, -1);
    _getch();


    // Devuelve true para indicar que la tabla se ha vaciado correctamente.
    return true;
}
void ModificarElemento(TablaHashDC& tabla)
{
    CambiaCursor(ENCENDIDO, NORMAL);
    imprimirTexto("=== Modificar Entrada ===", 0, -8);

    if (tabla.EstaVacia())
    {
        imprimirTexto("La tabla est\240 vac\241a. No hay elementos para modificar.", 0, -3);
        CambiaCursor(APAGADO);
        Sleep(2500);
        return;
    }

    std::string nombre;
    do {

        imprimirTexto("=== Modificar Entrada ===", 0, -8);
        imprimirTexto("Ingrese el nombre del elemento a modificar: ", 0, -3);
        std::getline(std::cin, nombre);
        borrador();

        if (nombre.empty()) {
            imprimirTexto("  El nombre no puede estar vac\241o. Por favor, ingrese un nombre v\240lido.", 0, -5);
        }

    } while (nombre.empty());

    int matricula = palabraAscii(nombre);
    imprimirTexto("=== Modificar Entrada ===", 0, -8);
    // Verificar si el elemento existe en la tabla
    if (!tabla.Buscar(matricula))
    {
        imprimirTexto("  El nombre no existe en la tabla. Por favor, ingrese un nombre v\240lido.", 0, -5);
        Sleep(2500);
        return;
    }

    // Solicitar los nuevos datos para el elemento
    std::string nuevoNombre;
    do {
        imprimirTexto("=== Modificar Entrada ===", 0, -8);
        imprimirTexto("  Ingrese el nuevo nombre: ", 0, -3);
        std::getline(std::cin, nuevoNombre);
        CambiaCursor(APAGADO);
        borrador();

        if (nuevoNombre.empty()) {
            imprimirTexto("  El nombre no puede estar vac\241o. Por favor, ingrese un nombre v\240lido.", 0, -5);
        }
    } while (nuevoNombre.empty());
    imprimirTexto("=== Modificar Entrada ===", 0, -8);
    // Crear el nuevo elemento modificado
    int nuevaMatricula = palabraAscii(nuevoNombre);
    Elemento nuevoElemento = {nuevoNombre, nuevaMatricula};

    // Eliminar el elemento antiguo
    tabla.Eliminar(matricula);

    // Insertar el nuevo elemento modificado
    tabla.Insertar(nuevoElemento);

    imprimirTexto("  El elemento ha sido modificado y reinsertado correctamente.", 0, -5);
    imprimirTexto("Presione cualquier tecla para volver al menu", 0, -3);
    _getch();
    borrador();
}
