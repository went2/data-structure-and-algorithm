//
//  stack-linked-list-version.hpp
//  
//
//  Created by WenTommy on 2022/7/11.
//

#ifndef stack_linked_list_version_hpp
#define stack_linked_list_version_hpp

#include <stdio.h>
#include <stdlib.h>

#endif /* stack_linked_list_version_hpp */

void push(int data);
int topValue(void);
void popup(void);
int isEmpty(void);

// 工具函数
struct Node* getNewNode(int data);
void printSt();

struct Node {
    int data;
    struct Node* next;
};

Node* head;

void push(int data) {
    struct Node* temp = getNewNode(data);
    if(head == NULL) {
        head = temp;
        return;
    }
    (*temp).next = head;
    head = temp;
}

int topValue() {
//    if(head == NULL) {
//        printf("Error: empty stack.");
//        return;
//    }
    return (*head).data;
}

void popup() {
    if(head == NULL) return;
    struct Node* firstNode = head;
    head = (*firstNode).next;
    printf("%d has been popup\n", (*firstNode).data);
    free(firstNode);
}

int isEmpty() {
    return head == NULL;
}

struct Node* getNewNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void printSt() {
    if(head == NULL) return;
    
    printf("\n===start print===\n");
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n===print finished===\n");
}
