#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colores.h"
int mostrarColor(eColor vec[], int tam, int cls)
{
    int retorno=0;
    if(vec!=NULL && tam>0 && cls>=0 && cls<=1)
    {
        if(cls)
        {
          system("cls");
        }

        printf("     ***  LISTA DE COLORES  ***\n");
        printf("Id             Descripcion\n");
        printf("--------------------------\n");
        for(int i=0; i<tam; i++)
        {
            printf("%d   %20s\n", vec[i].id, vec[i].nombreColor);

        }

        retorno=1;
    }

    return retorno;
}
int inicializarColor(eColor vec[], int tam)
{
    int retorno=0;

    if(vec!=NULL && tam>0)
    {
        for(int i =0; i<tam; i++)
        {
            vec[i].isEmpty=1;

        }
        retorno=1;
    }


    return retorno;

}
int cargarDescripcionColor(int id, char descripcion[], eColor vec[], int tam)
{
    int retorno=0;
    if(descripcion!=NULL && vec!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(vec[i].id == id)
            {
             strcpy(descripcion, vec[i].nombreColor);
            }
        }

        retorno=1;
    }
    return retorno;
}
int hardcodearColores(int* pId, eColor vec[], int tam, int cant)
{
    int retorno=0;
    eColor almacenColores[] = {{5000, "Gris"},
                              {5001, "Blanco"},
                              {5002, "Azul"},
                              {5003, "Negro"},
                              {5004, "Rojo"}};

    if(vec != NULL && tam > 0 && cant <= tam && cant <= 5)
    {

        for(int i=0; i<cant; i++)
        {
            vec[i]= almacenColores[i];
            *pId = *pId + 1;
        }
        retorno=1;
    }
    return retorno;
}
int validarColor(int id, eColor color[], int tam)
{
    int retorno=0;
    if(color != NULL && tam>0 && id>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(color[i].id==id)
            {
                retorno=1;
                break;
            }
        }

    }

    return retorno;
}
