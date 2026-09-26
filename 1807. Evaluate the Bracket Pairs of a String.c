#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASH_SIZE 200003

typedef struct Node {
    char *key;
    char *value;
    struct Node *next;
} Node;

unsigned long hash(const char *s) {
    unsigned long h = 0;
    while(*s) h = h * 131 + *s++;
    return h % HASH_SIZE;
}

void insert(Node **table, char *key, char *value) {
    unsigned long h = hash(key);
    Node *n = malloc(sizeof(Node));
    n->key = key;
    n->value = value;
    n->next = table[h];
    table[h] = n;
}

char *lookup(Node **table, const char *key) {
    unsigned long h = hash(key);
    Node *cur = table[h];
    while(cur) {
        if(strcmp(cur->key, key) == 0)
            return cur->value;
        cur = cur->next;
    }
    return NULL;
}

char* evaluate(char* s, char*** knowledge, int knowledgeSize, int* knowledgeColSize) {
    Node **table = calloc(HASH_SIZE, sizeof(Node*));
    for(int i = 0; i < knowledgeSize; i++) {
        insert(table, knowledge[i][0], knowledge[i][1]);
    }
    int n = strlen(s);
    char *result = malloc(n * 10 + 5);
    int ri = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            i++;
            int start = i;
            while(i < n && s[i] != ')') i++;
            int len = i - start;
            char key[105];
            memcpy(key, s + start, len);
            key[len] = '\0';
            char *val = lookup(table, key);
            if(val) {
                strcpy(result + ri, val);
                ri += strlen(val);
            } else {
                result[ri++] = '?';
            }
        } else {
            result[ri++] = s[i];
        }
    }

    result[ri] = '\0';
    return result;
}
