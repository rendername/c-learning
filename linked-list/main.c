#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int value;
    struct node_t *next;
} node_t;

void printNodes(node_t *head) {
    node_t *tmp = head;
    while(tmp != NULL) {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}

node_t *createNode(int value) {
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

void insertNodeAtHead(node_t **head, node_t *n) {
    n->next = *head;
    *head = n;
}

int main(void) {
    node_t *head = NULL;

    insertNodeAtHead(&head, createNode(10));
    insertNodeAtHead(&head, createNode(20));
    insertNodeAtHead(&head, createNode(30));

    printNodes(head);

    return 0;
}
