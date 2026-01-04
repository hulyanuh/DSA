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
void deallocSpace(VHeap *V, Index index);
void insertFirst(Index *L, VHeap *V, int elem);
void insertLast(Index *L, VHeap *V, int elem);
void insertSorted(Index *L, VHeap *V, int elem);
void deleteElem(Index *L, VHeap *V, int elem);
void display(Index L, VHeap V);

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

void deallocSpace(VHeap *V, Index index) {
    V->heap[index].next = V->avail;
    V->avail = index;
}

void insertFirst(Index *L, VHeap *V, int elem) {
    Index newCell = allocSpace(V);
    if (newCell != NULL_INDEX) {
        V->heap[newCell].elem = elem;
        V->heap[newCell].next = *L;
        *L = newCell;
    }
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

void insertSorted(Index *L, VHeap *V, int elem) {
    Index newCell = allocSpace(V);
    if (newCell != NULL_INDEX) {
        V->heap[newCell].elem = elem;

        if (*L == NULL_INDEX || elem < V->heap[*L].elem) {
            V->heap[newCell].next = *L;
            *L = newCell;
        } else {
            Index trav = *L;
            while (V->heap[trav].next != NULL_INDEX &&
                   V->heap[V->heap[trav].next].elem < elem) {
                trav = V->heap[trav].next;
            }
            V->heap[newCell].next = V->heap[trav].next;
            V->heap[trav].next = newCell;
        }
    }
}

void deleteElem(Index *L, VHeap *V, int elem) {
    Index *trav = L;

    while (*trav != NULL_INDEX && V->heap[*trav].elem != elem) {
        trav = &V->heap[*trav].next;
    }

    if (*trav != NULL_INDEX) {
        Index temp = *trav;
        *trav = V->heap[temp].next;
        deallocSpace(V, temp);
    }
}

void display(Index L, VHeap V) {
    while (L != NULL_INDEX) {
        printf("%d -> ", V.heap[L].elem);
        L = V.heap[L].next;
    }
    printf("NULL\n");
}

int main() {
    VHeap V;
    Index L = NULL_INDEX;

    initialize(&V);

    insertFirst(&L, &V, 10);
    insertFirst(&L, &V, 5);
    insertLast(&L, &V, 20);
    insertSorted(&L, &V, 15);

    printf("Cursor-Based List (Variation 1):\n");
    display(L, V);

    deleteElem(&L, &V, 15);
    printf("\nAfter Deleting 15:\n");
    display(L, V);

    return 0;
}