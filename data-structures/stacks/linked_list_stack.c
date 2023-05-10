#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node;

node *head = NULL;

node *createNode(int value) {
    node *n = malloc(sizeof(node));
    n->value = value;
    n->next = NULL;
    return n;
}

bool push(int value) {
    node *n = createNode(value);
    if(head == NULL) {
        head = n;
        return true;
    }

    n->next = head;
    head = n;

    return true;
}

node *pop() {
    node *tmp = head;
    head = tmp->next;
    return tmp;
}

int main(void) {
    push(10);
    push(20);
    push(30);

    printf("%d\n", pop()->value);
    printf("%d\n", pop()->value);
    printf("%d\n", pop()->value);

    return 0;
}
