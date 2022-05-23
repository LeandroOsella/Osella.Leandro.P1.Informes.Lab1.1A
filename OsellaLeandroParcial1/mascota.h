#include "tipo.h"
#include "color.h"

#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    char vacunado;
    int isEmpty;
}eMascota;


#endif // MASCOTA_H_INCLUDED

/** \brief recorre el array de mascotas y pone el campo isEmpty de cada posicion en 0
 *
 * \param mascotas[] eMascota array de mascotas
 * \param tamm int tamaño del array de mascotas
 * \return int retorna 1 si todo OK o 0 si hubo algun eror
 *
 */
int inicializarMascotas(eMascota mascotas[], int tamm);
/** \brief recorre el array de mascotas y busca la primer posicion libre (campo isEmpty = 1)
 *
 * \param mascotas[] eMascota array de mascotas
 * \param tamm int  tamaño del array de mascotas
 * \param pIndex int* puntero a la variable donde se escribe el indice del lugar disponible encontrado
 * \return int retorna 1 si todo OK o 0 si hubo algun eror
 *
 */
int buscarLibre(eMascota mascotas[], int tamm, int* pIndex);
/** \brief permite realizar el alta de una mascota ubicandola en el primer espacio libre y asignandole un id automaticamente
 *
 * \param mascotas[] eMascota array de mascotas
 * \param tamm int tamaño del array de mascotas
 * \param pProximoIdMascota int* puntero a id que se le asigna a la mascota
 * \param tipos[] eTipo array de tipo de mascotas
 * \param tamt int tamaño del array de tipo de mascotas
 * \param colores[] eColor array de colores
 * \param tamc int tamaño del array de colores
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int altaMascota(eMascota mascotas[], int tamm, int* pProximoIdMascota, eTipo tipos[], int tamt, eColor colores[], int tamc);
/** \brief muestra en pantalla 1 mascota
 *
 * \param mascota eMascota 1 mascota del array
 * \param tamm int tamaño del array de mascotas
 * \param colores[] eColor array de colores
 * \param tamc int tamaño del array de colores
 * \param tipos[] eTipo array de tipo de mascotas
 * \param tamt int tamaño del array de tipo de mascotas
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int mostrarMascota(eMascota mascota, int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt);
/** \brief muestra en pantalla el listado de mascotas
 *
 * \param mascotas[] eMascota array de mascotas
 * \param tamm int tamaño del array de mascotas
 * \param colores[] eColor array de colores
 * \param tamc int tamaño del array de colores
 * \param tipos[] eTipo array de tipo de mascotas
 * \param tamt int tamaño del array de tipo de mascotas
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int listarMascotas(eMascota mascotas[], int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt);
/** \brief pide un id al usuario y busca en el array la mascota con dicho id
 *
 * \param mascotas[] eMascota array de mascotas
 * \param tamm int tamaño del array de mascotas
 * \param id int id de la mascota deseada
 * \param pIndex int* puntero a la variable donde se guarda la posicion de la mascota (se carga con -1 en caso de no encontrar dicha mascota)
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int buscarMascota(eMascota mascotas[], int tamm, int id, int* pIndex);
/** \brief permite realizar la modificacion de los datos "tipo" y "vacunado" de una mascota
 *
 * \param mascotas[] eMascota array de mascotas
 * \param tamm int tamaño del array de mascotas
 * \param colores[] eColor array de colores
 * \param tamc int tamaño del array de colores
 * \param tipos[] eTipo array de tipo de mascotas
 * \param tamt int tamaño del array de tipo de mascotas
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int modificarMascota(eMascota mascotas[], int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt);
/** \brief permite realizar la baja logica de una mascota (pone su campo isEmpty en 1)
 *
 * \param mascotas[] eMascota array de mascotas
 * \param tamm int tamaño del array de mascotas
 * \param colores[] eColor array de colores
 * \param tamc int tamaño del array de colores
 * \param tipos[] eTipo array de tipo de mascotas
 * \param tamt int tamaño del array de tipo de mascotas
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int bajaMascota(eMascota mascotas[], int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt);
/** \brief carga el nombre de una mascota
 *
 * \param mascotas[] eMascota array de mascotas
 * \param tamm int tamaño del array de mascotas
 * \param id int id de la mascota de la cual se quiere cargar el nombre
 * \param descripcion[] char variable donde se guarda el nombre de la mascota
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int cargarDescripcionMascota(eMascota mascotas[], int tamm, int id, char descripcion[]);
/** \brief ordena el listado de mascotas por tipo y nombre de manera Ascendente o Descendente
 *
 * \param mascotas[] eMascota array de mascotas
 * \param tamm int tamaño del array de mascotas
 * \param orden int orden en el que se ordena el array (1 para Ascendente y 2 para Descendente)
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int ordenarMascotas(eMascota mascotas[], int tamm, int orden);
/** \brief realiza un hardcodeo de un listado de mascotas
 *
 * \param mascotas[] eMascota array de mascotas
 * \param tamm int tamaño del array de mascotas
 * \param cant int cantidad de mascotas que se desea cargar
 * \param pId int* puntero a la variable id que se le asigna a cada mascota
 * \param flagAlta int* puntero a flagAlta cuyo valor se cambia a 1 para poder operar por el menu de opciones
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int hardcodearMascotas(eMascota mascotas[], int tamm, int cant, int* pId, int* flagAlta);

/** \brief muestra en pantalla un listado de mascotas de un color seleccionado por el usuario
 *
 * \param mascotas[] eMascota array de mascotas
 * \param tamm int tamaño del array de mascotas
 * \param colores[] eColor array de colores
 * \param tamc int tamaño del array de colores
 * \param tipos[] eTipo array de tipo de mascotas
 * \param tamt int tamaño del array de tipo de mascotas
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int listarMascotasColor(eMascota mascotas[], int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt);

/** \brief muestra en pantalla el promedio de mascotas vacunadas (campo vacunado == 's')
 *
 * \param mascotas[] eMascota array de mascotas
 * \param tamm int tamaño del array de mascotas
 * \param colores[] eColor array de colores
 * \param tamc int tamaño del array de colores
 * \param tipos[] eTipo array de tipo de mascotas
 * \param tamt int tamaño del array de tipo de mascotas
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int promedioMascotasVacunadas(eMascota mascotas[], int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt);

/** \brief muestra en pantalla un listado de las mascotas de menor edad
 *
 * \param mascotas[] eMascota array de mascotas
 * \param tamm int tamaño del array de mascotas
 * \param colores[] eColor array de colores
 * \param tamc int tamaño del array de colores
 * \param tipos[] eTipo array de tipo de mascotas
 * \param tamt int tamaño del array de tipo de mascotas
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int informarMascotaMenorEdad(eMascota mascotas[], int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt);

/** \brief muestra en pántalla un listado de mascotas separadas por tipo
 *
 * \param mascotas[] eMascota array de mascotas
 * \param tamm int tamaño del array de mascotas
 * \param colores[] eColor array de colores
 * \param tamc int tamaño del array de colores
 * \param tipos[] eTipo array de tipo de mascotas
 * \param tamt int tamaño del array de tipo de mascotas
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int listarMascotasPorTipo(eMascota mascotas[], int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt);

/** \brief muestra en pantalla la cantidad de mascotas de un determinado tipo y color
 *
 * \param mascotas[] eMascota array de mascotas
 * \param tamm int tamaño del array de mascotas
 * \param colores[] eColor array de colores
 * \param tamc int tamaño del array de colores
 * \param tipos[] eTipo array de tipo de mascotas
 * \param tamt int tamaño del array de tipo de mascotas
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int informarMascotasColorYTipo(eMascota mascotas[], int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt);


/** \brief muestra en pantalla el color con mayor cantidad de mascotas
 *
 * \param mascotas[] eMascota array de mascotas
 * \param tamm int tamaño del array de mascotas
 * \param colores[] eColor array de colores
 * \param tamc int tamaño del array de colores
 * \param tipos[] eTipo array de tipo de mascotas
 * \param tamt int tamaño del array de tipo de mascotas
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int informarColorMasMascotas(eMascota mascotas[], int tamm, eColor colores[], int tamc, eTipo tipos[], int tamt);
