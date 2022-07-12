# 数据结构与算法

## Array

- 有固定长度的
- 在内存中是连续存放的

### 数组操作的时间复杂度：

Access：包括 read/write，O(1), 读取指定元素，是将第一个元素地址加上(索引值\*4)，假设 `array[0]` 在内存中的地址是`213`，那么 array[2] 在内存中的地址是`213+2*4=221`，读取任何元素都做这一相同计算，耗时恒定。

Insert：O(n)，O(n)，将指定位置及后续所有元素向右移动一位，插入元素。

Remove：O(n)，删除指定元素，将后续所有元素向左移动一位。

array 在定义时就要确定一个 size，以便操作系统划出一块空间来保存数据。想要动态增加 array 的容量怎么办？

需要一种更有效地利用内存，且保留数组操作特征的结构：Linked List

### Linked List

```c++
struct Node
{
	int data; // 4 bytes
	Node* link; // 4 bytes
};
```

Address of the head gives access to the whole linked list.

链表操作的时间复杂度

Read: O(n)，从 head 依次查下去，与链表的 size 有关。

Insertion: O(n)

选择数据结构的基本问题：

	- 你最常用它做什么操作
	- 存什么数据，数据量多少

array 与 linked list 比较

| 比较项\\数据结构| Array | Linked List|
|---|---|---|
|内存占用   | size * sizeof(data), 数组长度 * 数据所占空间 |  节点个数 * (sizeof(data) + sizeof(pointer))  |
|   | 需占用一整块连续的内存空间 |  占用一个个独立且小的内存空间  |
|读取操作的时间复杂度   | 常数时间，O(1)  |  O(n)  |
|插入与删除元素的时间复杂度：开始位置   |  O(n)，要将所有元素 shift |  O(1)  |
|插入与删除元素的时间复杂度：最后位置   |  数组还有空间时：O(1)；数组没有空间时：O(n) |  O(n)  |
|插入与删除元素的时间复杂度：中间位置   |  O(n) |  O(n)  |

- 要存的数据越大，linked list 越省内存，因为每个节点的 pointer(4 bytes) 所占空间的比例越小。

## Linked List —— Implementation in C/C++

### 概念

链表的入口是head，head 是指针类型，存第一个节点的地址。

创建一个链表，就是创建一个保存指针的变量，这个变量类型是 `Node\*`, 值是下一个节点的内存地址。因为链表只能通过 head 元素访问，所以创建链表就是创建这个指针类型的 head，分配给它一个变量名，让它保存下一个节点的内存地址。

创建一个节点，就是在内存的 heap 区域划出一块空间，存节点数据及指针, C 语言中用 `malloc(int numOfBytes)`函数获取一块内存空间，返回值是这块 memory 起始位置的地址。

### 链表操作：

删除节点：
	- fix the links 
	- free the space by build-in function `free()` 

翻转链表(reversing a linked list)：
	
想象链表是人形蜈蚣（啊~好吓人！），翻转链表是将其中每个人掉个头，
	从 `A -> B -> C -> D` 变为 `D -> C -> B -> A` 

这是从整体角度看的，这个概念是人的设想，或叫逻辑上的翻转，不存在于计算机内部，如何将这个操作用c语言实现？描述为：将每个节点的 next 从当前的值变为指向该节点的节点地址。

递归（recursion）实现链表倒转（reversing a linked list）

如果用函数实现一个递归，函数自己调用自己，调用栈一个个向上叠加，直至达到return条件，然后从最顶部的调用栈开始return，执行上一个调用栈内后续的代码（如果还有的话），因为之前的调用栈没有return。

写递归先写退出条件(exit condition)

### 双向链表(doubly linked list)

- 实现这些 interface：
	- `void insertAtHead(int data)`;
	- `void insertAtTail(int data)`;
	- `void printLL(void)`;
	- `void printLLReverse(void)`;

- 对重复操作用函数封装

比如，实现往双向链表的头部插入节点 `void insertAtHead(int data)` 接口过程中，在新建节点后，需要将其位置放到链表的第一个，处理这步时，要停下来，想象一个头尾相接的人形蜈蚣（啊！），新节点的尾部接到原新节点的头部，然后将其 map 到链表操作，这个操作是重复的，用函数封装为：

```c

// 封装
void placeNodeToHead(struct Node* nodeAddress);

void placeNodeToHead(struct Node* nodeAddress) {
    (*head).prev = nodeAddress;
    (*nodeAddress).next = head;
    head = nodeAddress;
}

// 使用

void insertAtHead(int data) {
    struct Node* newNodeAddress = getNewNode(data);
    if (head == NULL) {
        head = newNodeAddress;
        return;
    }
    placeNodeToHead(newNodeAddress);
}
```

看起来是封装在先，使用在后，实际上是先写了这个使用过程，然后将这部分过程从其上下文中提取，封装为函数，让它通过参数和它的上下文沟通。

类似的，走访到链表的最后一个节点，也可以封装为函数，外界给它一个 head，它返回最后一个节点的地址：

```c
// 封装
struct Node* toLastNode(struct Node* head) {
    struct Node* temp = head;
    while ((*temp).next != NULL) {
        temp = (*temp).next;
    }
    return temp;
}

// 使用：在插入节点为最后一个节点的 interface 中使用
void insertAtTail(int data) {
    struct Node* newNodeAddress = getNewNode(data);
    struct Node* lastNode;
    if(head == NULL) {
        head = newNodeAddress;
        return;
    }
    lastNode = toLastNode(head);
    placeNodeToLast(newNodeAddress, lastNode);
}
```

## [栈 stack](./3_stack/stack.md)

### 1. 概念(stack as ADT)

#### 1.1 stack operations

#### 1.2 栈的使用场景

### 2. 栈的实现（implementation of a stack）

#### 2.1 用 array 实现 stack 的思路

#### 2.2 使用 linked list 实现 stack 的思路

### 3. 栈的使用

#### 3.1 例1：翻转字符串

#### 3.2 例2：翻转链表

#### 3.3 例3：检查括号是否成对出现









