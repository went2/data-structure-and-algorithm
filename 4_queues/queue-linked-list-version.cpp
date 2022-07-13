//
//  queue-linked-list-version.cpp
//  
//
//  Created by WenTommy on 2022/7/13.
//

#include "queue-linked-list-version.hpp"

void Enqueue(int x);
void Dequeue(void);
bool IsEmpty(void);
int Front(void);
void printQ(void);

int main() {
    Enqueue(11);Enqueue(22);Enqueue(33);Enqueue(44);
    printQ();
    Dequeue();Dequeue();Dequeue();Dequeue();
    printf("isEmpty: %d: ", IsEmpty());
    
    return 0;
    
}
