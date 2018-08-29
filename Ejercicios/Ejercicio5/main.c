#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cuadrado,num,flag=0;

    while(flag==0){
    printf("Ingrese Numero: ");
    scanf("%d",&num);
        if(num>0)
        {
            cuadrado=num*2;
            flag=1;
        }
        else{
            printf("ERROR, el numero debe ser mayor que cero\n");
        }
    }
    printf("El resultado es: %d",cuadrado);
    return 0;
}
