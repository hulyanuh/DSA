#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
#define EMPTY -1
#define DELETED -2

typedef struct {
    int table[MAX];
} HashTable;

void initialize(HashTable *ht) {
    for (int i = 0; i < MAX; i++)
        ht->table[i] = EMPTY;
}

int hash(int key) {
    return key % MAX;
}

bool insert(HashTable *ht, int key) {
    int idx = hash(key);
    int start = idx;

    while (ht->table[idx] != EMPTY && ht->table[idx] != DELETED) {
        idx = (idx + 1) % MAX; // linear probing
        if (idx == start) return false; // full table
    }

    ht->table[idx] = key;
    return true;
}

bool delete(HashTable *ht, int key) {
    int idx = hash(key);
    int start = idx;

    while (ht->table[idx] != EMPTY) {
        if (ht->table[idx] == key) {
            ht->table[idx] = DELETED;
            return true;
        }
        idx = (idx + 1) % MAX;
        if (idx == start) break;
    }
    return false;
}

bool find(HashTable *ht, int key) {
    int idx = hash(key);
    int start = idx;

    while (ht->table[idx] != EMPTY) {
        if (ht->table[idx] == key) return true;
        idx = (idx + 1) % MAX;
        if (idx == start) break;
    }
    return false;
}

void display(HashTable ht) {
    for (int i = 0; i < MAX; i++) {
        if (ht.table[i] == EMPTY) printf("[%d] EMPTY\n", i);
        else if (ht.table[i] == DELETED) printf("[%d] DELETED\n", i);
        else printf("[%d] %d\n", i, ht.table[i]);
    }
}

int main() {
    HashTable ht;
    initialize(&ht);

    insert(&ht, 5);
    insert(&ht, 15);
    insert(&ht, 25);

    printf("Hash Table (Closed Hashing / Linear Probing):\n");
    display(ht);

    delete(&ht, 15);
    printf("\nAfter deleting 15:\n");
    display(ht);

    printf("\nFind 25: %s\n", find(&ht, 25) ? "Found" : "Not Found");

    return 0;
}