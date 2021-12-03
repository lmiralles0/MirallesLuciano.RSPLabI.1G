#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "get_Entrada.h"
#include "datos.h"
#include "controller.h"
#include <time.h>

int main()
{
    int opcion;
    char archivo[20];
    int flag = 0;
    int flagMapeado = 0;


    LinkedList* listaPost = ll_newLinkedList();
    LinkedList* listaPostSort = ll_newLinkedList();
    LinkedList* listaMasLikes = ll_newLinkedList();
    LinkedList* listaMenosLikes = ll_newLinkedList();

    if(listaPost == NULL && listaPostSort == NULL && listaMasLikes != NULL && listaMenosLikes != NULL)
    {
        printf("Error LinkedList no creado.\n");
        exit(EXIT_FAILURE);
    }
    do
    {
        printf("1).Cargar datos del archivo.\n");
        printf("2).Listar datos.\n");
        printf("3).Asignar estadisticas.\n");
        printf("4).Filtrar mejores posteos.\n");
        printf("5).Filtar por haters.\n");
        printf("6).Ordenar por cantidad de followers.\n");
        printf("7).Mostrar mas popular.\n");
        printf("8).Salir.\n");
        if(get_EntradaInt(&opcion, "Ingrese la opcion del menu.\n", "Error al ingresar opcion.\n", 8, 1, 5) == 0)
        {
            system("cls");
            switch(opcion)
            {
            case 1:
                printf("Ingrese el nombre del archivo.\n");
                fflush(stdin);
                scanf("%s", archivo);
                if(controller_loadFromText(archivo, listaPost) == 0)
                {
                    printf("\nArchivo cargado con exito.\n");
                    system("pause");
                    system("cls");
                    fflush(stdin);
                    flag = 1;
                }
                else
                {
                    printf("ERROR.\n");
                    system("pause");
                    system("cls");
                    fflush(stdin);
                }
                break;
            case 2:
                if(flag == 1 && flagMapeado == 1)
                {
                    ePost_Prints(listaPost);
                    system("pause");
                    system("cls");
                }
                else
                {
                    printf("No se cargo archivo, ni estadistica.\n");
                    system("pause");
                    system("cls");
                }
                break;
            case 3:
                if(flag == 1)
                {
                    listaPost = ll_map(listaPost, randomLikes);
                    listaPost = ll_map(listaPost, randomDislikes);
                    listaPost = ll_map(listaPost, randomFollowers);
                    ePost_Prints(listaPost);
                    flagMapeado = 1;
                    system("pause");
                    system("cls");
                }
                else
                {
                    printf("No se cargo archivo.\n");
                    system("pause");
                    system("cls");
                }
                break;
            case 4:
                if(flag == 1 && flagMapeado == 1)
                {
                    listaMasLikes = ll_filter(listaPost, filterMejoresPosteos);
                    ePost_Prints(listaMasLikes);
                    controller_saveAsText("post+.txt", listaMasLikes);
                }
                else
                {
                    printf("No se cargo archivo, ni estadisticas.\n");
                    system("pause");
                    system("cls");
                }
                break;
            case 5:
                if(flag == 1 && flagMapeado == 1)
                {
                    listaMenosLikes = ll_filter(listaPost, filterPeorPosteos);
                    controller_saveAsText("post-.txt", listaMenosLikes);
                }
                break;
            case 6:
                if(flag == 1 && flagMapeado == 1)
                {
                    listaPostSort= ll_clone(listaPost);
                    ll_sort(listaPostSort, comparePost, 0);
                    ePost_Prints(listaPostSort);
                    system("pause");
                    system("cls");
                }
                else
                {
                    printf("No se cargo archivo, ni estadisticas.\n");
                    system("pause");
                    system("cls");
                }
                break;
            case 7:
                break;
            }
        }

    }while (opcion != 8);

    return 0;
}
