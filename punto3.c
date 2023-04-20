/*3) Escriba un programa que solicite 5 nombres, los cargue en un vector de punteros char y una
vez cargados los liste por pantalla (Todo implementando reserva dinámica de memoria) (Lea
las notas 1 y 2)*/
#include<stdio.h>
#include<stdlib.h>

int main(){
    char *punt;
    punt = (char *)malloc(5 * sizeof(char));
    
    for (int i = 0; i < 5; i++)
    {
        printf("\n Ingrese nombre %i: ", i+1);
        fflush(stdin);
        scanf("%c", &punt[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("\n Nombre %i: %s", i+1, *punt);
        punt++;
    }
    free(punt);
    
    return 0;
}