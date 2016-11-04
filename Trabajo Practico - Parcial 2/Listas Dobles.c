#include <stdio.h>
#include <stdlib.h>
#include "Listas Dobles.h"

nodo * inicLista()
{
    return NULL;
}


nodo * crearNodoLista(int dato)
{
    nodo* aux= (nodo *)malloc(sizeof(nodo2));
    aux->dato=dato;
    aux->ante=NULL;
    aux->ste=NULL;
    return aux;
}

nodo * agregarAlPrincipio(nodo * lista, nodo * nuevoNodo)
{
    nuevoNodo->ste=lista;
    if(lista!=NULL)
    {
        lista->ante=nuevoNodo;
    }
    return nuevoNodo;
}

// recursivo
nodo * buscarUltimo(nodo * lista)
{
    nodo* rta=NULL;
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

nodo2 * insertarNodo(nodo * lista, nodo * nuevoNodo)
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

        nodo * anterior=lista;
        nodo * seg=lista->ste;

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



void mostrarNodo(nodo * aux)
{
    printf(" %d", aux->dato);
}

void recorrerYmostrar(nodo2 * lista)
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

nodo2 * cargarLista(nodo * lista)
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
nodo2 * borrarNodo(nodo * lista, int dato)
{
    nodo * aBorrar=NULL;
    nodo * seg=NULL;

    if(lista!=NULL)
    {
        if(lista->dato==dato)
        {
            aBorrar=lista;

            lista=lista->ste;
            if(lista!=NULL)
                lista->ante=NULL;

            free(aBorrar);
        }
        else
        {
            seg=lista->ste;
            while(seg!=NULL && seg->dato!=dato)
            {
                seg=seg->ste;
            }

            if( seg!= NULL)
            {
                nodo * anterior=seg->ante; /// bajo a una variable el anterior

                anterior->ste = seg->ste; ///salteo el nodo que quiero eliminar.

                if(seg->ste) /// si existe el nodo siguiente
                {
                    nodo * siguiente = seg->ste;
                    siguiente->ante=anterior;
                }
                free(seg); ///elimino el nodo.
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
    nodo*nuevo=malloc(sizeof(nodo*));
    nuevo=crearNodoLista(dato);
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

Fila*quitar(Fila*fila)
{
    int resp=0;
    if(fila->final!=NULL)
    {
        nodo* aux=fila->final;
        nodo* sig=aux->final;
        if(fila->final!=fila->cola)
        {
            sig->anterior=NULL;
            fila->final=sig;
        }
        else{
            fila->final=NULL;
            fila->inicio=NULL;
        }
        resp=aux->dato;
        free(aux);
    }
    return resp;
}
