/**
 * Implementation of singly linked list with JavsScript
 * 2022-07-13 By WenTommy
 */

class LinkNode {
    public data: number;
    public next: LinkNode;

    constructor(data: number) {
        this.data = data;
        this.next = null;
    }
}

class SinglyLinkedList {
    public length: number;
    public head: LinkNode;
    public tail: LinkNode;

    constructor() {
        this.length = 0;
        this.head = null;
        this.tail = null;
    }

    // 将一个节点插入链表尾部，作为最后一个节点
    push(data: number): void {
        const newNode = new LinkNode(data);

        if (this.head === null) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            this.tail.next = newNode;
            this.tail = newNode;
        }
        this.increaseLength();
    }

    // 在链表的头部插入一个节点
    insertAtHead(data: number): void {
        const temp = new LinkNode(data);
        if(this.head === null) {
            this.head = temp;
            this.increaseLength();
            return;
        }
        temp.next = this.head;
        this.head = temp;
        this.increaseLength();
    }

    // 链表索引从1开始，head 为第1个节点
    insertAt(data: number, pos: number): void {
        const temp = new LinkNode(data);

        if(this.head === null) {
            this.head = temp;
            this.increaseLength();
        } else if(pos > this.length) {
            this.push(data);
        } else {
            let temp2: LinkNode = this.head;
            for(let i=0; i<pos-1;i++) {
                temp2 = temp2.next;
            }
            temp.next = temp2.next;
            temp2.next = temp;
            this.increaseLength();
        }
    }

    deleteNode(pos: number): void {
        if(pos < 1) {
            console.log('DeleteError: 位置不能小于1');
            return;
        }
        if(this.head === null) {
            console.log('Error: empty linked list');
            return;
        }
        if(pos > this.length) {
            console.log('Error: 超过链表长度');
            return;
        }
        if(this.length === 1) {
            this.head = null;
            this.tail = null;
            this.length = 0;
            return;
        }
        // 找到 pos-1 号的node
        let temp: LinkNode = this.head;
        for(let i=0; i<pos-2; i++) {
            temp = temp.next;
        }

        temp.next = temp.next.next;
        this.decreaseLength();
    }

    printLL(): void {
        if(this.head === null) {
            console.log('empty linked list');
            return;
        }
        let temp: LinkNode = this.head;
        while(temp !== null) {
            console.log(temp.data);
            temp = temp.next;
        }
    }

    // increasing length of linked list by 1
    increaseLength() {
        this.length++;
    }
    decreaseLength() {
        if(this.length <= 0) return;
        this.length--;
    }

}

