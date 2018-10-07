#ifndef X_H_INCLUDED
#define X_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    //......
    //......
    //......
    //......
    int isEmpty;
}estruc;


/** \brief Muestro un Menu y Devuelvo la Opcion Ingresada
 *
 * \return int Retorno el valor ingresado por el usuario
 *
 */
int menu();

void init(estruc list[],int len);

/**Devuelvo la Posicion del Id en el Array**/
int BuscarId(estruc list[],int len,int id);

/**Alta**/
int Alta(estruc men[],int len);

int Modificacion(estruc men[],int len);




#endif // X_H_INCLUDED
