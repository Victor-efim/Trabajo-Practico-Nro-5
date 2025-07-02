#include <iostream>
using namespace std;

typedef struct tnodo *pnodo;

struct tnodo {
    int dato;
    pnodo sig;
    pnodo ant;
};

struct tlista {
    pnodo inicio;
    pnodo fin;
};

void iniciar_lista(tlista &lista) {
    lista.inicio = NULL;
    lista.fin = NULL;
}

pnodo eliminar_inicio(tlista &lista) {
    if (lista.inicio == NULL) return NULL;
    pnodo eliminado = lista.inicio;

    if (lista.inicio == lista.fin) {
        lista.inicio = NULL;
        lista.fin = NULL;
    } else {
        lista.inicio = eliminado->sig;
        lista.inicio->ant = NULL;
    }

    eliminado->sig = NULL;
    eliminado->ant = NULL;
    return eliminado;
}

pnodo eliminar_final(tlista &lista) {
    if (lista.fin == NULL) return NULL;
    pnodo eliminado = lista.fin;

    if (lista.inicio == lista.fin) {
        lista.inicio = NULL;
        lista.fin = NULL;
    } else {
        lista.fin = eliminado->ant;
        lista.fin->sig = NULL;
    }

    eliminado->sig = NULL;
    eliminado->ant = NULL;
    return eliminado;
}
