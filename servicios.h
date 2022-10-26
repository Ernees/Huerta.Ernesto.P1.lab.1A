#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct{
    int id;
    char descripcion[25];
    float precio;
}eServicio;


#endif // SERVICIOS_H_INCLUDED

int validarIdServicios(int id, eServicio vec[], int tam);
int hardcodearServicios(int* pId, eServicio vec[], int tam, int cant);
int cargarDescripcionServicio(int id, char descripcion[], eServicio servicios[], int tam);
int mostrarServicios(eServicio servicios[], int tam);
