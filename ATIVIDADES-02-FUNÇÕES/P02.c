//Crie uma função que receba 2 números e retorne o maior valor entre eles (se forem iguais, retorna o segundo).
#include <stdio.h>
int maior(int, int);

int main()
{   
    int num1, num2;
    printf("Digite um número: ");
    scanf("%d", &num1);
    printf("Digite outro número: ");
    scanf("%d", &num2);
    
    printf("O maior número entre %d e %d é: %d", num1, num2, maior(num1, num2));

    return 0;
}


int maior(int num1, int num2)
{
    if (num1 > num2)
    {
        return num1;
    }
    else
    {
        return num2;
    }
}