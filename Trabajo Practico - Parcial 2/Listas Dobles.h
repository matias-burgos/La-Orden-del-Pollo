#ifndef LISTAS_DOBLES_H_INCLUDED
#define LISTAS_DOBLES_H_INCLUDED
typedef struct{
 persona cliente;
 struct nodo * siguiente;
 struct nodo * anterior;
} nodo;

typedef struct{
 struct nodo * inicio;
 struct nodo * final;
} Fila;

nodo * inicLista();
nodo * crearNodoLista(int dato);
nodo * buscarUltimo(nodo * lista);
nodo * agregarAlFinal(nodo * lista, nodo * nuevoNodo);
nodo* insertarNodo(nodo * lista, nodo * nuevoNodo);;
agregarEnOrdenTipoCli (por tipo de cliente)
agregarEnOrdenPorCant (por cantidad de productos)
void recorrerYmostrar(nodo2 * lista);
nodo2 * borrarNodo(nodo * lista, int dato);
nodo2 * cargarLista(nodo * lista);
borrarPrimero (para vaciar la fila)


fila* inicFila(fila*nuevo);
Fila*agregar(Fila*fila, int dato);
Fila*quitar(Fila*fila);
mostrar
filaVacia




#endif // LISTAS_DOBLES_H_INCLUDED
