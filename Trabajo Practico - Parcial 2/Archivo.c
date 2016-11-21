#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Archivo.h"
/////////////MUESTRA UNA UNICA PERSONA///////////////////////////////////////
void mostrar_persona(persona p)//Bien.
{
    printf("\n ------------O-O-O-O------------");
    printf("\n --Nombre y Apellido: _ %s", p.nombreApellido);
    printf("\n --Cantidad de articulos que posee: _ %d", p.cantArticulos);
    printf("\n --Tipo de pago: _ %d", p.tipo_pago);
    printf("\n --Tipo de cliente: _ %d", p.tipo_cliente);
    printf("\n \n ");
}
/////////////MUESTRA UN ARCHIVO DE PERSONAS///////////////////////////////////////
void mostrar_archivo(char Personas[])//Bien.
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
persona cargar()
{
    int nota;
    persona p;
    printf("Ingrese Nombre y Apellido: ");
    fflush(stdin);
    scanf("%s",p.nombreApellido);
    printf("Ingrese la cantidad de articulos: ");
    fflush(stdin);
    scanf("%d",&p.cantArticulos);
    p.tiempoDeEspera = 0;
    p.tiempoProcesado = 0;
    printf("Ingrese tipo de cliente \n(1.Embarazada/2.Jubilado/3.Comun: ");
    fflush(stdin);
    scanf("%d",&p.tipo_cliente);
    printf("\n¿Desea saber los tipos de pago disponibles?: s/n");
    fflush(stdin);
    scanf("%d", &nota);
    if(nota=='s')
    {
        printf("\nEl codigo para cada tipo de pago disponible es el siguiente: ");
        printf("\n1_Efectivo.");
        printf("\n2_Credito o Debito.");
        printf("\n3_Todos.");
    }
    printf("Ingrese tipo de pago: ");
    fflush(stdin);
    scanf("%d",&p.tipo_pago);
    return p;
}

void cargarPersonas(char nombre[])
{
    FILE * archi;
    char rta='s';
    char nota='n';
    persona p;
    archi=fopen(nombre, "a+b");
    if (archi!=NULL)
    {
        while(rta=='s')
            {
                p=cargar();
                fwrite(&p,sizeof(persona),1,archi);
                printf("\n Desea cargas mas clientes? s/n: ");
                fflush(stdin);
                scanf("%c",&rta);
                printf("\n");
            }
        }
    fclose(archi);
}
