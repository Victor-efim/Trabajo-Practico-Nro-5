#include <iostream>
using namespace std;

typedef struct tnodo *pnodo;

struct tnodo {
    int dato;
    pnodo sig;
    pnodo ant;
};


void iniciar_lista(pnodo &inicio) {
    inicio = NULL;
}

void crear_nodo(pnodo &nuevo, int valor) {
    nuevo = new tnodo;
    if (nuevo != NULL) {
        nuevo->dato = valor;
        nuevo->sig = NULL;
        nuevo->ant = NULL;
    }
}

void agregar_inicio(pnodo &inicio, pnodo nuevo) {
    if (inicio == NULL) {
        inicio = nuevo;
    } else {
        nuevo->sig = inicio;
        inicio->ant = nuevo;
        inicio = nuevo;
    }
}

void agregar_final(pnodo &inicio, pnodo nuevo) {
    if (inicio == NULL) {
        inicio = nuevo;
    } else {
        pnodo i;
        for (i = inicio; i->sig != NULL; i = i->sig);
        i->sig = nuevo;
        nuevo->ant = i;
    }
}

void agregar_ordenado(pnodo &inicio, pnodo nuevo) {
    if (inicio == NULL) {
        inicio = nuevo;
    } else if (nuevo->dato < inicio->dato) {
        nuevo->sig = inicio;
        inicio->ant = nuevo;
        inicio = nuevo;
    } else {
        pnodo i;
        for (i = inicio; i->sig != NULL && i->sig->dato < nuevo->dato; i = i->sig);
        nuevo->sig = i->sig;
        nuevo->ant = i;
        if (i->sig != NULL)
            i->sig->ant = nuevo;
        i->sig = nuevo;
    }
}

pnodo quitar_inicio(pnodo &inicio) {
    if (inicio == NULL) return NULL;
    pnodo extraido = inicio;
    inicio = inicio->sig;
    if (inicio != NULL)
        inicio->ant = NULL;
    extraido->sig = NULL;
    return extraido;
}

pnodo quitar_final(pnodo &inicio) {
    if (inicio == NULL) return NULL;
    pnodo i = inicio;
    while (i->sig != NULL)
        i = i->sig;

    if (i->ant != NULL)
        i->ant->sig = NULL;
    else
        inicio = NULL;

    i->ant = NULL;
    return i;
}
pnodo quitar_nodo(pnodo &inicio, int valor) {
    if (inicio == NULL) return NULL;
    pnodo i = inicio;

    if (i->dato == valor) {
        return quitar_inicio(inicio);
    }

    while (i != NULL && i->dato != valor)
        i = i->sig;

    if (i == NULL) return NULL;

    if (i->sig != NULL)
        i->sig->ant = i->ant;
    if (i->ant != NULL)
        i->ant->sig = i->sig;

    i->sig = NULL;
    i->ant = NULL;
    return i;
}

bool buscar(pnodo inicio, int valor) {
    for (pnodo i = inicio; i != NULL; i = i->sig)
        if (i->dato == valor)
            return true;
    return false;
}

void mostrar_lista(pnodo inicio) {
    for (pnodo i = inicio; i != NULL; i = i->sig)
        cout << i->dato << " ";
    cout << endl;
}
