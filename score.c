#include <stdio.h>
#include <stdlib.h>

struct noderec{
int info;
struct noderec *next;
};
typedef struct noderec *node;

node start,end,new,temp,prev;
typedef node header;
header h;

void create(){
h=(header) malloc(sizeof(header));
h->next=h;
}

int isEmpty(){
return(h->next==h);
}

void insert(int x){
    new=(node) malloc(sizeof(node));
    new->info=x;
    temp=h;
    while(temp->next!=h){
        temp=temp->next;
    }
    temp->next=new;
    new->next=h;
}

void totalmatches(){
    if(!isEmpty()){
        temp=h->next;
        int i=1;
        while(temp->next!=h){
            i++;
            temp=temp->next;
        }
        printf("No.of matches Played: %d\n",i);
    }else{
        printf("Please play the game at least once .\n");
    }
}

void scorehistory(){
    if(!isEmpty()){
        totalmatches();
        temp=h->next;
        int i=1;
        while(temp!=h){
            printf("Match:%d \t\t Score: %d \n",i,temp->info);
            temp=temp->next;
            i++;
        }
        printf("\n");
    }else{
        printf("Please play the game at least once .\n");
    }
}

int highscore(){
    if(!isEmpty()){
        temp=h->next;
        int max=temp->info;
        while(temp!=h){
            if(temp->info > max){
                max=temp->info;
            }
            temp=temp->next;
        }
        return max;
    }else{
        printf("Please play the game at least once .\n");
        return 0;
    }
}

