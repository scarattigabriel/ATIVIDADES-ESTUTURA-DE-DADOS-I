// Faça um programa que peça 4 números inteiros. Em seguida, apresente quantos números informados são negativos e quantos são positivos (considere o 0 como positivo)

#include <stdio.h>
int main()
{
    int num1, num2, num3, num4;
    printf("Digite um número inteiro: ");
    scanf("%d", &num1);
    printf("Digite um número inteiro: ");
    scanf("%d", &num2);
    printf("Digite um número inteiro: ");
    scanf("%d", &num3);
    printf("Digite um número inteiro: ");
    scanf("%d", &num4);

    int ctd_negativo = 0;
    int ctd_positivo = 0;

    if (num1 >= 0)
    {
        ctd_positivo++;
    }
    else
    {
        ctd_negativo++;
    }

    if (num2 >= 0)
    {
        ctd_positivo++;
    }
    else
    {
        ctd_negativo++;
    }

    if (num3 >= 0)
    {
        ctd_positivo++;
    }
    else
    {
        ctd_negativo++;
    }

    if (num4 >= 0)
    {
        ctd_positivo++;
    }
    else
    {
        ctd_negativo++;
    }

    printf("Números positivos: %d\n", ctd_positivo);
    printf("Números negativos: %d", ctd_negativo);

    return 0;
}