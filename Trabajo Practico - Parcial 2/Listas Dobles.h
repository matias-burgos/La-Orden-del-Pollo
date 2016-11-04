#ifndef LISTAS_DOBLES_H_INCLUDED
#define LISTAS_DOBLES_H_INCLUDED
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
nodo2 * crearNodoLista(int dato);
nodo2 * buscarUltimo(nodo2 * lista);
nodo2 * agregarAlFinal(nodo2 * lista, nodo2 * nuevoNodo);
nodo2* insertarNodo(nodo2 * lista, nodo2 * nuevoNodo);//
agregarEnOrdenTipoCli (por tipo de cliente)//
agregarEnOrdenPorCant (por cantidad de productos)//
void recorrerYmostrar(nodo2 * lista);//
nodo2 * borrarNodo(nodo2 * lista, int dato);//
nodo2 * cargarLista(nodo2* lista);//
borrarPrimero (para vaciar la fila)//


fila* inicFila(fila*nuevo);
Fila*agregar(Fila*fila, int dato);
Fila*quitar(Fila*fila);
void mostrar(Fila*fila);
int filavacia(Fila*fila);




#endif // LISTAS_DOBLES_H_INCLUDED
