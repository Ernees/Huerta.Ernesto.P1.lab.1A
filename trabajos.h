#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED
#include "servicios.h"
#include "colores.h"
#include "tipos.h"
#include "bicicletas.h"

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;


#endif // TRABAJOS_H_INCLUDED

int inicializarTrabajos(eTrabajo vec[], int tam);
int buscarLibreTrabajo(int* pIndice, eTrabajo vec[], int tam);
int altaTrabajo(int* pId, eBicicleta vec[], int tam, eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamS, eTipo tipo[], int tamT, eColor color[], int tamC, int cls);
int mostrarTrabajos(eBicicleta vec[], int tam, eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamS);
void mostrarTrabajo(eTrabajo trabajo, eBicicleta vec[], int tam, eServicio servicios[], int tamS);
