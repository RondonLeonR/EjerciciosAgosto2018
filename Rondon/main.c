#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

#define CANTJ 10
#define CANTC 10
#define CANTAL 50

int main()
{
    char seguir = 's';
    int flag=0,flag2=0;

    eJuego juegos[CANTJ];
    eCliente clientes[CANTC];
    eAlquiler alquileres[CANTAL];

    initJuego(juegos,CANTJ);
    initCliente(clientes,CANTC);
    initAlquileres(alquileres,CANTAL);

    do
    {
        switch(menu())
        {

        case 1:
            flag=Juegos(juegos,CANTJ,flag);
            break;
        case 2:
            flag2=opcClientes(clientes,CANTC,flag2);
            break;
        case 3:
            if(flag==0)
            {
                system("cls");
                printf("No se ingreso ningun Juego.\n\n");
                system("pause");
            }
            else if(flag2 ==0)
            {
                system("cls");
                printf("No se ingreso ningun Cliente.\n\n");
                system("pause");
            }

            if(flag2==1 && flag ==1)
            {
                alquileresJ(alquileres,CANTAL,clientes,CANTC,juegos,CANTJ);
            }

            break;
        case 4:
            informar(alquileres,CANTAL,juegos,CANTJ,clientes,CANTC);
            break;
        case 5:
            seguir = 'n';
            break;
        }

    }while(seguir == 's');
    return 0;
}

