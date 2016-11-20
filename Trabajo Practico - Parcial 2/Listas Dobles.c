#include <stdio.h>
#include <stdlib.h>
#include "Listas Dobles.h"


nodo2 * inicLista()//Bien.
{
    return NULL;
}


nodo2 * crearNodoLista(persona nuevo)//Bien.
{
    nodo2* aux= malloc(sizeof(nodo2));
    aux->cliente=nuevo;
    aux->anterior=NULL;
    aux->siguiente=NULL;
    return aux;
}

nodo2 * agregarAlPrincipio(nodo2 * lista, nodo2 * nuevo)//Bien.
{
    if(lista==NULL)
     {
         lista=nuevo;
     }
     else{

         nuevo->siguiente=lista;
         lista->anterior=nuevo;
         lista=nuevo;
     }

    return lista;
}


nodo2 * buscarUltimo(nodo2 * lista)//Bien.
{
    nodo2* rta=NULL;
    if(lista!=NULL)
    {
        if(lista->siguiente==NULL)
        {
            rta=lista;
        }
        else
        {
            rta=buscarUltimo(lista->siguiente);
        }
    }
    return rta;
}

nodo2 * agregarAlFinal(nodo2 * lista, nodo2 * nuevo)//Bien.
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nodo2 * ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
    }
    return lista;
}
/*
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
*/
nodo2* agregarEnOrdenTipoCli (nodo2* lista, nodo2* nuevo)//Bien.//se ordena por tipo de cliente desde el inicio hasta el final.
{
    nodo2*aux=lista;
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else{

        while(aux->cliente.tipo_cliente<nuevo->cliente.tipo_cliente && aux!=NULL)
        {
            aux=aux->siguiente;
        }

        if(aux!=NULL)
        {
            nodo2* ante=aux->anterior;
            nuevo->siguiente=aux;
            nuevo->anterior=ante;

        }
        else{
            lista=agregarAlFinal(lista, nuevo);
        }
    }

    return lista;
}
nodo2* agregarEnOrdenPorCant (nodo2*lista, nodo2*nuevo)//Bien.//se ordena por cantidad de articulos del cliente desde el inicio hasta el final.
{
    nodo2*aux=lista;
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else{
        while(aux->cliente.cantArticulos<nuevo->cliente.cantArticulos && aux!=NULL)
        {
            aux=aux->siguiente;
        }
       if(aux!=NULL)
        {
            nodo2* ante=aux->anterior;
            nuevo->siguiente=aux;
            nuevo->anterior=ante;

        }
        else{
            lista=agregarAlFinal(lista, nuevo);
        }
    }

    return lista;
}

void mostrarNodo(nodo2 * aux)//Bien.//Muestra un solo nodo.
{
    mostrar_persona(aux->cliente);
}

void mostrarLista(nodo2 * lista)//Bien.//Muestra todos los nodos de la lista.
{
    printf("\n Contenido de la lista: ");
    nodo2 * seg = lista;
    while (seg != NULL)
    {
        printf("\n asdfsadfasdfasdfasdfasfasdfasdfasdf");
        mostrarNodo(seg);
        seg= seg->siguiente;
    }
    printf("\n");
}
/*
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
*/
nodo2 * borrarNodo(nodo2 * lista,char nombre[])//Bien.
{
    nodo2 * borrar=NULL;
    nodo2 * seg=NULL;

    if(lista!=NULL)
    {
        if(lista->cliente.nombreApellido==nombre)
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
            while(seg!=NULL && seg->cliente.nombreApellido!=nombre)
            {
                seg=seg->siguiente;
            }

            if( seg!= NULL)
            {
                nodo2 * aux=seg->anterior; //Se crea un auxiliar donde se almacenara la lista sin el nodo que se busca borrar.
                aux->siguiente = seg->siguiente;
                free(seg);
            }

        }
    }

    return lista;

}

nodo2*borrarPrimero(nodo2* lista)//Bien.
{

    while(lista!=NULL)
    {
        nodo2* borrar=lista;
        lista=lista->siguiente;
        free(borrar);
    }
    return lista;
}

Fila inicFila(Fila nuevo)//Bien.
{
    nuevo.inicio=inicLista();
    nuevo.final=inicLista();
    return nuevo;
}

Fila agregar(Fila fila, persona cliente)//Bien.
{
    nodo2*nuevo=crearNodoLista(cliente);
    fila.inicio=agregarAlFinal(fila.inicio, nuevo);
    fila.final=buscarUltimo(fila.inicio);
    nodo2*inicio=fila.inicio;
    return fila;
}

Fila quitar(Fila filas)//Bien.
{
    if(filas.inicio!=NULL)
    {
        filas.inicio=borrarPrimero(filas.inicio);
    }
    else{
        printf("\n !!!La Fila ya esta vacia.¡¡¡\n ");
    }

    return filas;
}

void mostrar(Fila fila)//Bien.
{
    mostrarLista(fila.inicio);
}


int filavacia(Fila fila)//Bien.
{

    int i=0;
    if( fila.inicio==NULL)
    {
        i=1;
    }
   return i;
}
