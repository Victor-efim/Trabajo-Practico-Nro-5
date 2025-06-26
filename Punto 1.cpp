#include<bits/stdc++.h>

using namespace std;
struct typedef tnodo *pnodo;

struct tnodo {
    int dato;
    struct tnodo *sig;
};

void iniciar(pnodo &lista) {
    lista = NULL;
}
void crear_nodo(pnodo &muevo, pnodo &lista)
{
    nuevo = new tnodo;
    if(nuevo != NULL)
    {
        cout << "Ingrese el dato: ";
        cin >> nuevo->dato;
        nuevo->sig = NULL;
    }
    else
    {
        cout << "No se pudo crear el nodo" << endl;
        return;
    }
}
void agregar_inicio(pnodo &lista, pnodo nuevo) 
{
    nuevo->sig = lista;
    lista = nuevo;
}
void agregar_final(pnodo &lista, pnodo nuevo) 
{
    
    pnodo i;
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        for( i = lista; i->sig != NULL; i = i -> sig)
        {
            i -> sig = nuevo;
        }
    }
}
void eliminar_inicio(pnodo &lista) 
{
    pnodo borrado;
    if(lista == NULL)
    {
        borrado = NULL;
    }
    else
    {
        borrado = lista;
        lista = lista->sig;
        borrado -> sig = NULL;
    }
    return borrado;
}
void eliminar_final(pnodo &lista) 
{
    pnodo borrado, i;
    if(lista == NULL)
    {
        borrado = NULL;
    }
    else if(lista->sig == NULL)
    {
        borrado = lista;
        lista = NULL;
    }
    else
    {
        for(i = lista; i->sig->sig != NULL; i = i->sig);
        borrado = i->sig;
        i->sig = NULL;
    }
    return borrado;
}
void mostrar(pnodo lista) {
    pnodo i;
    if (lista != NULL) {
       for(i = lista; i!=NULL; i = i->sig) {
            cout <<"NODO: "<< i->dato << " ";
        }
    }
    else {
        cout << "La lista esta vacia" << endl;
    }
}
void buscar_nodo(pnodo lista, int valor) {
    pnodo i;
    bool encontrado = false;
   if(lista != NULL)
   {
    for( i = lista; i != NULL && encontrado == false; i = i->sig) {
        if(i->dato == valor) {
            encontrado = true;
        }
    }
   }
    return encontrado;
}
int minimo(pnodo lista) 
{
    if (lista == NULL) return -999;
    int min = lista->dato;
    for (pnodo i = lista; i != NULL; i = i->siguiente)
        if (i->dato < min)
            min = i->dato;
    return min;
}
