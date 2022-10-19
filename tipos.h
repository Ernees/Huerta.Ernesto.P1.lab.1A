#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct{
    int id;//empieza en 1000
    char descripcion[20];
    int isEmpty;
}eTipo;

#endif // TIPOS_H_INCLUDED
int hardcodearTipos(int* pId, eTipo vec[], int tam, int cant);
int validarTipo(int id, eTipo tipo[], int tam);
int mostrarTipo(eTipo vec[], int tam, int cls);
int inicializarTipo(eTipo vec[], int tam);
int cargarDescripcionTipo(int id, char descripcion[], eTipo vec[], int tam);
