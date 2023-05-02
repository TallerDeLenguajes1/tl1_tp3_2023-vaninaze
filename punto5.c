//Modifico el punto 3
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char *buff, **punt;
    int cant;

    buff = (char *)malloc(20*sizeof(char));

    printf("\n Cantidad de nombres a cargar: ");
    scanf("%i", &cant);

    punt = (char **)malloc(cant*sizeof(char));

    for (int i = 0; i < cant; i++)
    {
        printf("\n Ingrese nombre %i: ", i+1);
        fflush(stdin);
        gets(buff); //guardo en un puntero auxiliar

        punt[i] = (char *)malloc(sizeof(char)*(strlen(buff)+1)); //asigno memoria para el nombre 
        strcpy(punt[i],buff); //copio el buff en el vector
    }
    for (int i = 0; i < cant; i++)
    {
        printf(" \n - Nombre %i: %s", i+1, punt[i]);
    }
    
    free(buff);
    free(punt);
    return 0;
}