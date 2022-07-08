struct Node {
    int data;
    struct Node* next;
};

Node* insertToFirst(Node* head, int val);


// insert an element after the head
// 按值传递参数，head 已是本地变量，怎么影响原链表的head？
// 返回一个新 head
Node* insertToFirst(Node* head, int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    (*temp).data = val;
    (*temp).next = head;
    return temp;
}