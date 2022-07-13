//
//  queue-array-version.hpp
//  
//
//  Created by WenTommy on 2022/7/13.
//

#ifndef queue_array_version_hpp
#define queue_array_version_hpp

#include <stdio.h>

#endif /* queue_array_version_hpp */

// 容量为100个整数的队列

#define MAX_SIZE 100

int arr[MAX_SIZE];
int front = -1;
int rear = -1;

void EnQueue(int x);
int DeQueue(void);
int Front(void);
void PrintQ(void);
bool IsEmpty(void);
bool IsFull(void);

void EnQueue(int x) {
    if(IsEmpty()) {
        front = rear = 0;
        arr[0] = x;
    } else if(IsFull()) {
        printf("full queue\n");
        return;
    } else {
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = x;
    }
}

int DeQueue(void) {
    int temp = front;
    if (front == rear) {
        front = rear = -1;
        return arr[temp];
    }
//    else if (IsEmpty())
//    {
//        printf("empty queue\n");
//        return;
//    }
    else {
        front = (front + 1) % MAX_SIZE;
        return arr[temp];
    }
}

int Front(void) {
//    if(IsEmpty()) {
//        printf("empty queue\n");
//        return;
//    }
    return arr[front];
}

bool IsEmpty(void) {
    return front == -1 || rear == -1;
}

bool IsFull(void) {
    return (rear + 1) % MAX_SIZE == front;
}

void PrintQ(void) {
    if(IsEmpty()) {
        printf("empty queue\n");
        return;
    }
    printf("\n===start print queue===\n");
    for(int i=front; i<=rear; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n===print finished===\n");
}
