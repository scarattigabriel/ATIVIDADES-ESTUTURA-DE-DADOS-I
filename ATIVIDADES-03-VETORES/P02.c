/*Faça uma função que receba um vetor e o seu tamanho como parâmetro e imprima o maior e o menor elemento do vetor. 
*/

#include <stdio.h>

void MaiorMenorElemento(int [], int);

int main() {
    int tamanho_vetor;

    printf("Escolha o tamanho do vetor: ");
    scanf("%d", &tamanho_vetor);

    int vetor[tamanho_vetor];

    printf("Digite os %d elementos do vetor:\n", tamanho_vetor);
    for (int i = 0; i < tamanho_vetor; i++) 
    {
        scanf("%d", &vetor[i]);
    }

    MaiorMenorElemento(vetor, tamanho_vetor);

    return 0;
}

void MaiorMenorElemento(int vetor [], int tamanho)
{
    int maior = vetor[0];
    int menor = vetor[0];

    for (int i = 1; i < tamanho; i++)
    {
        if (vetor[i] > maior)
        {
            maior = vetor[i];
        }
        if (vetor[i] < menor)
        {
            menor = vetor[i];
        }
    }

    printf("O maior elemento do vetor é: %d\n", maior);
    printf("O menor elemento do vetor é: %d\n", menor);
}