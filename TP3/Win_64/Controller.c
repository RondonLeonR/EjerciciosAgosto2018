#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    pFile = fopen(path,"r");

    if(pFile == NULL)
    {
        system("cls");
        printf("\nEl Archivo %s \nNo existe O No se ha encontrado\n",path);
        return 1;
    }
    parser_EmployeeFromText(pFile,pArrayListEmployee);
    fclose(pFile);
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    pFile = fopen(path,"rb");

    if(pFile == NULL)
    {
        system("cls");
        printf("\nEl Archivo %s \nNo existe O No se ha encontrado\n",path);
        exit(0);
    }
    parser_EmployeeFromBinary(pFile,pArrayListEmployee);
    fclose(pFile);
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee *this = employee_new();
    char name[50];
    int hours,r,id;
    float salary;

    printf("Ingrese ID: \n");
    scanf("%d",&id);
    fflush(stdin);
    printf("Ingrese Nombre: \n");
    gets(name);
    printf("Ingrese Horas Trabajadas: \n");
    scanf("%d",&hours);
    printf("Ingrese Salario: \n");
    scanf("%f",&salary);

    this->id = id;
    strncpy(this->nombre,name,sizeof(this->nombre));
    this->horasTrabajadas = hours;
    this->sueldo= salary;

    r=ll_add(pArrayListEmployee,this);
    if(r == 0)
    {
        printf("\nSe agrego con Exito\n\n");
        system("pause");
    }
    else
    {
        printf("Hubo un error al guardar. \n\n");
        system("pause");
    }

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee *this = employee_new();
    int i,r,opc,idAux,horasAux,tam;
    char nombreAux[50];
    float sueldoAux;
    controller_ListEmployee(pArrayListEmployee);
    printf("\n\n\tIngrese ID del usuario a Modificar: ");
    scanf("%d",&r);
    tam = ll_len(pArrayListEmployee);
    for(i=0; i<tam; i++)
    {
        if(i==r)//TERMINAR//
        {
            //if()

                this = (Employee*)ll_get(pArrayListEmployee,i);
        }
    }
    system("cls");
    if(this != NULL)
    {
        do
        {
            printf("1- Modificar ID\n");
            printf("2- Modificar Nombre\n");
            printf("3- Modificar Horas Trabajadas\n");
            printf("4- Modificar Sueldo\n");
            printf("5- Cancelar\n\n");
            printf("Seleccione opcion\n");
            scanf("%d",&opc);

            switch(opc)
            {
            case 1:
                printf("\n\nIngrese nuevo ID: ");
                scanf("%d",&idAux);
                employee_setId(this,idAux);
                break;
            case 2:
                printf("\n\nIngrese nuevo Nombre: ");
                gets(nombreAux);
                employee_setNombre(this,nombreAux);
                break;
            case 3:
                printf("\n\nIngrese nuevas Horas Trabajadas: ");
                scanf("%d",&horasAux);
                employee_setHorasTrabajadas(this,horasAux);
                break;
            case 4:
                printf("\n\nIngrese nuevo Sueldo: ");
                scanf("%f",&sueldoAux);
                employee_setSueldo(this,sueldoAux);
                break;
            case 5:
                system("cls");
                printf("\tOperacion Cancelada\n\n");
                system("pause");
                break;
            }
        }
        while(opc<5 && opc>0);
    }
    else
    {
        system("cls");
        printf("\nEl ID ingresado no Existe\n\n");
        system("pause");
    }

    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee *this = employee_new();
    int r;

    controller_ListEmployee(pArrayListEmployee);
    printf("\nIngrese el ID que desea Borrar: ");
    scanf("%d",&r);

    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* this;
    int i,tam,idAux,HorasAux;
    char nombreAux[50];
    float sueldoAux;

    tam = ll_len(pArrayListEmployee);

    printf("  ID     NAME     HOURS    SALARY\n");
    for(i=0; i<tam; i++)
    {
        this = (Employee*)ll_get(pArrayListEmployee,i);
        employee_getId(this,&idAux);
        employee_getNombre(this,nombreAux);
        employee_getHorasTrabajadas(this,&HorasAux);
        employee_getSueldo(this,&sueldoAux);

        printf("%4d %10s   %4d   %6.2f\n",idAux,nombreAux,HorasAux,sueldoAux);
    }

    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    Employee *this = employee_new();
    int tam,i,idAux,horasAux;
    float sueldoAux;
    char nombreAux[50];

    pFile = fopen(path,"w");
    tam = ll_len(pArrayListEmployee);
    system("cls");

    if(this == NULL || pFile == NULL)
    {
        printf("\nEl archivo no se encontro. \n\n");
        system("pause");
        return 1;
    }

    for(i=0; i<tam; i++)
    {
        this = (Employee*)ll_get(pArrayListEmployee,i);
        employee_getId(this,&idAux);
        employee_getNombre(this,nombreAux);
        employee_getHorasTrabajadas(this,&horasAux);
        employee_getSueldo(this,&sueldoAux);
        fflush(stdin);
        fprintf(pFile,"%d,%s,%d,%.2f\n",idAux,nombreAux,horasAux,sueldoAux);
    }

    fclose(pFile);

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

