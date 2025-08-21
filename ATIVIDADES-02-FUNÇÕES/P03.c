//Crie uma função que receba 3 números e retorne o maior valor, utilizando uma chamada para a função anterior.
#include <stdio.h>

int maior(int, int);
int maior3(int, int, int);


int main()
{
    int num1, num2, num3;
    printf("Digite um número: ");
    scanf("%d",&num1);

    printf("Digite um número: ");
    scanf("%d",&num2);

    printf("Digite um número: ");
    scanf("%d",&num3);

    printf("O maior número entre %d, %d e %d é: %d", num1, num2, num3, maior3(num1, num2, num3));
    
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

int maior3(int num1, int num2, int num3)
{
    return maior(maior(num1, num2), num3);
}
