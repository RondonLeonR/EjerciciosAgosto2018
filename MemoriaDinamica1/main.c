#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;

    /**
    (int*) Castea la direccion q devuelve el malloc a un puntero de entero
    malloc Busca espacio libre en la Memoria Dinamica y devuelve la direccion
    */
    p=(int*) malloc(sizeof(int));

    if(p==NULL)
    {
        printf("NO se encontro Lugar");
        exit(1);
    }

    *p=24;

    printf("%d",*p);

/**Libero el espacio de memoria ocupado**/
    free(p);

    return 0;
}
