#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Funciones.h"
#include "../../Library/input.h"

ePersona* nuevaPersona()
{
    ePersona* this;

    this =(ePersona*)malloc(sizeof(ePersona));

    if(this != NULL)
    {
        this->id=0;
        this->sueldo=0;
        strcpy(this->nombre,"");
    }
    else
    {
        system("cls");
        printf("No se ha encontrado mas Lugar en Memoria.\n");
        exit(0);
    }

    return this;

}


int agregarPersona(LinkedList* this)
{
    ePersona* Persona = nuevaPersona();
    int idAux;
    char nombreAux[50],direccionAux[60];
    float importe;

    if(this != NULL && Persona != NULL )
    {

        Persona->id = this->size;
        getString(&nombreAux,"Ingrese Nombre: ","ERROR. Nombre demasiado grande\n",0,50);
        strcpy(Persona->nombre,nombreAux);
        getFloat(&importe,"Ingrese Sueldo: ","ERROR Sueldo demasiado grande\n",0.00,25000.00);
        Persona->sueldo=importe;

        ll_add(this,Persona);

        printf("Agregado con Exito.");
        system("pause");
    }
    return 0;
}

void mostrarLista(LinkedList *this)
{
    ePersona* Persona = NULL;
    int len = ll_len(this);
    system("cls");
    printf("Cantidad de Personas en la lista: %d\n\n",len);
    for(int i=0;i<len;i++)
    {
        Persona = ll_get(this,i);
        printf("%d %s %.2f\n",Persona->id,Persona->nombre,Persona->sueldo);
    }
    system("pause");
}

int prueba(LinkedList* this)
{
    /*ePersona* persona = nuevaPersona();
    int len = ll_len(this);
    if(this != NULL)
    {
        for(int i=0;i<len;i++)
        {
            if(i == 2)
            {
                ll_remove(this,i);
            }
        }
    }*/

    if(ll_clear(this) == 0)
    {
        printf("Se limpio la lista con exito");
        system("pause");
    }
    else
    {
        printf("Hubo un error al limpiar la lista");
    }
    return 0;
}
