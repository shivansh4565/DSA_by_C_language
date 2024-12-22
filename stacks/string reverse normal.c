#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    int start = 0, end = strlen(str) - 1;
    while (start < end) {
        // Swap characters at start and end
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char str[] = "Hello";
    reverseString(str);
    printf("Reversed string: %s\n", str);
    return 0;
}
