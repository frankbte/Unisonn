#include "TablaHash.h"


//************ Metodos para asegurar el buen funcionamiento ***************
TablaHashDC::TablaHashDC(int capacidad): Capacidad(capacidad), CapacidadMaxima(capacidad), NumeroElementos(0)
{
    tabla = new Lista<Elemento>[Capacidad];
}

TablaHashDC::TablaHashDC(const TablaHashDC& otraTabla) : Capacidad(otraTabla.Capacidad), CapacidadMaxima(otraTabla.CapacidadMaxima), NumeroElementos(otraTabla.NumeroElementos)
{
    tabla = new Lista<Elemento>[Capacidad];
    for(int i = 0; i < Capacidad; i++)
    {
        tabla[i] = otraTabla.tabla[i];
    }
}

TablaHashDC& TablaHashDC::operator=(const TablaHashDC& otraTabla)
{
    if(this == &otraTabla)
    {
        return *this;
    }

    delete[] tabla;

    Capacidad = otraTabla.Capacidad;
    CapacidadMaxima = otraTabla.CapacidadMaxima;
    NumeroElementos = otraTabla.NumeroElementos;

    tabla = new Lista<Elemento>[Capacidad];

    for(int i = 0;  i < Capacidad; i++)
    {
        tabla[i] = otraTabla.tabla[i];
    }

    return *this;
}

TablaHashDC::~TablaHashDC()
{
    delete[] tabla;
}


//********** Metodo Insertar **************
void TablaHashDC::Insertar(const Elemento& elemento)
{
    if(EstaVacia())
    {
        int indice = FuncionHash(elemento.Id);
        tabla[indice].AgregarAlFinal(elemento);
        NumeroElementos++;
    }
    else
    {
        if(Buscar(elemento.Id))
        {
            gotoxy(1,2);
            std::cout << "La matricula ya está en uso. No se puede agregar el elemento." << std::endl;
            return;
        }
        int indice = FuncionHash(elemento.Id);
        tabla[indice].AgregarAlFinal(elemento);
        NumeroElementos++;

        if(tabla[indice].Tamano() >= 5)
        {
            Redimensionar();
        }

    }
}


//************* Metodo Eliminar ***************
void TablaHashDC::Eliminar(int matricula)
{
    if(EstaVacia())
    {
        std::cout << "La tabla esta vacia. No se pueden eliminar elementos." << std::endl;
        return;
    }
    int indice = FuncionHash(matricula);
    Lista<Elemento>& lista = tabla[indice];

    for(unsigned int i = 0; i < lista.Tamano(); i++)
    {
        if(lista[i].Id == matricula)
        {
            std::string ElementoEliminado = ObtenerNombreElemento(matricula);
            lista.EliminarEnIndice(i);
            NumeroElementos--;
            gotoxy(1,2);
            std::cout << "El elemento [" << ElementoEliminado << "] ha sido eliminado correctamente." << std::endl;
            return;
        }
    }

    gotoxy(1,2);

    std::cout << "Error" << std::endl;

}

//*************** Vaciar ************
void TablaHashDC::Vaciar()
{
    if(EstaVacia())
    {
        gotoxy(1,14);
        std::cout << "La tabla no tiene elementos." << std::endl;
        return;
    }

    for(int i = 0; i < Capacidad; i++)
    {
        tabla[i].Vaciar();
    }
    NumeroElementos = 0;
    gotoxy(1,14);
    std::cout << "Tabla vaciada correctamente." << std::endl;
}

//************* Imprimir *****************
void TablaHashDC::Imprimir() const
{
    if(EstaVacia())
    {
        std::cout << "La tabla esta vacia." << std::endl;
        return;
    }
    for(int i = 0; i < Capacidad; i++)
    {
        std::cout<< "\t\t";
        Lista<Elemento>& lista = tabla[i];
        for(unsigned int j = 0; j < lista.Tamano(); j++)
        {
            Elemento& elemento = lista[j];
            std::cout << "[" << elemento.Nombre << "] --> ";
        }
        std::cout << "\b\b\b\b    ";
        std::cout << "\rIndice " << i << ": ";
        std::cout << std::endl;
    }
}

bool TablaHashDC::EstaVacia() const
{
    return NumeroElementos == 0;
}


//******************** FUNCION HASH ************************
int TablaHashDC::FuncionHash(int matricula) const
{
    return matricula % Capacidad;
}

bool TablaHashDC::Buscar(int matricula) const
{
    if(EstaVacia())
    {
        std::cout << "La tabla no tiene elementos." << std::endl;
        return false;
    }

    int indice = FuncionHash(matricula);
    Lista<Elemento>& lista = tabla[indice];

    for(unsigned int i = 0; i < lista.Tamano(); i++)
    {
        Elemento& elemento = lista[i];
        if(elemento.Id == matricula)
        {
            return true;
        }
    }

    return false;
}

void TablaHashDC::Redimensionar()
{
    Capacidad *= 2;
    Lista<Elemento>* nuevaTabla = new Lista<Elemento>[Capacidad];
    for(int i = 0; i <Capacidad / 2; i++)
    {
        Lista<Elemento>& lista = tabla[i];
        for(unsigned int j = 0; j < lista.Tamano(); j++)
        {
            Elemento& elemento = lista[j];
            int nuevoIndice = FuncionHash(elemento.Id);
            nuevaTabla[nuevoIndice].AgregarAlFinal(elemento);
        }
    }

    delete[] tabla;

    tabla = nuevaTabla;
}

std::string  TablaHashDC::ObtenerNombreElemento(int matricula) const
{
    if(EstaVacia())
    {
        std::cout << "La tabla no tiene elementos." << std::endl;
        return "";
    }
    int indice = FuncionHash(matricula);

    Lista<Elemento>& lista = tabla[indice];

    for(unsigned int i = 0; i < lista.Tamano(); i++)
    {
        Elemento& elemento = lista[i];
        if(elemento.Id == matricula)
        {
            return elemento.Nombre;
        }
    }

    gotoxy(1,2);
    std::cout << "Elemento no encontrado." << std::endl;
    return "";
}

int TablaHashDC::NumeroDeElementos() const
{
    return NumeroElementos;
}

int TablaHashDC::CapacidadTabla() const
{
    return Capacidad;
}

const Lista<Elemento>& TablaHashDC::ObtenerListaEnlazada(int indice) const
{
    return tabla[indice];
}
