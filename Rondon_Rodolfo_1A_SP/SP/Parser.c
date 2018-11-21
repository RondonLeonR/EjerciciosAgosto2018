#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "input.h"
#include "Empleado.h"

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    FILE* pFile;
    pFile = fopen(fileName,"r");
    int r,retorno=0;
    if(pFile == NULL)
    {
        printf("\nEl archivo no existe o no fue encontrado\n");
        system("pause");
    }
    else
    {
        Empleado *this;
        this = nuevoEmpleado();
        int r;
        char var1[30],var2[30],var3[30];

        r = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",var1,var2,var3);
        do
        {
            r = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",var1,var2,var3);
            if(r == 3)
            {
                this =  empleado_newParametros(var1,var2,var3);
                ll_add(listaEmpleados,this);
            }

            if(feof(pFile) != 0)
            {
                printf("Se cargo todo el Archivo.\n\n");
                retorno = 1;
            }

        }
        while(!feof(pFile));
    }
    fclose(pFile);
    return retorno; // OK
}



