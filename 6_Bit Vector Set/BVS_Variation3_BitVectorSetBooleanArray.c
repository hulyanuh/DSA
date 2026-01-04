#include <stdio.h>
#include <stdbool.h>

#define MAX_ELEMENTS 8

typedef bool Set[MAX_ELEMENTS];

void initialize(Set set) {
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        set[i] = false;
    }
}

void insert(Set set, int element) {
    if (element >= 0 && element < MAX_ELEMENTS) {
        set[element] = true;
    }
}

void delete(Set set, int element) {
    if (element >= 0 && element < MAX_ELEMENTS) {
        set[element] = false;
    }
}

bool find(Set set, int element) {
    if (element >= 0 && element < MAX_ELEMENTS) {
        return set[element];
    }
    return false;
}

void setUnion(Set A, Set B, Set C) {
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        C[i] = A[i] || B[i];
    }
}

void intersection(Set A, Set B, Set C) {
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        C[i] = A[i] && B[i];
    }
}

void difference(Set A, Set B, Set C) {
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        C[i] = A[i] && !B[i];
    }
}

void display(Set set) {
    printf("{ ");
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (set[i]) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}

int main() {
    Set A, B, C;

    initialize(A);
    initialize(B);

    insert(A, 0);
    insert(A, 2);
    insert(A, 7);

    insert(B, 2);
    insert(B, 4);
    insert(B, 5);

    printf("Set A: "); display(A);
    printf("Set B: "); display(B);

    setUnion(A, B, C);
    printf("Union: "); display(C);

    intersection(A, B, C);
    printf("Intersection: "); display(C);

    difference(A, B, C);
    printf("Difference A - B: "); display(C);

    return 0;
}