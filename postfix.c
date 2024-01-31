#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct stack {
    char items[20];
    int top;
};

// Function to push a character onto the stack
void push(struct stack *s, char ch) {
    if (s->top == 19) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = ch;
}

// Function to pop a character from the stack
char pop(struct stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

// Function to get the precedence of an operator
int getPrecedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0; // Assuming all other characters are operands
    }
}

// Function to convert infix expression to postfix expression
void infixToPostfix(struct stack *s, char *infix, char *postfix) {
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        switch (ch) {
            case '(':
                push(s, ch);
                break;
            case ')':
                while (s->top != -1 && s->items[s->top] != '(') {
                    postfix[j++] = pop(s);
                }
                if (s->top != -1 && s->items[s->top] == '(') {
                    pop(s); // Pop '(' from the stack
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (s->top != -1 && getPrecedence(s->items[s->top]) >= getPrecedence(ch)) {
                    postfix[j++] = pop(s);
                }
                push(s, ch);
                break;
            default:
                // If the character is an operand, add it to the postfix expression
                postfix[j++] = ch;
        }
    }

    // Pop remaining operators from the stack and add to postfix
    while (s->top != -1) {
        postfix[j++] = pop(s);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    struct stack s;
    s.top = -1;

    char infix[20], postfix[20];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(&s, infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
