#include <stdio.h>
#include <stdbool.h>

#define MAX_STACK 10

int stack[MAX_STACK];
int top = -1;

bool push(int value) {
    if(top > MAX_STACK) return false; //stack is full
    stack[++top] = value;
    return true;
}

int pop(void) {
    if(top < 0) return -100;
    return stack[top--];
}

int main(void) {
    push(10);
    push(20);
    push(30);

    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());

    return 0;
}
