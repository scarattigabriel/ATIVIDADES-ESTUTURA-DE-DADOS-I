#include <stdio.h>
#include <stdlib.h>

struct tinteiro
{
int value;
struct tinteiro *next;
};typedef struct tinteiro inteiro;


int main()
{


    inteiro *p, *aux, *first = NULL;
    int i=0;


    while (1)
    {
        i++;
        p=(inteiro *)malloc(sizeof(inteiro));
        p->value=i;
        p->next=NULL;
        if (first == NULL)
        {
        first = p;
        aux = p;
        }
        else
        {
            aux->next=p;
        } 
        aux = p; 
        if (i == 100)
        {
            break;;
        }
    }
 
    for(aux = first; aux!= NULL; aux=aux->next)
    {
        printf("%d\n", aux->value);
    }



    return 0;
}



