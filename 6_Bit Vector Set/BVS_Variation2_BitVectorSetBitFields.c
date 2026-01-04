#include <stdio.h>
#include <stdbool.h>

#define MAX_BITS 8

typedef struct {
    unsigned int field : 8;
} Set;

void initialize(Set *set) {
    set->field = 0;
}

void insert(Set *set, int element) {
    if (element >= 0 && element < MAX_BITS) {
        set->field |= (1 << element);
    }
}

void delete(Set *set, int element) {
    if (element >= 0 && element < MAX_BITS) {
        set->field &= ~(1 << element);
    }
}

bool find(Set set, int element) {
    if (element >= 0 && element < MAX_BITS) {
        return (set.field & (1 << element)) != 0;
    }
    return false;
}

Set setUnion(Set A, Set B) {
    Set C;
    C.field = A.field | B.field;
    return C;
}

Set intersection(Set A, Set B) {
    Set C;
    C.field = A.field & B.field;
    return C;
}

Set difference(Set A, Set B) {
    Set C;
    C.field = A.field & (~B.field);
    return C;
}

void display(Set set) {
    printf("{ ");
    for (int i = 0; i < MAX_BITS; i++) {
        if (set.field & (1 << i)) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}

int main() {
    Set A, B, C;

    initialize(&A);
    initialize(&B);

    insert(&A, 0);
    insert(&A, 4);
    insert(&A, 5);

    insert(&B, 2);
    insert(&B, 5);

    printf("Set A: "); display(A);
    printf("Set B: "); display(B);

    C = setUnion(A, B);
    printf("Union: "); display(C);

    C = intersection(A, B);
    printf("Intersection: "); display(C);

    C = difference(A, B);
    printf("Difference A - B: "); display(C);

    return 0;
}