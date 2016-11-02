#include <stdio.h>
#include <stdlib.h>
#include "Archivo.h"


int main()
{
    char nombre[]="archivo.dat";
    int limite=2;
    printf("\n Ingresar la informacion de las personas: ");
    int validos=cargar_archivo(nombre, limite);
    printf("\n Lista de las personas ingresadas: ");
    mostrar_archivo(nombre);

    return 0;
}

