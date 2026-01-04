#include <stdio.h>

#define MAX 10
#define NULL_INDEX -1

typedef int Index;

typedef struct {
    int elem;
    Index next;
} Cell;

typedef struct {
    Cell heap[MAX];
    Index avail;
} VHeap;

void initialize(VHeap *V);
Index allocSpace(VHeap *V);
void insertLast(Index *L, VHeap *V, int elem);
void displayReverse(Index L, VHeap V);

void initialize(VHeap *V) {
    int i;
    V->avail = 0;
    for (i = 0; i < MAX - 1; i++) {
        V->heap[i].next = i + 1;
    }
    V->heap[MAX - 1].next = NULL_INDEX;
}

Index allocSpace(VHeap *V) {
    Index temp = V->avail;
    if (temp != NULL_INDEX) {
        V->avail = V->heap[temp].next;
    }
    return temp;
}

void insertLast(Index *L, VHeap *V, int elem) {
    Index newCell = allocSpace(V);
    if (newCell != NULL_INDEX) {
        V->heap[newCell].elem = elem;
        V->heap[newCell].next = NULL_INDEX;

        if (*L == NULL_INDEX) {
            *L = newCell;
        } else {
            Index trav = *L;
            while (V->heap[trav].next != NULL_INDEX) {
                trav = V->heap[trav].next;
            }
            V->heap[trav].next = newCell;
        }
    }
}

void displayReverse(Index L, VHeap V) {
    if (L != NULL_INDEX) {
        displayReverse(V.heap[L].next, V);
        printf("%d -> ", V.heap[L].elem);
    }
}

int main() {
    VHeap V;
    Index L = NULL_INDEX;

    initialize(&V);

    insertLast(&L, &V, 10);
    insertLast(&L, &V, 20);
    insertLast(&L, &V, 30);
    insertLast(&L, &V, 40);

    printf("Cursor-Based List (Variation 2 - From Last Going Up):\n");
    displayReverse(L, V);
    printf("NULL\n");

    return 0;
}