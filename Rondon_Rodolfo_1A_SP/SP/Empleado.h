#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  float sueldo;
};
typedef struct S_Empleado Empleado;

int pedirNombreArchivo(char* Archivo);

int em_calcularSueldo(void* p);

float SueldoTotal(int horas, float precioxHora);

Empleado* nuevoEmpleado();
Empleado* empleado_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);

int employee_setId(Empleado* this,int id);
int employee_getId(Empleado* this,int* id);
int employee_setNombre(Empleado* this,char* nombre);
int employee_getNombre(Empleado* this,char* nombre);
int employee_setHorasTrabajadas(Empleado* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);
int employee_setSueldo(Empleado* this,float sueldo);
int employee_getSueldo(Empleado* this,float* sueldo);




#endif // EMPLEADO_H_INCLUDED
