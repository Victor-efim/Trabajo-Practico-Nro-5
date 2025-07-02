#include <iostream>
using namespace std;

typedef struct tnodo {
    int dato;
    tnodo* sig;
    tnodo* ant;
} *pnodo;


void CrearNodo(pnodo &nuevo, int valor) 
{
    nuevo = new tnodo;
    if (nuevo != NULL) 
    {
        nuevo->dato = valor;
        nuevo->sig = NULL;
        nuevo->ant = NULL;
    }
}


void AgregarFinal(pnodo &inicio, pnodo nuevo) 
{
    if (inicio == NULL) 
    {
        inicio = nuevo;
    } else {
        pnodo i;
        for (i = inicio; i->sig != NULL; i = i->sig);
        i->sig = nuevo;
        nuevo->ant = i;
    }
}

void EliminarMultiplosDeTres(pnodo &inicio)
{
    pnodo actual = inicio;
    while (actual != NULL) 
    {
        if (actual->dato % 3 == 0) 
        {
            pnodo eliminar = actual;
            if (eliminar->ant != NULL)
                eliminar->ant->sig = eliminar->sig;
            else
                inicio = eliminar->sig;

            if (eliminar->sig != NULL)
                eliminar->sig->ant = eliminar->ant;

            actual = eliminar->sig;
            delete eliminar;
        } else {
            actual = actual->sig;
        }
    }
}

void MostrarLista(pnodo inicio) 
{
    for (pnodo i = inicio; i != NULL; i = i->sig) 
    {
        cout << i->dato << " ";
    }
    cout << endl;
}

