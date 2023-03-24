#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int dado;
    struct lista *prox;
} celula;

void imprimir();
void push();
void pop();

celula *top = NULL;

int main()
{
    int n;
    char opcao;
    do
    {
        printf("MENU DA PILHA\n-----------------\ne.Empilhar\nd.Desempilhar\ni.Imprimir\ns.Exit\n");
        printf("\nEscolha uma opcao: ");
        scanf("%c", &opcao);
        switch (opcao)
        {
        case 'e':
            printf("Entre com um item a ser empilhado: ");
            scanf("%d", &n);
            push(n);
            break;
        case 'd':
            pop();
            break;
        case 'i':
            imprimir();
            break;
        }
    } while (opcao != 's');
}

void push(int item)
{
    printf("\n\nEmpilhando\n\n");
    celula *novo = malloc(sizeof(celula));
    novo->dado = item;
    novo->prox = top;
    top = novo;
    printf("\nValor %d empilhado\n", novo->dado);
}

void pop()
{
    if (top == NULL)
    {
        printf("\nA pilha está vazia!\n");
    }
    else
    {
        celula *temp;
        temp = top;
        top = top->prox;
        printf("\nDesempilhando\n", temp->dado);
        free(temp);
    }
}
void imprimir()
{
    if (top == NULL)
    {
        printf("\nA pilha esta vazia!\n\n");
    }
    else
    {
        celula *temp;
        temp = top;
        printf("\nImprimindo PILHA\n");
        while (temp != NULL)
        {
            printf("\n%d\n\n", temp->dado);
            temp = temp->prox;
        }
    }
}