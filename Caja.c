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
        printf("\n Clientes de la fila: ");
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



void TiempoDeEsperaRoundRobin (Fila * fila)
{
    nodo2 * aux = fila->inicio;
    int tiempo = 0;
    int quantum = 8;

    aux->cliente.tiempoDeEspera = 0;

    while (aux->siguiente != NULL)
    {

        if (aux->cliente.cantArticulos < 8 && aux->cliente.cantArticulos >= 0)
        {
            tiempo = aux->cliente.cantArticulos + tiempo;
        }
        else
        {
            tiempo = quantum + tiempo;
        }

        nodo2 * seg = aux->siguiente;
        seg->cliente.tiempoDeEspera = tiempo;
        aux = aux-> siguiente;
    }
}


void TiempoDeEjecucion (Fila * fila)
{
    nodo2 * aux = fila->inicio;
    while (aux != NULL)
    {
        if(aux->cliente.cantArticulos > 0)
        {
            aux->cliente.tiempoProcesado = aux->cliente.tiempoProcesado + aux->cliente.cantArticulos;
        }
        aux->cliente.cantArticulos = 0;
        aux = aux->siguiente;
    }
}

*/

float SumarTiempoDeEjecucion (Fila  filitaa)//
{
    float tiempo=0;
    nodo2* aux=filitaa.inicio;
    while(aux!=NULL)
    {
        tiempo=tiempo+aux->cliente.tiempoProcesado;
        aux=aux->siguiente;
    }
    return tiempo;
}

float SumarTiempoDeEspera(Fila fila)//
{
    float tiempo = 0;
    nodo2 * aux=fila.inicio;
    while(aux!=NULL)
    {
        tiempo=tiempo+aux->cliente.tiempoDeEspera;
        aux=aux->siguiente;
    }
    return tiempo;
}

float PromedioDeEspera (Fila filita)//
{
    float suma = SumarTiempoDeEspera(filita);
    int cant=0;
    float promedio=0;
    nodo2*auxiliar=filita.inicio;

    while(auxiliar!=NULL)
    {
        cant++;
        auxiliar=auxiliar->siguiente;
    }

    promedio=suma/cant;
    return promedio;
}


float PromedioDeEjecucion (Fila  fila)//
{
    float suma = SumarTiempoDeEjecucion (fila);
    int cant=0;
    float promedio = 0;
    nodo2 * auxiliar = fila.inicio;

    while(auxiliar != NULL)
    {
        cant++;
        auxiliar = auxiliar->siguiente;
    }

    promedio = suma / cant;
    return promedio;
}
/*
void PlanFIFO (Caja cajas[], int pos, nodo2 * nuevo)
{
    agregar(cajas[pos].filita,nuevo);
    nodo2 * ultimo = buscarUltimo(cajas[pos].filita.inicio);
    cajas[pos].filita.final = ultimo;
    tiempoDeEspera(cajas[pos].filita);
}

void PlanSRTF (Caja cajas[],int pos, nodo2 * nuevo)
{
    Fila aux = cajas[pos].filita;
    nodo2 * aux2 = aux.inicio;
    cajas[pos].filita.inicio = agregarEnOrdenPorCant(aux2,nuevo);
    nodo2 * ultimo = buscarUltimo(cajas[pos].filita.inicio);
    cajas[pos].filita.final = ultimo;
    tiempoDeEspera(&cajas[pos].filita);
}






void InsertarFIFO (Caja cajas[], int pos, nodo2 * nuevo, int tiempo)
{
    nodo2 * aux = cajas[pos].filita.inicio;
    nodo2 * ultimo = cajas[pos].filita.final;

    while (aux != NULL)
    {
        if (aux->cliente.cantArticulos < tiempo)
        {
            aux->cliente.tiempoProcesado = aux->cliente.cantArticulos;
            tiempo = tiempo - aux->cliente.cantArticulos;
            aux->cliente.cantArticulos = 0;
        }
        else
        {
            aux->cliente.cantArticulos = aux->cliente.cantArticulos - tiempo;
            aux->cliente.tiempoProcesado = tiempo;
            tiempo = 0;
        }
        aux = aux->siguiente;
    }
    PlanFIFO(cajas,pos,nuevo);
}

/*
void planificacionFIFO (Caja cajas[], int pos, nodo2 * nuevo) //puede ir puntero
{
    cajas[pos].filita=agregar(cajas[pos].filita, nuevo);
    nodo2 * ultimo = BuscarUltimo(cajas[pos].filita.inicio);
    cajas[pos].filita.final = ultimo;
    tiempoDeEspera(&cajas[pos].filita);
}
*/
/*
void planificacionSRTF (Caja cajas[],int pos, nodo2 * nuevo)
{
    Fila  aux = cajas[pos].filita;
    nodo2 * aux2 = aux.inicio;
    cajas[pos].filita.inicio = agregarEnOrdenPorCant(aux2,nuevo);
    nodo2 * ultimo = buscarUltimo(cajas[pos].filita.inicio);
    cajas[pos].filita.final = ultimo;
    tiempoDeEspera(&cajas[pos].filita);
}

void PlanPrioridades(Caja cajas[],int pos, nodo2 * nuevo)
{
    Fila  aux = cajas[pos].filita;
    nodo2*  aux2 = aux.inicio;
    cajas[pos].filita.inicio = agregarEnOrdenTipoCli(aux2,nuevo);
    Fila*  ultimo = buscarUltimo(cajas[pos].filita.inicio);
    cajas[pos].filita.final = ultimo;
    tiempoDeEspera(&cajas[pos].filita);

}

void PlanRR (Caja cajas[],int pos, nodo2 * nuevo)
{
    Fila aux = cajas[pos].filita;
    nodo2* aux2 = aux.inicio;
    aux=agregar(cajas[pos].filita, nuevo);
    Fila * ultimo = buscarUltimo(cajas[pos].filita.inicio);
    cajas[pos].filita.final = ultimo;

}

void tiempoDeEspera (Fila filita)
{
    nodo2* aux = filita.inicio;
    int tiempo=0;

    while (aux->siguiente != NULL)
    {
        tiempo = aux->cliente.cantArticulos + tiempo;
        nodo2 * seg = aux->siguiente;
        seg->cliente.tiempoDeEspera = tiempo ;
        aux = aux->siguiente;
    }
}
*/
void atender(Caja cajas[],int dato)
{
    float promedioEjecucion = PromedioDeEjecucion(cajas[dato].filita);
    float PromedioEspera = PromedioDeEspera(cajas[dato].filita);
    printf("\n\tPromedio Ejecucion: %.2f\n",promedioEjecucion);
    printf("\n\tPromedio Espera: %.2f\n",PromedioEspera);
}

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


void antenderClientes(Caja cajas[], int validos, int dato)
{
    int i=0;
    char RR[]={'RR'};
    atender(cajas, dato);
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
