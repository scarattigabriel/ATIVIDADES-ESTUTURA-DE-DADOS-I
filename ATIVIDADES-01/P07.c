//Dada uma sequência de n números (um número menor ou igual à 0 finaliza a sequência), apresentar o percentual de números informados que são maiores ou igual a 10 e menores ou igual a 20. 

#include <stdio.h>

int main(){

    int num;

    printf("Digite um número:(0 ou negativo para finalizar)");
    scanf("%d", &num);

    int ctd_num =0; int ctd_faixa_num= 0;

    while (num > 0)
    {
        ctd_num++;
        
        if (num >= 10 && num <= 20)
        {
            ctd_faixa_num++;
        }
        
        printf("Digite um número:(0 ou negativo para finalizar)");
        scanf("%d", &num);

    }
    
    float porcentagem;
    if (ctd_num > 0)
    {
        porcentagem= ((float) ctd_faixa_num / ctd_num) * 100;
        printf("%% entre 10 e 20: %.2f%%", porcentagem);
    }
    
    else
    {
        printf("Nenhum número informado!");
    }

    return 0;
}