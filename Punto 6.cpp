#include<bits/stdc++.h>

using namespace std;

bool es_primo(int n) 
{
    if (n <= 1)
    { 
      return false;
    }
    for (int i = 2; i*i <= n; ++i)
        if (n % i == 0) 
        {
          return false;
        }
    return true;
}
int contar_primos(pnodo lista)
{
    int contador = 0;
    for (pnodo i = lista; i != NULL; i = i->siguiente) 
    {
        if (es_primo(i->dato)) contador++;
    }
    return contador;
}
int contar_mayusculas(pnodo lista) 
{
    int cont = 0;
    for (pnodo i = lista; i != NULL; i = i->siguiente)
        if (isupper(i->dato)) cont++;
    return cont;
}

int contar_minusculas(pnodo lista) 
{
    int cont = 0;
    for (pnodo i = lista; i != NULL; i = i->siguiente)
        if (islower(i->dato)) cont++;
    return cont;
}
