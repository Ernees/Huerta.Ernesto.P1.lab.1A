#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"
int validarTipo(int id, eTipo tipo[], int tam)
{
    int retorno=0;
    if(tipo != NULL && tam>0 && id>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(tipo[i].id==id)
            {
                retorno=1;
                break;
            }
        }

    }

    return retorno;
}

int mostrarTipo(eTipo vec[], int tam, int cls)
{
    int retorno=0;
    if(vec!=NULL && tam>0 && cls>=0 && cls<=1)
    {
        if(cls)
        {
          system("cls");
        }

        printf("     ***  LISTA DE TIPOS  ***\n");
        printf("Id             Descripcion\n");
        printf("--------------------------\n");
        for(int i=0; i<tam; i++)
        {
            printf("%d   %20s\n", vec[i].id, vec[i].descripcion);

        }

        retorno=1;
    }

    return retorno;
}
int hardcodearTipos(int* pId, eTipo vec[], int tam, int cant)
{
    int retorno=0;
    eTipo almacenTipos[] = {{1000, "Rutera"},
                            {1001, "Carrera"},
                            {1002, "Mountain"},
                            {1003, "BMX"}};

    if(vec != NULL && tam > 0 && cant <= tam && cant <= 4)
    {

        for(int i=0; i<cant; i++)
        {
            vec[i]= almacenTipos[i];
            *pId = *pId + 1;
        }
    }
    return retorno;
}
int inicializarTipo(eTipo vec[], int tam)
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
int cargarDescripcionTipo(int id, char descripcion[], eTipo vec[], int tam)
{
    int retorno=0;
    if(descripcion!=NULL && vec!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(vec[i].id == id)
            {
             strcpy(descripcion, vec[i].descripcion);
            }
        }

        retorno=1;
    }
    return retorno;
}
