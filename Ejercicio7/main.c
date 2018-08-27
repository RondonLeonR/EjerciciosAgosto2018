#include <stdio.h>
#include <stdlib.h>

int main()
{
    float radio,longitud,area;

    printf("Ingrese el Radio de la circunferencia: ");
    scanf("%f",&radio);

    longitud=radio*2;
    area=longitud*3.14;

    printf("La longitud es: %.2f",longitud);
    printf("\nEl area es: %.2f",area);


    return 0;
}
