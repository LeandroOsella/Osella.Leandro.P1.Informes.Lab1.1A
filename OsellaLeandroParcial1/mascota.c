#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "mascota.h"
#include "validacion.h"
#include "tipo.h"
#include "color.h"

int inicializarMascotas(eMascota mascotas[], int tamm)
{
    int todoOk = 0;

    if(mascotas!=NULL && tamm>0)
    {
        for(int i=0; i<tamm; i++)
        {
            mascotas[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibre(eMascota mascotas[], int tamm, int* pIndex)
{
    int todoOk = 0;

    if(mascotas!=NULL && tamm>0 && pIndex!=NULL)
    {
        *pIndex = -1;
        for(int i=0; i<tamm; i++)
        {
            if(mascotas[i].isEmpty == 1)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}



int altaMascota(eMascota mascotas[], int tamm, int* pProximoIdMascota, eTipo tipos[], int tamt, eColor colores[], int tamc)
{
    int todoOk = 0;
    int indice;
    eMascota auxMascota;

    if(mascotas!=NULL && tamm>0 && pProximoIdMascota!=NULL && tipos!=NULL && tamt>0 && colores!=NULL && tamc>0)
    {
        if(buscarLibre(mascotas, tamm, &indice))
        {
            if(indice == -1)
            {
                printf("No hay lugar en el sistema!!\n\n");
            }
            else
            {
                utn_getString("Ingrese nombre: ", "Error!! Ingrese nombre valido. ", 20, 100, auxMascota.nombre);

                listarTipos(tipos, tamt);
                utn_getInt("Ingrese Id tipo: ", "Error. Ingrese id valido. ", 1000, 1004, 100, &auxMascota.idTipo);

                listarColores(colores, tamc);
                utn_getInt("Ingrese Id Color: ", "Error. Ingrese Id valido. ", 5000, 5004, 100, &auxMascota.idColor);

                utn_getInt("Ingrese edad: ", "Error. Ingrese edad valida.", 1, 80, 100, &auxMascota.edad);

                printf("Ingrese estado de vacunacion (s/n): ");
                fflush(stdin);
                scanf("%c", &auxMascota.vacunado);
                auxMascota.vacunado = tolower(auxMascota.vacunado);
                while(auxMascota.vacunado != 's' && auxMascota.vacunado!= 'n')
                {
                    printf("Error. Reingrese estado de vacunacion (s/n): ");
                    fflush(stdin);
                    scanf("%c", &auxMascota.vacunado);
                    auxMascota.vacunado = tolower(auxMascota.vacunado);
                }

                auxMascota.isEmpty = 0;

                auxMascota.id = *pProximoIdMascota;
                (*pProximoIdMascota)++;

                mascotas[indice] = auxMascota;

                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros!!\n\n");
        }
    }
    return todoOk;
}

int menuModificarMascota()
{
    int opcion;

    printf("      ******Campos a Modificar******      \n");
    printf("-------------------------------------\n\n");
    printf("1- Tipo\n");
    printf("2- Vacunado\n");
    printf("3- Salir\n");
    utn_getInt("Ingrese opcion: ", "Error. Ingrese opcion valida. ",1,3,100,&opcion);

    return opcion;
}

int mostrarMascota(eMascota mascota, int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt)
{
    int todoOk = 0;
    char descripcionColor[20];
    char descripcionTipo[20];

    if(tamm>0 && colores!=NULL && tamc>0 && tipos!=NULL && tamt>0)
    {
        cargarDescripcionColor(colores, tamc,mascota.idColor,descripcionColor);
        cargarDescripcionTipo(tipos, tamt, mascota.idTipo, descripcionTipo);

        printf("%d   %-16s   %-10s   %-10s   %d         %c\n", mascota.id, mascota.nombre, descripcionTipo, descripcionColor, mascota.edad, mascota.vacunado);

        todoOk = 1;
    }
    return todoOk;
}

int listarMascotas(eMascota mascotas[], int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt)
{
    int todoOk = 0;
    int flag = 0;
    if(mascotas != NULL && tamm>0 && colores!=NULL && tamc>0 && tipos!=NULL && tamt>0)
    {
        printf("      ******Listado de Mascotas******      \n\n");
        printf("Id       Nombre             Tipo        Color        Edad      Vacunado\n");
        for(int i=0; i<tamm; i++)
        {
            if(mascotas[i].isEmpty == 0)
            {
                mostrarMascota(mascotas[i], tamm, colores, tamc, tipos, tamt);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("No hay mascotas en el sistema!!\n");
        }
    }
    return todoOk;
}

int buscarMascota(eMascota mascotas[], int tamm, int id, int* pIndex)
{
    int todoOk = 0;

    if(mascotas!=NULL && tamm>0 && pIndex!=NULL && id > 0)
    {
        *pIndex = -1;
        for(int i=0; i<tamm; i++)
        {
            if(mascotas[i].isEmpty == 0 && mascotas[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int modificarMascota(eMascota mascotas[], int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt)
{
    int todoOk = 0;
    int indice;
    int idMascota;
    int auxIdTipo;
    char auxVacunado;
    char salir = 'n';

    if(mascotas != NULL && tamm>0 && colores!=NULL && tamc>0 && tipos!=NULL && tamt>0)
    {
        listarMascotas(mascotas,tamm,colores,tamc,tipos,tamt);

        utn_getInt("Ingrese Id de la Mascota: ", "Error Id invalido. ", 10000, 20000, 100, &idMascota);

        if(buscarMascota(mascotas, tamm, idMascota, &indice))
        {
            if(indice == -1)
            {
                printf("No hay una mascota con id %d\n", idMascota);
            }
            else
            {
                printf("\n");
                mostrarMascota(mascotas[indice],tamm,colores,tamc,tipos,tamt);
                printf("\n");
                do
                {
                    switch(menuModificarMascota())
                    {
                    case 1:
                        listarTipos(tipos, tamt);
                        utn_getInt("Ingrese Id del nuevo tipo: ", "Error. Id invalido.",1000,1004,100,&auxIdTipo);

                        mascotas[indice].idTipo = auxIdTipo;
                        printf("\nModificacion exitosa!!\n");
                        break;
                    case 2:
                        printf("Ingrese estado de vacunacion (s/n): ");
                        fflush(stdin);
                        scanf("%c", &auxVacunado);
                        auxVacunado = tolower(auxVacunado);
                        while(auxVacunado != 's' && auxVacunado!= 'n')
                        {
                            printf("Error. Reingrese estado de vacunacion (s/n): ");
                            fflush(stdin);
                            scanf("%c", &auxVacunado);
                            auxVacunado = tolower(auxVacunado);
                        }

                        mascotas[indice].vacunado = auxVacunado;
                        printf("\nModificacion exitosa!!\n");
                        break;
                    case 3:
                        salir = 's';
                        break;
                    }
                }
                while(salir != 's');

                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar empleado!!\n\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int bajaMascota(eMascota mascotas[], int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt)
{
    int todoOk = 0;
    int indice;
    int idMascota;
    char confirma;

    if(mascotas != NULL && tamm>0 && colores!=NULL && tamc>0 && tipos!=NULL && tamt>0)
    {
        listarMascotas(mascotas,tamm,colores,tamc,tipos,tamt);

        utn_getInt("Ingrese id Mascota: ", "Error. Ingrese Id valido. ", 10000,20000,100, &idMascota);

        if(buscarMascota(mascotas, tamm, idMascota, &indice))
        {
            if(indice == -1)
            {
                printf("No hay una mascota con id %d\n", idMascota);
            }
            else
            {
                mostrarMascota(mascotas[indice],tamm, colores, tamc, tipos,tamt);
                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma != 'S' && confirma != 's')
                {
                    printf("Baja cancelada por el usuario!!\n");
                }
                else
                {
                    mascotas[indice].isEmpty = 1;
                    printf("Baja realizada con exito!!\n\n");
                    todoOk = 1;
                }
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar empleado!!\n\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int cargarDescripcionMascota(eMascota mascotas[], int tamm, int id, char descripcion[])
{
    int todoOk = 0;
    int indice;

    buscarMascota(mascotas, tamm, id, &indice);

    if(descripcion!=NULL && indice!=-1)
    {
        strcpy(descripcion, mascotas[indice].nombre);
        todoOk = 1;
    }
    return todoOk;
}

int ordenarMascotas(eMascota mascotas[], int tamm, int orden)
{
    int todoOk = 0;
    eMascota auxMascota;

    if(mascotas!=NULL && tamm>0)
    {
        for(int i=0; i<tamm-1; i++)
        {
            for(int j=i+1; j<tamm; j++)
            {
                if(((mascotas[i].idTipo > mascotas[j].idTipo) && orden == 1)
                        || ((mascotas[i].idTipo < mascotas[j].idTipo) && orden == 2)
                        || ((mascotas[i].idTipo == mascotas[j].idTipo) && (strcmp(mascotas[i].nombre, mascotas[j].nombre)>0) && orden == 1)
                        || ((mascotas[i].idTipo == mascotas[j].idTipo) && (strcmp(mascotas[i].nombre, mascotas[j].nombre)<0) && orden == 2))
                {
                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j] = auxMascota;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int hardcodearMascotas(eMascota mascotas[], int tamm, int cant, int* pId, int* flagAlta)
{
    int todoOk = 0;

    eMascota mascotasCopia[10] =
    {
        {0000, "Firulais", 1001, 5000, 6, 's',0},
        {0000, "Frufru", 1003, 5000, 3, 's',0},
        {0000, "Sofia", 1001, 5003, 13, 'n',0},
        {0000, "Rambo", 1004, 5003, 3, 's',0},
        {0000, "Ciro", 1002, 5000, 5, 'n',0},
        {0000, "Uma", 1002, 5000, 8, 's',0},
        {0000, "Ricardo", 1001, 5001, 12, 's',0},
        {0000, "Jackie", 1004, 5003, 16, 'n',0},
        {0000, "Otario", 1000, 5003, 11, 'n',0},
        {0000, "Lorenzo", 1000, 5001, 30, 's',0}
    };

    if(mascotas!=NULL && tamm>0 && pId!=NULL && flagAlta!=NULL && cant>0 && cant<=tamm)
    {
        for(int i=0; i<cant; i++)
        {
            mascotas[i] = mascotasCopia[i];
            mascotas[i].id = *pId;
            *pId = *pId + 1;
        }
        todoOk = 1;
        *flagAlta = 1;
    }
    return todoOk;
}

int listarMascotasColor(eMascota mascotas[], int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt)
{
    int todoOk = 0;
    int idColor;
    int flag = 0;
    char descripcionColor[20];

    if(mascotas!=NULL && tamm>0 && colores!=NULL && tamc>0 && tipos!=NULL && tamt>0)
    {
        listarColores(colores,tamc);

        utn_getInt("Ingrese id del color de mascota deseado: ", "Error. Ingrese id valido. ",5000,5004,100,&idColor);
        cargarDescripcionColor(colores,tamc,idColor,descripcionColor);
        system("cls");
        printf("      ******Listado de Mascotas de color %s******      \n\n", descripcionColor);
        printf("Id       Nombre             Tipo        Color        Edad      Vacunado\n");

        for(int i=0; i<tamm; i++)
        {
            if(mascotas[i].isEmpty==0 && mascotas[i].idColor == idColor)
            {
                mostrarMascota(mascotas[i],tamm,colores,tamc,tipos,tamt);
                flag = 1;
            }
        }

        if(flag == 0)
        {
            printf("\nNo hay mascotas en el sistema!!\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int promedioMascotasVacunadas(eMascota mascotas[], int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt)
{
    int todoOk = 0;
    int contadorVacunadas = 0;
    int contadorMascotas = 0;
    float promedioVacunadas;
    int flag = 0;
    int flagVacunadas = 0;

    if(mascotas!=NULL && tamm>0 && colores!=NULL && tamc>0 && tipos!=NULL && tamt>0)
    {
        for(int i=0; i<tamm; i++)
        {
            if(mascotas[i].isEmpty==0)
            {
                contadorMascotas++;
                flag = 1;
            }
        }

        for(int i=0; i<tamm; i++)
        {
            if(mascotas[i].isEmpty==0 && mascotas[i].vacunado == 's')
            {
                contadorVacunadas++;
                flagVacunadas = 1;
            }
        }

        if(flagVacunadas == 0)
        {
            promedioVacunadas = 0;
        }
        else
        {
            promedioVacunadas = (float) contadorMascotas / contadorVacunadas;
        }

        if(flag == 0)
        {
            printf("\nNo hay mascotas en el sistema!!\n");
        }
        else
        {
            printf("El promedio de mascotas vacunadas es: %.2f\n", promedioVacunadas);
        }

        todoOk = 1;
    }
    return todoOk;
}

int informarMascotaMenorEdad(eMascota mascotas[], int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt)
{
    int todoOk = 0;
    int menorEdad;
    int flag = 0;

    if(mascotas!=NULL && tamm>0 && colores!=NULL && tamc>0 && tipos!=NULL && tamt>0)
    {
        for(int i=0; i<tamm; i++)
        {
            if(mascotas[i].isEmpty==0)
            {
                if(i==0)
                {
                    menorEdad = mascotas[i].edad;
                }
                else
                {
                    if(mascotas[i].edad<menorEdad)
                    {
                        menorEdad = mascotas[i].edad;
                    }
                }
                flag = 1;
            }
        }

        if(flag == 0)
        {
            printf("\nNo hay mascotas en el sistema!!\n");
        }
        else
        {
            printf("      ******Listado de Mascotas de menor edad******      \n\n");
            printf("Id       Nombre             Tipo        Color        Edad      Vacunado\n");

            for(int i=0; i<tamm; i++)
            {
                if(mascotas[i].edad == menorEdad)
                {
                    mostrarMascota(mascotas[i],tamm,colores,tamc,tipos,tamt);
                }
            }
        }


        todoOk = 1;
    }
    return todoOk;
}

int listarMascotasPorTipo(eMascota mascotas[], int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt)
{
    int todoOk = 0;
    int flag = 0;

    if(mascotas!=NULL && tamm>0 && colores!=NULL && tamc>0 && tipos!=NULL && tamt>0)
    {
        for(int i=0; i<tamt; i++)
        {
            printf("\nMascotas tipo %s\n", tipos[i].descripcion);
            printf("Id       Nombre             Tipo        Color        Edad      Vacunado\n\n");
            for(int j=0; j<tamm; j++)
            {
                if(mascotas[j].isEmpty==0 && mascotas[j].idTipo == tipos[i].id)
                {
                    mostrarMascota(mascotas[j],tamm,colores,tamc,tipos,tamt);
                    flag = 1;
                }
            }

        }

        if(flag == 0)
        {
            printf("\nNo hay mascotas en el sistema!!\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int informarMascotasColorYTipo(eMascota mascotas[], int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt)
{
    int todoOk = 0;
    int idColor;
    int idTipo;
    char descripcionColor[20];
    char descripcionTipo[20];
    int contadorMascotasColorYTipo=0;
    int flag = 0;

    if(mascotas!=NULL && tamm>0 && colores!=NULL && tamc>0 && tipos!=NULL && tamt>0)
    {
        listarColores(colores,tamc);

        utn_getInt("Ingrese id del color de mascota deseado: ", "Error. Ingrese id valido. ",5000,5004,100,&idColor);
        cargarDescripcionColor(colores,tamc,idColor,descripcionColor);

        listarTipos(tipos, tamt);

        utn_getInt("Ingrese id del tipo de mascota deseado: ", "Error. Ingrese id valido. ",1000,1004,100,&idTipo);
        cargarDescripcionTipo(tipos,tamt,idTipo,descripcionTipo);
        for(int i=0; i<tamm; i++)
        {
            if(mascotas[i].idColor==idColor && mascotas[i].idTipo==idTipo)
            {
                contadorMascotasColorYTipo++;
                flag = 1;
            }
        }

        if(flag == 0)
        {
            printf("\nNo hay mascotas en el sistema!!\n");
        }
        else
        {
            printf("\nCantidad de mascotas de tipo %s y de color %s: %d\n", descripcionTipo, descripcionColor, contadorMascotasColorYTipo);
        }

        todoOk = 1;
    }
    return todoOk;
}


int informarColorMasMascotas(eMascota mascotas[], int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt)
{
    int todoOk = 0;
    int contadorNegro = 0;
    int contadorRojo = 0;
    int contadorBlanco = 0;
    int contadorGris = 0;
    int contadorAzul = 0;
    int mayorCantidad;
    int flag = 0;

    if(mascotas!=NULL && tamm>0 && colores!=NULL && tamc>0 && tipos!=NULL && tamt>0)
    {
        for(int i=0; i<tamm; i++)
        {
            if(mascotas[i].isEmpty==0 && mascotas[i].idColor == 5000)
            {
                contadorNegro++;
                flag = 1;
            }
            else
            {
                if(mascotas[i].isEmpty==0 && mascotas[i].idColor == 5001)
                {
                    contadorBlanco++;
                    flag = 1;
                }
                else
                {
                    if(mascotas[i].isEmpty==0 && mascotas[i].idColor == 5002)
                    {
                        contadorRojo++;
                        flag = 1;
                    }
                    else
                    {
                        if(mascotas[i].isEmpty==0 && mascotas[i].idColor == 5003)
                        {
                            contadorGris++;
                            flag = 1;
                        }
                        else
                        {
                            if(mascotas[i].isEmpty==0 && mascotas[i].idColor == 5004)
                            {
                                contadorAzul++;
                                flag = 1;
                            }
                        }
                    }
                }
            }
        }

        if(contadorNegro>contadorAzul && contadorNegro>contadorBlanco && contadorNegro>contadorRojo && contadorNegro>contadorGris)
        {
            mayorCantidad = contadorNegro;
        }
        else
        {
            if(contadorAzul>contadorRojo && contadorAzul>contadorBlanco && contadorAzul>contadorGris)
            {
                mayorCantidad = contadorAzul;
            }
            else
            {
                if(contadorBlanco>contadorRojo && contadorBlanco>contadorGris)
                {
                    mayorCantidad = contadorBlanco;
                }
                else
                {
                    if(contadorRojo>contadorGris)
                    {
                        mayorCantidad = contadorRojo;
                    }
                    else
                    {
                        mayorCantidad = contadorGris;
                    }
                }
            }
        }

        if(flag == 0)
        {
            printf("\nNo hay mascotas en el sistema!!\n");
        }
        else
        {
            printf("Colores con mayor cantidad de mascotas: \n");
            if(contadorNegro==mayorCantidad)
            {
                printf("Negro\n");
            }
            if(contadorAzul==mayorCantidad)
            {
                printf("Azul\n");
            }
            if(contadorBlanco==mayorCantidad)
            {
                printf("Blanco\n");
            }
            if(contadorRojo==mayorCantidad)
            {
                printf("Rojo\n");
            }
            if(contadorGris==mayorCantidad)
            {
                printf("Gris\n");
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
