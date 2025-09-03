// Uma loja vende produtos à vista e a prazo (pagamento 30 dias depois da compra). À vista tem um desconto de 5% e a prazo um acréscimo de 10%. Faça um programa em C que peça o preço do produto e a forma de pagamento: 1 para à vista e 2 para a prazo. Depois apresente o preço final do produto.
#include <stdio.h>
int main(){
    float preco_inicial, preco_final;
    int forma_pagamento;
    printf("Digite o preço do produto: ");
    scanf("%f", &preco_inicial);
    printf("Digite a forma de pagamento(1-para à vista | 2-para a prazo): ");
    scanf("%d", &forma_pagamento);

    if (forma_pagamento==1)
    {
        preco_final= preco_inicial * 0.95;
        printf("Preço final do produto: %.2f", preco_final);
    }
    else if (forma_pagamento==2)
    {
        preco_final = preco_inicial * 1.10;
        printf("Preço final do produto: %.2f", preco_final);
    }
    else 
    {
        printf("Forma de pagamento não identificada!");
    }

    
    return 0;
}