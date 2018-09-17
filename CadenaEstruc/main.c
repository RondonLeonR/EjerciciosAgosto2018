#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;
}eEmpleado;

void mostrarEmpleado(eEmpleado employee);

int main()
{
    eEmpleado unEmpleado;

    unEmpleado.legajo = 1234;
    strcpy(unEmpleado.nombre,"Juan");
    unEmpleado.sexo='m';
    unEmpleado.sueldo=10000.5;
    unEmpleado.fechaIngreso.dia=17;
    unEmpleado.fechaIngreso.mes=9;
    unEmpleado.fechaIngreso.anio=2018;

    mostrarEmpleado(unEmpleado);
    return 0;
}

void mostrarEmpleado(eEmpleado employee){

    printf("%d %s %c %.2f %02d/%02d/%04d\n",employee.legajo,employee.nombre,employee.sexo,employee.sueldo,employee.fechaIngreso.dia,employee.fechaIngreso.mes,employee.fechaIngreso.anio);


}

