//
//  doubly-linked-list.cpp
//  
//
//  Created by WenTommy on 2022/7/10.
//

#include "doubly-linked-list.hpp"
#include <stdio.h>

void insertAtHead(int data);
void printLL(void);

int main() {
    head = NULL;
    insertAtHead(77); printLL();
    insertAtHead(88); printLL();
    insertAtHead(99); printLL();
    
    return 0;
}
