#include <stdio.h>
#include <stdlib.h>

struct tqueueinfo
{
    char item;
    struct tqueueinfo *next;
};
typedef struct tqueueinfo qinfo;
struct tqueue
{
    qinfo *head;
    qinfo *tail;
};
typedef struct tqueue queue;
//
void initQueue(queue *q)
{
    q->head = q->tail = NULL;
}
//
int isEmpty(queue q)
{
    return q.head == NULL;
}
//
void enQueue(queue *q, char info)
{
    qinfo *p;
    p = (qinfo *)malloc(sizeof(qinfo));
    p->item = info;
    p->next = NULL;
    if (isEmpty(*q) == 1) // empty queue
    {
        q->head = p;
        q->tail = p;
    }
    else
    {
        q->tail->next = p;
        q->tail = p;
    }
}
//
char deQueue(queue *q)
{
    char info;
    if (isEmpty(*q) == 1)
        return 122; // empty queue
    info = q->head->item;
    qinfo *aux = q->head;
    if (q->head == q->tail) // one element
    {
        free(aux);
        initQueue(q);
        return info;
    }
    q->head = q->head->next;
    free(aux);
    return info;
}
//
int main()
{
    queue q;
    char *stQueue = {"My Queue"};
    initQueue(&q);
    printf("Filling the queue!\n");
    for (int i = 0; stQueue[i] != 0; i++)
        enQueue(&q, stQueue[i]);
    printf("Retrieving from the queue!\n");
    while (isEmpty(q) == 0)
    {
        char c = deQueue(&q);
        printf("%c", c);
    }
    printf("\n");
    return 0;
}