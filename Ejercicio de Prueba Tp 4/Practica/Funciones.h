#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{

    int id;
    char nombre[50];
    float sueldo;

}ePersona;

ePersona* nuevaPersona();

int agregarPersona(LinkedList* this);
void mostrarLista(LinkedList *this);

int prueba(LinkedList* this);



#endif // FUNCIONES_H_INCLUDED
