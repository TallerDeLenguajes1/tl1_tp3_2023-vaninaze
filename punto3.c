/*3) Escriba un programa que solicite 5 nombres, los cargue en un vector de punteros char y una
vez cargados los liste por pantalla (Todo implementando reserva dinámica de memoria) (Lea
las notas 1 y 2)*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char *buff, *punt[5];
    buff = (char *)malloc(20*sizeof(char));

    for (int i = 0; i < 5; i++)
    {
        printf("\n Ingrese nombre %i: ", i+1);
        fflush(stdin);
        gets(buff); //guardo en un puntero auxiliar

        punt[i] = (char *)malloc(sizeof(char)*(strlen(buff)+1)); //asigno memoria para el nombre 
        strcpy(punt[i],buff); //copio el buff en el vector
    }
    for (int i = 0; i < 5; i++)
    {
        printf("\n PUNT %s", punt[i]);
    }
    
    free(buff);
    free(punt[5]);
    
    return 0;
}