#include <stdio.h>
#include <stdlib.h>

int main()
{
     char nombre[20]= {"ana"};
    char apellido[20] = {"aerez"};
    char nombreCompleto[40];

    strcpy(nombreCompleto, nombre);

    strcat(nombreCompleto, " ");

    strcat(nombreCompleto, apellido);


    printf("%s\n", nombreCompleto);
    return 0;
}
