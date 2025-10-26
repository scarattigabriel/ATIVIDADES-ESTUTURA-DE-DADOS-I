///////////////////////INCLUIR UMA FUNÇÃO PARA ADICIONAR ELEMENTOS NO MEIO DA LISTA////////////////////////////






#include <stdio.h>
#include <stdlib.h>

struct ttemp
{
    float temp;
    struct ttemp *next;
};typedef struct ttemp temperatura;

/*temperatura* insereTemp(temperatura *f)
{
    temperatura *p;
    p=(temperatura *)malloc(sizeof(temperatura)); // alocar memória
    printf("Temperatura: "); scanf("%f", &p->temp); // guardando valores no espaço alocado
    p->next=NULL; // Nullificar ponteiros
    if (f == NULL ) return p; //Encadeamento
    temperatura *aux;
    for (aux = f; aux->next!=NULL; aux=aux->next); //procura o ultimo elemento da lista
    aux->next=p;
    return  f;
}*/

temperatura* insereTemp(temperatura *first)
{
    temperatura *temp_inserir;
    int posicao;

    temp_inserir = (temperatura*)malloc(sizeof(temperatura ));
    if (temp_inserir ==NULL)
    {
        printf("Erro de alocação!");
        return first;
    }

    printf("Digite a temperatura: "); scanf("%f", &temp_inserir->temp );
    temp_inserir->next =NULL;
    
    printf("Digite a posição que deseja inserir: "); scanf ("%d", &posicao);
    
    if(posicao < 0)//posição menor que 0
    {
        printf("Posição Inválida!");
        return first;
    }
    
    if(posicao == 0)//primeira posição
    {
        temp_inserir->next = first;
        return temp_inserir;
        
    }

    temperatura *aux = first;
    int total_posicoes = 0;
    while (aux != NULL)//VERIFICA O TOTAL DE ELEMENTOS NA LISTA
    {
        aux = aux->next;
        total_posicoes++;
    }
    
    
    if (total_posicoes <= posicao)//Posição maior do que o tamanho da lista ou ultima posição
    {
        printf("Posição Inválida! Inserindo ao final da lista!");
        aux = first;
        while(aux->next != NULL) aux = aux->next;//procura o ultimo elemento  
        aux->next = temp_inserir;
        return first;
    }

    int i=0; //Inserir no meio
    temperatura *aux2 = NULL;
    aux = first;
    while(i < posicao)
    {
        aux2=aux;
        aux = aux->next;
        i++;
    }

    aux2->next = temp_inserir;
    temp_inserir->next = aux;

    return first;



}



/*temperatura* insereTemp(temperatura *f)
{
    temperatura *temp_inserir;
    int posicao;
    temp_inserir = (temperatura *)malloc(sizeof(temperatura));
    printf("Temperatura: \n"); scanf("%f", &temp_inserir->temp);
    printf("Digite em que posição deseja adicionar: "); scanf("%d", &posicao);
    if (posicao < 0)
    {
        printf("Posição inválida!");
    }
    temperatura *aux1, *aux2;
    int i=0;
    for(aux1 = f; aux1 != NULL; aux1 = aux1->next)//verifica o total de valores inseridos ja
    {
        i++;
    }
    if (posicao > i)//se a posição for maior que o total de valores inseridos, insere no final
    {
        printf("Posição inválida! Inserindo no final da lista.\n");
        for (aux1 = f; aux1->next!=NULL; aux1=aux1->next)
        { //procura o ultimo elemento da lista
        aux1->next=temp_inserir;
        return  f;
        }
    }
    if(posicao == 0)
    {
        temp_inserir->next = f;
        f = temp_inserir;
        return f;
    }

    i = 0;
    aux1 = f;
    while(i < posicao )
    {
        aux2= aux1;
        aux1 = aux1->next;           
    }
    aux2->next = temp_inserir;
    temp_inserir->next = aux1;
    return f;

}*/

temperatura *printTemp(temperatura *f, float t)
{
    temperatura *aux;
    for (aux=f; aux!=NULL; aux=aux->next)
        if (aux->temp==t) return aux;
    return NULL; //retornar aux também irá retornar NULL
}



void printAll(temperatura *p)
{
    temperatura *aux;
    for(aux = p; aux!=NULL; aux=aux->next){
    printf("Temperatura: %.2f\n", aux->temp);
    }
}

void freeAll(temperatura *first)
{
    temperatura *aux1, *aux2; 
    aux1 = first;
    while (aux1 != NULL)
    {
        aux2=aux1;
        aux1=aux1->next;
        free(aux2);
    }
}

temperatura *delTemp(temperatura *f, float t)
{
    temperatura *aux;

    if(f == NULL)
    {
        printf("Lista vazia!\n");
        return f;
    }

    
    if (f->temp==t)//O PRIMEIRO
    {
        aux=f;
        f=f->next;
        free(aux);
        return f;
    }
    
    temperatura *aux2;
    aux=f;
    while (aux!=NULL)
    {
        if (aux->temp==t)break;
        aux2=aux;
        aux=aux->next;
    }



    aux = printTemp(f, t);
    if (aux == NULL)
    {
        printf("Temperatura não encontrada!");
        return f;
    }


    if(aux->next==NULL)//O ULTIMO
    {
        aux2->next=NULL;
        free(aux);
        return f;
    }   

    aux2->next=aux->next;

    return f;
}
    

int main()
{
    temperatura *first = NULL, *aux;
    int op = 5;
    float t;
    while (op != 0)
    {
        printf("1. Inserir\n2. Consultar\n3. Listar\n4. Excluir\n0. Sair\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1: first = insereTemp(first);
            break;
        case 2:
            printf("Temperatura: ");
            scanf("%f", &t);
            aux=printTemp(first, t);
            if (aux==NULL)printf("Temperatura não encontrada!\n");
            else printf("A temperatura está na lista: %.2f\n", aux->temp);
            break;
        case 3: printAll(first);
            break;
        case 4: printf("Temperatura: "); scanf("%f", &t);
        first=delTemp(first, t);
        }
    }
    

    freeAll(first);


    return 0;
}