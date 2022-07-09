//
//  linked-list2.cpp
//  
//
//  Created by WenTommy on 2022/7/9.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    Node* next;
};

void insert(int data, int pos);
void print(void);
void deleteNode(int pos);
void reverseIteration(void);
void reverseRecursion(Node* p);

Node* head;

int main() {
    head = NULL;
    insert(34, 1);
    insert(55, 2);
    insert(222, 2);
    insert(45, 1);
    print();
    
    reverseRecursion(head);
    print();
    return 0;
}

void insert(int data, int pos) {
    Node* temp = (Node*)malloc(sizeof(Node));
    (*temp).data = data;
    (*temp).next = NULL;
    
    if (pos == 1) {
        (*temp).next = head;
        head = temp;
        return;
    }
    
    // get Node at pos-1
    Node* temp2 = head;
    for(int i=0; i<pos-2; i++) {
        temp2 = (*temp2).next;
    }
    (*temp).next = (*temp2).next;
    (*temp2).next = temp;
}

void print(void) {
    printf("linked list:\n");
    Node* temp = head;
    while(temp != NULL) {
        printf("%d ", (*temp).data);
        temp = (*temp).next;
    }
}

void deleteNode(int n) {
    Node* temp = head;
    if (n <= 0) {
        printf("no such node");
        return;
    }
    if (n == 1) {
        head = (*temp).next;
        free(temp);
        return;
    }
    
    for(int i=0; i<n-2; i++) {
        temp = (*temp).next; // temp: (n-1)th node
    }
    Node* temp2 = NULL;
    temp2 = (*temp).next;
    (*temp).next = (*temp2).next;
    free(temp2);
}

void reverseIteration() {
    Node *current, *prev, *next;
    current = head;
    prev = NULL;
    
    if(current == NULL)
        return;
    
    while(current != NULL) {
        next = (*current).next;
        
        (*current).next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void reverseRecursion(Node* p) {
    
    if((*p).next == NULL) { // exit condition
        head = p;
        return;
    }
    reverseRecursion((*p).next);
    
    Node* temp = (*p).next;
    (*temp).next = p;
    (*p).next = NULL;
}
