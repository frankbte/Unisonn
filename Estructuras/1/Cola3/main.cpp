#include "Cola.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include<cstdlib>

#define COLA_VACIA

using namespace std;

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


int main()
{
    Cola q1;
    Init(&q1);


    Encolar (&q1, 5);
    Encolar (&q1, 6);
    Encolar (&q1, 7);


    return 0;
}

