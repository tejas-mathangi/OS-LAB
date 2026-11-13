#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node* next;
};

struct Node *top = NULL;

void push(int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val=x;
    newNode->next=top;
    top=newNode;
    return;
}

int pop(){
    struct Node* temp = top;
    int val = top->val;
    top=top->next;
    free(temp);
    return val;
}

void peek(){
    printf("%d",top->val);
    return;
}

void display(){
    struct Node *temp = top;
    while(temp!=NULL){
        printf("%d ",temp->val);
        temp=temp->next;
    }
    printf("\n");
    return;
}

int main(){
    push(1);
    push(1);
    push(3);
    push(2);
    push(2);
    push(5);
    display();
    pop();
    display();
    peek();
}