#include "pilha.h"
#include <stdio.h>




/*pilha pushPilha(pilha p, int valor)
{
    if (p.pos_ultimo_elm == 1)
    {
    p.vetor[p.pos_ultimo_elm] = valor;
    }
    else
    {
    p.pos_ultimo_elm++;
    p.vetor[p.pos_ultimo_elm] = valor;
    }
    return p;
}*/


pilha pushPilha(pilha p, int valor)
{
    if (p.pos_ultimo_elm >= MAX)
    {
        return ;
    }
    p.vetor[p.pos_ultimo_elm]=valor;
    p.pos_ultimo_elm++;
    return p;
}




/*pilha pop(pilha p)
{
    if (p.pos_ultimo_elm == 0)
    {
        printf("Pilha vazia!");
    }
    else
    {
    p.pos_ultimo_elm--;
    }
    return p;
}*/

int pop(pilha *p)
{
    if (p->pos_ultimo_elm == 0)
    {
        return -1;
    }
    p->pos_ultimo_elm--;
    int v=p->vetor[p->pos_ultimo_elm];
}