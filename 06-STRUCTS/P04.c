/*Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve conter a matrícula do aluno, nome, nota da primeira prova, nota da segunda prova e nota da terceira prova.
Permita ao usuário entrar com os dados de 5 alunos.
Encontre o aluno com maior nota da primeira prova.
Encontre o aluno com maior média geral.
Encontre o aluno com menor média geral.
Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para aprovação.
*/
#include <stdio.h>



struct tipo_aluno
{
    int matricula;
    char nome[100];
    float nota_prova1;
    float nota_prova2;
    float nota_prova3;

}; typedef struct tipo_aluno aluno;

 float CalculaMedia(aluno );



int main()
{
    aluno alunos[5];

    for ( int i = 0; i < 5; i++)
    {
        printf("Digite a matrícula do aluno %d: \n", i+1);
        scanf("%d", &alunos[i].matricula);
        printf("Digite o nome do aluno: \n");
        scanf("%s", alunos[i].nome);
        printf("Digite a nota da prova 1 do aluno: \n");
        scanf("%f", &alunos[i].nota_prova1);
        printf("Digite a nota da prova 2 do aluno: \n");
        scanf("%f", &alunos[i].nota_prova2);
        printf("Digite a nota da prova 3 do aluno: \n");
        scanf("%f", &alunos[i].nota_prova3);
    }

    
    int iterador_maior_np1 = 0; 
    for (int i = 0; i < 5; i++) //CONFERE MAIOR NOTA PROVA 1
    {
        if (alunos[i].nota_prova1 > alunos [iterador_maior_np1].nota_prova1)
        {
            iterador_maior_np1+=i;
        }
    }
    
    
    
    int iterador_maior_media=0;
   
    for ( int i = 0; i < 5; i++) //CONFERE MAIOR MÉDIA
    {
        if (CalculaMedia(alunos[i]) > CalculaMedia(alunos[iterador_maior_media]))
        {
            iterador_maior_media+=i;
        }
    }

    int iterador_menor_media=0; //CONFERE MENOR MÉDIA
   
    for ( int i = 0; i < 5; i++)
    {
        if (CalculaMedia(alunos[i]) > CalculaMedia(alunos[iterador_maior_media]))
        {
            iterador_menor_media+=i;
        }
    }

    
    printf("Aluno com a maior nota na prova 1: Aluno %d - Nota Prova 1 = %.2f\nALuno com a maior média: Aluno %d - Maior média = %.2f\nAluno com a menor média: Aluno - %d Menor média = %.2f", iterador_maior_np1  + 1, alunos[iterador_maior_media].nota_prova1, iterador_maior_media + 1, CalculaMedia(alunos[iterador_maior_media]), iterador_menor_media + 1, CalculaMedia(alunos[iterador_menor_media]));   
    
    printf("\n\nMédia de cada aluno\n\n");

    for (int i = 0; i < 5; i++)
    {
        printf("Aluno %d\nMédia: %.2f", i + 1, CalculaMedia(alunos[i]));
    }

    return 0;
}







    float CalculaMedia(aluno aluno_qualquer )
    {
        float media;
        media = (aluno_qualquer.nota_prova1 + aluno_qualquer.nota_prova2 + aluno_qualquer.nota_prova3) / 3;

        return media;
    }

    
