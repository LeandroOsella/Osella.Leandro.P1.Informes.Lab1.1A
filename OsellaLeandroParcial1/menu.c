#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "menu.h"

int menu()
{
    int opcion;

    system("cls");
    printf("    ****  Menu de Opciones  ****    \n\n");

    printf("1- ALTA MASCOTA\n");
    printf("2- MODIFICAR MASCOTA\n");
    printf("3- BAJA MASCOTA\n");
    printf("4- LISTAR MASCOTAS\n");
    printf("5- LISTAR TIPOS\n");
    printf("6- LISTAR COLORES\n");
    printf("7- LISTAR SERVICIOS\n");
    printf("8- ALTA TRABAJO\n");
    printf("9- LISTAR TRABAJOS\n");
    printf("10- LISTAR MASCOTAS DE 1 COLOR\n");
    printf("11- PROMEDIO DE MASCOTAS VACUNADAS\n");
    printf("12- LA/LAS MASCOTAS DE MENOR EDAD\n");
    printf("13- LISTAR MASCOTAS POR TIPO\n");
    printf("14- CANTIDAD DE MASCOTAS DE 1 COLOR Y 1 TIPO\n");
    printf("15- COLOR CON MAS CANTIDAD DE MASCOTAS\n");
    printf("16- Salir\n\n");

    utn_getInt("Ingrese una opcion: ", "Ingrese una opcion valida!!", 1, 16, 100, &opcion);

    system("cls");

    return opcion;
}
