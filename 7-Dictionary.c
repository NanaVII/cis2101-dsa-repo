// DICTIONARY - Open Hashing
#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct node{
    int elem; 
    struct node * next; 
}node, *Hash; 

typedef Node* DictionaryLL[SIZE];

void initialize(Hash array[]){
    for(int i = 0; i < MAX; i++){
        array[i] = NULL; 
    }
}

void display(Hash array[]){\
    printf("OPEN HASH\n");
    for(int i = 0; i < MAX; i++){
        printf("Index %d: ", i); 
        node * trav = array[i];

        while(trav != NULL){
            printf("%d -> ", trav->elem);
            trav = trav->next; 
        }

        printf("NULL \n");
    }

    printf("\n\n");
}

void insert(Hash array[], int key){
    int index = hash(key); 

    node * newNode = (node*)calloc(1, sizeof(node)); 
    newNode->elem = key; 

    newNode->next = array[index]; 
    array[index] = newNode; 
}
void delete(Hash array[], int key){
    int index = hash(key);

    node ** trav = &array[index];
    while(*trav != NULL){
        if((*trav)->elem == key) break; 
        trav = &(*trav)->next;
    }

    if(*trav == NULL ) return; 

    node * del = *trav; 
    *trav = (*trav)->next; 
    free(del);
}
int hash(int key){
    int index = ((key + 132 - 10) * 5) % MAX; 
    return index;
}


void deleteAll(Hash array[]){
    for(int i = 0; i < MAX; i++){
        while(array[i] != NULL){
            node * del = array[i]; 
            array[i] = array[i]->next; 
            free(del); 
        }

    }

    printf("Cleaned!\n\n");
} 





// DICTIONARY - Closed Hashing
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAX 20
#define SECONDARY 10

typedef struct{
    char elem[4];
    int next;
}cell, Heapspace[MAX];

typedef struct{
    Heapspace H;
    int avail;
}VHeap;

void initialize(VHeap * V){
    V->avail = SECONDARY;
    for(int i = 0;i < SECONDARY;i++){
        strcpy(V->H[i].elem, "");
        V->H[i].next = -1;
    }

    for(int i = SECONDARY; i < MAX - 1;i++){
        strcpy(V->H[i].elem, "");
        V->H[i].next = i+1;
    }

    strcpy(V->H[MAX - 1].elem, "");
    V->H[MAX - 1].next = -1;
}


int hash(char * elem){
    int hash = ((elem[0] - 'A') * 26 * 26  + (elem[1] - 'A') * 26 + (elem[2] - 'A')) % 10;
    return hash;
}

int allocSpace(VHeap * V){
    int index = V->avail;
    V->avail = V->H[V->avail].next;
    return index;
}

void deallocSpace(VHeap * V, int index){
    V->H[index].next = V->avail;
    V->avail = index;
}

bool finder(VHeap * V, char * elem){
    int key = hash(elem);
    int trav = key;
    while(trav != -1){
        if(strcmp(V->H[trav].elem, elem) == 0){
            return true;
        }
        trav = V->H[trav].next;
    }
    return false;
}

void insertSortedElem(VHeap * VH){
    if(VH->avail != -1){
           char elem[4];
    printf("Enter airport code: "); 
    scanf("%s", elem);
 
        int key = hash(elem);
        
        cell * curr = &VH->H[key];
        cell * prev = NULL;


        if(strcmp(curr->elem, "") == 0){
            strcpy(curr->elem, elem);
            return;
        }
        
        while(1){
            if(strcmp(curr->elem, elem) == 0){
                printf("SAME");
                return;
            }

            if(strcmp(curr->elem, elem) > 0 || curr->next == -1){
                break; 
            }

            prev = curr; 
            curr = &VH->H[curr->next]; 
        }

        int index = allocSpace(VH); 
        VH->H[index].next = -1;

        if(strcmp(curr->elem, elem) < 0){
            prev = curr; 
        }

        if(prev == NULL){
            VH->H[index] = *curr;
            strcpy(curr->elem, elem);
            curr->next = index;
        }else{
            strcpy(VH->H[index].elem, elem);
            VH->H[index].next = prev->next;
            prev->next = index; 
        }
    }

}


void delete(VHeap * VH){

   char elem[4];
    printf("Enter airport code: "); 
    scanf("%s", elem);



    int key = hash(elem);
    cell * curr = &VH->H[key]; 
    cell * prev = NULL;

    while(curr->next != -1){
        if(strcmp(curr->elem, elem) == 0){
            break;
        }
        prev = curr; 
        curr = &VH->H[curr->next];
    }
    

    if(strcmp(curr->elem, elem) != 0){
        return; 
    }

    if(prev == NULL){
        if(curr->next == -1){
            strcpy(curr->elem, "");
            return;
        }

        VH->H[key] = VH->H[curr->next]; 
        deallocSpace(VH, curr->next); 
            
    }else{
        int index = prev->next; 
        prev->next = curr->next; 
        deallocSpace(VH, index);
    }
        
}


void display(VHeap * V){
    printf("--- AIRPLACE elemS ---\n");
    for(int i = 0;i < SECONDARY ;i++){
        int trav = i;
        printf("Index [%d] -> ", i);
        if(strlen(V->H[trav].elem) == 0){
            printf("EMPTY\n");
        }else{
            while(trav != -1){
            printf("%s -> ", V->H[trav].elem);
                trav = V->H[trav].next;
        }

        
         printf(" NULL\n");
   
        }
    }
}
