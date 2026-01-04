#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;   // points to last node
    Node* rear;    // points to first node
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
    return q->rear == NULL;
}

/*
   Enqueue Steps:
   1. Allocate new node
   2. Set data and next
   3. If empty, set front and rear
   4. Else insert at beginning
*/
bool enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return false;
    }

    newNode->data = value;
    newNode->next = q->rear;

    if (isEmpty(q)) {
        q->rear = newNode;
        q->front = newNode;
    } else {
        q->rear = newNode;
    }

    return true;
}

/*
   Dequeue Steps:
   1. Check if empty
   2. Traverse to node before front
   3. Retrieve front data
   4. Update front pointer
   5. Free old front node
*/
bool dequeue(Queue* q, int* removedValue) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return false;
    }

    Node* temp = q->rear;
    Node* prev = NULL;

    while (temp->next != q->front) {
        temp = temp->next;
    }

    prev = temp;
    *removedValue = q->front->data;

    if (q->rear == q->front) {
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    } else {
        free(q->front);
        q->front = prev;
        q->front->next = NULL;
    }

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

    Node* temp = q->rear;
    printf("Queue contents (rear to front): ");

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