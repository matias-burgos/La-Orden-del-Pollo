
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
                arbol->p.nombreApellido=(nodoMasDerecho(arbol->izq))->p.nombreApellido;
                arbol->izq=borrarNodo(arbol->izq, arbol->p.nombreApellido);
            }
            else if(arbol->der!=NULL)
            {
                arbol->p.nombreApellido=(nodoMasIzquierdo(arbol->der))->p.nombreApellido;
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

