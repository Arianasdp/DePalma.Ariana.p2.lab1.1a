#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "notebook.h"
#include "trabajo.h"
#include "validaciones.h"
#include "menu.h"

#define TAM 5
#define TAM_M 4
#define TAM_T 4
#define TAM_S 4
#define TAMC 3


int main()
{
    char salir = 'n';
    int proximoId = 100;
    int proximoIdT = 800;
    int flagAlta = 0;
    int flagAltaTra = 0;
    eNotebook lista[TAM];
    eTrabajo listaT[TAM];
    eMarca marcas[TAM_M] ={
        {1000, "Compaq"},
        {1001, "Asus"},
        {1002, "Acer"},
        {1003, "HP"}
        };
    eTipo tipos[TAM_T] ={
        {5000, "Gamer"},
        {5001, "Disenio"},
        {5002, "Ultrabook"},
        {5003, "Normalita"}
        };
    eServicio servicios[TAM_S] = {
    {20000, "Bateria", 2250},
    {20001, "Display", 1030},
    {20002, "Mantenimiento", 4400},
    {20003, "Fuente", 5600}
    };
    eCliente clientes[TAMC] = {
    {6000, "Marcos", 'm'},
    {6001, "Azul", 'f'},
    {6002, "Teo", 'm'}
    };

    inicializarNotebooks(lista, TAM);
    hardcodearNotebooks(lista, TAM, 2, &proximoId);

    inicializarTrabajos(listaT, TAM);
    printf("%d \n", lista->isEmpty);
    hardcodearTrabajos(listaT, TAM, 2, &proximoIdT);

    do{
            switch(menu())
        {
            case 1:
                 if(altaNotebook(lista, TAM, marcas, TAM_M, tipos, TAM_T, clientes, TAMC, &proximoId, &flagAlta))
                 {
                    printf("Notebook agregada con exito\n");
                 }
                 else
                 {
                     printf("Problema al hacer el alta de Notebook\n");
                 }
                break;
            case 2:
                if(flagAlta)
                {
                    if(modificarNotebook(lista, TAM, marcas, TAM_M, tipos, TAM_T, clientes, TAMC) == 0)
                    {
                        printf("Problema al hacer la modificacion de la Notebook\n");
                    }
                }
                else
                {
                    printf("No puede realizar una modificacion sin antes haber ingresado al menos una notebook\n");
                }
                break;
            case 3:
                if(flagAlta)
                {
                    if(bajaNotebooks(lista, TAM, marcas, TAM_M, tipos, TAM_T, clientes, TAMC) == 0)
                    {
                        printf("Problema al hacer la baja de la notebook\n");
                    }
                }
                else
                {
                    printf("No se puede realizar una baja si no se ha dado de alta ninguna notebook\n");
                }
                break;
            case 4:
                if(flagAlta)
                {
                    ordenarNotebooksPorMarcaYPrecio(lista, TAM);
                    listarNotebooks(lista, TAM, marcas, TAM_M, tipos, TAM_T, clientes, TAMC);
                }
                else
                {
                    printf("No se pueden listar las notebooks cuando no hay notebooks para mostrar, realice un alta primero\n");
                }
                break;
            case 5:
                listarMarcas(marcas, TAM_M);
                break;
            case 6:
                listarTipos(tipos, TAM_T);
                break;
            case 7:
                listarServicios(servicios, TAM_S);
                break;
            case 8:
                if(flagAlta)
                {
                    altaTrabajo(listaT, TAM, servicios, TAM_S, &proximoIdT, lista, TAM, marcas, TAM_M, tipos, TAM_T, clientes, TAMC, &flagAltaTra);
                }
                else
                {
                    printf("Para realizar un trabajo debe tener primero una notebook con la que trabajar\n");
                }
                break;
            case 9:
                if(flagAltaTra)
                {
                   listarTrabajos(listaT, TAM, servicios, TAM_S);
                }
                else
                {
                    printf("Realice un alta primero\n");
                }
                break;
            case 10:
                if(flagAlta)
                {
                   listarNotebooksSegunTipoSeleccionado(lista, TAM, marcas, TAM_M, tipos, TAM_T, clientes, TAMC);
                }
                else
                {
                    printf("Realice un alta primero\n");
                }
                break;
            case 11:
                if(flagAlta)
                {
                   listarNotebooksSegunMarcaSeleccionada(lista, TAM, marcas, TAM_M, tipos, TAM_T, clientes, TAMC);
                }
                else
                {
                    printf("Realice un alta primero\n");
                }
                break;
            case 12:
                 if(flagAlta)
                {
                   informarNotebookMasBarata(lista, TAM, marcas, TAM_M, tipos, TAM_T, clientes, TAMC);
                }
                else
                {
                    printf("Realice un alta primero\n");
                }
                break;
            case 13:
                 if(flagAlta)
                {
                   informarNotebooksXMarca(lista, TAM, marcas, TAM_M, tipos, TAM_T, clientes, TAMC);
                }
                else
                {
                    printf("Realice un alta primero\n");
                }
                break;
            case 14:
                if(flagAlta)
                {
                   listarNotebooksSegunTipoYMarcaSeleccionados(lista, TAM, marcas, TAM_M, tipos, TAM_T, clientes, TAMC);
                }
                else
                {
                    printf("Realice un alta primero\n");
                }
                break;
            case 15:
                if(flagAlta)
                {
                   marcaMasElegida(lista, TAM, marcas, TAM_M);
                }
                else
                {
                    printf("Realice un alta primero\n");
                }
                break;
            case 16:
                confirmarSalida(&salir);
                break;
            default:
            printf("Opcion invalida\n\n");
            fflush(stdin);
        }
        system("pause");
    }
    while(salir != 's');
    return 0;
}
