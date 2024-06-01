#include <stdio.h>
#include <stdlib.h>

struct stackrec{
    char *starr;
    int tos;
    int capacity;
};
typedef struct stackrec *stack;
stack s;

void createstack(){
    s=(stack) malloc(sizeof(stack));
    s->starr=(char *)malloc(100*sizeof(char));
    s->tos =-1;
    s->capacity =100;
}

int isEmptystack(){
    return (s->tos==-1);
}

int isFull(){
    return (s->tos==s->capacity-1);
}

void push(char c){
    if(!isFull()){
        s->starr[++s->tos]=c;
    }else{
        printf("Stack overflow.\n");
    }
}

void form(){
    if(!isEmptystack()){
        int i;
        i=s->tos;
        printf("Current form: ");
        for(int i=s->tos;i>=0;i--){
            printf("%c ",s->starr[i]);
        }
        printf("\n");
    }else{
        printf("Stack underflow.\n");
    }
}


