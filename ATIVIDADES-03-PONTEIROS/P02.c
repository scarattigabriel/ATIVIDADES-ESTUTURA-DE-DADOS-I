/*Crie uma função chamada maior(), que receba dois inteiros e um ponteiro para um inteiro. A função deve armazenar o valor do maior no endereço do ponteiro.
Exemplo de chamada: maior(a, b, &c)*/
#include <stdio.h>

void maior(int, int, int *);

int main()
{
    int num1, num2, resultado;
    

    printf("Digite um número: ");
    scanf("%d", &num1);
    printf("Digite outro número: ");
    scanf("%d", &num2);

    maior(num1, num2, &resultado);
    
    printf("O maior número entre %d e %d é: %d\n", num1, num2, resultado);
    
    return 0;
}

void maior(int num1, int num2, int *maior)
{
    if(num1 > num2)
    {
        *maior= num1;
    }

    else
    {
        *maior= num2;
    }

}