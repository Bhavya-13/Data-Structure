#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 106

char stack[MAX_SIZE];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1)
        return '\0';
    return stack[top--];
}

bool isEmpty() {
    return top == -1;
}

bool isValidInput(char* s) {
    int len = strlen(s);

    if (len < 1 || len > 106) {
        printf("Error: String length must be between 1 and 106.\n");
        return false;
    }

    for (int i = 0; i < len; i++) {
        if (s[i] != '{' && s[i] != '}' &&
            s[i] != '(' && s[i] != ')' &&
            s[i] != '[' && s[i] != ']') {
            printf("Error: Invalid character '%c' found. Only brackets are allowed.\n", s[i]);
            return false;
        }
    }

    return true;
}

bool isBalanced(char* s) {
    top = -1;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        else if (ch == ')') {
            if (pop() != '(')
                return false;
        }
        else if (ch == '}') {
            if (pop() != '{')
                return false;
        }
        else if (ch == ']') {
            if (pop() != '[')
                return false;
        }
    }

    return isEmpty();
}

int main() {
    char s[MAX_SIZE];

    printf("Enter the bracket expression: ");
    scanf("%1000000s", s);

    if (!isValidInput(s))
        return 1;

    if (isBalanced(s))
        printf("Output: true (Expression is balanced)\n");
    else
        printf("Output: false (Expression is not balanced)\n");

    return 0;
}
