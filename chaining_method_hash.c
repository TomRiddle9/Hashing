#include<stdio.h>
#include<stdlib.h>
#define size 10
//code for chaining method to avoid collision.

struct node{
    int data;
    struct node* next;
};

struct node* chain[size];

void init(){
    for(int i=0;i<size;i++){
            chain[i] = NULL;
    }
}

void insert(int value){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node -> next = NULL;
    int key = value%size;
    if(chain[key]== NULL){
            chain[key] = new_node;
    }
    else{
            struct node* temp = chain[key];
            while(temp->next){
                temp = temp->next;
            }
            temp->next = new_node;
    }
}

void print(){

    for(int i=0;i<size;i++){
            struct node* temp = chain[i];
            printf("chain[%d]--->", i);
            while(temp){
                    printf("%d--->",temp->data);
                    temp = temp->next;
            }
            printf("NULL\n");
    }
}

int main(){

    init();
    insert(7);
    insert(4);
    insert(44);
    insert(27);
    insert(54);
    insert(9);
    insert(3);
    insert(2);
    insert(1);
    print();
    return 0;
}
