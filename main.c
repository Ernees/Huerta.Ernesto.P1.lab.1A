#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "bicicletas.h"
#include "colores.h"
#include "tipos.h"
#include "trabajos.h"
#include "listados.h"


#define TAM 15
#define TAM_T 4
#define TAM_S 4
#define TAM_C 5
#define TAM_TRAB 20





int menu();
int confirmarSalida(char* pVariable, char confirma, char rechaza);

int main()
{

    int nextIdBici = 100;
    int nextIdColor = 5000;
    int nextIdTipo = 1000;
    int nextIdServicio = 20000;
    int nextIdTrabajo = 10000;
    int flag=1;

    char salir='n';

    eBicicleta bicicletas[TAM];
    eColor colores[TAM_C];
    eTipo tipos[TAM_T];
    eServicio servicicios[TAM_S];
    eTrabajo trabajos[TAM_TRAB];

    inicializarBicicletas(bicicletas, TAM);
    inicializarColor(colores, TAM_C);
    inicializarTipo(tipos, TAM_T);
    inicializarTrabajos(trabajos, TAM_TRAB);

    hardcodearBicicletas(&nextIdBici, bicicletas, TAM, 11);
    hardcodearServicios(&nextIdServicio, servicicios, TAM_T, 4);
    hardcodearColores(&nextIdColor, colores, TAM_C, 5);
    hardcodearTipos(&nextIdTipo, tipos, TAM_T, 4);



    do{
            switch(menu())
            {
                case 1:
                    if(!altaBicicleta(&nextIdBici, bicicletas, TAM, tipos, TAM_T, colores, TAM_C))//agregar salario y años de contrato

                    {
                        printf("no se pudo realizar el alta\n");
                    }
                    else
                    {
                        printf("alta exitosa\n");
                    }

                    break;
                case 2:

                    if(bicicletas->isEmpty==1)
                    {
                        printf("No hay bicicletas cargadas en el sistema\n");
                    }
                    else
                    {
                        modificarBicicletas(bicicletas, TAM, colores, TAM_C, tipos, TAM_T);
                    }
                    break;
                case 3:

                    if(bicicletas->isEmpty==1)
                    {
                        printf("No hay bicicletas cargadas en el sistema\n");
                    }
                    else
                    {
                        bajaBicicleta(bicicletas, colores, tipos, TAM_C, TAM_T, TAM);
                    }


                    break;
                case 4:
                    mostrarBicicletas(bicicletas, TAM, tipos, TAM_T, colores, TAM_C, 1);
                    break;
                case 5:
                    mostrarTipo(tipos, TAM_T, 1);
                    break;
                case 6:
                    mostrarColor(colores, TAM_C, 1);
                    break;
                case 7:
                    listarBicisColor(bicicletas, TAM, tipos, TAM_T, colores, TAM_C);
                    break;
                case 8:
                    listarBicisTipo(bicicletas, TAM, tipos, TAM_T, colores, TAM_C);
                    break;
                case 9:
                    listarBicisPorTipo(bicicletas, TAM, tipos, TAM_T, colores, TAM_C);
                    break;

                case 10:
                    mostrarMayorCantMaterial(bicicletas, TAM, tipos, TAM_T, colores, TAM_C);
                    break;


                case 11:
                    listarBicisColorTipo(bicicletas, TAM, tipos, TAM_T, colores, TAM_C);
                    break;

                case 12:
                    listarColorMasElegido(bicicletas, TAM, tipos, TAM_T, colores, TAM_C);
                    break;

                case 13:
                    mostrarServicios(servicicios, TAM_T);
                    break;
                case 14:
                    if(flag!=1)
                    {
                        printf("No hay bicicletas cargadas en el sistema\n");
                    }
                    else
                    {
                        flag=1;
                        altaTrabajo(&nextIdTrabajo, bicicletas, TAM, trabajos, TAM_TRAB, servicicios, TAM_S, tipos, TAM_T, colores, TAM_C,1);
                    }
                    break;
                case 15:
                    mostrarTrabajos(bicicletas, TAM, trabajos, TAM_TRAB, servicicios, TAM_S);
                    break;
                case 20:
                    confirmarSalida(&salir, 's', 'n');
                    break;
            }
            system("pause");
   }while(salir == 'n');

}

int menu()
{
    int opcion;
    system("cls");
    printf("    ***ABM BICICLETAS***\n");
    printf("1-Alta Bicicleta\n");
    printf("2-Modificar Bicicleta\n");
    printf("3-Baja Bicicleta\n");
    printf("4-Listar Bicicleta\n");
    printf("5-Listar Tipos\n");
    printf("6-Listar colores\n");


    printf("7-Listar Bicicletas de un color\n");

    printf("8-listar Bicicletas de un tipo\n");
    printf("9-listar Bicicletas por tipo\n");
    printf("10-Listar Bicicletas del material mas elegido\n");

    printf("11-Listar Bicicletas por color y tipo\n");
    printf("12-Listar color mas elegido\n");

    printf("13-Listar Servicios\n");
    printf("14-Alta Trabajo\n");
    printf("15-Listar Trabajos\n");
    printf("20-Salir\n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


int confirmarSalida(char* pVariable, char confirma, char rechaza)
{
    int ret = 0;
    char resp;
    if(pVariable != NULL)
    {
       printf("confirma salir?");
       fflush(stdin);
       resp = getchar();
       if(resp == 's')
       {
           *pVariable = confirma;
       }
       else
       {
           *pVariable = rechaza;
       }
        ret = 1;
    }

    return ret;
}



