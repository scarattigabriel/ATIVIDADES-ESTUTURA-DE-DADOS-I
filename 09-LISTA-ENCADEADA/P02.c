/*Considerando a estrutura proposta no exercício anterior, faça as seguintes adaptações em seu programa:
O programa deve ler (do teclado) vários registros de funcionários (quando id for igual a 0 a entrada é finalizada).
Use a mesma função implementada anteriormente e imprima a lista para ver se todos os elementos estão presentes
Crie uma função para desalocar a memória de todas as instâncias de funcionário (nós da lista). 
Super desafio: crie uma nova função que imprime a lista na ordem inversa
Dica: vimos uma possível técnica em aulas anteriores :)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct date
{
    int dia;
    int mes;
    int ano;
};typedef struct date Date;

struct employee 
{
    int id;
    char name[41];
    double income;
    Date dbirth;
    struct employee *next;
};typedef struct employee Employee;




int imprimeEmployee(Employee *first)
{   
    Employee *aux = first;
    while (aux != NULL)
    {
        printf("ID: %d\n", aux->id);
        printf("Nome: %s\n", aux->name);
        printf("Renda: %lf\n", aux->income);
        printf("Data de nascimento: %d/%d/%d\n", aux->dbirth.dia, aux->dbirth.mes, aux->dbirth.ano);
        aux = aux->next;
    }
    return 0;
}

void freeEmployee(Employee *first)
{
    Employee *aux = first;
    while (aux != NULL)
    {
        free(first);
        aux = aux->next;
    }
}
/*
void ImprimeInverso(Employee *first)
{
    Employee *aux;
    aux = first;
    if (aux->next != NULL)
    {
        aux = aux->next;
        ImprimeInverso(aux);
    }
    else{
        printf("ID: %d\n", aux->id);
        printf("Nome: %s\n", aux->name);
        printf("Renda: %lf\n", aux->income);
        printf("Data de nascimento: %d/%d/%d\n", aux->dbirth.dia, aux->dbirth.mes, aux->dbirth.ano);
        free(aux);
}*/

int main()
{   
    Employee *funcionario, *aux = NULL, *first = NULL;
    int id_break, i = 0;
    
    
    while (1)
    {
    i ++;
    funcionario=(Employee *)malloc(sizeof(Employee));
    printf("Funcionario %d - Digite o id: \n", i);
    scanf("%d", &id_break);
    if (id_break == 0)
    {
        break;
    }
    else
    {
        funcionario->id = id_break;
    }
    printf("Funcionario %d - Digite o nome: \n", i);
    scanf("%s", funcionario->name);   
    printf("Funcionario %d - Digite a renda: \n", i);
    scanf("%lf", &funcionario->income);
    printf("Funcionario %d - Digite o dia de nascimento: \n", i);   
    scanf("%d", &funcionario->dbirth.dia);
    printf("Funcionario %d - Digite o mês de nascimento: \n", i);  
    scanf("%d", &funcionario->dbirth.mes);
    printf("Funcionario %d - Digite o ano de nascimento: \n", i);   
    scanf("%d", &funcionario->dbirth.ano);
    if (first == NULL)
    {
        first = funcionario;
        aux = funcionario;
    }
    else
    {
        aux->next = funcionario;
        aux = funcionario;
    }


    }

    imprimeEmployee(first);
    /*ImprimeInverso(first);*/
    freeEmployee(first);
    

    return 0;
}