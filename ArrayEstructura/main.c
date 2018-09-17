#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
} eEmpleado;

void ordenarEmpleados(eEmpleado lista[], int tam);
void mostrarEmpleado(eEmpleado employee);
void mostrarArrayDeEmpleados(eEmpleado lista[], int tam);

int main()
{
    int i;
    eEmpleado empleados[TAM] =
    {
        {1234, "Juan", 'm', 12300},
        {2321, "Luisa", 'f', 14700},
        {2122,"Ariel",'m',11000},
        {3423,"Laura", 'f',15600},
        {6753,"Hugo",'m',10800},
        {6325,"Maria",'f',12000}
    };
    /*for(i=0; i<TAM; i++)
    {
        printf("Ingrese Legajo: ");
        scanf("%d",&empleados[i].legajo);
        fflush(stdin);
        printf("Ingrese Nombre: ");
        scanf("%s",&empleados[i].nombre);
        fflush(stdin);
        printf("Ingrese Sexo: ");
        scanf("%c",&empleados[i].sexo);
        printf("Ingrese Sueldo: ");
        scanf("%f",&empleados[i].sueldo);
    }*/

    mostrarArrayDeEmpleados(empleados,TAM);
    ordenarEmpleados(empleados,TAM);
    mostrarArrayDeEmpleados(empleados,TAM);


    return 0;
}


void mostrarEmpleado(eEmpleado employee)
{


    printf("%d\t%s\t%c\t%.2f\n",employee.legajo,employee.nombre,employee.sexo,employee.sueldo);


}

void mostrarArrayDeEmpleados(eEmpleado lista[], int tam)
{

    int i;
    printf("Legajo\tNombre\tSexo\tSueldo\n");
    for(i=0; i<tam; i++)
    {
        mostrarEmpleado(lista[i]);
    }


}

void ordenarEmpleados(eEmpleado lista[], int tam)
{
    eEmpleado auxEmpleado;
    int i,j;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(lista[i].sexo > lista[j].sexo)
            {
                auxEmpleado = lista[i];
                lista[i]= lista[j];
                lista[j] = auxEmpleado;
            }
            else if(lista[i].sexo==lista[j].sexo&&strcmp(lista[i].nombre,lista[j].nombre)>1)
            {
                auxEmpleado = lista[i];
                lista[i]= lista[j];
                lista[j] = auxEmpleado;
            }
        }
    }


}
