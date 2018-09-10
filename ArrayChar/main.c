#include <stdio.h>
#include <stdlib.h>

void ArrayMostrarChar(char vec [], int tam);
void ordenamientoCaracteres(char vec[], int tam);

int main()
{
    char letras[] = { 'g', 'f','a','A','e','g','b','Z'};

    ArrayMostrarChar(letras, 8);

    ordenamientoCaracteres(letras , 8);

    ArrayMostrarChar(letras, 8);
    return 0;
}

void ArrayMostrarChar(char vec [], int tam){
    int i;

    for(i=0;i<tam;i++){
        printf("%c ",vec[i]);
    }
    printf("\n\n");
}

void ordenamientoCaracteres(char vec[], int tam){

    char LetraAux;

    for(int i=0;i<tam-1;i++){
        for(int j=i+1;j<tam;j++){
            if(vec[i]>vec[j]){

                LetraAux=vec[i];
                vec[i]=vec[j];
                vec[j]=LetraAux;
            }
        }
    }
}
