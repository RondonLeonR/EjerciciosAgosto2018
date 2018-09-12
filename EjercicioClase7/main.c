#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define CANT 20

int Alta(int isEmpty[],int edad[], char nom[][20], char apell[][20]);
int Baja(int isEmpty[],int edad[], char nom[][20], char apell[][20]);
int Modificar(int isEmpty[],int edad[], char nom[][20], char apell[][20]);
int Ordenamiento(int isEmpty[],int edad[], char nom[][20], char apell[][20]);
void Mostrar(int isEmpty[], int edad[],char nom[][20],char apell[][20]);

int main()
{
    int edad[CANT],opc,i;
    int isEmpty[CANT];
    for(i=0; i<CANT; i++)
    {
        isEmpty[i]=0;
    }
    char nombre[CANT][20];
    char apellido[CANT][20];

    do
    {

        printf("1-Alta\n");
        printf("2-Baja\n");
        printf("3-Modificacion\n");
        printf("4-Salir\n");
        scanf("%d",&opc);
        switch(opc)
        {
        case 1:
            Alta(isEmpty,edad,nombre,apellido);
            break;
        case 2:
            Baja(isEmpty,edad,nombre,apellido);
            break;
        case 3:
            Modificar(isEmpty,edad,nombre,apellido);
            break;
        case 4:
            break;

        }
    }
    while(opc!=4);

    system("cls");

    Ordenamiento(isEmpty,edad,nombre,apellido);

    return 0;
}

int Alta(int isEmpty[],int edad[], char nom[][20], char apell[][20])
{
    int i;
    for(i=0; i<CANT; i++)
    {
        if(isEmpty[i]==0)
        {
            printf("Ingresar Edad: ");
            scanf("%d",&(edad[i]));
            fflush(stdin);
            printf("Ingresar Nombre: ");
            //scanf("%s",&nom[i]);
            //gets(nom[i]);
            fgets(nom[i],sizeof(nom[i]),stdin);
            fflush(stdin);
            printf("Ingresar Apellido: ");
            //scanf("%s",&apell[i]);
            fgets(apell[i],sizeof(apell[i]),stdin);

            isEmpty[i]=1;
            break;
        }
    }
    return 0;
}


void Mostrar(int isEmpty[], int edad[],char nom[][20],char apell[][20])
{
    int i;
    for(i=0; i<CANT; i++)
    {
        if(isEmpty[i]==1)
        {
            printf("%d",isEmpty[i]);
            printf("\t%d\n",edad[i]);
            printf("\t%s\n",nom[i]);
            printf("\t%s\n\n",apell[i]);
        }
    }
}

int Baja(int isEmpty[],int edad[], char nom[][20], char apell[][20])
{
    int indice;
    Mostrar(isEmpty,edad,nom,apell);
    printf("Seleccione Indice: ");
    scanf("%d",&indice);
    if(isEmpty[indice-1]==1)
    {
        isEmpty[indice-1]=-1;
    }
    return 0;
}

int Ordenamiento(int isEmpty[],int edad[], char nom[][20], char apell[][20])
{
    int i,j,edadAux,isEmptyAux;
    char nomAux[20],apellAux[20];
    for(i=0; i<CANT-1; i++)
    {
        for(j=i+1; j<CANT; j++)
        {
            if(strcmp(apell[i],apell[j])>0)
            {
                strcpy(apellAux,apell[i]);
                strcpy(apell[i],apell[j]);
                strcpy(apell[j],apellAux);

                strcpy(nomAux,nom[i]);
                strcpy(nom[i],nom[j]);
                strcpy(nom[j],nomAux);

                edadAux=edad[i];
                edad[i]=edad[j];
                edad[j]=edadAux;

                isEmptyAux=isEmpty[i];
                isEmpty[i]=isEmpty[j];
                isEmpty[j]=isEmptyAux;
            }
        }
    }

    Mostrar(isEmpty,edad,nom,apell);


    return 0;

}

int Modificar(int isEmpty[],int edad[], char nom[][20], char apell[][20])
{
    int opc;
    Mostrar(isEmpty,edad,nom,apell);
    printf("Ingrese el indice a modificar: ");
    scanf("%d",&opc);
    printf("A modificar: ");
    printf("\n%d\t\t%d\t%s\t%s\n",isEmpty[opc],edad[opc],nom[opc],apell[opc]);
    printf("\nIngrese Edad: ");
    scanf("%d",&edad[opc]);
    fflush(stdin);
    printf("Ingrese Nombre: ");
    fgets(nom[opc],sizeof(nom[opc]),stdin);
    fflush(stdin);
    printf("Ingrese Apellido: ");
    fgets(apell[opc],sizeof(apell[opc]),stdin);
    return 0;
}

/*******Ordenar por 2 Variables*****/
/*
for(i=0; i<CANT-1; i++)
{
    for(j=i+1; j<CANT; j++)
    {
        if(strcmp(nombre[i],nombre[j])>0)
        {
            srtcpy(nomAux,nombre[i]);
            srtcpy(nombre[i],nombre[j]);
            srtcpy(nombre[j],nomAux);

            srtcpy(apellAux,apellido[i]);
            srtcpy(apellido[i],apellido[j]);
            srtcpy(apellido[j],apellAux);

            edadAux=edad[i];
            edad[i]=edad[j];
            edad[j]=edadAux;

            legajoAux=legajo[i];
            legajo[i]=legajo[j];
            legajo[j]=legajoAux;

            isEmptyAux=isEmpty[i];
            isEmpty[i]=isEmpty[j];
            isEmpty[j]=isEmptyAux;


        }
        else
        {
            if(strcmp(apellido[i],apellido[j])==0&&strcmp(nombre[i],nombre[j])>0)
            {

            }

        }

    }
}
*/

/*****Baja Logica*****/
/*
printf("Legajo: ");
scanf("%d",&legajoAux);
flag=0;
for(i=0; i<CANT; i++)
{
    if(legajoAux==legajo[i])
    {
        isEmpty[i]=1;
    }
}
if(flag==0)
{
    printf("Dato no encontrado");
}

*/

/*****Mostrar-Listar****/
/*
printf("Legajo\tApellido\t\tNombre\t\tEdad\n\n");
for(i=0; i<CANT; i++)
{
    if(isEmpty[i]==0)
    {
        printf("%d\t%s\t%s\t\t%d\n",legajo[i],apellido[i],nombre[i],edad[i]);

    }
}

*/
/*****Modificacion*****/
/*
printf("Legajo: ");
scanf("%d",&legajoAux);
flag=0;
for(i=0; i<CANT; i++)
{
    if(legajoAux==Legajo[i])
    {
        printf("%d%s%s%d",legajo[i],apellido[i],nombre[i],edad[i]);
        printf("Modificar s/n?");
        fflush(stdin);
        scanf("%c",&rta);

        if(rta=='s')
        {
            do
            {
                printf("MENU");
                printf("1-Apellido");
                printf("2-Nombre");
                printf("3-Edad");
                printf("4-Salir");
                printf("Seleccione");
                scanf("%d",&opcion);
                switch(opcion)
                {
                case 1:
                    printf("Apellido: ");
                    fflush(stdin);
                    fgets(apellido[i],sizeof(apellido),stdin);
                    break;
                }
            }
        }
    }
}
*/
