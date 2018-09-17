#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**1ra Forma, Definicion de Estructura**/
/*struct empleado{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
};*/

/**2da Forma, Definicion de tipo de dato
**/
typedef struct{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
}eEmpleado;

void mostrarEmpleado(eEmpleado employee);

int main()
{
    eEmpleado unEmpleado;
    eEmpleado otroEmpleado;
    eEmpleado emp3 = {2222, "Jose", 'm', 20000};
    eEmpleado emp4;
    eEmpleado emp5;

    emp4 = emp3;

    unEmpleado.legajo = 1234;
    strcpy(unEmpleado.nombre,"Juan");
    unEmpleado.sexo='m';
    unEmpleado.sueldo=10000.5;


    otroEmpleado.legajo = 1122;
    strcpy(otroEmpleado.nombre,"Lucia");
    otroEmpleado.sexo= 'f';
    otroEmpleado.sueldo=15000.75;

    printf("Ingrese Legajo: ");
    scanf("%d",&emp5.legajo);
    fflush(stdin);
    printf("Ingrese Nombre: ");
    scanf("%s",&emp5.nombre);
    fflush(stdin);
    printf("Ingrese Sexo: ");
    scanf("%c",&emp5.sexo);
    printf("Ingrese Sueldo: ");
    scanf("%f",&emp5.sueldo);

    mostrarEmpleado(unEmpleado);
    mostrarEmpleado(otroEmpleado);
    mostrarEmpleado(emp3);
    mostrarEmpleado(emp4);
    mostrarEmpleado(emp5);
    return 0;
}
/**Paso una COPIA de la estructura**/
void mostrarEmpleado(eEmpleado employee){

    printf("%d %s %c %.2f\n",employee.legajo,employee.nombre,employee.sexo,employee.sueldo);


}
