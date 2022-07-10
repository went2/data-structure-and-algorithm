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

void insertAtHead(int data);
struct Node* getNewNode(int data);
void printLL(void);
void printLLReverse(void);

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
    (*head).prev = newNodeAddress;
    (*newNodeAddress).next = head;
    head = newNodeAddress;
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

void printLL() {
    Node* temp = head;
    while(temp != NULL) {
        printf("%d ", (*temp).data);
        temp = (*temp).next;
    }
    printf("\n");
}



