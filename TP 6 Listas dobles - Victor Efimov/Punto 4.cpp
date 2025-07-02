#include <iostream>
using namespace std;

typedef struct tnodo {
    int dato;
    tnodo* sig;
    tnodo* ant;
} *pnodo;


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


void MostrarMinMax(pnodo inicio) 
{
    if (inicio == NULL) 
    {
        cout << "La lista está vacía." << endl;
        return;
    }

    int min = inicio->dato;
    int max = inicio->dato;
    for (pnodo actual = inicio->sig; actual != NULL; actual = actual->sig) 
    {
        if (actual->dato < min) min = actual->dato;
        if (actual->dato > max) max = actual->dato;
    }

    cout << "Valor mínimo: " << min << endl;
    cout << "Valor máximo: " << max << endl;
}

int main() 
{
    pnodo lista = NULL;
    int datos[] = {18, 7, 21, 2, 35};
    for (int i = 0; i < 5; ++i) {
        pnodo nuevo;
        CrearNodo(nuevo, datos[i]);
        AgregarFinal(lista, nuevo);
    }

    MostrarMinMax(lista);

    return 0;
}
