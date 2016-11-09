#include <stdio.h>
#include <stdlib.h>
#include "caja.h"
#include "Listas Dobles.h"
Caja agregarCaja(Caja cajas)//mal
{
    printf("\n Ingresar el numero de la caja: ");
    scanf("%d",&cajas.numero_de_cajas );
    printf("\n Ingrese el nombre del Cajero: ");
    gets(cajas.nombreCajero);
    printf("\n Ingresar el tipo de pago que acepta la caja: ");
    scanf("%d",&cajas.tipo_pago);
    printf("\n Ingrese el tipo de planificacion que se utilizara para esta caja: ");
    gets(cajas.algoritmoPlanificacion);
    cajas.filita=NULL;

    /*int i=0;
    FILE*archi=fopen(nombre, "r+b");
    if(archi!=NULL)
    {
        while(fread(cajas[i].filita, sizeof(Caja), 1, archi)>0)//mal
        {
            i++;
        }
    }
    fclose(archi);*/
    return cajas;
}

Caja abrirOcerrarCaja(Caja cajas[], int numeroCaja)
{
    if(cajas[numeroCaja].filita==NULL)
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
    return cajas;
}

Caja buscarCaja(Caja cajas[], int pago, int validos)
{
    int i=0;
    Caja aux=NULL;
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
void mostrarCaja(Caja cajas)
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
Caja IngresarFilas(Caja cajas[], int validos)
{
    int i=0;
    whille(i<validos)
    {
       Fila aux=malloc(sizeof(Fila));
       inicFila(aux);
       cajas[i].filita=aux;
       i++;
    }
    return cajas;

}

Caja ingresarEnFila(Caja cajas, persona individuo)//falta terminar el cliente que se ejecuta.
{
    if(cajas.algoritmoPlanificacion=='FIFO')//usar string
    {
        if(caja.filita==NULL)
        {
            cajas.filita.inicio=individuo;
        }
        else{
            cajas.filita.final.siguiente=individuo;
        }
    }
    if(cajas.algoritmoPlanificacion=='SRTF')//usar string
    {
        if(cajas.filita==NULL)
        {
            cajas.filita.inicio=individuo;
        }
        else{
            fila.inicio=agregarEnOrdenPorCant(fila.inicio, individuo);
            fila.final=buscarUltimo(fila.inicio);
        }
    }
    if(cajas.algoritmoPlanificacion=='prioridades')//usar string
    {
        if(cajas.filita==NULL)
        {
            cajas.filita.inicio=individuo;
        }
        else{
            fila.inicio=agregarEnOrdenTipoCli(fila.inicio, individuo);
            fila.final=buscarUltimo(fila.inicio);
        }
    }
    if(cajas.algoritmoPlanificacion=='RR')//usar string
    {
        if(cajas.filita==NULL)
        {
            cajas.filita.inicio=individuo;
        }
        else{
            fila.inicio=agregarEnOrdenTipoCli(fila.inicio, individuo);
            fila.final=buscarUltimo(fila.inicio);
        }
    }
}

Caja agregarClienteACaja(Caja cajas[], int validos, persona*individuo)
{

    int i=0;
    while(cajas.abiertaOcerrada==1)
    {
        int i=0;
        while(i<validos && cajas[i].tipo_pago!=individuo.tipo_pago)
        {
            i++;
        }
        cajas[i]=ingresarEnCajas(cajas, individuo);
    }
    return cajas;
}
