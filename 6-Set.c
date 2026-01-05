// SET - Bit Vector Implementation
#include <stdio.h>
#include <stdbool.h>
#define SIZE 8

typedef bool Set[SIZE];

void initialize(Set set){
    for(int i = 0; i < SIZE; i++)
        set[i] = false;
}

void display(Set set){
    printf("\nArray Elements: ");
    for(int i = 0; i < SIZE; i++)
        printf("%d ", set[i]);

    printf("\nSet Elements: ");
    for(int i = 0; i < SIZE; i++)
        if(set[i])
            printf("%d ", i);
}

bool find(Set set, int element){
    return set[element];
}

void insert(Set set, int element){
    set[element] = true;
}

void delete(Set set, int element){
    set[element] = false;
}

void set_union(Set A, Set B, Set C){
    for(int i = 0; i < SIZE; i++)
        C[i] = A[i] || B[i];
}

void set_intersection(Set A, Set B, Set C){
    for(int i = 0; i < SIZE; i++)
        C[i] = A[i] && B[i];
}

void set_difference(Set A, Set B, Set C){
    for(int i = 0; i < SIZE; i++)
        C[i] = A[i] && !B[i];
}





// SET - Computer Word Implementation
#include <stdio.h>
#include <stdbool.h>
#define SIZE 8

void initialize(unsigned char *set){
    *set = 0;
}

void display(unsigned char set){
    printf("\n\nDecimal Value: %d", set);

    printf("\nBinary Value: ");
    for(int i = SIZE - 1; i >= 0; i--)
        printf("%d", (set & (1 << i)) ? 1 : 0);
    
    printf("\nSet Elements: ");
    for(int i = 0; i < SIZE; i++) 
        if(set & (1 << i))
            printf("%d ", i);
}

bool find(unsigned char set, int element){
    return (set & (1 << element)) != 0;
}

void insert(unsigned char *set, int element){
    *set |= (1 << element);
}

void delete(unsigned char *set, int element){
    *set &= ~(1 << element);
}

unsigned char set_union(unsigned char A, unsigned char B){
    return A | B;
}

unsigned char set_intersection(unsigned char A, unsigned char B){
    return A & B;
}

unsigned char set_difference(unsigned char A, unsigned char B){
    return A & ~B;
}





// SET- Bitfield Implementation
#include <stdio.h>
#include <stdbool.h>
#define SIZE 8

typedef struct{
    unsigned int field : 8;
} Set;

void initialize(Set *set){
    set->field = 0;
}

void display(Set set){
    printf("\n\nDecimal Value: %d\n", set.field);

    printf("\nBinary Value: ");
    for(int i = SIZE - 1; i >= 0; i--)
        printf("%d", (set.field & (1 << i)) ? 1 : 0);
    
    printf("\nSet Elements: ");
    for(int i = 0; i < SIZE; i++) 
        if(set.field & (1 << i))
            printf("%d ", i);
}

bool find(Set set, int element){
    return (set.field & (1 << element)) != 0;
}

void insert(Set *set, int element){
    set->field |= (1 << element);
}

void delete(Set *set, int element){
    set->field &= ~(1 << element);
}

Set set_union(Set A, Set B){
    Set C;
    C.field = A.field | B.field;
    return C; 
}

Set set_intersection(Set A, Set B){
    Set C;
    C.field = A.field & B.field;
    return C;
}

Set set_difference(Set A, Set B){
    Set C;
    C.field = A.field & ~B.field;
    return C;
}
