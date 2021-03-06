#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "validacion.h"
#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "mascota.h"
#include "servicio.h"
#include "trabajo.h"
#include "menu.h"

#define TAMT 5
#define TAMC 5
#define TAMS 3
#define TAMM 10
#define TAMTRA 10



int main()
{
    eMascota mascotas[TAMM];
    eTrabajo trabajos[TAMTRA];
    eTipo tipos[TAMT] =
    {
        {1000, "Ave"},
        {1001, "Perro"},
        {1002, "Roedor"},
        {1003, "Gato"},
        {1004, "Pez"}
    };

    eColor colores[TAMC] =
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Rojo"},
        {5003, "Gris"},
        {5004, "Azul"}
    };

    eServicio servicios[TAMS] =
    {
        {20000, "Corte", 450},
        {20001, "Desparasitado", 800},
        {20002, "Castrado", 600}
    };

    char salir = 'n';
    int proximoIdMascota = 10000;
    int proximoTrabajo = 60000;
    int flagAlta = 0;
    int flagTrabajos = 0;
    int orden;

    inicializarMascotas(mascotas, TAMM);
    inicializarTrabajos(trabajos, TAMTRA);

    hardcodearMascotas(mascotas,TAMM,10,&proximoIdMascota, &flagAlta);
    hardcodearTrabajos(trabajos,TAMTRA,mascotas,TAMM,servicios,TAMS,10,&proximoTrabajo,&flagTrabajos);

    do
    {
        switch(menu())
        {
        case 1:
            if(altaMascota(mascotas, TAMM, &proximoIdMascota, tipos, TAMT, colores, TAMC)== 0)
            {
                printf("Error al dar el alta!!\n");
            }
            else
            {
                printf("Alta exitosa!!\n");
                flagAlta = 1;
            }
            break;

        case 2:
            if(flagAlta == 0)
            {
                printf("Para realizar una modificacion, primero de de Alta!!\n");
            }
            else
            {
                modificarMascota(mascotas,TAMM,colores,TAMC,tipos,TAMT);
            }
            break;

        case 3:
            if(flagAlta == 0)
            {
                printf("\nPara dar de baja a una mascota primero debe dar de ALTA!!\n");
            }
            else
            {
                bajaMascota(mascotas,TAMM,colores,TAMC,tipos,TAMT);
            }
            break;

        case 4:
            if(flagAlta == 0)
            {
                printf("Para listar primero debe dar de alta!!\n");
            }
            else
            {
                utn_getInt("Ingrese orden deseado (1-ASC / 2- DESC): ", "Error. Ingrese un orden valido.", 1,2,100,&orden);

                ordenarMascotas(mascotas,TAMM,orden);
                listarMascotas(mascotas,TAMM,colores,TAMC,tipos,TAMT);
            }
            break;
        case 5:
            listarTipos(tipos, TAMT);
            break;
        case 6:
            listarColores(colores, TAMC);
            break;
        case 7:
            listarServicios(servicios, TAMS);
            break;
        case 8:
            if(flagAlta==0)
            {
                printf("Para dar de Alta un trabajo primero debe dar de ALTA una mascota!!\n");
            }
            else
            {
                altaTrabajo(trabajos,TAMTRA,mascotas,TAMM,servicios,TAMS,colores,TAMC,tipos,TAMT,&proximoTrabajo);
                flagTrabajos = 1;
            }

            break;
        case 9:
            if(flagTrabajos == 0)
            {
                printf("Para listar trabajos primero hacer el ALTA TRABAJOS!!\n");
            }
            else
            {
                listarTrabajos(trabajos,TAMTRA, mascotas,TAMM,servicios,TAMS);
            }
            break;
        case 10:
            if(flagAlta==0)
            {
                printf("Para listar primero debe dar de alta!!\n");
            }
            else
            {
                listarMascotasColor(mascotas,TAMM,colores,TAMC,tipos,TAMT);
            }
            break;
        case 11:
            if(flagAlta==0)
            {
                printf("Para ver el promedio primero debe dar de alta!!\n");
            }
            else
            {
                promedioMascotasVacunadas(mascotas,TAMM,colores,TAMC,tipos,TAMT);
            }
            break;
        case 12:
            if(flagAlta==0)
            {
                printf("Para ver mascota de menor edad primero debe dar de alta!!\n");
            }
            else
            {
                informarMascotaMenorEdad(mascotas,TAMM,colores,TAMC,tipos,TAMT);
            }
            break;
        case 13:
            if(flagAlta==0)
            {
                printf("Para listar por tipo primero debe dar de alta!!\n");
            }
            else
            {
                listarMascotasPorTipo(mascotas,TAMM,colores,TAMC,tipos,TAMT);
            }
            break;
        case 14:
            if(flagAlta==0)
            {
                printf("Para listar por color y tipo primero debe dar de alta!!\n");
            }
            else
            {
                informarMascotasColorYTipo(mascotas,TAMM,colores,TAMC,tipos,TAMT);
            }
            break;
        case 15:
            if(flagAlta==0)
            {
                printf("Para informar color con mas cantidad de mascotas primero debe dar de alta!!\n");
            }
            else
            {
              informarColorMasMascotas(mascotas,TAMM,colores,TAMC,tipos,TAMT);
            }
            break;
        case 16:
            printf("Confirma salida?? (s/n): \n");
            fflush(stdin);
            scanf("%c", &salir);
            salir = tolower(salir);
            while(salir != 's' && salir != 'n')
            {
                printf("Error!! Ingrese opcion valida. Confirma salida?? (s/n): \n");
                fflush(stdin);
                scanf("%c", &salir);
                salir = tolower(salir);
            }
            break;
        }
        system("pause");
    }
    while(salir != 's');

    return 0;
}
