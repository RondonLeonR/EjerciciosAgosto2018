#include <stdio.h>
#include <stdlib.h>
#include "../EjerciciosAgosto2018/EjerciciosAgosto2018/Library/input.h"

int main()
{
    char seguir = 's';

    /**Declaro las estructuras y las inicializo**/

    do
    {
        switch(menu())
        {

        case 1:

            break;
        case 2:

            break;

        case 3:
            seguir = 'n';
            break;
        }

    }while(seguir == 's');
    return 0;
}
