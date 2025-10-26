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

/*crie o primeiro funcionário da lista encadeada;
Adicione um segundo funcionário mantendo o encadeamento;
Crie uma função que receba o ponteiro inicial da lista e imprima todos os elementos (funcionários)
*/

void imprimeEmployee(Employee *first)
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
    
}

int main()
{
    Employee *f1, *f2, *aux, *first = NULL; 
    f1=(Employee *)malloc(sizeof(Employee));
    first=f1;
    aux =f1;
    f1->id = 1;
    strcpy(f1->name, "gabriel");
    f1->income = 2300;
    f1->dbirth.ano = 2025;
    f1->dbirth.dia = 25;
    f1->dbirth.mes = 12;
    f1->next =NULL;
    

    f2=(Employee *)malloc(sizeof(Employee));
    f2->id = 2;
    strcpy(f2->name, "jose");
    f2->income = 2200;
    f2->dbirth.ano = 2022;
    f2->dbirth.dia = 22;
    f2->dbirth.mes = 11;
    f2->next = NULL;
    aux->next= f2;

    imprimeEmployee(first);
    free(f1);
    free(f2);



    return 0;
}

