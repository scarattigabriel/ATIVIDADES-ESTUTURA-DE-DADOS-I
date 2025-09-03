/*Crie um aplicativo de conversão entre as temperaturas Celsius e Fahrenheit.
Primeiro o usuário deve escolher se vai entrar com a temperatura em Celsius ou Fahrenheit, depois a conversão escolhida é realizada.
Se C é a temperatura em Celsius e F em Fahrenheit, as fórmulas de conversão são:
C = 5*(F-32)/9
F = (9*C/5) + 32*/

#include <stdio.h>
float CelsiusParaFahrenheit(float);
float FahrenheitParaCelsius(float);


int main()
{
    int CelsiusOrFahrenheit;
    float temperatura;
    printf("Digite qual a escala da temperatura: (1-Celsius | 2-Fahrenheit)");
    scanf("%d", &CelsiusOrFahrenheit);
    printf("Digite a temperatura: ");
    scanf("%f", &temperatura);

    if (CelsiusOrFahrenheit == 1)
    {
       printf("%f°C é equivalente à %.2f°F",temperatura, CelsiusParaFahrenheit(temperatura));
     
    }
    else    
        if (CelsiusOrFahrenheit==2)
        {
        printf("%f°F é equivalente à %.2f°C",temperatura, FahrenheitParaCelsius(temperatura));
     }
     else
     {
        printf("Escala não identificada!");
     }

    return 0;
}


float CelsiusParaFahrenheit(float celsius)
{
    return (9*celsius/5) + 32; 
}


float FahrenheitParaCelsius(float fahrenheit)
{
    return 5*(fahrenheit-32)/9;
}