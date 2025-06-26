#include<bits/stdc++.h>

using namespace std;

struct Pila {
    pnodo tope;
};

void iniciar_pila(Pila &p) 
{
    p.tope = NULL;
}

void push(Pila &p, int valor) 
{
    pnodo nuevo;
    crear_nodo(nuevo, valor);
    nuevo->siguiente = p.tope;
    p.tope = nuevo;
}

int pop(Pila &p) 
{
    if (p.tope == NULL) return -1;
    pnodo aux = p.tope;
    int dato = aux->dato;
    p.tope = p.tope->siguiente;
    delete aux;
    return dato;
}

bool pila_vacia(Pila p) 
{
    return p.tope == NULL;
}

