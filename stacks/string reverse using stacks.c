#include <stdio.h>
#include <string.h>

#define MAX 100

void reverseStringUsingStack(char *str) {
    int len = strlen(str);
    char stack[MAX];
    int top = -1;

    // Push all characters into stack
    for (int i = 0; i < len; i++) {
        stack[++top] = str[i];
    }

    // Pop characters from stack and put them back in the string
    for (int i = 0; i < len; i++) {
        str[i] = stack[top--];
    }
}

int main() {
    char str[] = "Hello";
    reverseStringUsingStack(str);
    printf("Reversed string using stack: %s\n", str);
    return 0;
}
