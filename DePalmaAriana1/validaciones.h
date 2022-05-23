#include "trabajo.h"
#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED

/** \brief valida si la fecha existe y devuelve la fecha resultante
 *
 * \param unaFecha eFecha recibe la estructura fecha
 * \return eFecha retorna la fecha
 *
 */
eFecha validarFecha(eFecha unaFecha);
/** \brief valida si el id de la marca ingresada es correcto
 *
 * \param marcas[] eMarca recibe el array de marcas
 * \param tam int recibe el tamaño del array de marcas
 * \param id int recibe el idMarca
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int validarMarcas(eMarca marcas[], int tam, int id);
/** \brief valida si el id del tipo ingresado es correcto
 *
 * \param tipos[] eTipo recibe el array de tipos
 * \param tam int recibe el tamaño del array de tipos
 * \param id int recibe el idTipo
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int validarTipos(eTipo tipos[], int tam, int id);

/** \brief valida si el id del servicio ingresado es correcto
 *
 * \param servicios[] eServicio recibe el array de servicios
 * \param tam int recibe el tamaño del array de servicios
 * \param id int recibe el idServicios
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int validarServicios(eServicio servicios[], int tam, int id);

/** \brief busca la marca segun el id
 *
 * \param marcas[] eMarca recibe el array de marcas
 * \param tam int recibe el tamaño del array de marcas
 * \param id int recibe el idMarca
 * \param pIndice int* recibe el indice como puntero
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int buscarMarcas(eMarca marcas[], int tam, int id, int* pIndice);
/** \brief busca el tipo segun el id
 *
 * \param tipos[] eTipo recibe el array de tipos
 * \param tam int recibe el tamaño del array de tipos
 * \param id int recibe el idTipo
 * \param pIndice int* recibe el indice como puntero
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int buscarTipos(eTipo tipos[], int tam, int id, int* pIndice);
/** \brief busca el servicio segun el id
 *
 * \param servicios[] eServicio recibe el array de servicios
 * \param tam int recibe el tamaño del array de servicios
 * \param id int recibe el idServicios
 * \param pIndice int* recibe el indice como puntero
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int buscarServicios(eServicio servicios[], int tam, int id, int* pIndice);

int validarClientes(eCliente clientes[], int tam, int id);
int buscarClientes(eCliente clientes[], int tam, int id, int* pIndice);
