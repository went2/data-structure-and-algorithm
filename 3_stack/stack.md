# 栈 stack

## 1. 概念（stack as ADT）

栈是一种列表（list）结构，栈中的数据只能从一端出入，这一端是栈的顶端。后进先出 last in first out.

### 1.1 stack operations

实现一个栈结构，要实现以下基本操作（或叫 interface）：
	- push()， 在栈中推入一个元素
	- popup()，弹出栈顶的第一个元素
	- top()，获取栈顶的第一个元素
	- isEmpty()，查询栈中是否有元素

以上这些操作的时间复杂度为常数O(1)，意思是在栈中有1个数据和1000个情况下，进行这些操作的时间都是一样的。

### 1.2 栈的使用场景

- Function calls/Recursion, 函数调用/递归调用，函数作用域（scope，js中的叫法）一个一个叠在栈结构上
- 编辑器中的撤销上一步操作 Ctrl+Z
- 检查文本中括号是否成对出现
- 浏览器中的浏览记录

## 2. 栈的实现（implementation of a stack）

栈可在两种结构上实现：

- Array
- Link list

### 2.1 用 array 实现 stack 的思路

有一个 `int top` 变量表示栈顶端的元素, top 初始值为 `-1`，表示没有任何元素，是个空栈。

1. `top()` 表示为：`array[top]`， 因为用数组来实现，所以是数组的方式读取元素；
2. `push(x)` 表示为： `top = top + 1; array[top] = x`;
3. `popup()`表示为：`top = top - 1;`
4. `isEmpty()`表示为：`top == -1`

**处理 overflow**

数组有固定大小，当数组存满时，就无法再做 push 操作，如何处理 overflow？

要多做一步操作，在 push 时先判断数组是否已满，满了就另建一个更大的数组（两倍大小的），将当前所有数据拷贝到新数组，然后执行 push 操作，这叫动态数组技术 dynamic array

### 2.2 使用 linked list 实现 stack 的思路

- 栈顶元素的进入用链表的头部节点还是尾部节点的操作来模拟？
- 头部节点，因为对头部节点的增加与删除操作的时间复杂度是O(1)，操作尾部元素则因为要走访到尾部节点，时间负责度为O(n)

所以用链表实现 stack 主要是对头部节点操作，在实现时，单向链表的 head 变量(指针类型，保存第一个节点的地址) 可以无缝替换为 top 变量。

1. `top()` ：获取第一个节点的值 `top->data`；
2. `push(x)`：在链表的头部插入一个节点；
3. `popup()`：移除链表的第一个节点
4. `isEmpty()`：判断 `top == NULL`

使用链表实现栈不会有数据 overflow 的问题。

之前提链表的实现，链表也是由 c 中的基本数据类型和相应的操作实现的，这里用链表实现

## 3. 栈的使用

- 实现了一个栈结构后，能够用它干什么？
- 可以用来做翻转操作（reverse）

因为栈中的数据出入特征是先进的后出，所以要翻转某个数据结构，现将数据像倒豆子一样 push 进栈里，然后一个个读取栈顶端的元素，这样原来最后一个入栈的元素，现在成了第一个被读取出来的元素，倒数第二个入栈的，成为第二个被读取的，把它们按读出来的顺序存入一个数据结构。

- 翻转一个字符串，reverse a string;
- 翻转一个链表，reverse a linked list;

### 例1：翻转字符串

c 中的字符串是以 `\0` 结尾的字符的序列(字符的数组)，`\0` 用于标识字符串的结束，但它不是字符串的内容。

```c
// 使用c标准库的stack
// C是字符数组，n 为数组长度

void Reverse(char *C, int n) {
	stack<char> S;
	// loop for push

	for(int i=0; i<n; i++) {
		S.push(C[i]);
	}
	// loop for pop
	for(int i=0; i<n; i++) {
		C[i] = S.top();
		S.pop();
	}
}
```

用栈结构翻转字符串，时间复杂度：O(n)，空间复杂度O(n)。

就翻转字符串这操作本身来说，有种更省空间的做法：交换首尾两端字符的位置：

```c
void Reverse(char *C, int n) {
	for (i=0, j=n-1; i<j; i++, j--) {
		C[i] = C[j];
	}
}
```

### 例2：翻转链表

方式一：使用递归翻转链表，隐式使用了栈结构（内存的函数调用栈）。

方式二：显示地使用栈结构翻转链表：

```c
struct Node {
	int data;
	struct Node* next;
};

void Reverse() {
	// 假设 head 是全局变量
	if(head == NULL) return;

	stack<struct Node*> S;

	Node* temp = head;

	// 将每个节点的地址推入栈结构中
	while(temp != NULL) {
		S.push(temp);
		temp = temp->next;
	}

	// 拿到最后一个节点的地址，将之设为新链表的第一个元素
	temp = S.top(); head = temp;
	S.pop();

	// 依次翻转链的指向，要画图逐行理解代码
	while(!S.empty()) {
		temp->next = S.top();
		temp = temp->next;
		S.pop();
	}

	temp->next = NULL;
}



```













