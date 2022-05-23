#include "notebook.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id;
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

typedef struct{

int id;
char descripcion[20];
int precio;
}eServicio;

#endif // TRABAJO_H_INCLUDED

/** \brief para indicar que las posiciones del array están vacías, pone el isempty en verdadero
 *
 * \param vec[] eTrabajo recibe el array de trabajos
 * \param tam int recibe el tamaño del array de trabajos
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no (si el array es NULL o el tamaño < 0)
 *
 */
int inicializarTrabajos(eTrabajo vec[], int tam);

/** \brief harcodea un listado de trabajos
 *
 * \param vec[] eTrabajo recibe el array de trabajos
 * \param tam int recibe el tamaño del array de trabajos
 * \param cant int recibe la cantidad que quieras mostrar de tu harcodeo
 * \param pId int* recibe como puntero el id de trabajos y lo guarda
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no (si el array es NULL, el tamaño < 0, la cantidad < 0 o > al tamaño, o el id es NULL)
 *
 */
int hardcodearTrabajos(eTrabajo vec[], int tam, int cant, int* pId);

/** \brief da de alta (ingresa/carga en el sistema) los trabajos
 *
 * \param tra[] eTrabajo recibe el array de trabajos
 * \param tamTra int recibe el tamaño del array de trabajos
 * \param servicios[] eServicio recibe el array de servicios
 * \param tamS int recibe el tamaño del array de servicios
 * \param pId int* recibe como puntero el id de trabajos y lo guarda
 * \param vec[] eNotebook recibe el array de notebooks
 * \param tam int recibe el tamaño del array de notebooks
 * \param marcas[] eMarca recibe el array de marcas
 * \param tamM int recibe el tamaño del array de marcas
 * \param tipos[] eTipo recibe el array de tipos
 * \param tamT int recibe el tamaño del array de tipos
 * \param pFlag int* recibe como puntero una bandera
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int altaTrabajo(eTrabajo tra[], int tamTra, eServicio servicios[], int tamS, int* pId, eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC, int* pFlag);

/** \brief muestra la lista de trabajos cargados en el sistema
 *
 * \param vec[] eTrabajo recibe el array de trabajos
 * \param tam int recibe el tamaño del array de trabajos
 * \param servicios[] eServicio recibe el array de servicios
 * \param tamS int recibe el tamaño del array de servicios
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int listarTrabajos(eTrabajo vec[], int tam, eServicio servicios[], int tamS);

/** \brief muestra los detalles del trabajo
 *
 * \param t eTrabajo recibe el array de trabajos
 * \param servicios[] eServicio recibe el array de servicios
 * \param tam int recibe el tamaño del array de servicios
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int mostrarTrabajos(eTrabajo t, eServicio servicios[], int tam);

/** \brief carga la descripcion(nombre) del servicio
 *
 * \param servicios[] eServicio recibe el tamaño del array de servicios
 * \param tam int recibe el tamaño del array de servicios
 * \param id int recibe el idServicio
 * \param descripcion[] char  recibe el nombre del servicio
 * \return int  retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int cargarDescripcionServicios(eServicio servicios[], int tam, int id, char descripcion[]);

/** \brief se fija si hay espacio para poder cargar un trabajo
 *
 * \param vec[] eTrabajo recibe el array de trabajos
 * \param tam int recibe el tamaño del array de trabajos
 * \param pIndex int* recibe como puntero el indice, el cual, si hay espacio, guarda la direccion del espacio vacio
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int buscarTrabajoLibre(eTrabajo vec[], int tam, int* pIndex);

/** \brief muestra la lista de servicios disponibles
 *
 * \param servicios[] eServicio recibe el array de sevicios
 * \param tam int recibe el tamaño del array de sevicios
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int listarServicios(eServicio servicios[], int tam);

