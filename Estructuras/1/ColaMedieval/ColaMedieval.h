#include <iostream>

using std::cout;
using std::endl;

// Estructura para almacenar la información de una persona en la cola medieval
struct Persona 
{
    int id;         // Identificador único de la persona
    bool es_noble;  // Verdadero si la persona es un noble, falso si es un plebeyo
    Persona(){}
    Persona(int id, bool es_noble) : id(id), es_noble(es_noble) {}
};

// Definición de la clase ColaMedieval
class ColaMedieval 
{
private:
    Persona* elementos;     // Array dinámico para almacenar los elementos de la cola
    int capacidad;          // Capacidad máxima de la cola
    int primero;            // Índice del primer elemento en la cola
    int ultimo;             // Índice del último elemento en la cola
    int num_nobles;         // Número de nobles en la cola
    int num_plebeyos;       // Número de plebeyos en la cola
public:
    // Constructor que recibe la capacidad máxima de la cola
    ColaMedieval(int capacidad) {
        elementos = new Persona[capacidad];
        this->capacidad = capacidad;
        primero = -1;
        ultimo = -1;
        num_nobles = 0;
        num_plebeyos = 0;
    }
    
    // Destructor
    ~ColaMedieval() {
        delete[] elementos;
    }
    
    // Métodos para añadir una nueva persona a la cola
    void agregar_noble(int id) {
        agregar_persona(true, id);
    }
    
    void agregar_plebeyo(int id) {
        agregar_persona(false, id);
    }
    
    // Método privado para añadir una nueva persona a la cola
    void agregar_persona(bool es_noble, int id) {
        if (num_nobles == 0 || !es_noble) {
            // Si no hay nobles en la cola o la persona es un plebeyo, se agrega al final
            if (ultimo == capacidad - 1) {
                ultimo = 0;
            } else {
                ultimo++;
            }
            elementos[ultimo].es_noble = es_noble;
            elementos[ultimo].id = id;
            if (primero == -1) {
                primero = 0;
            }
        } else {
            // Si hay nobles en la cola y la persona es un noble, se agrega antes del primer plebeyo
            int i = primero;
            while (i != ultimo && elementos[i].es_noble) {
                i = (i + 1) % capacidad;
            }
            if (i == ultimo && elementos[i].es_noble) {
                // Si todos los elementos son nobles, se agrega al final
                if (ultimo == capacidad - 1) {
                    ultimo = 0;
                } else {
                    ultimo++;
                }
                elementos[ultimo].es_noble = es_noble;
                elementos[ultimo].id = id;
            } else {
                // Se desplazan los elementos hacia la derecha para dejar espacio para el nuevo noble
                int j = ultimo;
                while (j != i) {
                    if (j == 0) {
                        elementos[j] = elementos[capacidad - 1];
                        j = capacidad - 1;
                    } else {
                        elementos[j] = elementos[j - 1];
                        j--;
                    }
                }
                elementos[i].es_noble = es_noble;
                elementos[i].id = id;
            if (ultimo == capacidad - 1) {
                ultimo = 0;
            } else {
                ultimo++;
            }
        }
        if (primero == -1) {
            primero = 0;
        }
    }
    if (es_noble) {
        num_nobles++;
    } else {
        num_plebeyos++;
    }
}

// Métodos para consultar el primer y último elemento de la cola
Persona consultar_primero() {
    return elementos[primero];
}

Persona consultar_ultimo() {
    return elementos[ultimo];
}

// Método para eliminar un elemento de la cola
void eliminar() {
    if (primero == -1) {
        // La cola está vacía
        return;
    }
    if (num_nobles > 0) {
        // Se busca el primer noble en la cola
        int i = primero;
        while (i != ultimo && !elementos[i].es_noble) {
            i = (i + 1) % capacidad;
        }
        if (elementos[i].es_noble) {
            // Se elimina el noble
            if (primero == ultimo) {
                primero = -1;
                ultimo = -1;
            } else if (i == primero) {
                primero = (primero + 1) % capacidad;
            } else if (i == ultimo) {
                ultimo--;
            } else {
                for (int j = i; j != primero; j = (j - 1 + capacidad) % capacidad) {
                    elementos[j] = elementos[(j - 1 + capacidad) % capacidad];
                }
                primero = (primero + 1) % capacidad;
            }
            num_nobles--;
        } else {
            // No hay nobles en la cola, se elimina el primer plebeyo
            if (primero == ultimo) {
                primero = -1;
                ultimo = -1;
            } else {
                primero = (primero + 1) % capacidad;
            }
            num_plebeyos--;
        }
    } else {
        // No hay nobles en la cola, se elimina el primer plebeyo
        if (primero == ultimo) {
            primero = -1;
            ultimo = -1;
        } else {
            primero = (primero + 1) % capacidad;
        }
        num_plebeyos--;
    }
}

// Métodos para consultar el número de nobles, plebeyos y ciudadanos en la cola
int consultar_num_nobles() {
    return num_nobles;
}

int consultar_num_plebeyos() {
    return num_plebeyos;
}

int consultar_num_ciudadanos() {
    return num_nobles + num_plebeyos;
}

// Método para consultar si la cola está vacía
bool esta_vacia() {
    return primero == -1;
}

// Método para imprimir la cola
void imprimir() {
    if (esta_vacia()) {
        // La cola está vacía
        cout << "La cola medieval está vacía." << endl;
        return;
    }
    cout << "Cola medieval:" << endl;
    int i = primero;
    while (!esta_vacia()) {
        cout << "  " << (elementos[i].es_noble ? "Noble" : "Plebeyo") << " " << elementos[i].id << endl;
        if (i == ultimo) {
            break;
        }
        i = (i + 1) % capacidad;
    }
}
};

// Función para simular al Rey Arturo atendiendo peticiones de los ciudadanos
void simular_atencion(ColaMedieval& cola) {
int num_atenciones = 0;
while (!cola.esta_vacia()) {
Persona persona = cola.consultar_primero();
cola.eliminar();
num_atenciones++;
cout << "Atendiendo " << (persona.es_noble ? "al noble " : "al plebeyo ") << persona.id << " (" << num_atenciones << " de " << cola.consultar_num_ciudadanos() << ")" << endl;
}
}
