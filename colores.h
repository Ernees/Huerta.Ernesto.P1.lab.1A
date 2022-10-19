#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED

typedef struct{
    int id;//empieza en 5000
    char nombreColor[20];
    int isEmpty;
}eColor;


#endif // COLORES_H_INCLUDED

int validarColor(int id, eColor color[], int tam);
int mostrarColor(eColor vec[], int tam, int cls);
int inicializarColor(eColor vec[], int tam);
int cargarDescripcionColor(int id, char descripcion[], eColor vec[], int tam);
int hardcodearColores(int* pId, eColor vec[], int tam, int cant);
