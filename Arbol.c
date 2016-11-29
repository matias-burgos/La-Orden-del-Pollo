#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"
#include "string.h"
#include "Archivo.h"
/////////////INICIALIZA EL ARBOL///////////////////////////////////////
nodoArbol * inicArbol()
{
    return NULL;
}

/////////////CREA UN NODO DE UNA ARBOL///////////////////////////////////////
nodoArbol * crearNodoArbol(persona p)
{
    nodoArbol * aux = (nodoArbol *) malloc(sizeof(nodoArbol));

    aux->p=p;
    aux->izq=NULL;
    aux->der=NULL;

    return aux;
}

/////////////INGRESA LA PERSONA MEDIANTE UN NODO AL ARBOL///////////////////////////////////////
nodoArbol*insertar(nodoArbol*arbol, persona p)
{
    if(arbol==NULL)
    {
        arbol = crearNodoArbol(p);
    }
    else
    {
        if(strcmp(arbol->p.nombreApellido, p.nombreApellido)>0)
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

/////////////PASA UNA PERSONA DEL ARCHIVO LO PASA AL ARBOL///////////////////////////////////////
nodoArbol* IngresarPersonas(nodoArbol*arbol, char nombre[])
{
    FILE*archi=fopen(nombre, "rb");
    persona p;
    while(fread(&p, sizeof(persona), 1, archi)> 0)
    {
        arbol=insertar(arbol, p);
    }
    fclose(archi);
    return arbol;
}
/////////////RECORRE Y MUESTRA EL ARBOL POR PREORDER///////////////////////////////////////
void preorder(nodoArbol * arbol)//Bien.
{
    if(arbol!=NULL)
    {
        mostrar_persona(arbol->p);
        printf("\n \n ");
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}

/////////////RECORRE Y MUESTRA EL ARBOL POR INORDER///////////////////////////////////////
void inorder(nodoArbol * arbol)//Bien.
{
    if(arbol!=NULL)
    {
        inorder(arbol->izq);
        mostrar_persona(arbol->p);
        printf("\n \n ");
        inorder(arbol->der);
    }
}
/////////////RECORRE Y MUESTRA EL ARBOL POR POSTORDER///////////////////////////////////////
void postorder(nodoArbol * arbol)//Bien.
{

    if(arbol!=NULL)
    {
        postorder(arbol->izq);
        postorder(arbol->der);
        mostrar_persona(arbol->p);
        printf("\n \n ");
    }
}
/////////////MUESTRA EL ARBOL EN LAS TRES FORMAS///////////////////////////////////////
void mostrarArbol(nodoArbol*arbol)//Bien.
{
    printf("\n Preorder: ");
    preorder(arbol);
    printf("\n \n ");
    system(" pause");
    system("cls");
    printf("\n Inorder: ");
    inorder(arbol);
    printf("\n \n ");
    system(" pause");
    system("cls");
    printf("\n Postorder: ");
    postorder(arbol);
    printf("\n \n ");
    system(" pause");
    system("cls");
}

/////////////BUSCA UNA PERSONA EN EL ARBOL EN BASE AL NOMBRE///////////////////////////////////////
nodoArbol *buscarPorNombre(nodoArbol *arbol, persona p)//Bien.
{
    nodoArbol*rta=inicArbol();
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



nodoArbol *nodoMasDerecho(nodoArbol *arbol)//Bien.
{
    nodoArbol* aux;

    if(!arbol->der) aux = arbol;

    else aux = nodoMasDerecho(arbol->der);

    return aux;
    /*nodoArbol *aux;
    if(arbol->der==NULL)
    {
        aux=arbol;
    }
    else
    {
        aux=nodoMasDerecho(arbol->der);
    }*/
    return aux;
}


nodoArbol *nodoMasIzquierdo(nodoArbol *arbol)//Bien.
{
    nodoArbol* aux;

    if(!arbol->izq) aux = arbol;

    else aux = nodoMasIzquierdo(arbol->izq);

    return aux;
    /*nodoArbol *aux;
    if(arbol->izq==NULL)
    {
        aux=arbol;
    }
    else
    {
        aux=nodoMasIzquierdo(arbol->izq);
    }*/
    return aux;
}
/////////////BORRA UN NODO DE UN ARBOL CON RECURSION///////////////////////////////////////
nodoArbol* borrarUnNodoArbol(nodoArbol* arbol, char nombre[])//Bien.
{
    if(arbol)
    {
        if(strcmp(nombre, arbol->p.nombreApellido)>0)
        {
            arbol->der= borrarUnNodoArbol(arbol->der, nombre);
        }
        else if(strcmp(nombre, arbol->p.nombreApellido)<0)
        {
            arbol->izq = borrarUnNodoArbol(arbol->izq, nombre);
        }
        else
        {
            if(arbol->izq)
            {
                arbol->p= (nodoMasDerecho(arbol->izq))->p;
                arbol->izq= borrarUnNodoArbol(arbol->izq, arbol->p.nombreApellido);
            }
            else if(arbol->der)
            {
                arbol->p= (nodoMasIzquierdo(arbol->der))->p;
                arbol->der= borrarUnNodoArbol(arbol->der, arbol->p.nombreApellido);
            }
            else
            {
                free(arbol);
                arbol= NULL;
            }
        }
    }
   /* if(arbol!=NULL)
    {
        if(strcmp(arbol->p.nombreApellido, nombre)<0)
            {
                arbol->der= borrarUnNodoArbol(arbol->der , nombre);
            }
        else if(strcmp( arbol->p.nombreApellido, nombre)>0)
            {
                arbol->izq = borrarUnNodoArbol(arbol->izq, nombre);
            }
            else
                {
                    if(arbol->izq!=NULL)
                {
                    arbol->p= (nodoMasDerecho(arbol->izq))->p;
                    arbol->izq= borrarUnNodoArbol(arbol->izq, arbol->p.nombreApellido);
                }

                else if(arbol->der!=NULL)
                {
                    arbol->p= (nodoMasIzquierdo(arbol->der))->p;
                    arbol->der= borrarUnNodoArbol(arbol->der, arbol->p.nombreApellido);
                }

                else
                {
                    free(arbol);
                    arbol= NULL;
                }
            }
        }*/

    return arbol;

}

/////////////PASA UN NODO DE UN ARBOL A UN NODO LISTA///////////////////////////////////////
nodo2* pasarARbolALista(nodoArbol*arbol)
{
    nodo2* aux=(nodo2*)malloc(sizeof(nodo2));
    aux->cliente=arbol->p;
    aux->anterior=NULL;
    aux->siguiente=NULL;
    return aux;
}
/////////////PASA UN ARBOL A UN NODO LISTA EN BASE AL TIPO DE METODO SELECCIONADO///////////////////////////////////////
nodo2* pasarDeArbolToLineaDeCajas(nodoArbol* arbol, int metodo, Caja cajas[],nodo2* lista)//Bien.
{
    if(arbol!=NULL && metodo==1)
    {
       // nodo2*aux=pasarARbolALista(arbol);

        lista=agregarAlFinal(lista, pasarARbolALista(arbol));
        lista=pasarDeArbolToLineaDeCajas(arbol->izq, metodo, cajas, lista);
        lista=pasarDeArbolToLineaDeCajas(arbol->der, metodo, cajas, lista);
    }
    else
            if(arbol!=NULL && metodo==2)
        {

            lista=pasarDeArbolToLineaDeCajas(arbol->izq, metodo, cajas, lista);
        //  nodo2*aux=pasarARbolALista(arbol);
            lista=agregarAlFinal(lista, pasarARbolALista(arbol));
            lista=pasarDeArbolToLineaDeCajas(arbol->der, metodo, cajas, lista);

        }


    else   if(arbol!=NULL && metodo==3)
        {

            lista=pasarDeArbolToLineaDeCajas(arbol->izq, metodo, cajas, lista);
            lista=pasarDeArbolToLineaDeCajas(arbol->der, metodo, cajas, lista);
        // nodo2*aux=pasarARbolALista(arbol);
            lista=agregarAlFinal(lista, pasarARbolALista(arbol));

        }

    return lista;

}
/////////////PASA EL PRIMER NODO DE LA LISTA A UN UNICO NODO///////////////////////////////////////
nodo2* PasarUnNodo(nodo2*lista)
{
    nodo2*aux=malloc(sizeof(nodo2));
    aux->cliente=lista->cliente;
    aux->siguiente=NULL;
    aux->anterior=NULL;
    return aux;
}
/////////////PASA UN NODO DE PERSONA DE LA LISTA AL ARCHIVO///////////////////////////////////////
void PasajeArbolCaja(nodoArbol*arbol, int metodo, Caja cajas[])
{

    nodo2*aux=inicArbol();
    nodo2*nuevo=inicArbol();
    if(arbol!=NULL)
    {
        aux=pasarDeArbolToLineaDeCajas(arbol, metodo, cajas, aux);

        while(aux!=NULL)
        {
            nuevo=PasarUnNodo(aux);
            //Hasta aca todo bien
            agregarClienteACaja(cajas, nuevo);
            aux=aux->siguiente;

        }
    }
    else{
        printf("\n No se puede realizar la operacion, el arbol esta vacio");
    }


}
