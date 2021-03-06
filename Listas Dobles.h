#ifndef LISTAS_DOBLES_H_INCLUDED
#define LISTAS_DOBLES_H_INCLUDED
#include "Archivo.h"

typedef struct{
    persona cliente;
    struct nodo * siguiente;
    struct nodo * anterior;
} nodo2;

typedef struct{
    struct nodo2 * inicio;
    struct nodo2 * final;
} Fila;

nodo2 * inicLista();
nodo2 * crearNodoLista(persona cliente);
nodo2 * agregarAlPrincipio(nodo2 * lista, nodo2 * nuevoNodo);
nodo2 * buscarUltimo(nodo2 * lista);
nodo2 * agregarAlFinal(nodo2 * lista, nodo2 * nuevoNodo);
nodo2* insertarNodo(nodo2 * lista, nodo2 * nuevoNodo);
nodo2* agregarEnOrdenTipoCli (nodo2*lista, nodo2* nuevo);
nodo2* agregarEnOrdenPorCant (nodo2*lista, nodo2*nuevo);
void mostrarLista(nodo2 * lista);
nodo2* cargarLista(nodo2* lista);
nodo2 * borrarNodo(nodo2 * lista,char nombre[]);
nodo2* borrarPrimero(nodo2* lista);


Fila inicFila(Fila nuevo);
Fila agregar(Fila fila, nodo2*lista);
Fila quitar(Fila fila);
void mostrar(Fila fila);
int filavacia(Fila fila);
Fila procesarFila(Fila fila);



#endif // LISTAS_DOBLES_H_INCLUDED
