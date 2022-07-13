/**
 * Implementation of singly linked list with JavsScript
 * 2022-07-13 By WenTommy
 */

class Node {
    constructor(val) {
        this.data = val;
        this.next = null;
    }
}

class SinglyLinkedList {
    constructor() {
        this.length = 0;
        this.head = null;
        this.tail = null;
    }

    // 将一个节点插入链表尾部，作为最后一个节点
    push(val) {
        const newNode = new Node(val);

        if (this.head === null) {
            this.head = newNode;
            this.tail = newNode;
            return;
        }
        this.tail.next = newNode;
        this.tail = newNode;
        this.length++;
    }



}