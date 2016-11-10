#include <stdio.h>
#include <stdlib.h>
#include "Caja.h"
#include "Listas Dobles.h"
#include "Archivo.h"
#include "string.h"

Caja agregarCaja(Caja cajas)
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
    if(strstr(cajas.algoritmoPlanificacion,'FIFO')!=NULL)
    {
        if(caja.filita==NULL)
        {
            cajas.filita.inicio=individuo;
        }
        else{
            cajas.filita.final.siguiente=individuo;
        }
    }
    if(strstr(cajas.algoritmoPlanificacion, 'SRTF')!=NULL)
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
    if(strstr(cajas.algoritmoPlanificacion, 'prioridades')!=NULL)
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
    if(strstr(cajas.algoritmoPlanificacion, 'RR')!=NULL)
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
    while(i<validos && cajas[i].tipo_pago!=individuo.tipo_pago)
    {
        i++;

    }
    if(cajas[i].abiertaOcerrada==1)
    {
        cajas[i]=ingresarEnCajas(cajas, individuo);
    }

    return cajas;
}
agregarTiempo(Caja cajas, persona nuevo, int tiempo)//Es cualquier cosa esto.
{
    Caja aux=cajas;
    int suma=0;
    while(tiempo<suma)
    {
        suma=suma+aux.filita.final.cliente.cantArticulos;
        aux.filita.final=aux.filita.final.anterior;
    }
    Caja auxi=aux;
    aux.filita.final.siguiente=nuevo;
    nuevo.filita.final.siguiente=auxi;
}

void agregarClienteACajaEnTiempoDeterminado(Caja cajas[], int validos, persona nuevo, int tiempo)
{
    int i=0;
    while(i<validos && cajas[i].tipo_pago!=nuevo.tipo_pago)
    {
        i++;
    }
    agregarTiempo(Caja cajas, persona nuevo, int tiempo);
}
