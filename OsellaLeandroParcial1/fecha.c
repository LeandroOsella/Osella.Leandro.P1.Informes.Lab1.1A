#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "fecha.h"
#include "validacion.h"

int ingresarFecha(int* dia, int* mes, int* anio)
{
    int todoOk = 0;

    utn_getInt("Ingrese dia: ", "Error, ingrese un dia valido. ",1,31,100,dia);
    utn_getInt("Ingrese mes: ", "Error, ingrese un mes valido. ",1,12,100,mes);
    utn_getInt("Ingrese anio: ", "Error, ingrese un anio valido. ",2000,2022,100,anio);

    switch(*mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if(*dia>=1 && *dia<=31)
        {
            printf("\nFecha correcta.\n");
            todoOk = 1;
        }
        else
        {
            printf("\nFecha Incorrecta.\n");
        }
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        if(*dia>=1 && *dia<=30)
        {
            printf("\nFecha correcta.\n");
            todoOk = 1;
        }
        else
        {
            printf("\nFecha Incorrecta.\n");
        }
        break;

    case 2:
        if(*dia>=1 && *dia<=28)
        {
            printf("\nFecha correcta.\n");
            todoOk = 1;
        }
        else
        {
            printf("\nFecha Incorrecta.\n");
        }
        break;
    }

    return todoOk;
}
