#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
} eCliente;

#endif // CLIENTE_H_INCLUDED

/** \brief carga el nombre d elos clientes
 *
 * \param clientes[] eCliente recibe el array de clientes
 * \param tamC int recibe el tamaño del array de clientes
 * \param id int recibe el id del cliente
 * \param nombre[] char recibe el nombre del cliente
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int cargarDescripcionClientes(eCliente clientes[], int tamC, int id, char nombre[]);

/** \brief muestra una lista con los clientes
 *
 * \param clientes[] eCliente recibe el array de clientes
 * \param tamC int recibe el tamaño del array de clientes
 * \return int retorna todoOk = 1 si entra en la funcion y 0 si no
 *
 */
int listarClientes(eCliente clientes[], int tamC);
