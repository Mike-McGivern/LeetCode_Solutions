#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 3000

void reverse(char *s) {
    int left = 0;
    int right = strlen(s) - 1;
    while(left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

char* reverseParentheses(char* s) {
    char *stack[2000];
    int top = 0;
    stack[top] = calloc(MAX_LEN, sizeof(char));
    for(int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        if(ch == '(') {
            top++;
            stack[top] = calloc(MAX_LEN, sizeof(char));
        } else if(ch == ')') {
            char *temp = stack[top];
            reverse(temp);
            top--;
            strcat(stack[top], temp);
            free(temp);
        } else {
            int len = strlen(stack[top]);
            stack[top][len] = ch;
            stack[top][len + 1] = '\0';
        }
    }

    return stack[0];
}
