#include "persona.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define LIBRE 1
#define OCUP 2
#define BAJA -2

void init(EPersona lista[], int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        lista[i].isEmpty = LIBRE;
        lista[i].id=i+1;
    }
}

int obtenerEspacioLibre(EPersona lista[], int len)
{
    int i;
    int retorno = -1;

    for(i=0; i<len; i++)
    {
        if(lista[i].isEmpty == LIBRE)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

void mostrarUsuario(EPersona usuario)
{


    printf("\n%d\t%s\t%s\t\t%ld\t %02d/%02d/%04d\n",usuario.id,usuario.nombre,usuario.apellido,usuario.dni,usuario.feNac.dia,usuario.feNac.mes,usuario.feNac.anio);


}

void mostrarArrayDeUsuarios(EPersona lista[], int tam)
{

    int i;
    printf("ID\tNombre\tApellido\tDNI\tFecha de Nac.\n");
    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty==OCUP)
        {
            mostrarUsuario(lista[i]);
        }
    }
}


int buscarPorDni(EPersona lista[], long int dni,int len)
{
    int i,retorno=-1;

    for(i=0; i<len; i++)
    {
        if(lista[i].dni==dni)
        {
            retorno=i;
        }
    }
    return retorno;
}



void alta(EPersona lista[], int len)
{
    int index;

    index = obtenerEspacioLibre(lista, len);

    if(index == -1)
    {
        printf("No hay mas lugar\n");
    }
    else
    {
        system("cls");
        printf("Ingrese Nombre: \n");
        fflush(stdin);
        gets(lista[index].nombre);
        printf("Ingrese Apellido: \n");
        fflush(stdin);
        gets(lista[index].apellido);
        printf("Ingrese DNI: \n");
        scanf("%ld",&lista[index].dni);
        printf("\nIngrese Fecha de Nacimiento: \n");
        printf("Dia: ");
        scanf("%d",&lista[index].feNac.dia);
        printf("Mes: ");
        scanf("%d",&lista[index].feNac.mes);
        printf("Anio: ");
        scanf("%d",&lista[index].feNac.anio);
        printf("\n\n\tUsuario Ingresado.\n");
        system("pause");

        lista[index].isEmpty=OCUP;

    }

    return;
}


void baja(EPersona lista[], int len)
{
    int dniIngresado,idEncontrado;
    char opc;
    system("cls");
    mostrarArrayDeUsuarios(lista,len);
    printf("\nIngrese el DNI del Usuario a dar de Baja: ");
    scanf("%d",&dniIngresado);
    idEncontrado=buscarPorDni(lista,dniIngresado,len);
    system("cls");
    if(idEncontrado==-1)
    {
        printf("\nUsuario no Encontrado.\n");
        system("pause");
    }
    else
    {
        printf("Usuario Encontrado: ");
        mostrarUsuario(lista[idEncontrado]);
        printf("\n\nDesea dar de Baja? s ò n");
        fflush(stdin);
        scanf("%c",&opc);
        if(opc=='n')
        {
            printf("\n\n\tOperacion Cancelada.\n\n");
            system("pause");
        }
        else
        {
            lista[idEncontrado].isEmpty=BAJA;
            printf("\n\n\tUsuario Dado de Baja.\n\n");
            system("pause");
        }
    }
}


void modificar(EPersona lista[],int len){
    system("cls");
    int DniIngresado,IdEncontrado;

    mostrarArrayDeUsuarios(lista,len);
    printf("Ingrese El DNI del Usuario a Modificar: ");
    scanf("%d",&DniIngresado);
    IdEncontrado=buscarPorDni(lista,DniIngresado,len);



}



