#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"
#include "Archivo.h"

nodoArbol * inicArbol()
{
    return NULL;
}


nodoArbol * crearNodoArbol(persona p)
{
    nodoArbol * aux = (nodoArbol *) malloc(sizeof(nodoArbol));

    aux->p=p;
    aux->izq=NULL;
    aux->der=NULL;

    return aux;
}


nodoArbol * insertar (nodoArbol * arbol, persona p)
{
    if(arbol==NULL)
    {
        arbol = crearNodoArbol(p);
    }
    else
    {
        if(p.nombreApellido>arbol->p.nombreApellido)
        {
            arbol->der=insertar(arbol->der, p);
        }
        else
        {
            arbol->izq=insertar(arbol->izq, p);
        }
    }
    return arbol;
}


void inorder(nodoArbol * arbol)
{
    if(arbol!=NULL)
    {
        inorder(arbol->izq);
        printf("%s ", arbol->p.nombreApellido);
        inorder(arbol->der);
    }
}

void preorder(nodoArbol * arbol)
{
    if(arbol!=NULL)
    {
        printf("%s ", arbol->p.nombreApellido);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}

void postorder(nodoArbol * arbol)
{
    if(arbol!=NULL)
    {
        postorder(arbol->izq);
        postorder(arbol->der);
        printf("%s ", arbol->p.nombreApellido);
    }
}
void mostrarArbol(nodoArbol*arbol)
{
    printf("\n Inorder: ");
    inorder(arbol);
    printf("\n Preorder: ");
    preorder(arbol);
    printf("\n Postorder: ");
    preorder(arbol);
}


nodoArbol *buscarPorNombre(nodoArbol *arbol, persona p)
{
    nodoArbol*rta=inicarbol();
    if(arbol)
    {
        if(p.nombreApellido==arbol->p.nombreApellido)
        {
            rta=arbol;
        }
        else
        {
            if(p.nombreApellido > arbol->p.nombreApellido)
            {
                rta=buscarPorNombre(arbol->der, p);
            }
            else
            {
                rta=buscarPorNombre(arbol->izq, p);
            }
        }
    }
    return rta;
}



nodoArbol *nodoMasDerecho(nodoArbol *arbol)
{
    nodoArbol *aux;
    if(arbol->der==NULL)
    {
        aux=arbol;
    }
    else
    {
        aux=nodoMasDerecho(arbol->der);
    }
    return aux;
}


nodoArbol *nodoMasIzquierdo(nodoArbol *arbol)
{
    nodoArbol *aux;
    if(arbol->izq==NULL)
    {
        aux=arbol;
    }
    else
    {
        aux=nodoMasIzquierdo(arbol->izq);
    }
    return aux;
}


nodoArbol *borrarNodo(nodoArbol *arbol, char nombre[])
{
    if(arbol!=NULL)
    {
        if(strcmp(nombre, arbol->p.nombreApellido)<0)// Revisar.
        {
            arbol->der=borrarNodo(arbol->der, nombre);
        }
        else if(strcmp(nombre<arbol->p.nombreApellido)<0)//Revisar.
        {
            arbol->izq=borrarNodo(arbol->izq, nombre);
        }
        else
        {
            if(arbol->izq!=NULL)
            {
                arbol->p=(nodoMasDerecho(arbol->izq))->p;
                arbol->izq=borrarNodo(arbol->izq, arbol->p.nombreApellido);
            }
            else if(arbol->der!=NULL)
            {
                arbol->p=(nodoMasIzquierdo(arbol->der))->p;
                arbol->der=borrarNodo(arbol->der, arbol->p.nombreApellido);
            }
            else
            {
                free(arbol);
                arbol=NULL;
            }
        }
    }
    return arbol;
}
nodo2* preorderCliente(nodoArbol * arbol, Caja cajas[], int validos)
{
    persona aux;
    if(arbol!=NULL)
    {
        aux=arbol.p;
        agregarClienteACaja(cajas, validos, aux);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
    return cajas;
}
nodo2* inorderCliente(nodoArbol * arbol, Caja cajas[], int validos)
{
    persona*aux=malloc(sizeof(persona));
    if(arbol!=NULL)
    {
        inorder(arbol->izq);
        aux=arbol;
        agregarClienteACaja(cajas, validos, aux);
        aux=aux->siguiente;
        inorder(arbol->der);
    }
    return cajas;
}
nodo2* postorderCliente(nodoArbol * arbol, Caja cajas[], int validos)
{
    persona*aux=malloc(sizeof(persona));
    if(arbol!=NULL)
    {
        postorder(arbol->izq);
        postorder(arbol->der);
        aux=arbol;
        agregarClienteACaja(cajas, validos, aux);
    }
    return cajas;
}



void pasarDeArbolToLineaDeCajas(nodoArbol* arbol, int metodo, int validos, Caja cajas[])
{
    while(arbol!=NULL && metodo==1)
    {
        cajas=preorderCliente(arbol, cajas, validos);
    }
    while(arbol!=NULL && metodo==2)
    {
        cajas=inorderCliente(arbol, cajas, validos);
    }
    while(arbol!=NULL && metodo==3)
    {
        cajas=postorderCliente(arbol, cajas, validos);
    }
}
