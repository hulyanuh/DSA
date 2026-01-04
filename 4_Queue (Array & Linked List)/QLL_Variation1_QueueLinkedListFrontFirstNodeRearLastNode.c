#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* initialize() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool isFull(Queue* q) {
    return false;
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

/*
   Enqueue Steps:
   1. Allocate new node
   2. Set data and next to NULL
   3. If empty, set front and rear
   4. Else link rear to new node
   5. Update rear
*/
bool enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return false;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    return true;
}

/*
   Dequeue Steps:
   1. Check if empty
   2. Store front node
   3. Retrieve data
   4. Move front pointer
   5. Update rear if queue becomes empty
   6. Free old front
*/
bool dequeue(Queue* q, int* removedValue) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return false;
    }

    Node* temp = q->front;
    *removedValue = temp->data;
    q->front = temp->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return true;
}

bool front(Queue* q, int* frontValue) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return false;
    }

    *frontValue = q->front->data;
    return true;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    Node* temp = q->front;
    printf("Queue contents (front to rear): ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* Q = initialize();

    enqueue(Q, 1);
    enqueue(Q, 3);
    enqueue(Q, 5);
    enqueue(Q, 4);

    display(Q);

    int value;
    dequeue(Q, &value);
    printf("Dequeued: %d\n", value);

    display(Q);

    free(Q);
    return 0;
}