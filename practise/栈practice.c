#include <stdio.h>
#define MAX_SIZE 100

//永数组模拟栈
int stack[MAX_SIZE];
int top = -1;

//入栈函数
void push(int x){
    if(top < MAX_SIZE - 1){
        top ++;
        stack[top] = x;
    }
    else {
        printf("full stack\n");
    }
}

//出栈函数
int pop() {
    if(top >= 0){
        int element = stack[top];
        top --;
        return element;
    }
    else {
        printf("empty stack\n");
        return -1;
    }
}
int main() {
    push(5);
    push(10);
    push(20);
    printf("poped element:%d\n",pop());
    return 0;
}