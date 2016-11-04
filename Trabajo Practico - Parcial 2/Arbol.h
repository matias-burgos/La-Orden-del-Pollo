#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
typedef struct
{
    persona p;
    struct nodoArbol *izq;
    struct nodoArbol *der;
}nodoArbol;
nodoArbol * inicArbol();
nodoArbol * crearNodoArbol(persona p);
nodoArbol * insertar (nodoArbol * arbol, persona p);
void inorder(nodoArbol * arbol);
void preorder(nodoArbol * arbol);
void postorder(nodoArbol * arbol);
nodoArbol *buscarPorNombre(nodoArbol *arbol, persona p);
nodoArbol *nodoMasDerecho(nodoArbol *arbol);
nodoArbol *nodoMasIzquierdo(nodoArbol *arbol);
nodoArbol *borrarNodo(nodoArbol *arbol, char nombre[]);


#endif // LISTAS_DOBLES_H_INCLUDED
