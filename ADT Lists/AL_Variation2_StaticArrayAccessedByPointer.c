#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
} Etype, *EPtr;

void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);

int main() {
    EPtr L = (EPtr)malloc(sizeof(Etype));
    initialize(L);
    
    insertPos(L, 10, 0);
    insertPos(L, 20, 1);
    insertPos(L, 30, 2);
    display(L);
    
    deletePos(L, 1);
    display(L);
    
    printf("Locate 30: %d\n", locate(L, 30));
    printf("Retrieve pos 1: %d\n", retrieve(L, 1));
    
    insertSorted(L, 15);
    insertSorted(L, 25);
    display(L);
    
    makeNULL(L);
    return 0;
}

void initialize(EPtr L){
    L->count = 0;
}

void insertPos(EPtr L, int data, int position){
    if(L->count < MAX && position >= 0 && position <= L-> count){
        for(int i = L->count; i > position; i--){
            L->elem[i] = L->elem[i - 1];
        }
        L->elem[position] = data;
        L->count++;
    }
}

void deletePos(EPtr L, int position){
    if(position >= 0 && position < L->count){
        for(int i = position; i < L->count - 1; i++){
            L->elem[i] = L->elem[i + 1];
        }
        L->count--;
    }
}

int locate(EPtr L, int data){
    for(int i = 0; i < L->count; i++){
        if(L->elem[i] == data) return i;
    }
    return -1;
}

int retrieve(EPtr L, int position){
    return (position >= 0 && position < L->count) ? L->elem[position] : -1;
}

void insertSorted(EPtr L, int data){
    if(L->count < MAX){
        int i = L->count - 1;
        while(i >= 0 &&L->elem[i] > data){
            L->elem[i + 1] = L->elem[i];
            i--;
        }
        L->elem[i + 1] = data;
        L->count++;
    }
}

void display(EPtr L){
    for(int i = 0; i < L->count; i++){
        printf("%d", L->elem[i]);
    }
    printf("\n");
}

void makeNULL(EPtr L){
    free(L);
}