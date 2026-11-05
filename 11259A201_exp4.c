
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

float stack[MAX];
int top = -1;

void push(float val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = val;
    }
}

float pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return 0;
    }

    return stack[top--];
}

float evaluatePostfix(char postfix[]) {
    int i;
    float op1, op2, result;

    top = -1;

    for (i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isdigit((unsigned char)c)) {
            push(c - '0');
        }

        else if (isspace((unsigned char)c)) {
            continue;
        }

        else {
            op2 = pop();
            op1 = pop();

            switch (c) {
                case '+':
                    result = op1 + op2;
                    break;

                case '-':
                    result = op1 - op2;
                    break;

                case '*':
                    result = op1 * op2;
                    break;

                case '/':
                    if (op2 == 0) {
                        printf("Error: Division by zero.\n");
                        return 0;
                    }
                    result = op1 / op2;
                    break;

                case '^':
                    result = pow(op1, op2);
                    break;

                default:
                    printf("Invalid operator: %c\n", c);
                    return 0;
            }

            push(result);
        }
    }

    if (top != 0) {
        printf("Invalid postfix expression.\n");
        return 0;
    }

    return pop();
}

int main() {
    char postfix[MAX];

    printf("Enter a postfix expression (single-digit operands): ");
    scanf("%99s", postfix);

    printf("Result = %.2f\n", evaluatePostfix(postfix));

    return 0;
}
