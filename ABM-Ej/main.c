#include <stdio.h>
#include <stdlib.h>
#include "persona.h"



#define CANT 3
#define OCUP 2


int main()
{
    char seguir='s';
    int opcion=0;
    EPersona personas[CANT] =
    {
            {"Lopez","A",1111,18,9,2018, OCUP, 1},
            {"Lopez","J",2222,19,10,2017, OCUP, 2},
            {"A","Juan",3333,20,12,2010, OCUP, 3}
    };

    //init(personas, CANT);

    do
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Modificar persona\n");
        printf("4- Imprimir lista ordenada por apellido y nombre\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            alta(personas, CANT);
            break;
        case 2:
            baja(personas, CANT);
            break;
        case 3:
            modificar(personas, CANT);
            break;
        case 4:
            ordenamiento(personas, CANT);
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');

    return 0;
}
