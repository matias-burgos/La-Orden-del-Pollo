#ifndef CAJA_H_INCLUDED
#define CAJA_H_INCLUDED
#include "Listas Dobles.h"
#include "Archivo.h"

typedef struct
{
    int numero_de_cajas;
    char nombreCajero[40];
    int tipo_pago;
    int abiertaOcerrada;
    char algoritmoPlanificacion[30];
    Fila filita;
}Caja;

Caja agregarCaja(Caja filas, Caja cajas);
void ingresarCaja(Caja cajas[], char nombre[]);
void abrirOcerrarCaja(Caja cajas[], int numeroCaja);
void abrirOcerrarTodasLasCajas(Caja cajas[], int validos);
int cantidadFila(Fila filita);
int buscarCaja(Caja cajas[], int pago, int validos);
void mostrarIndividual(Caja caja);
void mostrarCaja(Caja cajas[]);
void IngresarFilas(Caja cajas[], int validos);
Caja ingresarEnCajas(Caja cajas, nodo2*lista);
void agregarClienteACaja(Caja cajas[], nodo2*lista);
Caja agregarTiempo(Caja cajas, persona nuevo, int tiempo);
Caja agregarClienteACajaEnTiempoDeterminado(Caja cajas[], int validos, persona nuevo, int tiempo);
Caja AtenderAlgoritmos(Caja cajas);
Caja AlgoritmoRR(Caja cajas);
void antenderClientes(Caja cajas[], int validos);

#endif // CAJA_H_INCLUDED
