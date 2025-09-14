#include <stdio.h>
#include "triangle.h"
#include <math.h>

void setTriangle(trngl *triangle, int lado_a, int lado_b, int lado_c)
{
    triangle->lado_a=lado_a;
    triangle->lado_b=lado_b; 
    triangle->lado_c=lado_c;

}

int getType(trngl triangle)
{
    if((triangle.lado_a + triangle.lado_b > triangle.lado_c) && (triangle.lado_a + triangle.lado_c > triangle.lado_b) && (triangle.lado_b + triangle.lado_c > triangle.lado_a))
    {
        if ((triangle.lado_a == triangle.lado_b) && (triangle.lado_a == triangle.lado_c) && (triangle.lado_b == triangle.lado_c))
        {
            return 1;//EQUILÁTERO
        }
        else
            if ((triangle.lado_a != triangle.lado_b) && (triangle.lado_a != triangle.lado_c) && (triangle.lado_b != triangle.lado_c))
            {
                return 3;//ESCALENO
            }
        else
        {
            return 2;//ISOSCELES
        }
    }
    else
    {
        return 0;//NÃO FORMA UM TRIÂNGULO
    }
}

void showTriangle(trngl triangle)
{
    printf("AB: %d, BC: %d, CA: %d", triangle.lado_a, triangle.lado_b, triangle.lado_c);
}


int getPerimeter(trngl triangle)
{
    return triangle.lado_a + triangle.lado_b + triangle.lado_c;
}

//p = (a + b + c) / 2

float getArea(trngl triangle)
{
    float semiperimeter;
    semiperimeter= getPerimeter(triangle) / 2.0;
    return sqrt((semiperimeter * (semiperimeter - triangle.lado_a) * (semiperimeter - triangle.lado_b) * (semiperimeter - triangle.lado_c)));
}


float cosA (trngl triangle)
{
    return (pow(triangle.lado_b, 2) + pow(triangle.lado_c, 2) - pow(triangle.lado_a, 2)) / (2 * triangle.lado_b * triangle.lado_c);
}

float cosB (trngl triangle)
{
    return (pow(triangle.lado_a, 2) + pow(triangle.lado_c, 2) - pow(triangle.lado_b, 2)) / (2 * triangle.lado_a * triangle.lado_c);
}

float cosC (trngl triangle)
{
    return (pow(triangle.lado_a, 2) + pow(triangle.lado_b, 2) - pow(triangle.lado_c, 2)) / (2 * triangle.lado_a * triangle.lado_b);
}

int isSimilar(trngl triangle1, trngl triangle2)
{ 
    if ((cosA(triangle1) == cosA(triangle2)) && (cosB(triangle1) == cosB(triangle2)) && (cosC(triangle1) == cosC(triangle2)))
    {
        return 1;
    }
    else{
        return 0;
    }

}
