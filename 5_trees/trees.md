# 树 Trees

## 1. 概念 trees as ADT

之前学的几种数据结构（数组、链表、栈、队列）常用来存储线性(linear structures)结构的数据，线性结构有两个端，数据的进出都通过两个端。

树这种结构用来表达如家族族谱一般的**层次**关系。

### 1.1 树的术语

树结构由节点构成，每个节点保存它的数据以及指向下个节点的指针，节点可以只有数据没有指针。

![trees-overview](./images/trees-overview.png)

- root: 根节点，树的起始节点；
- children: 上图中，节点1指向的节点2、节点3，节点2、节点3叫节点1的子节点；
- parent: 节点1是节点2、节点3的父节点；
- sibling: 拥有相同父节点的兄弟节点，节点2是节点3的兄弟节点；
- leaf: 没有子节点的节点

只能单向走访树中的节点，如果我们可以从 A 走访到 B，那么：
	- A 叫 B 的祖先(ancestor)
	- B 叫 A 的后代(descendent)

### 1.2 树的特征

- 树是一种可用递归描述的结构(recursive data structrue)

- 对于有 `N` 个节点的树，有 `N-1` 个链接(树枝， edges)，因为每个节点只有一个指向它的链接

- 节点有深度(depth), depth of x = numbers of edges in path from root to x, root 节点深度记为0

- 节点有高度(height), height of x = numbers of edges in longest path from x to a leaf，从它自身到一个叶子节点经过的树枝中的最长一条。叶子节点的高度记为0

- 树有高度，树的高度即根节点的高度

### 1.3 树的分类

- 二分树(binary tree)：每个节点最多只能有2个子节点的树，最简单、最常见的树结构

![binary-tree](./images/binary-tree.png)


### 1.4 树结构的使用场景

- 存放天生有层次结构的数据，如文件系统、浏览器的 DOM 结构
- 需要快速查找、插入、删除数据时，可用二分查找树(binary search tree)
- Trie，字典树
- Networking routing algorithm

## 2. 树的实作——以二分树为例

### 2.1 概念

- strict binary tree: 每个节点要么有2个子节点，要么没有子节点
- complete binary tree: 除了最下面一层，其他所有层次的节点都满格，最下面一层的节点位于最左边。
- perfect binary tree: 所有层级都充满节点

节点的层次(即节点的深度)与最大节点数量

第 i 层最大的节点数：level<sub>i</sub> = 2<sup>i</sup>

对数进行的操作的时间负责度与数的高度有关，在构造树结构时，考虑尽量缩小树的高度，使之成为一个 `balanced binary tree`:

- balanced binary tree: 对于每个节点的左右两个子树，其diff<sub>height</sub>(高度差)不超过 1

> 约定：空树的高度为 -1， 只有一个节点的树高度为 0；
> diff<sub>height</sub> = | height<sub>left-sub-tree</sub> - height<sub>right-sub-tree</sub> |

![diff-height](./images/diff-height.png)

### 2.2 二分树的实现



 



