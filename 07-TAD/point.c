#include <stdio.h>
#include "point.h"
#include <math.h>

Point setPoint(int x, int y)
{
    Point p;
    p.x=x;
    p.y=y;
    
    return p; 
}

Point getPoint(Point p)
{
    return p;    
}
int getX(Point p)
{
    return p.x;
}
int getY(Point p)
{
    return p.x;
}
void printPoint(Point p, int jump)
{
    printf("(%d, %d)", p.x, p.y);
    if (jump==1)printf("\n");
}

//√((x₂ – x₁)² + (y₂ – y₁)²)

float distancePoint ( Point a, Point b)
{
    float distance;
    distance=sqrt((pow((b.x - a.x), 2) + pow((b.y - a.y), 2)));

    return distance;
}