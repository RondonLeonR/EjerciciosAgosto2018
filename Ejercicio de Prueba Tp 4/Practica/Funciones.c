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
    char nombreAux[50];
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
    if(this != NULL && len>0)
    {
        printf("Cantidad de Personas en la lista: %d\n\n",len);
        for(int i=0;i<len;i++)
        {
            Persona = ll_get(this,i);
            printf("%d %s %.2f\n",Persona->id,Persona->nombre,Persona->sueldo);
        }
        system("pause");
    }
    else{
        printf("La lista no existe");
        system("pause");
    }

}





int prueba(LinkedList* this)
{
    ePersona* persona = nuevaPersona();
    int len = ll_len(this);
    int aux;
    if(this != NULL)
    {
        for(int i=0;i<len;i++)
        {
            if(i==2)
            {
                persona = ll_get(this,i);
                aux=ll_contains(this,persona);
                if(aux == 1)
                {
                    printf("EL ELEMENTO EXISTE");
                    system("pause");
                }
            }
        }
    }



    return 0;
}

int filterBySalary(ePersona* this)
{
    int retorno =0;

    if(this->sueldo > 1000.00)
    {
        retorno = 1;
    }

    return retorno;
}

LinkedList* filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* newLista = ll_newLinkedList();
    ePersona* persona = NULL;
    int len;
    printf("asdasa");
    system("pause");
    if(this != NULL)
    {
        len = ll_len(this);
        for(int i=0;i<len;i++)
        {
            persona=ll_get(this,i);
            if(pFunc(persona) == 1)
            {
                ll_add(newLista,persona);
            }
        }
    }
    return newLista;
}
