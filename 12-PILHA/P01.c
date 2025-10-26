#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct elemStack {
    Item item;
    struct elemStack *next;
} ElemStack;
typedef struct {		
    ElemStack *top;	
} Stack;


void push(Stack *s, Item item) {
    ElemStack *aux;

    // Cria um novo elemento da lista encadeada que representa a pilha e
    // armazena neste novo elemento o item a ser inserido na pilha
    aux = (ElemStack *)malloc(sizeof(ElemStack));
    aux->item = item;

    // Insere o novo elemento no início da lista encadeada que representa a
    // pilha
    aux->next = s->top;
    s->top = aux;
}
void pop(Stack *s, Item *item) {
    ElemStack *aux;

    // Verificar se a pilha está vazia!

    // Armazena o item a ser removido da pilha
    *item = s->top->item; // ATENÇÃO: Depende da definição do tipo do item

    // Armazena o primeiro elemento da lista encadeada que representa a pilha
    // e remove este primeiro elemento da lista
    aux = s->top;
    s->top = s->top->next;

    // Libera a memória alocada para o elemento removido
    free(aux);
}
void initStack(Stack *s) {
    s->top = NULL;
}
int isEmptyStack(Stack *s) {
    return (s->top == NULL);
}
//ou
/*int isEmptyStack(Stack *s) {
    if (s->top == NULL) return 1;
    else return 0;
}*/
void freeStack(Stack *s) {
    ElemStack *aux;

    while (!isEmptyStack(s)) {
        // Armazena o primeiro elemento da lista encadeada que representa a
        // pilha e remove este primeiro elemento da lista
        aux = s->top;
        s->top = s->top->next;

        // Libera a memória alocada para o elemento removido
        free(aux);
    }
}
int main() {
    Stack stack;
    Item item;

    initStack(&stack);

    for (int i = 0; i < 10; i++) {
        item = i;

        printf("Inserindo na pilha o item %d.\n", item);
        push(&stack, item);
    }
    // Continuacao do slide anterior

    while (isEmptyStack(&stack) == 0) {
        pop(&stack, &item);
        printf("Item %d removido da pilha.\n", item);
    }

    freeStack(&stack); // Sem efeito se a pilha já estiver vazia

    return 0;
}
