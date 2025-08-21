/*Crie um programa que lê 5 valores inteiros, armazena-os em um vetor e, em seguida, mostre na tela os valores lidos.*/
#include <stdio.h>

int main()
{
    int vetor[5];

    for(int i=0; i<5; i++)
    { 
    printf("Digite um valor inteiro: ");
    scanf("%d", &vetor[i]);
    }

    printf("Elementos do vetor: \n");

    for(int i=0; i<5; i++)
    {
        printf("%d ", vetor[i]);        
    }
    
    return 0;
}


