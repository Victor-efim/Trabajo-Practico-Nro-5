#include<bits/stdc++.h>

using namespace std;

int buscar_indice(tlista lista, int valor) 
{
    int indice = 0;
    for (pnodo i = lista.inicio; i != NULL; i = i->siguiente, indice++) 
    {
        if (i->dato == valor) return indice;
    }
    return -1;
}
pnodo buscar_por_indice(tlista lista, int h) 
{
    int indice = 0;
    for (pnodo i = lista.inicio; i != NULL; i = i->siguiente, indice++) 
    {
        if (indice == h) return i;
    }
    return NULL;
}
