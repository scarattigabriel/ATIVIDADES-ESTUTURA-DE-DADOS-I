/*Escreva as seguintes funções considerando o tipo Data definido nesta apresentação:
int extraiDia(Data data)
Retorna o dia que compõe a data passada como parâmetro (data)*/

#include <stdio.h>

struct tdata
{
    int dia, mes, ano;
}; typedef struct tdata Data;
int extraiData(Data);
Data ConstrutorData(Data, int, int, int);

int main()
{

    Data data;
    int dia, mes, ano;
    printf("Digite o dia, mes e ano: ");
    scanf("%d %d %d", &dia, &mes, &ano);    
    ConstrutorData(data, dia, mes, ano);
    printf("Dia: %d\n", extraiData(data));


    return 0;
}

int extraiData(Data data)
{
    return data.dia;
}

Data ConstrutorData(Data data, int dia, int mes, int ano)
{
    Data CData;
    CData.dia=dia;
    CData.mes=mes;
    CData.ano=ano;

    return CData;

}


