#include <stdio.h>
#include <stdlib.h>
#include "Archivo.h"
#include "Arbol.h"

int main()
{
    int limite=30;
    printf("\n Lista de las personas ingresadas: ");
    char nombre[]="Personas.dat";
    mostrar_archivo(nombre);
    printf("\n \n ");
    system(" pause");
    system("cls");

    printf("\n ----------O----------O----------O----------O----------O----------O----------O");
    printf("\n Arbol con las personas: ");
    nodoArbol* arbol = inicArbol();
    arbol=IngresarPersonas(arbol, nombre);
    mostrarArbol(arbol);
    printf("\n Ingresar nombre de la persona que desee borrar. ");
    char persona[30];
    fflush(stdin);
    scanf("%s", &persona);
<<<<<<< HEAD
    arbol=borrarNodo(arbol, persona);
=======
    borrarNodo(arbol, persona);
>>>>>>> origin/master
    mostrarArbol(arbol);

    return 0;
}

//Pasaje de arbol a caja. Se le debe dar la opcion al usuario de recorrer el arbol con inorden, preorden, postorden
//y pasarlo a las cajas segun la cantidad de productos, teniendo caja rapida con 5< productos, y 2 con prioridades
