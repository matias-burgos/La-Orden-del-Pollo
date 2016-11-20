#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"
#include "string.h"
#include "Archivo.h"

nodoArbol * inicArbol()//Bien.
{
    return NULL;
}


nodoArbol * crearNodoArbol(persona p)//Bien.
{
    nodoArbol * aux = (nodoArbol *) malloc(sizeof(nodoArbol));

    aux->p=p;
    aux->izq=NULL;
    aux->der=NULL;

    return aux;
}


nodoArbol * insertar (nodoArbol * arbol, persona p)//Bien.
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

nodoArbol* IngresarPersonas(nodoArbol*arbol, char nombre[])//Bien.
{
    FILE*archi=fopen(nombre, "r+b");
    persona p;
    while(fread(&p, sizeof(persona), 1, archi)!=NULL)
    {
        arbol=insertar(arbol, p);
    }
    fclose(archi);
    return arbol;
}
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


nodoArbol *nodoMasIzquierdo(nodoArbol *arbol)//Bien.
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

nodoArbol* borrarUnNodoArbol(nodoArbol* arbol, char nombre[])//Bien.
{
    printf("\n fadfa");
    if(arbol!=NULL)
    {
        if(strcmp(arbol->p.nombreApellido, nombre)<0){
                arbol->der= borrarUnNodoArbol(arbol->der , nombre);
        }
        else {
            if(strcmp( arbol->p.nombreApellido, nombre)>0){
                arbol->izq = borrarUnNodoArbol(arbol->izq, nombre);
            }else{

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
        }

    }
    return arbol;
}
/*
nodoArbol* preorderCliente(nodoArbol * arbol, Caja cajas[], int validos)
{
    persona aux;
    if(arbol!=NULL)
    {

        aux=arbol->p;
        arbol=borrarUnNodoArbol(arbol, aux.nombreApellido);
        agregarClienteACaja(cajas, aux);
        mostrarTodo(cajas);


        arbol->izq=preorderCliente(arbol->izq, cajas, validos);
        arbol->der=preorderCliente(arbol->der, cajas, validos);
    }
    return arbol;

}
nodoArbol* inorderCliente(nodoArbol * arbol, Caja cajas[], int validos)
{
    persona aux;
    if(arbol!=NULL)
    {
        arbol->izq=inorderCliente(arbol->izq, cajas, validos);

        aux=arbol->p;
        arbol=borrarUnNodoArbol(arbol, aux.nombreApellido);
        agregarClienteACaja(cajas, validos, aux);
        mostrarTodo(cajas);

        arbol->der=inorderCliente(arbol->der, cajas, validos);
    }
    return arbol;

}

nodoArbol* postorderCliente(nodoArbol * arbol, Caja cajas[], int validos)
{
    persona aux;
    if(arbol!=NULL)
    {
        arbol->izq=postorderCliente(arbol->izq, cajas, validos);
        arbol->der=postorderCliente(arbol->der, cajas, validos);

        aux=arbol->p;
        arbol=borrarUnNodoArbol(arbol, aux.nombreApellido);
        agregarClienteACaja(cajas, validos, aux);
        mostrarTodo(cajas);

    }
    return arbol;

}
*/
nodo2* pasarARbolALista(nodoArbol*arbol)
{
    nodo2*aux=malloc(sizeof(nodo2));
    aux->cliente=arbol->p;
    aux->anterior=NULL;
    aux->siguiente=NULL;
    return aux;
}

nodo2* pasarDeArbolToLineaDeCajas(nodoArbol* arbol, int metodo, Caja cajas[],nodo2* lista)//Bien.
{


    if(arbol!=NULL && metodo==1)
    {
        lista=agregarAlFinal(lista, pasarARbolALista(arbol));
        lista=pasarDeArbolToLineaDeCajas(arbol->izq, metodo, cajas, lista);
        lista=pasarDeArbolToLineaDeCajas(arbol->der, metodo, cajas, lista);





        //arbol=preorderCliente(arbol, cajas, validos);
    }
    if(arbol!=NULL && metodo==2)
    {
        lista=pasarDeArbolToLineaDeCajas(arbol->izq, metodo, cajas, lista);
        lista=agregarAlFinal(lista, pasarARbolALista(arbol));
        lista=pasarDeArbolToLineaDeCajas(arbol->der, metodo, cajas, lista);





        //arbol=inorderCliente(arbol, cajas, validos);
    }
    if(arbol!=NULL && metodo==3)
    {

        lista=pasarDeArbolToLineaDeCajas(arbol->izq, metodo, cajas, lista);
        lista=pasarDeArbolToLineaDeCajas(arbol->der, metodo, cajas, lista);
        nodo2*aux=pasarARbolALista(arbol);
        mostrarNodo(aux);
       // arbol=borrarUnNodoArbol(arbol, aux->cliente.nombreApellido);
        lista=agregarAlFinal(lista, aux);





        //arbol=postorderCliente(arbol, cajas, validos);
    }

    return lista;

}
nodo2* PasarUnNodo(nodo2*lista)
{
    nodo2*aux=malloc(sizeof(nodo2));
    aux->cliente=lista->cliente;
    aux->siguiente=NULL;
    aux->anterior=NULL;
    return aux;
}
void PasajeArbolCaja(nodoArbol*arbol, int metodo, Caja cajas[])
{
    nodo2*aux=inicArbol();
    nodo2*nuevo=inicArbol();
    aux=pasarDeArbolToLineaDeCajas(arbol, metodo, cajas, aux);
    while(aux!=NULL)
    {
        nuevo=PasarUnNodo(aux);
        agregarClienteACaja(cajas, nuevo);
        mostrarTodo(cajas);
        aux=aux->siguiente;

    }


}
