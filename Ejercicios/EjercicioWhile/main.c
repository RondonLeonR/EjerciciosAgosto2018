#include <stdio.h>
#include <stdlib.h>

int main()
{
    char resp='s',preg;
    int conta=0,num,suma=0;
    float promedio;
    do{
        printf("\nIngrese Numero: ");
        scanf("%d",&num);
        suma=suma+num;

        printf("\nDesea Ingresar otro Numero: 's' ò 'n'");
        scanf("%s",&resp);

        conta++;
    }while(resp=='s');

    printf("\nLa suma de los numeros es: %d",suma);
    promedio=(float)suma/conta;
    printf("\nEl promedio es: %.2f",promedio);
    return 0;
}
