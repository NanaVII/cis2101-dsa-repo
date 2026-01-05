// ARRAY LIST - Variation 1 (Static, by Value)
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;

List initialize(List L){
    L.count = 0;
    int i;
    for(i=0; i<MAX; i++){
        L.elem[i] = 0;
    }
    return L;
}

List insertPos(List L, int data, int position){
    if(L.count == MAX){
        printf("\nCould not insert. Array is full.");
        return L;
    }

    printf("\n\nEnter position: "); scanf("%d", &position);
    if(position-1 > L.count){
        printf("Invalid Position.");
        return L;
    }

    printf("Enter data: "); scanf("%d", &data);
    int i;
    for(i = MAX-1; i >= 0; i--){
        L.elem[i] = L.elem[i-1];
        if(i == position-1){
            L.elem[i] = data;
            break;
        }
    }
    L.count++;
    return L;
}

List deletePos(List L, int position){
    printf("\n\nEnter position: "); scanf("%d", &position);
    if(position-1 > L.count){
        printf("Invalid Position.");
        return L;
    }

    int i;
    for(i = 0; i < MAX; i++){
        if(i >= position-1 && i != MAX-1){
        	L.elem[i] = L.elem[i+1];
		}
    }
    L.count--;
    return L;
}

int locate(List L, int data){
	printf("Enter data: "); scanf("%d", &data);
	
	int i;
	for(i = 0; i < MAX; i++){
		if(L.elem[i] == data){
			return i+1;
		}
	}
	return -1;
}

List insertSorted(List L, int data){
	if(L.count == MAX){
        printf("\nCould not insert. Array is full.");
        return L;
    }
    
    printf("Enter data: "); scanf("%d", &data);
    int i;
    int n = 0;
    for(i = 0; i < L.count; i++){
        if(L.elem[i] < data){
        	n++;
        }
    }
    
    for(i = L.count; i > n; i--){
        L.elem[i] = L.elem[i-1];
    }
    L.elem[n] = data;
    L.count += 1;
    return L;
}





// ARRAY LIST - Variation 2 (Static, by Pointer)
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}Etype, *EPtr;

void initialize(EPtr L){
    L->count = 0;
}
void insertPos(EPtr L, int data, int position){
    if(L->count == MAX){
        printf("Error: Array is Full.");
        return;
    }
    printf("Enter position: "); scanf("%d", &position);
    if(position > L->count){
        printf("Error: Invalid Position. Position is higher than Count.");
        return;
    }
    
    printf("Enter data: "); scanf("%d", &data);
    for(int i=L->count; i>position; i--){
        L->elem[i] = L->elem[i-1];
    }
    L->elem[position] = data;
    L->count++;
}
void deletePos(EPtr L, int position){
    printf("Enter position: "); scanf("%d", &position);
    if(position > L->count-1){
        printf("Error: Invalid Position. Position is higher than Count.");
        return;
    }
    
    for(int i=position; i<L->count; i++){
        L->elem[i] = L->elem[i+1];
    }
    L->count--;
}
int locate(EPtr L, int data){
    if(L->count == 0){
        return -1;
    }
    printf("Enter data to search: "); scanf("%d", &data);
    for(int i=0; i<L->count; i++){
        if(L->elem[i] == data) return i;
    }
    return -1;
}
int retrieve(EPtr L, int position){
    if(L->count == 0){
        return -1;
    }
    printf("Enter position: "); scanf("%d", &position);
    if(position > L->count-1){
        return -1;
    }
    
    return L->elem[position];
}
void insertSorted(EPtr L, int data){
    if(L->count == MAX){
        printf("Error: Array is Full.");
        return;
    }
    
    printf("Enter data to insert: "); scanf("%d", &data);
    int n = 0;
    for(int i=0; i<L->count; i++){
        if(data > L->elem[i]){
            n++;
        }
    }
    
    for(int i=L->count; i>n; i--){
        L->elem[i] = L->elem[i-1];
    }
    L->elem[n] = data;
    L->count++;
    printf("Data inserted successfully.");
}
void display(EPtr L){
    printf("Array: ");
    for(int i=0; i<L->count; i++){
        printf("%d", L->elem[i]);
        if(i != L->count-1) printf(", ");
    }
}
void makeNULL(EPtr L){
    free(L);
}



// ARRAY LIST - Variation 3 (Dynamic, by Value)
#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
} List;

List initialize(List L){
    L.elemPtr = malloc(LENGTH * sizeof(int));
    L.count = 0;
    L.max = LENGTH;
    return L;
}


List insertPos(List L, int data, int position){
    if(position <= L.count){
        if(L.count == L.max){
            L = resize(L);
        }
        for(int i =  L.count;i > position;i--){
            L.elemPtr[i] = L.elemPtr[i - 1];
        }
        L.elemPtr[position] = data;
        L.count++;
        printf("Data %d inserted at position %d!\n", L.elemPtr[position], position);
        return L;
	}
	else{
        return L;
    }
}

List deletePos(List L, int position){
    if(position <= L.count){
        for(int i = position;i < L.count;i++){
            L.elemPtr[i] = L.elemPtr[i + 1];
        }
        printf("deletion successful, current data at position %d is %d\n", position, L.elemPtr[position]);
        L.count--;
        return L;
    }
	else{
        return L;
    }

}
int locate(List L, int data){
    int i = 0;
    while(i <= L.count){
        printf("\nI count = %d\n", i);
        printf("Count is %d\n", L.count);
        printf("\n Iterating\n..");
        if(L.elemPtr[i] == data){
            printf("Data found at position %d, returning value..\n", i);
            return i;
		}
        i++;
	}
    printf("\nData not found..\n");
    return -1;
}

List insertSorted(List L, int data){
    if(L.count == L.max){
        L = resize(L);
    }

    int pos = 0;

    while (pos < L.count && L.elemPtr[pos] < data) {
	    pos++;
	}

    printf("POS IS %d\n", pos);

    L = insertPos(L, data, pos);
    return L;
}
void display(List L){
    printf("DISPLAYING LIST:\n");
    for(int i = 0; i <= L.count - 1;i++){
        printf("Index %d: %d\n", i, L.elemPtr[i]);
    }
}

List resize(List L){
    L.max *= 2;
    L.elemPtr = realloc(L.elemPtr,L.max * sizeof(int));
    printf("LIST RESIZED! CURRENT MAX IS NOW %d", L.max);
    return L;

}





// ARRAY LIST - Variation 4 (Dynamic, by Pointer)
#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct{
    int *elemPtr;
    int count;
    int max;
}List, *EPtr;

void initialize(EPtr L){
    L = malloc(sizeof(List));
    L->elemPtr = malloc(LENGTH * sizeof(int));
    L->count = 0;
    L->max = LENGTH;
}

void insertPos(EPtr L, int data, int position)
{
    if(position <= L->count){
        if(L->count == L->max - 1){
            resize(L);
        }
        for(int i = L->count; i > position ;i--){
            L->elemPtr[i] = L->elemPtr[i-1];
        }
        L->elemPtr[position] = data;
        L->count++;

    }else{
        printf("\nINVALID POSITION\n");
    }
}

void deletePos(EPtr L, int position){
    if(position <= L->count){
        for(int i = position;i <= L->count;i++){
            L->elemPtr[i] = L->elemPtr[i+1];

        }
        printf("\nData was deleted from position %d, current num is now %d", position, L->elemPtr[position]);
    }
	else{
        printf("\nPosition Invalid\n");
    }
}

int locate(EPtr L, int data){
    for(int i = 0;i <= L->count;i++){
        if(data == L->elemPtr[i]){
            printf("\nElement Found! Returning position");
            return i;
        }
        printf("\nElement NOT found!");
        return -1;
    }
}

int retrieve(EPtr L, int position){
    if(position <= L->count){
        return L->elemPtr[position];
    }
    printf("\nPosition not valid");
    return -1;
}   

void display(EPtr L){
    printf("\nDisplaying current list");
    for (int i = 0; i <= L->count; i++){
        printf("\nIndex %d: Data %d", i, L->elemPtr[i]);
    }
}
void resize(EPtr L){
    L->max *= 2;
    L = realloc(L->elemPtr, L->max * sizeof(int));
}

void makeNULL(List *L){
    free(L->elemPtr);
}
