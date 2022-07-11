//
//  linked-list.c
//  
//
//  Created by WenTommy on 2022/7/8.
//

#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

void printLL(struct Node* head);
void insert(int data, int n);
void deleteNode(int position);
void reverseIterative();
void reverseRecursion(Node* address);

int main() {
    head = NULL; // head of linked list
    insert(2, 1); // 2
    insert(44,2); // 2 44
    insert(234,1); // 234 2 44
    insert(99, 2); // 234 99 2 44
    printLL(head);
    
    reverseRecursion(head);
    printLL(head);
    return 0;
    
    printLL(head);
    deleteNode(1);
    printLL(head); // 99 1 44
    deleteNode(2);
    printLL(head); // 99 44
    
   
}
