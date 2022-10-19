#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED
#include "colores.h"
#include "tipos.h"

typedef struct{
    int id;
    char marca[20];
    int idTipo;//validar
    int idColor;//validar
    char material;// c carbono a aluminio
    int isEmpty;
}eBicicleta;

#endif // BICICLETAS_H_INCLUDED
int modificarBicicletas(eBicicleta vec[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT);
int buscarBici(int* pIndice, int id, eBicicleta vec[], int tam);
void mostrarBiciConfirmacion(eBicicleta b, eColor colores[], int tamC, eTipo tipos[], int tamT);
int cargarBicicleta(eBicicleta* pBici, int tam, eTipo tipo[], int tamT, eColor color[], int tamC);
int altaBicicleta(int* pId, eBicicleta vec[], int tam, eTipo tipo[], int tamT, eColor color[], int tamC);
int buscarLibre(int* pIndice, eBicicleta vec[], int tam);
int inicializarBicicletas(eBicicleta vec[], int tam);
int mostrarBicicletas(eBicicleta vec[], int tam, eTipo tipo[], int tamT, eColor color[], int tamC,int cls);
void mostrarBici(eBicicleta b, eColor colores[], int tamC, eTipo tipos[], int tamT);
int hardcodearBicicletas(int* pId, eBicicleta vec[], int tam, int cant);
int cargarDescripcionMaterial(eBicicleta bici[], char material[]);
int bajaBicicleta(eBicicleta vec[], eColor colores[], eTipo tipos[], int tamC, int tamT, int tam, int* flag);
int validarMarca(char valor);
int validarConfirmacion(char valor);
