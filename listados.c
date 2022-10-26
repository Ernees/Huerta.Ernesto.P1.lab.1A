#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "listados.h"
#include "bicicletas.h"
#include "colores.h"
#include "tipos.h"

int listarBicisTipo(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
    int ret = 0;
    int idTipo;

    if(bicicletas != NULL && tipos != NULL && tam > 0 && tamT > 0 && colores!=NULL && tamC>0)
    {
        system("cls");
        printf("    ***LISTADO BICICLETAS DE UN TIPO***\n");

        mostrarTipo(tipos, tamT, 0);
        printf("ingrese id del tipo:\n");
        scanf("%d", &idTipo);

        while(!validarTipo(idTipo, tipos, tamT))
        {
            printf("Id invalida, reingrese id del Tipo\n");
            scanf("%d", &idTipo);
        }


        mostrarBicisTipo(idTipo, bicicletas, tam, tipos, tamT, colores, tamC);


        ret = 1;
    }

    return ret;
}



int mostrarBicisTipo(int idTipo, eBicicleta bicicletas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
    int ret = 0;
    int flag = 1;

    if(bicicletas != NULL && tipos != NULL && tam > 0 && tamT > 0 && colores!=NULL && tamC>0)
    {
        printf("Id              Marca               Tipo            Color        Material\n");
        printf("---------------------------------------------------------------------------\n");
        for(int i =0; i< tam; i++)
        {
            if(!bicicletas[i].isEmpty && bicicletas[i].idTipo == idTipo)
            {
                mostrarBici(bicicletas[i], colores, tamC, tipos, tamT);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No se ha registrado ninguna bicicleta de ese tipo\n");
        }
        printf("\n\n");


        ret = 1;
    }
    return ret;
}
int listarBicisColorTipo(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC)

{
    int ret = 0;
    int idColor;
    int idTipo;


    if(bicicletas != NULL && tipos != NULL && tam > 0 && tamT > 0 && colores!=NULL && tamC>0)
    {
        system("cls");
        printf("    ***LISTADO BICICLETAS DE UN COLOR Y UN TIPO***\n");

        mostrarColor(colores, tamC, 0);
        printf("ingrese id del Color:\n");
        scanf("%d", &idColor);

        while(!validarColor(idColor, colores, tamC))
        {
            printf("Id invalida, reingrese id del Color\n");
            scanf("%d", &idColor);
        }

        mostrarTipo(tipos, tamT, 0);
        printf("ingrese id del tipo:\n");
        scanf("%d", &idTipo);

        while(!validarTipo(idTipo, tipos, tamT))
        {
            printf("Id invalida, reingrese id del Tipo\n");
            scanf("%d", &idTipo);
        }


        mostrarBicisColorTipo(idColor, idTipo, bicicletas, tam, tipos, tamT, colores, tamC);


        ret = 1;
    }

    return ret;
}

int mostrarBicisColorTipo(int idColor, int idTipo, eBicicleta bicicletas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
    int ret = 0;
    int flag = 1;

    if(bicicletas != NULL && tipos != NULL && tam > 0 && tamT > 0 && colores!=NULL && tamC>0)
    {
        printf("Id              Marca               Tipo            Color        Material\n");
        printf("---------------------------------------------------------------------------\n");
        for(int i =0; i< tam; i++)
        {
            if(!bicicletas[i].isEmpty && bicicletas[i].idColor == idColor && bicicletas[i].idTipo == idTipo)
            {
                mostrarBici(bicicletas[i], colores, tamC, tipos, tamT);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No se ha registrado ninguna bicicleta de ese color y tipo\n");
        }
        printf("\n\n");


        ret = 1;
    }
    return ret;
}









int listarBicisColor(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
    int ret = 0;
    int idColor;

    if(bicicletas != NULL && tipos != NULL && tam > 0 && tamT > 0 && colores!=NULL && tamC>0)
    {
        system("cls");
        printf("    ***LISTADO BICICLETAS DE UN COLOR***\n");

        mostrarColor(colores, tamC, 0);
        printf("ingrese id del Color:\n");
        scanf("%d", &idColor);

        while(!validarColor(idColor, colores, tamC))
        {
            printf("Id invalida, reingrese id del Color\n");
            scanf("%d", &idColor);
        }


        mostrarBicisColor(idColor, bicicletas, tam, tipos, tamT, colores, tamC);


        ret = 1;
    }

    return ret;
}



int mostrarBicisColor(int idColor, eBicicleta bicicletas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
    int ret = 0;
    int flag = 1;

    if(bicicletas != NULL && tipos != NULL && tam > 0 && tamT > 0 && colores!=NULL && tamC>0)
    {
        printf("Id              Marca               Tipo            Color        Material\n");
        printf("---------------------------------------------------------------------------\n");
        for(int i =0; i< tam; i++)
        {
            if(!bicicletas[i].isEmpty && bicicletas[i].idColor == idColor)
            {
                mostrarBici(bicicletas[i], colores, tamC, tipos, tamT);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No se ha registrado ninguna bicicleta de ese color\n");
        }
        printf("\n\n");


        ret = 1;
    }
    return ret;
}


int listarBicisPorTipo(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
    int ret = 0;

    if(bicicletas != NULL && tipos != NULL && tam > 0 && tamT > 0 && colores!=NULL && tamC>0)
    {
        system("cls");
        printf("    ***LISTADO BICICLETAS POR TIPO***\n");

        for(int i =0; i < tamT; i++)
        {
            printf("tipo: %s\n", tipos[i].descripcion);

            mostrarBicisTipo(tipos[i].id, bicicletas, tam, tipos, tamT, colores, tamC);
        ret = 1;
        }
    }

    return ret;
}


int mostrarMayorCantMaterial(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
    int retorno=0;
    int contAluminio=0;
    int contCarbono=0;
    char material;


    if(bicicletas != NULL && tipos != NULL && tam > 0 && tamT > 0 && colores!=NULL && tamC>0)
    {
        for(int i =0; i < tam; i++)
        {
            if(!bicicletas[i].isEmpty && bicicletas[i].material == 'a')
            {
                contAluminio++;

            }
            else
            {
                contCarbono++;
            }
        }

        if(contAluminio<contCarbono)
        {
            material='c';
            printf("Hay mas Bicicletas de carbono: %d\n", contCarbono);
            mostrarBicisMaterial(material, bicicletas, tam, tipos, tamT, colores, tamC);


        }
        else
        {
            material='a';
            printf("Hay mas Bicicletas de Aluminio: %d\n", contAluminio);
            mostrarBicisMaterial(material, bicicletas, tam, tipos, tamT, colores, tamC);

        }
        retorno=1;
    }


    return retorno;
}

int mostrarBicisMaterial(char material, eBicicleta bicicletas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
    int ret = 0;
    int flag = 1;

    if(bicicletas != NULL && tipos != NULL && tam > 0 && tamT > 0 && colores!=NULL && tamC>0)
    {
        printf("Id              Marca               Tipo            Color        Material\n");
        printf("---------------------------------------------------------------------------\n");
        for(int i =0; i< tam; i++)
        {
            if(!bicicletas[i].isEmpty && bicicletas[i].material == material)
            {
                mostrarBici(bicicletas[i], colores, tamC, tipos, tamT);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No se ha registrado ninguna bicicleta de ese color\n");
        }
        printf("\n\n");


        ret = 1;
    }
    return ret;
}

int listarColorMasElegido(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
    int retorno=0;
    int idColor;
    int contGris=0;
    int contBlanco=0;
    int contAzul=0;
    int contNegro=0;
    int contRojo=0;

    if(bicicletas != NULL && tipos != NULL && tam > 0 && tamT > 0 && colores!=NULL && tamC>0)
    {
        for(int i =0; i < tam; i++)
        {
            if(!bicicletas[i].isEmpty)
            {
                switch(bicicletas[i].idColor)
                {
                    case 5000:
                        contGris++;
                        break;
                    case 5001:
                        contBlanco++;
                        break;
                    case 5002:
                        contAzul++;
                        break;
                    case 5003:
                        contNegro++;
                        break;
                    case 5004:
                        contRojo++;
                        break;
                }

            }
        }

        if(contGris>contBlanco && contGris> contAzul && contGris>contNegro && contGris>contRojo)
        {
            idColor=5000;
        }
        else{
            if(contBlanco>contAzul && contBlanco>contNegro && contBlanco>contRojo)
            {
                idColor=5001;
            }
            else{
                if(contAzul>contNegro && contAzul>contRojo)
                {
                    idColor=5002;
                }
                else{
                    if(contNegro>contRojo)
                    {
                        idColor=5003;
                    }
                    else{
                        idColor=5004;
                    }
                }
            }
        }

        mostrarColorMasElegido(idColor, bicicletas, tam, tipos, tamT, colores, tamC);

        retorno=1;
    }



    return retorno;
}
int mostrarColorMasElegido(int idColor, eBicicleta bicicletas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
    int ret = 0;
    int flag = 1;

    if(bicicletas != NULL && tipos != NULL && tam > 0 && tamT > 0 && colores!=NULL && tamC>0)
    {
        printf("Id              Marca               Tipo            Color        Material\n");
        printf("---------------------------------------------------------------------------\n");
        for(int i =0; i< tam; i++)
        {
            if(!bicicletas[i].isEmpty && bicicletas[i].idColor == idColor)
            {
                mostrarBici(bicicletas[i], colores, tamC, tipos, tamT);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No se ha registrado ninguna bicicleta de ese color\n");
        }
        printf("\n\n");


        ret = 1;
    }
    return ret;
}
