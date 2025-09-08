#include <stdio.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
} List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);

int main() {
    List L;
    L = initialize(L);
    
    L = insertPos(L, 10, 0);
    L = insertPos(L, 20, 1);
    L = insertPos(L, 30, 1);
    display(L);
    
    L = deletePos(L, 1);
    display(L);
    
    printf("Locate 30: %d\n", locate(L, 30));
    
    L = insertSorted(L, 15);
    L = insertSorted(L, 25);
    display(L);
    
    return 0;
}

List initialize(List L){
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    if(L.count < MAX && position >= 0 && position <= L.count){
        for(int i = L.count; i > position; i--){
            L.elem[i] = L.elem[i - 1];
        }
        L.elem[position] = data;
        L.count++;
    }
    return L;
}

List deletePos(List L, int position){
    if(position >= 0 && position < L.count){
        for(int i = position; i < L.count - 1; i++){
            L.elem[i] = L.elem[i + 1];
        }
        L.count--;
    }
    return L;
}

int locate(List L, int data){
    for(int i = 0; i < L.count; i++){
        if(L.elem[i] == data) return i;
    }
    return -1;
}

List insertSorted(List L, int data){
    if(L.count < MAX){
        int i = L.count - 1;
        while(i >= 0 && L.elem[i] > data){
            L.elem[i + 1] = L.elem[i];
            i--;
        }
        L.elem[i + 1] = data;
        L.count++;
    }
    return L;
}

void display(List L){
    for(int i = 0; i < L.count; i++){
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}