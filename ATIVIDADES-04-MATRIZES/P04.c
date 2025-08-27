//Faça um programa que preenche uma matriz 5 x 5 com o produto da posição da linha e da coluna de cada elemento. Em seguida, imprima.
#include <stdio.h>
#define ROW 5
#define COL 5
int main()
{
    int matriz[ROW][COL];
    for (int l=0; l < ROW; l++)
    {
        for (int c = 0; c < COL; c++)
        {
            matriz[l][c]=l*c;
        }
        
    }
    
    printf("Matriz 5x5 com o produto da posição da linha e da coluna de cada elemento:\n");
    for (int l=0; l < ROW; l++)
    {
        for (int c = 0; c < COL; c++)
        {
            printf("%d ", matriz[l][c]);
        }
        printf("\n");
    }




}