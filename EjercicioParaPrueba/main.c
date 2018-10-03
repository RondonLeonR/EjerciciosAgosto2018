#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Negocio.h"

#define LIBRE 1
#define OCUP 0
#define TAM_EMP 20
#define TAM_MEN 20


int main()
{
    char seguir = 's';
    eSector sectores[] = {{1,"RRHH"},{2,"Ventas"},{3,"Compras"},{4,"Contable"},{5,"Sistemas"}};
    eEmployee emp[TAM_EMP];
    eMenu menues[TAM_MEN];

    initEmployee(emp,TAM_EMP);
    initMenu(menues,TAM_MEN);


    do
    {
        switch(menu())
        {

        case 1:
            MenuesOpci(menues,TAM_MEN);
            break;
        case 2:
            empleadosOpci(emp,TAM_EMP,sectores,5);
            break;

        case 3:
            seguir = 'n';
            break;
        }

    }while(seguir == 's');

    return 0;
}
