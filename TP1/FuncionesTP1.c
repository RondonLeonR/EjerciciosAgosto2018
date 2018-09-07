#include <stdio.h>
#include <stdlib.h>

int fun_getNumber(float* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
    int ret;
    float num;

    while(reintentos>0)
    {
        printf(mensaje);
        if(scanf("%f",&num)==1);
        {
            if(num<=maximo&&num>=minimo)
            {
                break;
            }
        }
        fflush(stdin);

        reintentos--;
        printf(mensajeError);
    }

    if(reintentos==0)
    {
        ret=1;
    }
    else
    {
        ret=0;
        *pResultado = num;
    }
    return ret;
}

int fun_OpcOne(float *num1)
{
    int ret;
    float num;
    ret = fun_getNumber(&num,"Ingrese el 1er Operando: \n","Error. Numero NO valido\n",0,1000,3);
        if(ret==0)
        {
            printf("\n\tNumero Ingresado con Exito\n");
            *num1=num;
        }
        else{
            printf("\n\tERROR. Numero NO Ingresado\n");
        }
    system("pause");
}

int fun_OpcTwo(float *num2)
{
    int ret;
    float num;
    ret = fun_getNumber(&num,"Ingrese el 2do Operando: \n","Error. Numero NO valido\n",0,1000,3);
        if(ret==0)
        {
            printf("\n\tNumero Ingresado con Exito\n");
            *num2 = num;
        }
        else
        {
            printf("\n\tERROR. Numero NO Ingresado\n");
        }
}

int fun_OpcThree(float *sum,float *num1, float *num2)
{
    float num1Aux,num2Aux,sumAux;
    num1Aux=*num1;
    num2Aux=*num2;

    fun_Sum(&sumAux,num1Aux,num2Aux);
        *sum=sumAux;



}

int fun_Sum(float *sum,float num1,float num2)
{
    int ret=1;
    float suma;

    suma= num1 + num2;
    *sum=suma;
    ret=0;

    return ret;
}
