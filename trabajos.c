#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trabajos.h"
#include "bicicletas.h"
#include "servicios.h"


int altaTrabajo(int* pId, eBicicleta vec[], int tam, eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamS, eTipo tipo[], int tamT, eColor color[], int tamC, int cls)
{
    int ret = 0;
    int indice;
    int indiceBici;
    int auxIdBici;
    char confirma;
    eTrabajo auxTrabajo;

    if(pId != NULL && vec != NULL && tam > 0 && trabajos != NULL && tamTra > 0 && servicios != NULL && tamS > 0&& tipo!=NULL && tamT>0 && color!=NULL && tamC>0)
    {
        //system("cls");
        printf("            **ALTA TRABAJO**\n");

        mostrarBicicletas(vec, tam, tipo, tamT, color, tamC, 1);
        printf("ingrese Id de la bicicleta que recibira el servicio:\n");
//&auxTrabajo.idBicicleta
        scanf("%d", &auxIdBici);

        while(!validarIdBici(auxIdBici, vec, tam))
        {
            printf("Id invalida, reingrese id de la Bicicleta\n");
            scanf("%d", &auxIdBici);
        }

        buscarBici(&indiceBici, auxIdBici, vec, tam);


        buscarLibreTrabajo(&indice, trabajos, tamTra);

        if(indice == -1 || indiceBici ==-1)
        {
            printf("Ocurrio un error\n");
        }
        else
        {
            mostrarBiciConfirmacion(vec[indiceBici], color, tamC, tipo, tamT);

            printf("Confirma el servicio?: ");
            fflush(stdin);
            confirma=getchar();

            while(!validarConfirmacion(confirma))
            {
                printf("Respuestas invalida. Confirma el servicio?: ");
                fflush(stdin);
                confirma=getchar();

            }

            if(confirma=='s')
            {
                vec[indice].isEmpty=1;
                mostrarServicios(servicios, tamS);
                printf("ingrese Id del Servicio:\n");
                scanf("%d", &auxTrabajo.idServicio);

                while(!validarIdServicios(auxTrabajo.idServicio, servicios, tamS))
                {
                    printf("Id invalida, reingrese id de la Bicicleta\n");
                    scanf("%d", &auxTrabajo.idServicio);
                }


                printf("ingrese fecha de Servicio(dd/mm/aaaa):\n");
                scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);

                printf("Trabajo dado de alta con exito!!!\n");
            }
            else
            {
                printf("Se ha cancelado el Trabajo\n");
            }


            auxTrabajo.isEmpty = 0;

            auxTrabajo.id = *pId;

            auxTrabajo.idBicicleta=auxIdBici;

            trabajos[indice] = auxTrabajo;


            (*pId)++;

        }
        ret = 1;
    }
    return ret;
}

int buscarLibreTrabajo(int* pIndice, eTrabajo vec[], int tam)
{
    int ret = 0;
    int indice = -1;

    if(pIndice != NULL && vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(vec[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
        *pIndice = indice;
        ret = 1;
    }
    return ret;
}

void mostrarTrabajo(eTrabajo trabajo, eBicicleta vec[], int tam, eServicio servicios[], int tamS)
{
    char descripcionServicio[20];
    char marca[20];

    for(int i = 0; i<tam; i++)
    {
        if(vec[i].id == trabajo.idBicicleta && !vec[i].isEmpty)
        {
            strcpy(marca, vec[i].marca);
            break;
        }
    }


    cargarDescripcionServicio(trabajo.idServicio, descripcionServicio, servicios, tamS);
    printf("%d%14s    %15s      %02d/%02d/%d\n", trabajo.id, marca, descripcionServicio, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);
}

int mostrarTrabajos(eBicicleta vec[], int tam, eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamS)
{
    int ret = 0;
    int flag = 1;

    if(vec != NULL && tam > 0)//VALIDAR
    {

        system("cls");
        printf("         *** TRABAJOS BICICLETAS *** \n");
        printf("id            Marca          Servicio         Fecha\n");
        printf("----------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(!trabajos[i].isEmpty)
            {

                mostrarTrabajo(trabajos[i], vec, tam, servicios, tamS);
                flag = 0;
            }
        }

        if(flag)
        {
            printf("no hay Trabajos en el sistema\n");
        }

        ret = 1;
    }
    return ret;
}



int inicializarTrabajos(eTrabajo vec[], int tam)
{
    int ret = 0;

    if(vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        ret = 1;
    }
    return ret;
}
