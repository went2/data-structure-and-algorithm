//
//  doubly-linked-list.cpp
//  
//
//  Created by WenTommy on 2022/7/10.
//

#include "doubly-linked-list.hpp"
#include <stdio.h>

void insertAtHead(int data);
void insertAtTail(int data);
void printLL(void);
void printLLReverse(void);

int main() {
    head = NULL;
    insertAtHead(77); printLL(); printLLReverse();
    insertAtHead(88); printLL(); printLLReverse();
    insertAtHead(99); printLL(); printLLReverse();
    
    return 0;
}
