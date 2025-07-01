typedef struct tnodo *pnodo;

struct tnodo {
    int dato;
    pnodo siguiente;
};

struct tlista {
    pnodo inicio;
    pnodo final;
    int contador;
};
void iniciar_lista(tlista &lista) {
    lista.inicio = NULL;
    lista.final = NULL;
    lista.contador = 0;
}
void crear_nodo(pnodo &nuevo, int valor) {
    nuevo = new tnodo;
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
}
void agregar_final(tlista &lista, pnodo nuevo) {
    if (lista.inicio == NULL) {
        lista.inicio = nuevo;
        lista.final = nuevo;
    } else {
        lista.final->siguiente = nuevo;
        lista.final = nuevo;
    }
    lista.contador++;
}
void agregar_ordenado(tlista &lista, pnodo nuevo) {
    if (lista.inicio == NULL) {
        lista.inicio = nuevo;
        lista.final = nuevo;
    } else if (nuevo->dato < lista.inicio->dato) {
        nuevo->siguiente = lista.inicio;
        lista.inicio = nuevo;
    } else {
        pnodo i = lista.inicio;
        while (i->siguiente != NULL && i->siguiente->dato < nuevo->dato) {
            i = i->siguiente;
        }
        nuevo->siguiente = i->siguiente;
        i->siguiente = nuevo;
        if (nuevo->siguiente == NULL) lista.final = nuevo;
    }
    lista.contador++;
}
void ordenar_por_seleccion(tlista &lista) {
    for (pnodo i = lista.inicio; i != NULL; i = i->siguiente) {
        pnodo min = i;
        for (pnodo j = i->siguiente; j != NULL; j = j->siguiente) {
            if (j->dato < min->dato) {
                min = j;
            }
        }
        if (min != i) {
            int aux = i->dato;
            i->dato = min->dato;
            min->dato = aux;
        }
    }
}
void combinar_sin_orden(tlista &resultado, tlista l1, tlista l2) {
    for (pnodo i = l1.inicio; i != NULL; i = i->siguiente) {
        pnodo nuevo;
        crear_nodo(nuevo, i->dato);
        agregar_final(resultado, nuevo);
    }
    for (pnodo i = l2.inicio; i != NULL; i = i->siguiente) {
        pnodo nuevo;
        crear_nodo(nuevo, i->dato);
        agregar_final(resultado, nuevo);
    }
}
void combinar_con_orden(tlista &resultado, tlista l1, tlista l2) {
    for (pnodo i = l1.inicio; i != NULL; i = i->siguiente) {
        pnodo nuevo;
        crear_nodo(nuevo, i->dato);
        agregar_ordenado(resultado, nuevo);
    }
    for (pnodo i = l2.inicio; i != NULL; i = i->siguiente) {
        pnodo nuevo;
        crear_nodo(nuevo, i->dato);
        agregar_ordenado(resultado, nuevo);
    }
}
