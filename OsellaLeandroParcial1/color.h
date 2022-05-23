#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
}eColor;

#endif // COLOR_H_INCLUDED

/** \brief muestra en pantalla el listado de colores
 *
 * \param colores[] eColor array de colores
 * \param tamc int tamaño del array de colores
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int listarColores(eColor colores[], int tamc);
/** \brief pide un id de un color al usuario y recorre el array buscando dicho color
 *
 * \param colores[] eColor array de colores
 * \param tamc int tamaño del array de colores
 * \param id int id del color deseado
 * \param pIndice int* puntero a variable donde se guarda la posicion del color (se carga con -1 en caso de no encontrarlo)
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int buscarColor(eColor colores[], int tamc, int id, int* pIndice);
/** \brief carga el nombre de un color
 *
 * \param colores[] eColor array de colores
 * \param tamc int tamaño del array de colores
 * \param id int id del color del cual se desea cargar el nombre
 * \param descripcion[] char variable donde se guarda el nombre del color
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int cargarDescripcionColor(eColor colores[], int tamc, int id, char descripcion[]);
