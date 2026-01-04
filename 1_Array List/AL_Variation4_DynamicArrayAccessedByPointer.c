#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct{
    int *elemPtr;
    int count;
    int max;
} List;

void initialize(List *L);
void insertPos(List *L, int data, int position);
void deletePos(List *L, int position);
int locate(List *L, int data);
int retrieve(List *L, int position);
void insertSorted(List *L, int data);
void display(List *L);
void resize(List *L);
void makeNULL(List *L);

int main() {
    List L;
    initialize(&L);
    
    insertPos(&L, 10, 0);
    insertPos(&L, 20, 1);
    insertPos(&L, 30, 2);
    display(&L);
    
    deletePos(&L, 1);
    display(&L);
    
    printf("Locate 30: %d\n", locate(&L, 30));
    printf("Retrieve pos 1: %d\n", retrieve(&L, 1));
    
    insertSorted(&L, 15);
    insertSorted(&L, 25);
    display(&L);
    
    makeNULL(&L);
    return 0;
}

void initialize(List *L){
    L->elemPtr = (int*)malloc(LENGTH * sizeof(int));
    L->max = LENGTH;
    L->count = 0;
}

void insertPos(List *L, int data, int position){
    if(position >= 0 && position <= L->count){
        if(L->count == L->max) resize(L);
        for(int i = L->count; i > position; i--){
            L->elemPtr[i] = L->elemPtr[i - 1];
        }
        L->elemPtr[position] = data;
        L->count++;
    }
}

void deletePos(List *L, int position){
    if(position >= 0 && position < L->count){
        for(int i = position; i < L->count - 1; i++){
            L->elemPtr[i] = L->elemPtr[i + 1];
        }
        L->count--;
    }
}

int locate(List *L, int data){
    for(int i = 0; i < L->count; i++){
        if(L->elemPtr[i] == data) return i;
    }
    return -1;
}

int retrieve(List *L, int position){
    return(position >= 0 && position < L->count) ? L->elemPtr[position] : -1;
}

void insertSorted(List *L, int data){
    if(L->count == L->max) resize(L);
    
    int i = L->count - 1;
    while(i >= 0 && L->elemPtr[i] > data){
        L->elemPtr[i + 1] = L->elemPtr[i];
        i--;
    }
    L->elemPtr[i + 1] = data;
    L->count++;
}

void display(List *L){
    for(int i = 0; i < L->count; i++){
        printf("%d ", L->elemPtr[i]);
    }
    printf("\n");
}

void resize(List *L){
    L->max *= 2;
    L->elemPtr = (int*)realloc(L->elemPtr, L->max * sizeof(int));
}

void makeNULL(List *L){
    free(L->elemPtr);
    L->elemPtr = NULL;
    L->count = 0;
    L->max = 0;
}