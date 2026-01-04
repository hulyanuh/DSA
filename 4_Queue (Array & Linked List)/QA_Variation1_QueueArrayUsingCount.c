#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int front;
    int rear;
    int count;
} Queue;

Queue* initialize() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->count = 0;
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isFull(Queue* q) {
    return q->count == MAX;
}

bool isEmpty(Queue* q) {
    return q->count == 0;
}

/*
   Enqueue Steps:
   1. Check if queue is full
   2. If empty, set front and rear to 0
   3. Else move rear circularly
   4. Insert value
   5. Increment count
*/
bool enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow!\n");
        return false;
    }

    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }

    q->items[q->rear] = value;
    q->count++;
    return true;
}

/*
   Dequeue Steps:
   1. Check if queue is empty
   2. Store front value
   3. If last element, reset queue
   4. Else move front circularly
   5. Decrement count
*/
bool dequeue(Queue* q, int* removedValue) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return false;
    }

    *removedValue = q->items[q->front];

    if (q->count == 1) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }

    q->count--;
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
    int index = q->front;

    for (int i = 0; i < q->count; i++) {
        printf("%d ", q->items[index]);
        index = (index + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Queue* Q = initialize();

    enqueue(Q, 1);
    enqueue(Q, 3);
    enqueue(Q, 2);
    enqueue(Q, 5);

    display(Q);

    int value;
    dequeue(Q, &value);
    printf("Dequeued: %d\n", value);

    display(Q);

    free(Q);
    return 0;
}