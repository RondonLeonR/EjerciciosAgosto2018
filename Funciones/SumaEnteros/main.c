#include <stdio.h>
#include <stdlib.h>

int sumaDosNum(int a,int b);/***Prototipo ò Firma***/

/**Funcion Principal**/
int main()
{
    int nro1,nro2,result;
    printf("\t*****SUMA******\n");
    printf("Ingrese 1er Numero: ");
    scanf("%d",&nro1);
    printf("\nIngrese 2do Numero: ");
    scanf("%d",&nro2);
    result=sumaDosNum(nro1,nro2); /***Llamada a la Funcion***/
    printf("\n\tEl Resultado es: %d",result);
    return 0;
}

/*****Funcion para Sumar*****/
int sumaDosNum(int a,int b)
{
    int result;
    result=a+b;
    return result;
}
