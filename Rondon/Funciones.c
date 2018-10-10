#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Funciones.h"
#include "input.h"

#define LIBRE 1
#define OCUP 0


void initJuego(eJuego list[],int len)
{
    for(int i=0; i<len; i++)
    {
        list[i].isEmpty=LIBRE;
        list[i].codigoJuego=i;
    }
}

void initCliente(eCliente list[],int len)
{
    for(int i=0; i<len; i++)
    {
        list[i].isEmpty=LIBRE;
        list[i].codigoCliente=i;
    }
}

void initAlquileres(eAlquiler list[],int len)
{
    for(int i=0; i<len; i++)
    {
        list[i].isEmpty=LIBRE;
        list[i].codigoAlquiler=i;
    }
}


int BuscarCodigoC(eCliente list[],int len,int codigo)
{
    int retorno=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].codigoCliente==codigo && list[i].isEmpty == OCUP)
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
    printf("  1- JUEGOS\n");
    printf("  2- CLIENTES\n");
    printf("  3- ALQUILERES\n");

    printf("  4- Salir\n\n");
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

int Juegos(eJuego list[],int len,int flag)
{
    int retorno=0;
    switch(menuABM())
    {

    case 1:
        retorno=1;
        AltaJuego(list,len);
        break;
    case 2:
        if(flag==1)
        {
            ModificacionJuego(list,len);
        }
        else
        {
            system("cls");
            printf("No se Ingreso Ningun Juego todavia.\n\n");
            system("pause");
        }
        break;
    case 3:
        if(flag==1)
        {
            BajaJuego(list,len);
        }
        else
        {
            system("cls");
            printf("No se Ingreso Ningun Juego todavia.\n\n");
            system("pause");
        }

        break;
    case 4:
        if(flag==1)
        {
            listarJuegos(list,len);
        }
        else
        {
            system("cls");
            printf("No se Ingreso Ningun Juego todavia.\n\n");
            system("pause");
        }

        break;
    default:
        break;
    }
    return retorno;
}

void mostrarJuego(eJuego list)
{
    printf("%d  %s  %.2f\n",list.codigoJuego,list.descripcion,list.importe);
}

void mostrarJuegos(eJuego list[],int len)
{
    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==OCUP)
        {
            mostrarJuego(list[i]);
        }
    }
}

int BuscarCodigoJ(eJuego list[],int len,int codigo)
{
    int retorno=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].codigoJuego == codigo && list[i].isEmpty == OCUP)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int AltaJuego(eJuego list[],int len)
{
    int flag=0;
    char descrip[51];
    float importe;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==1)
        {
            getString(descrip,"Ingrese Descripcion Del Juego: ","Cantidad de Caracteres excedida\n",0,51);
            strcpy(list[i].descripcion,descrip);
            getFloat(&importe,"Ingrese Importe del Juego: ","El importe es menor que cero\n",1.00,1000.00);
            list[i].importe=importe;
            list[i].isEmpty=OCUP;
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

int ModificacionJuego(eJuego list[],int len)
{
    int opc,opc2,CodigoBusc;
    int flag=1;
    char descrip[51];
    float importe;

    system("cls");
    mostrarJuegos(list,len);
    printf("\n\nIngrese el Codigo del Juego a Modificar: ");
    scanf("%d",&opc);

    CodigoBusc=BuscarCodigoJ(list,len,opc);
    system("cls");

    if(CodigoBusc==-1)
    {

        printf("\n\nCodigo No encontrado\n");
        system("pause");
    }
    else
    {
        printf("JUEGO: \n");
        mostrarJuego(list[CodigoBusc]);

        printf("\n ****Modificar**** \n\n");
        printf(" 1-Descripcion\n");
        printf(" 2-Importe\n");
        printf(" 3-Cancelar\n");
        fflush(stdin);
        scanf("%d",&opc2);
        switch(opc2)
        {
        case 1:
            getString(&descrip,"Ingrese Nueva Descripcion: ","Cantidad de Caracteres excedida\n",0,51);
            strcpy(list[CodigoBusc].descripcion,descrip);
            break;
        case 2:
            getFloat(&importe,"Ingrese Nuevo Importe: ","El importe es Menor que cero\n",0,20000);
            break;
        default:
            printf("Modificacion Cancelada\n");
            system("pause");
            break;
        }


    }

    return 0;
}


int BajaJuego(eJuego list[],int len)
{
    int opc,CodigoB;
    int flag=1;
    char opc2;

    system("cls");
    mostrarJuegos(list,len);
    printf("\n\nIngrese el Codigo del Juego a Dar de Baja: ");
    scanf("%d",&opc);

    CodigoB=BuscarCodigoJ(list,len,opc);
    system("cls");

    if(CodigoB== -1)
    {
        printf("Codigo No encontrado.");
        system("pause");
    }
    else
    {
        printf("Codigo Encontrado: \n");
        mostrarJuego(list[CodigoB]);
        printf("Desea Dar de Baja? 's' o 'n'");
        fflush(stdin);
        scanf("%c",&opc2);
        if(opc2== 's' || opc2 == 'S')
        {
            system("cls");
            list[CodigoB].isEmpty=LIBRE;
            printf("\nJuego Borrado.\n\n");
            system("pause");
        }
        else
        {
            printf("Baja Cancelada\n\n");
            system("pause");
        }

    }
    return 0;
}


void listarJuegos(eJuego list[],int len)
{
    eJuego listAux;

    for(int i=0; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(list[i].importe<list[j].importe)
            {
                listAux=list[i];
                list[i]=list[j];
                list[j]=listAux;
            }
            if(list[i].importe==list[j].importe && strcmp(list[i].descripcion,list[j].descripcion)>0)
            {
                listAux=list[i];
                list[i]=list[j];
                list[j]=listAux;
            }
        }
    }
    mostrarJuegos(list,len);
    printf("\n\n");
    system("pause");
}

void mostrarCliente(eCliente list)
{
    printf("%d  %s  %s  %c  %s\n",list.codigoCliente,list.apellido,list.nombre,list.sexo,list.domicilio);
}

void mostrarClientes(eCliente list[],int len)
{
    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==OCUP)
        {
            mostrarCliente(list[i]);
        }
    }
}

int opcClientes(eCliente list[],int len,int flag)
{
    int retorno= 0;
    switch(menuABM())
    {
    case 1:
        AltaCliente(list,len);
        retorno=1;
        break;
    case 2:
        if(flag==1)
        {
            ModificacionCliente(list,len);
        }
        else
        {
            system("cls");
            printf("No se Ingreso Ningun Juego todavia.\n\n");
            system("pause");
        }
        break;
    case 3:
        if(flag==1)
        {
            BajaCliente(list,len);
        }
        else
        {
            system("cls");
            printf("No se Ingreso Ningun Juego todavia.\n\n");
            system("pause");
        }
        break;
    case 4:
        if(flag==1)
        {
            ListarClientes(list,len);
        }
        else
        {
            system("cls");
            printf("No se Ingreso Ningun Juego todavia.\n\n");
            system("pause");
        }

        break;
    default:
        break;
    }
    return retorno;
}


int AltaCliente(eCliente list[],int len)
{
    int flag=0;
    int flag2=0;
    char Apellido[51];
    char Nombre[51];
    char Domicilio[51];
    char sex;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==1)
        {
            getString(Apellido,"Ingrese su Apellido: ","Cantidad de Caracteres excedida\n",0,51);
            strcpy(list[i].apellido,Apellido);
            getString(Nombre,"Ingrese su Nombre: ","Cantidad de Caracteres excedida\n",0,51);
            strcpy(list[i].nombre,Nombre);
            getString(Domicilio,"Ingrese su Domicilio: ","Cantidad de Caracteres excedida\n",0,51);
            strcpy(list[i].domicilio,Domicilio);
            do
            {
                printf("Ingrese Sexo: 'm' o 'f'");
                fflush(stdin);
                scanf("%c",&sex);

            }
            while(!(sex == 'm' || sex == 'f' || sex == 'M' || sex == 'F'));

            list[i].sexo=sex;

            list[i].isEmpty=OCUP;
            flag2=1;

            printf("\n\nAgregado.\n");
            system("pause");
            break;
        }

    }

    if(flag2==0)
    {
        system("cls");
        printf("\n\n\tNo hay mas Lugar.\n\n");
        system("pause");
    }
    return 0;
}

int ModificacionCliente(eCliente list[],int len)
{
    int opc,opc2,CodigoBusc;
    char Apellido[51];
    char Nombre[51];
    char Domicilio[51];
    char sex;

    system("cls");
    mostrarClientes(list,len);
    printf("\n\nIngrese el Codigo del Cliente a Modificar: ");
    scanf("%d",&opc);

    CodigoBusc=BuscarCodigoC(list,len,opc);
    system("cls");

    if(CodigoBusc==-1)
    {

        printf("\n\nCodigo No encontrado\n");
        system("pause");
    }
    else
    {
        printf("CLIENTE: \n");
        mostrarCliente(list[CodigoBusc]);

        printf("\n ****Modificar**** \n\n");
        printf(" 1-Apellido\n");
        printf(" 2-Nombre\n");
        printf(" 3-Sexo\n");
        printf(" 4-Domicilio\n");
        printf(" 5-Cancelar\n");
        fflush(stdin);
        scanf("%d",&opc2);
        switch(opc2)
        {
        case 1:
            getString(&Apellido,"Ingrese Nuevo Apellido: ","Cantidad de Caracteres excedida\n",0,51);
            strcpy(list[CodigoBusc].apellido,Apellido);
            break;
        case 2:
            getString(&Nombre,"Ingrese Nuevo Nombre: ","Cantidad de Caracteres excedida\n",0,51);
            strcpy(list[CodigoBusc].nombre,Nombre);
            break;
        case 3:
            do
            {
                printf("Ingrese Sexo: 'm' o 'f'");
                fflush(stdin);
                scanf("%c",&sex);

            }
            while(!(sex == 'm' || sex == 'f' || sex == 'M' || sex == 'F'));
            break;
        case 4:
            getString(&Domicilio,"Ingrese Nuevo Domicilio: ","Cantidad de Caracteres excedida\n",0,51);
            strcpy(list[CodigoBusc].domicilio,Domicilio);
            break;
        default:
            printf("Modificacion Cancelada\n");
            system("pause");
            break;
        }


    }

    return 0;
}



int BajaCliente(eCliente list[],int len)
{
    int opc,CodigoB;
    int flag=1;
    char opc2;

    system("cls");
    mostrarClientes(list,len);
    printf("\n\nIngrese el Codigo del Cliente a Dar de Baja: ");
    scanf("%d",&opc);

    CodigoB=BuscarCodigoC(list,len,opc);
    system("cls");

    if(CodigoB== -1)
    {
        printf("Codigo No encontrado.");
        system("pause");
    }
    else
    {
        printf("Codigo Encontrado: \n");
        mostrarCliente(list[CodigoB]);
        printf("Desea Dar de Baja? 's' o 'n'");
        fflush(stdin);
        scanf("%c",&opc2);
        if(opc2== 's' || opc2 == 'S')
        {
            system("cls");
            list[CodigoB].isEmpty=LIBRE;
            printf("\nCliente Borrado.\n\n");
            system("pause");
        }
        else
        {
            printf("Baja Cancelada\n\n");
            system("pause");
        }

    }
    return 0;
}

void ListarClientes(eCliente list[],int len)
{
    eCliente listAux;

    for(int i=0; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(strcmp(list[i].apellido,list[j].apellido)>0)
            {
                listAux=list[i];
                list[i]=list[j];
                list[j]=listAux;
            }
            if(strcmp(list[i].apellido,list[j].apellido)==0 && strcmp(list[i].nombre,list[j].nombre)>0)
            {
                listAux=list[i];
                list[i]=list[j];
                list[j]=listAux;
            }
        }
    }
    mostrarClientes(list,len);
    printf("\n\n");
    system("pause");
}


void alquileresJ(eAlquiler list[],int len,eCliente listCl[],int lenCl,eJuego listJu[],int lenJu)
{
    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==LIBRE)
        {
            system("cls");
            mostrarClientes(listCl,lenCl);
            printf("\nIngrese el Codigo del Cliente: ");
            scanf("%d",&list[i].codigoCliente);


            mostrarJuegos(listJu,lenJu);
            printf("Ingrese el Codigo del Juego: ");
            scanf("%d",&list[i].codigoJuego);
            system("cls");
            printf("\nIngrese Fecha \n");
            printf("Dia: \n");
            scanf("%d",&list[i].fecha.dia);
            printf("Mes: \n");
            scanf("%d",&list[i].fecha.mes);
            printf("Anio: \n");
            scanf("%d",&list[i].fecha.anio);

            list[i].isEmpty=OCUP;
            break;
        }
    }
}
