#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

class Vector{
friend Vector operator*(double escalar, Vector v);
friend std::ostream & operator<<(std::ostream &out, Vector v);
friend std::istream & operator>>(std::istream &in, Vector &v);

public: // todos tienen acceso
    explicit Vector(int dim = 3);
    Vector& operator=(const Vector &v);
    ~Vector();
    int ObtenerDim() const;
    void Capturar();
    void Imprimir() const;

    Vector operator+(Vector v) const;
    Vector operator-(Vector v);
    Vector operator*(double esc) const;
    double operator*(Vector v);
    double ObtenerMag();


private: // amigos y yo
    int dim;
    void EstablecerDim(int dimension);
    //double componente[MAXDIM];
    double *componente;












};


#endif // VECTOR_H_INCLUDED
