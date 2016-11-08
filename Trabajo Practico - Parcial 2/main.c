#include <stdio.h>
#include <stdlib.h>
#include "Archivo.h"


int main()
{
    char nombre[]="archivo.dat";
    int limite=30;
    printf("\n Ingresar la informacion de las personas: ");
    int validos=cargar_archivo(nombre, limite);// Creación y asignación de las personas al archivo.
    printf("\n Lista de las personas ingresadas: ");
    mostrar_archivo(nombre);
/*
    printf("Hello world!\n");
    nodoArbol * arbolito = inicArbol();
    persona p;
    persona p2;
    persona p3;
    persona p4;
    //p.nombreApellido[40]='Pepe';
    printf("Ingresar nombre: ");
    gets(p.nombreApellido);
     printf("Ingresar nombre: ");
    gets(p2.nombreApellido);
     printf("Ingresar nombre: ");
    gets(p3.nombreApellido);
      printf("Ingresar nombre: ");
    gets(p4.nombreApellido);

    arbolito=insertar(arbolito, p);
    arbolito=insertar(arbolito, p2);
    arbolito=insertar(arbolito, p3);
    arbolito=insertar(arbolito, p4);
    printf("\n Inorden: ");
    inorder(arbolito);
    printf("\n Preorder: ");
    preorder(arbolito);
    printf("\n Postorder: ");
    postorder(arbolito);
    */

    return 0;
}

//Pasaje de arbol a caja. Se le debe dar la opcion al usuario de recorrer el arbol con inorden, preorden, postorden
//y pasarlo a las cajas segun la cantidad de productos, teniendo caja rapida con 5< productos, y 2 con prioridades
