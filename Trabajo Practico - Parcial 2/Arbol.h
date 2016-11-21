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
nodoArbol* preorderCliente(nodoArbol * arbol, Caja cajas[], int validos);
nodoArbol* inorderCliente(nodoArbol * arbol, Caja cajas[], int validos);
nodoArbol* postorderCliente(nodoArbol * arbol, Caja cajas[], int validos);
nodo2* pasarDeArbolToLineaDeCajas(nodoArbol* arbol, int metodo, Caja cajas[],nodo2* aux);
nodo2* PasarUnNodo(nodo2*lista);
void PasajeArbolCaja(nodoArbol*arbol, int metodo, Caja cajas[]);

#endif // ARBOL_H_INCLUDED
