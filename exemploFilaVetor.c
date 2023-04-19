#include <stdio.h>
#define MAX_SIZE 10 // Tamanho máximo da fila

// Definindo a estrutura da fila
typedef struct
{
    int data[MAX_SIZE];
    int front; // Índice do início da fila
    int rear;  // Índice do fim da fila
} Queue;

// Função para criar uma fila vazia
void createQueue(Queue *queue)
{
    queue->front = -1; // Inicializa o início da fila como -1
    queue->rear = -1;  // Inicializa o fim da fila como -1
}

// Função para verificar se a fila está vazia
int isEmpty(Queue *queue)
{
    return (queue->front == -1 && queue->rear == -1);
}

// Função para verificar se a fila está cheia
int isFull(Queue *queue)
{
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Função para enfileirar um elemento na fila
void enqueue(Queue *queue, int value)
{
    if (isFull(queue))
    {
        printf("A fila está cheia. Não é possível enfileirar.\n");
        return;
    }
    else if (isEmpty(queue))
    {
        queue->front = 0; // Se a fila estiver vazia, atualiza o início da fila para 0
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE; // Atualiza o fim da fila circularmente
    queue->data[queue->rear] = value;           // Insere o valor no fim da fila
}

// Função para desenfileirar um elemento da fila
int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("A fila está vazia. Não é possível desenfileirar.\n");
        return -1;
    }
    else if (queue->front == queue->rear)
    {
        // Se houver apenas um elemento na fila, atualiza o início e fim da fila para -1
        int value = queue->data[queue->front];
        queue->front = -1;
        queue->rear = -1;
        return value;
    }
    else
    {
        int value = queue->data[queue->front];        // Armazena o valor do início da fila
        queue->front = (queue->front + 1) % MAX_SIZE; // Atualiza o início da fila circularmente
        return value;
    }
}

int main()
{
    Queue queue;                                              // Cria uma fila
    createQueue(&queue);                                      // Inicializa a fila
    enqueue(&queue, 10);                                      // Enfileira o valor 10
    enqueue(&queue, 20);                                      // Enfileira o valor 20
    enqueue(&queue, 30);                                      // Enfileira o valor 30
    printf("Elemento desenfileirado: %d\n", dequeue(&queue)); // Desenfileira e imprime o valor
    printf("Elemento desenfileirado: %d\n", dequeue(&queue)); // Desenfileira e imprime o valor
    printf("Elemento desenfileirado: %d\n", dequeue(&queue)); // Desenfileira e imprime o valor
    printf("Elemento desenfileirado: %d\n", dequeue(&queue)); // Tentativa de desenfileirar de fila

return 0;
}