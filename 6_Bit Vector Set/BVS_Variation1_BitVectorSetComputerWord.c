#include <stdio.h>
#include <stdbool.h>

#define MAX_BITS 8

void initialize(unsigned char *set) {
    *set = 0;
}

void insert(unsigned char *set, int element) {
    if (element >= 0 && element < MAX_BITS) {
        *set |= (1 << element);
    }
}

void delete(unsigned char *set, int element) {
    if (element >= 0 && element < MAX_BITS) {
        *set &= ~(1 << element);
    }
}

bool find(unsigned char set, int element) {
    if (element >= 0 && element < MAX_BITS) {
        return (set & (1 << element)) != 0;
    }
    return false;
}

unsigned char setUnion(unsigned char A, unsigned char B) {
    return A | B;
}

unsigned char intersection(unsigned char A, unsigned char B) {
    return A & B;
}

unsigned char difference(unsigned char A, unsigned char B) {
    return A & (~B);
}

void display(unsigned char set) {
    printf("{ ");
    for (int i = 0; i < MAX_BITS; i++) {
        if (set & (1 << i)) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}

int main() {
    unsigned char A, B;

    initialize(&A);
    initialize(&B);

    insert(&A, 1);
    insert(&A, 6);

    insert(&B, 3);
    insert(&B, 6);
    insert(&B, 7);

    printf("Set A: "); display(A);
    printf("Set B: "); display(B);

    printf("Union: "); display(setUnion(A, B));
    printf("Intersection: "); display(intersection(A, B));
    printf("Difference A - B: "); display(difference(A, B));

    return 0;
}