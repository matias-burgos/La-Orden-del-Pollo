#include <stdio.h>
#include <stdlib.h>
#include "Caja.h"
#include "Listas Dobles.h"
#include "Archivo.h"
#include "string.h"

/////////////INGRESA UNA CAJA EN EL ARREGLO///////////////////////////////////////
Caja agregarCaja(Caja caja, Caja nuevo)
{
    caja=nuevo;
    caja.filita.inicio=NULL;
    caja.filita.final=NULL;
    return caja;
}

/////////////INGRESA TODAS LAS CAJAS AL ARREGLO LLAMANDO A LA FUNCION "agregarCaja"///////////////////////////////////////
void ingresarCaja(Caja cajas[], char nombre[])
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



/////////////ABRE O CIERRA UNA CAJA EN BASE AL ESTADO DE LA MISMA///////////////////////////////////////
void abrirOcerrarCaja(Caja cajas[], int numeroCaja)
{

    if(!filavacia(cajas[numeroCaja].filita))
    {
        printf("\n La caja no puede cerrarce, aun quedan clientes");
    }
    else{
        if(cajas[numeroCaja].abiertaOcerrada==0)
        {
            cajas[numeroCaja].abiertaOcerrada=1;
            printf("\n La caja numero %d se ha abierto", numeroCaja+1);
        }
        else{
            if(cajas[numeroCaja].abiertaOcerrada==1)
            {
                cajas[numeroCaja].abiertaOcerrada=0;
                printf("\n La caja numero %d se ha cerrado", numeroCaja+1);
            }
        }
    }
}
void abrirOcerrarTodasLasCajas(Caja cajas[], int validos)
{
    int i=0;
    while(i<validos)
    {
        abrirOcerrarCaja(cajas, i);
        i++;
    }
}

/////////////CUENTA LA CANTIDAD DE CLIENTES EN UNA FILA/////////////////////////////////////////////////
int cantidadFila(Fila filita)
{
    nodo2* aux=filita.inicio;
    int i=0;
    while(aux!=NULL)
    {
        aux=aux->siguiente;
        i++;
    }

    return i;
}
/////////////BUSCA LA CAJA QUE ACEPTE EL MISMO TIPO DE PAGO QUE EL CLIENTE QUE SE DEBE INGRESAR///////////////////////////////////////
int buscarCaja(Caja cajas[], int pago, int validos)
{
    int flag=-1;
    int posicion=-1;
    int cant;
    int i=0;
    while(i<8)
    {
        if(cajas[i].abiertaOcerrada==1)
        {
            if( (cajas[i].tipo_pago==3)||(cajas[i].tipo_pago==pago) )
            {
                flag++;
                if(flag>-1)
                {
                    if(cant>cantidadFila(cajas[i].filita))
                    {
                        posicion=i;
                        cant=cantidadFila(cajas[i].filita);
                    }
                }
                else
                {
                    posicion=i;
                    cant=cantidadFila(cajas[i].filita);
                }
            }
        }
        i++;
    }
    return posicion;
}
void mostrarIndividual(Caja caja)
{
    printf("\n Numero de caja: %d", caja.numero_de_cajas);
    printf("\n Nombre del cajero: %s", caja.nombreCajero);
    printf("\n Tipo de pago que se acepta en la caja: %d", caja.tipo_pago);
    printf("\n Su algoritmo de planificacion es: %s", caja.algoritmoPlanificacion);
    if(caja.abiertaOcerrada==0)
    {


        printf("\n La caja se encuentra cerrada ");
        system("\n pause");
        system("cls");

    }else{
        printf("\n La caja se encuentra abierta ");
        mostrarLista(caja.filita.inicio);
        printf("\n \n");
        system("\n pause");
        system("cls");
    }

}

/////////////MUESTRA UNA SOLA CAJA ENVIADA POR PARAMETROS////////////////////////////////////////
void mostrarCaja(Caja cajas[])
{

    int i=0;
    while(i<8)
    {
        printf("\n ----------O----------o----------O----------o----------O----------o");
        mostrarIndividual(cajas[i]);
        i++;
    }

}
/////////////MUESTREO DE TODAS LAS CAJAS LLAMANDO A LA FUNCIOND DE "mostrarCaja"////////////////////////////////////////

/////////////INGRESA UNA FILA EN LA CAJA BASIA///////////////////////////////////////
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
/////////////INGRESA EL NODO CON LA PERSONA EN EL ARREGLO DEPENDIENDO EL TIPO DE ALGORITMO QUE PRESENTA LA CAJA///////////////////////////////////////
Caja ingresarEnCajas(Caja cajas, nodo2*lista)
{
    if(strcmp(cajas.algoritmoPlanificacion, "FIFO")==0)
    {
        cajas.filita.inicio=agregarAlFinal(cajas.filita.inicio, lista);
        cajas.filita.final=buscarUltimo(cajas.filita.inicio);


    }

    if(strcmp(cajas.algoritmoPlanificacion, "SRTF")==0)
    {
        cajas.filita.inicio=agregarEnOrdenPorCant(cajas.filita.inicio, lista);

        nodo2* ultimo=buscarUltimo(cajas.filita.inicio);
        cajas.filita.final=ultimo;

    }

    if((strcmp(cajas.algoritmoPlanificacion, "Prioridades")==0)|| strcmp(cajas.algoritmoPlanificacion, "RR")==0)
    {
        cajas.filita.inicio=agregarEnOrdenTipoCli(cajas.filita.inicio, lista);
        nodo2* ultimo=buscarUltimo(cajas.filita.inicio);
        cajas.filita.final=ultimo;

    }

    return cajas;
}
/////////////BUSCA LA CAJA QUE ACEPTE EL MEDIO DE PAGO DE LA PERSONA Y LLAMA A LA FUNCION "ingresarEnCaja"///////////////////////////////////////
void agregarClienteACaja(Caja cajas[], nodo2*lista)
{

    int i=buscarCaja(cajas, lista->cliente.tipo_pago, 8);

    if(i<8)
    {
        cajas[i]=ingresarEnCajas(cajas[i], lista);
    }
    else{
        printf("\n No hay caja que acepte ese tipo de pago.");
    }

}
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////A PARTIR DE ACA NOSE QUE VA A PASAR////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





void abrirCaja (Caja cajas[], int numeroDeCaja)
{
    if(numeroDeCaja>8 || numeroDeCaja<0)
    {
        printf("\nEsa caja no existe.");
    }
    else
    {
        if(cajas[numeroDeCaja-1].abiertaOcerrada==1)
        {
            printf("\nLa caja ya estaba abierta.");
        }
        if(cajas[numeroDeCaja-1].abiertaOcerrada==0)
        {
            cajas[numeroDeCaja-1].abiertaOcerrada=1;
        }
    }
}

void abrirTodasLasCajas (Caja cajas[])
{
    int i = 0;

    while (i < 8)
    {
        if (cajas[i].abiertaOcerrada == 0)
        {
            cajas[i].abiertaOcerrada = 1;
        }
        i++;
    }
}


void cerrarCaja(Caja cajas[], int numeroDeCaja)
{
    if(numeroDeCaja>8 || numeroDeCaja<0)
    {
        printf("\nEsa caja no existe.");
    }
    else
    {
        if(cajas[numeroDeCaja-1].abiertaOcerrada==0)
        {
            printf("\nLa caja ya estaba cerrada.");
        }
        if(cajas[numeroDeCaja-1].abiertaOcerrada==1)
        {
            cajas[numeroDeCaja-1].abiertaOcerrada=0;
        }
    }
}


void cerrarTodasLasCajas(Caja cajas[])
{
    int i = 0;

    while (i < 8)
    {
        if (cajas[i].abiertaOcerrada == 1)
        {
            cajas[i].abiertaOcerrada = 0;
        }
        i++;
    }
}

void procesarCola(Caja caja)
{
    caja.filita=procesarFila(caja.filita);
}

void procesarTodasLasColas(Caja cajas[])
{
    int i=0;
    while(i<8)
    {
        procesarCola(cajas[i]);
        i++;
    }
}

float obtenerTiempoProcesamiento(Caja caja)
{
    float contArticulos = 0;
    int contPersonas = cantidadFila(caja.filita);;
    float promedio = 0;
    nodo2* lista = caja.filita.inicio;

    if (lista != NULL)
    {
        while (lista != NULL)
        {
            contArticulos = contArticulos + lista->cliente.cantArticulos;

            lista = lista->siguiente;
        }
        promedio = contArticulos / contPersonas;
    }

    return promedio;
}

float obtenerTiempoRespuesta(Caja caja)
{
    float tiempoDeEspera = 0;
    int contPersonas = cantidadFila(caja.filita);
    float promedio = 0;
    nodo2* lista = caja.filita.inicio;

    if (lista != NULL) {
        while (lista != NULL) {
            tiempoDeEspera = tiempoDeEspera + lista->cliente.tiempoDeEspera;

            lista = lista->siguiente;
        }
        promedio = tiempoDeEspera / contPersonas;
    }

    return promedio;
}

