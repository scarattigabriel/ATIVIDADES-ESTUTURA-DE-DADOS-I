// Um professor gostaria de ter um programa para calcular a média final de seus alunos. Para isso, ele informa a matrícula e as 5 notas que o alunos teve durante o semestre. Após informar as 5 notas, o programa imprime a matrícula do aluno e a média que obteve (média aritmética simples). Quando o professor digitar 0 na matrícula, o programa finaliza e apresenta a média geral da turma. Proibido colocar 5 scanf para pedir as notas.

#include <stdio.h>

int main(){
 
    int matricula;

    printf("Digite a matrícula do aluno:(0 para finalizar)");
    scanf("%d", &matricula);


    float nota, media_aluno, soma_medias=0, contador_alunos=0;
    
    while(matricula != 0)
    {
    
    float soma_notas=0;
    int i=1;

    while (i <= 5)
        {
            printf("Digite a nota %d: ", i);
            scanf("%f", &nota);
            soma_notas +=nota;
            i++;
        }

    
    media_aluno= soma_notas / 5;
    soma_medias+=media_aluno;
    contador_alunos++;
    printf("Matrícula: %d\nMédia: %.2f\n", matricula, media_aluno);

    
    printf("Digite a matrícula do aluno:(0 para finalizar)");
    scanf("%d", &matricula);


    }

    float media_turma;

    if (contador_alunos > 0)
    {
        media_turma= soma_medias / contador_alunos;
        printf("Média geral da turma: %.2f", media_turma);
    }
    else
    {
        printf("Nenhum aluno informado!");
    }

    return 0;
}