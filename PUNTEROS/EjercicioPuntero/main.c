#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    char marca[25];
    int capacidad;
    float precio;
} ePendrive;

int cargarPendrive(ePendrive *pen);
void mostrarPendrive(ePendrive *pen);
int cargarPendriveParam(ePendrive *pen, int codigo, char marca[25],int cap,float precio);


int main()
{
    int codigo;
    char marca[25];
    int capacidad;
    float precio;
    ePendrive pen;

    /*if(cargarPendrive(&pen)==1)
    {
        mostrarPendrive(&pen);
    }
    else
    {
        printf("No se cargo Correctamente");
    }*/

    if(cargarPendriveParam(&pen,codigo,marca,capacidad,precio)==1)
    {
        mostrarPendrive(&pen);
    }
    else
    {
        printf("No se cargo Correctamente");
    }

    return 0;
}

int cargarPendrive(ePendrive *pen)
{
    int ret=0;
    if(pen!=NULL)
    {
        printf("Ingrese Codigo: ");
        scanf("%d",&pen->codigo);
        printf("Ingrese Marca: ");
        fflush(stdin);
        gets(pen->marca);
        printf("Ingrese Capacidad: ");
        scanf("%d",&pen->capacidad);
        printf("Ingrese Precio: ");
        scanf("%f",&pen->precio);
        ret=1;
    }

    return ret;
}


void mostrarPendrive(ePendrive *pen)
{
    if(pen != NULL)
    {
        system("cls");
        printf("**PenDrive**\n\n");
        printf("%d\n",pen->codigo);
        printf("%s\n",pen->marca);
        printf("%d\n",pen->capacidad);
        printf("%.2f\n",pen->precio);
    }

}


int cargarPendriveParam(ePendrive *pen, int codigo, char marca[25],int cap,float precio)
{
     int ret=0;
    if(pen!=NULL)
    {
        printf("Ingrese Codigo: ");
        scanf("%d",&codigo);

        printf("Ingrese Marca: ");
        fflush(stdin);
        gets(marca);

        printf("Ingrese Capacidad: ");
        scanf("%d",&cap);

        printf("Ingrese Precio: ");
        scanf("%f",&precio);
        ret=1;

        pen->codigo=codigo;
        strcpy(pen->marca,marca);
        pen->capacidad=cap;
        pen->precio=precio;
    }
    return ret;
}



