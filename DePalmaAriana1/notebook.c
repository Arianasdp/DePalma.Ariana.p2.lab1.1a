#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "notebook.h"
#include "validaciones.h"

int inicializarNotebooks(eNotebook vec[], int tam)
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

int hardcodearNotebooks(eNotebook vec[], int tam, int cant, int* pId)
{
    int todoOk = 0;
    eNotebook impostores[] =
    {
        {100, "modelo4", 100000, 1001, 5000, 6001,0},
        {101, "modelo1", 120000, 1003, 5003, 6002,0},
        {102, "modelo3", 80000, 1000, 5001, 6000,0}
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

int altaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC, int* pId, int* pFlag)
{
    int todoOk = 0;
    int indice;
    char auxCad[100];
    eNotebook nuevaNotebook;

    if(vec != NULL && tam > 0 && pId && marcas != NULL && tipos != NULL && tamM > 0 && tamT > 0)
    {
        if(buscarNotebookLibre(vec, tam, &indice))
        {

            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                printf("Ingrese el nombre del modelo de la notebook: ");
                fflush(stdin);
                gets(auxCad);

                while(strlen(auxCad) >= 20)
                {
                    printf("Nombre demasiado largo. Reingrese nombre: ");
                    fflush(stdin);
                    gets(auxCad);
                }
                strcpy(nuevaNotebook.modelo, auxCad);

                printf("Ingrese precio: ");
                scanf("%f", &nuevaNotebook.precio);

                while(nuevaNotebook.precio <= 0)
                {
                   printf("Error. Ingrese precio valido: ");
                   scanf("%f", &nuevaNotebook.precio);
                }

                listarMarcas(marcas, tamM);

                printf("Ingrese Id Marca: ");
                scanf("%d", &nuevaNotebook.idMarca);

                while(!validarMarcas(marcas, tamM, nuevaNotebook.idMarca))
                {
                    printf("Marca invalida. Ingrese Id Marca: ");
                    scanf("%d", &nuevaNotebook.idMarca);
                }

                 listarTipos(tipos, tamT);

                printf("Ingrese Id Tipo: ");
                scanf("%d", &nuevaNotebook.idTipo);

                while(!validarTipos(tipos, tamT, nuevaNotebook.idTipo))
                {
                    printf("Tipo invalido. Ingrese Id Tipo: ");
                    scanf("%d", &nuevaNotebook.idTipo);
                }

                listarClientes(clientes, tamC);

                printf("Ingrese Id cliente: ");
                scanf("%d", &nuevaNotebook.idCliente);

                while(!validarClientes(clientes, tam, nuevaNotebook.idCliente))
                {
                    printf("Cliente invalido. Ingrese Id Cliente: ");
                    scanf("%d", &nuevaNotebook.idCliente);
                }

                nuevaNotebook.isEmpty = 0;
                nuevaNotebook.id = *pId;
                *pId = *pId + 1;
                vec[indice] = nuevaNotebook;
                *pFlag = 1;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }
    return todoOk;
}

int buscarNotebookLibre(eNotebook vec[], int tam, int* pIndex)
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

int listarMarcas(eMarca marcas[], int tam){
int todoOk = 0;

    if(marcas && tam > 0){
        system("cls");
        printf("   *** Lista de Marcas  ***\n");
        printf("  Id    Descripcion\n");
        printf("-----------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d    %10s\n", marcas[i].id, marcas[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}

int listarTipos(eTipo tipos[], int tam){
int todoOk = 0;

    if(tipos && tam > 0){
        system("cls");
        printf("   *** Lista de Tipos  ***\n");
        printf("  Id    Descripcion\n");
        printf("-----------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d    %10s\n", tipos[i].id, tipos[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}

int listarNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC)
{
    int todoOk = 0;
    int flag = 0;
    if(vec && tam > 0 && marcas && tamM > 0 && tipos && tamT > 0 && clientes && tamC > 0)
    {
        system("cls");
        printf("          *** Listado de Notebooks ***\n\n");
        printf(" Id     Modelo      Precio        Marca       Tipo            Cliente\n");
        printf("---------------------------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty )
            {
                mostrarNotebook(vec[i], marcas, tipos, tamM, tamT, clientes, tamC);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay notebooks en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int mostrarNotebook(eNotebook n, eMarca marcas[], eTipo tipos[], int tamM, int tamT, eCliente clientes[], int tamC)
{
    int todoOk = 0;
    char descMarca[20];
    char descTipo[20];
    char nombreCliente[20];

    if(marcas && tipos && tamM > 0 && tamT > 0 && clientes && tamC > 0){

    cargarDescripcionMarcas(marcas, tamM, n.idMarca, descMarca);
    cargarDescripcionTipos(tipos, tamT, n.idTipo, descTipo);
    cargarDescripcionClientes(clientes, tamC, n.idCliente, nombreCliente);

    printf("  %3d   %8s     %9.2f     %5s    %4s   %8s\n",
           n.id,
           n.modelo,
           n.precio,
           descMarca,
           descTipo,
           nombreCliente
          );
        todoOk = 1;
    }
    return todoOk;
}


int cargarDescripcionMarcas(eMarca marcas[], int tam, int id, char descripcion[]){
int todoOk = 0;

    if(marcas && tam > 0 && id >= 1000 && id <= 1003 && descripcion){
     for(int i=0; i < tam; i++){

        if(marcas[i].id == id){
            strcpy(descripcion, marcas[i].descripcion);
            break;
        }
     }
     todoOk = 1;
    }
  return todoOk;
}

int cargarDescripcionTipos(eTipo tipos[], int tam, int id, char descripcion[]){
int todoOk = 0;

    if(tipos && tam > 0 && id >= 5000 && id <= 5003 && descripcion){
     for(int i=0; i < tam; i++){

        if(tipos[i].id == id){
            strcpy(descripcion, tipos[i].descripcion);
            break;
        }
     }
     todoOk = 1;
    }
  return todoOk;
}

int buscarNotebook(eNotebook vec[], int tam,int id, int* pIndex)
{
    int todoOk = 0;
    if(vec && tam > 0 && pIndex && id > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty == 0 &&  vec[i].id == id )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int ordenarNotebooksPorMarcaYPrecio(eNotebook vec[], int tam)
{
    int todoOk = 0;
    eNotebook auxNotebook;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                if( ((vec[i].idMarca == vec[j].idMarca) &&  (vec[i].precio > vec[j].precio))
                        || ((vec[i].idMarca != vec[j].idMarca) &&(vec[i].idMarca > vec[j].idMarca) ))
                {
                    auxNotebook = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxNotebook;
                }

            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int menuModificarNotebook()
{
    int opcion;
    printf("     *** Campos a modificar ***\n");
    printf("1- Marca\n");
    printf("2- Tipo\n");
    printf("3- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int modificarNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC)
{
    int todoOk = 0;
    int indice;
    int id;
    char salir = 'n';
    char descMarca[20];
    char descTipo[20];

    if(vec && tam > 0)
    {
        listarNotebooks(vec, tam, marcas, tamM, tipos, tamT, clientes, tamC);
        printf("Ingrese id: ");
        scanf("%d", &id);
        if( buscarNotebook(vec, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay una notebook con id %d\n", id);
            }
            else
            {
                mostrarNotebook(vec[indice], marcas, tipos, tamM, tamT, clientes, tamC);


                do
                {
                    switch(menuModificarNotebook())
                    {
                    case 1:
                        listarMarcas(marcas, tamM);
                        cargarDescripcionMarcas(marcas, tamM, id, descMarca);
                        printf("Ingrese id de nueva marca: ");
                        scanf("%d", &vec[indice].idMarca);
                        printf("Se ha modificado la marca\n");
                        break;
                    case 2:
                        listarTipos(tipos, tamT);
                        cargarDescripcionTipos(tipos, tamT, id, descTipo);
                        printf("Ingrese id de nuevo tipo: ");
                        scanf("%d", &vec[indice].idTipo);
                        printf("Se ha modificado el tipo\n");
                        break;
                    case 3:
                        salir = 's';
                        break;
                    }
                    system("pause");
                }
                while(salir != 's');
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar la notebook\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int bajaNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if(vec && tam > 0)
    {
        listarNotebooks(vec, tam, marcas, tamM, tipos, tamT, clientes, tamC);
        printf("Ingrese id: ");
        scanf("%d", &id);
        if( buscarNotebook(vec, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay una notebook con id %d\n", id);
            }
            else
            {
                mostrarNotebook(vec[indice], marcas, tipos, tamM, tamT, clientes, tamC);
                printf("Confirma baja?(s/n): ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma != 'S' && confirma != 's')
                {
                    printf("Baja cancelada por el usuario\n");
                }
                else
                {
                    vec[indice].isEmpty = 1;
                    printf("Baja realizada con exito\n");
                    todoOk = 1;
                }
            }

        }
        else
        {
            printf("Ocurrio un problema al buscar notebook\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int listarNotebooksSegunTipoSeleccionado(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC)
{
    int todoOk = 0;
    int idTipo;

    if(vec != NULL && tipos != NULL && tam > 0 && tamT > 0 && marcas != NULL && clientes != NULL && tamM > 0 && tamC > 0)
    {


        listarTipos(tipos, tamT);

        printf("Ingrese Id tipo: ");
        scanf("%d", &idTipo);

        while(!validarTipos(tipos, tamT, idTipo))
        {
            printf("Tipo invalido. Ingrese Id Tipo: ");
            scanf("%d", &idTipo);
        }

        system("cls");
        printf("   *** Listado de notebooks con idTipo %d ***\n", idTipo);
        printf("---------------------------------------------\n");
        printf(" Id     Modelo      Precio        Marca       Tipo            Cliente\n");
        printf("---------------------------------------------------------------------\n");

         for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty && vec[i].idTipo == idTipo)
            {
                mostrarNotebook(vec[i], marcas, tipos, tamM, tamT, clientes, tamC);
            }
        }


        todoOk = 1;
    }
    return todoOk;
}

int listarNotebooksSegunMarcaSeleccionada(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC)
{
    int todoOk = 0;
    int idMarca;

    if(vec != NULL && tipos != NULL && tam > 0 && tamT > 0 && marcas != NULL && clientes != NULL && tamM > 0 && tamC > 0)
    {

        listarMarcas(marcas, tamM);

        printf("Ingrese Id Marca: ");
        scanf("%d", &idMarca);

        while(!validarMarcas(marcas, tamM, idMarca))
        {
            printf("Marca invalida. Ingrese Id Marca: ");
            scanf("%d", &idMarca);
        }

        system("cls");
        printf("   *** Listado de notebooks con idMarca %d ***\n", idMarca);
        printf("---------------------------------------------\n");
        printf(" Id     Modelo      Precio        Marca       Tipo            Cliente\n");
        printf("---------------------------------------------------------------------\n");

         for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty && vec[i].idMarca == idMarca)
            {
                mostrarNotebook(vec[i], marcas, tipos, tamM, tamT, clientes, tamC);
            }
        }


        todoOk = 1;
    }
    return todoOk;
}

int informarNotebookMasBarata(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC)
{
    int todoOk = 0;
    int masBarata;
    int flag = 0;

    if(vec != NULL && tam > 0 )
    {

        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty && (vec[i].precio < masBarata || !flag)  )
            {
                masBarata = vec[i].precio;
                flag = 1;
            }
        }

        system("cls");
        printf("              *** Informe Notebook mas barata ***\n");
        printf("---------------------------------------------------------------------\n");

        printf(" Id     Modelo      Precio        Marca       Tipo            Cliente\n");
        printf("---------------------------------------------------------------------\n");

        if(flag == 0)
        {
            printf("No hay Notebooks cargadas en el sistema\n\n");
        }
        else
        {

            for(int i=0; i < tam; i++)
            {
                if( !vec[i].isEmpty && vec[i].precio == masBarata)
                {
                     mostrarNotebook(vec[i], marcas, tipos, tamM, tamT, clientes, tamC);
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}

int informarNotebooksXMarca(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC)
{
    int todoOk = 0;
    int flag;

    if(vec != NULL && marcas != NULL && tipos != NULL && clientes != NULL && tam > 0 && tamM > 0 && tamT > 0 && tamC > 0)
    {
        system("cls");
        printf("    *** Listado de Notebooks por Marca  ***\n");
        printf("-----------------------------------------------------\n");

        for(int m = 0; m < tamM; m++)
        {
            printf("Marca: %s\n\n", marcas[m].descripcion);
            printf(" Id     Modelo      Precio        Marca       Tipo            Cliente\n");
            printf("---------------------------------------------------------------------\n");

            flag = 1;
            for(int e = 0; e < tam; e++)
            {
                if( !vec[e].isEmpty && vec[e].idMarca == marcas[m].id)
                {
                    mostrarNotebook(vec[e], marcas, tipos, tamM, tamT, clientes, tamC);
                    flag = 0;
                }
            }
            if(flag)
            {
                printf("No hay notebooks\n");
            }
            printf("\n\n");

        }
        todoOk = 1;
    }
    return todoOk;
}

int listarNotebooksSegunTipoYMarcaSeleccionados(eNotebook vec[], int tam, eMarca marcas[], int tamM, eTipo tipos[], int tamT, eCliente clientes[], int tamC)
{
     int todoOk = 0;
     int idTipo;
     int idMarca;

    if(vec != NULL && tipos != NULL && tam > 0 && tamT > 0 && marcas != NULL && clientes != NULL && tamM > 0 && tamC > 0)
    {

        listarTipos(tipos, tamT);

        printf("Ingrese Id tipo: ");
        scanf("%d", &idTipo);

        while(!validarTipos(tipos, tamT, idTipo))
        {
            printf("Tipo invalido. Ingrese Id Tipo: ");
            scanf("%d", &idTipo);
        }

        listarMarcas(marcas, tamM);

        printf("Ingrese Id Marca: ");
        scanf("%d", &idMarca);

        while(!validarMarcas(marcas, tamM, idMarca))
        {
            printf("Marca invalida. Ingrese Id Marca: ");
            scanf("%d", &idMarca);
        }

        system("cls");
        printf("   *** Listado de notebooks con idTipo %d y idMarca %d ***\n", idTipo, idMarca);
        printf("---------------------------------------------\n");
        printf(" Id     Modelo      Precio        Marca       Tipo            Cliente\n");
        printf("---------------------------------------------------------------------\n");

         for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty && vec[i].idTipo == idTipo && vec[i].idMarca == idMarca)
            {
                mostrarNotebook(vec[i], marcas, tipos, tamM, tamT, clientes, tamC);
            }
        }

        todoOk = 1;
    }
    return todoOk;
}

int marcaMasElegida(eNotebook vec[], int tam,eMarca marcas[], int tamM){
int todoOk = 0;
int contadorMarcas[tamM];
int masElegida;
int flag = 1;

   if(vec != NULL && marcas != NULL && tam > 0 && tamM > 0)
    {
        system("cls");
        printf("   *** Marca mas elegida ***\n");
        printf("---------------------------------------------------\n");

        for(int i=0; i < tamM; i++){
            contadorMarcas[i] = 0;
        }

        for(int m = 0; m < tamM; m++){
            for(int e = 0; e < tam; e++){
                if(!vec[e].isEmpty && vec[e].idMarca == marcas[m].id){
                    contadorMarcas[m]++;
                }
            }
        }

        for(int m = 0; m < tamM; m++){
            if(flag || contadorMarcas[m] > masElegida){
                masElegida = contadorMarcas[m];
                flag = 0;
            }
        }

        printf("La/s marca/s mas elegida/s es/son: ");
          for(int m = 0; m < tamM; m++){
            if(contadorMarcas[m] == masElegida){
                printf("%s\n", marcas[m].descripcion);
            }
        }
      todoOk = 1;
    }
    return todoOk;
}

