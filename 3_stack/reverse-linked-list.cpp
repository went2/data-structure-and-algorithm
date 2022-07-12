//
//  reverse-linked-list.cpp
//  
//
//  Created by WenTommy on 2022/7/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <iostream>

using namespace std;

void insertAtHead(int data);
struct Node* getNewNode(int data);
void printLL(void);
void Reverse(void);

struct Node {
    int data;
    struct Node* next;
};

Node* head;

int main() {
    head = NULL;
    insertAtHead(11);
    insertAtHead(22);
    insertAtHead(33);
    insertAtHead(44);
    printLL();
    
    Reverse();
    printLL();
    return 0;
}

void Reverse(void) {
    stack<struct Node*> S;
    
    Node* temp = head;
    // 将链表节点的地址从头到尾压入栈
    while (temp != NULL) {
        S.push(temp);
        temp = temp->next;
    }
    
    temp = S.top();
    head = temp;
    S.pop();
    while(!S.empty()) {
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

void insertAtHead(int data) {
    struct Node* temp = getNewNode(data);
    
    if(head == NULL) {
        head = temp;
        return;
    }
    temp->next = head;
    head = temp;
}

struct Node* getNewNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}


void printLL() {
    struct Node* temp = head;
    printf("\n===start print===\n");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n===print finished===\n");
}
