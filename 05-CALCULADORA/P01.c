#include <stdio.h>

int Multiplicacao(int, int);
int Potenciacao(int, int);
int RestoDaDivisao(int, int);

int main()
{
    int operador, num1, num2;
    do
    {
        printf("Escolha a operação: \n1-Multiplicação\n2-Potenciação\n3-Resto da Divisao\n0-Sair\n");
        scanf("%d", &operador);
        if (operador == 1 || operador == 2 || operador == 3)
        {
            printf("Digite o primeiro número:  \n");
            scanf("%d", &num1);
            printf("Digite o segundo número: \n");
            scanf("%d", &num2);
            if (operador == 1)
            {
                printf("%d\n", Multiplicacao(num1, num2));
            }
            
            if (operador == 2)
            {
                printf("%d\n", Potenciacao(num1, num2));
            }
            if (operador == 3)
            {
                printf("%d\n", RestoDaDivisao(num1, num2));
            }

        }
        else
            if(operador != 0)
            {
                printf("Digite um operador válido\n");
            }
        
    } while (operador!=0);

    
    return 0;
}


int Multiplicacao(int num1, int num2)
{
    int acumulador=0;
    if (num1 == 0 || num2 ==0)
    {
        return 0;
    } 
    else
        if (num1 == 1)
        {
            return num2;
        }
    else
        if (num2 == 1 )
        {
           return num1;
        }
    else{ 
        for (int i=0; i < num1; i++)
        {
            acumulador+=num2;
        }
        return acumulador;
        }


}

int Potenciacao(int base, int expoente)
{
    if(base == 0)
    {
        return 0;
    }
    else 
        if (base == 1)
        {
            return 1;
        }
    else   
        if (expoente == 0)
    {
        return 1;
    }
    else
        if (expoente == 1)
        {
            return base;
        }
    else
    {
        int acumulador;
        acumulador = base;
        for(int i=0; i<(expoente-1); i++)
        {
            acumulador*=base;
        }
        return acumulador;
    }
}     

    int RestoDaDivisao(int dividendo, int divisor)
    {
        if (divisor == 0)
        {
            return -1;
        }
        else
            if (dividendo == 0 || dividendo == divisor || divisor == 1)
        {
            return 0;
        } 
        else
            if (dividendo < divisor)
            {
                return dividendo;
            }
            
        else
        {
            while (dividendo > divisor)
            {
                dividendo-=divisor;
            }
            return dividendo;        
        }

    }

