#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct TQueue
{
    Item item;
    struct TQueue *next;
} EQueue;

typedef struct
{
    EQueue *head;
    EQueue *tail;
} Queue;

void enQueue(Queue *queue, Item item);

void deQueue(Queue *queue, Item *item);
void initQueue(Queue *queue);

int isEmpty(Queue *queue);

void freeAll(Queue *queue);

int main()
{
    Queue queue;
    Item item;

    initQueue(&queue);

    for (int i = 0; i < 10; i++)
    {
        item = i;

        printf("Inserindo na fila o item %d.\n", item);
        enQueue(&queue, item);
    }

    while (isEmpty(&queue) == 0)
    { // Enquanto a fila não estiver vazia
        deQueue(&queue, &item);
        printf("Item %d removido da fila.\n", item);
    }

    freeAll(&queue); // Sem efeito se a fila já está vazia
    return 0;
}

void initQueue(Queue *queue)//Inicializa a fila
{
    queue->head = NULL;
    queue->tail = NULL;
}

void enQueue(Queue *queue, Item item)//Insere um item na fila
{
    EQueue *aux;

    // Cria um novo elemento da lista encadeada que representa a fila e
    // armazena neste novo elemento o item a ser inserido na fila
    aux = (EQueue *)malloc(sizeof(EQueue));
    aux->item = item;
    aux->next = NULL;

    // Insere o novo elemento no fim da lista encadeada que representa a
    // fila
    if (queue->head == NULL)
    { // Se a fila esta vazia
        queue->head = aux;
        queue->tail = aux;
    }
    else
    { // Se a fila nao esta vazia
        queue->tail->next = aux;
        queue->tail = aux;
    }
}

void deQueue(Queue *queue, Item *item)//Remove um item da fila
{
    EQueue *aux;

    // Verificar se a fila esta vazia!

    // Armazena o item a ser removido da fila
    *item = queue->head->item; // ATENÇÃO: Depende da definição do tipo do
                               // item
    // Armazena o primeiro elemento da lista encadeada que representa a fila e
    // remove este primeiro elemento da lista
    aux = queue->head;
    if (queue->head == queue->tail)
    {
        queue->head = NULL;
        queue->tail = NULL;
    }
    else
    {
        queue->head = queue->head->next;
    }

    // Libera a memoria alocada para o elemento removido
    free(aux);
}
int isEmpty(Queue *queue)//Verifica se a fila está vazia
{
    return (queue->head == NULL);
}
// ou
/*int isEmpty(Queue *queue)
{
    if (queue->head == NULL)
        return 1;
    else
        return 0;
}*/
void freeAll(Queue *queue)//Libera toda a memória alocada para a fila
{
    EQueue *aux;

    while (queue->head != NULL)
    {
        // Armazena o primeiro elemento da lista encadeada que representa a
        // fila e remove este primeiro elemento da lista
        aux = queue->head;
        queue->head = queue->head->next;

        // Libera a memoria alocada para o elemento removido
        free(aux);
    }
    queue->tail = NULL;
}
