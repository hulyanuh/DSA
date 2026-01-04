#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;   // pointer to the top node
} Stack;

Stack* initialize() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

bool isFull(Stack* s) {
    return false;   // linked list stack is never full
}

bool isEmpty(Stack* s) {
    return s->top == NULL;
}

/*
   Push Operation Steps:
   1. Allocate memory for new node
   2. Set node data
   3. Link node to current top
   4. Update top pointer
*/
bool push(Stack* s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return false;
    }

    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;

    return true;
}

/*
   Pop Operation Steps:
   1. Check if stack is empty
   2. Store top node in temp
   3. Retrieve data
   4. Move top pointer
   5. Free old top node
*/
bool pop(Stack* s, int* poppedValue) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return false;
    }

    Node* temp = s->top;
    *poppedValue = temp->data;
    s->top = temp->next;
    free(temp);

    return true;
}

// Peek Operation: Returns the value at the top without removing it

bool peek(Stack* s, int* topValue) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return false;
    }

    *topValue = s->top->data;
    return true;
}

void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }

    Node* temp = s->top;
    printf("Stack contents (top to bottom): ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack* S = initialize();

    push(S, 1);
    push(S, 3);
    push(S, 5);
    push(S, 4);

    display(S);

    int value;
    pop(S, &value);
    printf("Popped: %d\n", value);

    display(S);

    free(S);
    return 0;
}