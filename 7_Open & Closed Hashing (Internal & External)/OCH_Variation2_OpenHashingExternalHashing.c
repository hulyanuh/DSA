#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct Node {
    int key;
    struct Node *next;
} Node;

typedef struct {
    Node *table[MAX];
} HashTable;

int hash(int key) {
    return key % MAX;
}

void initialize(HashTable *ht) {
    for (int i = 0; i < MAX; i++)
        ht->table[i] = NULL;
}

void insert(HashTable *ht, int key) {
    int idx = hash(key);
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = ht->table[idx];
    ht->table[idx] = newNode;
}

bool delete(HashTable *ht, int key) {
    int idx = hash(key);
    Node *curr = ht->table[idx], *prev = NULL;

    while (curr != NULL) {
        if (curr->key == key) {
            if (prev == NULL) ht->table[idx] = curr->next;
            else prev->next = curr->next;
            free(curr);
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

bool find(HashTable *ht, int key) {
    int idx = hash(key);
    Node *curr = ht->table[idx];
    while (curr != NULL) {
        if (curr->key == key) return true;
        curr = curr->next;
    }
    return false;
}

void display(HashTable ht) {
    for (int i = 0; i < MAX; i++) {
        printf("[%d] -> ", i);
        Node *curr = ht.table[i];
        while (curr != NULL) {
            printf("%d -> ", curr->key);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

int main() {
    HashTable ht;
    initialize(&ht);

    insert(&ht, 5);
    insert(&ht, 15);
    insert(&ht, 25);
    insert(&ht, 3);

    printf("Hash Table (Open Hashing / Chaining):\n");
    display(ht);

    delete(&ht, 15);
    printf("\nAfter deleting 15:\n");
    display(ht);

    printf("\nFind 25: %s\n", find(&ht, 25) ? "Found" : "Not Found");

    return 0;
}