/*Escreva uma função chamada troca(), que receba dois ponteiros para inteiros e troca os valores entre eles.
Exemplo de chamada: troca(&a, &b)*/
 #include <stdio.h>

void troca(int *, int *);

 int main()
 {
    int a, b;
    printf("Digite o valor de a: ");
    scanf("%d", &a);
    printf("Digite o valor de b: ");
    scanf("%d", &b);

    troca(&a, &b);

    printf("O novo valor de a é: %d\n", a);
    printf("O novo valor de b é: %d\n", b);

    return 0;
 }

  void troca(int *ponteiro1, int *ponteiro2)
 {
    int armazena_ponteiro1;
    armazena_ponteiro1 = *ponteiro1;
    *ponteiro1= *ponteiro2;
    *ponteiro2= armazena_ponteiro1;
    
 }