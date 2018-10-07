#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/***Ctrl + R (Para Modificar una palabra varias veces) ***/


/*void init(estruc list[],int len)
{

    for(int i=0; i<len; i++)
    {

    }
}*/
/*
int BuscarId(estruc list[],int len,int id)
{
    int retorno=-1;

    for(int i=0; i<len; i++)
    {
        if(emp[i].legajo==legajo) /**MODIFICAR**
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}*/


int menu()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("  1- \n");
    printf("  2- \n");
    printf("  3- \n");
    printf("  4- \n\n");
    printf("  5- Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


int Alta(estruc men[],int len)
{
    int flag=0;

    for(int i=0; i<len; i++)
    {
        if(men[i].isEmpty==1)
        {
            printf("\nIngrese: ");
            fflush(stdin);
            gets();//Guardo
            printf("\nIngrese el Importe: ");
            scanf();//Guardo
            men[i].isEmpty=0;//Doy de alta Logicamente
            flag=1;

            printf("\n\nAgregado.\n");
            system("pause");
            break;
        }
    }

    if(flag==0)
    {
        system("cls");
        printf("\n\n\tNo hay mas Lugar.\n\n");
        system("pause");
    }
    return 0;
}


int Modificacion(estruc men[],int len)
{
    int opc,opc2,i,flag=1;

    system("cls");
    /**Muestro lo Ingresado por el usuario**/
    //mostrar(men,len);
    printf("\n\nIngrese el ID  a Modificar: ");
    scanf("%d",&opc);
    system("cls");
    for(i=0; i<len; i++)
    {
        if(men[i].id==opc)
        {
            flag=0;
            printf(" ****Modificar**** \n\n");
            printf(" 1-\n");
            printf(" 2-\n");
            printf(" 3-Cancelar\n");

            scanf("%d",&opc2);

            /**SWITCH**/
            if(opc2==1)
            {
                printf("\nIngrese Nueva ...: ");
                fflush(stdin);
                gets(men[i].descripcion);
                printf("\n\nModificacion Realizada.\n");
                system("pause");
            }
            else if(opc2==2)
            {
                printf("\nIngrese Nuevo Importe: ");
                scanf("%f",&men[i].importe);
                printf("\n\nModificacion Realizada.\n");
                system("pause");
            }
            else
            {
                printf("\n\nModificacion Cancelada\n");
                system("pause");
            }
        }

    }

    if(flag==1)
    {
        printf("\nID no Encontrado.\n");
        system("pause");
    }
    return 0;

}
