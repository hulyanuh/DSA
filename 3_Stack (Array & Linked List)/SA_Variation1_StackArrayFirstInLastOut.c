#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];   // static array for stack storage
    int top;          // index of the top element
} Stack;

Stack* initialize() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

bool isFull(Stack* s) {
    return s->top == MAX - 1;
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

/*
   Push Operation Steps:
   1. Check if stack is full
   2. Increment top
   3. Insert value at items[top]
*/
bool push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return false;
    }
    s->top++;
    s->items[s->top] = value;
    return true;
}

/*
   Pop Operation Steps:
   1. Check if stack is empty
   2. Retrieve value at items[top]
   3. Decrement top
   4. Return value
*/
bool pop(Stack* s, int* poppedValue) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return false;
    }
    *poppedValue = s->items[s->top];
    s->top--;
    return true;
}

// Peek Operation: Returns the value at the top without removing it

bool peek(Stack* s, int* topValue) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return false;
    }
    *topValue = s->items[s->top];
    return true;
}

int top(Stack* s) {
    return s->top;
}

void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack contents (top to bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main() {
    Stack* S = initialize();

    push(S, 1);
    push(S, 3);
    push(S, 2);
    push(S, 5);

    display(S);

    int value;
    pop(S, &value);
    printf("Popped: %d\n", value);

    display(S);

    free(S);
    return 0;
}