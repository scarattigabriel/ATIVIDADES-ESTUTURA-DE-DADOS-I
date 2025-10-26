#include <stdio.h>
#include <stdlib.h>

struct tdouble
{
    float value;
    struct tdouble *next, *prev;
};typedef struct tdouble doub;

struct tsent
{
    doub *head, *tail;
};typedef struct tsent sent; 

int main()
{
    doub *p,*aux;
    sent sentinel={NULL, NULL};

    p=(doub *)malloc(sizeof(doub));
    p -> value = 1.55;
    p -> next = NULL;
    p -> prev = NULL;
    if (sentinel.head == NULL)
    {
        sentinel.head=p;
        sentinel.tail=p;
        aux=p;
    }
    else
    {
        aux -> next = p;
        p -> prev = aux;
        aux = p;
        sentinel.tail = p;
    }


    return 0;
}