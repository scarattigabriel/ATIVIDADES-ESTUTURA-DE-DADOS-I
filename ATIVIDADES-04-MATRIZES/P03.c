//Declare uma matriz 5 x 5. Preencha com 1 a diagonal principal e com 0 os demais elementos. Imprima, ao final, a matriz obtida.

#include <stdio.h>
#define ROW 5
#define COL 5



int main ()     
{
    int matriz[ROW][COL];

    for (int l = 0; l < ROW; l++)
    {
        for (int c = 0; c < COL; c++)
        {
            if (l==c)
            {
                matriz[l][c]=1;
            }

            else
            {
                matriz[l][c]=0;
            }
        }
        
    }
    
    for (int l = 0; l < ROW; l++)
    {
        for (int c = 0; c < COL; c++)
        {
            printf("%d",matriz[l][c]);
        }
        printf("\n");
    }
    
}
