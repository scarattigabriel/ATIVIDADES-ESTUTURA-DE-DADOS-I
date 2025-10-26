#include <stdio.h>
#include <stdlib.h>
struct tdouble {
	int value;
	struct tdouble *next, *prev;
};
typedef struct tdouble doub;

struct tsent {
	doub *head, *tail;
};
typedef struct tsent sentinela;

void setValue (sentinela *s, int v)
{
	doub *p;
	p=(doub *)malloc(sizeof(doub)); // passo 1
	p->value=v;   // passo 2
	p->next=NULL; // passo 2
	p->prev=NULL; // passo 2
	//passo 3 - encadear
	if (s->head==NULL)
	{
		s->head=p;
		s->tail=p;
		return;
	}
	s->tail->next=p;   
	p->prev=s->tail;
	s->tail=p;
	return;
}

void delValue(sentinela *s, int key)
{
    doub *aux;
    for (aux = s->head; aux != NULL && aux->value != key; aux = aux->next);

    if (aux == NULL) {
        printf("Valor não encontrado!\n");
        return;
    }

    if (aux == s->head) { // primeiro
        s->head = aux->next;
        if (s->head != NULL)
            s->head->prev = NULL;
        else
            s->tail = NULL;
    }
    else if (aux == s->tail) { // último
        s->tail = aux->prev;
        if (s->tail != NULL)
            s->tail->next = NULL;
        else
            s->head = NULL;
    }
    else { // meio
        aux->prev->next = aux->next;
        aux->next->prev = aux->prev;
    }

    free(aux);
}


int main()
{
	sentinela sent={NULL,NULL};
	for (int i=10;i<25;i++)  setValue(&sent,i);
	for (doub *aux=sent.head;aux!=NULL;aux=aux->next)
	   printf("%d\n",aux->value);
	printf("========\n");
	for (doub *aux=sent.tail;aux!=NULL;aux=aux->prev)
	   printf("%d\n",aux->value);
	///
	delValue(&sent,24);
	printf("DELETE: \n");
		for (doub *aux=sent.head;aux!=NULL;aux=aux->next)
	   printf("%d\n",aux->value);
	printf("========\n");
	for (doub *aux=sent.tail;aux!=NULL;aux=aux->prev)
	   printf("%d\n",aux->value);
	return 0;
}
