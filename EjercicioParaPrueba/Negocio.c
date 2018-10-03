#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Negocio.h"

#define LIBRE 1
#define OCUP 0
#define TAM_EMP 100
#define TAM_MEN 20


void initEmployee(eEmployee emp[],int tamEmp)
{
    for(int i=0; i<tamEmp; i++)
    {
        emp[i].legajo=i;
        emp[i].isEmpty=LIBRE;
    }
}

void initMenu(eMenu men[],int tamMen)
{
    for(int i=0; i<tamMen; i++)
    {
        men[i].id=i;
        men[i].isEmpty=LIBRE;
    }
}

void initAlmuerzo(eAlmuerzo alm[],int tamAlmuerzo)
{
    for(int i=0; i<tamAlmuerzo; i++)
    {
        alm[i].id=i;
        alm[i].isEmpty=LIBRE;
    }
}

void initSec(eSector sect[],int tamSec)
{
    for(int i=0; i<tamSec; i++)
    {
        sect[i].id=i;
    }
}

int BuscarEmp(eEmployee emp[],int tamEmp,int legajo)
{
    int retorno=-1;

    for(int i=0; i<tamEmp; i++)
    {
        if(emp[i].legajo==legajo)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int menu()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("  1- MENUES\n");
    printf("  2- EMPLEADOS\n\n");
    printf("  3- Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuABM()
{
    int opc;
    system("cls");
    printf("\n  1-Alta\n");
    printf("  2-Modificacion\n");
    printf("  3-Baja\n");
    printf("  4-Listar\n");
    printf("  5-Salir\n\n");
    printf("Seleccione Opcion: ");
    fflush(stdin);
    scanf("%d",&opc);

    return opc;
}

void MenuesOpci(eMenu menu[],int tamMen)
{
    char seguir='s';
    do
    {
        switch(menuABM())
        {
        case 1:
            AltaMenu(menu,tamMen);
            break;
        case 2:
            ModificacionMenu(menu,tamMen);
            break;
        case 3:
            BajaMenu(menu,tamMen);
            break;
        case 4:
            OrdenamientoMenu(menu,tamMen);
            break;
        case 5:
            seguir='n';
            break;
        }
    }
    while(seguir == 's');
}

int AltaMenu(eMenu men[],int tam)
{
    int flag=0;
    for(int i=0;i<tam;i++)
    {
        if(men[i].isEmpty==LIBRE && flag==0)
        {
            printf("\nIngrese Descripcion del Menu: ");
            fflush(stdin);
            gets(men[i].descripcion);
            printf("\nIngrese el Importe: ");
            scanf("%f",&men[i].importe);
            men[i].isEmpty=OCUP;
            flag=1;

            printf("\n\nAgregado al Menu.\n");
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

int ModificacionMenu(eMenu men[],int tam)
{
    int opc,opc2,i,flag=1;

    system("cls");
    mostrarMenues(men,tam);
    printf("\n\nIngrese el ID del Menu a Modificar: ");
    scanf("%d",&opc);
    system("cls");
    for(i=0;i<tam;i++)
    {
        if(men[i].id==opc)
        {
            flag=0;
            printf(" ****Modificar**** \n\n");
            printf(" 1-Descripcion\n");
            printf(" 2-Importe\n");
            printf(" 3-Cancelar\n");

            scanf("%d",&opc2);
            if(opc2==1)
            {
                printf("\nIngrese Nueva Descripcion: ");
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

int BajaMenu(eMenu men[],int tam)
{
    int opc,flag=1;
    char opc2;
    system("cls");
    mostrarMenues(men,tam);
    printf("\n\nIngrese el ID del Menu a dar de Baja: ");
    scanf("%d",&opc);

    for(int i=0;i<tam;i++)
    {
        if(men[i].id==opc)
        {
            printf("\nMenu encontrado.");
            mostrarMenu(men[i]);
            printf("\nDar de Baja: s o n\t");
            fflush(stdin);
            scanf("%c",&opc2);
            if(opc2=='s')
            {
                men[i].isEmpty=LIBRE;
                printf("\n\nMenu dado de Baja.\n");
                system("pause");
            }
            else
            {
                printf("\n\nOperacion Cancelada.\n");
                system("pause");
            }

        }
    }
    return 0;
}


int OrdenamientoMenu(eMenu men[],int tam)
{
    eMenu menAux;

    for(int i=0;i<tam-1;i++)
    {
        for(int j=i+1;j<tam;j++)
        {
            if(men[i].importe<men[j].importe)
            {
                menAux=men[i];
                men[i]=men[j];
                men[j]=menAux;
            }
            else if(men[i].importe==men[j].importe && strcmp(men[i].descripcion,men[j].descripcion)<0)
            {
                menAux=men[i];
                men[i]=men[j];
                men[j]=menAux;
            }
        }
    }
    mostrarMenues(men,tam);
    system("pause");
}

void mostrarMenu(eMenu menu)
{
    printf("%d   %10s   %.2f\n",menu.id,menu.descripcion,menu.importe);
}

void mostrarMenues(eMenu men[],int tam)
{
    printf("ID     Menu     Importe\n");
    for(int i=0;i<tam;i++)
    {
        if(men[i].isEmpty==OCUP)
        {
            mostrarMenu(men[i]);
        }
    }
}

void empleadosOpci(eEmployee emp[],int tam,eSector sector[],int tamSec)
{
    char seguir='s';
    do
    {
        switch(menuABM())
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
            seguir='n';
            break;
        }
    }
    while(seguir == 's');
}

int AltaEmpleado(eEmployee emp[],int tam,eSector sector[],int tamSec)
{
    int flag=0;
    for(int i=0;i<tam;i++)
    {
        if(emp[i].isEmpty==LIBRE)
        {
            printf("\nIngrese Apellido: ");
            fflush(stdin);
            gets(emp[i].Apellido);
            printf("\nIngrese Nombre: ");
            fflush(stdin);
            gets(emp[i].Nombre);
            printf("\nIngrese Sexo: m ò f");
            fflush(stdin);
            scanf("%c",&emp[i].sexo);
            printf("\nIngrese su Salario: ");
            scanf("%f",&emp[i].salario);
            printf("Ingrese Fecha de Ingreso: ");
            printf("Dia: ");
            scanf("%d",&emp[i].fecha.dia);
            printf("Mes: ");
            scanf("%d",&emp[i].fecha.mes);
            printf("Anio: ");
            scanf("%d",&emp[i].fecha.anio);

            emp[i].idSector=elegirSector(sector,tamSec);
            emp[i].isEmpty=OCUP;
            flag=1;

            printf("\n\nAgregado al Menu.\n");
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


int elegirSector(eSector sectores[], int tam)
{

    int i,idSector;

    printf("\nSectores \n\n");
    for(i=0; i<tam; i++)
    {
        printf("%d %s\n",sectores[i].id,sectores[i].descripcion);

    }
    printf("\nSeleccione sector: ");
    scanf("%d",&idSector);

    return idSector;
}
