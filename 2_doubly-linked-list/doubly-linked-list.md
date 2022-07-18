# 双向链表(doubly linked list)

## 1. 双向链表的操作

- 实现这些 interface：
	- `void insertAtHead(int data)`;
	- `void insertAtTail(int data)`;
	- `void printLL(void)`;
	- `void printLLReverse(void)`;

- 对重复操作用函数封装

比如，实现往双向链表的头部插入节点 `void insertAtHead(int data)` 接口过程中，在新建节点后，需要将其位置放到链表的第一个，处理这步时，要停下来，想象一个头尾相接的人形蜈蚣（啊！），新节点的尾部接到原新节点的头部，然后将其 map 到链表操作，这个操作是重复的，用函数封装为：

## 2. 实现双向链表的代码示例

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
