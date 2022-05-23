#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED

/** \brief muestra en pantalla el listado de tipos de mascotas
 *
 * \param tipos[] eTipo array de tipo de mascotas
 * \param tamt int tamaño del array de tipo de mascotas
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int listarTipos(eTipo tipos[], int tamt);
/** \brief pide al usuario un id y busca en el array el tipo de mascota con ese id
 *
 * \param tipos[] eTipo array de tipo de mascotas
 * \param tamt int tamaño del array de tipo de mascotas
 * \param id int id del tipo que se desea buscar
 * \param pIndice int* puntero a la variable donde se guarda la posicion del servicio encontrado (se carga con -1 en caso de no encontrarlo)
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int buscarTipo(eTipo tipos[], int tamt, int id, int* pIndice);
/** \brief carga el nombre de un tipo de mascota
 *
 * \param tipos[] eTipo array de tipo de mascotas
 * \param tamt int tamaño del array de tipo de mascotas
 * \param id int id del tipo de mascota del cual se quiere cargar el nombre
 * \param descripcion[] char variable donde se guarda el nombre del tipo de mascota en cuestion
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int cargarDescripcionTipo(eTipo tipos[], int tamt, int id, char descripcion[]);
