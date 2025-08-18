//Faça um programa que simule a multiplicação por meio de adições. Para tal serão pedidos os dois operandos. Por exemplo se for informado 3 e 4, deverá ser calculado, usando a soma, 3∗4, ou seja, 12. Este cálculo é feito somando o primeiro valor informado por ele mesmo o número de vezes representada pelo segundo número. Nesse exemplo, o três seria somado quatro vezes: 3+3+3+3, resultando 12. 

#include <stdio.h>
int main(){
    float multiplicando, multiplicador, resultado=0;
    int i;
    
    printf("Digite o multiplicando: ");
    scanf("%f", &multiplicando);
    printf("Digite o multiplicador: ");
    scanf("%f", &multiplicador);

    for (i=0; i < multiplicador; i++)
    {
        resultado+= multiplicando;
    }

    printf("Resultado: %.2f", resultado);

    return 0;
}