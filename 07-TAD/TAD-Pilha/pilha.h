#define MAX 100


struct tpilha
{
    int vetor[MAX];
    int pos_ultimo_elm;
};typedef struct tpilha pilha;

pilha pushPilha(pilha, int);
int pop(pilha *p);
