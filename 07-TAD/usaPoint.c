#include <stdio.h>
#include "point.c"

int main()
{
    Point p1, p2;
    p1=setPoint(3,5);
    p2=setPoint(10, 19);

    printPoint(p1, 1);
    printPoint(p2, 1);

    printf("%f", distancePoint(p1, p2));
    
    return 0;
}