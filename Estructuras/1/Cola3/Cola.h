#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include<cstdlib>
#include <iostream>

#define COLA_VACIA = -1

typedef struct Nodo
{
    int dato;
    Nodo *siguiente;
} Nodo;

typedef struct
{
    Nodo *primero;
    Nodo *ultimo;
}Cola;

void Init(Cola *q)
{
    q ->primero = NULL;
    q ->ultimo = NULL;
}

bool Encolar(Cola* q, int dato)
{
    //En este paso creamos un nuevo nodo
    Nodo * nuevoNodo = malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) return false;
    nuevoNodo ->dato = dato;
    nuevoNodo ->siguiente = NULL;


    if(q->ultimo != NULL){
        q->ultimo->siguiente = nuevoNodo;
    }
    q->ultimo= nuevoNodo;


    if(q->primero == NULL){
        q->primero= nuevoNodo;
    }
    return true;
}

bool ColaVacia(Cola *q);

int Desencolar(Cola *q)
{
    if (q->primero == NULL) return COLA_VACIA;

    Nodo *aux = q->primero;

    int resultado = aux->dato;

    q->primero = q->primero->siguiente;
    if(q->primero == NULL){
        q->ultimo = NULL;
    }
    delete aux;

    return resultado;
}


#endif // COLA_H_INCLUDED
