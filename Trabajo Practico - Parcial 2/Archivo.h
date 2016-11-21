#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
typedef struct
{
      char nombreApellido [40];
      int cantArticulos;            // es el tiempo de ejecuci�n
      int tiempoDeEspera;     // es el tiempo de respuesta
      int tiempoProcesado;    // es el tiempo que ya fue procesado en la l�nea de caja (tiempo de ejecucion)
      int tipo_cliente;              //  prioridad (1: embarazada, 2: jubilado y 3: com�n)
      int tipo_pago;                //  1 efectivo, 2 cr�dito o d�bito, 3 todos
}persona;

void mostrar_persona(persona p);
void mostrar_archivo(char nombre[]);
persona cargar();
void cargarPersonas(char nombre[]);



#endif // ARCHIVO_H_INCLUDED
