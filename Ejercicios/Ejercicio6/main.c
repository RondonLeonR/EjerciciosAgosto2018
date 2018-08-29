#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num[10];
    int contMay=0,contMen=0,i;

    for(i=0;i<10;i++)
    {
        printf("Ingrese Numero: ");
        scanf("%d",&num[i]);
        if(num[i]<0)
        {
            contMen++;
        }
        else{
            contMay++;
        }
    }
    printf("Hay %d numeros mayores a cero\n",contMay);
    printf("Hay %d numeros menores a cero",contMen);
    return 0;
}
