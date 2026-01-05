// ARRAY QUEUE - Variation 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
	int items[MAX];
	int count;
}List;

typedef struct{
	List list;
	int front;
	int rear;
}Queue

Queue* initialize(){
	Queue *Q = (Queue*)malloc(sizeof(Queue));
	Q->list.count = 0;
	Q->front = -1;
	Q->rear = -1;
	return Q;
}

bool isFull(Queue* Q){
	return Q->list.count == MAX;
}

bool isEmpty(Queue* Q){
	return Q->list.count == 0;
}

void enqueue(Queue* Q, int value){
	if(isFull(Q)){
		return;
	}
	
	if(isEmpty(Q)){
		Q->front = 0;
		Q->rear = 0;
	}
	else {
		Q->rear = (Q->rear+1)%MAX;
	}
	
	Q->list.items[Q->rear] = value;
	Q->list.count++;
}

int dequeue(Queue* Q){
	if(isEmpty(Q)){
		return;
	}
	else{
		int val = Q->list.items[Q->front];
		if(Q->list.count == 1){
			Q->front = -1;
			Q->rear = -1;
		}
		else if(Q->list.count > 1){
			Q->front = (Q->front+1)%MAX;
		}
		Q->list.count--;
		return val;
	}
}

int front(Queue* Q){
	if(!isEmpty(Q)){
		return Q->list.items[Q->front];
	}
}

void display(Queue* Q){
	if(isEmpty(Q)){
		printf("Queue is empty.");
		return;
	}
	
	int i;
	for(i=Q->front; i != ((Q->rear+1)%MAX); i = (i+1)%MAX){
		printf("%d ", Q->list.items[i]);
	}
}





// ARRAY QUEUE - Variation 2
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
    int items[MAX];
}List;

typedef struct{
    List list;
    int front;
    int rear;
}Queue;

Queue* initialize(){
    Queue Q = (Queue)malloc(sizeof(Queue));
    Q->front = 1;
    Q->rear = 0;
    return Q;
}

bool isFull(Queue* Q){
    return Q->front == (Q->rear + 2) % MAX;
}

bool isEmpty(Queue* Q){
    return Q->front == (Q->rear + 1) % MAX;
}

void enqueue(Queue* Q, int value){
    if(isFull(Q)){
        return;
    }
    
    if(isEmpty(Q)){
        Q->front = 1;
        Q->rear = 1;
    }
    else {
        Q->rear = (Q->rear+1)%MAX;
    }
    
    Q->list.items[Q->rear] = value;
}

int dequeue(Queue* Q){
    if(isEmpty(Q)){
        return -1;
    }
    else{
        int val = Q->list.items[Q->front];
        if(Q->front == Q->rear){
            Q->front = 1;
            Q->rear = 0;
        }
        else{
            Q->front = (Q->front+1)%MAX;
        }
        return val;
    }
}

int front(Queue* Q){
    if(!isEmpty(Q)){
        return Q->list.items[Q->front];
    }
}

void display(Queue* Q){
    if(isEmpty(Q)){
        printf("Queue is empty.");
        return;
    }
    
    int i;
    for(i=Q->front; i != ((Q->rear+1)%MAX); i = (i+1)%MAX){
        printf("%d ", Q->list.items[i]);
    }
}

// LL QUEUE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct{
    Node* front;
    Node* rear;
} Queue;

Queue* initialize(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    
    return q;
}

Node* alloc(){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    return newNode;
}

bool isEmpty(Queue* q){
    return q->front == NULL;
}

void enqueue(Queue* q, int data){
    Node* newNode = alloc();
    newNode->data = data;
    
    if(isEmpty(q)){
        q->front = newNode;
    }
    else{
        q->rear->next = newNode;
    }
    q->rear = newNode;
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        return -1;
    }
    
    Node* temp = q->front;
    int val = q->front->data;
    if(q->rear == q->front){
        q->rear = NULL;
        q->front = NULL;
    }
    else{
        q->front = q->front->next;
    }
    free(temp);
    return val;
}

void display(Queue* q){
    if(isEmpty(q)){
        printf("Empty.");
        return;
    }
    
    Node* trav = q->front;
    while(trav != NULL){
        printf("%d ", trav->data);
        trav = trav->next;
    }
}
