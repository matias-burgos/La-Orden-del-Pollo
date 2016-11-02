#include <stdio.h>
#include <stdlib.h>
#include "Archivo.h"
#include "string.h"
persona cargar_persona()
{
    persona aux;
    printf("\n Ingresar nombre y apellido: ");
    gets(aux.nombreApellido);
    printf("\n Ingrese cantidad de articulos: ");
    fflush(stdin);
    scanf("%d", &aux.cantArticulos);
    printf("\n Ingrese el tipo de persona: \n1:Embarazada \n2:Jubilado \n3:Comun\n ");
    fflush(stdin);
    scanf("%d", &aux.tipo_cliente);
    printf("\n Ingresar su tipo de pago: \n1:Efectivo; \n2:Credito o Debito \n3:Todos\n ");
    fflush(stdin);
    scanf("%d", &aux.tipo_pago);
    aux.tiempoDeEspera=0;
    aux.tiempoProcesado=0;
    return aux;
}

int cargar_archivo(char nombre[], int limite)
{
    int i=0;
    persona personas;
    char letra='s';
    FILE*archi=fopen(nombre, "w+b");
    if(archi!=NULL)
    {
        while(i<limite)
        {
            personas=cargar_persona();
            fwrite(&personas, sizeof(persona), 1, archi);
            i++;
        }
    }
    fclose(archi);
    return i;
}

void mostrar_persona(persona aux)
{
    printf("\m ------------O-O-O-O------------");
    printf("\n --Nombre y Apellido: _ %s", aux.nombreApellido);
    printf("\n --Cantidad de articulos que posee: _ %d", aux.cantArticulos);
    printf("\n --Tipo de pago: _ %d", aux.tipo_pago);
    printf("\n --Tipo de cliente: _ %d", aux.tipo_cliente);
}

void mostrar_archivo(char nombre[])
{
    persona aux;
    int i=0;
    FILE*archi=fopen(nombre, "r+b");
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
