#include <stdio.h>
#include <stdlib.h>

struct tdoub {
    char c;
    struct tdoub *next, *prev;
};
struct tsentinel
{
    struct tdoub *head, *tail; 
};
typedef struct tdoub doub;
typedef struct tsentinel sentinel;

void insertList(sentinel *s, char cr)
{
    doub *d;
    //alocar
    d=(doub*)malloc(sizeof(doub));
    //colocar valores
    d->c=cr;;
    d->prev=NULL;
    d->next=NULL;
    //encadear
    if (s->head==NULL)
    {
        s->head=d;
        s->tail=d;
    }
    else
    {
        s->tail->next=d;
        d->prev=s->tail;
        s->tail=d;
    }
    return;
}


void printList(sentinel s)
{
    doub *aux;
    for (aux=s.head; aux!=NULL; aux=aux->next)
    {
        printf("%c\n", aux->c);
    }

}

void DeleteList(sentinel*s, char cr)
{
    doub *aux;
    //Primeiro buscar elemento
    for(aux=s->head;aux!=NULL;aux=aux->next)
    {
        if(aux->c==cr)
        {
            break;
        }
    }
    if(aux==NULL)
    {
        return;
    }
    //Excluí-lo
    if(s->head == s->tail)//a lista tem apenas 1 elemento
    {
        free(aux);
        s->head = NULL;
        s->tail = NULL;
        return;
    }
    if(aux==s->head) //excuir o primeiro elemento
    {
        s->head=aux->next;
        s->head->prev=NULL;
        free(aux);
        return;
    }

    if(aux==s->tail)//ecluir o ultimo
    {
        s->tail=s->tail->prev;
        s->tail->next=NULL;
        free(aux);
        return;
    }
    aux->next->prev=aux->prev;
    aux->prev->next=aux->next;
    free(aux);
    return;
}

doub *SearchList(sentinel s, char cr)
{
    doub *aux;
    for(aux=s.head; aux=NULL; aux=aux->next)
    {
        if(aux->c==cr)
        {
            break;
        }
    return aux;
    }
}

int main()
{
    sentinel s={NULL, NULL};//s.head=NULL s.tail=NULL
    char caracter;
    int op=1;
    while(op!=0)
    {
        printf("1. Inserir Fim\n2. Inserir Ordem \n3. Exclui\n4. Print\n5. Consulra\n0. Sai\n:");
        scanf("%d", &op); getchar();
    switch (op)
    {
    case 1:
        printf("Digite um caracter: ");
        scanf("%c", &caracter);
        insertList(&s, caracter);
        break;
    
    case 3:
        printf("Digite um caracter: ");
        scanf("%c", &caracter);
        DeleteList(&s, caracter);
        break;
    case 4:
        printList(s);
        break;
    case 5:
        printf("Digite um caracter: ");
        scanf("%c", &caracter);
        doub *d;
        d=SearchtList(s, caracter);
        if(d==NULL)
        {
            printf("Caracter não encontrado!\n");
        }
        else
        {
            printf("Caracter encontrado!\n");
        }
        break;
    }
    }




    return 0;
}