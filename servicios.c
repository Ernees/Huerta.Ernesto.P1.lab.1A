#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicios.h"

int mostrarServicios(eServicio servicios[], int tam)
{
    int ret = 0;

    if(servicios != NULL && tam > 0)
    {
        system("cls");
        printf("             **LISTA DE SERVICIOS***\n");
        printf("\n");
        printf("id            Descripcion          Precio\n");
        printf("------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            printf("%d %20s %15.2f\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
        }

        ret = 1;
    }
    return ret;
}

int hardcodearServicios(int* pId, eServicio vec[], int tam, int cant)
{
    int retorno=0;
    eServicio almacenServicios[] = {{20000, "Limpieza", 30},
                                    {20001, "Parche", 400},
                                    {20002, "Centrado", 500},
                                    {20003, "Cadena", 450}};

    if(vec != NULL && tam > 0 && cant <= tam && cant <= 4)
    {

        for(int i=0; i<cant; i++)
        {
            vec[i]= almacenServicios[i];
            *pId = *pId + 1;
        }
        retorno=1;
    }
    return retorno;
}





int validarIdServicios(int id, eServicio vec[], int tam)
{
    int retorno=0;
    if(vec != NULL && tam>0 && id>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(vec[i].id==id)
            {
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}


int cargarDescripcionServicio(int id, char descripcion[], eServicio servicios[], int tam)
{
    int ret = 0;
    if(descripcion != NULL && servicios != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(servicios[i].id == id)
            {
                strcpy(descripcion, servicios[i].descripcion);
                break;
            }
        }

        ret = 1;
    }

    return ret;
}
