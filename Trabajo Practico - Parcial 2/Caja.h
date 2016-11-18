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
Caja buscarCaja(Caja cajas[], int pago, int validos);
void mostrarCaja(Caja cajas);
void mostrarTodo(Caja cajas[]);
Caja IngresarFilas(Caja cajas[], int validos);//Posiblemente se borre. No tiene funcion.
Caja ingresarEnCaja(Caja cajas, persona individuo, Fila fila);
void agregarClienteACaja(Caja cajas[], int validos, persona cliente);  //Originalmente era asi: void agregarClienteACaja(Caja cajas[], int validos, nodo2*cliente);
Caja agregarTiempo(Caja cajas, persona nuevo, int tiempo);
Caja agregarClienteACajaEnTiempoDeterminado(Caja cajas[], int validos, persona nuevo, int tiempo);
Caja AtenderAlgoritmos(Caja cajas);
Caja RR(Caja cajas);
void antenderClientes(Caja cajas[], int validos);

#endif // CAJA_H_INCLUDED
