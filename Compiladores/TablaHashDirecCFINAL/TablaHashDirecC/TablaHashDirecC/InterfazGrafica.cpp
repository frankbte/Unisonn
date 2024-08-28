#include "InterfazGrafica.h"

//********************************************************************************************************************* MENÚ INICIAL.
int menuInicio(){
    //********** Muestra la información del menú inicial. *****************//
    imprimirTexto("===== Tabla Hash DC. =====", 0, -10);
    imprimirTexto("Agregar entrada.", 0, -7);
    imprimirTexto("Agregar entradas random.", 0, -5);
    imprimirTexto("Eliminar entrada.", 0, -3);
    imprimirTexto("Vaciar tabla.", 0, -1);
    imprimirTexto("Modificar entrada.", 0, 1);
    imprimirTexto("Imprimir.", 0, 3);
    imprimirTexto("Salir.", 0, 7);

    //**************************** Mueva la flecha de selección, que indica la selección actual del usuario. **********************//
    visibilidadCursor(false);
    int posicionActual = 0, posicionAnterior = 0;

    while(true){
        //********** Indica la selección actual del usuario.
        switch(posicionActual){
            case AGREGAR_ENTRADA:
                imprimirTexto (">>", -longitudTexto("Agregar entrada.")+5, -7);
                break;
            case AGREGAR_RANDOM:
                imprimirTexto (">>", -longitudTexto("Agregar entradas random.")+9, -5);
                break;
            case ELIMINAR_ENTRADA:
                imprimirTexto (">>", -longitudTexto("Eliminar entrada.")+5, -3);
                break;
            case VACIAR_TABLA:
                imprimirTexto (">>", -longitudTexto("Vaciar tabla.")+2, -1);
                break;
            case MODIFICAR_ENTRADA:
                imprimirTexto (">>", -longitudTexto("Modificar entrada.")+5, 1);
                break;
            case IMPRIMIR_TABLA:
                imprimirTexto (">>", -longitudTexto("Imprimir.")+1, 3);
                break;
             case SALIR:
                imprimirTexto (">>", -longitudTexto("Salir."), 7);
                break;
        };

        //********** Lee la acción del usuario: flecha abajo, flecha arriba o enter.
        int teclaPresionada;

        while(true){
            teclaPresionada = getch();

            if(teclaPresionada == 72 && posicionActual >= 1){ // Seleccionó flecha arriba.
                posicionAnterior = posicionActual;
                posicionActual = posicionActual - 1;
                Sleep(120);
                break;

            } else if(teclaPresionada == 80 && posicionActual <= 5){ // Seleccionó flecha abajo.
                posicionAnterior = posicionActual;
                posicionActual = posicionActual + 1;
                Sleep(120);
                break;

            } else if(teclaPresionada == 13){   // Dió enter.
                system("cls");
                return posicionActual;
            }
        }

        //********** Borra la antigua flecha de selección.
        switch(posicionAnterior){
            case AGREGAR_ENTRADA:
                imprimirTexto ("  ", -longitudTexto("Agregar entrada.")+5, -7);
                break;
            case AGREGAR_RANDOM:
                imprimirTexto ("  ", -longitudTexto("Agregar entradas random.")+9, -5);
                break;
            case ELIMINAR_ENTRADA:
                imprimirTexto ("  ", -longitudTexto("Eliminar entrada.")+5, -3);
                break;
            case VACIAR_TABLA:
                imprimirTexto ("  ", -longitudTexto("Vaciar tabla.")+2, -1);
                break;
            case MODIFICAR_ENTRADA:
                imprimirTexto ("  ", -longitudTexto("Modificar entrada.")+5, 1);
                break;
            case IMPRIMIR_TABLA:
                imprimirTexto ("  ", -longitudTexto("Imprimir.")+1, 3);
                break;
             case SALIR:
                imprimirTexto ("  ", -longitudTexto("Salir."), 7);
                break;
        };
    }
}

//********************************************************************************************************************* IMPRIMIR TEXTO
void imprimirTexto(const std::string& texto, int desplazamientoHorizontal, int desplazamientoVertical) {
    //*** Datos de la terminal.
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    //*** Determina el ancho y alto de la terminal.
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    //*** Ajuste a la coordenada X del texto a imprimir.
    int padding = (consoleWidth - texto.length()) / 2 + desplazamientoHorizontal;

    //*** Donde comenzará la impresión.
    COORD coord;
    coord.X = 0;
    coord.Y = consoleHeight / 2 + desplazamientoVertical;
    SetConsoleCursorPosition(hConsole, coord);

    //*** Imprimir el texto en el centro.
    std::cout << std::string(padding, ' ');
    std::cout << texto << std::endl;

    //*** Ajustar el cursor adyancte al final del texto.
    coord.X = padding + longitudTexto(texto) + 1;
    SetConsoleCursorPosition(hConsole, coord);
}

//********************************************************************************************************************* LONGITUD TEXTO.
int longitudTexto(std::string texto){
    int longitudCadena = 0;

    for (char c : texto) ++longitudCadena;
    return longitudCadena;
}

//******************************* DESEA CONTINUAR OPERACIÓN.

bool continuarOperacion(const std::string& cadena, int x, int y){
    imprimirTexto(cadena, x, y);   //Petición para continuar.
    std::string continuar; std::cin >> continuar; //Respuesta del usuario.

    //*** Lee la respuesta.
    while(true){
        if(continuar[0] == 's' || continuar[0] == 'S'){ //Continuar operación.
            system("cls");
            return true;

        } else if(continuar[0] == 'n' || continuar[0] == 'N'){ //Finalizar operación.
            return false;

        } else{
            std::cout << "Respuesta inválida.\n"; //Respuesta inválida.
            std::cout << cadena; std::cin >> continuar;
        }
    }
}

//************************** VISIBILIDAD DEL CURSOR.
void visibilidadCursor(bool visible) {
    //*** Obtiene información de actual terminal.
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) {
        std::cerr << "Error getting console handle." << std::endl;
        return;
    }

    CONSOLE_CURSOR_INFO cursorInfo;
    if (!GetConsoleCursorInfo(hConsole, &cursorInfo)) {
        std::cerr << "Error getting cursor info." << std::endl;
        return;
    }

    //*** Establece la (in)visibilidad del cursor.
    cursorInfo.bVisible = visible;
    if (!SetConsoleCursorInfo(hConsole, &cursorInfo)) {
        std::cerr << "Error setting cursor info." << std::endl;
        return;
    }
}
