#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Erro: Pilha cheia\n");
        return;
    }
    
    stack->top++;
    stack->data[stack->top] = value;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: Pilha vazia\n");
        return -1;
    }
    
    int value = stack->data[stack->top];
    stack->top--;
    return value;
}

void fibonacci(Stack* stack, int n) {
    int a = 0;
    int b = 1;
    
    for (int i = 0; i < n; i++) {
        push(stack, a);
        int temp = a;
        a = b;
        b = temp + b;
    }
}

int main() {
    int n;
    printf("Digite a quantidade de valores da sequencia de Fibonacci a serem acumulados na pilha: ");
    scanf("%d", &n);
    
    Stack stack;
    initialize(&stack);
    
    fibonacci(&stack, n);
    
    printf("Valores acumulados na pilha:\n");
    while (!isEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }
    printf("\n");
    
    return 0;
}
