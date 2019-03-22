package com.bqlion.DataStructure.List;

public class CHDoublyLinkedList<E> {
    protected DlinkedNode<E>head;               //本体是一个头节点

    public CHDoublyLinkedList(){                //头结点在构造函数中初始化
        this.head = new DlinkedNode<E>(null);  //头结点的值为空，前后指针指向自己
        this.head.prev = head;
        this.head.next = head;
    }

    public void add(E element,int index){
        int i = 0;
        DlinkedNode<E> p = head;
        DlinkedNode<E> q = new DlinkedNode<E>(element);
        if(head.next != null && element != null && index >=0 ){
            while(i < index){
                p = p.next;
            }
            q.next = p.next;
            q.prev = p;
            p.next.prev = q;
            p.next = q;
            return;
        }
        return;
    }

    public void add(E element){         //未指定插入位置则插入到队列尾部
        DlinkedNode<E> p = head;
        DlinkedNode<E> q = new DlinkedNode<E>(element);
        p = p.prev;                     //工作指针从头指针移动到尾部，就位。剩下的操作一致。

        q.next = p.next;
        q.prev = p;
        p.next.prev = q;
        p.next = q;
        return;

    }

    public boolean remove(int index){
        if(index > 0 && head.next != null) {
            DlinkedNode<E> p = head;
            int i = 0;
            while(i < index){
                i++;
                p = p.next;
            }
            p.next.prev = p.prev;
            p.prev.next = p.next;
            p.next = null;
            p.prev = null;
            return true;
        }
        return false;
    }

    public boolean set(int index,E element){
        if(element != null && index >0 && head.next != null)
        {
            int i = 0;
            DlinkedNode<E>p = head;
            while(i < index){
                i++;
                p = p.next;
            }
            p.data = element;
            return true;
        }
        return false;

    }

    public boolean search(E element){

        if(element != null && head.next != null){
            DlinkedNode<E>p = head.next;
            while(p != head && p.data != element)
                p = p.next;
            if (p == head)
                return false;
            else
                return true;
        }
        return false;
    }
    public String toString(){
        String str = "(";
        DlinkedNode<E>p = this.head.next;
        while(p != head){
            str += p.data.toString();
            p = p.next;
            if(p!=head)
                str += ", ";
        }
        return str+")";

    }
}
