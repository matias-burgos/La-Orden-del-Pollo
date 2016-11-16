#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Archivo.h"
void mostrar_persona(persona p)
{
    printf("\m ------------O-O-O-O------------");
    printf("\n --Nombre y Apellido: _ %s", aux.nombreApellido);
    printf("\n --Cantidad de articulos que posee: _ %d", aux.cantArticulos);
    printf("\n --Tipo de pago: _ %d", aux.tipo_pago);
    printf("\n --Tipo de cliente: _ %d", aux.tipo_cliente);
}

void mostrar_archivo(char Personas[])
{
    persona aux;
    int i=0;
    FILE*archi=fopen(Personas, "r+b");
    if(archi!=NULL)
    {
        while(fread(&aux, sizeof(persona), 1, archi)!=0)
        {
            i++;
            printf("\n Persona %d", i);
            mostrar_persona(aux);
        }
    }
    fclose(archi);
}
