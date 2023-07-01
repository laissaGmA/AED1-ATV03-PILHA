#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1 ? 1 : 0;
}

void push(Stack* stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Erro: Pilha cheia\n");
        return;
    }
    
    stack->top++;
    stack->data[stack->top] = value;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: Pilha vazia\n");
        return 0;
    }
    
    int value = stack->data[stack->top];
    stack->top--;
    return value;
}

int top(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: Pilha vazia\n");
        return 0;
    }
    
    return stack->data[stack->top];
}

void print(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Pilha vazia\n");
        return;
    }
    
    printf("Elementos da pilha: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initialize(&stack);
    
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    
    printf("Topo: %d\n", top(&stack));
    print(&stack);
    
    int value = pop(&stack);
    printf("Elemento removido: %d\n", value);
    
    print(&stack);
    
    return 0;
}
