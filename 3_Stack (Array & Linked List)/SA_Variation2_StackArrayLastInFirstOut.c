#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int top;
} Stack;

Stack* initialize() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = MAX;
    return s;
}

bool isFull(Stack* s) {
    return s->top == 0;
}

bool isEmpty(Stack* s) {
    return s->top == MAX;
}

/*
   Push operation:
   1. Decrement top
   2. Insert value
*/
bool push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return false;
    }
    s->top--;
    s->items[s->top] = value;
    return true;
}

/*
   Pop operation:
   1. Retrieve value
   2. Increment top
*/
bool pop(Stack* s, int* poppedValue) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return false;
    }
    *poppedValue = s->items[s->top];
    s->top++;
    return true;
}

bool peek(Stack* s, int* topValue) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return false;
    }
    *topValue = s->items[s->top];
    return true;
}

void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack contents (top to bottom): ");
    for (int i = s->top; i < MAX; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main() {
    Stack* S = initialize();

    push(S, 10);
    push(S, 20);
    push(S, 30);

    display(S);

    int value;
    pop(S, &value);
    printf("Popped: %d\n", value);

    display(S);

    free(S);
    return 0;
}