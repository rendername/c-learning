#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node *next;
} node;

node *createNode(int value) {
    node *n = malloc(sizeof(node));
    n->value = value;
    n->next = NULL;
    return n;
}

typedef struct {
    node *head;
    node *tail;
} queue;

queue *newqueue() {
    queue *q = malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void enqueue(queue *q, int value) {
    node *n = createNode(value);
    if(q->tail != NULL) q->tail->next = n;
    q->tail = n;

    if(q->head == NULL) q->head = n;
}

int dequeue(queue *q) {
    node *tmp = q->head;
    if(tmp == NULL) return false;
    q->head = tmp->next;
    int result = tmp->value;
    free(tmp);
    return result;
}

int main(void) {
    queue *one = newqueue();
    enqueue(one, 10);
    enqueue(one, 20);
    enqueue(one, 30);
    
    int v;
    while((v = dequeue(one))) {
        printf("%d\n", v);
    }

    return 0;
}
