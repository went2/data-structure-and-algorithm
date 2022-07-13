//
//  queue-array-version.cpp
//  
//
//  Created by WenTommy on 2022/7/13.
//

#include "queue-array-version.hpp"

void EnQueue(int x);
int DeQueue(void);
int Front(void);
bool IsEmpty(void);
bool IsFull(void);
void PrintQ(void);

int main() {
    EnQueue(11);EnQueue(22);EnQueue(33);EnQueue(44);PrintQ();
    printf("%d\n", DeQueue());
    printf("%d\n", DeQueue());
    printf("%d\n", DeQueue());
    printf("%d\n", DeQueue());
    printf("%d\n", DeQueue());
    PrintQ();
    
    return 0;
}
