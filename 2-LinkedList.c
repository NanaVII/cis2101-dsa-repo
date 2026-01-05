// LINKED LIST - Accessed by Pointer
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct{
    Node *head;
    int count;
}List;

List* initialize(){
    List *list = (List *)malloc(sizeof(List));
    if (list == NULL) {
        printf("Allocation failed\n");
        return NULL;
    }
    list->head = NULL;
    list->count = 0;
    return list;
}

void empty(List *list){
    Node *temp;
    while (list->head != NULL) {
        temp = list->head;
        list->head = temp->next;
        free(temp);
    }
    list->count = 0;
}

void insertFirst(List *list, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}

void insertLast(List *list, int data){
    if (list->head == NULL){
        insertFirst(list, data);
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    Node *trav = list->head;
    while (trav->next != NULL)
        trav = trav->next;

    trav->next = newNode;
    list->count++;
}

void insertPos(List *list, int data, int index){
    if (index < 0 || index > list->count)
        return;

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    Node **trav = &list->head;
    for (int i = 0; i < index; i++)
        trav = &(*trav)->next;

    newNode->next = *trav;
    *trav = newNode;
    list->count++;
}

void deleteStart(List *list){
    if (list->head == NULL)
        return;

    Node *temp = list->head;
    list->head = temp->next;
    free(temp);
    list->count--;
}

void deleteLast(List *list){
    if (list->head == NULL)
        return;

    Node **trav = &list->head;
    while ((*trav)->next != NULL)
        trav = &(*trav)->next;

    free(*trav);
    *trav = NULL;
    list->count--;
}

void deletePos(List *list, int index) 
    if (index < 0 || index >= list->count)
        return;

    Node **trav = &list->head;
    for (int i = 0; i < index; i++)
        trav = &(*trav)->next;

    Node *temp = *trav;
    *trav = temp->next;
    free(temp);
    list->count--;
}

int retrieve(List *list, int index){
    if (index < 0 || index >= list->count)
        return -1;

    Node *trav = list->head;
    for (int i = 0; i < index; i++)
        trav = trav->next;

    return trav->data;
}

int locate(List *list, int data){
    int index = 0;
    for (Node *trav = list->head; trav != NULL; trav = trav->next, index++)
        if (trav->data == data)
            return index;
    return -1;
}

void display(List *list){
    if (list->head == NULL){
        printf("List is empty\n");
        return;
    }

    for (Node *trav = list->head; trav != NULL; trav = trav->next)
        printf("%d ", trav->data);
    printf("\n");
}

