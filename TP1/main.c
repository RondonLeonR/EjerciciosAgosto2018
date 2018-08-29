#include <stdio.h>
#include <stdlib.h>

/***Prototipos de las Funciones***/

int main()
{
    int opc;
    float num1=0,num2=0;
    do{
    printf("\t*****MENU*****");
    printf("\n\n1.Ingresar 1er Operando(A=%.0f)",num1);
    printf("\n2.Ingresar 2do Operando(B=%.0f)",num2);
    printf("\n3.Calcular todas las Operaciones.");
    printf("\n4.Informar Resultados.");
    printf("\n5.Salir");

    printf("\n\n\tSeleccione Opcion: ");
    scanf("%d",&opc);
        switch(opc){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            printf("ERROR");




        }

    }while(opc!=5);


    return 0;
}
