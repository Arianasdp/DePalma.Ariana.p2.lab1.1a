#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "validaciones.h"
#include "trabajo.h"
#include "notebook.h"

eFecha validarFecha(eFecha unaFecha)
{
    while((unaFecha.anio < 1990 || unaFecha.anio > 2022)
          || (unaFecha.mes < 1 || unaFecha.mes > 12)
          || (unaFecha.dia < 1 || unaFecha.dia > 31)
          || (unaFecha.anio % 4 == 0 && unaFecha.mes == 2 && unaFecha.dia > 29)
          || (unaFecha.anio % 4 != 0 && unaFecha.mes == 2 && unaFecha.dia > 28))
    {
        printf("Error, reingrese fecha: ");
        scanf("%d/%d/%d", &unaFecha.dia, &unaFecha.mes, &unaFecha.anio);
    }

    return unaFecha;
}

int validarMarcas(eMarca marcas[], int tam, int id){
    int esValido = 0;
    int indice;

    buscarMarcas(marcas, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}

int validarTipos(eTipo tipos[], int tam, int id){
    int esValido = 0;
    int indice;

    buscarTipos(tipos, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}

int buscarMarcas(eMarca marcas[], int tam, int id, int* pIndice){
    int todoOk = 0;
    if(marcas && tam > 0 && pIndice){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(marcas[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}

int buscarTipos(eTipo tipos[], int tam, int id, int* pIndice){
    int todoOk = 0;
    if(tipos && tam > 0 && pIndice){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(tipos[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}

int validarServicios(eServicio servicios[], int tam, int id){
    int esValido = 0;
    int indice;

    buscarServicios(servicios, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}

int buscarServicios(eServicio servicios[], int tam, int id, int* pIndice){
    int todoOk = 0;
    if(servicios && tam > 0 && pIndice){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(servicios[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}

int validarClientes(eCliente clientes[], int tam, int id){
    int esValido = 0;
    int indice;

    buscarClientes(clientes, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}

int buscarClientes(eCliente clientes[], int tam, int id, int* pIndice){
    int todoOk = 0;
    if(clientes && tam > 0 && pIndice){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(clientes[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}
