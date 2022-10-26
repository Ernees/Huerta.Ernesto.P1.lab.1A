#ifndef LISTADOS_H_INCLUDED
#define LISTADOS_H_INCLUDED
#include "colores.h"
#include "tipos.h"
#include "bicicletas.h"


#endif // LISTADOS_H_INCLUDED
int mostrarBicisTipo(int idTipo, eBicicleta bicicletas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
int listarBicisTipo(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
int listarBicisPorTipo(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
int mostrarBicisColor(int idColor, eBicicleta bicicletas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
int listarBicisColor(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
int mostrarBicisMaterial(char material, eBicicleta bicicletas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
int mostrarMayorCantMaterial(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
int mostrarBicisColorTipo(int idColor, int idTipo, eBicicleta bicicletas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
int listarBicisColorTipo(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
int mostrarColorMasElegido(int idColor, eBicicleta bicicletas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
int listarColorMasElegido(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
