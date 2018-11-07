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
    int i,tam;
    tam = ll_len(pArrayListEmployee);
    printf(" ID       NAME    HOURS    SALARY\n");
    for(i=0; i<tam; i++)
    {
        this = (Employee*)ll_get(pArrayListEmployee,i);
        printf("%4d %10s   %4d   %6.2f\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
    }
    system("pause");
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
    int tam,i;
    char var1[50],var2[50],var3[50],var4[50];


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
        fflush(stdin);
        fwrite(this,sizeof(Employee),1,pFile);
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

