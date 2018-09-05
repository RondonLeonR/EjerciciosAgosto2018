#include <stdio.h>
#include <stdlib.h>
#define CANT 10


int main()
{
    int i,legajo[CANT],legajoAux;

    legajo[1]=10;

    printf("Ingrese legajo a buscar: ");
    scanf("d",&legajoAux);

    for(i=0;i<CANT;i++){
        if(legajoAux==legajo[i]){
            printf("Dato Encontrado");
            break;
        }
        if(i==(CANT-1)){
            printf("No");
        }
    }

    return 0;
}
