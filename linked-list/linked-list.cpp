//
//  linked-list.c
//  
//
//  Created by WenTommy on 2022/7/8.
//

#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"



void printLinkedList(struct Node* head);
Node* insertToFirst(Node* head, int val);

int main() {
    int i, val, val2, num = 0;
    
    struct Node* head = NULL; // head of linked list
    
    printf("input a number of linked-list:\n");
    scanf("%d", &val);
    
    head = insertToFirst(head, val);
    
    printf("input another number of linked-list:\n");
    scanf("%d", &val2);
    
    struct Node* temp2 = (struct Node*)malloc(sizeof(struct Node));
    (*temp2).data = val2;
    (*temp2).next = NULL;
    (*head).next = temp2;
    
    printLinkedList(head);
    
    return 0;
}

// traversal linked-list to print node value
void printLinkedList(struct Node* head) {
    printf("Linked-List: \n");
    while(head != NULL) {
        printf("%d ", (*head).data);
        head = (*head).next;
    }
}
