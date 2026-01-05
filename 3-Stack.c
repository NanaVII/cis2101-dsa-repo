// ARRAY STACK
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int items[MAX];
    int top;
} Stack;

Stack* initialize(){
	Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

bool isFull(Stack *s){
	return s->top == MAX-1;
}

bool isEmpty(Stack *s){
	return s->top == -1;
}

void push(Stack *s, int value){
	if(isFull(s)){
		return;
	}
	s->top++;
	s->items[s->top] = value;
}

int pop(Stack *s){
	if(!isEmpty(s)){
		int val = s->items[s->top];
		s->top--;
		return val;
	}
}

int peek(Stack *s){
	if(!isEmpty(s)){
		return s->items[s->top];
	}
}

int top(Stack *s){
    return s->items[s->top];
}

void display(Stack *s){
	if(!isEmpty(s)){
		int i;
		for(i=s->top; i >= 0; i--){
			printf("\n%d", s->items[i]);
		}
	}
	else{
	    printf("\nStack is empty.");
	}
}





/* ARRAY STACK - Variation 2 (Last In, First Out) */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int items[MAX];
    int top;
} Stack;

Stack* initialize(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = MAX;
    return s;
}

bool isEmpty(Stack* s){ return s->top == MAX; }
bool isFull(Stack* s){ return s->top == 0; }

void push(Stack* s, int value){
    if(isFull(s)) return;
    
    s->top--;
    s->items[s->top] = value;
}

void pop(Stack* s){
    if(isEmpty(s)) return;

    s->top++;
}

int peek(Stack* s){
    if(isEmpty(s)) return -1;
    return s->items[s->top];
}

void display(Stack* s){
    for(int i = s->top; i < MAX; i++)
        printf("%d ", s->items[i]);
}





// LL STACK
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

Stack* initialize(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

bool isEmpty(Stack* s){ 
	return s->top == NULL; 
}

bool isFull(Stack* s){
	return false; 
}

void push(Stack* s, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

void pop(Stack* s){
    if (isEmpty(s)) return -1;
    Node *temp = s->top;
    s->top = temp->next;
    free(temp);
}

int peek(Stack* s){
    if (isEmpty(s)) return -1;
    return s->top->data;
}

void display(Stack* s){
    for(Node* trav = s->top; trav != NULL; trav = trav->next)
        printf("%d ", trav->data);
}
