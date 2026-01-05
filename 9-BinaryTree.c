#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node, *BST;

typedef struct {
    BST arr[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}
int isEmptyStack(Stack *s) {
    return s->top == -1;
}
void push(Stack *s, BST n) {
    s->arr[++s->top] = n;
}
BST pop(Stack *s) {
    return s->arr[s->top--];
}

typedef struct {
    BST arr[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}
int isEmptyQueue(Queue *q) {
    return q->front == q->rear;
}
void enqueue(Queue *q, BST n) {
    q->arr[q->rear++] = n;
}
BST dequeue(Queue *q) {
    return q->arr[q->front++];
}

void insert(BST *tree, int val) {
    BST *trav = tree;

    while (*trav != NULL && (*trav)->data != val) {
        trav = (val < (*trav)->data)
               ? &(*trav)->left
               : &(*trav)->right;
    }

    if (*trav == NULL) {
        *trav = (BST)malloc(sizeof(Node));
        (*trav)->data = val;
        (*trav)->left = (*trav)->right = NULL;
    }
}

void delete(BST *tree, int val) {
    BST *trav = tree;

    while (*trav != NULL && (*trav)->data != val) {
        trav = (val < (*trav)->data)
               ? &(*trav)->left
               : &(*trav)->right;
    }

    if (*trav == NULL) return;

    BST del = *trav;

    if (del->left == NULL) {
        *trav = del->right;
        free(del);
    }
    else if (del->right == NULL) {
        *trav = del->left;
        free(del);
    }
    else {
        BST succ = del->right;
        while (succ->left != NULL)
            succ = succ->left;

        del->data = succ->data;
        delete(&del->right, succ->data);
    }
}

void preorder(BST tree) {
    if (tree == NULL) return;
    printf("%d ", tree->data);
    preorder(tree->left);
    preorder(tree->right);
}

void inorder(BST tree) {
    if (tree == NULL) return;
    inorder(tree->left);
    printf("%d ", tree->data);
    inorder(tree->right);
}

void postorder(BST tree) {
    if (tree == NULL) return;
    postorder(tree->left);
    postorder(tree->right);
    printf("%d ", tree->data);
}

void iterativePreorder(BST tree) {
    if (tree == NULL) return;

    Stack s;
    initStack(&s);
    push(&s, tree);

    while (!isEmptyStack(&s)) {
        BST curr = pop(&s);
        printf("%d ", curr->data);

        if (curr->right) push(&s, curr->right);
        if (curr->left)  push(&s, curr->left);
    }
}

void bfs(BST tree) {
    if (tree == NULL) return;

    Queue q;
    initQueue(&q);
    enqueue(&q, tree);

    while (!isEmptyQueue(&q)) {
        BST curr = dequeue(&q);
        printf("%d ", curr->data);

        if (curr->left)  enqueue(&q, curr->left);
        if (curr->right) enqueue(&q, curr->right);
    }
}
