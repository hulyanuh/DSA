#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct{
    int *elemPtr;
    int count;
    int max;
} List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);
List resize(List L);

int main() {
    List L;
    L = initialize(L);
    
    L = insertPos(L, 10, 0);
    L = insertPos(L, 20, 1);
    L = insertPos(L, 30, 2);
    display(L);
    
    L = deletePos(L, 1);
    display(L);
    
    printf("Locate 30: %d\n", locate(L, 30));
    
    L = insertSorted(L, 15);
    L = insertSorted(L, 25);
    display(L);
    
    free(L.elemPtr);
    return 0;
}

List initialize(List L){
    L.elemPtr = (int*)malloc(LENGTH * sizeof(int));
    L.max = LENGTH;
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    if(position >= 0 && position <= L.count){
        if(L.count == L.max) L = resize(L);
        for(int i = L.count; i > position; i--){
            L.elemPtr[i] = L.elemPtr[i - 1];
        }
        L.elemPtr[position] = data;
        L.count++;
    }
    return L;
}

List deletePos(List L, int position){
    if(position >= 0 && position < L.count){
        for(int i = position; i <L.count - 1; i++){
            L.elemPtr[i] = L.elemPtr[i + 1];
        }
        L.count--;
    }
    return L;
}

int locate(List L, int data){
    for(int i = 0; i < L.count; i++){
        if(L.elemPtr[i] == data) return i;
    }
    return -1;
}

List insertSorted(List L, int data){
    if(L.count == L.max) L = resize(L);
    int i = L.count - 1;
    while(i >= 0 && L.elemPtr[i] > data){
        L.elemPtr[i + 1] = L.elemPtr[i];
        i--;
    }
    L.elemPtr[i + 1] = data;
    L.count++;
    return L;
}

void display(List L){
    for(int i = 0; i < L.count; i++){
        printf("%d ", L.elemPtr[i]);
    }
    printf("\n");
}

List resize(List L){
    L.max *= 2;
    L.elemPtr = (int*)realloc(L.elemPtr, L.max * sizeof(int));
    return L;
}