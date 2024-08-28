#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <string>

class Persona{
public:
    Persona(std::string nombre, bool es_noble) : nombre(nombre), es_noble(es_noble) {}
    std::string ObtenerNombre() const { return nombre; }
    bool esNoble() const { return es_noble; }
private:
    std::string nombre;
    bool es_noble;
};

#endif // PERSONA_H_INCLUDED
