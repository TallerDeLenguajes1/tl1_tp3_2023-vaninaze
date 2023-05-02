#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void ganancia(int mat[5][12]);
void maxMinimo(int mat[5][12]);
int main(){
    int mat[5][12];
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            mat[i][j] = rand()%40001 + 10000; //num entre 10000 y 50000
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf(" Anio %i: ", i+1);
        for (int j = 0; j < 12; j++)
        {
            printf(" %i ", mat[i][j]);
        }
        printf("\n");
    }
    ganancia(mat);
    maxMinimo(mat);
    return 0;
}
void ganancia(int mat[5][12]){
    int monto = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            monto = monto + mat[i][j];
        }
        printf("Promedio de Ganancia Anio %i: %i \n", i+1, monto/12);
    }
}
void maxMinimo(int mat[5][12]){
    int mayor, menor = 0, anioMay, anioMen, mesMay, mesMen;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (i == 0)
            {
                mayor = mat[i][j];
                anioMay = i+1;
                mesMay = j+1;
            } else {
                if (mayor < mat[i][j])
                {
                    menor = mayor;
                    anioMen = anioMay+1;
                    mesMen = anioMay+1;
                    mayor = mat[i][j];
                    anioMay = i+1;
                    mesMay = j+1;
                } else if(mat[i][j] < menor) {
                    menor = mat[i][j];
                    anioMen = i+1;
                    mesMen = j+1;
                }
            }
        }  
    }
    printf("\n Maximo: %i Anio: %i Mes: %i", mayor, anioMay, mesMay);
    printf("\n Menor: %i Anio: %i Mes: %i", menor, anioMen, mesMen);
}