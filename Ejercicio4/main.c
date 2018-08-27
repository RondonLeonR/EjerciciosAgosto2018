#include <stdio.h>
#include <stdlib.h>

int main()
{
    fflush(stdin);
    int num1,num2,resta;


    printf("Ingrese Numero: ");
    scanf("%d",&num1);

    printf("Ingrese Numero: ");
    scanf("%d",&num2);
    resta=num1-num2;
    if(resta<0)
    {
        printf("Resultado Negativo");
    }
    else{
        printf("Resultado Positivo");
    }
    return 0;
}
