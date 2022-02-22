#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef char *string;


typedef struct {
    int key;
    string value;
}dict;

typedef struct node {
    int data;
    struct node * next;
}node;

void printListW(struct node * n) {
    while (n != NULL) {
        printf("%d ", n->data);
        n = n-> next;
    }
}

void printList(node * n) {
    printf("\n%d\n", n->data);
}

void append(struct node** head_ref, int new_data) {
    /* 1. allocate node */
    node* new_node = (struct node*) malloc(sizeof(node));

    node *last = *head_ref;  /* used in step 5*/

    /* 2. put in the data  */
    new_node->data  = new_data;

    /* 3. This new node is going to be the last node, so make next of
          it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;
}

int main(void) {
    char names[] = {"sam"};

    node * head = NULL;
    node * second = NULL;
    node * third = NULL;

    head = (node*) malloc(sizeof(node));
    second = (node*) malloc(sizeof(node));
    third = (node*) malloc(sizeof(node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    append(&head, 5);

    printf("%p\n", &head);
    printListW(head);
    printList(head);
}