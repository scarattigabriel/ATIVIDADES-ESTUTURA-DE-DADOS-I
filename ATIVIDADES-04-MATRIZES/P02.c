//Leia uma matriz 4 x 4 e escreva a localização (linha e coluna) do maior valor.
#include <stdio.h>
#define ROW 4
#define COL 4
int main ()
{
    int matriz[ROW][COL];
    printf("Digite os elementos da matriz para obter a posição do maior valor\n");
    for (int r=0; r<ROW; r++)
    {
        printf("Linha %d\n", r);
        for (int c=0; c<COL; c++)
        {
            printf("Coluna %d: ", c);
            scanf("%d" ,&matriz[r][c]);
        }
    }


    int maior_elemento=0;
    int coluna_maior, linha_maior;
    for (int r=0; r<ROW; r++)
    {
        for (int c=0; c<COL; c++)
        {
            if (matriz[r][c] > maior_elemento)
            {
                maior_elemento=matriz[r][c];
                linha_maior=r;
                coluna_maior=c;
            }
        }
    }


    printf("Maior número: %d\nPosição: Linha: %d Coluna: %d", maior_elemento, linha_maior, coluna_maior);
}


