#include <stdio.h>
#include <stdlib.h>
#define CANT 5

int main()
{
    int legajo[CANT];
    float salario[CANT];
    int i;

    for(i=0;i<CANT;i++){
        printf("Legajo: ");
        scanf("%d",&legajo[i]);
        printf("Salario: ");
        scanf("%f",&salario[i]);
    }
    system("cls");
    printf("Legajo\tSalario\n");
    for(i=0;i<CANT;i++){
        printf("%d\t%.2f\n",legajo[i],salario[i]);
    }
    return 0;
}
