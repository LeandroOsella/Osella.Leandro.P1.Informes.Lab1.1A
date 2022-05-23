#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;
}eServicio;

#endif // SERVICIO_H_INCLUDED
/** \brief muestra en pantalla el listado de servicios
 *
 * \param servicios[] eServicio array de servicios
 * \param tams int tamaño del array de servicios
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int listarServicios(eServicio servicios[], int tams);
/** \brief pide un id al usuario y busca el servicio con dicho id
 *
 * \param servicios[] eServicio array de servicios
 * \param tams int tamaño del array de servicios
 * \param id int id del servicio que se desea buscar
 * \param pIndice int* puntero a variable donde se guarda la posicion del servicio (se carga con -1 en caso de no encontrarlo)
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int buscarServicio(eServicio servicios[], int tams, int id, int* pIndice);
/** \brief carga el nombre de un servicio
 *
 * \param servicios[] eServicio array de servicios
 * \param tams int tamaño del array de servicios
 * \param id int id del servicio del cual se desea cargar el nombre
 * \param descripcion[] char variable donde se guarda el nombre del servicio en cuestion
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int cargarDescripcionServicio(eServicio servicios[], int tams, int id, char descripcion[]);
