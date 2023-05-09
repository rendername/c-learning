#include <stdlib.h>
#include <stdio.h>

typedef struct node_t {
    int value;
    struct node_t *prev;
    struct node_t *next;
} node_t;

node_t *createNode(int value) {
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->prev = NULL;
    result->next = NULL;
    return result;
}

void insertAtHead(node_t **head, node_t *n) {
    n->next = *head;
    n->prev = NULL;
    if(n->next != NULL) n->next->prev = n;
    *head = n;
}

void insertAfter(node_t *after, node_t *n) {
    n->next = after->next;
    after->next = n;
    n->prev = after;
    if(n->next != NULL) n->next->prev = n;
}

node_t *findNodeByValue(node_t *head, int value) {
    node_t *tmp = head;
    while(tmp != NULL) {
        if(tmp->value == value) return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

void printNodes(node_t *head) {
    node_t *tmp = head;
    while(tmp != NULL) {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}

void deleteNode(node_t **head, node_t *n) {
    if(n->prev == NULL) { //head
        *head = n->next;   
        n->next->prev = NULL;
        n = NULL;
        free(n);
        return;
    }

    if(n->next == NULL) { //tail
        n->prev->next = NULL;
        n = NULL;
        free(n);
        return;
    }

    n->prev->next = n->next;
    n->next->prev = n->prev;
    n = NULL;
    free(n);
}

int main(void) {
    node_t *head = NULL;

    insertAtHead(&head, createNode(10));
    insertAtHead(&head, createNode(20));
    insertAtHead(&head, createNode(30));

    insertAfter(findNodeByValue(head, 20), createNode(25));

    deleteNode(&head, findNodeByValue(head, 30));
    
    printNodes(head);

    return 0;
}
