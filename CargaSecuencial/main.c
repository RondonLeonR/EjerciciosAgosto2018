#include <stdio.h>
#include <stdlib.h>
#define CANT 50

int main()
{
    /****Usarlo para dar de Alta****/
    int legajo[CANT],i,isEmpty[CANT];
    float salario[CANT];
    /***Inicializar, 1 indica libre***/
    for(i=0;i<CANT;i++){
        isEmpty[i]=1;
    }
    for(i=0;i<CANT;i++){
        if(isEmpty[i]==1){
            printf("Legajo: ");
            scanf("%d",&legajo[i]);
            printf("Salario: ");
            scanf("%f",&salario[i]);
            /**Cambio el valor dado antes, 0 indica ocupado**/
            isEmpty[i]=0;
            break;
        }
    }

    /*for(i=0;i<CANT;i++){
        if(isEmpty==0){
            printf("Legajo\tSalario\n");
            printf("%d\t%.2f\n",legajo[i],salario[i]);
        }
        else{
            break;
        }
    }*/

    return 0;
}
