//
//  queue-linked-list-version.hpp
//  
//  implemetation of a queue based on linked list
//  Created by WenTommy on 2022/7/13.
//

#ifndef queue_linked_list_version_hpp
#define queue_linked_list_version_hpp

#include <stdio.h>
#include <stdlib.h>

#endif /* queue_linked_list_version_hpp */

struct Node {
    int data;
    struct Node* next;
};

// 全局变量 front, tear
struct Node* front = NULL;
struct Node* tear = NULL;

void Enqueue(int x);
void Dequeue(void);
bool IsEmpty(void);
int Front(void);
void printQ(void);

struct Node* getNewNode(int x);

void Enqueue(int x) {
    struct Node* temp = getNewNode(x);
    if(front == NULL && tear == NULL) {
        front = tear = temp;
        return;
    }
    tear->next = temp;
    tear = temp;
}

void Dequeue(void) {
    struct Node* temp = front;
    if(temp == NULL) {
        return;
    }
    
    if(front == tear) {
        front = tear = NULL;
        free(temp);
    }
    front = temp->next;
    free(temp);
}

bool IsEmpty(void) {
    return (front == NULL) && (tear == NULL);
}

int Front(void) {
    return front->data;
}

struct Node* getNewNode(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void printQ(void) {
    struct Node* temp = front;
    
    printf("\n===start printing queue===\n");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n===printing finished===\n");
}
