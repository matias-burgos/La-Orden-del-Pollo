#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "Archivo.h"
#include "Caja.h"

typedef struct
{
    persona p;
    struct nodoArbol *izq;
    struct nodoArbol *der;
}nodoArbol;

nodoArbol * inicArbol();
nodoArbol * crearNodoArbol(persona p);
nodoArbol * insertar (nodoArbol * arbol, persona p);
nodoArbol* IngresarPersonas(nodoArbol*arbol, char nombre[]);
void inorder(nodoArbol * arbol);
void preorder(nodoArbol * arbol);
void postorder(nodoArbol * arbol);
void mostrarArbol(nodoArbol*arbol);
nodoArbol *buscarPorNombre(nodoArbol *arbol, persona p);
nodoArbol *nodoMasDerecho(nodoArbol *arbol);
nodoArbol *nodoMasIzquierdo(nodoArbol *arbol);
nodoArbol *borrarUnNodoArbol(nodoArbol *arbol, char nombre[]);
nodo2* preorderCliente(nodoArbol * arbol, Caja cajas[], int validos);
nodo2* inorderCliente(nodoArbol * arbol, Caja cajas[], int validos);
nodo2* postorderCliente(nodoArbol * arbol, Caja cajas[], int validos);
void pasarDeArbolToLineaDeCajas(nodoArbol* arbol, int metodo, int validos, Caja cajas[]);

#endif // ARBOL_H_INCLUDED
