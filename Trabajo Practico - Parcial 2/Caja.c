#include <stdio.h>
#include <stdlib.h>
#include "Caja.h"
#include "Listas Dobles.h"
#include "Archivo.h"
#include "string.h"


Caja agregarCaja(Caja caja, Caja nuevo)//Ingresa una caja al arreglo//Bien
{
    caja=nuevo;
    caja.filita.inicio=NULL;
    caja.filita.final=NULL;
    return caja;
}


void ingresarCaja(Caja cajas[], char nombre[])//Ingresa todos las cajas al arreglo.//Bien.
{
    FILE* archi=fopen(nombre, "r+b");
    Caja nuevo;
    int i=0;
    if(archi!=NULL)
    {
        while(fread(&nuevo, sizeof(Caja),1, archi)!=0)
            {
                cajas[i]=agregarCaja(cajas[i], nuevo);
                i++;
            }
    }
    fclose(archi);
}




void abrirOcerrarCaja(Caja cajas[], int numeroCaja)//Bien.
{

    if(!filavacia(cajas[numeroCaja].filita))
    {
        printf("\n La caja no puede cerrarce, aun quedan clientes");
    }
    else{
        if(cajas[numeroCaja].abiertaOcerrada==0)
        {
            cajas[numeroCaja].abiertaOcerrada=1;
            printf("\n La caja se ha abierto");
        }
        else{
            if(cajas[numeroCaja].abiertaOcerrada==1)
            {
                cajas[numeroCaja].abiertaOcerrada=0;
                printf("\n La caja se ha cerrado");
            }
        }
    }
}

int buscarCaja(Caja cajas[], int pago, int validos)
{
    int i=0;
    int o=0;
    Caja aux;
    while(i<validos)
    {
        if(cajas[i].tipo_pago==pago)
        {
            if(cajas[i].abiertaOcerrada==1)
            {
                aux=cajas[i];
                o=i;
            }
            else{
                aux.abiertaOcerrada=0;

            }
        }
        i++;
    }
    return o;
}

void mostrarCaja(Caja caja)//Bien.
{
    printf("\n Numero de caja: %d", caja.numero_de_cajas);
    printf("\n Nombre del cajero: %s", caja.nombreCajero);
    printf("\n Tipo de pago que se acepta en la caja: %d", caja.tipo_pago);
    printf("\n Su algoritmo de planificacion es: %s", caja.algoritmoPlanificacion);
    if(caja.abiertaOcerrada==0)
    {


        printf("\n La caja se encuentra cerrada");

    }else{
        printf("\n La caja se encuentra abierta");
        printf("\n Clientes de la fila: ");
        mostrar(caja.filita);
        system("pause");
        system("cls");
    }
}

void mostrarTodo(Caja cajas[])//Bien
{
    int i=0;
    while(i<8)
    {
        printf("\n ----------O----------o----------O----------o----------O----------o");
        mostrarCaja(cajas[i]);
        i++;
    }
}

void IngresarFilas(Caja cajas[], int validos)
{
    int i=0;
    while(i<validos)
    {
       Fila aux=inicFila(aux);
       cajas[i].filita=aux;
       i++;
    }

}

Caja ingresarEnCajas(Caja cajas, persona individuo)//Bien.//Problema aca creo.
{
    if(strcmp(cajas.algoritmoPlanificacion, "FIFO")==0)
    {

        agregar(cajas.filita, individuo);




    }
    if(strcmp(cajas.algoritmoPlanificacion, "SRTF")==0)
    {

        nodo2*aux=crearNodoLista(individuo);
        cajas.filita.inicio=agregarEnOrdenPorCant(cajas.filita.inicio, aux);

        nodo2* ultimo=buscarUltimo(cajas.filita.inicio);
        cajas.filita.final=ultimo;

    }
    if((strcmp(cajas.algoritmoPlanificacion, "Prioridades")==0)|| strcmp(cajas.algoritmoPlanificacion, "RR")==0)
    {


        nodo2*nuevo=crearNodoLista(individuo);
        cajas.filita.inicio=agregarEnOrdenTipoCli(cajas.filita.inicio, nuevo);
        nodo2* ultimo=buscarUltimo(cajas.filita.inicio);
        cajas.filita.final=ultimo;
    }

    return cajas;
}

void agregarClienteACaja(Caja cajas[], int validos, persona individuo)//Bien.
{
    int i=buscarCaja(cajas, individuo.tipo_pago, validos);
    if(i<8)
    {
        if(cajas[i].abiertaOcerrada==1)
        {


            cajas[i]=ingresarEnCajas(cajas[i], individuo);

        }
        else{
            printf("\n Ninguna caja abierta acepta su tipo de pago.");
        }
    }
    else{
        printf("\n No hay caja que acepte ese tipo de pago.");
    }

}
/*
Caja agregarTiempo(Caja caja, persona nuevo, int tiempo)//Es cualquier cosa esto.
{
    Caja aux=caja;
    int suma=0;
    while(tiempo<suma)
    {
        Fila filita=aux.filita;
        nodo2*final=filita.final;
        persona p=final->cliente;
        suma=suma+p.cantArticulos;
        aux.filita.final=final->anterior;
    }
    Caja auxi=aux;
    aux.filita.final.siguiente=nuevo;
    nuevo.filita.final.siguiente=aux; // decia auxi
    return cajas;
}

Caja agregarClienteACajaEnTiempoDeterminado(Caja cajas[], int validos, persona nuevo, int tiempo)
{
    int i=0;
    while(i<validos && cajas[i].tipo_pago!=nuevo.tipo_pago)
    {
        i++;
    }
    cajas[i]=agregarTiempo(cajas[i], nuevo, tiempo);  //Original: cajas[i]=agregarTiempo(Caja cajas[i], persona nuevo, int tiempo);
    return cajas;
}
*/
Caja AtenderAlgoritmos(Caja cajas)
{
    while(cajas.filita.inicio!=NULL)
    {
        int i=0;
        int tiempoEspera=0;
        if(cajas.abiertaOcerrada==1)
        {
            while(cajas.filita.inicio!=NULL)
            {
                i=0;
                Fila filita=cajas.filita;
                nodo2*aux=filita.inicio;
                aux->cliente.tiempoDeEspera=tiempoEspera;
                while(i<aux->cliente.cantArticulos)
                {
                    aux->cliente.tiempoProcesado++;
                    tiempoEspera++;
                    i++;
                }
                if(cajas.filita.inicio==cajas.filita.final)
                {
                    free(cajas.filita.final);
                }
                cajas.filita=quitar(cajas.filita);
            }
        }
        else{
               printf("\n La caja se encuentra cerrada ");
        }
    }
    return cajas;
}
Caja AlgoritmoRR(Caja cajas)
{
    int q=8;
    while(cajas.filita.inicio!=NULL)
    {
        int i=0;
        int tiempoEspera=0;
        if(cajas.abiertaOcerrada==1)
        {
            while(cajas.filita.inicio!=NULL)
            {
                i=0;
                Fila filita=cajas.filita;//Por problemas del codeblocks decidimos "modularizar" la caja.
                nodo2*inicio=filita.inicio;
                inicio->cliente.tiempoDeEspera=tiempoEspera;
                while(i<inicio->cliente.cantArticulos)
                {
                    if(i==q)
                    {
                        inicio=agregarEnOrdenTipoCli(filita.inicio, filita.inicio);
                        nodo2* aux=cajas.filita.inicio;
                        inicio=inicio->anterior;
                        free(aux);
                    }
                    inicio->cliente.tiempoProcesado++;
                    tiempoEspera++;
                    i++;
                }
                if(cajas.filita.inicio==cajas.filita.final)
                {
                    free(cajas.filita.final);
                }
                cajas.filita=quitar(cajas.filita);
            }
        }
        else{
               printf("\n La caja se encuentra cerrada ");
        }
    }
    return cajas;
}


void antenderClientes(Caja cajas[], int validos)
{
    int i=0;
    char RR[]={'RR'};
    while(i<validos)
    {

        if(strstr(cajas[i].algoritmoPlanificacion, RR)!=NULL)
        {
            cajas[i]=AlgoritmoRR(cajas[i]);
        }
        else{
            cajas[i]=AtenderAlgoritmos(cajas[i]);
        }

    }

}

