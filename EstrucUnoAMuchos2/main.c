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

typedef struct
{
    int id;
    char descripcion[20];
    int isEmpty;
} eMenu;

typedef struct
{
    int id;
    int idEmpleado;
    int idMenu;
    int isEmpty;
} eEmpleadoMenu;

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
void MayorSueldoPorSector(eEmpleado lista[],int tam, eSector sectores[],int tamSector);
void cargarDescripcionComida(eMenu comidas[],int tamComida,int idComida,char cadena[]);
void mostrarAlmuerzos(eMenu comidas[], int tamComida, eEmpleadoMenu Almuerzo[],int tamAlmuerzo,eEmpleado empleados[],int tamEmpleados);
void mostrarAlumerzosxEmpleados(eMenu comidas[], int tamComida, eEmpleadoMenu Almuerzo[],int tamAlmuerzo,eEmpleado empleados[],int tamEmpleados,eSector sectore[],int tamSector);
int menu();

int main()
{

    char seguir = 's';
    eEmpleado lista[10];
    eSector sectores[] = {{1,"RRHH"},{2,"Ventas"},{3,"Compras"},{4,"Contable"},{5,"Sistemas"}};
    eMenu menu2[] =
    {
        {1,"Milanesa",0},
        {2,"Fideos",0},
        {3,"Pizza",0},
        {4,"Sopa",0},
        {5,"Pescado",0}
    };

    eEmpleadoMenu Almuerzo[] =
    {
        {1,2222,1,0},
        {2,1111,3,0},
        {3,3333,2,0},
        {4,4444,2,0},
        {5,5555,5,0},
        {6,1111,2,0},
        {7,3333,4,0},
        {8,4444,5,0},
        {9,2222,2,0},
        {10,5555,3,0},
        {11,1111,4,0}
    };

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
            ordenamientoSectorNombre(lista,10,sectores,5);
            system("pause");
            break;
        case 7:
            MayorSueldoPorSector(lista,10,sectores,5);
            break;
        case 8:
            system("cls");
            mostrarAlmuerzos(menu2,5,Almuerzo,20,lista,10);
            system("pause");
            break;
        case 9:
            system("cls");
            mostrarAlumerzosxEmpleados(menu2,5,Almuerzo,20,lista,10,sectores,5);
            system("pause");
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
    printf("7- Empleado con Mayor Sueldo Por Sector\n");
    printf("8- Mostrar Almuerzos\n");
    printf("9- Mostrar Almuerzos por Empleados\n");
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

void cargarDescripcionComida(eMenu comidas[],int tamComida,int idComida,char cadena[])
{

    for(int i=0; i<tamComida; i++)
    {
        if(comidas[i].id == idComida)
        {
            strcpy(cadena,comidas[i].descripcion);
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
    for(i=0; i<tam; i++)
    {
        if(emp[i].isEmpty==1 &&emp[i].idSector==idSector)
        {
            mostrarEmpleado(emp[i],sectores,tamSector);
        }
    }
    system("pause");
}

void hardcodeo(eEmpleado empleados[])
{
    eEmpleado emp[]=
    {
        {1111,"Ana",'f',10000,1,1},
        {2222,"Luis",'m',20000,2,1},
        {3333,"Laura",'f',30000,1,1},
        {4444,"Juan",'m',15000,2,1},
        {5555,"Agustin",'m',30000,1,1}
    };

    for(int i=0; i<5; i++)
    {
        empleados[i]=emp[i];
    }
}

void ordenamientoSectorNombre(eEmpleado empleados[],int tam,eSector sectores[],int tamSector)
{

    eSector SectorAux;
    eEmpleado empleadosAux;

    for(int i=0; i<tamSector-1; i++)
    {
        for(int j=i+1; j<tamSector; j++)
        {
            if(strcmp(sectores[i].descripcion,sectores[j].descripcion)>0)
            {
                SectorAux=sectores[i];
                sectores[i]=sectores[j];
                sectores[j]=SectorAux;
            }
            else if(strcmp(sectores[i].descripcion,sectores[j].descripcion) == 0 && strcmp(empleados[i].nombre,empleados[j].nombre)>0)
            {
                empleadosAux=empleados[i];
                empleados[i]=empleados[j];
                empleados[j]=empleadosAux;
            }

        }
    }
    mostrarEmpleados(empleados,tam,sectores,tamSector);

}


void MayorSueldoPorSector(eEmpleado lista[],int tam, eSector sectores[],int tamSector)
{
    float SueldoMay1=0;
    char descripcion[20];
    int idSector,idMaySueldo,idMaySueldo2,flag=0;

    idSector=elegirSector(sectores,tamSector);
    cargarDescripcion(sectores,tamSector,idSector,descripcion);

    system("cls");

    for(int i=0; i<tam; i++)
    {
        if(flag==0 || lista[i].sueldo>SueldoMay1 && lista[i].idSector == idSector)
        {
            SueldoMay1=lista[i].sueldo;
            idMaySueldo=i;
            flag=1;
            continue;
        }
        else if(lista[i].sueldo==SueldoMay1 && lista[i].idSector == idSector)
        {
            idMaySueldo2=i;
        }
    }
    printf("Los mayores sueldos del sector: %s\n\n",descripcion);

    for(int i=0; i<tam; i++)
    {
        if(lista[i].idSector==idSector)
        {
            if(idMaySueldo2==i || idMaySueldo==i)
            {
                mostrarEmpleado(lista[i],sectores,tamSector);
            }
        }
    }
    system("pause");
}

void mostrarAlmuerzos(eMenu comidas[], int tamComida, eEmpleadoMenu Almuerzo[],int tamAlmuerzo,eEmpleado empleados[],int tamEmpleados)
{
    char descripcionComida[20];

    printf("Legajo\tNombre\tComida\n\n");

    for(int i=0; i<tamAlmuerzo; i++)
    {
        if(Almuerzo[i].isEmpty==0)
        {
            for(int j=0; j<tamEmpleados; j++)
            {
                if(Almuerzo[i].idEmpleado==empleados[j].legajo)
                {
                    for(int l=0; l<tamComida; l++)
                    {
                        if(Almuerzo[i].idMenu==comidas[l].id)
                        {
                            cargarDescripcionComida(comidas,tamComida,comidas[l].id,descripcionComida);
                            printf("%d\t%s\t%s\n",Almuerzo[i].idEmpleado,empleados[j].nombre,descripcionComida);
                        }
                    }
                }
            }
        }
    }
}



void mostrarAlumerzosxEmpleados(eMenu comidas[], int tamComida, eEmpleadoMenu Almuerzo[],int tamAlmuerzo,eEmpleado empleados[],int tamEmpleados,eSector sectore[],int tamSector)
{
    char descripcionComida[20];
    int legajoIngresado;
    mostrarEmpleados(empleados,tamEmpleados,sectore,tamSector);
    printf("Ingrese el Legajo: ");
    scanf("%d",&legajoIngresado);
    system("cls");

    for(int l=0; l<tamEmpleados; l++)
    {
        if(legajoIngresado == empleados[l].legajo)
        {
            printf("Almuerzos del Legajo: %s\n",empleados[l].nombre);

            for(int i=0; i<tamAlmuerzo; i++)
            {
                if(legajoIngresado == Almuerzo[i].idEmpleado)
                {
                    for(int j=0; j<tamComida; j++)
                    {
                        if(Almuerzo[i].idMenu==comidas[j].id)
                        {
                            cargarDescripcionComida(comidas,tamComida,comidas[j].id,descripcionComida);
                            printf("%s\t%s\n",empleados[l].nombre,descripcionComida);
                        }
                    }
                }
            }
        }
    }

}

