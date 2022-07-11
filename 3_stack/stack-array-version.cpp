//
//  stack-array-verison.cpp
//  implementation of basic stack operations
//
//  Created by WenTommy on 2022/7/11.
//

#include <stdio.h>

#define MAXSIZE 101

int top = -1;
int arr[MAXSIZE];

// operations
void push(int data);
int topValue(void);
int isEmpty(void);
void popup(void);
void printSt(void);

int main() {
    push(5); printSt();
    push(7); printSt();
    push(79); printSt();
    
    return 0;
}

void push(int data) {
    if(top >= MAXSIZE - 1) {
        printf("Error: could not push, Stack overflow\n");
        return;
    }
    
    arr[++top] = data;
}

void popup() {
    if(top == -1) {
        printf("Error: could not popup, stack is empty.\n");
        return;
    }
    top--;
}

int topValue() {
    return arr[top];
}

int isEmpty() {
    return top == -1;
}

void printSt() {
    printf("\n===print begin===\n");
    if(top == -1) {
        printf("Error: empty stack.\n");
        return;
    }
    for(int i=0; i<=top; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n===print finished===\n");
}
