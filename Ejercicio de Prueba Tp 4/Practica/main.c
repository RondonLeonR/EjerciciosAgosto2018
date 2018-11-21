#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Funciones.h"
#include "../../Library/input.h"

int main()
{
    LinkedList* listaPersonas = ll_newLinkedList();
    LinkedList* nuevaLista = NULL;
    int flag =1,opc,len;

    do{
        system("cls");
        printf("1-Agregar");
        printf("\n2-Mostrar Lista");
        printf("\n3-Prueba");
        printf("\n5-Salir\n");
        scanf("%d",&opc);
        switch(opc)
        {
        case 1:
            agregarPersona(listaPersonas);
            break;
        case 2:
            mostrarLista(listaPersonas);
            break;
        case 3:
            //prueba(listaPersonas);
            nuevaLista = filter(listaPersonas,filterBySalary);
            mostrarLista(nuevaLista);
            break;
        case 5:
            flag=0;
            break;
        }

    }while(flag==1);

    ll_deleteLinkedList(listaPersonas);
    ll_deleteLinkedList(nuevaLista);
    return 0;
}
