#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "mascota.h"
#include "validacion.h"
#include "fecha.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    int idMascota;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED
/** \brief recorre el array de trabajos y pone el campo isEmpty de cada posicion en 1
 *
 * \param trabajos[] eTrabajo array de trabajos
 * \param tamtra int tamaño del array de trabajos
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int inicializarTrabajos(eTrabajo trabajos[], int tamtra);
/** \brief recorre el array de trabajos y busca la primer posicion libre
 *
 * \param trabajos[] eTrabajo array de trabajos
 * \param tamtra int tamaño del array de trabajos
 * \param pIndex int* puntero a la variable donde se guarda la posicion del primer espacio libre
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int buscarLibreTrabajo(eTrabajo trabajos[], int tamtra, int* pIndex);
/** \brief permite dar de alta un trabajo y le asigna un id automaticamente
 *
 * \param trabajos[] eTrabajo array de trabajos
 * \param tamtra int tamaño del array de trabajos
 * \param mascotas[] eMascota array de mascotas
 * \param tamm int tamaño del array de mascotas
 * \param servicios[] eServicio array de servicios
 * \param tams int tamaño del array de servicios
 * \param colores[] eColor array de colores
 * \param tamc int tamaño del array de colores
 * \param tipos[] eTipo array de tipo de mascotas
 * \param tamt int tamaño del array de tipo de mascotas
 * \param pProximoIdTrabajo int* puntero a id que se le asigna al trabajo
 * \return int retona 1 si todo OK o 0 si hubo algun error
 *
 */
int altaTrabajo(eTrabajo trabajos[], int tamtra, eMascota mascotas[], int tamm, eServicio servicios[], int tams, eColor colores[], int tamc, eTipo tipos[], int tamt, int* pProximoIdTrabajo);
/** \brief muestra en pantalla 1 trabajo
 *
 * \param trabajo eTrabajo 1 trabajo del array
 * \param tamtra int tamaño del array de trabajos
 * \param servicios[] eServicio array de servicios
 * \param tams int tamaño del array de servicios
 * \param mascotas[] eMascota array de mascotas
 * \param tamm int tamaño del array de mascotas
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int mostrarTrabajo(eTrabajo trabajo, int tamtra, eServicio servicios[], int tams, eMascota mascotas[], int tamm);
/** \brief muestra en pantalla un listado de todos los trabajos
 *
 * \param trabajos[] eTrabajo array de trabajos
 * \param tamtra int tamaño del array de trabajos
 * \param mascotas[] eMascota array de mascotas
 * \param tamm int tamaño del array de mascotas
 * \param servicios[] eServicio array de servicios
 * \param tams int tamaño del array de servicios
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int listarTrabajos(eTrabajo trabajos[], int tamtra, eMascota mascotas[], int tamm, eServicio servicios[], int tams);

/** \brief realiza un hardcodeo de trabajos
 *
 * \param trabajos[] eTrabajo array de trabajos
 * \param tamtra int tamaño del array de trabajos
 * \param mascotas[] eMascota array de mascotas
 * \param tamm int tamaño del array de mascotas
 * \param servicios[] eServicio array de servicios
 * \param tams int tamaño del array de servicios
 * \param cant int cantidad de trabajos que se desea hardcodear
 * \param pIdTrabajo int* puntero a id que se le asigna al trabajo
 * \param flagAltaTrabajo int* puntero a flagAltaTrabajo cuyo valor se pone en 1 para poder operar en el menu de opciones
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int hardcodearTrabajos(eTrabajo trabajos[], int tamtra, eMascota mascotas[], int tamm, eServicio servicios[], int tams, int cant, int* pIdTrabajo, int* flagAltaTrabajo);
