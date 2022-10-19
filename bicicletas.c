#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bicicletas.h"

int bajaBicicleta(eBicicleta vec[], eColor colores[], eTipo tipos[], int tamC, int tamT, int tam, int* pFlag)
{
    int retorno=0;
    int id;
    int indice;
    char confirma;

    if(vec!=NULL && tam>0)
    {
        system("cls");
        printf("      *** BAJA ALUMNO ***     \n");

        mostrarBicicletas(vec, tam, tipos, tamT, colores, tamC, 1);

        printf("Ingrese el id de la bicicleta a dar de baja: ");
        scanf("%d", &id);

        buscarBici(&indice, id, vec, tam);
        if(indice==-1)
        {
            printf("No existe una bici con id : %d\n", id);
        }
        else
        {

            mostrarBiciConfirmacion(vec[indice], colores, tamC, tipos, tamT);

            printf("Confirma baja?: ");
            fflush(stdin);
            confirma=getchar();

            while(!validarConfirmacion(confirma))
            {
                printf("Respuestas invalida. Confirma la baja?: ");
                fflush(stdin);
                confirma=getchar();

            }

            if(confirma=='s')
            {
                vec[indice].isEmpty=1;
                printf("Baja exitosa!!!\n");
            }
            else
            {
                printf("Se ha cancelado la baja\n");
            }
        }

        retorno=1;

    }
    *pFlag=0;

    return retorno;
}



int subMenuModificar()
{
    int opcion;

    system("cls");
    printf("Que desea modificar:\n");
    printf("1-Marca\n");
    printf("2-Tipo\n");
    printf("3-Color\n");
    printf("4-Material\n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
int validarConfirmacion(char valor)
{
    int esValido=0;
    valor=tolower(valor);
    if(valor=='s' || valor=='n')
    {
        esValido=1;
    }

    return esValido;
}
int modificarBicicletas(eBicicleta vec[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int retorno=0;
    int id;
    int indice;
    int auxIdTipo;
    int auxIdColor;
    char auxMaterial;
    char confirma;
    char auxCad[20];

    if(vec!=NULL && tam>0)
    {
        system("cls");
        printf("      *** MODIFICAR BICICLETA ***     \n");

        mostrarBicicletas(vec, tam, tipos, tamT, colores, tamC, 0);



        printf("Ingrese el id de la bicicleta a modificar: ");
        scanf("%d", &id);


        buscarBici(&indice, id, vec, tam);
        if(indice==-1)
        {
            printf("No existe bici con el id: %d\n", id);
        }
        else
        {
            mostrarBiciConfirmacion(vec[indice], colores, tamC, tipos, tamT);
            printf("Confirma modificacion?: ");
            fflush(stdin);
            confirma=getchar();
            while(!validarConfirmacion(confirma))
            {
                printf("Respuestas invalida. Confirma modificacion?: ");
                fflush(stdin);
                confirma=getchar();

            }


            if(confirma=='s')
            {
                switch(subMenuModificar())
                {
                    case 1:
                        printf("Ingrese Marca actualizada: ");
                        fflush(stdin);
                        gets(auxCad);
                        while(strlen(auxCad)>20)
                        {
                            printf("Nombre de marca demasiado largo. Reingrese marca\n");
                            fflush(stdin);
                            gets(auxCad);
                        }

                        strcpy(vec[indice].marca, auxCad);
                        printf("Marca modificado con exito!!!\n");

                        break;
                    case 2:

                        mostrarTipo(tipos, tamT, 1);

                        printf("Ingrese id del tipo de bici actualizado: ");
                        scanf("%d", &auxIdTipo);

                        while(!validarTipo(auxIdTipo, tipos, tamT))
                        {
                            printf("Id invalida, reingrese id del Tipo\n");
                            scanf("%d", &auxIdTipo);
                        }

                        vec[indice].idTipo=auxIdTipo;
                        printf("Tipo modificado con exito!!!\n");
                    //Edad
                        break;
                    case 3:
                        mostrarColor(colores, tamC, 1);

                        printf("Ingrese id del Color actualizado: ");
                        scanf("%d", &auxIdColor);

                        while(!validarColor(auxIdColor, colores, tamC))
                        {
                            printf("Id invalida, reingrese id del Color\n");
                            scanf("%d", &auxIdColor);
                        }

                        vec[indice].idColor=auxIdColor;
                        printf("Color modificado con exito!!!\n");

                    //Carrera
                        break;

                    case 4:
                        printf("Ingrese material actualizado: ('c' para carbono o 'a' para aluminio)");
                        fflush(stdin);
                        scanf("%c", &auxMaterial);

                        while(validarMarca(auxMaterial)==0)
                        {
                            printf("Marca invalida, reingrese la marca:\n");
                            fflush(stdin);
                            scanf("%c", &auxMaterial);
                        }

                        vec[indice].material=auxMaterial;

                        break;
                }
            }
            else
            {
                printf("Se ha cancelado la modificacion\n");
            }

        }

        retorno=1;

    }

    return retorno;

}


void mostrarBiciConfirmacion(eBicicleta b, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
        char color[20];
        char tipo[20];
        char material[20];

        if(b.material=='c')
        {
            strcpy(material, "Carbono");
        }
        else{
            strcpy(material, "Aluminio");
        }

        cargarDescripcionColor(b.idColor, color, colores, tamC);
        cargarDescripcionTipo(b.idTipo, tipo, tipos, tamT);
        printf(" --------------------\n");
        printf(" Bicicleta seleccionada:\n");
        printf(" Id: %d \n Marca: %-10s \n Tipo: %-10s \n Color: %-10s \n material: %-10s\n", b.id, b.marca, tipo, color, material);
        printf(" --------------------\n");
}


int buscarBici(int* pIndice, int id, eBicicleta vec[], int tam)
{
    int retorno=0;
    int indice=-1;

    if(pIndice!=NULL && vec!=NULL && tam>0)
    {
        for(int i =0; i<tam; i++)
        {
            if(!vec[i].isEmpty && vec[i].id == id)
            {
                indice=i;
                break;
            }
        }
        *pIndice=indice;
        retorno=1;
    }

    return retorno;
}

int buscarLibre(int* pIndice, eBicicleta vec[], int tam)
{
    int retorno=0;
    int indice=-1;

    if(pIndice!=NULL && vec!=NULL && tam>0)
    {
        for(int i =0; i<tam; i++)
        {
            if(vec[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
        *pIndice=indice;
        retorno=1;
    }

    return retorno;

}

int mostrarBicicletas(eBicicleta vec[], int tam, eTipo tipo[], int tamT, eColor color[], int tamC,int cls)
{
    int retorno=0;
    int flag=1;

    if(vec!=NULL && tam>0 && tipo!=NULL && tamT>0 && color!=NULL && tamC>0 && cls>=0 && cls<=1)
    {
        if(cls)
        {
            system("cls");
        }

        printf("                    ***LISTA DE BICICLETAS***\n");
        printf("\n");
        printf("Id              Marca               Tipo            Color        Material\n");
        printf("--------------------------------------------------------------------------\n");

        for(int i =0; i<tam; i++)
        {
            if(!vec[i].isEmpty)
            {
                mostrarBici(vec[i], color, tamC, tipo, tamT);
                flag=0;
            }

        }
        if(flag)
        {
            printf("No hay bicicletas cargadas en el sistema\n");
        }
        printf("\n\n");
        retorno=1;
    }

    return retorno;
}

void mostrarBici(eBicicleta b, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    char color[20];
    char tipo[20];
    char material[10];

    if(b.material=='c')
    {
        strcpy(material, "Carbono");
    }
    else{
        strcpy(material, "Aluminio");
    }

    cargarDescripcionColor(b.idColor, color, colores, tamC);
    cargarDescripcionTipo(b.idTipo, tipo, tipos, tamT);
    printf("%d%20s       %10s      %10s        %10s\n", b.id, b.marca, tipo, color, material);

}








int inicializarBicicletas(eBicicleta vec[], int tam)
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


int altaBicicleta(int* pId, eBicicleta vec[], int tam, eTipo tipo[], int tamT, eColor color[], int tamC)
{

    int retorno=0;
    int indice;
    eBicicleta auxBici;

    if(pId!=NULL && vec!=NULL && tam>0 && tipo!=NULL && color!=NULL && tamT>0 && tamC>0)
    {
        system("cls");
        printf("      *** ALTA BICICLETA ***     \n");

        buscarLibre(&indice, vec, tam);

        if(indice==-1)
        {
            printf("No hay lugar en el sistema!!!\n");

        }
        else
        {
            cargarBicicleta(&auxBici, tam, tipo, tamT, color, tamC);

            auxBici.id = *pId;

            *pId=*pId+1;

            vec[indice] = auxBici;
            retorno=1;
        }

    }
    return retorno;
}

int cargarBicicleta(eBicicleta* pBici, int tam, eTipo tipo[], int tamT, eColor color[], int tamC)//falta pedir los ids
{
    int retorno=0;
    int auxIdTipo;
    int auxIdColor;
    char auxMaterial;
    char auxCad[tam];

    if(pBici!=NULL && color!=NULL && tipo!=NULL && tam>0 && tamT>0 && tamC>0)
    {

        printf("Ingrese marca: ");
        fflush(stdin);
        gets(auxCad);

        while(strlen(auxCad)>20)
        {
            printf("Nombre de marca demasiado larga. Reingrese la marca\n");
            fflush(stdin);
            gets(auxCad);
        }
        strcpy(pBici->marca, auxCad);

        mostrarTipo(tipo, tamT, 1);

        printf("Ingrese id del tipo: ");
        scanf("%d", &auxIdTipo);

        while(!validarTipo(auxIdTipo, tipo, tamT))
        {
            printf("Id invalida, reingrese id del Tipo\n");
            scanf("%d", &auxIdTipo);
        }

        pBici->idTipo=auxIdTipo;


        mostrarColor(color, tamC, 1);

        printf("Ingrese id del Color: ");
        scanf("%d", &auxIdColor);

        while(!validarColor(auxIdColor, color, tamC))
        {
            printf("Id invalida, reingrese id del Color\n");
            scanf("%d", &auxIdColor);
        }

        pBici->idColor=auxIdColor;

        printf("Ingrese material: ('c' para carbono o 'a' para aluminio)\n");
        fflush(stdin);
        scanf("%c", &auxMaterial);

        while(validarMarca(auxMaterial)==0)
        {
            printf("Marca invalida, reingrese la marca:\n");
            fflush(stdin);
            scanf("%c", &auxMaterial);
        }

        pBici->material=auxMaterial;

        pBici->isEmpty=0;

        retorno=1;
    }

    return retorno;
}

int validarMarca(char valor)
{
    int esValido=0;
    valor=tolower(valor);
    if(valor=='c' || valor=='a')
    {
        esValido=1;
    }

    return esValido;

}



int hardcodearBicicletas(int* pId, eBicicleta vec[], int tam, int cant)
{
    int retorno=0;
    eBicicleta almacenBicis[] = {{100, "Peugeot", 1000, 5003, 'a'},
                                {101, "Mila", 1002, 5003, 'c'},
                                {102, "Taurus", 1001, 5001, 'c'},
                                {103, "Menia", 1004, 5002, 'a'},
                                {104, "Spedoo", 1002, 5000, 'c'}};

    if(vec != NULL && tam > 0 && cant <= tam && cant <= 5)
    {

        for(int i=0; i<cant; i++)
        {
            vec[i]= almacenBicis[i];
            *pId = *pId + 1;
        }
        retorno=1;
    }
    return retorno;
}
