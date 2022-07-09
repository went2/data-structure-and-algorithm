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

Node* head;

int main() {
    head = NULL;
    insert(34, 1);
    insert(55, 2);
    insert(222, 2);
    insert(45, 1);
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
