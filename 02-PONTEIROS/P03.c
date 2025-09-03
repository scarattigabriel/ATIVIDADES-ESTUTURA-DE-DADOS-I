/*Crie uma função somaImpares(), que receba dois inteiros (inicio, fim) e um ponteiro. A função deve somar os ímpares do intervalo.*/

#include <stdio.h>
void SomaImpares(int, int, int*);

int main()
{   
    int inicio, fim, ResultadoImpares;
    printf("Digite um número inteiro para o início do intervalo: ");
    scanf("%d", &inicio);
    printf("Digite um número inteior para o fim do intervalo: ");
    scanf("%d", &fim);

    SomaImpares(inicio, fim, &ResultadoImpares);

    printf("A soma dos números ímpares entre %d e %d é: %d", inicio, fim, ResultadoImpares);

    return 0;
}

void SomaImpares(int inicio, int fim, int *soma )
{
    *soma=0;
    for(int i=inicio; i<=fim; i++ )
    {
        if(i%2!=0)
        {
            *soma += i;
        }
    }
}