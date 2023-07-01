#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Erro: Pilha cheia\n");
        return;
    }
    
    stack->top++;
    stack->data[stack->top] = value;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: Pilha vazia\n");
        return '\0';
    }
    
    char value = stack->data[stack->top];
    stack->top--;
    return value;
}

char top(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: Pilha vazia\n");
        return '\0';
    }
    
    return stack->data[stack->top];
}

int isMatchingPair(char opening, char closing) {
    if (opening == '(' && closing == ')')
        return 1;
    if (opening == '[' && closing == ']')
        return 1;
    if (opening == '{' && closing == '}')
        return 1;
    return 0;
}

int isBalanced(char* expression) {
    Stack stack;
    initialize(&stack);
    
    int len = strlen(expression);
    for (int i = 0; i < len; i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(&stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (isEmpty(&stack)) {
                return 0;
            } else if (!isMatchingPair(top(&stack), expression[i])) {
                return 0;
            } else {
                pop(&stack);
            }
        }
    }
    
    return isEmpty(&stack);
}

int main() {
    char expression[MAX_SIZE];
    printf("Digite a expressao: ");
    fgets(expression, sizeof(expression), stdin);
    
    // Remover o caractere de nova linha da string
    expression[strcspn(expression, "\n")] = '\0';
    
    if (isBalanced(expression)) {
        printf("Os parenteses, colchetes e chaves estao bem balanceados.\n");
    } else {
        printf("Os parenteses, colchetes e chaves nao estao bem balanceados.\n");
    }
    
    return 0;
}
