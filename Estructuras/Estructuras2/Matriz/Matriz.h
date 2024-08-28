#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

class matriz {
private:
    int filas, columnas;
    int **datos;

public:
    matriz(int filas = 1, int columnas = 1);
    ~matriz();
    matriz(const matriz &m);
    void Imprimir() const;
    matriz transpuesta() const;
    void Capturar();
    void Redimensionar(int nuevaFila, int nuevaCol);
    matriz operator+(matriz m);
    matriz operator-(matriz m);
    matriz operator*(double esc)const;
    matriz Multiplicar(const matriz &m) const;
    matriz& operator=(const matriz &m);
};
#endif // MATRIZ_H_INCLUDED
