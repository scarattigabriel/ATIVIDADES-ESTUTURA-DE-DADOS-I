//Faça um programa que peça o número de horas trabalhadas e o valor da hora de um determinado funcionário. Em seguida, calcule o salário do funcionário. Caso o funcionário tenha trabalhado mais de 200 horas, o salário final é acrescido de 5%.
#include <stdio.h>
int main()
{
    float hrs_trabalhadas, valor_hr, salario;
    printf("Digite o número de horas trabalhadas: ");
    scanf("%f", &hrs_trabalhadas);
    printf("Digite o valor da sua hora de trabalho:");
    scanf("%f", &valor_hr);
    salario=hrs_trabalhadas * valor_hr;

    if (hrs_trabalhadas > 200)
    {
        salario=salario*1.05;
    }

    printf("Seu salário é: %.2f", salario);

    return 0;

}