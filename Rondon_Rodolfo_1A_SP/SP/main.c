#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "LinkedList.h"
#include "Parser.h"
#include "input.h"

int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados);

int main()
{
    char nombreArchivo[50];
    // Definir lista de empleados
    LinkedList* listaEmpleados;
    // Crear lista empledos
    listaEmpleados = ll_newLinkedList();
    pedirNombreArchivo(nombreArchivo);

    // Leer empleados de archivo data.csv
    if(parser_parseEmpleados(nombreArchivo,listaEmpleados)==1)
    {
        // Calcular sueldos
        printf("Calculando sueldos de empleados\n\n");
        al_map(listaEmpleados,em_calcularSueldo);

        // Generar archivo de salida
        if(generarArchivoSueldos("info.csv",listaEmpleados)==1)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");
    }
    return 0;
}

int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados)
{
    FILE* pFile;
    Empleado* empleadoAux = NULL;
    int idAux,horasAux,len,retorno = -1;
    char nombreAux[128];
    float sueldoAux;

    pFile = fopen(fileName,"w");
    if(pFile == NULL || listaEmpleados == NULL)
    {
        printf("No se pudo crear el Archivo.\n");
        system("pause");
    }
    else
    {
        fprintf(pFile,"id,nombre,hora_trabajadas,sueldo\n");
        len = ll_len(listaEmpleados);
        for(int i=0;i<len;i++)
        {
            empleadoAux = ll_get(listaEmpleados,i);
            employee_getId(empleadoAux,&idAux);
            employee_getNombre(empleadoAux,nombreAux);
            employee_getHorasTrabajadas(empleadoAux,&horasAux);
            employee_getSueldo(empleadoAux,&sueldoAux);
            fflush(stdin);
            fprintf(pFile,"%d,%s,%d,%.2f\n",idAux,nombreAux,horasAux,sueldoAux);
        }
        printf("Informacion guardada. \n");
        system("pause");
        retorno = 1;
    }
    fclose(pFile);
    return retorno;
}
