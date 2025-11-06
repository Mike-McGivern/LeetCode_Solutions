/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>

 typedef struct {
    int* data;
    int size;
    int capacity;
 } IntArray;

IntArray* createIntArray() {
    IntArray* arr = (IntArray*)malloc(sizeof(IntArray));
    arr -> data = NULL;
    arr -> size = 0;
    arr -> capacity = 0;
    return arr;
}

void appendIntArray(IntArray* arr, int value) {
    if (arr -> size == arr -> capacity) {
        arr -> capacity = (arr -> capacity == 0) ? 1 : arr -> capacity * 2;
        arr -> data = (int*)realloc(arr -> data, sizeof(int) * arr -> capacity);
    }
    arr -> data[arr -> size++] = value;
}

void freeIntArray(IntArray* arr) {
    free(arr -> data);
    free(arr);
}

int find(int i, int* parent) {
    if(parent[i] == i) {
        return i;
    }
    parent[i] = find(parent[i], parent);
    return parent[i];
}

void union_sets(int i, int j, int* parent) {
    int root_i = find(i, parent);
    int root_j = find(j, parent);
    if(root_i != root_j) {
        parent[root_j] = root_i;
    } else {
        parent[root_i] = root_j;
    }
}


int* processQueries(int c, int** connections, int connectionsSize, int* connectionsColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int* parent = (int*)malloc(sizeof(int) * (c + 1));
    for(int i = 0; i <= c; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < connectionsSize; i++) {
        union_sets(connections[i][0], connections[i][1], parent);
    }

    IntArray** component_members = (IntArray**)malloc(sizeof(IntArray*) * (c + 1));
    for(int i = 0; i <= c; i++) {
        component_members[i] = NULL;
    }

    for(int i = 1; i <= c; i++) {
        int root = find(i, parent);
        if(component_members[root] == NULL) {
            component_members[root] = createIntArray();
        }
        appendIntArray(component_members[root], i);
    }

    bool* offline = (bool*)calloc(c + 1, sizeof(bool)); //init
    int* component_ptr = (int*)calloc(c + 1, sizeof(int)); //init dec
    int* results = (int*)malloc(sizeof(int) * queriesSize);
    *returnSize = 0;

    for(int i = 0; i < queriesSize; i++) {
        int q_type = queries[i][0];
        int x = queries[i][1];

        if(q_type == 2) {
            offline[x] = true;
        } else {
            if(!offline[x]) {
                results[(*returnSize)++] = x;
            } else {
                int root = find(x, parent);
                int ptr = component_ptr[root];
                IntArray* members = component_members[root];

                if(members == NULL) {
                    results[(*returnSize)++] = -1;
                    continue;
                }

                while(ptr < members -> size && offline[members -> data[ptr]]) {
                    ptr++;
                }

                component_ptr[root] = ptr;

                if(ptr < members -> size) {
                    results[(*returnSize)++] = members -> data[ptr];
                } else {
                    results[(*returnSize)++] = -1;
                }
            }
        }
    }

    free(parent);
    for(int i = 0; i <= c; i++) {
        if(component_members[i] != NULL) {
            freeIntArray(component_members[i]);
        }
    }

    free(component_members);
    free(offline);
    free(component_ptr);

    return results;
}



