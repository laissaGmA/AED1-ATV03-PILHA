#include <stdio.h>
#include <ctype.h>
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

int isPalindrome(char* str) {
    Stack stack;
    initialize(&stack);
    
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        // Ignorar espaços em branco
        if (isspace(str[i])) {
            continue;
        }
        
        // Ignorar acentos e converter para letras minúsculas
        char c = tolower(str[i]);
        
        push(&stack, c);
    }
    
    for (int i = 0; i < len; i++) {
        // Ignorar espaços em branco
        if (isspace(str[i])) {
            continue;
        }
        
        // Ignorar acentos e converter para letras minúsculas
        char c = tolower(str[i]);
        
        if (c != pop(&stack)) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    char str[100];
    printf("Digite a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remover o caractere de nova linha da string
    str[strcspn(str, "\n")] = '\0';
    
    if (isPalindrome(str)) {
        printf("A string digitada eh um palindromo.\n");
    } else {
        printf("A string digitada nao eh um palindromo.\n");
    }
    
    return 0;
}
