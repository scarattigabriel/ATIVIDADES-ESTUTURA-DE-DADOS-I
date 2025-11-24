/*Faça um aplicativo de venda simples de produtos para uma pequena loja.
O produto deve ser cadastrado com um código (que deve ser único), um nome,
um valor de compra e um valor de venda, além da quantidade em estoque.
Assim, o aplicativo deverá ter as seguintes opções:
1. Cadastrar produto
2. Atualizar produto (apenas preços e quantidade em estoque)
3. Excluir produto
4. Venda
5. Listar produtos (todos ou por quantidade em estoque)
6. Sair
Ao ser feita uma venda, o usuário deverá informar o código do produto, a quantidade comprada.
Ao finalizar a entrada deverá aparecer o nome do produto comprado, a quantidade comprada e o
valor total da compra. Lembrando que se a quantidade comprada for superior a existente em
estoque, a venda não deve ser efetivada e o usuário deve ser informado. Não esqueça de
atualizar o estoque após a venda*/

#include <stdio.h>
#include <stdlib.h>

//ESTRUTURA DO PRODUTO
struct tproduto
{
    int codigo;
    char nome[70];
    float valor_custo, valor_venda, estoque;
};
typedef struct tproduto produto;

//ESTRUTURA DA ÁRVORE BINÁRIA DE BUSCA
struct tnode
{
    produto p;                        // estrutura do produto
    struct tnode *direita, *esquerda; // ponteiro para os filhos
};
typedef struct tnode node;


//FUNÇÃO DE CRIAÇÃO DO PRODUTO
node *criarProduto()
{
    node *novo_n = (node *)malloc(sizeof(node));//ALLOCA MEMÓRIA PARA O NOVO NÓ
    //ATRIBUI OS VALORES PARA O NÓ
    printf("Digite o codigo: ");
    scanf("%d", &novo_n->p.codigo);
    printf("Digite o nome: ");
    scanf("%s", novo_n->p.nome);
    printf("Valor de custo: ");
    scanf("%f", &novo_n->p.valor_custo);
    printf("Valor de venda: ");
    scanf("%f", &novo_n->p.valor_venda);
    printf("Quantidade em estoque: ");
    scanf("%f", &novo_n->p.estoque);
    //NULLIFICA OS PONTEIROS
    novo_n->esquerda = NULL;
    novo_n->direita = NULL;
    return novo_n;
}

//FUNÇÃO DE ISERERIR O PRODUTO CRIADO NA ÁRVORE
node *inserirProduto(node *raiz, node *novo_n)
{
    if (raiz == NULL)//VERIFICA SE A RAIZ É NULA. SE SIM, RETORNA O NOVO NÓ
    {
        return novo_n;
    }
    else //CAI NO ELSE SE A RAIZ NÃO FOR NULA
    {
        if (novo_n->p.codigo < raiz->p.codigo)
        {
            raiz->esquerda = inserirProduto(raiz->esquerda, novo_n);//SE O CÓDGIO DO NOVO NÓ FOR MENOR, VAI PARA A ESQUERDA
        }
        else if (novo_n->p.codigo > raiz->p.codigo)
        {
            raiz->direita = inserirProduto(raiz->direita, novo_n);//SE O CÓDIGO DI NOV NO FR MAIOR VAI PARA A DIREITA
        }
        else if (novo_n->p.codigo == raiz->p.codigo) // SE O CÓDIGO JA EXISTIR RETORNA MENSAGEM DE ERRO
        {
            printf("Produto já cadastrado! \n");
            free(novo_n);
        }
    }

    return raiz;
}


//FUNÇÃO PARA BUSCAR SE HÁ UM PRODUTO NA ARVORE PELO SEU CÓDIGO
node *buscarProduto(node *raiz, int codigo)
{
    if (raiz == NULL)
    {
        return NULL;//código não encontrado
    }
    if (raiz->p.codigo == codigo) return raiz;//achou o código

    if (codigo < raiz->p.codigo)
    {
        return buscarProduto(raiz->esquerda, codigo);//busca na esquerda
    }
    else
    {
        return buscarProduto(raiz->direita, codigo);//busca na direita
    }
}

//FUNÇÃO PARA ATUALIZAR O PRODUTO
void atualizarProdutor(node *raiz)
{
    int codigo;
    printf("Digite o código do produto que deseja atualizar: ");
    scanf("%d", &codigo);
    if(buscarProduto(raiz, codigo) == NULL)//se buscar o produto e não encontrar
    {
        printf("Produto não encontrado!\n");
        return;
    }
    else
    {
        node *produto_atualizar = buscarProduto(raiz, codigo);//se encontrar, armazena o nó em uma nova vairavel
        //atribui os novos valores
        printf("Digite o novo valor de custo: ");
        scanf("%f", &produto_atualizar->p.valor_custo);
        
        printf("Digite o novo valor de venda: ");
        scanf("%f", &produto_atualizar->p.valor_venda);
        
        printf("Digite o novo estoque: ");
        scanf("%f", &produto_atualizar->p.estoque);

        printf("Produto atualizado!");

    }


}

//FUNÇÃO PARA ACHAR O MÍNIMO DA SUBÁRVORE
node *minimo(node *raiz)
{
    node *atual = raiz;
    //Percorre a árvore até encontrar o nó mais à esquerda
    while (atual && atual->esquerda != NULL)
    {
        atual = atual->esquerda;
    }
    return atual;
}

//FUNÇÃO DE EXCLUSÃO DO PRODUTO
node *excluirProduto(node *raiz, int codigo)
{

    if (raiz == NULL)//se a rraiz for nula é porque não encontrou o produto
    {
        printf("Produto não encontrado!\n");
        return raiz;
    }

    if (codigo < raiz->p.codigo)//se o código for menor, vai para a esquerda
        raiz->esquerda = excluirProduto(raiz->esquerda, codigo);
    else if (codigo > raiz->p.codigo)//se for maior vai para a direita
        raiz->direita = excluirProduto(raiz->direita, codigo);
    else
    {
        // Nó encontrado
        
        // Caso 1: Sem filhos ou 1 filho
        if (raiz->esquerda == NULL)
        {
            node *temp = raiz->direita;
            free(raiz);
            printf("Produto excluido com sucesso!\n");
            return temp;
        }
        else if (raiz->direita == NULL)
        {
            node *temp = raiz->esquerda;
            free(raiz);
            printf("Produto excluido com sucesso!\n");
            return temp;
        }

        // Caso 2: 2 filhos (pega o menor da subarvore direita)
        node *temp = minimo(raiz->direita);
        
        // Copia os dados do sucessor para este nó
        raiz->p = temp->p;

        // Exclui o sucessor duplicado
        raiz->direita = excluirProduto(raiz->direita, temp->p.codigo);
    }
    return raiz;
}




//FUNÇÃO PARA LISTAR OS PRODUTOS in order 
void listarProduto(node *raiz)
{
    if (raiz == NULL)//if a raiz for nula, retorna
    {
        return;
    }
    listarProduto(raiz->esquerda);//percorre a subárvore esquerda
    //imprime
    printf("Código: %d\nNome: %s\nEstoque:%f\nValor de custo: %f\nValor de venda:%f", raiz->p.codigo, raiz->p.nome, raiz->p.estoque, raiz->p.valor_custo, raiz->p.valor_venda);
    //percorre a subárvore direita
    listarProduto(raiz->direita);
}

//FUNÇÃO DE VENDA DE PRODTUO
node *venderProduto(node *raiz)
{
    int codigo, quantidade;
    printf("Digite o código do produto que deseja vender: ");
    scanf("%d", &codigo);
    printf("Digite a quantidade que deseja vender: ");
    scanf("%d", &quantidade);

    node *produto_vender = buscarProduto(raiz, codigo);//busca o produto pelo código
    if (produto_vender == NULL)//se não encontrar o produto
    {
        printf("Produto não encontrado!\n");
        return raiz;
    }   
    if (produto_vender->p.estoque < quantidade)//se o estoque for menor que a quantidade desejada
    {
        printf("Estoque insuficiente!\n");
        return raiz;
    }   
    produto_vender->p.estoque -= quantidade;//descresse a quantidade vendida do estoque
    float total_venda = quantidade * produto_vender->p.valor_venda; //calcula o total da venda
    printf("Venda realizada com sucesso!\n");
    printf("Produto: %s\nQuantidade vendida: %d\nValor total da venda: %.2f\n", produto_vender->p.nome, quantidade, total_venda);
    return raiz;
}





int main()
{
    node *raiz = NULL;
    while (1)
    {
        int op;
        printf("1-Cadastrar produto\n"
               "2-Atualizar produto\n"
               "3-Excluir produto\n"
               "4-Venda\n"
               "5-Listar Produtos\n"
               "6-Sair\n:");
        scanf("%d", &op);
        switch (op)
        {
            
        case 1:
            raiz = inserirProduto(raiz, criarProduto());
            break;
        case 2:
            atualizarProdutor(raiz);
            break;
        case 3:
            {
                int codigo;
                printf("Digite o código do produto que deseja excluir: ");
                scanf("%d", &codigo);
                raiz = excluirProduto(raiz, codigo);
            }
            break;
        case 4:
            raiz = venderProduto(raiz);
            break;
        case 5:
            listarProduto(raiz);
        case 6:
            exit(0);
            break;

        default:
            break;
        }
    }
    return 0;
}