#include <stdio.h>
#include <stdlib.h>
#include "caja.h"

Caja agregarCaja(char nombre[], Caja cajas[], int cantidad)
{
    int i=0;
    FILE*archi=fopen(nombre, "r+b");
    if(archi!=NULL)
    {
        while(fread(cajas[i], sizeof(Caja), 1, archi)>0)
        {
            i++;
        }
    }
    return cajas;
}
