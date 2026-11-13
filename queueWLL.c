#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node *next;
};
struct Node *front =NULL;
struct Node *rear = NULL;

void enqueue(int x){
     struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = x;
    newNode->next = NULL;

    if(front == NULL) {        // first node
        front = rear = newNode;
        return;
    }

    rear->next = newNode;      // add at end
    rear = newNode;
}

void dequeue(){
    if(front==NULL){
        printf("Empty queue");
        return;
    }
    struct Node *temp = front;
    int x = temp->val;
    front =front->next;
    free(temp);
    if(front == NULL)   
        rear = NULL;
    printf("dequeued %d",x);
    
}

void display(){
    struct Node *temp = front;
    while(temp!=NULL){
        printf("%d",temp->val);
        temp=temp->next;
    }
    return;
}