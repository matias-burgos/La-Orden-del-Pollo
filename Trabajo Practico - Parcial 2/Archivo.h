#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
typedef struct
{
      char nombreApellido [40];
      int cantArticulos;            // es el tiempo de ejecución
      int tiempoDeEspera;     // es el tiempo de respuesta
      int tiempoProcesado;    // es el tiempo que ya fue procesado en la línea de caja (tiempo de ejecucion)
      int tipo_cliente;              //  prioridad (1: embarazada, 2: jubilado y 3: común)
      int tipo_pago;                //  1 efectivo, 2 crédito o débito, 3 todos
}persona;

persona cargar_persona();
int cargar_archivo(char nombre[], int limite);
void mostrar_persona(persona aux);
void mostrar_archivo(char nombre[]);



#endif // ARCHIVO_H_INCLUDED
