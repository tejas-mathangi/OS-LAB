#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;

void push(int x){
    if(top==MAX-1){
        printf("Overflow\n");
        return;
    }
    stack[++top]=x;
    return;
}

int pop(){
    if(top==-1){
        printf("Underflow\n");
        return -1;
    }
    return stack[top--];
}

int peek(){
    if(top==-1){
        printf("Stack empty\n");
        return -1;
    }
    return stack[top];
}

void display(){
    if(top==-1){
        printf("Stack empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = top; i >=0 ; i--){
        printf("%d ",stack[i]);
    }
    return;
}
int main(){
    push(1);
    push(3);
    push(2);
    push(2);
    push(5);
    display();
    printf("\n%d\n",peek());
    pop();
    display();
    peek();
    printf("\n%d\n",peek());
    return 0;
}