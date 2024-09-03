#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node_t {
    int data;
    struct node_t* next;
};
typedef struct node_t node_t;

int size = 0;

node_t* createNode(int val);

void insertNode(node_t** current, unsigned int pos, int val);

void removeNode(node_t** current, unsigned int pos);

void printList(node_t* head);

void freeList(node_t* head);


int main(){
    node_t* head = NULL;
    head = createNode(100);
    printf("\nValue of head: %p", (void*)head);
    printf("\nData taken by head: %d", head -> data);

    head -> next = createNode(200);
    head -> next -> next = createNode(300);

    insertNode(&head, 1, 500);

    removeNode(&head, 2);

    printList(head);

    freeList(head);
    
    return 0;
}

node_t* createNode(int val){
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if(newNode == NULL){
        return NULL;
    }
    newNode -> data = val;
    newNode -> next = NULL;

    return newNode;
}

void insertNode(node_t** current, unsigned int pos, int val){
    if(pos == 0) {
        node_t* temp = createNode(val);
        temp->next = *current;
        *current = temp;
    }
    while(pos > 0) {
        current = &(*current) -> next;
        pos--;
    }
    node_t* temp = createNode(val);
    temp -> next = *current;
    *current = temp;
}

void removeNode(node_t **head, unsigned int pos){
    node_t* temp = *head;
    node_t* pre = NULL;

    if(pos == 0){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && pos > 0) {
        pre = temp;
        temp = temp->next;
        pos--;
    }
    pre->next = temp->next;
    free(temp);
}

void printList(node_t *head){
    while(head != NULL){
        printf("\nNode %d: data: %d\t address: %p", size, head -> data, (void*)(head -> next));
        head = head -> next;
        size++;
    }
}

void freeList(node_t *head){
    if(head -> next != NULL){
        freeList(head->next);
        free(head);
    }
    else if(head -> next == NULL){
        free(head);
    }
}
