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

### Linked List —— Implementation in C/C++

链表的入口是 pointer to the first node，这是唯一读取链表的方式。

创建一个链表，就是创建一个保存指针的变量，这个变量类型是 `Node\*`, 值是下一个节点的内存地址。因为链表只能通过 head 元素访问，所以创建链表就是创建这个指针类型的 head，分配给它一个变量名，让它保存下一个节点的内存地址。

创建一个节点，就是划出一块内存空间，就来存一个 `Node`, 在 C 中用 `malloc(int numOfBytes)`函数获取一块内存空间，返回值是这块 memory 起始位置的地址。


