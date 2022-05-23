#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"

int menu()
{
    int opcion;
    system("cls");
    printf("     *** ABM Notebooks ***\n");
    printf("1- Alta Notebook\n");
    printf("2- Modificar Notebook\n");
    printf("3- Baja Notebook\n");
    printf("4- Listar Notebooks\n");
    printf("5- Listar Marcas\n");
    printf("6- Listar Tipos\n");
    printf("7- Listar servicios\n");
    printf("8- Alta trabajo\n");
    printf("9- Listar trabajos\n");
    printf("10- Listar notebooks del tipo seleccionado por el usuario\n");
    printf("11- Listar notebooks de la marca seleccionada por el usuario\n");
    printf("12- Informar la/las notebook/s mas barata/s\n");
    printf("13- Listar notebooks por marca\n");
    printf("14- Listar notebooks del tipo y marca seleccionados por el usuario\n");
    printf("15- Informar la/las marca/s mas elegida/s por los clientes\n");
    printf("16- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;

}

void confirmarSalida(char* p)
{
    char confirma;

    printf("Confirma salida? s/n: ");
    fflush(stdin);
    scanf("%c", &confirma);

    *p = confirma;
}
