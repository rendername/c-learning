#include <stdio.h>
#include <stdbool.h>

#define STACK_LIMIT 10

int stack[STACK_LIMIT];
int top = -1;

bool push(int value) {
    if(top >= STACK_LIMIT) return false;

    top++;
    stack[top] = value;
    return true;
}

int pop() {
    if(top < 0) return -100;

    return stack[top--];
}

int main(void) {
    for(int i=0;i<STACK_LIMIT;i++) {
        push(i*10);
    }

    int tmp;
    while((tmp = pop()) != -100) {
        printf("%d\n", tmp);
    }

    return 0;
}
