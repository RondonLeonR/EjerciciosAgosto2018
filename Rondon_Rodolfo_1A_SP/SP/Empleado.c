#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "input.h"

int pedirNombreArchivo(char* Archivo)
{
    getString(Archivo,"Ingrese Nombre Del Archivo: ","ERROR, 0 - 50 caracteres ",0,50);
    return 1;
}

Empleado* nuevoEmpleado()
{
    Empleado* this;

    this = (Empleado*)malloc(sizeof(Empleado));

    if(this != NULL)
    {
        this->id=0;
        this->sueldo=0.00;
        this->horasTrabajadas=0;
        strcpy(this->nombre,"");
    }
    else
    {
        system("cls");
        printf("No se ha encontrado mas Lugar en Memoria.\n");
        exit(0);
    }

    return this;
}

Empleado* empleado_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    int id,hours;
    Empleado *this;
    this = nuevoEmpleado();

    if(this != NULL)
    {
        id = atoi(idStr);
        hours = atoi(horasTrabajadasStr);

        employee_setId(this,id);
        employee_setNombre(this,nombreStr);
        employee_setHorasTrabajadas(this,hours);
    }

    return this;
}

int employee_setId(Empleado* this,int id)
{
    int ret =0;
    if(id>0)
    {
        this->id = id;
        ret = 1;
    }
    return ret;
}

int employee_getId(Empleado* this,int* id)
{
    *id = this->id;
    return 1;
}

int employee_setNombre(Empleado* this,char* nombre)
{
    int ret = 0;
    if(nombre[0] != '\0')
    {
        strncpy(this->nombre, nombre, sizeof(this->nombre));
        ret = 1;
    }
    return ret;
}

int employee_getNombre(Empleado* this,char* nombre)
{
    strcpy(nombre,this->nombre);
    return 1;
}

int employee_setHorasTrabajadas(Empleado* this,int horasTrabajadas)
{
    int ret=0;
    if(horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        ret = 1;
    }
    return ret;
}

int employee_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{
    *horasTrabajadas = this->horasTrabajadas;
    return 1;
}

int employee_setSueldo(Empleado* this,float sueldo)
{
    int ret = 0;
    if(sueldo > 0)
    {
        this->sueldo = sueldo;
        ret = 1;
    }
    return ret;
}

int employee_getSueldo(Empleado* this,float* sueldo)
{
    *sueldo = this->sueldo;
    return 1;
}

float SueldoTotal(int horas, float precioxHora)
{
    float resultado;

    resultado = horas * precioxHora;

    return resultado;
}

int em_calcularSueldo(void* p)
{
    int horasAux;
    float sueldoxHora;
    float sueldoAux;
    if(p != NULL)
    {
        employee_getHorasTrabajadas(p,&horasAux);
        if(horasAux<=176)
        {
            sueldoxHora = 180;

        }
        else if(horasAux >=177 && horasAux<=208)
        {
            sueldoxHora = 270;
        }
        else if(horasAux >=209 && horasAux <=240)
        {
            sueldoxHora = 360;
        }

        sueldoAux = SueldoTotal(horasAux,sueldoxHora);
        employee_setSueldo(p,sueldoAux);
    }
    return 1;
}




