#ifndef NEGOCIO_H_INCLUDED
#define NEGOCIO_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int legajo;
    char Apellido[52];
    char Nombre[52];
    char sexo;
    float salario;
    eFecha fecha;
    int idSector;
    int isEmpty;
} eEmployee;

typedef struct
{
    int id;
    char descripcion[20];
    float importe;
    int isEmpty;

}eMenu;

typedef struct
{
    int id;
    char descripcion[52];
}eSector;

typedef struct
{
    int id;
    int legajoEmp;
    int idComida;
    eFecha fecha;
    int isEmpty;

}eAlmuerzo;


void initEmployee(eEmployee emp[],int tamEmp);
void initMenu(eMenu men[],int tamMen);
int BuscarEmp(eEmployee emp[],int tamEmp,int legajo);
int menu();
int menuABM();

void MenuesOpci(eMenu menu[],int tamMen);
int AltaMenu(eMenu men[],int tam);
int ModificacionMenu(eMenu men[],int tam);
int BajaMenu(eMenu men[],int tam);
int OrdenamientoMenu(eMenu men[],int tam);

void mostrarMenu(eMenu menu);
void mostrarMenues(eMenu men[],int tam);

void empleadosOpci(eEmployee emp[],int tam,eSector sector[],int tamSec);
int AltaEmpleado(eEmployee emp[],int tam,eSector sector[],int tamSec);
int elegirSector(eSector sectores[], int tam);









#endif // NEGOCIO_H_INCLUDED
