#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int priorities[MAX];
    int size;
} PriorityQueue;

PriorityQueue* initialize() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->size = 0;
    return pq;
}

bool isFull(PriorityQueue* pq) {
    return pq->size == MAX;
}

bool isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

// Enqueue: Insert element based on priority (higher value = higher priority)
bool enqueue(PriorityQueue* pq, int value, int priority) {
    if (isFull(pq)) {
        printf("Priority Queue Overflow!\n");
        return false;
    }
    int i = pq->size - 1;
    // Shift elements with lower priority to the right
    while (i >= 0 && pq->priorities[i] < priority) {
        pq->items[i + 1] = pq->items[i];
        pq->priorities[i + 1] = pq->priorities[i];
        i--;
    }
    pq->items[i + 1] = value;
    pq->priorities[i + 1] = priority;
    pq->size++;
    return true;
}

// Dequeue: Remove element with highest priority (front of array)
bool dequeue(PriorityQueue* pq, int* value) {
    if (isEmpty(pq)) {
        printf("Priority Queue Underflow!\n");
        return false;
    }
    *value = pq->items[0];
    for (int i = 1; i < pq->size; i++) {
        pq->items[i - 1] = pq->items[i];
        pq->priorities[i - 1] = pq->priorities[i];
    }
    pq->size--;
    return true;
}

void display(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty!\n");
        return;
    }
    printf("Element | Priority\n");
    for (int i = 0; i < pq->size; i++)
        printf("   %d    |   %d\n", pq->items[i], pq->priorities[i]);
}

int main() {
    PriorityQueue* pq = initialize();

    enqueue(pq, 10, 2);
    enqueue(pq, 20, 1);
    enqueue(pq, 30, 3);

    printf("Priority Queue:\n");
    display(pq);

    int val;
    dequeue(pq, &val);
    printf("\nDequeued: %d\n", val);

    printf("\nPriority Queue after dequeue:\n");
    display(pq);

    free(pq);
    return 0;
}