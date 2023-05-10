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

void insertNodeAfter(node_t *nodeAfter, node_t *newNode) {
    newNode->next = nodeAfter->next;
    nodeAfter->next = newNode;
}

node_t *findNodeByValue(node_t *head, int value) {
    node_t *tmp = head;
    while(tmp != NULL) {
        if(tmp->value == value) return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

int main(void) {
    node_t *head = NULL;

    insertNodeAtHead(&head, createNode(10));
    insertNodeAtHead(&head, createNode(20));
    insertNodeAtHead(&head, createNode(30));

    int search_value = 20;
    node_t *found = findNodeByValue(head, search_value);
    if(found != NULL) {
        printf("found node with value: %d\n", found->value);
    } else {
        printf("not found\n");
    }

    insertNodeAfter(found, createNode(25)); // ends up between 10 and 20 because we insert all elements backwards by default

    printNodes(head);

    return 0;
}
