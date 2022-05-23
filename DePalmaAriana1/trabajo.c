#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trabajo.h"
#include "notebook.h"
#include "validaciones.h"

int inicializarTrabajos(eTrabajo vec[], int tam)
{
    int todoOk = 0;
    if(vec && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int hardcodearTrabajos(eTrabajo vec[], int tam, int cant, int* pId)
{
    int todoOk = 0;
    eTrabajo impostores[] =
    {
        {000, 100, 20000, {3, 2, 2000}, 0},
        {000, 101, 20001, {5, 5, 2010}, 0},
        {000, 102, 20002, {18, 11, 2001}, 0}
    };

    if(vec && tam > 0 && pId && cant > 0 && cant <= tam)
    {

        for(int i = 0; i < cant; i++)
        {
            vec[i] = impostores[i];
            vec[i].id = *pId;
            *pId = *pId +1;

        }
        todoOk = 1;
    }
    return todoOk;

}

int altaTrabajo(eTrabajo tra[], int tamTra, eServicio servicios[], int tamS, int* pId, eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC, int* pFlag)
{
    int todoOk = 0;
    int indice;
    int indiceN;
    int id;
    eTrabajo nuevoTrabajo;
    eFecha fecha;

    if(tra && tamTra > 0 && pId)
    {
        if(buscarTrabajoLibre(tra, tamTra, &indice))
        {

            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                    listarNotebooks(vec, tam, marcas, tamM, tipos, tamT, clientes, tamC);
                    printf("Ingrese el IdNotebook: ");
                    scanf("%d", &id);

                    buscarNotebook(vec, tam, id, &indiceN);
                    while(indiceN == - 1)
                    {
                        printf("Error. Reingrese idNotebook: ");
                        scanf("%d", &id);
                        buscarNotebook(vec, tam, id, &indiceN);
                    }

                    nuevoTrabajo.idNotebook = id;

                    printf("Ingrese Fecha ingreso dd/mm/aaaa: ");
                    scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
                    fecha = validarFecha(fecha);

                    nuevoTrabajo.fecha = fecha;

                    listarServicios(servicios, tamS);

                    printf("Ingrese IdServicio: ");
                    scanf("%d", &nuevoTrabajo.idServicio);

                    while(!validarServicios(servicios, tam, nuevoTrabajo.idServicio))
                    {
                        printf("Servicio invalido. Ingrese IdServicio: ");
                        scanf("%d", &nuevoTrabajo.idServicio);
                    }

                    nuevoTrabajo.isEmpty = 0;
                    nuevoTrabajo.id = *pId;
                    *pId = *pId + 1;
                    tra[indice] = nuevoTrabajo;
                    *pFlag = 1;
                    todoOk = 1;
                }
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    return todoOk;
}

int buscarTrabajoLibre(eTrabajo vec[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(vec && tam > 0 && pIndex)
    {
        *pIndex = -1;
        for(int i = 0; i < tam; i++)
        {
            if(vec[i].isEmpty == 1)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int listarTrabajos(eTrabajo vec[], int tam, eServicio servicios[], int tamS)
{
    int todoOk = 0;
    int flag = 0;
    if(vec && tamS > 0 && tam > 0)
    {
        system("cls");
        printf("          *** Listado de Trabajos ***\n\n");
        printf(" Id     IdNotebook      IdServicio      fecha    \n");
        printf("--------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty )
            {
                mostrarTrabajos(vec[i], servicios, tam);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay trabajos en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int mostrarTrabajos(eTrabajo t, eServicio servicios[], int tam)
{
    int todoOk = 0;
    char descServicio[20];

    if(servicios && tam > 0){

    cargarDescripcionServicios(servicios, tam, t.idServicio, descServicio);

    printf("  %3d   %5d     %10d   %9d/%d/%d  \n",
           t.id,
           t.idNotebook,
           t.idServicio,
           t.fecha.dia,
           t.fecha.mes,
           t.fecha.anio
          );
        todoOk = 1;
    }
    return todoOk;
}

int cargarDescripcionServicios(eServicio servicios[], int tam, int id, char descripcion[]){
int todoOk = 0;

    if(servicios && tam > 0 && id >= 20000 && id <= 20003 && descripcion){
     for(int i=0; i < tam; i++){

        if(servicios[i].id == id){
            strcpy(descripcion, servicios[i].descripcion);
            break;
        }
     }
     todoOk = 1;
    }
  return todoOk;
}


int listarServicios(eServicio servicios[], int tamS){
int todoOk = 0;

    if(servicios && tamS > 0){
        system("cls");
        printf("   *** Lista de Servicios  ***\n");
        printf("  Id    Descripcion\n");
        printf("-----------------------\n");
        for(int i=0; i < tamS; i++){
            printf("   %3d    %10s\n", servicios[i].id, servicios[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}
