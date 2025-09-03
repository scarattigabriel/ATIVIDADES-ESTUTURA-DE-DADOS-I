//Faça um programa para calcular o fatorial de um número dado. O fatorial de um número n é n × (n − 1) × (n − 2) × . . . × 1, por definição o fatorial de 0 e 1 é 1. Por exemplo, o fatorial de 5 é 120, ou seja, 5 × 4 × 3 × 2 × 1 (perceba que não seria necessário fazer a última multiplicação já que 1 é o elemento neutro da multiplicação).

#include <stdio.h>
int main(){

    int num, i, fatorial=1;

    printf("Digite um número para calcular o fatorial: ");
    scanf("%d", &num);


    if (num < 0)
    {
        printf("Fatorial não definido para negativos");
    }
        
    else
    {
        for (i=num; i > 1; i--)
        {
            fatorial*= i;
        }
    printf("Fatorial = %d", fatorial);
    }


    return 0;
}