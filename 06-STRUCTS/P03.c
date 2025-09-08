/*Declare um tipo Fraction que consista em uma struct contendo dois membros, numerador e denominador, do tipo int, e faça o seguinte:
Escreva uma função setFraction que recebe dois argumentos do tipo int (o numerador e o denominador), e retorna os valores em um tipo Fraction.
Escreva uma função multFraction que recebe dois argumentos do tipo Fraction, multiplica, armazena o resultado em uma outra variável do tipo Fraction e retorna esta variável.  Lembrando: 4/5 x 3/2 = (4 x 3)/(5 x 2)*/

#include <stdio.h>


struct tfraction 
{
    int numerador, denominador;
}; typedef struct tfraction Fraction;

Fraction setFraction(int, int);
Fraction multFraction(Fraction, Fraction);

int main()
{
    int numerador, denominador;
    Fraction fraction1, fraction2, fraction_result;

    printf("Multiplicação de frações\n");
    printf("Digite o numerador: \n");
    scanf("%d", &numerador);
    printf("Digite o denominador: \n");
    scanf("%d", &denominador);
    fraction1=setFraction(numerador, denominador);
    
    printf("Digite a fração que multiplicará\n");
    printf("Digite o numerador: \n");
    scanf("%d", &numerador);
    printf("Digite o denominador: \n");
    scanf("%d", &denominador);
    fraction2=setFraction(numerador, denominador);
    fraction_result=multFraction(fraction1,fraction2);
    printf("Resultado: %d/%d\n", fraction_result.numerador, fraction_result.denominador);


    return 0;
}


Fraction setFraction(int numerador, int denominador)
{
    Fraction fraction;
    fraction.numerador=numerador;
    fraction.denominador=denominador;
    return fraction;
}

Fraction multFraction(Fraction fraction1, Fraction fraction2 )
{
    Fraction fraction_result;
    int numerador_result, denominador_result; 
    numerador_result= fraction1.numerador * fraction2.numerador;
    denominador_result= fraction1.denominador * fraction2.denominador;
    fraction_result.numerador= numerador_result;
    fraction_result.denominador=denominador_result;
    return fraction_result;
}