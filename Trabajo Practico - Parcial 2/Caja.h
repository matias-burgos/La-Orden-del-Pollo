#ifndef CAJA_H_INCLUDED
#define CAJA_H_INCLUDED
#include "Listas Dobles.h"
#include "Archivo.h"

typedef struct Caja
{
    int numero_de_cajas;
    char nombreCajero[40];
    int tipo_pago;
    int abiertaOcerrada;
    char algoritmoPlanificacion[30];
    Fila filita;
}Caja;

Caja agregarCaja(Caja filas, Caja cajas);
void abrirOcerrarCaja(Caja cajas[], int numeroCaja);
Caja buscarCaja(Caja cajas[], int pago, int validos);
void mostrarCaja(Caja cajas);
Caja IngresarFilas(Caja cajas[], int validos);
Caja ingresarEnFila(Caja cajas, persona individuo, Fila fila);
Caja agregarClienteACaja(Caja cajas[], int validos, persona cliente);  //Originalmente era asi: void agregarClienteACaja(Caja cajas[], int validos, nodo2*cliente);
Caja agregarTiempo(Caja cajas, persona nuevo, int tiempo);
Caja agregarClienteACajaEnTiempoDeterminado(Caja cajas[], int validos, persona nuevo, int tiempo);
Caja antenderClientes(Caja cajas[], int validos)

#endif // CAJA_H_INCLUDED
