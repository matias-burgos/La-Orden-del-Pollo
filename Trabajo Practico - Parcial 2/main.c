#include <stdio.h>
#include <stdlib.h>
#include "Archivo.h"
#include "Arbol.h"
#include "Caja.h"

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
    /*printf("\n Ingresar nombre de la persona que desee borrar. ");
    char persona[30];
    fflush(stdin);
    scanf("%s", &persona);
    arbol=borrarUnNodoArbol(arbol, persona);
    mostrarArbol(arbol);*/

    char cajas[]="cajas.dat";
    Caja filas[8];
    ingresarCaja(filas, cajas);
    printf("\n Cajas");
    mostrarTodo(filas);
    system("pause");
    system("cls");
    int i=0;
    while(i<8)
    {
        abrirOcerrarCaja(filas, i);
        i++;
    }
    printf("\n Ingresar la forma en que se recorra para pasarlo: ");
    int metodo;

    fflush(stdin);
    scanf("%d", &metodo);
    pasarDeArbolToLineaDeCajas(arbol, metodo, limite, filas);
    printf("\n Las personas han sido pasadas a las respectivas cajas");
    system("pause");
    system("cls");
    printf("\n Cajas con los clientes: ");
    mostrarTodo(filas);
    antenderClientes(filas, 8);
    return 0;
}

//Pasaje de arbol a caja. Se le debe dar la opcion al usuario de recorrer el arbol con inorden, preorden, postorden
//y pasarlo a las cajas segun la cantidad de productos, teniendo caja rapida con 5< productos, y 2 con prioridades
