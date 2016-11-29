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
        mostrarNodo(seg);
        seg= seg->siguiente;
    }
    printf("\n");
}


nodo2 * buscarUltimo(nodo2 * lista)//Bien.
{
    nodo2*aux=lista;
    while(aux->siguiente!=NULL)
    {
        aux=aux->siguiente;
    }
    return aux;
}

nodo2 * agregarAlFinal(nodo2 * lista, nodo2 * nuevo)//Bien.
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {

        nodo2* ult=buscarUltimo(lista);
        ult->siguiente=nuevo;
        nuevo->anterior=ult;
    }

    return lista;
    /*nodo2* aux=lista;
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        aux= buscarUltimo(aux);
        aux->siguiente = nuevo;
        nuevo->anterior = aux;
        nuevo->siguiente=NULL;

    }
    return lista;*/
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
    /*nodo2*aux=lista;
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else{

        while(aux!=NULL && aux->cliente.tipo_cliente<nuevo->cliente.tipo_cliente)
        {
            aux=aux->siguiente;
        }

        if(aux!=NULL)
        {
            nodo2* ante=aux->anterior;
            nuevo->siguiente=aux;
            nuevo->anterior=ante;
            ante->siguiente=nuevo;
            aux->anterior=nuevo;
        }
        else{
            lista=agregarAlFinal(lista, nuevo);
        }
    }*/
    if(!lista)
    {
        lista=nuevo;
    }
    else
    {
        if(lista->cliente.tipo_cliente>nuevo->cliente.tipo_cliente){
            lista=agregarAlPrincipio(lista, nuevo);
        }
        else{
            nodo2* ante=lista;
            nodo2* seg=lista->siguiente;
            while((seg)&&(seg->cliente.tipo_cliente<=nuevo->cliente.tipo_cliente))
            {
                seg=seg->siguiente;
            }
            nuevo->siguiente=seg;
            ante->siguiente=nuevo;
            nuevo->anterior=ante;
            if(seg)
            {
                seg->anterior=nuevo;
            }
        }
    }
    /*mostrarLista(lista);
    system("pause");*/
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
            ante->siguiente=nuevo;
            aux->anterior=nuevo;

        }
        else{
            lista=agregarAlFinal(lista, nuevo);

        }
    }
    /*mostrarLista(lista);
    system("pause");*/
    return lista;
}




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

Fila agregar(Fila filita, nodo2*lista)//Bien.
{
    Fila fila=filita;
    fila.inicio=agregarAlFinal(fila.inicio, lista);
    fila.final=buscarUltimo(fila.inicio);
    return filita;
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
