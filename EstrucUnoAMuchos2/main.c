#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int idSector;
    int isEmpty;
} eEmpleado;

typedef struct
{
    int id;
    char descripcion[20];
} eSector;

void inicializarEmpleados( eEmpleado x[], int tam);
void hardcodeo(eEmpleado empleados[]);
int buscarLibre( eEmpleado x[], int tam);
int buscarEmpleado(eEmpleado x[], int tam, int legajo);
void mostrarEmpleado(eEmpleado emp, eSector sectores[],int tamSectores);
void mostrarEmpleados(eEmpleado nomina[], int tam,eSector sectores[],int tamSectores);
void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSectores);
void eliminarEmpleado(eEmpleado *empleados, int tam, eSector sectores[],int tamSectores);
void modificarEmpleado(eEmpleado empleados[], int tam,eSector sectores[],int tamSectores);
int elegirSector(eSector sectores[], int tam);
void cargarDescripcion(eSector sectores[],int tamSector,int idSector,char cadena[]);
void listarEmpleadosPorSector(eEmpleado x[],int tam,eSector sectores[],int tamSector);
void ordenamientoSectorNombre(eEmpleado empleados[],int tam,eSector sectores[],int tamSector);
int menu();

int main()
{

    char seguir = 's';
    eEmpleado lista[10];
    eSector sectores[] = {{1,"RRHH"},{2,"Ventas"},{3,"Compras"},{4,"Contable"},{5,"Sistemas"}};

    inicializarEmpleados(lista, 10);
    hardcodeo(lista);


    do
    {
        switch(menu())
        {

        case 1:
            agregarEmpleado(lista, 10,sectores,5);
            system("pause");
            break;
        case 2:
            eliminarEmpleado(lista, 10,sectores,5);
            break;
        case 3:
            modificarEmpleado(lista, 10,sectores,5);
            break;
        case 4:
            mostrarEmpleados(lista, 10,sectores,5);
            system("pause");
            break;
        case 5:
            listarEmpleadosPorSector(lista, 10,sectores,5);
            break;
        case 6:
            break;
        case 10:
            seguir = 'n';
            break;
        }

    }
    while(seguir == 's');



    return 0;
}

void inicializarEmpleados( eEmpleado x[], int tam)
{
    int i;
    for(i=0; i < tam; i++)
    {
        x[i].isEmpty = 0;
    }
}

int buscarLibre( eEmpleado x[], int tam)
{
    int indice = -1;

    for(int i=0; i< tam; i++)
    {

        if( x[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(eEmpleado x[], int tam, int legajo)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {


        if( x[i].legajo == legajo && x[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int menu()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificar\n");
    printf("4- Listar\n");
    printf("5- Listar todos los empleados de un Sector\n");
    printf("6- Ordenar por Sectores y por Nombres\n");
    printf("10- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSectores)
{
    eEmpleado nuevoEmpleado;
    int indice;
    int esta;
    int legajo;

    indice = buscarLibre(empleados, tam);

    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(empleados, tam, legajo);

        if(esta != -1)
        {
            printf("Existe un empleado con el legajo %d\n", legajo);
            mostrarEmpleado( empleados[esta],sectores,tamSectores);
        }
        else
        {
            nuevoEmpleado.legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado.sexo);

            printf("Ingrese sueldo: ");
            fflush(stdin);
            scanf("%f", &nuevoEmpleado.sueldo);

            nuevoEmpleado.idSector=elegirSector(sectores,tamSectores);

            nuevoEmpleado.isEmpty = 1;

            empleados[indice] = nuevoEmpleado;

        }
    }

}

void mostrarEmpleado(eEmpleado emp, eSector sectores[],int tamSectores)
{
    char descripcion[20];
    cargarDescripcion(sectores,tamSectores,emp.idSector,descripcion);

    printf("%d %s %c %.2f %s\n\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo,descripcion);

}


void mostrarEmpleados(eEmpleado nomina[], int tam,eSector sectores[],int tamSectores)
{
    for(int i=0; i< tam; i++)
    {
        if( nomina[i].isEmpty == 1)
        {
            mostrarEmpleado(nomina[i],sectores,tamSectores);
        }
    }
}

void eliminarEmpleado(eEmpleado empleados[], int tam,eSector sectores[],int tamSectores)
{

    int legajo;
    int indice;
    char borrar;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(empleados, tam, legajo);

    if( indice == -1)
    {
        printf("No hay ningun empleado con el legajo %d\n", legajo);
    }
    else
    {
        mostrarEmpleado( empleados[indice],sectores,tamSectores);

        printf("\nConfirma borrado?: ");
        fflush(stdin);
        scanf("%c", &borrar);
        if(borrar != 's')
        {
            printf("Borrado cancelado\n\n");
        }
        else
        {
            empleados[indice].isEmpty = 0;
            printf("Se ha eliminado el empleado\n\n");
        }
        system("pause");
    }

}

void modificarEmpleado(eEmpleado empleados[], int tam,eSector sectores[],int tamSectores)
{

    int legajo;
    int indice;
    char modificar;
    float nuevoSueldo;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(empleados, tam, legajo);

    if( indice == -1)
    {
        printf("No hay ningun empleado con el legajo %d\n", legajo);
    }
    else
    {
        mostrarEmpleado( empleados[indice],sectores,tamSectores);

        printf("\nModifica sueldo?: ");
        fflush(stdin);
        scanf("%c", &modificar);
        if(modificar != 's')
        {
            printf("Modificacion cancelada\n\n");
        }
        else
        {
            printf("Ingrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);

            empleados[indice].sueldo = nuevoSueldo;
            printf("Se ha modificado el sueldo con exito\n\n");
        }

        system("pause");
    }



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


void cargarDescripcion(eSector sectores[],int tamSector,int idSector,char cadena[])
{

    for(int i=0; i<tamSector; i++)
    {
        if(sectores[i].id ==  idSector)
        {
            strcpy(cadena,sectores[i].descripcion);
            break;
        }
    }
}

void listarEmpleadosPorSector(eEmpleado emp[],int tam,eSector sectores[],int tamSector)
{
    int idSector,i;

    idSector=elegirSector(sectores,tamSector);
    system("cls");
    printf("Empleados: \n\n");
    for(i=0;i<tam;i++){
        if(emp[i].isEmpty==1 &&emp[i].idSector==idSector){
            mostrarEmpleado(emp[i],sectores,tamSector);
        }
    }
    system("pause");
}

void hardcodeo(eEmpleado empleados[]){
    eEmpleado emp[]= {
    {1111,"Ana",'f',10000,1,1},
    {2222,"Luis",'m',20000,2,1},
    {3333,"Laura",'f',30000,1,1}
    };

    for(int i=0;i<5;i++){
        empleados[i]=emp[i];
    }
}

void ordenamientoSectorNombre(eEmpleado empleados[],int tam,eSector sectores[],int tamSector){

    eSector SectorAux;

    for(int i=0;i<tamSector-1;i++){
        for(int j=i+1;j<tamSector;j++){
            if(strcmp(sectores[i].descripcion,sectores[j].descripcion)>0){
                SectorAux=sectores[i];
                sectores[i]=sectores[j];
                sectores[j]=SectorAux;
            }

        }
    }




}
