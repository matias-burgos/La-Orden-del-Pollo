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



/*
void abrirOcerrarCaja(Caja cajas[], int numeroCaja) //El error se va con un puntero, pero aparecen otros errores
{
    if(cajas[numeroCaja].filita.inicio!=NULL) //El NULL era de filita.inicio, con filita solo al parecer no se puede
    {
        printf("\n La caja no puede cerrarce, aun quedan clientes");
    }
    else{
        if(cajas[numeroCaja].abiertaOcerrada==0)
        {
            cajas[numeroCaja].abiertaOcerrada=1;
        }
        else{
            if(cajas[numeroCaja].abiertaOcerrada==1)
            {
                cajas[numeroCaja].abiertaOcerrada=0;
            }
        }
    }
}

Caja buscarCaja(Caja cajas[], int pago, int validos)
{
    int i=0;
    Caja aux;
    while(i<validos)
    {
        if(cajas[i].tipo_pago==pago)
        {
            if(cajas[i].abiertaOcerrada==1)
            {
                aux=cajas[i];
            }
        }
        i++;
    }
    return aux;
}
*/
void mostrarCaja(Caja cajas)//Bien.
{
    printf("\n Numero de caja: %d", cajas.numero_de_cajas);
    printf("\n Nombre del cajero: %s", cajas.nombreCajero);
    printf("\n Tipo de pago que se acepta en la caja: %d", cajas.tipo_pago);
    printf("\n Su algoritmo de planificación es: %s", cajas.algoritmoPlanificacion);
    if(cajas.abiertaOcerrada==0)
    {
        printf("\n La caja se encuentra cerrada");

    }else{
        printf("\n La caja se encuentra abierta");
        printf("\n Clientes de la fila: ");
        mostrar(cajas.filita);
    }
}

void mostrarTodo(Caja cajas[])//Bien
{
    int i=0;
    while(i<8)
    {
        printf("\n ----------O----------o----------O----------o----------O----------o----------O----------o");
        mostrarCaja(cajas[i]);
        i++;
    }
}
/*
Caja IngresarFilas(Caja cajas[], int validos)
{
    int i=0;
    while(i<validos)
    {
       Fila aux=inicFila(aux);
       cajas[i].filita=aux;
       i++;
    }
    //return cajas;//Codeblocks con cancer.
}
*/
Caja ingresarEnCajas(Caja cajas, persona individuo)//Bien.
{
    if(strstr(cajas.algoritmoPlanificacion,'FIFO')!=NULL)
    {
        cajas.filita=agregar(cajas.filita, individuo);
    }
    if(strstr(cajas.algoritmoPlanificacion, 'SRTF')!=NULL)
    {
        nodo2*aux=crearNodoLista(individuo);
        cajas.filita.inicio=agregarEnOrdenPorCant(cajas.filita.inicio, aux);
        nodo2* ultimo=buscarUltimo(cajas.filita.inicio);
        cajas.filita.final=ultimo;
    }
    if((strstr(cajas.algoritmoPlanificacion, 'prioridades')!=NULL)|| strstr(cajas.algoritmoPlanificacion, 'RR')!=NULL)
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
    int i=0;
    while(i<validos && cajas[i].tipo_pago!=individuo.tipo_pago)
    {
        i++;

    }
    if(cajas[i].abiertaOcerrada==1)
    {
        cajas[i]=ingresarEnCajas(cajas[i], individuo);
    }
    else{
        printf("\n La caja esta cerrada.");
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
Caja RR(Caja cajas)
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
    while(i<validos)
    {

        if(strstr(cajas[i].algoritmoPlanificacion, 'RR')!=NULL)
        {
            cajas[i]=RR(cajas[i]);
        }
        else{
            cajas[i]=AtenderAlgoritmos(cajas[i]);
        }

    }

}

