#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int codigoJuego;
    char descripcion[51];
    float importe;
    int isEmpty;
}eJuego;

typedef struct{
    int codigoCliente;
    char apellido[51];
    char nombre[51];
    char sexo;
    char domicilio[51];
    int isEmpty;
}eCliente;

typedef struct{
    int codigoAlquiler;
    int codigoJuego;
    int codigoCliente;
    eFecha fecha;
    int isEmpty;
}eAlquiler;


/** \brief Muestro un Menu y Devuelvo la Opcion Ingresada
 *
 * \return int Retorno el valor ingresado por el usuario
 *
 */
int menu();
int menuABM();

void initJuego(eJuego list[],int len);
void initCliente(eCliente list[],int len);
void initAlquileres(eAlquiler list[],int len);


int BuscarCodigoJ(eJuego list[],int len,int codigo);
int BuscarCodigoC(eCliente list[],int len,int codigo);


int Juegos(eJuego list[],int len,int flag);
int AltaJuego(eJuego list[],int len);
int ModificacionJuego(eJuego list[],int len);
void listarJuegos(eJuego list[],int len);
void mostrarJuego(eJuego list);
void mostrarJuegos(eJuego list[],int len);


void clientes(eCliente list[],int len);
int AltaCliente(eCliente list[],int len);
int ModificacionCliente(eCliente list[],int len);
int BajaCliente(eCliente list[],int len);
void ListarClientes(eCliente list[],int len);
void mostrarCliente(eCliente list);
void mostrarClientes(eCliente list[],int len);

void alquileresJ(eAlquiler list[],int len,eCliente listCl[],int lenCl,eJuego listJu[],int lenJu);









#endif // FUNCIONES_H_INCLUDED
