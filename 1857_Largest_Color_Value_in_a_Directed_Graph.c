#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct Queue {
    int *data;
    int front, rear, size;
} Queue;

Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->data = (int *)malloc(capacity * sizeof(int));
    queue->front = queue->rear = 0;
    queue->size = capacity;
    return queue;
}

void enqueue(Queue *queue, int item) {
    queue->data[queue->rear++] = item;
}

int dequeue(Queue *queue) {
    return queue->data[queue->front++];
}

int isEmpty(Queue *queue) {
    return queue->front == queue->rear;
}

void freeQueue(Queue *queue) {
    free(queue->data);
    free(queue);
}

int largestPathValue(const char *colors, int **edges, int edgesSize, int *edgesColSize) {
    int ans = 0, processed = 0;
    int n = strlen(colors);
    int *inDegrees = (int *)calloc(n, sizeof(int));
    int **count = (int **)malloc(n * sizeof(int *));
    Queue *q = createQueue(n);

    // Allocate adjacency list
    int **graph = (int **)malloc(n * sizeof(int *));
    int *graphSize = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        inDegrees[v]++;
        graphSize[u]++;
    }

    // Convert adjacency matrix to adjacency list
    for (int i = 0; i < n; i++) {
        graph[i] = (int *)malloc(graphSize[i] * sizeof(int));
        graphSize[i] = 0;
    }

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        graph[u][graphSize[u]++] = v;
    }

    // Allocate count arrays lazily
    for (int i = 0; i < n; i++)
        count[i] = (int *)calloc(ALPHABET_SIZE, sizeof(int));

    for (int i = 0; i < n; i++)
        if (inDegrees[i] == 0)
            enqueue(q, i);

    while (!isEmpty(q)) {
        int out = dequeue(q);
        processed++;
        ans = (count[out][colors[out] - 'a'] += 1) > ans ? count[out][colors[out] - 'a'] : ans;

        for (int j = 0; j < graphSize[out]; j++) {
            int in = graph[out][j];
            for (int k = 0; k < ALPHABET_SIZE; k++)
                count[in][k] = count[in][k] > count[out][k] ? count[in][k] : count[out][k];
            if (--inDegrees[in] == 0)
                enqueue(q, in);
        }
    }

    for (int i = 0; i < n; i++) {
        free(graph[i]);
        free(count[i]);
    }

    free(graph);
    free(count);
    free(inDegrees);
    free(graphSize);
    freeQueue(q);

    return processed == n ? ans : -1;
}
