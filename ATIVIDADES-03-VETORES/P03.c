/*Criar uma função que some os elementos de um vetor*/

#include <stdio.h>

int SomaElementosVetor(int [], int);

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
   
    printf("A soma dos %d elementos é: %d",tamanho_vetor,SomaElementosVetor(vetor, tamanho_vetor));
    return 0;
}


int SomaElementosVetor(int vetor[], int tamanho_vetor)
{
    int resultado_soma=0;
    for (int i=0; i < tamanho_vetor; i++)
    {
        resultado_soma+=vetor[i];
    }

    return resultado_soma;
}