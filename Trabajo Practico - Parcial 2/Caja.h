#ifndef CAJA_H_INCLUDED
#define CAJA_H_INCLUDED
typedef struct
{
    int numero_de_cajas;
    char nombreCajero[40];
    int tipo_pago;//
    int abiertaOcerrada;
    char algoritmoPlanificacion[30];
    Fila filita;
}Caja;

Caja agregarCaja(Fila fila, Caja cajas[], int cantidad);
Caja abrirOcerrarCaja(Caja cajas[], int numeroCaja);
Caja buscarCaja(Caja cajas[], int pago, int validos);
void mostrarCaja(Caja cajas);
Caja ingresarEnFila(Caja cajas, persona individuo, Fila fila);
void agregarClienteACaja(Caja cajas[], int validos, nodo2*cliente);
agregarClienteACajaEnTiempoDeterminado
antenderClientes

#endif // CAJA_H_INCLUDED
