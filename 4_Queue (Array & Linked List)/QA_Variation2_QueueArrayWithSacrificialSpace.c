#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

Queue* initialize() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 1;
    q->rear = 0;
    return q;
}

bool isEmpty(Queue* q) {
    return q->front == (q->rear + 1) % MAX;
}

bool isFull(Queue* q) {
    return q->front == (q->rear + 2) % MAX;
}

/*
   Enqueue Steps:
   1. Check if queue is full
   2. Move rear circularly
   3. Insert value
*/
bool enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow!\n");
        return false;
    }

    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    return true;
}

/*
   Dequeue Steps:
   1. Check if queue is empty
   2. Retrieve front value
   3. Move front circularly
*/
bool dequeue(Queue* q, int* removedValue) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return false;
    }

    *removedValue = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    return true;
}

bool front(Queue* q, int* frontValue) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return false;
    }

    *frontValue = q->items[q->front];
    return true;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue contents (front to rear): ");
    int i = q->front;

    while (i != (q->rear + 1) % MAX) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Queue* Q = initialize();

    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);

    display(Q);

    int value;
    dequeue(Q, &value);
    printf("Dequeued: %d\n", value);

    display(Q);

    free(Q);
    return 0;
}