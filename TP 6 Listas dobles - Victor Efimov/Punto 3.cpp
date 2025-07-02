#include <iostream>
using namespace std;

// DefiniciÃ³n de nodo doble
typedef struct tnodo *pnodo;

struct tnodo {
    int dato;
    pnodo sig;
    pnodo ant;
};

// Funciones auxiliares
void iniciar_lista(pnodo &inicio) {
    inicio = NULL;
}

void crear_nodo(pnodo &nuevo, int valor) {
    nuevo = new tnodo;
    nuevo->dato = valor;
    nuevo->sig = NULL;
    nuevo->ant = NULL;
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

void mostrar_lista(pnodo inicio) {
    for (pnodo i = inicio; i != NULL; i = i->sig) {
        cout << i->dato << " ";
    }
    cout << endl;
}

// Punto 3: ConversiÃ³n decimal a binario
void decimal_a_binario(int numero, pnodo &inicio) {
    iniciar_lista(inicio);

    if (numero == 0) {
        pnodo nuevo;
        crear_nodo(nuevo, 0);
        agregar_inicio(inicio, nuevo);
        return;
    }

    while (numero > 0) {
        int resto = numero % 2;
        pnodo nuevo;
        crear_nodo(nuevo, resto);
        agregar_inicio(inicio, nuevo);
        numero /= 2;
    }
}


