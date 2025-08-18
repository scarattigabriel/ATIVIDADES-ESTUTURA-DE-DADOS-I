//Faça um programa que peça o salário e o número de filhos dos habitantes de uma região. Quando o salário informado for menor que zero, as entradas são finalizadas e serão apresentadas as médias salarial e de filhos informados. 

#include <stdio.h>
int main(){
    float salario;
    int filhos;
    float acumulador_salarios=0;
    int acumulador_filhos=0;
    int contador_repeticao=0;

    printf("Qual o valor de seu salário:(Negativo para finalizar) ");
    scanf("%f", &salario);
    printf("Digite o número de filhos: ");
    scanf("%d", &filhos);

    while (salario >= 0) {
        contador_repeticao++;
        acumulador_salarios += salario; 
        acumulador_filhos += filhos;
        printf("Qual o valor de seu salário:(Negativo para finalizar) ");
        scanf("%f", &salario);
        if (salario < 0) {
            break;
        }
        printf("Digite o número de filhos: ");
        scanf("%d", &filhos);
    
    }

    float media_salarios, media_filhos;

    if (contador_repeticao == 0)
    {
        printf("Nenhuma informação registrada!");
    } 
    else
    {
        media_salarios= acumulador_salarios / contador_repeticao;
        media_filhos= acumulador_filhos / contador_repeticao;
        printf("Média salários: %.2f\nMédia filhos: %.2f", media_salarios, media_filhos);
    }
        return 0;
}