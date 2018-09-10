#include <stdio.h>
#include <stdlib.h>

int main()
{
       char nombre[20]= {"juAn carlos aLBerto"};
        int largo = strlen(nombre);
       strlwr(nombre);

       for(int i=0; i <= largo; i++){

        if(nombre[i] == ' '){
            nombre[i+1] = toupper(nombre[i+1]);
        }

       }

       nombre[0] = toupper(nombre[0]);





    printf("%s\n\n", nombre);
    return 0;
}
