#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,i;
    float prom;
    int cont=0;

    for(i=0;i<5;i++)
    {
        printf("Ingrese Numero: ");
        scanf("%d",&num);
        cont=cont+num;

    }
    prom =(float)cont/5;
    printf("El promedio es: %.2f",prom);
    return 0;
}
