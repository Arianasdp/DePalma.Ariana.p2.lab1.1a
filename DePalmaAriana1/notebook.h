#include "cliente.h"
#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED

typedef struct
{
    int id;
    char modelo[20];
    float precio;
    int idMarca;
    int idTipo;
    int idCliente;
    int isEmpty;
} eNotebook;

typedef struct{
    int id;
    char descripcion[20];

}eMarca;

typedef struct{

int id;
char descripcion[20];

}eTipo;

#endif // NOTEBOOK_H_INCLUDED

/** \brief para indicar que las posiciones del array están vacías, pone el isempty en verdadero
 *
 * \param vec[] eNotebook recibe el array de notebooks
 * \param tam int recibe el tamaño del array de notebooks
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no (si el array es NULL o el tamaño < 0)
 *
 */
int inicializarNotebooks(eNotebook vec[], int tam);

/** \brief harcodea un listado de notebooks
 *
 * \param vec[] eNotebook recibe el array de notebooks
 * \param tam int recibe el tamaño del array de notebooks
 * \param cant int recibe la cantidad que quieras mostrar de tu harcodeo
 * \param pId int* recibe como puntero el id de notebooks y lo guarda
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no (si el array es NULL, el tamaño < 0, la cantidad < 0 o > al tamaño, o el id es NULL)
 *
 */
int hardcodearNotebooks(eNotebook vec[], int tam, int cant, int* pId);

/** \brief da de alta (ingresa/carga en el sistema) las notebooks
 *
 * \param vec[] eNotebook recibe el array de notebooks
 * \param tam int recibe el tamaño del array de notebooks
 * \param marcas[] eMarca recibe el array de marcas
 * \param tamM int recibe el tamaño del array de marcas
 * \param tipos[] eTipo recibe el array de tipos
 * \param tamT int recibe el tamaño del array de tipos
 * \param clientes[] eCliente recibe el array de clientes
 * \param tamC int recibe el tamaño del array de clientes
 * \param pId int* recibe como puntero el id de notebooks y lo guarda
 * \param pFlag int* recibe como puntero una bandera
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int altaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC, int* pId, int* pFlag);

/** \brief modifica los datos de la notebook segun el usuario lo requiera
 *
 * \param vec[] eNotebook recibe el array de notebooks
 * \param tam int recibe el tamaño del array de notebooks
 * \param marcas[] eMarca recibe el array de marcas
 * \param tamM int recibe el tamaño del array de marcas
 * \param tipos[] eTipo recibe el array de tipos
 * \param tamT int recibe el tamaño del array de tipos
 * \param clientes[] eCliente recibe el array de clientes
 * \param tamC int recibe el tamaño del array de clientes
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int modificarNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC);

/** \brief da de baja una notebook segun el id que ingrese el usuario
 *
 * \param vec[] eNotebook recibe el array de notebooks
 * \param tam int recibe el tamaño del array de notebooks
 * \param marcas[] eMarca recibe el array de marcas
 * \param tamM int recibe el tamaño del array de marcas
 * \param tipos[] eTipo recibe el array de tipos
 * \param tamT int recibe el tamaño del array de tipos
 * \param clientes[] eCliente recibe el array de clientes
 * \param tamC int recibe el tamaño del array de clientes
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int bajaNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC);

/** \brief se fija si hay espacio para poder cargar una notebook
 *
 * \param vec[] eNotebook recibe el array de notebooks
 * \param tam int recibe el tamaño del array de notebooks
 * \param pIndex int* recibe como puntero el indice, el cual, si hay espacio, guarda la direccion del espacio vacio
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int buscarNotebookLibre(eNotebook vec[], int tam, int* pIndex);

/** \brief muestra la lista de marcas de notebooks disponibles
 *
 * \param marcas[] eMarca recibe el array de marcas
 * \param tam int recibe el tamaño del array de marcas
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int listarMarcas(eMarca marcas[], int tam);

/** \brief muestra la lista de tipos de notebooks disponibles
 *
 * \param tipos[] eTipo recibe el array de tipos
 * \param tam int recibe el tamaño del array de tipos
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int listarTipos(eTipo tipos[], int tam);

/** \brief muestra la lista de notebooks cargadas en el sistema
 *
 * \param vec[] eNotebook recibe el array de notebooks
 * \param tam int recibe el tamaño del array de notebooks
 * \param marcas[] eMarca recibe el array de marcas
 * \param tamM int recibe el tamaño del array de marcas
 * \param tipos[] eTipo recibe el array de tipos
 * \param tamT int recibe el tamaño del array de tipos
 * \param clientes[] eCliente recibe el array de clientes
 * \param tamC int recibe el tamaño del array de clientes
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int listarNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC);

/** \brief ordena el listado de notebooks por marca y precio
 *
 * \param vec[] eNotebook recibe el array de notebooks
 * \param tam int recibe el tamaño del array de notebooks
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int ordenarNotebooksPorMarcaYPrecio(eNotebook vec[], int tam);

/** \brief muestra los detalles de la notebook
 *
 * \param n eNotebook recibe el array de notebooks
 * \param marcas[] eMarca recibe el array de marcas
 * \param tipos[] eTipo recibe el array de tipos
 * \param tamM int recibe el tamaño del array de marcas
 * \param tamT int recibe el tamaño del array de tipos
 * \param clientes[] eCliente recibe el array de clientes
 * \param tamC int recibe el tamaño del array de clientes
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int mostrarNotebook(eNotebook n, eMarca marcas[], eTipo tipos[], int tamM, int tamT, eCliente clientes[], int tamC);

/** \brief carga la descripcion(nombre) de la marca
 *
 * \param marcas[] eMarca recibe el array de marcas
 * \param tam int recibe el tamaño del array de marcas
 * \param id int recibe el idMarca
 * \param descripcion[] char recibe el nombre de la marca
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int cargarDescripcionMarcas(eMarca marcas[], int tam, int id, char descripcion[]);
/** \brief carga la descripcion(nombre) del tipo
 *
* \param mtipos[] eTipo recibe el array de tipos
 * \param tam int recibe el tamaño del array de tipos
 * \param id int recibe el idTipo
 * \param descripcion[] char recibe el nombre del tipo
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int cargarDescripcionTipos(eTipo tipos[], int tam, int id, char descripcion[]);

/** \brief busca una notebook en particular mediante su id
 *
 * \param vec[] eNotebook recibe el array de notebooks
 * \param tam int recibe el tamaño del array de notebooks
 * \param id int recibe el id de la notebook
 * \param pIndex int* recibe el indice como puntero
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int buscarNotebook(eNotebook vec[], int tam,int id, int* pIndex);

/** \brief lista las notebooks segun el tipo elegido por el usuario
 *
 * \param vec[] eNotebook recibe el array de notebooks
 * \param tam int recibe el tamaño del array de notebooks
 * \param marcas[] eMarca recibe el array de marcas
 * \param tamM int recibe el tamaño del array de marcas
 * \param tipos[] eTipo recibe el array de tipos
 * \param tamT int recibe el tamaño del array de tipos
 * \param clientes[] eCliente recibe el array de clientes
 * \param tamC int recibe el tamaño del array de clientes
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int listarNotebooksSegunTipoSeleccionado(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC);

/** \brief lista las notebooks segun la marca elegida por el usuario
 *
 * \param vec[] eNotebook recibe el array de notebooks
 * \param tam int recibe el tamaño del array de notebooks
 * \param marcas[] eMarca recibe el array de marcas
 * \param tamM int recibe el tamaño del array de marcas
 * \param tipos[] eTipo recibe el array de tipos
 * \param tamT int recibe el tamaño del array de tipos
 * \param clientes[] eCliente recibe el array de clientes
 * \param tamC int recibe el tamaño del array de clientes
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int listarNotebooksSegunMarcaSeleccionada(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC);

/** \brief informa cual es la notebook mas barata
 *
 * \param vec[] eNotebook recibe el array de notebooks
 * \param tam int recibe el tamaño del array de notebooks
 * \param marcas[] eMarca recibe el array de marcas
 * \param tamM int recibe el tamaño del array de marcas
 * \param tipos[] eTipo recibe el array de tipos
 * \param tamT int recibe el tamaño del array de tipos
 * \param clientes[] eCliente recibe el array de clientes
 * \param tamC int recibe el tamaño del array de clientes
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int informarNotebookMasBarata(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC);

/** \brief presenta un listado de notebooks por marca
 *
 * \param vec[] eNotebook recibe el array de notebooks
 * \param tam int recibe el tamaño del array de notebooks
 * \param marcas[] eMarca recibe el array de marcas
 * \param tamM int recibe el tamaño del array de marcas
 * \param tipos[] eTipo recibe el array de tipos
 * \param tamT int recibe el tamaño del array de tipos
 * \param clientes[] eCliente recibe el array de clientes
 * \param tamC int recibe el tamaño del array de clientes
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int informarNotebooksXMarca(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC);

/** \brief le pide al usuario seleccionar una marca y un tipo y le presenta la notebook que cumpla con esos criterios, si es que la hay
 *
 * \param vec[] eNotebook recibe el array de notebooks
 * \param tam int recibe el tamaño del array de notebooks
 * \param marcas[] eMarca recibe el array de marcas
 * \param tamM int recibe el tamaño del array de marcas
 * \param tipos[] eTipo recibe el array de tipos
 * \param tamT int recibe el tamaño del array de tipos
 * \param clientes[] eCliente recibe el array de clientes
 * \param tamC int recibe el tamaño del array de clientes
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int listarNotebooksSegunTipoYMarcaSeleccionados(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC);

/** \brief informa cual es la marca mas elegida
 *
 * \param vec[] eNotebook recibe el array de notebooks
 * \param tam int recibe el tamaño del array de notebooks
 * \param marcas[] eMarca recibe el array de marcas
 * \param tamM int recibe el tamaño del array de marcas
 * \return int todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int marcaMasElegida(eNotebook vec[], int tam, eMarca marcas[], int tamM);
