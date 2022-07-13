/**
 * Implementation of singly linked list with JavsScript
 * 2022-07-13 By WenTommy
 */
var LinkNode = /** @class */ (function () {
    function LinkNode(data) {
        this.data = data;
        this.next = null;
    }
    return LinkNode;
}());
var SinglyLinkedList = /** @class */ (function () {
    function SinglyLinkedList() {
        this.length = 0;
        this.head = null;
        this.tail = null;
    }
    // 将一个节点插入链表尾部，作为最后一个节点
    SinglyLinkedList.prototype.push = function (data) {
        var newNode = new LinkNode(data);
        if (this.head === null) {
            this.head = newNode;
            this.tail = newNode;
        }
        else {
            this.tail.next = newNode;
            this.tail = newNode;
        }
        this.increaseLength();
    };
    // 在链表的头部插入一个节点
    SinglyLinkedList.prototype.insertAtHead = function (data) {
        var temp = new LinkNode(data);
        if (this.head === null) {
            this.head = temp;
            this.increaseLength();
            return;
        }
        temp.next = this.head;
        this.head = temp;
        this.increaseLength();
    };
    // 链表索引从1开始，head 为第1个节点
    SinglyLinkedList.prototype.insertAt = function (data, pos) {
        var temp = new LinkNode(data);
        if (this.head === null) {
            this.head = temp;
            this.increaseLength();
        }
        else if (pos > this.length) {
            this.push(data);
        }
        else {
            var temp2 = this.head;
            for (var i = 0; i < pos - 1; i++) {
                temp2 = temp2.next;
            }
            temp.next = temp2.next;
            temp2.next = temp;
            this.increaseLength();
        }
    };
    SinglyLinkedList.prototype.deleteNode = function (pos) {
        if (this.head === null) {
            console.log('Error: empty linked list');
            return;
        }
        if (pos > this.length) {
            console.log('Error: 超过链表长度');
            return;
        }
        if (this.length === 1) {
            this.head = null;
            this.tail = null;
            this.length = 0;
            return;
        }
        // 找到 pos-1 号的node
        var temp = this.head;
        for (var i = 0; i < pos - 1; i++) {
            temp = temp.next;
        }
        temp.next = temp.next.next;
        this.decreaseLength();
    };
    SinglyLinkedList.prototype.printLL = function () {
        if (this.head === null) {
            console.log('empty linked list');
            return;
        }
        var temp = this.head;
        while (temp !== null) {
            temp = temp.next;
            console.log(temp.data);
        }
    };
    // increasing length of linked list by 1
    SinglyLinkedList.prototype.increaseLength = function () {
        this.length++;
    };
    SinglyLinkedList.prototype.decreaseLength = function () {
        if (this.length <= 0)
            return;
        this.length--;
    };
    return SinglyLinkedList;
}());
