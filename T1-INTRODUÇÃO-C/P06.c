//Faça um programa que peça uma valor e imprima a soma de todos os números de 1 até o valor informado. Por exemplo, se o valor informado for 6, o resultado será 21, ou seja, 1 + 2 + 3 + 4 + 5 + 6. 

#include <stdio.h>
int main(){
    int num;
    
    printf("Digite um número: ");
    scanf("%d", &num);

    int i = 0, soma=0;
    while (i < num)
    {
        i++;
        soma= soma + i;
    }

    printf("A soma dos antecessores do número %d é: %d", num, soma);

    return 0;
}