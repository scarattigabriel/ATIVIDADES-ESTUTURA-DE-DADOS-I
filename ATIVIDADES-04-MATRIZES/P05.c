//Leia uma matriz 4 x 4 e imprima a triangular superior.
#include <stdio.h>
#define ROW 4
#define COL 4

int main ()
{
    int matriz[ROW][COL];
    printf("Digite os elementos da matriz para obter a triagular superior\n");
    for (int l=0; l<4; l++)
    {
        printf("Linha %d\n", l);
        for (int c=0; c<4; c++)
        {
            printf("Coluna %d: ", c);
            scanf("%d" ,&matriz[l][c]);
        }
    }


    printf("Matriz Triangular Superior:\n");

    for (int l = 0; l < ROW; l++)
    {
        for (int c = 0; c < COL; c++)
        {
            if (l <= c)
            {
                printf("%d ", matriz[l][c]);
            }
            else
            {
                printf("0 ");
            }

        }
        printf("\n");
    }


}