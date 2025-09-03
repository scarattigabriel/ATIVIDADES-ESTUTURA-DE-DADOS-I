//Faça um programa que calcule a duração de um evento qualquer. Para tal, o programa pede a hora de início e hora de fim (sem os minutos), as horas serão informadas de 0 a 23. Perceba que um evento pode começar em um dia e acabar em outro. Os eventos nunca terão duração de mais de 24 horas.
#include <stdio.h>
int main(){
    int hr_inicio, hr_final, duracao;
    printf("Digite a hora de início do evento: ");
    scanf("%d", &hr_inicio);
    printf("Digite a hora do término do evento: ");
    scanf("%d", &hr_final);

    if (hr_inicio < hr_final)
    {
        duracao= hr_final - hr_inicio;
    }
    else if (hr_inicio > hr_final)
    {
        duracao= (24 - hr_inicio) + hr_final;
    }
    else
    {
        duracao=24;
    }
    
    printf("Duração do evento: %d", duracao);

    return 0;
}