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

// Function to evaluate a postfix expression
int evaluatePostfix(struct stack *s, char *postfix) {
    int i, operand1, operand2, result;

    for (i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            push(s, ch - '0'); // Convert character to integer
        } else {
            operand2 = pop(s);
            operand1 = pop(s);

            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                // Add more operators if needed
            }

            push(s, result);
        }
    }

    return pop(s);
}

int main() {
    struct stack s;
    s.top = -1;

    char postfix[20];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(&s, postfix);

    printf("Result: %d\n", result);

    return 0;
}
