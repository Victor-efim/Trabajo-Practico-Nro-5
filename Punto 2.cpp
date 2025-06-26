#include<bits/stdc++.h>

using namespace std;

struct tlista 
{
    pnodo inicio;
    pnodo final;
    int contador;
};

void iniciar_lista(tlista &lista) 
{
    lista.inicio = NULL;
    lista.final = NULL;
    lista.contador = 0;
}

void agregar_final(tlista &lista, pnodo nuevo) 
{
    if (lista.inicio == NULL) 
    {
        lista.inicio = nuevo;
        lista.final = nuevo;
    } else 
    {
        lista.final->siguiente = nuevo;
        lista.final = nuevo;
    }
    lista.contador++;
}
