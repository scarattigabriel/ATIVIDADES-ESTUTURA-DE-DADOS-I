#include <stdlib.h>
#include <stdio.h>
#define MAX 30

struct tpQueue
{
    int value[MAX];
    int pos;
};typedef struct tpQueue pqueue;


void initPqueue(pqueue *q)
{
    q->pos = 1;
}

void enQueue(pqueue *q, int v)
{
    int pos_atual=q->pos;//armazena a posiçao atual
    q->value[q->pos++]=v;//insere o novo valor e incrementa a posiçao
    while(pos_atual != 1 &&  q->value[pos_atual/2] < q->value[pos_atual])//compara pai < filho
    {  
        //entra no laço se o valor do pai for menor que o valor do filho
        int aux = q->value[pos_atual];//aux armazena o valor do filho 
        q->value[pos_atual] = q->value[pos_atual/2];//filho recebe o valor do pai
        q->value[pos_atual/2] = aux;//pai recebe o valor do filho armazenado em aux
        pos_atual = pos_atual/2;//atualiza a posição para o pai por causa da troca
    }
}

int peeq(pqueue *q)
{
    return q->value[1];
}

int dequeue(pqueue *q)
{
    int v_excluido;//armazena o valor 
    v_excluido = peeq(q);
    q->pos--;
    q->value[1]=q->value[q->pos];
    q->value[q->pos]=0; 
    int x=1;
    while(x*2 < q-> pos || x*2+1 < q->pos)
    {
        int filho;//0 ou 1
        int max=q->value[x];

        if(x*2 < q->pos && q->value[x*2] > max)
        {

            max=q->value[x*2];
            filho=0;
        }
        
        if(x*2+1 < q->pos && q->value[x*2+1] > max)
        {
            max=q->value[x*2];
            filho=1;
        }

        if(q->value[x]==max)
        {
            break;
        }

        int aux=q->value[x*2+filho];
        q->value[x*2+filho]=q->value[x];
        q->value[x]=aux;
        x=x*2+filho;
    }
    return v_excluido;
}

int main()
{
    pqueue q;
    //iniciando o heap
    initPqueue(&q);
    //inserindo valores no heap
 
    enQueue(&q, 20);
    enQueue(&q, 10);
    enQueue(&q, 5);
    enQueue(&q, 4);
    enQueue(&q, 30);
    enQueue(&q, 50);
    enQueue(&q, 70);
    enQueue(&q, 45);
    for(int i=1;i<q.pos;i++)
    {
        printf("%d ", q.value[i]);
    }

    dequeue(&q);
    
    printf("\n");
        for(int i=1;i<q.pos;i++)
    {
        printf("%d ", q.value[i]);
    }
    
    return 0;
}