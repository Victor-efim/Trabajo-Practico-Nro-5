#include<bits/stdc++.h>

using namespace std;

struct Pila {
    pnodo tope;
};
struct Cola {
    pnodo inicio;
    pnodo final;
    int contador;
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
void iniciar_cola(Cola &c) 
{
    c.inicio = NULL;
    c.final = NULL;
    c.contador = 0;
}

void encolar(Cola &c, int valor) 
{
    pnodo nuevo;
    crear_nodo(nuevo, valor);
    if (c.inicio == NULL) 
    {
        c.inicio = nuevo;
        c.final = nuevo;
    } else 
    {
        c.final->siguiente = nuevo;
        c.final = nuevo;
    }
    c.contador++;
}

int desencolar(Cola &c) 
{
    if (c.inicio == NULL) return -1;
    pnodo aux = c.inicio;
    int dato = aux->dato;
    c.inicio = c.inicio->siguiente;
    if (c.inicio == NULL) c.final = NULL;
    delete aux;
    c.contador--;
    return dato;
}

int cantidad_elementos(Cola c) 
{
    return c.contador;
}
