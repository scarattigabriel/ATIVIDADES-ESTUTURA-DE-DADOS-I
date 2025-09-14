/*Nesta tarefa, deverá ser implementado um TAD para manipular triângulos:

- O arquivo de cabeçalho deverá ser chamado de triangle.h

- O arquivo de definição deverá ser chamado de triangle.c

- A estrutura deverá ser composta por três inteiros que representam os 3 lados de um triângulo.

- Deverão ser implementados, pelo menos, os seguintes métodos: setTriangle (atribui os valores aos lados dos triângulos), getType (retorna 1 se o triângulo for equilátero, 2 se for isoscelese, 3 caso for escaleno e 0 se os lados não formam um triângulo), showTriangle (mostra o triangulo no forma AB: valor lado A, BC: valor lado B e CA: valor lado A), getPerimeter (retorna o perímetro do triangulo), getArea (retorna a área do triangulo - deverá ser utilizada a fórmula de Heron para calcular a área baseada nos lados), e isSimilar (retorna 1 se os triângulos são similares, se não retorna 0 - calcula o coseno dos dois triângulos baseado nas medidas dos lados e verifica se são iguais)

GERAR um zip com o .h. e .c cujo o nome é a sua matrícula.

O programa abaixo será usado para testar a TAD submetida. Não precisa submeter o programa que usa a TAD, pois eu usarei o que está abaixo:*/

struct ttriangle
{
    int lado_a, lado_b, lado_c; 
};typedef struct ttriangle trngl;
