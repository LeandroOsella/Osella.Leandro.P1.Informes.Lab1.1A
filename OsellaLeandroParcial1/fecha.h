#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

#endif // FECHA_H_INCLUDED

/** \brief permite el ingreso de una fecha y valida que sea correcta
 *
 * \param dia int* puntero a la variable donde se escribira el dia
 * \param mes int* puntero a la variable donde se escribira el mes
 * \param anio int* puntero a la variable donde se escribira el anio
 * \return int retorna 1 si todo OK y 0 si hubo algun error
 *
 */
int ingresarFecha(int* dia, int* mes, int* anio);
