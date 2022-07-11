//
//  stack-linked-list-version.cpp
//  
//
//  Created by WenTommy on 2022/7/11.
//

#include "stack-linked-list-version.hpp"

void push(int data);
int topValue(void);
void popup(void);
int isEmpty(void);
void printSt();

int main() {
    head = NULL;
    push(11);
    printf("%d \n", topValue());
    push(22);push(33);push(44);push(55);
    printSt();
    printf("is empty: %d \n", isEmpty());
    
    return 0;
}
