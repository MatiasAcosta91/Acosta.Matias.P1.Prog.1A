#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5
/*
PARCIAL: PRIMER PARCIAL PROGRAMACION I
FECHA: 16/5/22
Autor: Acosta Matias Jordan
DNI: 36401197
DIVISION: 1A
PROFESOR: CHRISTIAN BAUS
*/
typedef struct
{
    int id;
    char nombre[20];
    char tipo;
    float efectividad;
} eVacuna;



float aplicarAumento(float precio);
int reemplazarCaracteres (char cadena[],char caracterUno,char caracterDos);
int ordenarVacunas (eVacuna vacunas[],int tam);


int main()
{
    eVacuna vacunas[TAM]=
    {
        {1000,"pfizer",'a',90.4},
        {1001,"astrazeneca",'b',95.2},
        {1002,"Sputnik",'b',70.4},
        {1003,"Covishield",'a',86.2},
        {1004,"Sinopharm",'b',65.2}
    };

    printf(" id           marca           tipo    efectividad\n");
    for(int i = 0; i < TAM; i++)
    {
        printf("%d %15s  %10c  %10.2f\n",vacunas[i].id,vacunas[i].nombre,vacunas[i].tipo,vacunas[i].efectividad);
    }
    ordenarVacunas(vacunas,TAM);
    printf("\n\n id           marca         tipo    efectividad\n");
    for(int i = 0; i < TAM; i++)
    {
         printf("%d %15s  %10c  %10.2f\n",vacunas[i].id,vacunas[i].nombre,vacunas[i].tipo,vacunas[i].efectividad);
    }

    return 0;
}


float aplicarAumento(float precio)
{
    float precioFinal;
    if(precio >0)
    {
        precioFinal = precio * 1.05;
    }
    return precioFinal;
}
int reemplazarCaracteres (char cadena[],char caracterUno,char caracterDos)
{
    int contador = 0;
    if (cadena != NULL)
    {
        for (int i = 0; i <strlen(cadena)-1; i++)
        {
            if (cadena[i] == caracterUno)
            {
                cadena[i] = caracterDos;
                contador++;
            }
        }

    }
    return contador;
}
int ordenarVacunas (eVacuna vacunas[],int tam)
{
    int retorno = 0;
    int ordenado;
    int limite=tam-1;
    eVacuna aux;
    if (vacunas != NULL && tam >0)
    {
        do
        {
            ordenado = 1;
            for (int i = 0; i < limite; i++)
            {
                if((vacunas[i].tipo>vacunas[i+1].tipo) || (vacunas[i].tipo==vacunas[i+1].tipo && vacunas[i].efectividad>vacunas[i+1].efectividad))
                {
                    aux = vacunas[i];
                    vacunas[i] = vacunas[i+1];
                    vacunas [i+1] = aux;
                    ordenado = 0;
                }
            }
            limite --;
        }
        while(ordenado == 0);
        retorno = 1;
    }
    return retorno;
}
