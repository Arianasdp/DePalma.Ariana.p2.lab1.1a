#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"

int cargarDescripcionClientes(eCliente clientes[], int tamC, int id, char nombre[])
{
    int todoOk = 0;

    if(clientes && tamC > 0 && id >= 6000 && id <= 6002 && nombre){
     for(int i=0; i < tamC; i++){

        if(clientes[i].id == id){
            strcpy(nombre, clientes[i].nombre);
            break;
        }
     }
     todoOk = 1;
    }
  return todoOk;
}

int listarClientes(eCliente clientes[], int tamC){
int todoOk = 0;

    if(clientes && tamC > 0){
        system("cls");
        printf("   *** Lista de Clientes  ***\n");
        printf("  Id    Nombre    Sexo \n");
        printf("-----------------------\n");
        for(int i=0; i < tamC; i++){
            printf("   %4d    %8s   %c\n", clientes[i].id, clientes[i].nombre, clientes[i].sexo);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}
