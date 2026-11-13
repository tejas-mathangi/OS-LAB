#include <stdio.h>
#define MAX 20

int queue[MAX];
int front=0,rear=-1;

void enqueue(int x){
    if(rear==MAX-1){
        printf("Queue is full.\n");
        return;
    }
    queue[++rear]=x;
    return;
}

int dequeue(){
    if(front>rear){
        printf("Queue is empty.\n");
        return -1;
    }
    return queue[front++];
}

int peek(){
    return queue[front];
}

void display(){
    if (front>rear){
        printf("empty queue.\n");
        return;
    }
    for(int i=front;i<=rear;i++){
        printf("%d",queue[i]);
    }
    printf("\n");
    return;
}
int main(){

    return 0;
}

