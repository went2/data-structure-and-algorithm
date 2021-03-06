struct Node {
    int data;
    struct Node* next;
};

Node* head;

void insertToFirst(Node* head, int val);
void printLL(struct Node* head);

// 在指定位置插入data, 需配合定义在 global 链表使用
void insert(int data, int n);
void deleteNode(int position); // 删除给定位置的节点
void reverseIterative(void);
void reverseRecursion(Node* address);

void insert(int data, int n) {
    Node* temp = (Node*)malloc(sizeof(Node));
    (*temp).data = data;
    (*temp).next = NULL;

    if(n <= 0) 
        return;
    else if (n == 1) {
        (*temp).next = head;
        head = temp;
        return;
    }

    Node* temp2 = head;
    for(int i=0; i<n-2; i++){
        temp2 = (*temp2).next; // 找到n-1号元素
    }
    (*temp).next = (*temp2).next;
    (*temp2).next = temp;
}

void deleteNode(int n) {
    Node* temp = head;
    if (n == 1) {
        head = (*head).next;
        free(temp);
        return;
    }
    for (int i=0; i<n-2; i++) {
        temp = (*temp).next;
    }
    Node* temp2 = NULL;
    temp2 = (*temp).next;
    (*temp).next = (*temp2).next;
    free(temp2);
}

void reverseIterative() {
    Node *prev, *current, *next, *temp;
    if (head == NULL) { // empty linked list
        return;
    }
    temp = head;
    prev = NULL;

    while(temp != NULL) {
        next = (*temp).next; // 先获取当前节点的下一个节点

        (*temp).next = prev; // 翻转：将当前节点指向前一个节点

        // 为翻转下一个节点做准备
        prev = temp; // 保存当前节点为”前一个节点“
        temp = next; // 继续翻转当前操作的下一个节点
    }
    head = prev;
}

void reverseRecursion(Node* address) {
    if ((*address).next == NULL) {
        head = address;
        return;
    }

    reverseRecursion((*address).next);
    Node* nextAddress = (*address).next; // 当前节点的下一个节点
    (*nextAddress).next = address; // 翻转: 让下一个节点指向当前节点
    (*address).next = NULL; // 将当前节点指向NULL，在下一个调用栈中设置
}


// insert an element after the head
// 按值传递参数，head 已是本地变量，怎么影响原链表的head？可以返回一个新 head
// 也可以用指针的指针来实现，第一个pointer 的值可以存任意内存空间地址，如作为链表的head，存的是第一个元素的地址，第二个指针的意思是指向第一个指针的值所在的内存空间的地址，即 Node** head
void insertToFirst(Node** head, int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    (*temp).data = val;
    (*temp).next = *head;
}

// traversal linked-list to print node value
void printLL(struct Node* head) {
    printf("\nlinked list: \n");
    while(head != NULL) {
        printf("%d ", (*head).data);
        head = (*head).next;
    }
    printf("\n");
}