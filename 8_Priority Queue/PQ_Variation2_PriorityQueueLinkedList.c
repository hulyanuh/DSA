#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

Node* createNode(int data, int priority) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->priority = priority;
    node->next = NULL;
    return node;
}

bool isEmpty(Node* head) {
    return head == NULL;
}


// Enqueue: Insert based on priority (higher number = higher priority)
Node* enqueue(Node* head, int data, int priority) {
    Node* newNode = createNode(data, priority);

    if (!head || priority > head->priority) {
        // Insert at the front if queue is empty or highest priority
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    while (temp->next && temp->next->priority >= priority)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Dequeue: Remove the node at the front (highest priority)
bool dequeue(Node** head, int* value) {
    if (isEmpty(*head)) {
        printf("Priority Queue Underflow!\n");
        return false;
    }
    Node* temp = *head;
    *value = temp->data;
    *head = (*head)->next;
    free(temp);
    return true;
}

void display(Node* head) {
    if (isEmpty(head)) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Data | Priority\n");
    while (head) {
        printf(" %d   |   %d\n", head->data, head->priority);
        head = head->next;
    }
}

int main() {
    Node* pq = NULL;

    pq = enqueue(pq, 10, 2);
    pq = enqueue(pq, 20, 1);
    pq = enqueue(pq, 30, 3);
    pq = enqueue(pq, 25, 2);

    printf("Linked List Priority Queue:\n");
    display(pq);

    int val;
    dequeue(&pq, &val);
    printf("\nDequeued: %d\n", val);

    printf("\nQueue after dequeue:\n");
    display(pq);

    // Free remaining nodes
    while (pq) {
        Node* temp = pq;
        pq = pq->next;
        free(temp);
    }

    return 0;
}