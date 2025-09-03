/*int comparaDatas(Data data1, Data data2)
Retorna -1 se a data data1 é anterior à data data2, 1 se a data data1 é posterior à data data2 e 0 se as datas data1 e data2 são iguais.
*/

#include <stdio.h>

struct tdata
{
    int dia, mes, ano;
}; typedef struct tdata Data;
int ComparaData(Data, Data);
Data ConstrutorData(int, int, int);


int main()
{

    Data data1, data2;
    int dia, mes, ano;
    printf("Digite o dia, mes e ano: ");
    scanf("%d %d %d", &dia, &mes, &ano);    
    data1=ConstrutorData(dia, mes, ano);
    printf("Digite o dia, mes e ano: ");  
    scanf("%d %d %d", &dia, &mes, &ano);
    data2=ConstrutorData(dia, mes, ano);
    printf("Comparação: %d\n", ComparaData(data1, data2));

    return 0;
}

int ComparaData(Data data1, Data data2) {
    if (data1.ano < data2.ano)return -1;
    if (data1.ano > data2.ano) return 1;
    if (data1.mes < data2.mes)return -1;
    if (data1.mes > data2.mes)return 1;
    if (data1.dia < data2.dia)return -1;
    if (data1.dia > data2.dia)return 1;
    return 0;
}



/*int ComparaData(Data data1, Data data2)
{

    if ((data1.ano < data2.ano) || ((data1.ano == data2.ano) && (data1.mes < data2.mes)) || ((data1.ano == data2.ano) && (data1.mes == data2.mes)&& (data1.dia < data2.dia)))
    {
        return -1;
    }
    else
        if ((data1.ano > data2.ano) || ((data1.ano == data2.ano) && (data1.mes > data2.mes)) || ((data1.ano == data2.ano) && (data1.mes == data2.mes)&& (data1.dia > data2.dia)))
        {
            return 1;
        }
    else
        {
            return 0;
        }
}
*/
Data ConstrutorData(int dia, int mes, int ano)
{
    Data c_data;
    c_data.dia=dia;
    c_data.mes=mes;
    c_data.ano=ano;

    return c_data;

}



