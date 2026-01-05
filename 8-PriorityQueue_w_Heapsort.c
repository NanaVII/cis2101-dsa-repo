#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10


typedef struct{
    int pqArr[MAX]; 
    int size; 
    int capacity; 
}PriorityQueue; 

void initPQ(PriorityQueue * pq){
    pq->size = 0; 
    pq->capacity = MAX; 
    printf("----- Initializing Heap -----\n\n"); 
}
void insert(PriorityQueue * pq, int val){
    if(pq->size != MAX){
            pq->pqArr[pq->size++] = val; 
            for(int i = pq->size/2-1; i>=0 ; i--){
                heapify(pq, pq->size, i); 
            }
            printf("Inserted value %d successfully\n", val);
        }
}

int extractRoot(PriorityQueue * pq){
    int val; 
    if(pq->size != 0 ){
        val = pq->pqArr[0]; 
        swap(&pq->pqArr[0], &pq->pqArr[--pq->size]); 
        heapify(pq, pq->size, 0); 
        printf("Deleted value %d successfully\n", val); 
    }
    return val; 
}

void heapify(PriorityQueue * pq, int size, int index){
    int largest = index; 
    int left = (index * 2) + 1; 
    int right = (index * 2) + 2;
    if(left < size && pq->pqArr[left] > pq->pqArr[largest]){
        largest = left; 
    }
    if(right < size && pq->pqArr[right] > pq->pqArr[largest]){
        largest = right; 
    }
    if(largest != index){
        swap(&pq->pqArr[largest], &pq->pqArr[index]); 
        heapify(pq, size, largest); 
    }
}


void heapsort(PriorityQueue * pq){
    for(int i = pq->size/2 - 1; i >= 0; i--){
        heapify(pq, pq->size, i); 
    }

    for(int i = pq->size - 1; i >= 0; i--){
        swap(&(pq->pqArr[0]), &(pq->pqArr[i])); 
        heapify(pq, i, 0); 
    }
}



void swap(int * a, int * b){
    int temp = *a; 
    *a = *b; 
    *b  = temp; 
}

void printHeap(PriorityQueue * pq){
    printf("Printing Heap\nHeap: ");
    for(int i = 0; i < pq->size; i++){
        printf("%d ", pq->pqArr[i]); 
    }
    printf("\n\n"); 
}
