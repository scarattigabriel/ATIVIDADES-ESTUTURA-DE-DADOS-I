//Leia uma matriz 4 x 4 (de inteiros) e imprima a diagonal principal
#include <stdio.h>
#define ROW 4
#define COL 4
int main ()
{
    int matriz[ROW][COL];
    printf("Digite os elementos da matriz para obter a diagonal principal\n");
    for (int l=0; l<ROW; l++)
    {
        printf("Linha %d\n", l);
        for (int c=0; c<COL; c++)
        {
            printf("Coluna %d: ", c);
            scanf("%d" ,&matriz[l][c]);
        }
    }

    printf("Diagonal Principal: \n");
    for (int i = 0; i < ROW; i++)
    {
        printf("%d", matriz[i][i]);
    }
    
    return 0;
}

