#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int flag=1;
    do
    {
        printf("%s",message);
        scanf("%d",input);

        if((*input)>=lowLimit  && (*input)<=hiLimit)
        {
            flag=0;
        }
        else
        {
            printf("%s",eMessage);
        }
    }
    while(flag==1);

    return 0;
}

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    float x;
    int flag=1;
    do
    {
        printf("%s",message);
        scanf("%f",&x);

        if(x>=lowLimit  && x<=hiLimit)
        {
            flag=0;
            *input=x;
        }
        else
        {
            printf("%s",eMessage);
        }
    }
    while(flag==1);
    return 0;
}


/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    int flag=1;
    do
    {
        printf("%s",message);
        fflush(stdin);
        scanf("%c",input);

        if((*input)>=lowLimit  && (*input)<=hiLimit)
        {
            flag=0;
        }
        else
        {
            printf("%s",eMessage);
        }
    }
    while(flag==1);

    return 0;
}


/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int flag=1;
    int len;
    char x[hiLimit];

    do
    {
        printf("%s",message);
        fflush(stdin);
        gets(x);

        len= strlen(x);

        if(len>=lowLimit  && len<=hiLimit)
        {
            flag=0;
            strcpy(input,x);
        }
        else
        {
            printf("%s",eMessage);
        }
    }
    while(flag==1);

    return 0;
}
