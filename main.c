#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include "Archivo.h"
#include "Caja.h"
#include "Listas Dobles.h"
#include "Arbol.h"


void menu_de_archivos()
{
    char nombre[]="Personas.dat";
    int opciones=0;

    printf("\NBienvenido al menu de Archivos!");
    while(opciones != 3)
    {
        opciones=0;
        system("cls");
        printf("\nOpciones: \n1_Carga de archivos \n2_Muestreo de archivos \n\n3_Volver\n");
        printf("\n\nElija el numero correspondiente a la opcion que desea: ");
        fflush(stdin);
        scanf("%d", &opciones);
        switch(opciones)
        {
            case 1:
                cargarPersonas(nombre);
                break;                  //La sentencia break: Se utiliza para salir de un bucle (while, do-while o for), cuando se da alguna condición especial. Cuando se ejecuta esta sentencia, el control del programa pasa inmediatamente a la instrucción siguiente al bucle.
            case 2:
                mostrar_archivo(nombre);
                system("pause");
                printf("\n\n");
                break;

        }
    }
}


nodoArbol* menu_de_arbol(nodoArbol* arbol)
{
    char nombre[20];
    int opciones_arbol=0;
    int opciones_de_muestreo=0;
    char archi[]="Personas.dat";

    while(opciones_arbol != 4)
    {
        system("cls");
        printf("\n||1_Pasar personas del archivo al arbol||");
        printf("\n||2_Mostrar arbol||");
        printf("\n||3_Borrar una persona del arbol ||");
        printf("\n\n||4_Volver||");
        printf("\n \n Ingrese el numero de la opcion que desea llevar a cabo: ||");
        fflush(stdin);
        scanf("%d", &opciones_arbol);

        switch(opciones_arbol)
        {
        case 1:
                arbol=IngresarPersonas(arbol, archi);
                if(arbol==NULL)
                {
                    printf("\nOjo. No hay nada!");
                }
                else{
                    printf("\n Las personas se han pasado correctamente ");
                }

                system("\n pause");
                break;

        case 2:
            if(arbol==NULL)
            {
                printf("\n No hay datos en el arbol");
                system("\n pause");
            }
            else
            {

                opciones_de_muestreo=0;
                while(opciones_de_muestreo<=4)
                {
                    system("cls");

                    printf("\nTipos de muestreo de arboles");
                    printf("\n||1_Preorder||");
                    printf("\n||2_Inorder||");
                    printf("\n||3_Postorder||");
                    printf("\n\n||4_Volver||");
                    printf("\n Elija una opcion: ");
                    fflush(stdin);
                    scanf("%d", &opciones_de_muestreo);

                    switch(opciones_de_muestreo)
                    {
                    case 1:
                        if(arbol==NULL)
                        {
                            printf("\nTampoco hay datos aqui!");
                        }
                        inorder(arbol);
                        system("pause");
                        break;

                    case 2:
                        if(arbol==NULL)
                        {
                            printf("\nNo hay nada");
                        }
                        postorder(arbol);
                        system("pause");
                        break;

                    case 3:
                        if(arbol==NULL)
                        {
                            printf("\nNada...");
                        }
                        preorder(arbol);
                        system("pause");
                        break;

                    }
                }
                break;
            }
            break;

                    case 3:
                        printf("\nIngrese el nombre que quiere borrar: ");
                        fflush(stdin);
                        scanf("%s", &nombre);
                        arbol=borrarUnNodoArbol(arbol, nombre);
                        printf("\n ¿Desea mostrar el arbol para ver como quedo? s/n: ");
                        char letra;
                        fflush(stdin);
                        scanf("%s", &letra);
                        if(letra=='s')
                        {
                            if(arbol==NULL)
                            {
                                printf("\nNo hay datos en el arbol");
                                system("pause");
                            }
                            else
                            {

                                opciones_de_muestreo=0;
                                while(opciones_de_muestreo<=4)
                                {
                                    system("cls");
                                    printf("\nTipos de muestreo de arboles");
                                    printf("\n||1_Preorder||");
                                    printf("\n||2_Inorder||");
                                    printf("\n||3_Postorder||");
                                    printf("\n\n||5_Volver||");
                                    printf("\n Elija una opcion: ");
                                    fflush(stdin);
                                    scanf("%d", &opciones_de_muestreo);

                                    switch(opciones_de_muestreo)
                                    {
                                        case 1:
                                            if(arbol==NULL)
                                            {
                                                printf("\nTampoco hay datos aqui!");
                                            }
                                            else{
                                                preorder(arbol);
                                                system("\n pause");
                                            }

                                            break;

                                        case 2:
                                            if(arbol==NULL)
                                            {
                                                printf("\nNo hay nada");
                                            }
                                            else{
                                                inorder(arbol);
                                                system("\n pause");
                                            }

                                            break;

                                        case 3:
                                            if(arbol==NULL)
                                            {
                                                printf("\nNada...");
                                            }
                                            else{
                                                postorder(arbol);
                                                system("\n pause");
                                            }
                                            break;
                                        case 4:

                                        break;
                                    }
                                }
                                break;
                            }

                        }
            }

    }
    return arbol;
}

void menu_de_cajas(nodoArbol* arbol, Caja cajas[])
{
    int cual=0;
    persona cliente;
    int validos=35;
    int opciones = 0;
    while(opciones != 6)
    {

        system("cls");
        printf("\n||1_Antes de trabajar, desea abrir/cerrar cajas?||");
        printf("\n||2_Pasar de arbol a cajas||");
        printf("\n||3_Mostrar cajas||");
        printf("\n||4_Agregar un cliente a la caja||");
        printf("\n||5_Atender clientes. (elija una caja)");
        printf("\n\n||6_Volver||");
        printf("\nElija un numero correspondiente a la opcion que desea llevar a cabo: ");
        fflush(stdin);
        scanf("%d", &opciones);
        int cual=0;
        switch(opciones)
        {
        case 1:
            menu_abrir_cerrar_cajas(cajas);
            break;
        case 2:
            if(arbol!=NULL)
            {
               menu_arbol_a_cajas(cajas, arbol);
            }
            else{
                printf("\nEl arbol esta vacio, debe ingresarle valores\n\n");
                system("pause");
            }
            break;

        case 3:
            mostrarCaja(cajas);
            break;

        case 4:

            cliente=cargar();
            nodo2* nuevo=crearNodoLista(cliente);
            agregarClienteACaja(cajas,nuevo);

        case 5:

            printf("\nIngrese el numero de la caja que desea que atienda: ");
            fflush(stdin);
            scanf("%d", &cual);
            if(cajas[cual].filita.inicio==NULL)
            {
                printf("\nNo se pudo atender porque no hay nadie.\n");
                system("pause");
            }
            else
            {
                antenderClientes(cajas,8, cual);
            }
            break;
        }
    }
}


void menu_abrir_cerrar_cajas(Caja cajas[])
{
    int opciones=0;
    int respuesta;

    while(opciones!=5)
    {
        opciones=0;
        system("cls");
        printf("\n||1_Abrir una caja||");
        printf("\n||2_Abrir todas las cajas||");
        printf("\n||3_Cerrar una caja||");
        printf("\n||4_Cerrar todas las cajas||");
        printf("\n\n||5_Volver||");
        printf("\nElija un numero correspondiente a la opcion que desea llevar a cabo: ");
        fflush(stdin);
        scanf("%d", &opciones);

        switch(opciones)
        {
        case 1:

            printf("\n Ingrese el numero de la caja que desea abrir: ");
            fflush(stdin);
            scanf("%d", &opciones);

            if(opciones>8)
            {
                printf("\nEsa caja no existe");
            }
            else
            {
                abrirCaja(cajas, opciones);
                printf("\nLa caja %d ahora se encuentra abierta");
                //abrirOcerrarCaja(cajas,opciones);

            }
            printf("\n");
            system("pause");
            break;

        case 2:
            abrirTodasLasCajas(cajas);
            printf("\nTodas las cajas estan abiertas");
            //abrirOcerrarTodasLasCajas(cajas, 8);
            printf("\n");
            system("pause");
            break;

        case 3:
            printf("\n Ingrese el numero de la caja que desea cerrar: ");
            fflush(stdin);
            scanf("%d", &opciones);

            if(opciones>8)
            {
                printf("\nEsa caja no existe");
            }
            else
            {
                cerrarCaja(cajas, opciones);
                printf("\nLa caja %d ahora esta cerrada", opciones);
            }
            printf("\n");
            system("pause");
            break;

        case 4:
            cerrarTodasLasCajas(cajas);
            printf("\nTodas las cajas estan cerradas");
            //abrirOcerrarTodasLasCajas(cajas, 8);
            printf("\n");
            system("pause");
            break;

        }
    }
}

void menu_arbol_a_cajas (Caja cajas[],nodoArbol * arbol)
{
    int opciones=0;
    nodoArbol * aux = arbol;
    while (opciones != 4)
    {
        int validos=30;
        opciones=0;
        system("cls");
        printf("\n1_ Pasar a Cajas con PreOrder");
        printf("\n2_ Pasar a Cajas con InOrder");
        printf("\n3_ Pasar a Cajas con PostOrder");
        printf("\n4_ Volver");
        printf("\nElija un numero correspondiente a la opcion que desea llevar a cabo: ");
        fflush(stdin);
        scanf("%d", &opciones);
        printf("\n");

        switch (opciones)
        {
        case 1:
            PasajeArbolCaja(arbol, opciones, cajas);
            mostrarCaja(cajas);
            system("pause");
            break;
        case 2:

            PasajeArbolCaja(arbol, opciones, cajas);
            mostrarCaja(cajas);
            system("pause");
            break;
        case 3:

            PasajeArbolCaja(arbol, opciones, cajas);
            mostrarCaja(cajas);
            system("pause");
            break;
        }
    }
}

void Menu ()
{
    int opciones=0;
    nodoArbol * arbol = inicArbol();
    char nombre[]="Cajas.dat";
    Caja cajas[8];
    ingresarCaja(cajas, nombre);

    while (opciones != 4)
    {
        system("cls");
        printf("\nO-------------¡¡Bienvenido al Menu De Opciones del Supermercado!!-------------O");
        printf("\n||1_ Archivo||");
        printf("\n||2_ Administracion de Arbol||");
        printf("\n||3_ Administracion de Cajas||\n");
        printf("\n||4_ Salir.||");
        printf("\nElija un numero correspondiente a la opcion que desea llevar a cabo:  ");
        fflush(stdin);
        scanf("%d", &opciones);

        switch(opciones)
        {
        case 1:
            menu_de_archivos();
            break;

        case 2:
            arbol = menu_de_arbol(arbol);
            break;

        case 3:
            menu_de_cajas(arbol,cajas);
            break;
        }

    }

}

int main()
{
    Menu();
    return 0;
}
