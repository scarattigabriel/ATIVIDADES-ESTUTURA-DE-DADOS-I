//Faça uma função que lê dois inteiros e apresenta a diferença entre os dois.
int diferenca(int, int);
#include <stdio.h>
int main()
{   
    int num1, num2;
    printf("Digite um número inteiro: ");
    scanf("%d", &num1);
    printf("Digite outro número inteiro: ");
    scanf("%d", &num2);

    printf("A diferença entre %d e %d é: %d", num1, num2, diferenca(num1, num2));

    return 0;
}

int diferenca(int num1, int num2)
{
    if (num1 > num2)
    {
        return num1-num2;
    }
    else
    {
        return num2 - num1;
    }
}