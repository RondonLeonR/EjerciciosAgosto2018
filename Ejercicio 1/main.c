#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,prom,i;
    int cont=0;

    for(i=0;i<5;i++)
    {
        printf("Ingrese Numero: ");
        scanf("%d",&num);
        cont=cont+num;

    }
    prom=cont/5;
    printf("El promedio es: %d",prom);
    return 0;
}
