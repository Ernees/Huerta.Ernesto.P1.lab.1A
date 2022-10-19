#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "bicicletas.h"
#include "colores.h"
#include "tipos.h"

#define TAM 20
#define TAM_T 4
#define TAM_C 5


int menu();
int confirmarSalida(char* pVariable, char confirma, char rechaza);

int main()
{

    int nextIdBici = 100;
    int nextIdColor = 5000;
    int nextIdTipo = 1000;
    int flag=0;

    char salir='n';

    eBicicleta bicicletas[TAM];
    eColor colores[TAM_C];
    eTipo tipos[TAM_T];


    inicializarBicicletas(bicicletas, TAM);
    inicializarColor(colores, TAM_C);
    inicializarTipo(tipos, TAM_T);

    //hardcodearBicicletas(&nextIdBici, bicicletas, TAM, 5);
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
                    flag=1;
                    break;
                case 2:
                    if(flag)
                    {
                        modificarBicicletas(bicicletas, TAM, colores, TAM_C, tipos, TAM_T);

                    }
                    else
                    {
                        printf("No hay bicicletas cargadas en el sistema\n");
                    }
                    break;
                case 3:
                    if(flag)
                    {
                        bajaBicicleta(bicicletas, colores, tipos, TAM_C, TAM_T, TAM, &flag);
                    }
                    else
                    {
                        printf("No hay bicicletas cargadas en el sistema\n");
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
    printf("    **ABM BICICLETAS\n");
    printf("1-Alta Bicicleta\n");
    printf("2-Modificar Bicicleta\n");
    printf("3-Baja Bicicleta\n");
    printf("4-Listar Bicicleta\n");
    printf("5-Listar tipos\n");
    printf("6-Listar colores\n");

    printf("7-salir\n");
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
