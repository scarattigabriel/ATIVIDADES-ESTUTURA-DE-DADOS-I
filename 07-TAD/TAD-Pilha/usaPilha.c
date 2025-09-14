#include <stdio.h>
#include "pilha.c"

int main()
{
    pilha pilha1;
    pilha1.pos_ultimo_elm=0;
    pushPilha(pilha1, 1);
    pushPilha(pilha1, 2);
    

    printf("%d", pilha1.vetor[1]);

    return 0;
}