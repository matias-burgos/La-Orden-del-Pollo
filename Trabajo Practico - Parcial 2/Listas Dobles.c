#include <stdio.h>
#include <stdlib.h>
#include "Listas Dobles.h"

nodo2 * inicLista()
{
    return NULL;
}


nodo2 * crearNodoLista(persona nuevo)
{
    nodo2* aux= (nodo2 *)malloc(sizeof(nodo2));
    aux->cliente=nuevo
    aux->ante=NULL;
    aux->ste=NULL;
    return aux;
}

nodo2 * agregarAlPrincipio(nodo2 * lista, nodo2 * nuevoNodo)
{
    nuevoNodo->ste=lista;
    if(lista!=NULL)
    {
        lista->ante=nuevoNodo;
    }
    return nuevoNodo;
}

// recursivo
nodo2 * buscarUltimo(nodo2 * lista)
{
    nodo2* rta=NULL;
    if(lista!=NULL)
    {
        if(lista->ste==NULL)
        {
            rta=lista;
        }
        else
        {
            rta=buscarUltimoR(lista->ste);
        }
    }
    return rta;
}

nodo2 * agregarAlFinal(nodo2 * lista, nodo2 * nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        nodo2 * ultimo = buscarUltimoR(lista);
        ultimo->ste = nuevoNodo;
        nuevoNodo->ante = ultimo;
    }
    return lista;
}

nodo2 * insertarNodo(nodo2 * lista, nodo2 * nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else if (nuevoNodo->dato< lista->dato)
    {
        lista=agregarAlPrincipio(lista, nuevoNodo);
    }
    else
    {

        nodo2 * anterior=lista;
        nodo2 * seg=lista->ste;

        while(seg!=NULL && seg->dato < nuevoNodo->dato)
        {
            anterior=seg;
            seg=seg->ste;
        }

        anterior->ste =nuevoNodo;

        nuevoNodo->ante = anterior;
        nuevoNodo->ste=seg;

        if(seg!=NULL)
        {
            seg->ante= nuevoNodo;
        }
    }
    return lista;
}
nodo2* agregarEnOrdenTipoCli (nodo2*lista, nodo2* nuevo)//se ordena por tipo de cliente desde el inicio hasta el final.
{
    nodo2*aux=lista;
    while(aux->cliente.tipo_cliente<nuevo.cliente.tipo_cliente && aux!=NULL)
    {
        aux=aux->cliente;
    }
    if(aux!=NULL)
    {
        nuevo->siguiente=aux;
        aux->anterior=nuevo;
    }
    else{
        aux->siguiente=nuevo;
        nuevo->anterior=nuevo;
    }
    return lista;
}
nodo2* agregarEnOrdenPorCant (nodo2*lista, nodo2*nuevo)
{
    nodo2*aux=lista;
    while(aux)
}

void mostrarNodo(nodo2 * aux)
{
    printf(" %d", aux->dato);
}

void mostrarLista(nodo2 * lista)
{
    printf("\nContenido de la lista: ");
    nodo2 * seg = lista;
    while (seg != NULL)
    {
        mostrarNodo(seg);
        seg= seg->ste;
    }
    printf("\n");
}

nodo2 * cargarLista(nodo2 * lista)
{
    char rta = 's';
    int dato;
    nodo2 * aux;
    while(rta == 's')
    {
        printf("\nIngrese un valor: ");
        scanf("%d", &dato);
        aux = crearNodo(dato);
        lista=agregarAlFinal(lista, aux);
        printf("\nContinuas?: ");
        fflush(stdin);
        scanf("%c", &rta);
    }
    return lista;
}
nodo2 * borrarNodo(nodo2 * lista,char nombre[])
{
    nodo2 * borrar=NULL;
    nodo2 * seg=NULL;

    if(lista!=NULL)
    {
        if(lista->nombre==nombre)
        {
            borrar=lista;

            lista=lista->siguiente;
            if(lista!=NULL)
            {
                lista->anterior=NULL;
            }
            free(borrar);
        }
        else
        {
            seg=lista->siguiente;
            while(seg!=NULL && seg->nombre!=nombre)
            {
                seg=seg->siguiente;
            }

            if( seg!= NULL)
            {
                nodo * aux=seg->anterior; //Se crea un auxiliar donde se almacenara la lista sin el nodo que se busca borrar.
                aux->siguiente = seg->siguiente;
                free(seg);
            }

        }
    }

    return lista;

}
Fila* inicFila(Fila*nuevo)
{
    nuevo->inicio=inicLista();
    nuevo->final=inicLista();
    return nuevo;
}

Fila*agregar(Fila*fila, int dato)
{
    nodo2*nuevo=crearNodoLista(dato);
    if(fila==NULL)
    {
        fila->inicio=nuevo;
    }
    else
    {
        fila->final=agregarAlFinal(fila->final, nuevo);
    }
    return fila;
}

persona*quitar(Fila*fila)
{
    int resp=0;
    if(fila->inicio!=NULL)
    {
        nodo2* aux=fila->inicio;
        nodo2* sig=aux->siguiente;
        if(fila->inicio!=fila->cola)
        {
            sig->anterior=NULL;
            fila->inicio=sig;
        }
        else{
            fila->final=NULL;
            fila->inicio=NULL;
        }
        resp=aux->persona;
        free(aux);
    }
    return resp;
}

void mostrar(Fila*fila)
{
    printf("\n Inicio: %d", fila->inicio);
    printf("\n Final: %d", fila->final);
}

int filavacia(Fila*fila)
{
    int i=0;
    if(fila->final==NULL && fila->inicio==NULL)
    {
        i=1;
    }
   return i;
}
