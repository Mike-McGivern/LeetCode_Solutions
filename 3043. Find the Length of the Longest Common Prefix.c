#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 200003

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* hashTable[HASH_SIZE];
int hash(int x) {
    return (x * 1315423911u) % HASH_SIZE;
}

void insert(int x) {
    int h = hash(x);
    Node* n = malloc(sizeof(Node));
    n->val =x;
    n->next = hashTable[h];
    hashTable[h] = n;
}

int exists(int x) {
    int h = hash(x);
    Node* cur = hashTable[h];
    while(cur) {
        if(cur-> val == x) return 1;
        cur = cur -> next;
    }
    return 0;
}
int longestCommonPrefix(int* arr1, int arr1Size, int* arr2, int arr2Size) {
    for (int i = 0; i < HASH_SIZE; i++) {
       Node* cur = hashTable[i];
        while (cur) {
            Node* nxt = cur->next;
            free(cur);
            cur = nxt;
        }
        hashTable[i] = NULL;
    }
    
    for(int i = 0; i < arr1Size; i++) {
        int x = arr1[i];
        while(x > 0) {
            insert(x);
            x /= 10;
        }
    }

    int best = 0;

    for(int i = 0; i < arr2Size; i++) {
        int x = arr2[i];
        while(x > 0) {
            if (exists(x)) {
                int len = 0, t = x;
                while(t > 0) {
                    len++;
                    t /= 10;
                }
                if(len > best) best = len;
                break;
            }
            x /= 10;
        }
    }

    return best;
}
