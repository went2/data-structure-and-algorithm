//
//  doubly-linked-list.hpp
//  
//
//  Created by WenTommy on 2022/7/10.
//

#ifndef doubly_linked_list_hpp
#define doubly_linked_list_hpp

#include <stdio.h>
#include <stdlib.h>

#endif /* doubly_linked_list_hpp */

// linked list 操作函数，供外部使用的
void insertAtHead(int data);
void insertAtTail(int data);
void printLL(void);
void printLLReverse(void);

// 工具函数，本文件内使用，供实现 linked list 操作
struct Node* getNewNode(int data);
void placeNodeToHead(struct Node* nodeAddress);
void placeNodeToLast(struct Node* newNode, struct Node* lastNode);
struct Node* toLastNode(struct Node* head);

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// global linked list
Node* head;

void insertAtHead(int data) {
    struct Node* newNodeAddress = getNewNode(data);
    if (head == NULL) {
        head = newNodeAddress;
        return;
    }
    placeNodeToHead(newNodeAddress);
}

void placeNodeToHead(struct Node* nodeAddress) {
    (*head).prev = nodeAddress;
    (*nodeAddress).next = head;
    head = nodeAddress;
}

void placeNodeToLast(struct Node* newNode,struct Node* lastNode) {
    (*lastNode).next = newNode;
    (*newNode).prev = lastNode;
}

void insertAtTail(int data) {
    struct Node* newNodeAddress = getNewNode(data);
    struct Node* lastNode;
    if(head == NULL) {
        head = newNodeAddress;
        return;
    }
    lastNode = toLastNode(head);
    placeNodeToLast(newNodeAddress, lastNode);
}

struct Node* toLastNode(struct Node* head) {
    struct Node* temp = head;
    while ((*temp).next != NULL) {
        temp = (*temp).next;
    }
    return temp;
}

Node* getNewNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    (*temp).data = data;
    (*temp).prev = NULL;
    (*temp).next = NULL;
    return temp;
    
    /* 以下写法的 newNode 的数据在函数返回后会被清除，因为它声明在栈中
        外界只接收到 newNode 的内存地址，却不能通过地址访问到 newNode 数据
     struct Node newNode;
     newNode.data = data;
     newNode.prev = NULL;
     newNode.next = NULL;
     return &newNode;
     */
}

void printLL(void) {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", (*temp).data);
        temp = (*temp).next;
    }
    printf("\n");
}

void printLLReverse(void) {
    struct Node* temp;
    
    // go to the last node
    temp = toLastNode(head);
    
    // traverse backward to print node data
    while(temp != NULL) {
        printf("%d ", (*temp).data);
        temp = (*temp).prev;
    }

    printf("\n");
}

